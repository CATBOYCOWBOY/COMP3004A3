/********************************************************************************
** Form generated from reading UI file 'mainelevatorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINELEVATORWINDOW_H
#define UI_MAINELEVATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainElevatorWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainElevatorWindow)
    {
        if (MainElevatorWindow->objectName().isEmpty())
            MainElevatorWindow->setObjectName("MainElevatorWindow");
        MainElevatorWindow->resize(800, 600);
        centralwidget = new QWidget(MainElevatorWindow);
        centralwidget->setObjectName("centralwidget");
        MainElevatorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainElevatorWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainElevatorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainElevatorWindow);
        statusbar->setObjectName("statusbar");
        MainElevatorWindow->setStatusBar(statusbar);

        retranslateUi(MainElevatorWindow);

        QMetaObject::connectSlotsByName(MainElevatorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainElevatorWindow)
    {
        MainElevatorWindow->setWindowTitle(QCoreApplication::translate("MainElevatorWindow", "MainElevatorWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainElevatorWindow: public Ui_MainElevatorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINELEVATORWINDOW_H
