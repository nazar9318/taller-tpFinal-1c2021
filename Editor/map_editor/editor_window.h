#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QPoint>
#include <QGraphicsPixmapItem>
#include <QGridLayout>
#include <QFileDialog>
#include <QObject>
#include "yaml-cpp/yaml.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
            Ui::MainWindow *ui;
            QGraphicsScene *scene;
            QString dragged;
            void saveBases(YAML::Emitter &emitter);
            void saveObjects(YAML::Emitter &emitter);
            size_t width();
            size_t height();
            bool isFloor();
            QGraphicsPixmapItem* createFloor();
            QGraphicsPixmapItem* createPlaceable();
            QGraphicsPixmapItem* createNewItem();

    private slots:
        void on_save_clicked();

        void on_load_clicked();

        void on_clean_clicked();

        void connectItems();

        void selectItem();

        void mouseReleaseEvent(QMouseEvent*) override;
};
#endif // MAINWINDOW_H