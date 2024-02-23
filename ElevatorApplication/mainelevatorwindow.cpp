#include "mainelevatorwindow.h"
#include "ui_mainelevatorwindow.h"
#include "constants.h"

MainElevatorWindow::MainElevatorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainElevatorWindow)
{
    ui->setupUi(this);
    ui->primaryTabs->setTabText(0, "Elevator Controls");
    ui->primaryTabs->setTabText(1, "Floor Controls");
    ui->primaryTabs->setTabText(2, "Building Controls");

    controller = ElevatorController::getInstance(this, NUM_FLOORS, NUM_ELEVATORS);
}

MainElevatorWindow::~MainElevatorWindow()
{
    delete ui;
    ElevatorController::destroyInstance();
}


void MainElevatorWindow::on_ElevatorComboBox_currentIndexChanged(int index) {
    qDebug() << "Selected index: " << index << Qt::endl;
}

