#ifndef _MATCHES_WIDGET_H
#define _MATCHES_WIDGET_H

#include <QPushButton>
#include "mainwindow.h"
/*************************************/
/* Citamos la documentacion de QT    */
/*************************************/
class MainWindow;
class MatchesWidget : public QWidget {
    Q_OBJECT

public:
    MatchesWidget(QStringList texts, MainWindow* main,
    				 QWidget *parent = 0);

signals:
    void clicked(const QString &text);

private:
    QSignalMapper *signalMapper;
    MainWindow* main;
};

#endif
