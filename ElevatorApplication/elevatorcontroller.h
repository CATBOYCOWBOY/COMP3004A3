#ifndef ELEVATORCONTROLLER_H
#define ELEVATORCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>
#include <QDebug>
#include <QMutex>
#include "elevator.h"

class ElevatorController : public QObject
{
  Q_OBJECT
public:
  static ElevatorController* getInstance(QObject* parent = nullptr);
  static void destroyInstance();
  ElevatorController(ElevatorController*) = delete;

  int getElevatorPosition(int);

public slots:
  void onFloorRequest(int);
  void onViewSelectElevator(int);
  void onElevatorControlsAction(int);

protected:
  explicit ElevatorController(QObject *parent = nullptr);
  ~ElevatorController();
  static ElevatorController* instance;

private:
  Elevator** elevators;
  QThread** threads;
  QMutex* mutex;

  int viewSelectedElevator;

  // shared resource between controller and elevators
  bool** queues;

signals:
};

#endif // ELEVATORCONTROLLER_H
