#ifndef MAINELEVATORWINDOW_H
#define MAINELEVATORWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "elevatorcontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainElevatorWindow;
}
QT_END_NAMESPACE

class MainElevatorWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainElevatorWindow(QWidget *parent = nullptr);
  ~MainElevatorWindow();

signals:
  int changeElevatorIndex(int);

private slots:
  void onElevatorIndexChange(int index);
  void onFloorIndexChange(int index);

private:
  void connectSlots();
  Ui::MainElevatorWindow *ui;
  ElevatorController* controller = nullptr;

  int selectedFloorIndex;
};
#endif // MAINELEVATORWINDOW_H
