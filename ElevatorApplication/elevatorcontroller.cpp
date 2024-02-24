#include "elevatorcontroller.h"
#include "constants.h"

ElevatorController::ElevatorController(QObject *parent)
  : QObject{parent}
{
  elevators = new Elevator *[NUM_ELEVATORS];
  for (int i = 0; i < NUM_ELEVATORS; i++) {
      elevators[i] = new Elevator();
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

