/********************************************************************************
** Form generated from reading UI file 'editor_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_WINDOW_H
#define UI_EDITOR_WINDOW_H

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
    QPushButton *glock_weapon;
    QPushButton *ak47_weapon;
    QPushButton *m3_weapon;
    QPushButton *awp_weapon;
    QPushButton *base_dust;
    QPushButton *base_inferno;
    QPushButton *base_aztec;
    QPushButton *box_brown;
    QPushButton *box_black;
    QPushButton *box_wood;
    QPushButton *box_wood_metal;
    QPushButton *box_metal;
    QPushButton *bomb_area_a;
    QPushButton *bomb_area_c;
    QPushButton *terrorist_spawn;
    QPushButton *counter_spawn;
    QPushButton *bomb_area_b;
    QGraphicsView *map;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(855, 612);
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
        scrollArea->setGeometry(QRect(630, 30, 120, 511));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 509));
        glock_weapon = new QPushButton(scrollAreaWidgetContents);
        glock_weapon->setObjectName(QString::fromUtf8("glock_weapon"));
        glock_weapon->setGeometry(QRect(0, 0, 121, 25));
        ak47_weapon = new QPushButton(scrollAreaWidgetContents);
        ak47_weapon->setObjectName(QString::fromUtf8("ak47_weapon"));
        ak47_weapon->setGeometry(QRect(0, 30, 121, 25));
        m3_weapon = new QPushButton(scrollAreaWidgetContents);
        m3_weapon->setObjectName(QString::fromUtf8("m3_weapon"));
        m3_weapon->setGeometry(QRect(0, 60, 121, 25));
        awp_weapon = new QPushButton(scrollAreaWidgetContents);
        awp_weapon->setObjectName(QString::fromUtf8("awp_weapon"));
        awp_weapon->setGeometry(QRect(0, 90, 121, 25));
        base_dust = new QPushButton(scrollAreaWidgetContents);
        base_dust->setObjectName(QString::fromUtf8("base_dust"));
        base_dust->setGeometry(QRect(0, 120, 121, 25));
        base_inferno = new QPushButton(scrollAreaWidgetContents);
        base_inferno->setObjectName(QString::fromUtf8("base_inferno"));
        base_inferno->setGeometry(QRect(0, 150, 121, 25));
        base_aztec = new QPushButton(scrollAreaWidgetContents);
        base_aztec->setObjectName(QString::fromUtf8("base_aztec"));
        base_aztec->setGeometry(QRect(0, 180, 121, 25));
        box_brown = new QPushButton(scrollAreaWidgetContents);
        box_brown->setObjectName(QString::fromUtf8("box_brown"));
        box_brown->setGeometry(QRect(0, 210, 121, 25));
        box_black = new QPushButton(scrollAreaWidgetContents);
        box_black->setObjectName(QString::fromUtf8("box_black"));
        box_black->setGeometry(QRect(0, 240, 121, 25));
        box_wood = new QPushButton(scrollAreaWidgetContents);
        box_wood->setObjectName(QString::fromUtf8("box_wood"));
        box_wood->setGeometry(QRect(0, 270, 121, 25));
        box_wood_metal = new QPushButton(scrollAreaWidgetContents);
        box_wood_metal->setObjectName(QString::fromUtf8("box_wood_metal"));
        box_wood_metal->setGeometry(QRect(0, 300, 121, 25));
        box_metal = new QPushButton(scrollAreaWidgetContents);
        box_metal->setObjectName(QString::fromUtf8("box_metal"));
        box_metal->setGeometry(QRect(0, 330, 121, 25));
        bomb_area_a = new QPushButton(scrollAreaWidgetContents);
        bomb_area_a->setObjectName(QString::fromUtf8("bomb_area_a"));
        bomb_area_a->setGeometry(QRect(-2, 360, 121, 25));
        bomb_area_c = new QPushButton(scrollAreaWidgetContents);
        bomb_area_c->setObjectName(QString::fromUtf8("bomb_area_c"));
        bomb_area_c->setGeometry(QRect(0, 420, 121, 25));
        terrorist_spawn = new QPushButton(scrollAreaWidgetContents);
        terrorist_spawn->setObjectName(QString::fromUtf8("terrorist_spawn"));
        terrorist_spawn->setGeometry(QRect(-2, 450, 121, 25));
        counter_spawn = new QPushButton(scrollAreaWidgetContents);
        counter_spawn->setObjectName(QString::fromUtf8("counter_spawn"));
        counter_spawn->setGeometry(QRect(0, 480, 121, 25));
        bomb_area_b = new QPushButton(scrollAreaWidgetContents);
        bomb_area_b->setObjectName(QString::fromUtf8("bomb_area_b"));
        bomb_area_b->setGeometry(QRect(-2, 390, 121, 25));
        scrollArea->setWidget(scrollAreaWidgetContents);
        map = new QGraphicsView(centralwidget);
        map->setObjectName(QString::fromUtf8("map"));
        map->setGeometry(QRect(0, 30, 631, 511));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 855, 22));
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
        glock_weapon->setText(QApplication::translate("MainWindow", "Glock", nullptr));
        ak47_weapon->setText(QApplication::translate("MainWindow", "AK-47", nullptr));
        m3_weapon->setText(QApplication::translate("MainWindow", "M3", nullptr));
        awp_weapon->setText(QApplication::translate("MainWindow", "AWP", nullptr));
        base_dust->setText(QApplication::translate("MainWindow", "Dust", nullptr));
        base_inferno->setText(QApplication::translate("MainWindow", "Inferno", nullptr));
        base_aztec->setText(QApplication::translate("MainWindow", "Aztec", nullptr));
        box_brown->setText(QApplication::translate("MainWindow", "Box Brown", nullptr));
        box_black->setText(QApplication::translate("MainWindow", "Box Black", nullptr));
        box_wood->setText(QApplication::translate("MainWindow", "Box Wood", nullptr));
        box_wood_metal->setText(QApplication::translate("MainWindow", "Box Wood Metal", nullptr));
        box_metal->setText(QApplication::translate("MainWindow", "Box Metal", nullptr));
        bomb_area_a->setText(QApplication::translate("MainWindow", "Bomb Area A", nullptr));
        bomb_area_c->setText(QApplication::translate("MainWindow", "Bomb Area C", nullptr));
        terrorist_spawn->setText(QApplication::translate("MainWindow", "Terrorist Spawn", nullptr));
        counter_spawn->setText(QApplication::translate("MainWindow", "Counter Spawn", nullptr));
        bomb_area_b->setText(QApplication::translate("MainWindow", "Bomb Area B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_WINDOW_H
