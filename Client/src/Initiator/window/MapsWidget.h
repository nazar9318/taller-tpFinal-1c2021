#ifndef _MAPS_WIDGET_H
#define _MAPS_WIDGET_H

#include <QPushButton>
#include "mainwindow.h"
/*************************************/
/* Citamos la documentacion de QT    */
/*************************************/
class MainWindow;

class MapsWidget : public QWidget {
    Q_OBJECT

public:
    MapsWidget(QStringList texts, MainWindow* main,
    				 QWidget *parent = 0);

signals:
    void clicked(const QString &text);

private:
    QSignalMapper *signalMapper;
    MainWindow* main;
};

#endif
