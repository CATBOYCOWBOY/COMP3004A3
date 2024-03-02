#include "elevator.h"
#include "constants.h"

Elevator::Elevator(QObject *parent, QMutex *m, int elevatorNumber, bool *queue)
    : QObject{parent}
    , floorQueue(queue)
    , number(elevatorNumber)
    , mainMutex(m)
{
  qDebug() << "Elevator " << number << " ctr";
  elevatorMutex = new QMutex();
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
  mainMutex->lock();
  floorQueue[floor] = true;
  mainMutex->unlock();
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
  mainMutex->lock();
  int next = -1;
  for (int i = 0; i < NUM_FLOORS; i++) {
    if (floorQueue[i]) {
      floorQueue[i] = false;
      next = i + 1;
    }
  }

  if (next > 0)
  {
    qDebug() << "Moving to floor " << next;
    currentFloor = next;
    emit floorChanged(next);
    mainMutex->unlock();
    return true;
  }
  mainMutex->unlock();
  return false;
}

void Elevator::onShutOff()
{
  qDebug() << "shutoff";
  systemIsRunning = false;
}

void Elevator::reset();
{
  elevatorMutex->lock();
}
