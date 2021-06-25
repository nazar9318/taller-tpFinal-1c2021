#include "editor_cell.h"

Cell::Cell() : empty(true), x_size(0), y_size(0), type(NONE) {}

Cell::Cell(const std::string &cell_name) : empty(false),
type(Cell::selectType(cell_name)), name(cell_name) {
    switch (this->type) {
        case BASE:
            this->x_size = BASE_X;
            this->y_size = BASE_Y;
            break;
        case WEAPON:
            this->x_size = WEAPON_X;
            this->y_size = WEAPON_Y;
            break;
        case OBJECT:
            this->x_size = OBJECT_X;
            this->y_size = OBJECT_Y;
            break;
        default:
            break;
    }
}

CELL_TYPE Cell::selectType(const std::string &cell_name) {
    if (cell_name.find("weapon") != std::string::npos) {
        return WEAPON;
    }
    if (cell_name.find("box") != std::string::npos) {
        return OBJECT;
    }
    return BASE;
}

void Cell::set(CELL_TYPE type, const std::string &cell_name) {
    this->type = type;
    this->name = cell_name;
    switch (this->type) {
        case BASE:
            this->x_size = BASE_X;
            this->y_size = BASE_Y;
            break;
        case WEAPON:
            this->x_size = WEAPON_X;
            this->y_size = WEAPON_Y;
            break;
        case OBJECT:
            this->x_size = OBJECT_X;
            this->y_size = OBJECT_Y;
            break;
        default:
            break;
    }
    this->empty = false;
}

CELL_TYPE Cell::getType() const { return this->type; }

std::string Cell::getName() const { return this->name; }

bool Cell::isEmpty() const {return empty;}

Cell::~Cell() {}
