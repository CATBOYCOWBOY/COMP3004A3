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

  selectedElevatorIndex = 0;
  selectedFloorIndex = 0;

  controller = ElevatorController::getInstance(this);
}

MainElevatorWindow::~MainElevatorWindow()
{
  delete ui;
  ElevatorController::destroyInstance();
}

void MainElevatorWindow::connectSlots()
{
  connect(ui->ElevatorComboBox,
      &QComboBox::currentIndexChanged,
      this,
      &MainElevatorWindow::onElevatorIndexChange);

  connect(ui->FloorComboBox,
      &QComboBox::currentIndexChanged,
      this,
      &MainElevatorWindow::onFloorIndexChange);
}


void MainElevatorWindow::onElevatorIndexChange(int index)
{
  std::stringstream stream;
  selectedElevatorIndex = index;
  stream << "Elevator " << index + 1 << " Controls";
  ui->ElevatorSelectLabel->setText(QString::fromStdString(stream.str()));
}

void MainElevatorWindow::onFloorIndexChange(int index)
{
  std::stringstream stream;
  selectedFloorIndex = index;
  stream << "Floor " << index + 1 << " Controls";
  ui->FloorSelectLabel->setText(QString::fromStdString(stream.str()));
}

