#ifndef EDITOR_CELL_H
#define EDITOR_CELL_H

#include "editor_cell_type.h"
#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QDebug>

class Cell : public QWidget {
    private:
        bool empty;
        size_t x_size;
        size_t y_size;
        CELL_TYPE type;
        std::string name;
        static CELL_TYPE selectType(const std::string &cell_name);
        static void changeColor();

    public:
        Cell();
        Cell(const std::string &cell_name);
        void set(CELL_TYPE type, const std::string &cell_name);
        bool isEmpty() const;
        CELL_TYPE getType() const;
        std::string getName() const;
        ~Cell();
};

#endif // EDITOR_CELL_H
