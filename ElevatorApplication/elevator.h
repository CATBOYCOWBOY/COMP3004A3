#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QRunnable>
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>

class Elevator : public QObject, public QRunnable
{
  Q_OBJECT
public:
  explicit Elevator(QObject *parent = nullptr, QMutex* = nullptr, int = -1, bool* = nullptr);

  void shutOff();

  int getCurrentFloor();

  void addFloorToQueue(int);

signals:
  int floorChanged(int);
  bool doorOpened(bool);
  QString elevatorMessageChanged(std::string);
  void onShutoff();

public slots:
   void eventLoop();

private:
  bool * floorQueue;
  bool isDoorBlocked = false;
  bool isOverloaded = false;
  bool isThereFire = false;
  bool systemIsRunning = false;

  int currentFloor = 1;
  int number;

  int nextFloor();
  bool moveToNextFloor();
  void onFloorChangeLoop();

  QMutex* mutex;

  // QRunnable interface
public:
  void run();
};

#endif // ELEVATOR_H
