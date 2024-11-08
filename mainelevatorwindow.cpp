#include "mainelevatorwindow.h"
#include "ui_mainelevatorwindow.h"
#include <sstream>
#include <QtGui>

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
  ui->buildingControlLabel->setAlignment(Qt::AlignCenter);

  ui->elevatorFloorDisplay->setSegmentStyle(QLCDNumber::Flat);

  controller = ElevatorController::getInstance();

  connectControllerSlots();
}

MainElevatorWindow::~MainElevatorWindow()
{
  delete ui;
  ElevatorController::destroyInstance();
}

void MainElevatorWindow::onElevatorIndexChange(int index)
{
  emit elevatorIndexChange(index);
  std::stringstream stream;
  stream << "Elevator " << index + 1 << " Controls";
  ui->ElevatorSelectLabel->setText(QString::fromStdString(stream.str()));
  ui->elevatorFloorDisplay->display(controller->getCurrentElevatorPostition());
  ui->ElevatorMessageBox->setText(controller->getCurrentElevatorMessage());
}

void MainElevatorWindow::onFloorIndexChange(int index)
{
  emit floorIndexChange(index);
  std::stringstream stream;
  selectedFloorIndex = index;
  stream << "Floor " << index + 1 << " Controls";
  ui->FloorSelectLabel->setText(QString::fromStdString(stream.str()));
}

void MainElevatorWindow::on_ElevatorOne_clicked()
{
  emit elevatorPanelRequest(0);
}


void MainElevatorWindow::on_ElevatorTwo_clicked()
{
  emit elevatorPanelRequest(1);
}


void MainElevatorWindow::on_ElevatorThree_clicked()
{
  emit elevatorPanelRequest(2);
}


void MainElevatorWindow::on_ElevatorFour_clicked()
{
  emit elevatorPanelRequest(3);
}


void MainElevatorWindow::on_ElevatorFive_clicked()
{
  emit elevatorPanelRequest(4);
}


void MainElevatorWindow::on_ElevatorSix_clicked()
{
  emit elevatorPanelRequest(5);
}


void MainElevatorWindow::on_ElevatorSeven_clicked()
{
  emit elevatorPanelRequest(6);
}


void MainElevatorWindow::on_ElevatorOpenButton_pressed()
{
  emit elevatorOpenRequest(true);
}


void MainElevatorWindow::on_ElevatorOpenButton_released()
{
  emit elevatorOpenRequest(false);
}


void MainElevatorWindow::on_ElevatorCloseButton_clicked()
{
  emit elevatorCloseRequest();
}


void MainElevatorWindow::on_ElevatorHelpButton_clicked()
{
  ui->buildingControlLabel->setText("Elevator needs help!");
  emit elevatorHelpButton();
}


void MainElevatorWindow::on_elevatorFireButton_clicked()
{
  emit elevatorFireButton();
}

void MainElevatorWindow::on_elevatorBlockButton_clicked()
{
  emit elevatorBlockButton();
}


void MainElevatorWindow::on_elevatorOverButton_clicked()
{
  emit elevatorOverButton();
}


void MainElevatorWindow::on_elevatorResetButton_clicked()
{
  emit elevatorResetButton();
}


void MainElevatorWindow::on_elevatorUpButton_clicked()
{
  emit floorButtonPushed();
}


void MainElevatorWindow::on_pushButton_3_clicked()
{
  emit floorButtonPushed();
}


void MainElevatorWindow::on_fireButton_clicked()
{
  ui->buildingControlLabel->setText("Building on fire!");
  emit buildingFireButton();
}


void MainElevatorWindow::on_powerOutButton_clicked()
{
  ui->buildingControlLabel->setText("Elevators lost power!");
  emit buildingOutageButton();
}


void MainElevatorWindow::on_handleHelpButton_clicked()
{
  ui->buildingControlLabel->setText("");
  emit handleHelpButton();
}


void MainElevatorWindow::on_resetButton_clicked()
{
  ui->buildingControlLabel->setText("");
  emit buildingResetButton();
}

void MainElevatorWindow::onElevatorFloorChanged()
{
  ui->elevatorFloorDisplay->display(controller->getCurrentElevatorPostition());
}

void MainElevatorWindow::onElevatorMessageChanged()
{
  ui->ElevatorMessageBox->setText(controller->getCurrentElevatorMessage());
}

void MainElevatorWindow::on_ElevatorComboBox_currentIndexChanged(int index)
{
  onElevatorIndexChange(index);
}



void MainElevatorWindow::on_FloorComboBox_currentIndexChanged(int index)
{
  onFloorIndexChange(index);
}


void MainElevatorWindow::connectControllerSlots()
{

  connect(this, &MainElevatorWindow::elevatorIndexChange, controller, &ElevatorController::onElevatorIndexChange);
  connect(this, &MainElevatorWindow::floorIndexChange, controller, &ElevatorController::onFloorIndexChange);
  connect(this, &MainElevatorWindow::elevatorPanelRequest, controller, &ElevatorController::onElevatorPanelRequest);
  connect(this, &MainElevatorWindow::elevatorOpenRequest, controller, &ElevatorController::onElevatorOpenRequest, Qt::DirectConnection);
  connect(this, &MainElevatorWindow::elevatorCloseRequest, controller, &ElevatorController::onElevatorCloseRequest);
  connect(this, &MainElevatorWindow::floorButtonPushed, controller, &ElevatorController::onFloorButtonRequest);
  connect(this, &MainElevatorWindow::elevatorFireButton, controller, &ElevatorController::onElevatorFireButton);
  connect(this, &MainElevatorWindow::elevatorHelpButton, controller, &ElevatorController::onElevatorHelpButton);
  connect(this, &MainElevatorWindow::elevatorOverButton, controller, &ElevatorController::onElevatorOverButton);
  connect(this, &MainElevatorWindow::elevatorBlockButton, controller, &ElevatorController::onElevatorBlockButton);
  connect(this, &MainElevatorWindow::elevatorResetButton, controller, &ElevatorController::onElevatorResetButton);
  connect(this, &MainElevatorWindow::buildingFireButton, controller, &ElevatorController::onBuildingFireButton);
  connect(this, &MainElevatorWindow::buildingOutageButton, controller, &ElevatorController::onBuildingOutageButton);
  connect(this, &MainElevatorWindow::buildingResetButton, controller, &ElevatorController::onBuildingResetButton);
  connect(this, &MainElevatorWindow::handleHelpButton, controller, &ElevatorController::buildingHandleHelp);

  connect(controller, &ElevatorController::elevatorFloorChanged, this, &MainElevatorWindow::onElevatorFloorChanged);
  connect(controller, &ElevatorController::elevatorMessageChanged, this, &MainElevatorWindow::onElevatorMessageChanged);
}


