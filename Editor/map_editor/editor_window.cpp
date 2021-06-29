#include "editor_window.h"
#include "./ui_editor_window.h"
#include <fstream>
#include <QLayoutItem>
#include <QLabel>
#include <QMouseEvent>
#include <math.h>
#include <cstdlib>
#include <QGraphicsRectItem>

#define BASE_X 65
#define BASE_Y 65
#define FLOOR_SIZE 64

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent), ui(new Ui::MainWindow) {
    this->ui->setupUi(this);
    scene = new QGraphicsScene(this);
    this->ui->map->setScene(scene);
    for (int x = 0; x <= 1000; x += BASE_X) {
        scene->addLine(x, 0, x, 1000, QPen(Qt::black));
    }
    for (int y = 0; y <= 1000; y += BASE_Y) {
        scene->addLine(0, y, 1000, y, QPen(Qt::black));
    }
    this->connectItems();
}

void MainWindow::saveObjects(YAML::Emitter &emitter) {
    int i = 0;
    for (auto item : this->scene->items()) {
        std::string name(item->data(0).toString().toStdString());
        if ((name.find("weapon") != std::string::npos) || (name.find("box") != std::string::npos) ||
            (name.find("bomb") != std::string::npos) || (name.find("spawn") != std::string::npos)) {
            YAML::Node node;
            node["node"] = i;
            i++;
            YAML::Node coordinates;
            coordinates.push_back((int)item->pos().x()/BASE_X);
            coordinates.push_back((int)item->pos().y()/BASE_X);
            node["item"] = item->data(0).toString().toStdString();
            node["position"] = coordinates;
            emitter << node;
        }
    }
}

void MainWindow::saveBases(YAML::Emitter &emitter) {
    int i = 0;
    for (auto item : this->scene->items()) {
        std::string name(item->data(0).toString().toStdString());
        if ((name.find("base") != std::string::npos)) {
            YAML::Node node;
            node["node"] = i;
            i++;
            YAML::Node coordinates;
            coordinates.push_back((int)item->pos().x()/BASE_X);
            coordinates.push_back((int)item->pos().y()/BASE_Y);
            node["item"] = item->data(0).toString().toStdString();
            node["position"] = coordinates;
            emitter << node;
        }
    }
}

size_t MainWindow::height() {
    size_t height = 0;
    for (auto item : this->scene->items()) {
        std::string name(item->data(0).toString().toStdString());
        if (name.size() > 0) {
            if ((size_t) item->pos().y() > height) {
                height = (size_t)item->pos().y();
            }
        }
    }
    return height/BASE_Y+1;
}

size_t MainWindow::width() {
    size_t width = 0;
    for (auto item : this->scene->items()) {
        std::string name(item->data(0).toString().toStdString());
        if (name.size() > 0) {
            if ((size_t) item->pos().x() > width) {
                width = (size_t)item->pos().x();
            }
        }
    }
    return width/BASE_X+1;
}

void MainWindow::on_save_clicked() {
    YAML::Emitter emitter;
    YAML::Node size;
    size["width"] = this->width();
    size["height"] = this->height();
    emitter << size;
    this->saveBases(emitter);
    this->saveObjects(emitter);
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Address Book"), "../configs/",
            tr("Address Book (*.yml);;All Files (*)"));
    std::ofstream out(fileName.toStdString());
    out << emitter.c_str();
}

void MainWindow::on_load_clicked() {
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "../configs/");
    std::vector<YAML::Node> nodes = YAML::LoadAllFromFile(file_name.toStdString());
    for (size_t i = 1; i < nodes.size(); i++) {
        QGraphicsPixmapItem *item;
        const std::string &new_item_name = nodes[i]["item"].as<std::string>();
        QString q_new_item_name = QString::fromStdString(new_item_name);
        if (q_new_item_name.toStdString().find("spawn") != std::string::npos) {
            QPixmap pix(":/resources/" + q_new_item_name + ".png");
            QPixmap pixmap = pix.scaled(QSize(32, 32));
            item = new QGraphicsPixmapItem(pixmap);
        } else if (q_new_item_name.toStdString().find("box") != std::string::npos) {
            QPixmap pix(":/resources/" + q_new_item_name + ".png");
            QPixmap pixmap = pix.scaled(QSize(FLOOR_SIZE, FLOOR_SIZE));
            item = new QGraphicsPixmapItem(pixmap);
        } else if (q_new_item_name.toStdString().find("bomb") != std::string::npos) {
            QPixmap pix(":/resources/" + q_new_item_name + ".png");
            QPixmap pixmap = pix.scaled(QSize(FLOOR_SIZE, FLOOR_SIZE));
            item = new QGraphicsPixmapItem(pixmap);
        } else {
            item = new QGraphicsPixmapItem(QPixmap(":/resources/" + q_new_item_name + ".png"));
        }
        item->setFlag(QGraphicsItem::ItemIsMovable, true);
        int x = (nodes[i]["position"][0].as<float>())*BASE_X+1;
        int y = (nodes[i]["position"][1].as<float>())*BASE_Y+1;
        item->setPos(x, y);
        item->setData(0, q_new_item_name);
        this->scene->addItem(item);
    }
}

