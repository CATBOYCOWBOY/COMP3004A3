#include "elevator.h"
#include "constants.h"

Elevator::Elevator(QObject *parent, QMutex *m, int elevatorNumber, bool *queue)
    : QObject{parent}
    , floorQueue(queue)
    , number(elevatorNumber)
    , mainMutex(m)
{}

Elevator::~Elevator()
{
  emit shutOff();
}

int Elevator::getCurrentFloor()
{
  return currentFloor;
}


bool Elevator::moveToNextFloor()
{
  mainMutex->lock();
  int next = -1;
  for (int i = 0; i < NUM_FLOORS; i++) {
    if (floorQueue[i]) {
      floorQueue[i] = false;
      next = i + 1;
      break;
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

////////////////////
//                //
//     SLOTS      //
//                //
////////////////////

void Elevator::addFloorToQueue(int floor)
{
  qDebug() << "adding floor " << floor << " in thread " << this->thread()->objectName();
  mainMutex->lock();
  floorQueue[floor] = true;
  mainMutex->unlock();
}

void Elevator::eventLoop() {
  elevatorMutex = new QMutex();

  if (elevatorMutex == nullptr) {
    qDebug() << "somethings gone very wrong";
    systemIsRunning = false;
  }

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
    qDebug() << "waited for " << i << " tenths of seconds";
    QThread::msleep(100);
  }
}

void Elevator::onShutOff()
{
  qDebug() << "onShutoff " << number;
  systemIsRunning = false;
}


void Elevator::handleOpenButton(bool)
{

}

void Elevator::handleCloseButton()
{

}

void Elevator::handleFire()
{

}

void Elevator::handleHelpButton()
{

}

void Elevator::handleOverload()
{

}

void Elevator::handleBlock()
{

}

void Elevator::handleOutage()
{

}

void Elevator::resolveHelp()
{

}

void Elevator::reset()
{

}

