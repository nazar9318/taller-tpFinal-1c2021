#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "yaml-cpp/yaml.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent), ui(new Ui::MainWindow) {
    this->ui->setupUi(this);
    scene = new QGraphicsScene(this);
    this->ui->map->setScene(scene);
    this->loadImages();
    this->connectItems();
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
        if (item->data(0).toString().toStdString().compare("Oficial") == 0) {
            node["life points"] = 5;
            node["bullets"] = 15;
        }
        emitter << node;
    }

    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Address Book"), "",
        tr("Address Book (*.yml);;All Files (*)"));
    std::ofstream out(fileName.toStdString());
    out << emitter.c_str();
}

void MainWindow::on_load_clicked() {
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "../configs/");
    QMessageBox::information(this, "..", file_name);
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
    connect(this->ui->ak47, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->awp, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->glock, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->m3, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->cofre, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->cruz, SIGNAL(pressed()), this, SLOT(selectItem()));
    /*connect(this->ui->Guardia, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->Llave, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->KitMedico, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->ManchaAgua, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->ManchaSangre, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->Mesa, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->Oficial, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->Pared, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->PuertaConLlave, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->PuertaSinLlave, SIGNAL(pressed()), this, SLOT(selectItem()));
    connect(this->ui->SS, SIGNAL(pressed()), this, SLOT(selectItem()));*/
}

void MainWindow::loadImages() {
/*    this->ui->ametralladora->setIcon(QPixmap(":/Ametralladora.png"));
    this->ui->barril->setIcon(QPixmap(":/Barril.png"));
    this->ui->balas->setIcon(QPixmap(":/Balas.png"));
    this->ui->canion->setIcon(QPixmap(":/CanionCadena.png"));
    this->ui->cofre->setIcon(QPixmap(":/Cofre.png"));
    this->ui->corona->setIcon(QPixmap(":/Corona.png"));
    this->ui->cruz->setIcon(QPixmap(":/Cruz.png"));
    this->ui->Guardia->setIcon(QPixmap(":/Guardia.png"));
    this->ui->Llave->setIcon(QPixmap(":/Llave.png"));
    this->ui->ManchaAgua->setIcon(QPixmap(":/ManchaAgua.png"));
    this->ui->ManchaSangre->setIcon(QPixmap(":/ManchaSangre.png"));
    this->ui->Mesa->setIcon(QPixmap(":/Mesa.png"));
    this->ui->KitMedico->setIcon(QPixmap(":/KitMedico.png"));
    this->ui->Pared->setIcon(QPixmap(":/Pared.png"));
    this->ui->PuertaSinLlave->setIcon(QPixmap(":/PuertaSinLlave.png"));
    this->ui->PuertaConLlave->setIcon(QPixmap(":/PuertaConLlave.png"));
    this->ui->SS->setIcon(QPixmap(":/SS.png"));*/
}

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
