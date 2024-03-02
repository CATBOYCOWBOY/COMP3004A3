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

signals:
  void shutOffElevators();


public slots:
  //SYSTEM CONTROL
  void onElevatorIndexChange(int);
  void onFloorIndexChange(int);

  void onElevatorPanelRequest(int);
  void onElevatorOpenRequest(bool);
  void onElevatorCloseRequest();

  void onFloorButtonRequest(int);

  void onElevatorFireButton();
  void onElevatorHelpButton();
  void onElevatorOverButton();
  void onElevatorResetButton();

  void onBuildingFireButton();
  void onBuildingOutageButton();
  void onHelpButton();
  void onBuildingResetButton();

protected:
  explicit ElevatorController(QObject *parent = nullptr);
  ~ElevatorController();
  static ElevatorController* instance;

private:
  Elevator** elevators;
  QThread** threads;
  QMutex* mutex;

  int viewSelectedElevatorIndex;
  int viewSelectedFloorIndex;

  int helpRequestedElevatorIndex;

  // shared resource between controller and elevators
  bool** queues;

  void connectElevatorSlots(Elevator*, QThread*);

};

#endif // ELEVATORCONTROLLER_H
