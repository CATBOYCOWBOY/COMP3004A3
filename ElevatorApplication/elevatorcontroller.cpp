#include "elevatorcontroller.h"

ElevatorController::ElevatorController(QObject *parent, int numFloors, int numElevators)
    : QObject{parent}
{
    qDebug() << "numFloors: " << numFloors << Qt::endl;
    qDebug() << "numElevators: " << numElevators << Qt::endl;
}

ElevatorController::~ElevatorController() {}

ElevatorController* ElevatorController::getInstance(QObject* parent, int numFloors, int numElevators) {
    if (ElevatorController::instance == nullptr) {
        ElevatorController::instance = new ElevatorController(parent, numFloors, numElevators);
    }
    return ElevatorController::instance;
}

void ElevatorController::destroyInstance() {
    if (ElevatorController::instance != nullptr) {
        delete ElevatorController::instance;
        ElevatorController::instance = nullptr;
    }
}
