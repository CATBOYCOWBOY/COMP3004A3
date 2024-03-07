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
  void elevatorIndexChange(int);
  void floorIndexChange(int);

  void elevatorPanelRequest(int);
  void elevatorOpenRequest(bool);
  void elevatorCloseRequest();

  void floorButtonPushed();

  void elevatorFireButton();
  void elevatorHelpButton();
  void elevatorOverButton();
  void elevatorBlockButton();
  void elevatorResetButton();

  void buildingFireButton();
  void buildingOutageButton();
  void handleHelpButton();
  void buildingResetButton();

private slots:
  // UI signnal handler
  void onElevatorIndexChange(int index);
  void onFloorIndexChange(int index);

  void on_ElevatorOne_clicked();
  void on_ElevatorTwo_clicked();
  void on_ElevatorThree_clicked();
  void on_ElevatorFour_clicked();
  void on_ElevatorFive_clicked();
  void on_ElevatorSix_clicked();
  void on_ElevatorSeven_clicked();



  void on_ElevatorOpen_pressed();
  void on_ElevatorOpen_released();
  void on_ElevatorClose_clicked();
  void on_ElevatorHelp_clicked();
  void on_elevatorFireButton_clicked();
  void on_elevatorBlockButton_clicked();
  void on_elevatorOverButton_clicked();
  void on_elevatorResetButton_clicked();

  void on_elevatorUpButton_clicked();
  void on_pushButton_3_clicked();

  void on_fireButton_clicked();
  void on_powerOutButton_clicked();
  void on_handleHelpButton_clicked();
  void on_resetButton_clicked();

  void on_ElevatorComboBox_currentIndexChanged(int index);

  void on_FloorComboBox_currentIndexChanged(int index);

  // Controller signal handler
  void onElevatorFloorChanged();
  void onElevatorMessageChanged();
private:
  void connectControllerSlots();
  Ui::MainElevatorWindow *ui;
  ElevatorController* controller = nullptr;

  int selectedFloorIndex;
};
#endif // MAINELEVATORWINDOW_H
