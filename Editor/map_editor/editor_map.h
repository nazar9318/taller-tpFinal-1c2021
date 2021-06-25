#ifndef EDITOR_MAP_H
#define EDITOR_MAP_H

#include <iostream>
#include <QGraphicsItem>
#include <QList>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QPoint>
#include <QGraphicsPixmapItem>
#include "editor_cell_type.h"
#include "editor_cell.h"

class Map {
    private:
        size_t x_size;
        size_t y_size;
        std::map<size_t, std::map<size_t, Cell*>> map;
        static CELL_TYPE selectType(const std::string &cell_name);

    public:
        Map();
        Map(size_t x, size_t y);
        void fill(QList<QGraphicsItem*> items);
        void place(size_t pos_x, size_t pos_y, const std::string &cell_name);
        std::string writeYaml();
        void readYaml(const std::string &file_name);
        ~Map();
};

#endif // EDITOR_MAP_H
