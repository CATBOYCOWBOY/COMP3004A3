#include "elevator.h"
#include "constants.h"

Elevator::Elevator(QObject *parent, int num)
    : QObject{parent}, number(num)
{
  floorQueue = new bool[NUM_FLOORS];
  isDoorBlocked = false;
  isOverloaded = false;
  systemIsRunning = true;

  currentFloor = 1;
}

Elevator::~Elevator()
{
  delete[] floorQueue;
}

void Elevator::eventLoop() {
  while (systemIsRunning)
  {
    moveToNextFloor();
    QThread::msleep(1000);
    qDebug() << "Elevator " << number << " running";
  }
}

void Elevator::onFloorChangeLoop()
{
  for (int i = 0; i < 10; i++)
  {

  }
}

void Elevator::run()
{
  eventLoop();
}

bool Elevator::moveToNextFloor()
{
  int next = nextFloor();
  if (next > 0)
  {
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
