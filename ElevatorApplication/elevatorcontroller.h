#ifndef ELEVATORCONTROLLER_H
#define ELEVATORCONTROLLER_H

#include <QObject>
#include <QDebug>
#include "elevator.h"

class ElevatorController : public QObject
{
    Q_OBJECT
public:
    static ElevatorController* getInstance(QObject* parent = nullptr, int numFloors = 0, int numElevators = 0);
    static void destroyInstance();
    ElevatorController(ElevatorController*) = delete;

protected:
    explicit ElevatorController(QObject *parent = nullptr, int numFloors = 0, int numElevators = 0);
    ~ElevatorController();
    static ElevatorController* instance;

private:
    Elevator* elevators;

signals:
};

#endif // ELEVATORCONTROLLER_H
