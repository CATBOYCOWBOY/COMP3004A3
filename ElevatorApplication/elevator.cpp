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


void Elevator::onFloorChangeLoop()
{
  for (int i = 0; i < 10; i++) {
    if (!systemIsRunning) {
      break;
    }
    qDebug() << "waited for " << i << " seconds";
    QThread::msleep(1000);
  }
}

void Elevator::handleEmergency()
{
  if (isDoorBlocked) {
    return onDoorBlockedLoop();
  } else if (isOverloaded) {
    return onOverloadedLoop();
  } else if (isThereFire) {
    return onFireLoop();
  } else if (helpButtonPushed) {
    return onHelpLoop();
  } else if (powerOutage) {
    return onPowerOutLoop();
  }
}

void Elevator::onDoorBlockedLoop()
{
  // 4 seconds and a bit is chosen very arbitrarily
  for (int i = 0; i < 40; i++) {
    if (!isDoorBlocked) {
      return;
    }
    QThread::msleep(100);
  }
  while (!isDoorBlocked) {
    qDebug() << "Elevator " << number + 1 << " door is blocked";
    for (int i = 0; i < 40; i++) {
      if (!isDoorBlocked) {
        return;
      }
      QThread::msleep(100);
    }
  }
}

void Elevator::onOverloadedLoop() {}

void Elevator::onHelpLoop() {}

void Elevator::onFireLoop() {}

void Elevator::onPowerOutLoop() {}

bool Elevator::isThereAnEmergency()
{
  return isDoorBlocked || isOverloaded || isThereFire || helpButtonPushed || powerOutage;
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
    qDebug() << "something gone very wrong";
    systemIsRunning = false;
  }

  while (systemIsRunning)
  {
    handleEmergency();
    moveToNextFloor();
    onFloorChangeLoop();

    QThread::msleep(1000);
  }
  qDebug() << "Elevator " << number + 1 << " shutting down";
  this->deleteLater();
}


void Elevator::onShutOff()
{
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

void Elevator::handleBlock(int i)
{
  if (number != i) {
    return;
  }
  elevatorMutex->lock();
  isDoorBlocked = true;
  elevatorMutex->unlock();
}

void Elevator::handleOutage()
{

}

void Elevator::resolveHelp()
{

}

void Elevator::reset()
{
  isDoorBlocked = false;
  isOverloaded = false;
}

void Elevator::resetEmergency()
{
  reset();
  isThereFire = false;
  helpButtonPushed = false;
  powerOutage = false;
}
