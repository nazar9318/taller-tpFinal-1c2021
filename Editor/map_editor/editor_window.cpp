#include "editor_window.h"
#include "./ui_editor_window.h"
#include <fstream>
#include <QLayoutItem>
#include <QLabel>
#include <QMouseEvent>
#include <math.h>
#include <cstdlib>
#include <QGraphicsRectItem>

#define BASE_X 33
#define BASE_Y 33
#define FLOOR_SIZE 32

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
ui(new Ui::MainWindow), delay_cnt(0), resized(false) {
    this->ui->setupUi(this);
    scene = new QGraphicsScene(this);
    this->ui->map->setScene(scene);
    for (int x = 0; x <= BASE_X*1000; x += BASE_X) {
        scene->addLine(x, 0, x, BASE_X*1000, QPen(Qt::black));
    }
    for (int y = 0; y <= BASE_Y*1000; y += BASE_Y) {
        scene->addLine(0, y, BASE_Y*1000, y, QPen(Qt::black));
    }
    this->connectItems();
    this->ui->map->setMouseTracking(true);
}

void MainWindow::saveObjects() {
    for (auto item : this->scene->items()) {
        std::string name(item->data(0).toString().toStdString());
        if ((name.find("weapon") != std::string::npos) || (name.find("box") != std::string::npos) ||
            (name.find("bomb") != std::string::npos) || (name.find("spawn") != std::string::npos)) {
            YAML::Node node;
            YAML::Node coordinates;
            coordinates.push_back((int)item->pos().x()/BASE_X);
            coordinates.push_back((int)item->pos().y()/BASE_X);
            node["item"] = item->data(0).toString().toStdString();
            node["position"] = coordinates;
            this->nodes.push_back(node);
        }
    }
}

bool MainWindow::thereIsFloorIn(int &x, int &y) {
    for (size_t i = 0; i < this->floor.size(); i++) {
        bool is_in_x = floor[i].first == x;
        bool is_in_y = floor[i].second == y;
        if (is_in_x && is_in_y) { return true; }
    }
    return false;
}

bool MainWindow::thereIsBoxIn(int &x, int &y) {
    for (size_t i = 0; i < this->box.size(); i++) {
        bool is_in_x = box[i].first == x;
        bool is_in_y = box[i].second == y;
        if (is_in_x && is_in_y) { return true; }
    }
    return false;
}

bool MainWindow::thereIsBombPlaceIn(int &x, int &y) {
    for (size_t i = 0; i < this->bomb.size(); i++) {
        bool is_in_x = bomb[i].first == x;
        bool is_in_y = bomb[i].second == y;
        if (is_in_x && is_in_y) { return true; }
    }
    return false;
}

bool MainWindow::thereIsWeaponIn(int &x, int &y) {
    for (size_t i = 0; i < this->weapon.size(); i++) {
        bool is_in_x = weapon[i].first == x;
        bool is_in_y = weapon[i].second == y;
        if (is_in_x && is_in_y) { return true; }
    }
    return false;
}

bool MainWindow::thereIsSpawnIn(int &x, int &y) {
    for (size_t i = 0; i < this->spawn.size(); i++) {
        bool is_in_x = spawn[i].first == x;
        bool is_in_y = spawn[i].second == y;
        if (is_in_x && is_in_y) { return true; }
    }
    return false;
}

void MainWindow::placePos(int &x, int &y) {
    if (this->dragged.toStdString().find("base") != std::string::npos) {
        this->floor.push_back(std::make_pair(x,y));
    }
    else if (this->dragged.toStdString().find("bomb") != std::string::npos) {
        this->bomb.push_back(std::make_pair(x,y));
    }
    else if (this->dragged.toStdString().find("weapon") != std::string::npos) {
        this->weapon.push_back(std::make_pair(x,y));
    }
    else if (this->dragged.toStdString().find("box") != std::string::npos) {
        this->box.push_back(std::make_pair(x,y));
    }
    else if (this->dragged.toStdString().find("spawn") != std::string::npos) {
        this->spawn.push_back(std::make_pair(x,y));
    }
}

void MainWindow::saveBases() {
    for (auto item : this->scene->items()) {
        std::string name(item->data(0).toString().toStdString());
        if ((name.find("base") != std::string::npos)) {
            int x = (int)item->pos().x()/BASE_X;
            int y = (int)item->pos().y()/BASE_Y;
            YAML::Node node;
            YAML::Node coordinates;
            coordinates.push_back(x);
            coordinates.push_back(y);
            node["item"] = item->data(0).toString().toStdString();
            node["position"] = coordinates;
            this->nodes.push_back(node);
        }
    }
}

