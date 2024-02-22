#ifndef ELEVATORCONTROLLER_H
#define ELEVATORCONTROLLER_H

#include <QObject>

class ElevatorController : public QObject
{
    Q_OBJECT
public:
    explicit ElevatorController(QObject *parent = nullptr);

signals:
};

#endif // ELEVATORCONTROLLER_H
