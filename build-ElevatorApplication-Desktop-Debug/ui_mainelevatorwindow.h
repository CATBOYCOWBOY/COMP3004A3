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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainElevatorWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *primaryTabs;
    QWidget *Elevator_Controls;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QComboBox *ElevatorComboBox;
    QWidget *Floor_Controls;
    QWidget *Building_Controls;
    QMenuBar *menubar;
    QMenu *menuREI_Elevator_controls;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainElevatorWindow)
    {
        if (MainElevatorWindow->objectName().isEmpty())
            MainElevatorWindow->setObjectName("MainElevatorWindow");
        MainElevatorWindow->resize(800, 600);
        centralwidget = new QWidget(MainElevatorWindow);
        centralwidget->setObjectName("centralwidget");
        primaryTabs = new QTabWidget(centralwidget);
        primaryTabs->setObjectName("primaryTabs");
        primaryTabs->setGeometry(QRect(10, 9, 781, 551));
        Elevator_Controls = new QWidget();
        Elevator_Controls->setObjectName("Elevator_Controls");
        label = new QLabel(Elevator_Controls);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 67, 17));
        verticalLayoutWidget = new QWidget(Elevator_Controls);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 20, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        ElevatorComboBox = new QComboBox(verticalLayoutWidget);
        ElevatorComboBox->addItem(QString());
        ElevatorComboBox->addItem(QString());
        ElevatorComboBox->addItem(QString());
        ElevatorComboBox->setObjectName("ElevatorComboBox");

        verticalLayout->addWidget(ElevatorComboBox);

        primaryTabs->addTab(Elevator_Controls, QString());
        Floor_Controls = new QWidget();
        Floor_Controls->setObjectName("Floor_Controls");
        primaryTabs->addTab(Floor_Controls, QString());
        Building_Controls = new QWidget();
        Building_Controls->setObjectName("Building_Controls");
        primaryTabs->addTab(Building_Controls, QString());
        MainElevatorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainElevatorWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuREI_Elevator_controls = new QMenu(menubar);
        menuREI_Elevator_controls->setObjectName("menuREI_Elevator_controls");
        MainElevatorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainElevatorWindow);
        statusbar->setObjectName("statusbar");
        MainElevatorWindow->setStatusBar(statusbar);

        menubar->addAction(menuREI_Elevator_controls->menuAction());

        retranslateUi(MainElevatorWindow);

        primaryTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainElevatorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainElevatorWindow)
    {
        MainElevatorWindow->setWindowTitle(QCoreApplication::translate("MainElevatorWindow", "MainElevatorWindow", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainElevatorWindow", "Select Elevator", nullptr));
        ElevatorComboBox->setItemText(0, QCoreApplication::translate("MainElevatorWindow", "Elevator 1", nullptr));
        ElevatorComboBox->setItemText(1, QCoreApplication::translate("MainElevatorWindow", "Elevator 2", nullptr));
        ElevatorComboBox->setItemText(2, QCoreApplication::translate("MainElevatorWindow", "Elevator 3", nullptr));

        primaryTabs->setTabText(primaryTabs->indexOf(Elevator_Controls), QCoreApplication::translate("MainElevatorWindow", "Tab 1", nullptr));
        primaryTabs->setTabText(primaryTabs->indexOf(Floor_Controls), QCoreApplication::translate("MainElevatorWindow", "Tab 2", nullptr));
        primaryTabs->setTabText(primaryTabs->indexOf(Building_Controls), QCoreApplication::translate("MainElevatorWindow", "Page", nullptr));
        menuREI_Elevator_controls->setTitle(QCoreApplication::translate("MainElevatorWindow", "REI Elevator ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainElevatorWindow: public Ui_MainElevatorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINELEVATORWINDOW_H