size_t MainWindow::heigth() {
    this->min_y = this->scene->items().first()->pos().y()/BASE_Y;
    this->max_y = this->scene->items().first()->pos().y()/BASE_Y;
    std::vector<size_t> count_heigth;
    for (auto item : this->scene->items()) {
        std::string name(item->data(0).toString().toStdString());
        if (name.size() > 0) {
            if (item->pos().y()/BASE_X < this->min_y) {
                this->min_y = item->pos().y()/BASE_Y;
            }
            if (item->pos().y()/BASE_X > this->max_y) {
                this->max_y = item->pos().y()/BASE_Y;
            }
        }
    }
    return (this->max_y - this->min_y + 1);
}

size_t MainWindow::width() {
    this->min_x = this->scene->items().first()->pos().x()/BASE_X;
    this->max_x = this->scene->items().first()->pos().x()/BASE_X;
    std::vector<size_t> count_width;
    for (auto item : this->scene->items()) {
        std::string name(item->data(0).toString().toStdString());
        if (name.size() > 0) {
            if (item->pos().x()/BASE_X < this->min_x) {
                this->min_x = item->pos().x()/BASE_X;
            }
            if (item->pos().x()/BASE_X > this->max_x) {
                this->max_x = item->pos().x()/BASE_X;
            }
        }
    }
    return (this->max_x - this->min_x + 1);
}

void MainWindow::moveMap(YAML::Emitter &emitter) {
    if (!this->resized) {
        if (this->min_x == 0) {
            for (size_t i = 1; i < nodes.size(); i++) {
                int x = nodes[i]["position"][0].as<int>();
                x++;
                nodes[i]["position"][0] = x;
            }
            this->min_x++;
            this->max_x++;
        } else {
            for (size_t i = 1; i < nodes.size(); i++) {
                int x = nodes[i]["position"][0].as<int>();
                nodes[i]["position"][0] = x-this->min_x+1;
            }
            this->max_x -= this->min_x-1;
            this->min_x = 1;
        }
        if (this->min_y == 0) {
            for (size_t i = 1; i < nodes.size(); i++) {
                int y = nodes[i]["position"][1].as<int>();
                y++;
                nodes[i]["position"][1] = y;
            }
            this->min_y++;
            this->max_y++;
        } else {
            for (size_t i = 1; i < nodes.size(); i++) {
                int y = nodes[i]["position"][1].as<int>();
                nodes[i]["position"][1] = y-this->min_y+1;
            }
            this->max_y -= this->min_y-1;
            this->min_y = 1;
        }
    }
    for (size_t i = 1; i < nodes.size(); i++) { emitter << nodes[i]; }
}

void MainWindow::makeSquared(YAML::Emitter &emitter) {
    std::map<std::pair<int,int>, int> positions;
    for (size_t i = min_x-1; i <= max_x + 1; i++) {
        for (size_t j = min_y-1; j <= max_y + 1; j++) {
            positions[std::make_pair(i,j)] = -1;
        }
    }
    for (size_t i = 1; i < nodes.size(); i++) {
        int x = nodes[i]["position"][0].as<int>();
        int y = nodes[i]["position"][1].as<int>();
        positions[std::make_pair(x, y)] = 0;
    }
    size_t inf_x = min_x - (this->resized ? 0:1);
    size_t sup_x = max_x + (this->resized ? 0:1);
    size_t inf_y = min_y - (this->resized ? 0:1);
    size_t sup_y = max_y + (this->resized ? 0:1);
    for (size_t i = inf_x; i <= sup_x; i++) {
        for (size_t j = inf_y; j <= sup_y; j++) {
            if (positions.at(std::make_pair(i,j)) == -1) {
                YAML::Node node;
                YAML::Node coordinates;
                coordinates.push_back(i);
                coordinates.push_back(j);
                node["item"] = "box_black";
                node["position"] = coordinates;
                emitter << node;
                this->nodes.push_back(node);
            }
        }
    }
}

