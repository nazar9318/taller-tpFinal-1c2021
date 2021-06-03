#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QGraphicsPixmapItem>

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

    private slots:
        void on_save_clicked();

        void on_load_clicked();

        void on_clean_clicked();

        void loadImages();

        void connectItems();

        void selectItem();

        void mouseReleaseEvent(QMouseEvent*) override;

        //void mousePressEvent(QMouseEvent*) override;

        //void on_ametralladora_clicked();
};
#endif // MAINWINDOW_H
