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

  selectedFloorIndex = 0;

  controller = ElevatorController::getInstance(this);

  connect(ui->ElevatorComboBox,
      qOverload<int>(&QComboBox::currentIndexChanged),
      this,
      &MainElevatorWindow::onElevatorIndexChange);

  connect(ui->FloorComboBox,
      qOverload<int>(&QComboBox::currentIndexChanged),
      this,
      &MainElevatorWindow::onFloorIndexChange);

  connect(ui->resetButton, &QPushButton::clicked, this, &MainElevatorWindow::onResetButton);

  connect(this,
          qOverload<int>(&MainElevatorWindow::changeElevatorIndex),
          controller,
          &ElevatorController::onViewSelectElevator);

  connect(this,
          &MainElevatorWindow::resetButtonPressed,
          controller,
          &ElevatorController::onResetButton);

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
  emit changeElevatorIndex(index);
}

void MainElevatorWindow::onFloorIndexChange(int index)
{
  std::stringstream stream;
  selectedFloorIndex = index;
  stream << "Floor " << index + 1 << " Controls";
  ui->FloorSelectLabel->setText(QString::fromStdString(stream.str()));
}

void MainElevatorWindow::onResetButton()
{
  emit resetButtonPressed();
}

