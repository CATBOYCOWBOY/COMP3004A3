#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <string>
#include <QObject>
#include <QString>
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>

class Elevator : public QObject
{
  Q_OBJECT
public:
  explicit Elevator(QObject* parent = nullptr, QMutex* = nullptr, int = -1, bool* = nullptr);
  ~Elevator();

  int getCurrentFloor();
  void onShutOff();
  std::string getElevatorMessage();
signals:
  void floorChanged(int);
  void doorOpened(bool);
  void elevatorMessageChanged(int);
  void shutOff();

public slots:
  void eventLoop();

  void addFloorToQueue(int);
  void handleOpenButton(bool);
  void handleCloseButton(int);

  void handleElevatorFireButton(int);
  void handleHelpButton(int);
  void handleOverloadButton(int);
  void handleBlockButton(int);

  void handleFire();
  void handleOutage();
  void resolveHelp();
  void reset(int);
  void resetEmergency();

private:
  bool * floorQueue;
  bool isOpenButtonPushed = false;
  bool isCloseButtonPushed = false;
  bool isDoorBlocked = false;
  bool isOverloaded = false;
  bool isThereFire = false;
  bool helpButtonPushed = false;
  bool powerOutage = false;
  bool systemIsRunning = true;

  std::string message;
  int currentFloor = 1;
  int number; // index of elevator in EC array

  bool moveToNextFloor();
  void onFloorChangeLoop();
  void onDoorBlockedOrOverloadLoop();
  void onHelpLoop();
  void onFireLoop();
  void onPowerOutLoop();

  void checkDoors();
  void handleEmergency();

  bool isThereAnEmergency();

  // locks main thread (floorQueue is shared)
  QMutex* mainMutex;

  // locks resources for elevator thread
  QMutex* elevatorMutex = nullptr;
};

#endif // ELEVATOR_H
