#include "elevatorcontroller.h"
#include "constants.h"

ElevatorController::ElevatorController(QObject *parent)
  : QObject{parent}
{
  elevators = new Elevator *[NUM_ELEVATORS];
  threads = new QThread *[NUM_ELEVATORS];
  for (int i = 0; i < NUM_ELEVATORS; i++) {
      Elevator* elevator = new Elevator(nullptr, i + 1);
      QThread* thread = new QThread();
      connect(thread, &QThread::started, elevator, &Elevator::eventLoop);
      connect(elevator, &Elevator::onShutoff, thread, &QThread::quit);
      connect(thread, &QThread::finished, elevator, &Elevator::deleteLater);

      elevators[i] = elevator;
      threads[i] = thread;

      elevator->moveToThread(thread);
      thread->start();
  }
}

ElevatorController::~ElevatorController()
{
  for (int i = 0; i < NUM_ELEVATORS; i++) {
    delete elevators[i];
  }
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

