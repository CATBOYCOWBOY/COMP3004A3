#include "mainelevatorwindow.h"
#include "ui_mainelevatorwindow.h"
#include <sstream>

MainElevatorWindow::MainElevatorWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainElevatorWindow)
{
  ui->setupUi(this);
  ui->primaryTabs->setTabText(0, "Elevator Controls");
  ui->primaryTabs->setTabText(1, "Floor Controls");
  ui->primaryTabs->setTabText(2, "Building Controls");

  ui->buildingControlLabel->setText("");
  ui->elevatorFloorDisplay->display(1);

  controller = ElevatorController::getInstance();
}

MainElevatorWindow::~MainElevatorWindow()
{
  delete ui;
  ElevatorController::destroyInstance();
}

void MainElevatorWindow::onElevatorIndexChange(int index)
{
  std::stringstream stream;
  stream << "Elevator " << index + 1 << " Controls";
  ui->ElevatorSelectLabel->setText(QString::fromStdString(stream.str()));
  emit elevatorIndexChange(index);
}

void MainElevatorWindow::onFloorIndexChange(int index)
{
  std::stringstream stream;
  selectedFloorIndex = index;
  stream << "Floor " << index + 1 << " Controls";
  ui->FloorSelectLabel->setText(QString::fromStdString(stream.str()));
  emit floorIndexChange(index);
}

void MainElevatorWindow::onBuildingResetButton()
{
  emit buildingResetButton();
}