void MainWindow::on_save_clicked() {
    YAML::Emitter emitter;
    YAML::Node size;
    YAML::Node resized;
    size["width"] = this->width() + (this->resized ? 0 : 2);
    size["height"] = this->heigth() + (this->resized ? 0 : 2);
    nodes.push_back(size);
    emitter << size;
    this->saveBases();
    this->saveObjects();
    this->moveMap(emitter);
    this->makeSquared(emitter);
    this->resized = true;
    resized["Resized"] = 1;
    emitter << resized;
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Address Book"), "../configs/",
            tr("Address Book (*.yml);;All Files (*)"));
    std::ofstream out(fileName.toStdString());
    out << emitter.c_str();
    nodes.clear();
}

void MainWindow::on_load_clicked() {
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "../configs/");
    std::vector<YAML::Node> nodes = YAML::LoadAllFromFile(file_name.toStdString());
    for (size_t i = 1; i < nodes.size()-1; i++) {
        QGraphicsPixmapItem *item;
        const std::string &new_item_name = nodes[i]["item"].as<std::string>();
        QString q_new_item_name = QString::fromStdString(new_item_name);
        if (q_new_item_name.toStdString().find("spawn") != std::string::npos) {
            QPixmap pix(":/resources/" + q_new_item_name + ".png");
            QPixmap pixmap = pix.scaled(QSize(FLOOR_SIZE/2, FLOOR_SIZE/2));
            item = new QGraphicsPixmapItem(pixmap);
        } else if (q_new_item_name.toStdString().find("box") != std::string::npos) {
            QPixmap pix(":/resources/" + q_new_item_name + ".png");
            QPixmap pixmap = pix.scaled(QSize(FLOOR_SIZE, FLOOR_SIZE));
            item = new QGraphicsPixmapItem(pixmap);
        } else if (q_new_item_name.toStdString().find("bomb") != std::string::npos) {
            QPixmap pix(":/resources/" + q_new_item_name + ".png");
            QPixmap pixmap = pix.scaled(QSize(FLOOR_SIZE, FLOOR_SIZE));
            item = new QGraphicsPixmapItem(pixmap);
        } else if (q_new_item_name.toStdString().find("weapon") != std::string::npos) {
            QPixmap pix(":/resources/" + q_new_item_name + ".png");
            QPixmap pixmap = pix.scaled(QSize(FLOOR_SIZE, FLOOR_SIZE/2));
            item = new QGraphicsPixmapItem(pixmap);
        } else {
            QPixmap pix(":/resources/" + q_new_item_name + ".png");
            QPixmap pixmap = pix.scaled(QSize(FLOOR_SIZE, FLOOR_SIZE));
            item = new QGraphicsPixmapItem(pixmap);
        }
        item->setFlag(QGraphicsItem::ItemIsSelectable, true);
        int x_0 = nodes[i]["position"][0].as<int>();
        int y_0 = nodes[i]["position"][1].as<int>();
        int x = (x_0)*BASE_X+1;
        int y = (y_0)*BASE_Y+1;
        item->setPos(x, y);
        item->setData(0, q_new_item_name);
        this->scene->addItem(item);
    }
    this->resized = (nodes[nodes.size()-1]["Resized"].as<int>() == 1);
}

void MainWindow::removeFrom(const std::string& item, int x, int y) {
    if (item.find("base") != std::string::npos) {
        this->floor.erase(std::remove(this->floor.begin(), this->floor.end(), std::make_pair(x,y)), this->floor.end());
    }
    if (item.find("box") != std::string::npos) {
        this->box.erase(std::remove(this->box.begin(), this->box.end(), std::make_pair(x,y)), this->box.end());
    }
    if (item.find("bomb") != std::string::npos) {
        this->bomb.erase(std::remove(this->bomb.begin(), this->bomb.end(), std::make_pair(x,y)), this->bomb.end());
    }
    if (item.find("spawn") != std::string::npos) {
        this->spawn.erase(std::remove(this->spawn.begin(), this->spawn.end(), std::make_pair(x,y)), this->spawn.end());
    }
    if (item.find("weapon") != std::string::npos) {
        this->weapon.erase(std::remove(this->weapon.begin(), this->weapon.end(), std::make_pair(x,y)), this->weapon.end());
    }
}

void MainWindow::on_clean_selected_clicked() {
    for (auto item : this->scene->items()) {
        if (item->isSelected()) {
            int x = item->pos().x();
            int y = item->pos().y();
            removeFrom(item->data(0).toString().toStdString(), x, y);
            this->scene->removeItem(item);
            delete item;
        }
    }
}

