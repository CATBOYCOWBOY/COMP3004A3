#include "elevator.h"
#include "constants.h"
#include <sstream>

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
  int  actualTimeCounter = 0;
  for (int i = 0; i < NUM_TENTHS_STOPPAGE; i++) {
    if (!systemIsRunning) {
      return;
    }
    checkDoors();
    handleEmergency();
    if (isCloseButtonPushed) {
      elevatorMutex->lock();
      isCloseButtonPushed = false;
      elevatorMutex->unlock();
      break;
    } else if (isOpenButtonPushed){
      i -= 1;
    } else if (actualTimeCounter >= NUM_TENTHS_STOPPAGE) {
      break;
    }
    actualTimeCounter += 1;
    QThread::msleep(100);
  }
  checkDoors();
  handleEmergency();
  if (systemIsRunning) {
    qInfo() << "Elevator " << number + 1 << " rings bell";
    qInfo() << "Elevator " << number + 1 << " close door";
  }
}

void Elevator::checkDoors()
{
  if (isDoorBlocked || isOverloaded) {
      onDoorBlockedOrOverloadLoop();
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

void Elevator::onDoorBlockedOrOverloadLoop()
{
  std::stringstream s;
  if (isDoorBlocked){
    qInfo() << "\nWARNING - elevator " << number + 1 << " door is blocked";
    s << BLOCKED_MSG << " ";
  }
  if (isOverloaded) {
    qInfo() << "WARNING - elevator " << number + 1 << " door is overloaded\n";
    s << OVER_MSG;
  }
  message = s.str();
  emit elevatorMessageChanged(number);

  // 4 seconds and a bit is chosen arbitrarily
  for (int i = 0; i < 40; i++) {
    if ((!isDoorBlocked && !isOverloaded)|| !systemIsRunning) {
      break;
    }
    QThread::msleep(100);
  }
  while ((isDoorBlocked||isOverloaded) && systemIsRunning) {
    if (isDoorBlocked){
      qInfo() << "\nWARNING - elevator " << number + 1 << " door is blocked";
    }
    if (isOverloaded) {
      qInfo() << "WARNING - elevator " << number + 1 << " door is overloaded\n";
    }
    for (int i = 0; i < 40; i++) {
      if ((!isDoorBlocked && !isOverloaded) || !systemIsRunning) {
        break;
      }
      QThread::msleep(100);
    }
  }
  message = "";
  emit elevatorMessageChanged(number);
}

void Elevator::onHelpLoop()
{
  qInfo() << "Elevator " << number + 1 << " calling for help from building";
  message = HELP_MSG;
  emit elevatorMessageChanged(number);
  for (int i = 0; i < 50; i++) {
    if (!systemIsRunning) {
        return;
    }
    QThread::msleep(100);
  }
  qInfo() << "\nCalling emergency services...\n";
  while (helpButtonPushed && systemIsRunning) {
    if (!systemIsRunning) {
      return;
    }
    QThread::msleep(100);
  }
  qInfo() << "Elevator " << number + 1 << " help call resolved";
  message = "";
  emit elevatorMessageChanged(number);
}

void Elevator::onFireLoop()
{
  qInfo() << "Elevator " << number + 1 << " fire alert, moving to ground floor";
  message = FIRE_MSG;
  emit elevatorMessageChanged(number);
  currentFloor = 1;
  emit floorChanged(1);
  qInfo() << "Elevator " << number + 1 << " message: please exit elevator";
  while (isThereFire) {
    if (!systemIsRunning) {
      return;
    }
    QThread::msleep(100);
  }
  qInfo() << "Elevator " << number + 1 << " back to normal operation";
}

void Elevator::onPowerOutLoop() {
  qInfo() << "Elevator " << number + 1 << " power out alert, moving to ground floor";
  message = FIRE_MSG;
  emit elevatorMessageChanged(number);
  currentFloor = 1;
  emit floorChanged(1);
  qInfo() << "Elevator " << number + 1 << " message: please exit elevator";
  onFloorChangeLoop();
  while (powerOutage) {
    if (!systemIsRunning) {
      return;
    }
    QThread::msleep(100);
  }
  qInfo() << "Elevator " << number + 1 << " back to normal operation";
}

bool Elevator::isThereAnEmergency()
{
  return (isDoorBlocked || isOverloaded || isThereFire || helpButtonPushed || powerOutage);
}

std::string Elevator::getElevatorMessage()
{
  return message;
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


void Elevator::handleOpenButton(bool status, int i)
{
  if (number != i)
  {
    return;
  }
  elevatorMutex->lock();
  isOpenButtonPushed = status;
  elevatorMutex->unlock();
}

void Elevator::handleCloseButton(int i)
{
  if (number != i) {
      return;
  }
  qDebug() << "Elevator " << number + 1 << " close ";
  elevatorMutex->lock();
  isCloseButtonPushed = true;;
  elevatorMutex->unlock();
}

void Elevator::handleFire()
{
  handleElevatorFireButton(number);
}

void Elevator::handleElevatorFireButton(int i)
{
  if (number != i) {
      return;
  }
  qDebug() << "Elevvator fire button: " << i;
  elevatorMutex->lock();
  isThereFire = true;
  elevatorMutex->unlock();
}

void Elevator::handleHelpButton(int i)
{
  if (number != i) {
      return;
  }
  qDebug() << "Elevator help buton: " << i;
  elevatorMutex->lock();
  helpButtonPushed = true;
  elevatorMutex->unlock();
}

void Elevator::handleOverloadButton(int i)
{
  if (number != i) {
    return;
  }
  qDebug() << "Elevator overload signal num: " << i;
  elevatorMutex->lock();
  isOverloaded = true;
  elevatorMutex->unlock();
}

void Elevator::handleBlockButton(int i)
{

  if (number != i) {
    return;
  }
  qDebug() << "Door block signal num: " << i;
  elevatorMutex->lock();
  isDoorBlocked = true;
  elevatorMutex->unlock();
}

void Elevator::handleOutage()
{
  qDebug() << "Elevator outage";
  elevatorMutex->lock();
  powerOutage = true;
  elevatorMutex->unlock();
}

void Elevator::resolveHelp()
{
  qDebug() << "Elevator help resolve";
  elevatorMutex->lock();
  powerOutage = true;
  elevatorMutex->unlock();
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
  message = "";
  emit elevatorMessageChanged(number);
}
