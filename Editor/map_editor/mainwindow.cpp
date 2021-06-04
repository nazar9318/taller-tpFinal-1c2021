#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent), ui(new Ui::MainWindow) {
    this->ui->setupUi(this);
    scene = new QGraphicsScene(this);
    this->ui->map->setScene(scene);
    this->loadImages();
    this->connectItems();
}

void MainWindow::save_extra_attributes(QGraphicsItem* item, YAML::Node node) {
    if (item->data(0).toString().toStdString().compare("ak47_m") == 0) {
        node["rate"] = 3;
        node["automatic"] = true;
        node["frequency"] = 0.4;
        node["damage"] = 10;
        node["accuracy"] = 100;
        node["distance_penalty"] = 5;
        node["price"] = 10;
    } else if (item->data(0).toString().toStdString().compare("glock_m") == 0) {
        node["rate"] = 1;
        node["automatic"] = false;
        node["frequency"] = 0;
        node["damage"] = 15;
        node["accuracy"] = 50;
        node["distance_penalty"] = 5;
        node["price"] = 50;
    } else if (item->data(0).toString().toStdString().compare("m3_m") == 0) {
        node["rate"] = 1;
        node["automatic"] = false;
        node["frequency"] = 0;
        node["damage"] = 25;
        node["accuracy"] = 30;
        node["distance_penalty"] = 20;
        node["price"] = 100;
    } else if (item->data(0).toString().toStdString().compare("awp_m") == 0) {
        node["rate"] = 1;
        node["automatic"] = false;
        node["frequency"] = 0;
        node["damage"] = 50;
        node["accuracy"] = 100;
        node["distance_penalty"] = 0;
        node["price"] = 500;
    }
}

void MainWindow::on_save_clicked() {
    YAML::Emitter emitter;
    int i = 0;
    for (auto item : this->scene->items()) {
        YAML::Node node;
        node["node"] = i;
        i++;
        YAML::Node coordinates;
        coordinates.push_back(item->pos().x());
        coordinates.push_back(item->pos().y());
        node["item"] = item->data(0).toString().toStdString();
        node["position"] = coordinates;
        save_extra_attributes(item, node);
        emitter << node;
    }
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Address Book"), "../configs/",
        tr("Address Book (*.yml);;All Files (*)"));
    std::ofstream out(fileName.toStdString());
    out << emitter.c_str();
}

void MainWindow::on_load_clicked() {
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "../configs/");
    std::vector<YAML::Node> nodes = YAML::LoadAllFromFile(file_name.toStdString());
    for (size_t i = 0; i < nodes.size(); i++) {
        QGraphicsPixmapItem *item;
        const std::string &new_item_name = nodes[i]["item"].as<std::string>();
        QString q_new_item_name = QString::fromStdString(new_item_name);
        item = new QGraphicsPixmapItem(QPixmap(":/resources/" + q_new_item_name + ".png"));
        item->setFlag(QGraphicsItem::ItemIsMovable, true);
        item->setPos(nodes[i]["position"][0].as<float>(), nodes[i]["position"][1].as<float>());
        item->setData(0, q_new_item_name);
        this->scene->addItem(item);
    }
}

void MainWindow::on_clean_clicked() {
    this->scene->clear();
    this->scene->items().clear();
    this->scene->update();
}

void MainWindow::connectItems() {
    connect(this->ui->ak47_m, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->awp_m, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->glock_m, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->m3_m, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->default_aztec, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->aztec, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->default_dust, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->dust, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->default_inferno, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->box_black, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->box_brown, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->box_metal, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->box_wood, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->box_wood_metal, SIGNAL(pressed()), this, SLOT(selectItem()));
}

void MainWindow::loadImages() {}

void MainWindow::selectItem() {
    QPushButton* button = (QPushButton*) sender();
    this->dragged = button->objectName();
    button->show();
}

void MainWindow::mouseReleaseEvent(QMouseEvent*) {
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem
        (QPixmap(":/resources/" + this->dragged + ".png"));
    item->setFlag(QGraphicsItem::ItemIsMovable, true);
    item->setPos(cursor().pos().x(), cursor().pos().y());
    item->setData(0, this->dragged);
    this->scene->addItem(item);
}

MainWindow::~MainWindow() { delete ui; }
