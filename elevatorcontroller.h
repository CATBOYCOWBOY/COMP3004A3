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
  int getCurrentElevatorPostition();
  QString getCurrentElevatorMessage();

signals:
  // signals to elevator
  void shutOff();


  void blockButton(int);
  void elevatorResetButton(int);
  void elevatorOverButton(int);

  void elevatorOpenButton(bool, int);
  void elevatorCloseButton(int);
  void elevatorFireButton(int);
  void elevatorHelpButton(int);

  void buildingFireButton();
  void buildingOutageButton();
  void buildingHandleHelp();
  void buildingResetButton();

  // signals to ui
  void elevatorFloorChanged();
  void elevatorMessageChanged();

public slots:
  //SLOTS FROM CONTROLLER
  void onElevatorIndexChange(int);
  void onFloorIndexChange(int);

  void onElevatorPanelRequest(int);
  void onElevatorOpenRequest(bool);
  void onElevatorCloseRequest();

  void onFloorButtonRequest();

  void onElevatorFireButton();
  void onElevatorHelpButton();
  void onElevatorOverButton();
  void onElevatorBlockButton();
  void onElevatorResetButton();

  void onBuildingFireButton();
  void onBuildingOutageButton();
  void onBuildingHelpButton();
  void onBuildingResetButton();

  //SLOTS FROM ELEVATOR
  void onElevatorFloorChange();
  void onElevatorMessageChanged(int);

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

  // shared resource between controller and elevators
  bool** queues;

  void connectElevatorSlots(Elevator*, QThread*);

};

#endif // ELEVATORCONTROLLER_H
