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
    QPushButton *glock;
    QPushButton *ak47;
    QPushButton *m3;
    QPushButton *awp;
    QPushButton *cofre;
    QPushButton *corona;
    QPushButton *cruz;
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
        scrollArea->setGeometry(QRect(430, 30, 120, 291));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 289));
        glock = new QPushButton(scrollAreaWidgetContents);
        glock->setObjectName(QString::fromUtf8("glock"));
        glock->setGeometry(QRect(0, 0, 121, 25));
        ak47 = new QPushButton(scrollAreaWidgetContents);
        ak47->setObjectName(QString::fromUtf8("ak47"));
        ak47->setGeometry(QRect(0, 30, 121, 25));
        m3 = new QPushButton(scrollAreaWidgetContents);
        m3->setObjectName(QString::fromUtf8("m3"));
        m3->setGeometry(QRect(0, 60, 121, 25));
        awp = new QPushButton(scrollAreaWidgetContents);
        awp->setObjectName(QString::fromUtf8("awp"));
        awp->setGeometry(QRect(0, 90, 121, 25));
        cofre = new QPushButton(scrollAreaWidgetContents);
        cofre->setObjectName(QString::fromUtf8("cofre"));
        cofre->setGeometry(QRect(0, 120, 121, 25));
        corona = new QPushButton(scrollAreaWidgetContents);
        corona->setObjectName(QString::fromUtf8("corona"));
        corona->setGeometry(QRect(0, 150, 121, 25));
        cruz = new QPushButton(scrollAreaWidgetContents);
        cruz->setObjectName(QString::fromUtf8("cruz"));
        cruz->setGeometry(QRect(-2, 180, 121, 25));
        scrollArea->setWidget(scrollAreaWidgetContents);
        map = new QGraphicsView(centralwidget);
        map->setObjectName(QString::fromUtf8("map"));
        map->setGeometry(QRect(0, 30, 431, 291));
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
        glock->setText(QApplication::translate("MainWindow", "Glock", nullptr));
        ak47->setText(QApplication::translate("MainWindow", "AK-47", nullptr));
        m3->setText(QApplication::translate("MainWindow", "M3", nullptr));
        awp->setText(QApplication::translate("MainWindow", "AWP", nullptr));
        cofre->setText(QApplication::translate("MainWindow", "Cofre", nullptr));
        corona->setText(QApplication::translate("MainWindow", "Corona", nullptr));
        cruz->setText(QApplication::translate("MainWindow", "Cruz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
