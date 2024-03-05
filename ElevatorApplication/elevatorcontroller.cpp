#include "elevatorcontroller.h"
#include "constants.h"
#include <cmath>
#include <sstream>


// Ctr, dtr, singleton handler methods

ElevatorController::ElevatorController(QObject* parent)
    : QObject{parent}
    , viewSelectedElevatorIndex(0)
    , viewSelectedFloorIndex(0)
    , helpRequestedElevatorIndex(0)
{
  elevators = new Elevator *[NUM_ELEVATORS];
  threads = new QThread *[NUM_ELEVATORS];
  queues = new bool*[NUM_ELEVATORS];
  mutex = new QMutex();

  for (int i = 0; i < NUM_ELEVATORS; i++) {
    std::stringstream s;
    queues[i] = new bool[NUM_FLOORS];

    for (int j = 0; j < NUM_FLOORS; j++) {
      queues[i][j] = false;
    }
    s << "thread " << i +1;

    Elevator* elevator = new Elevator(nullptr, mutex, i, queues[i]);
    QThread* thread = new QThread();
    thread->setObjectName(QString::fromStdString(s.str()));

    connectElevatorSlots(elevator, thread);

    elevators[i] = elevator;
    threads[i] = thread;

    elevator->moveToThread(thread);
    thread->start();
  }
}


ElevatorController::~ElevatorController()
{
  for (int i = 0; i < NUM_ELEVATORS; i++) {
    elevators[i]->onShutOff();
    threads[i]->wait();
  }

  for (int i = 0; i < NUM_ELEVATORS; i++) {
    delete threads[i];
    delete queues[i];
  }

  delete mutex;
  delete[] queues;
  delete[] elevators;
}

ElevatorController* ElevatorController::getInstance(QObject* parent)
{
  if (ElevatorController::instance == nullptr) {
    ElevatorController::instance = new ElevatorController(parent);
  }
  return ElevatorController::instance;
}

void ElevatorController::destroyInstance()
{
  if (ElevatorController::instance != nullptr) {
    delete ElevatorController::instance;
    ElevatorController::instance = nullptr;
  }
}

////////////////////
//                //
//     SLOTS      //
//                //
////////////////////

// qComboBox slots

void ElevatorController::onElevatorIndexChange(int index)
{
  if (index < 0 || index > (NUM_ELEVATORS - 1)) {
    exit(1);
  }
  viewSelectedElevatorIndex = index;
  qDebug() << "Selected Elevator: " << viewSelectedElevatorIndex + 1;
}

void ElevatorController::onFloorIndexChange(int index)
{
  if (index < 0 || index > (NUM_FLOORS - 1)) {
    exit(1);
  }
  viewSelectedFloorIndex = index;
  qDebug() << "Selected Floor: " << viewSelectedElevatorIndex + 1;
}

// controls slots

void ElevatorController::onElevatorPanelRequest(int floor)
{
  elevators[viewSelectedElevatorIndex]->addFloorToQueue(floor);
}

void ElevatorController::onElevatorOpenRequest(bool req)
{
  qDebug() << "Open: " << req;
}

void ElevatorController::onElevatorCloseRequest()
{
  qDebug() << "close";
}

void ElevatorController::onFloorButtonRequest()
{
  qDebug() << "floor button pushed, floor " << viewSelectedFloorIndex;
  int closestIndex = 0;
  int closestValue = NUM_FLOORS + 1;

  for (int i = 0; i < NUM_ELEVATORS; i++) {
    int diff = std::abs(elevators[i]->getCurrentFloor() - (viewSelectedFloorIndex + 1));
    if (diff < closestValue) {
      closestValue = diff;
      closestIndex = i;
    }
  }
  elevators[closestIndex]->addFloorToQueue(viewSelectedFloorIndex);
}

// elevator emergency slots

void ElevatorController::onElevatorFireButton()
{
  qDebug() << "Elevator " << viewSelectedElevatorIndex << " fire button ";
}

void ElevatorController::onElevatorHelpButton()
{
  helpRequestedElevatorIndex = viewSelectedElevatorIndex;
  qDebug() << "Elevator " << viewSelectedElevatorIndex << " help button";
}

void ElevatorController::onElevatorOverButton()
{
  qDebug() << "Elevator " << viewSelectedElevatorIndex << " overload button";
}

void ElevatorController::onElevatorBlockButton()
{
  qDebug() << "Elevator " << viewSelectedElevatorIndex << " block button";
  emit blockButton(viewSelectedElevatorIndex);
}

void ElevatorController::onElevatorResetButton()
{
  qDebug() << "Elevator " << viewSelectedElevatorIndex << " reset button";
}

// Building slots

void ElevatorController::onBuildingFireButton()
{
  qDebug() << "Building fire Button";
}

void ElevatorController::onBuildingOutageButton()
{
  qDebug() << "Building outage Button";
}

void ElevatorController::onHelpButton()
{
  qDebug() << "handling elevator help request on elevator " << helpRequestedElevatorIndex;
  helpRequestedElevatorIndex = -1;
}

void ElevatorController::onBuildingResetButton()
{
  qDebug() << "reset emergency states";
}

// slots from elevator


void ElevatorController::onElevatorFLoorChange(int)
{
  emit elevatorFloorChanged();
}

// other

int ElevatorController::getElevatorPosition(int i)
{
  return elevators[i]->getCurrentFloor();
}

int ElevatorController::getCurrentElevatorPostition()
{
  return elevators[viewSelectedElevatorIndex]->getCurrentFloor();
}

void ElevatorController::connectElevatorSlots(Elevator * elevator, QThread * thread)
{
  connect(thread, &QThread::started, elevator, &Elevator::eventLoop);
  connect(elevator, &Elevator::shutOff, thread, &QThread::quit, Qt::DirectConnection);
  connect(thread, &QThread::finished, elevator, &Elevator::deleteLater);
  connect(this, &ElevatorController::blockButton, elevator, &Elevator::handleBlock);

  connect(elevator, &Elevator::floorChanged, this, &ElevatorController::onElevatorFLoorChange);
}

