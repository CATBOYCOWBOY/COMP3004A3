#include "mainelevatorwindow.h"
#include "ui_mainelevatorwindow.h"

MainElevatorWindow::MainElevatorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainElevatorWindow)
{
    ui->setupUi(this);
}

MainElevatorWindow::~MainElevatorWindow()
{
    delete ui;
}
