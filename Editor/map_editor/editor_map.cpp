#include "editor_map.h"
#include <string>
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QObject>
#include "yaml-cpp/yaml.h"

Map::Map() : x_size(0), y_size(0) {}

Map::Map(size_t x, size_t y) : x_size(x), y_size(y) {
    for (size_t i = 0; i < this->x_size; i++) {
        for (size_t j = 0; j < this->y_size; j++) {
            this->map[i][j] = new Cell();
        }
    }
}

void Map::place(size_t x, size_t y, const std::string &name) {
    this->map[x][y]->set(Map::selectType(name), name);
}

CELL_TYPE Map::selectType(const std::string &cell_name) {
    if (cell_name.find("weapon") != std::string::npos) {
        return WEAPON;
    }
    if (cell_name.find("box") != std::string::npos) {
        return OBJECT;
    }
    return BASE;
}

void Map::fill(QList<QGraphicsItem*> items) {
    int k = 0;
    for (size_t i = 0; i < this->x_size; i++) {
        for (size_t j = 0; j < this->y_size; j++) {
            std::string cell_name(items.at(k)->data(0).toString().toStdString());
            this->place(i, j, cell_name);
            k++;
        }
    }
}

std::string Map::writeYaml() {
    YAML::Emitter emitter;
    for (size_t i = 0; i < this->x_size; i++) {
        for (size_t j = 0; j < this->y_size; j++) {
            YAML::Node node;
            node["node"] = i;
            i++;
            YAML::Node coordinates;
            coordinates.push_back(i);
            coordinates.push_back(j);
            node["item"] = this->map[i][j]->getName();
            node["position"] = coordinates;
            emitter << node;
        }
    }
    return emitter.c_str();
}

Map::~Map() {
    for (size_t i = 0; i < this->x_size; i++) {
        for (size_t j = 0; j < this->y_size; j++) {
            delete this->map[i][j];
        }
    }
}
