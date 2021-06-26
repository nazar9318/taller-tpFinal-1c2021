#include "MapConfigParser.h"

MapParser::MapParser(const std::string &file_name) :
nodes(YAML::LoadAllFromFile(file_name)), it(1) {
    this->type = nodes[1]["item"].as<std::string>();
    this->pos_x = nodes[1]["position"][0].as<int>();
    this->pos_y = nodes[1]["position"][1].as<int>();
}

void MapParser::getNext() {
    if (this->it < this->nodes.size()) {
        it++;
        this->type = nodes[it]["item"].as<std::string>();
        this->pos_x = nodes[it]["position"][0].as<int>();
        this->pos_y = nodes[it]["position"][1].as<int>();
    }
}

const std::string& MapParser::getName() {
    return this->type;
}

const int MapParser::getPosX() {
    return this->pos_x;
}

const int MapParser::getPosY() {
    return this->pos_y;
}

const WEAPON_TYPE MapParser::getWeaponType() {
    if (this->type.find("m3") != std::string::npos) {
        return SHOTGUN;
    }
    if (this->type.find("awp") != std::string::npos) {
        return SNIPER;
    }
    if (this->type.find("glock") != std::string::npos) {
        return PISTOL;
    }
    if (this->type.find("ak") != std::string::npos) {
        return AUTOMATIC;
    }
    return NONE;
}

MapParser::~MapParser() {}
