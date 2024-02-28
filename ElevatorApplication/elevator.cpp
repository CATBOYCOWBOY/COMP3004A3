#include "elevator.h"
#include "constants.h"

Elevator::Elevator(QObject *parent, QMutex *m, int elevatorNumber, bool *queue)
    : QObject{parent}
    , floorQueue(queue)
    , number(elevatorNumber)
    , mutex(m)
{
  qDebug() << "Elevator " << number << " ctr";
}

Elevator::~Elevator()
{
  qDebug() << "Elevator " << number << " dtor";
  emit shutOff();
}

int Elevator::getCurrentFloor()
{
  return currentFloor;
}

void Elevator::addFloorToQueue(int floor)
{
  mutex->lock();
  floorQueue[floor] = true;
  mutex->unlock();
}

void Elevator::eventLoop() {
  while (systemIsRunning)
  {
    moveToNextFloor();
    QThread::msleep(1000);
  }
  qDebug() << "Elevator " << number << " shutting down";
  this->deleteLater();
}

void Elevator::onFloorChangeLoop()
{
  for (int i = 0; i < 10; i++)
  {

  }
}

bool Elevator::moveToNextFloor()
{
  int next = nextFloor();
  if (next > 0)
  {
    qDebug() << "Moving to floor " << next;
    currentFloor = next;
    emit floorChanged(next);
    return true;
  }
  return false;
}

int Elevator::nextFloor()
{
  for (int i = 0; i < NUM_FLOORS; i++) {
    if (floorQueue[i]) {
      floorQueue[i] = false;
      return i + 1;
    }
  }
  return -1;
}

void Elevator::sayHello()
{
  qDebug() << "hello world " << number;
}

void Elevator::onShutOff()
{
  qDebug() << "shutoff";
  systemIsRunning = false;
}
