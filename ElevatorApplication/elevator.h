#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>


class Elevator : public QObject
{
  Q_OBJECT
public:
  friend class ElevatorController;
  explicit Elevator(QObject *parent = nullptr);

signals:

private:
  int * floorQueue;
};

#endif // ELEVATOR_H
