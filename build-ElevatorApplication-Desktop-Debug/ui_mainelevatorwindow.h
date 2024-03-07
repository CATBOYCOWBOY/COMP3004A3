/********************************************************************************
** Form generated from reading UI file 'mainelevatorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINELEVATORWINDOW_H
#define UI_MAINELEVATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QLabel *ElevatorSelectLabel;
    QPushButton *ElevatorOpen;
    QPushButton *ElevatorClose;
    QPushButton *ElevatorHelp;
    QPushButton *elevatorFireButton;
    QPushButton *elevatorBlockButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ElevatorOne;
    QSpacerItem *verticalSpacer;
    QPushButton *ElevatorTwo;
    QSpacerItem *verticalSpacer_2;
    QPushButton *ElevatorThree;
    QSpacerItem *verticalSpacer_3;
    QPushButton *ElevatorFour;
    QSpacerItem *verticalSpacer_4;
    QPushButton *ElevatorFive;
    QSpacerItem *verticalSpacer_5;
    QPushButton *ElevatorSix;
    QSpacerItem *verticalSpacer_6;
    QPushButton *ElevatorSeven;
    QFrame *ElevatorFrame;
    QLCDNumber *elevatorFloorDisplay;
    QLabel *label_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *ElevatorMessageBox;
    QLabel *label_6;
    QPushButton *elevatorOverButton;
    QPushButton *elevatorResetButton;
    QWidget *Floor_Controls;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QComboBox *FloorComboBox;
    QLabel *FloorSelectLabel;
    QPushButton *elevatorUpButton;
    QPushButton *pushButton_3;
    QWidget *Building_Controls;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QPushButton *fireButton;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_10;
    QPushButton *powerOutButton;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *verticalSpacer_11;
    QPushButton *handleHelpButton;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer_15;
    QSpacerItem *verticalSpacer_14;
    QPushButton *resetButton;
    QLabel *buildingControlLabel;
    QMenuBar *menubar;
    QMenu *menuREI_Elevator_controls;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainElevatorWindow)
    {
        if (MainElevatorWindow->objectName().isEmpty())
            MainElevatorWindow->setObjectName(QString::fromUtf8("MainElevatorWindow"));
        MainElevatorWindow->resize(800, 600);
        centralwidget = new QWidget(MainElevatorWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        primaryTabs = new QTabWidget(centralwidget);
        primaryTabs->setObjectName(QString::fromUtf8("primaryTabs"));
        primaryTabs->setGeometry(QRect(10, 9, 781, 551));
        Elevator_Controls = new QWidget();
        Elevator_Controls->setObjectName(QString::fromUtf8("Elevator_Controls"));
        label = new QLabel(Elevator_Controls);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 67, 17));
        verticalLayoutWidget = new QWidget(Elevator_Controls);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        ElevatorComboBox = new QComboBox(verticalLayoutWidget);
        ElevatorComboBox->addItem(QString());
        ElevatorComboBox->addItem(QString());
        ElevatorComboBox->addItem(QString());
        ElevatorComboBox->setObjectName(QString::fromUtf8("ElevatorComboBox"));

        verticalLayout->addWidget(ElevatorComboBox);

        ElevatorSelectLabel = new QLabel(verticalLayoutWidget);
        ElevatorSelectLabel->setObjectName(QString::fromUtf8("ElevatorSelectLabel"));

        verticalLayout->addWidget(ElevatorSelectLabel);

        ElevatorOpen = new QPushButton(Elevator_Controls);
        ElevatorOpen->setObjectName(QString::fromUtf8("ElevatorOpen"));
        ElevatorOpen->setGeometry(QRect(250, 150, 89, 25));
        ElevatorClose = new QPushButton(Elevator_Controls);
        ElevatorClose->setObjectName(QString::fromUtf8("ElevatorClose"));
        ElevatorClose->setGeometry(QRect(250, 190, 89, 25));
        ElevatorHelp = new QPushButton(Elevator_Controls);
        ElevatorHelp->setObjectName(QString::fromUtf8("ElevatorHelp"));
        ElevatorHelp->setGeometry(QRect(250, 280, 89, 25));
        elevatorFireButton = new QPushButton(Elevator_Controls);
        elevatorFireButton->setObjectName(QString::fromUtf8("elevatorFireButton"));
        elevatorFireButton->setGeometry(QRect(250, 340, 89, 25));
        elevatorBlockButton = new QPushButton(Elevator_Controls);
        elevatorBlockButton->setObjectName(QString::fromUtf8("elevatorBlockButton"));
        elevatorBlockButton->setGeometry(QRect(250, 410, 89, 25));
        verticalLayoutWidget_2 = new QWidget(Elevator_Controls);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 150, 160, 249));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ElevatorOne = new QPushButton(verticalLayoutWidget_2);
        ElevatorOne->setObjectName(QString::fromUtf8("ElevatorOne"));

        verticalLayout_2->addWidget(ElevatorOne);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        ElevatorTwo = new QPushButton(verticalLayoutWidget_2);
        ElevatorTwo->setObjectName(QString::fromUtf8("ElevatorTwo"));

        verticalLayout_2->addWidget(ElevatorTwo);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        ElevatorThree = new QPushButton(verticalLayoutWidget_2);
        ElevatorThree->setObjectName(QString::fromUtf8("ElevatorThree"));

        verticalLayout_2->addWidget(ElevatorThree);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        ElevatorFour = new QPushButton(verticalLayoutWidget_2);
        ElevatorFour->setObjectName(QString::fromUtf8("ElevatorFour"));

        verticalLayout_2->addWidget(ElevatorFour);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        ElevatorFive = new QPushButton(verticalLayoutWidget_2);
        ElevatorFive->setObjectName(QString::fromUtf8("ElevatorFive"));

        verticalLayout_2->addWidget(ElevatorFive);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        ElevatorSix = new QPushButton(verticalLayoutWidget_2);
        ElevatorSix->setObjectName(QString::fromUtf8("ElevatorSix"));

        verticalLayout_2->addWidget(ElevatorSix);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        ElevatorSeven = new QPushButton(verticalLayoutWidget_2);
        ElevatorSeven->setObjectName(QString::fromUtf8("ElevatorSeven"));

        verticalLayout_2->addWidget(ElevatorSeven);

        ElevatorFrame = new QFrame(Elevator_Controls);
        ElevatorFrame->setObjectName(QString::fromUtf8("ElevatorFrame"));
        ElevatorFrame->setGeometry(QRect(440, 150, 231, 171));
        ElevatorFrame->setFrameShape(QFrame::StyledPanel);
        ElevatorFrame->setFrameShadow(QFrame::Raised);
        elevatorFloorDisplay = new QLCDNumber(ElevatorFrame);
        elevatorFloorDisplay->setObjectName(QString::fromUtf8("elevatorFloorDisplay"));
        elevatorFloorDisplay->setGeometry(QRect(20, 60, 64, 23));
        elevatorFloorDisplay->setAutoFillBackground(false);
        elevatorFloorDisplay->setSmallDecimalPoint(false);
        label_3 = new QLabel(ElevatorFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 30, 131, 20));
        verticalLayoutWidget_3 = new QWidget(ElevatorFrame);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 160, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        ElevatorMessageBox = new QLabel(ElevatorFrame);
        ElevatorMessageBox->setObjectName(QString::fromUtf8("ElevatorMessageBox"));
        ElevatorMessageBox->setGeometry(QRect(10, 120, 201, 17));
        label_6 = new QLabel(Elevator_Controls);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(250, 390, 111, 17));
        elevatorOverButton = new QPushButton(Elevator_Controls);
        elevatorOverButton->setObjectName(QString::fromUtf8("elevatorOverButton"));
        elevatorOverButton->setGeometry(QRect(250, 440, 111, 41));
        elevatorResetButton = new QPushButton(Elevator_Controls);
        elevatorResetButton->setObjectName(QString::fromUtf8("elevatorResetButton"));
        elevatorResetButton->setGeometry(QRect(250, 490, 83, 25));
        primaryTabs->addTab(Elevator_Controls, QString());
        Floor_Controls = new QWidget();
        Floor_Controls->setObjectName(QString::fromUtf8("Floor_Controls"));
        verticalLayoutWidget_4 = new QWidget(Floor_Controls);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(310, 50, 160, 80));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        FloorComboBox = new QComboBox(verticalLayoutWidget_4);
        FloorComboBox->addItem(QString());
        FloorComboBox->addItem(QString());
        FloorComboBox->addItem(QString());
        FloorComboBox->addItem(QString());
        FloorComboBox->addItem(QString());
        FloorComboBox->addItem(QString());
        FloorComboBox->addItem(QString());
        FloorComboBox->setObjectName(QString::fromUtf8("FloorComboBox"));

        verticalLayout_4->addWidget(FloorComboBox);

        FloorSelectLabel = new QLabel(verticalLayoutWidget_4);
        FloorSelectLabel->setObjectName(QString::fromUtf8("FloorSelectLabel"));

        verticalLayout_4->addWidget(FloorSelectLabel);

        elevatorUpButton = new QPushButton(Floor_Controls);
        elevatorUpButton->setObjectName(QString::fromUtf8("elevatorUpButton"));
        elevatorUpButton->setGeometry(QRect(340, 230, 89, 25));
        pushButton_3 = new QPushButton(Floor_Controls);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 320, 89, 25));
        primaryTabs->addTab(Floor_Controls, QString());
        Building_Controls = new QWidget();
        Building_Controls->setObjectName(QString::fromUtf8("Building_Controls"));
        verticalLayoutWidget_5 = new QWidget(Building_Controls);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(290, 140, 176, 197));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_7);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_8);

        fireButton = new QPushButton(verticalLayoutWidget_5);
        fireButton->setObjectName(QString::fromUtf8("fireButton"));

        verticalLayout_5->addWidget(fireButton);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_9);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_10);

        powerOutButton = new QPushButton(verticalLayoutWidget_5);
        powerOutButton->setObjectName(QString::fromUtf8("powerOutButton"));

        verticalLayout_5->addWidget(powerOutButton);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_12);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_11);

        handleHelpButton = new QPushButton(verticalLayoutWidget_5);
        handleHelpButton->setObjectName(QString::fromUtf8("handleHelpButton"));

        verticalLayout_5->addWidget(handleHelpButton);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_13);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_15);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_14);

        resetButton = new QPushButton(verticalLayoutWidget_5);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        verticalLayout_5->addWidget(resetButton);

        buildingControlLabel = new QLabel(Building_Controls);
        buildingControlLabel->setObjectName(QString::fromUtf8("buildingControlLabel"));
        buildingControlLabel->setGeometry(QRect(350, 90, 67, 17));
        primaryTabs->addTab(Building_Controls, QString());
        MainElevatorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainElevatorWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuREI_Elevator_controls = new QMenu(menubar);
        menuREI_Elevator_controls->setObjectName(QString::fromUtf8("menuREI_Elevator_controls"));
        MainElevatorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainElevatorWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
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

        ElevatorSelectLabel->setText(QCoreApplication::translate("MainElevatorWindow", "Elevator 1 Controls", nullptr));
        ElevatorOpen->setText(QCoreApplication::translate("MainElevatorWindow", "Open", nullptr));
        ElevatorClose->setText(QCoreApplication::translate("MainElevatorWindow", "Close", nullptr));
        ElevatorHelp->setText(QCoreApplication::translate("MainElevatorWindow", "Help", nullptr));
        elevatorFireButton->setText(QCoreApplication::translate("MainElevatorWindow", "Fire", nullptr));
        elevatorBlockButton->setText(QCoreApplication::translate("MainElevatorWindow", "Block Door", nullptr));
        ElevatorOne->setText(QCoreApplication::translate("MainElevatorWindow", "1", nullptr));
        ElevatorTwo->setText(QCoreApplication::translate("MainElevatorWindow", "2", nullptr));
        ElevatorThree->setText(QCoreApplication::translate("MainElevatorWindow", "3", nullptr));
        ElevatorFour->setText(QCoreApplication::translate("MainElevatorWindow", "4", nullptr));
        ElevatorFive->setText(QCoreApplication::translate("MainElevatorWindow", "5", nullptr));
        ElevatorSix->setText(QCoreApplication::translate("MainElevatorWindow", "6", nullptr));
        ElevatorSeven->setText(QCoreApplication::translate("MainElevatorWindow", "7", nullptr));
        label_3->setText(QCoreApplication::translate("MainElevatorWindow", "Current Floor", nullptr));
        ElevatorMessageBox->setText(QString());
        label_6->setText(QCoreApplication::translate("MainElevatorWindow", "TESTING ONLY", nullptr));
        elevatorOverButton->setText(QCoreApplication::translate("MainElevatorWindow", "Overload", nullptr));
        elevatorResetButton->setText(QCoreApplication::translate("MainElevatorWindow", "Reset", nullptr));
        primaryTabs->setTabText(primaryTabs->indexOf(Elevator_Controls), QCoreApplication::translate("MainElevatorWindow", "Tab 1", nullptr));
        label_4->setText(QCoreApplication::translate("MainElevatorWindow", "Select Floor", nullptr));
        FloorComboBox->setItemText(0, QCoreApplication::translate("MainElevatorWindow", "1", nullptr));
        FloorComboBox->setItemText(1, QCoreApplication::translate("MainElevatorWindow", "2", nullptr));
        FloorComboBox->setItemText(2, QCoreApplication::translate("MainElevatorWindow", "3", nullptr));
        FloorComboBox->setItemText(3, QCoreApplication::translate("MainElevatorWindow", "4", nullptr));
        FloorComboBox->setItemText(4, QCoreApplication::translate("MainElevatorWindow", "5", nullptr));
        FloorComboBox->setItemText(5, QCoreApplication::translate("MainElevatorWindow", "6", nullptr));
        FloorComboBox->setItemText(6, QCoreApplication::translate("MainElevatorWindow", "7", nullptr));

        FloorSelectLabel->setText(QCoreApplication::translate("MainElevatorWindow", "Floor 1 Controls", nullptr));
        elevatorUpButton->setText(QCoreApplication::translate("MainElevatorWindow", "UP", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainElevatorWindow", "DOWN", nullptr));
        primaryTabs->setTabText(primaryTabs->indexOf(Floor_Controls), QCoreApplication::translate("MainElevatorWindow", "Tab 2", nullptr));
        label_5->setText(QCoreApplication::translate("MainElevatorWindow", "REI BUILDING CONTROLS", nullptr));
        fireButton->setText(QCoreApplication::translate("MainElevatorWindow", "Trigger Fire Alarm", nullptr));
        powerOutButton->setText(QCoreApplication::translate("MainElevatorWindow", "Trigger Power Out", nullptr));
        handleHelpButton->setText(QCoreApplication::translate("MainElevatorWindow", "Handle Help Request(s)", nullptr));
        resetButton->setText(QCoreApplication::translate("MainElevatorWindow", "Reset", nullptr));
        buildingControlLabel->setText(QCoreApplication::translate("MainElevatorWindow", "TextLabel", nullptr));
        primaryTabs->setTabText(primaryTabs->indexOf(Building_Controls), QCoreApplication::translate("MainElevatorWindow", "Page", nullptr));
        menuREI_Elevator_controls->setTitle(QCoreApplication::translate("MainElevatorWindow", "REI Elevator ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainElevatorWindow: public Ui_MainElevatorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINELEVATORWINDOW_H
