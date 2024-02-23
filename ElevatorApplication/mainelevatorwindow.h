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

private slots:
    void on_ElevatorComboBox_currentIndexChanged(int index);

private:
    Ui::MainElevatorWindow *ui;
    ElevatorController* controller = nullptr;

};
#endif // MAINELEVATORWINDOW_H