void MainWindow::on_clean_clicked() {
    this->scene->clear();
    this->scene->items().clear();
    for (int x = 0; x <= 1000; x += BASE_X) {
        scene->addLine(x, 0, x, 1000, QPen(Qt::black));
    }
    for (int y = 0; y <= 1000; y += BASE_Y) {
        scene->addLine(0, y, 1000, y, QPen(Qt::black));
    }
    this->scene->update();
}

void MainWindow::connectItems() {
    connect(this->ui->ak47_weapon, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->awp_weapon, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->glock_weapon, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->m3_weapon, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->base_aztec, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->base_dust, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->base_inferno, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->box_black, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->box_brown, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->box_metal, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->box_wood, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->box_wood_metal, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->bomb_area_a, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->bomb_area_b, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->bomb_area_c, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->T_spawn, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->C_spawn, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->ak47_weapon, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->awp_weapon, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->glock_weapon, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->m3_weapon, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->base_aztec, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->base_dust, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->base_inferno, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->box_black, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->box_brown, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->box_metal, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->box_wood, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->box_wood_metal, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->bomb_area_a, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->bomb_area_b, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->bomb_area_c, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->T_spawn, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
    connect(this->ui->C_spawn, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
}

void MainWindow::selectItem() {
    QPushButton* button = (QPushButton*)sender();
    this->dragged = button->objectName();
    button->show();
}

bool MainWindow::isFloor() {
    bool is_base = (this->dragged.toStdString().find("base") != std::string::npos);
    bool is_bomb_zone = (this->dragged.toStdString().find("bomb") != std::string::npos);
    bool is_box = (this->dragged.toStdString().find("box") != std::string::npos);
    return (is_base || is_bomb_zone || is_box);
}

QGraphicsPixmapItem* MainWindow::createSpawn() {
    QPixmap pix(":/resources/" + this->dragged + ".png");
    QPixmap pixmap = pix.scaled(QSize(FLOOR_SIZE/2, FLOOR_SIZE/2));
    return new QGraphicsPixmapItem(pixmap);
}

QGraphicsPixmapItem* MainWindow::createFloor() {
    QPixmap pix(":/resources/" + this->dragged + ".png");
    QPixmap pixmap = pix.scaled(QSize(FLOOR_SIZE, FLOOR_SIZE));
    return new QGraphicsPixmapItem(pixmap);
}

QGraphicsPixmapItem* MainWindow::createPlaceable() {
    QPixmap pix(":/resources/" + this->dragged + ".png");
    return new QGraphicsPixmapItem(pix);
}

QGraphicsPixmapItem* MainWindow::createNewItem() {
    if (this->dragged.toStdString().find("spawn") != std::string::npos) {
        return createSpawn();
    }
    return isFloor() ? createFloor() : createPlaceable();
}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {
    qDebug() << "kakakx";
    QGraphicsRectItem* item1 = new QGraphicsRectItem(0, 0, 65, 65);
    int x_0 = (this->ui->map->mapToScene(event->pos()).x()-3)/(BASE_X);
    int y_0 = (this->ui->map->mapToScene(event->pos()).y()-35)/(BASE_Y);
    int x = x_0*BASE_X;
    int y = y_0*BASE_Y;
    item1->setPos(x, y);
    item1->setData(0, this->dragged);
    item1->setBrush(QBrush(Qt::red));
    item1->setData(0, "color");
    scene->addItem(item1);
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
    QGraphicsRectItem* item1 = new QGraphicsRectItem(0, 0, 65, 65);
    int x_0 = (this->ui->map->mapToScene(event->pos()).x()-3)/(BASE_X);
    int y_0 = (this->ui->map->mapToScene(event->pos()).y()-35)/(BASE_Y);
    int x = x_0*BASE_X;
    int y = y_0*BASE_Y;
    item1->setPos(x, y);
    item1->setData(0, this->dragged);
    item1->setBrush(QBrush(Qt::red));
    item1->setData(0, "color");
    scene->addItem(item1);
}

void MainWindow::on_button_clicked() {
    for (auto item : this->scene->items()) {
        std::string name(item->data(0).toString().toStdString());
        if ((name.find("color") != std::string::npos)) {
            QGraphicsPixmapItem *new_item = this->createNewItem();
            new_item->setData(0, this->dragged);
            new_item->setFlag(QGraphicsItem::ItemIsMovable, true);
            //new_item->setFlag(QGraphicsItem::ItemIsSelectable, true);
            new_item->setPos(item->pos().x()+1, item->pos().y()+1);
            this->scene->addItem(new_item);
            delete item;
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event) {
    QGraphicsPixmapItem *item = this->createNewItem();
    item->setFlag(QGraphicsItem::ItemIsMovable, true);
    //item->setFlag(QGraphicsItem::ItemIsSelectable, true);
    int x_0 = (this->ui->map->mapToScene(event->pos()).x()-3)/(BASE_X);
    int y_0 = (this->ui->map->mapToScene(event->pos()).y()-35)/(BASE_Y);
    int x = x_0*BASE_X+1;
    int y = y_0*BASE_Y+1;
    item->setPos(x, y);
    item->setData(0, this->dragged);
    this->scene->addItem(item);
}

MainWindow::~MainWindow() { delete ui; }
