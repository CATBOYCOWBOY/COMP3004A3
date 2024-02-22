#ifndef MAINELEVATORWINDOW_H
#define MAINELEVATORWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainElevatorWindow *ui;
};
#endif // MAINELEVATORWINDOW_H
