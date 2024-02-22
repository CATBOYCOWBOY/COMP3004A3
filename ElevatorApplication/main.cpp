#include "mainelevatorwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainElevatorWindow w;
    w.show();
    return a.exec();
}
