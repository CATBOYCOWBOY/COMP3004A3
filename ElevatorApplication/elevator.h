#ifndef ELEVATOR_H
#define ELEVATOR_H

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

  void addFloorToQueue(int);

  void sayHello();

  void onShutOff();

signals:
  void floorChanged(int);
  void doorOpened(bool);
  void elevatorMessageChanged(std::string);
  void shutOff();

public slots:
  void eventLoop();


private:
  bool * floorQueue;
  bool isDoorBlocked = false;
  bool isOverloaded = false;
  bool isThereFire = false;
  bool systemIsRunning = true;

  int currentFloor = 1;
  int number;

  int nextFloor();
  bool moveToNextFloor();
  void onFloorChangeLoop();

  QMutex* mutex;
};

#endif // ELEVATOR_H
