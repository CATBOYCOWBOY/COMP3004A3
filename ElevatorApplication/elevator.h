#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QRunnable>
#include <QDebug>


class Elevator : public QObject, public QRunnable
{
  Q_OBJECT
public:
  explicit Elevator(QObject *parent = nullptr, int = -1);
  ~Elevator();

  void shutOff();

  int getCurrentFloor();

signals:
  int floorChanged(int);
  bool doorOpened(bool);
  QString elevatorMessageChanged(std::string);
  void onShutoff();

public slots:
   void eventLoop();

private:
  bool * floorQueue;
  bool isDoorBlocked;
  bool isOverloaded;
  bool systemIsRunning;

  int currentFloor;
  int number;

  int nextFloor();
  bool moveToNextFloor();
  void onFloorChangeLoop();

  // QRunnable interface
public:
  void run();
};

#endif // ELEVATOR_H