void MainWindow::on_clean_all_clicked() {
    for (auto item : this->scene->items()) { delete item; }
    this->scene->clear();
    this->scene->items().clear();
    this->floor.clear();
    this->bomb.clear();
    this->box.clear();
    this->spawn.clear();
    this->weapon.clear();
    for (int x = 0; x <= BASE_X*1000; x += BASE_X) {
        scene->addLine(x, 0, x, BASE_X*1000, QPen(Qt::black));
    }
    for (int y = 0; y <= BASE_Y*1000; y += BASE_Y) {
        scene->addLine(0, y, BASE_Y*1000, y, QPen(Qt::black));
    }
    this->scene->update();
    this->resized = false;
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
    QPixmap pixmap = pix.scaled(QSize(FLOOR_SIZE, FLOOR_SIZE/2));
    return new QGraphicsPixmapItem(pixmap);
}

QGraphicsPixmapItem* MainWindow::createNewItem() {
    if (this->dragged.toStdString().find("spawn") != std::string::npos) {
        return createSpawn();
    }
    return isFloor() ? createFloor() : createPlaceable();
}

void MainWindow::addSquare(QMouseEvent* event) {
    int x_0 = (this->ui->map->mapToScene(event->pos()).x()-3)/(BASE_X);
    int y_0 = (this->ui->map->mapToScene(event->pos()).y()-35)/(BASE_Y);
    int x = x_0*BASE_X;
    int y = y_0*BASE_Y;
    QGraphicsRectItem* item1 = new QGraphicsRectItem(0, 0, BASE_X, BASE_Y);
    item1->setPos(x, y);
    item1->setBrush(QBrush(Qt::red));
    item1->setData(0, "color");
    scene->addItem(item1);
}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {
    if (this->dragged.toStdString().compare("color") == 0) {
        delay_cnt++;
        if (delay_cnt < BASE_X) { return; }
        delay_cnt = 0;
        int x_0 = (this->ui->map->mapToScene(event->pos()).x()-3)/(BASE_X);
        int y_0 = (this->ui->map->mapToScene(event->pos()).y()-35)/(BASE_Y);
        int x = x_0*BASE_X+1;
        int y = y_0*BASE_Y+1;
        if (!this->thereIsFloorIn(x, y)) { this->addSquare(event); }
    }
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
    this->dragged = "color";
    this->addSquare(event);
}

void MainWindow::on_button_clicked() {
    for (auto item : this->scene->items()) {
        std::string name(item->data(0).toString().toStdString());
        if ((name.find("color") != std::string::npos)) {
            QGraphicsPixmapItem *new_item = this->createNewItem();
            QPushButton* button = (QPushButton*)sender();
            new_item->setData(0, button->objectName());
            new_item->setFlag(QGraphicsItem::ItemIsSelectable, true);
            int x = item->pos().x()+1;
            int y = item->pos().y()+1;
            if (!this->thereIsFloorIn(x, y)) {
                new_item->setPos(x, y);
                this->placePos(x,y);
                this->scene->addItem(new_item);
            } else {
                delete new_item;
            }
            this->scene->removeItem(item);
            delete item;
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event) {
    int x_0 = (this->ui->map->mapToScene(event->pos()).x()-3)/(BASE_X);
    int y_0 = (this->ui->map->mapToScene(event->pos()).y()-35)/(BASE_Y);
    int x = x_0*BASE_X+1;
    int y = y_0*BASE_Y+1;
    std::string dragged = this->dragged.toStdString();
    bool putting_box_in_floor = thereIsFloorIn(x, y) && (dragged.find("box") != std::string::npos);
    bool putting_floor_in_floor = thereIsFloorIn(x, y) && (dragged.find("base") != std::string::npos);
    bool putting_bomb_in_floor = thereIsFloorIn(x, y) && (dragged.find("bomb") != std::string::npos);
    bool valid = !putting_box_in_floor && !putting_floor_in_floor && !putting_bomb_in_floor;
    if (valid && this->dragged.compare("color") != 0) {
        QGraphicsPixmapItem *item = this->createNewItem();
        item->setFlag(QGraphicsItem::ItemIsSelectable, true);
        if (!thereIsWeaponIn(x, y) && !thereIsBombPlaceIn(x, y) && !thereIsBoxIn(x, y) && !thereIsSpawnIn(x, y)) {
            item->setPos(x, y);
            this->placePos(x,y);
            item->setData(0, this->dragged);
            this->scene->addItem(item);
        } else { delete item; }
    }
}

MainWindow::~MainWindow() {
    for (auto item : this->scene->items()) { delete item; }
    delete this->scene;
    delete ui;
}
