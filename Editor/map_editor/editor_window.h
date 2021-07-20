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
#include <vector>
#include <algorithm>
#include "yaml-cpp/yaml.h"
#include "Paths.h"

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
        void saveBases();
        void saveObjects();
        void makeSquared(YAML::Emitter &emitter);
        void moveMap(YAML::Emitter &emitter);
        size_t width();
        size_t heigth();
        size_t min_x;
        size_t min_y;
        size_t max_x;
        size_t max_y;
        std::vector<YAML::Node> nodes;
        bool isFloor();
        QGraphicsPixmapItem* createFloor();
        QGraphicsPixmapItem* createPlaceable();
        QGraphicsPixmapItem* createNewItem();
        QGraphicsPixmapItem* createSpawn();
        void addSquare(QMouseEvent* event);
        bool thereIsFloorIn(int &x, int &y);
        bool thereIsWeaponIn(int &x, int &y);
        bool thereIsBoxIn(int &x, int &y);
        bool thereIsBombPlaceIn(int &x, int &y);
        bool thereIsSpawnIn(int &x, int &y);
        std::vector<std::pair<int,int>> floor;
        std::vector<std::pair<int,int>> weapon;
        std::vector<std::pair<int,int>> box;
        std::vector<std::pair<int,int>> bomb;
        std::vector<std::pair<int,int>> spawn;
        std::vector<std::pair<int,int>> positions_loaded;
        void removeFrom(const std::string& item, int x, int y);
        void placePos(int &x, int &y);
        bool hasPos(std::vector<size_t> &vector, size_t pos);
        void loadIcons();
        int delay_cnt;
        bool resized;

    private slots:
        void on_save_clicked();

        void on_load_clicked();

        void on_clean_all_clicked();

        void connectItems();

        void selectItem();

        void mouseReleaseEvent(QMouseEvent*) override;

        void mousePressEvent(QMouseEvent* event) override;

        void mouseMoveEvent(QMouseEvent* event) override;

        void on_button_clicked();
        void on_clean_selected_clicked();
};
#endif // MAINWINDOW_H
