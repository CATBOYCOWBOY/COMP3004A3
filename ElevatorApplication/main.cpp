#include "mainelevatorwindow.h"

#include <QApplication>
#include <elevatorcontroller.h>

//initialize singleton to null
ElevatorController* ElevatorController::instance = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainElevatorWindow w;
    w.show();
    return a.exec();
}
