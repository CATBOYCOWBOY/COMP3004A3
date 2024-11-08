#include "elevatorcontroller.h"
#include "constants.h"
#include <cmath>
#include <sstream>


// Ctr, dtr, singleton handler methods

ElevatorController::ElevatorController(QObject* parent)
    : QObject{parent}
    , viewSelectedElevatorIndex(0)
    , viewSelectedFloorIndex(0)
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
}

void ElevatorController::onFloorIndexChange(int index)
{
  if (index < 0 || index > (NUM_FLOORS - 1)) {
    exit(1);
  }
  viewSelectedFloorIndex = index;
}

// controls slots

void ElevatorController::onElevatorPanelRequest(int floor)
{
  elevators[viewSelectedElevatorIndex]->addFloorToQueue(floor);
}

void ElevatorController::onElevatorOpenRequest(bool status)
{
  emit elevatorOpenButton(status, viewSelectedElevatorIndex);
}

void ElevatorController::onElevatorCloseRequest()
{
  emit elevatorCloseButton(viewSelectedElevatorIndex);
}

void ElevatorController::onFloorButtonRequest()
{
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
  emit elevatorFireButton(viewSelectedElevatorIndex);
}

void ElevatorController::onElevatorHelpButton()
{
  emit elevatorHelpButton(viewSelectedElevatorIndex);
}

void ElevatorController::onElevatorOverButton()
{
  emit elevatorOverButton(viewSelectedElevatorIndex);
}

void ElevatorController::onElevatorBlockButton()
{
  emit blockButton(viewSelectedElevatorIndex);
}

void ElevatorController::onElevatorResetButton()
{
  emit elevatorResetButton(viewSelectedElevatorIndex);
}

// Building slots

void ElevatorController::onBuildingFireButton()
{
  emit buildingFireButton();
}

void ElevatorController::onBuildingOutageButton()
{
  emit buildingOutageButton();
}

void ElevatorController::onBuildingHelpButton()
{
  emit buildingHandleHelp();
}

void ElevatorController::onBuildingResetButton()
{
  emit buildingResetButton();
}

// slots from elevator


void ElevatorController::onElevatorFloorChange()
{
  emit elevatorFloorChanged();
}

void ElevatorController::onElevatorMessageChanged(int i) {
  if (i == viewSelectedElevatorIndex) {
    emit elevatorMessageChanged();
  }
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

QString ElevatorController::getCurrentElevatorMessage()
{
  return QString::fromStdString(elevators[viewSelectedElevatorIndex]->getElevatorMessage());
}

void ElevatorController::connectElevatorSlots(Elevator * elevator, QThread * thread)
{
  connect(thread, &QThread::started, elevator, &Elevator::eventLoop);
  connect(elevator, &Elevator::shutOff, thread, &QThread::quit, Qt::DirectConnection);
  connect(thread, &QThread::finished, elevator, &Elevator::deleteLater);

  connect(this,
          &ElevatorController::blockButton,
          elevator,
          &Elevator::handleBlockButton,
          Qt::DirectConnection);
  connect(this,
          &ElevatorController::elevatorResetButton,
          elevator,
          &Elevator::reset,
          Qt::DirectConnection);
  connect(this,
          &ElevatorController::elevatorOverButton,
          elevator,
          &Elevator::handleOverloadButton,
          Qt::DirectConnection);

  connect(this,
          &ElevatorController::elevatorOpenButton,
          elevator,
          &Elevator::handleOpenButton,
          Qt::DirectConnection);
  connect(this,
          &ElevatorController::elevatorCloseButton,
          elevator,
          &Elevator::handleCloseButton,
          Qt::DirectConnection);
  connect(this,
          &ElevatorController::elevatorFireButton,
          elevator,
          &Elevator::handleElevatorFireButton,
          Qt::DirectConnection);
  connect(this,
          &ElevatorController::elevatorHelpButton,
          elevator,
          &Elevator::handleHelpButton,
          Qt::DirectConnection);

  connect(this,
          &ElevatorController::buildingFireButton,
          elevator,
          &Elevator::handleFire,
          Qt::DirectConnection);
  connect(this,
          &ElevatorController::buildingOutageButton,
          elevator,
          &Elevator::handleOutage,
          Qt::DirectConnection);
  connect(this,
          &ElevatorController::buildingHandleHelp,
          elevator,
          &Elevator::resolveHelp,
          Qt::DirectConnection);
  connect(this,
          &ElevatorController::buildingResetButton,
          elevator,
          &Elevator::resetEmergency,
          Qt::DirectConnection);

  connect(elevator,
          &Elevator::floorChanged,
          this,
          &ElevatorController::onElevatorFloorChange,
          Qt::DirectConnection);
  connect(elevator,
          &Elevator::elevatorMessageChanged,
          this,
          &ElevatorController::onElevatorMessageChanged,
          Qt::DirectConnection);
}

