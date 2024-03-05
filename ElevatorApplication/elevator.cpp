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
    qInfo() << "Elevator " << number + 1 << " moves to floor " << next + 1;
    currentFloor = next;
    emit floorChanged(next);
    mainMutex->unlock();
    onFloorChangeLoop();
    return true;
  }
  mainMutex->unlock();
  return false;
}


void Elevator::onFloorChangeLoop()
{
  qInfo() << "Elevator " << number + 1 << " rings bell";
  qInfo() << "Elevator " << number + 1 << " opens door";
  for (int i = 0; i < 20; i++) {
    if (!systemIsRunning) {
      break;
    }
    QThread::msleep(100);
  }
  qInfo() << "emergency: " << isThereAnEmergency();
  while (isThereAnEmergency()) {
    checkDoors();
  }
  qInfo() << "Elevator " << number + 1 << " rings bell";
  qInfo() << "Elevator " << number + 1 << " close door";
}

void Elevator::checkDoors()
{
  qDebug() << "check doors";
  if (isDoorBlocked) {
    return onDoorBlockedLoop();
  } else if (isOverloaded) {
    return onOverloadedLoop();
  }
}

void Elevator::handleEmergency()
{
  if (isThereFire) {
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
    if (!isDoorBlocked || !systemIsRunning) {
      return;
    }
    QThread::msleep(100);
  }
  while (isDoorBlocked && systemIsRunning) {
    qDebug() << "Elevator " << number + 1 << " door is blocked";
    for (int i = 0; i < 40; i++) {
      if (!isDoorBlocked || !systemIsRunning) {
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
  return (isDoorBlocked || isOverloaded || isThereFire || helpButtonPushed || powerOutage);
}

////////////////////
//                //
//     SLOTS      //
//                //
////////////////////

void Elevator::addFloorToQueue(int floor)
{
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

    QThread::msleep(100);
  }
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
  qDebug() << "Door block signal num: " << i;
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

void Elevator::reset(int i)
{
  if (number == i) {
    elevatorMutex->lock();
    isDoorBlocked = false;
    isOverloaded = false;
    elevatorMutex->unlock();
  }
}

void Elevator::resetEmergency()
{
  reset(number);
  elevatorMutex->lock();
  isThereFire = false;
  helpButtonPushed = false;
  powerOutage = false;
  elevatorMutex->unlock();
}
