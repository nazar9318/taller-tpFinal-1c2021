/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *load;
    QPushButton *save;
    QPushButton *clean;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *glock_m;
    QPushButton *ak47_m;
    QPushButton *m3_m;
    QPushButton *awp_m;
    QPushButton *default_dust;
    QPushButton *default_inferno;
    QPushButton *default_aztec;
    QPushButton *dust;
    QPushButton *inferno;
    QPushButton *aztec;
    QPushButton *box_brown;
    QPushButton *box_black;
    QPushButton *box_wood;
    QPushButton *box_wood_metal;
    QPushButton *box_metal;
    QGraphicsView *map;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        load = new QPushButton(centralwidget);
        load->setObjectName(QString::fromUtf8("load"));
        load->setGeometry(QRect(0, 0, 89, 25));
        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(90, 0, 89, 25));
        clean = new QPushButton(centralwidget);
        clean->setObjectName(QString::fromUtf8("clean"));
        clean->setGeometry(QRect(180, 0, 89, 25));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(430, 30, 120, 451));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 449));
        glock_m = new QPushButton(scrollAreaWidgetContents);
        glock_m->setObjectName(QString::fromUtf8("glock_m"));
        glock_m->setGeometry(QRect(0, 0, 121, 25));
        ak47_m = new QPushButton(scrollAreaWidgetContents);
        ak47_m->setObjectName(QString::fromUtf8("ak47_m"));
        ak47_m->setGeometry(QRect(0, 30, 121, 25));
        m3_m = new QPushButton(scrollAreaWidgetContents);
        m3_m->setObjectName(QString::fromUtf8("m3_m"));
        m3_m->setGeometry(QRect(0, 60, 121, 25));
        awp_m = new QPushButton(scrollAreaWidgetContents);
        awp_m->setObjectName(QString::fromUtf8("awp_m"));
        awp_m->setGeometry(QRect(0, 90, 121, 25));
        default_dust = new QPushButton(scrollAreaWidgetContents);
        default_dust->setObjectName(QString::fromUtf8("default_dust"));
        default_dust->setGeometry(QRect(0, 120, 121, 25));
        default_inferno = new QPushButton(scrollAreaWidgetContents);
        default_inferno->setObjectName(QString::fromUtf8("default_inferno"));
        default_inferno->setGeometry(QRect(0, 150, 121, 25));
        default_aztec = new QPushButton(scrollAreaWidgetContents);
        default_aztec->setObjectName(QString::fromUtf8("default_aztec"));
        default_aztec->setGeometry(QRect(-2, 180, 121, 25));
        dust = new QPushButton(scrollAreaWidgetContents);
        dust->setObjectName(QString::fromUtf8("dust"));
        dust->setGeometry(QRect(0, 210, 121, 25));
        inferno = new QPushButton(scrollAreaWidgetContents);
        inferno->setObjectName(QString::fromUtf8("inferno"));
        inferno->setGeometry(QRect(0, 240, 121, 25));
        aztec = new QPushButton(scrollAreaWidgetContents);
        aztec->setObjectName(QString::fromUtf8("aztec"));
        aztec->setGeometry(QRect(0, 270, 121, 25));
        box_brown = new QPushButton(scrollAreaWidgetContents);
        box_brown->setObjectName(QString::fromUtf8("box_brown"));
        box_brown->setGeometry(QRect(0, 300, 121, 25));
        box_black = new QPushButton(scrollAreaWidgetContents);
        box_black->setObjectName(QString::fromUtf8("box_black"));
        box_black->setGeometry(QRect(0, 330, 121, 25));
        box_wood = new QPushButton(scrollAreaWidgetContents);
        box_wood->setObjectName(QString::fromUtf8("box_wood"));
        box_wood->setGeometry(QRect(0, 360, 121, 25));
        box_wood_metal = new QPushButton(scrollAreaWidgetContents);
        box_wood_metal->setObjectName(QString::fromUtf8("box_wood_metal"));
        box_wood_metal->setGeometry(QRect(-2, 390, 121, 25));
        box_metal = new QPushButton(scrollAreaWidgetContents);
        box_metal->setObjectName(QString::fromUtf8("box_metal"));
        box_metal->setGeometry(QRect(0, 420, 121, 25));
        scrollArea->setWidget(scrollAreaWidgetContents);
        map = new QGraphicsView(centralwidget);
        map->setObjectName(QString::fromUtf8("map"));
        map->setGeometry(QRect(0, 30, 431, 451));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        load->setText(QApplication::translate("MainWindow", "Load", nullptr));
        save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        clean->setText(QApplication::translate("MainWindow", "Clean", nullptr));
        glock_m->setText(QApplication::translate("MainWindow", "Glock", nullptr));
        ak47_m->setText(QApplication::translate("MainWindow", "AK-47", nullptr));
        m3_m->setText(QApplication::translate("MainWindow", "M3", nullptr));
        awp_m->setText(QApplication::translate("MainWindow", "AWP", nullptr));
        default_dust->setText(QApplication::translate("MainWindow", "Default Dust", nullptr));
        default_inferno->setText(QApplication::translate("MainWindow", "Default Inferno", nullptr));
        default_aztec->setText(QApplication::translate("MainWindow", "Default Aztec", nullptr));
        dust->setText(QApplication::translate("MainWindow", "Dust", nullptr));
        inferno->setText(QApplication::translate("MainWindow", "Inferno", nullptr));
        aztec->setText(QApplication::translate("MainWindow", "Aztec", nullptr));
        box_brown->setText(QApplication::translate("MainWindow", "Box Brown", nullptr));
        box_black->setText(QApplication::translate("MainWindow", "Box Black", nullptr));
        box_wood->setText(QApplication::translate("MainWindow", "Box Wood", nullptr));
        box_wood_metal->setText(QApplication::translate("MainWindow", "Box Wood Metal", nullptr));
        box_metal->setText(QApplication::translate("MainWindow", "Box Metal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
