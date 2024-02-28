#include "elevatorcontroller.h"
#include "constants.h"
#include <cmath>

ElevatorController::ElevatorController(QObject *parent)
  : QObject{parent}
{
  elevators = new Elevator *[NUM_ELEVATORS];
  threads = new QThread *[NUM_ELEVATORS];
  queues = new bool*[NUM_ELEVATORS];
  mutex = new QMutex();

  for (int i = 0; i < NUM_ELEVATORS; i++) {
    queues[i] = new bool[NUM_FLOORS];

    Elevator* elevator = new Elevator(nullptr, mutex, i + 1, queues[i]);
    QThread* thread = new QThread();
    connect(thread, &QThread::started, elevator, &Elevator::eventLoop);
    connect(elevator, &Elevator::onShutoff, thread, &QThread::quit);
    connect(thread, &QThread::finished, elevator, &Elevator::deleteLater);

    elevators[i] = elevator;
    threads[i] = thread;

    elevator->setAutoDelete(true);
    elevator->moveToThread(thread);
    thread->start();
  }
}

int ElevatorController::getElevatorPosition(int i)
{
  return elevators[i]->getCurrentFloor();
}

void ElevatorController::onFloorRequest(int floor)
{
  // closest value is always squared to keep values positive and compare absolute values w/o using CMath
  int closestIndex = 0;
  int closestValue = NUM_FLOORS + 1;

  for (int i = 0; i < NUM_ELEVATORS; i++) {
    int diff = std::abs(elevators[i]->getCurrentFloor() - floor);
    if (diff < closestValue) {
      closestValue = diff;
      closestIndex = i;
    }
  }

  elevators[closestIndex]->addFloorToQueue(floor);
}

void ElevatorController::onViewSelectElevator(int index)
{
  if (index < 0 || index > (NUM_ELEVATORS - 1)) {
    return;
  }
  viewSelectedElevator = index;
  qDebug() << "Selected Elevator: " << viewSelectedElevator + 1;
}

void ElevatorController::onElevatorControlsAction(int action)
{
  qDebug() << "Controls action: " << action;
}

ElevatorController::~ElevatorController()
{
  for (int i = 0; i < NUM_ELEVATORS; i++) {
    threads[i]->exit();
    delete threads[i];
    delete queues[i];
  }
  delete mutex;
  delete[] queues;
  delete[] elevators;
}

ElevatorController* ElevatorController::getInstance(QObject* parent) {
  if (ElevatorController::instance == nullptr) {
    ElevatorController::instance = new ElevatorController(parent);
  }
  return ElevatorController::instance;
}

void ElevatorController::destroyInstance() {
  if (ElevatorController::instance != nullptr) {
    delete ElevatorController::instance;
    ElevatorController::instance = nullptr;
  }
}

