/*#include "MapConfigParser.h"

MapParser::MapParser(const std::string &type,
    std::vector<Position> &list, int &x, int &y) :
nodes(YAML::LoadAllFromFile(type)), it(1) {
    x = this->nodes[0]["width"].as<int>();
    y = this->nodes[1]["height"].as<int>();
    this->type = nodes[1]["item"].as<std::string>();
    this->pos_x = nodes[1]["position"][0].as<int>();
    this->pos_y = nodes[1]["position"][1].as<int>();
	while (!this->endFile()) {
		list.push_back(Position(this->getPosX(), this->getPosY(),
            this->isTerroristSpawnZone(), this->isCounterSpawnZone(),
            this->isBombZone(), this->isBlockZone(), this->getWeaponType()));
		this->getNext();
	}
}

void MapParser::getNext() {
    if (this->it < this->nodes.size()) {
        it++;
        this->type = nodes[it]["item"].as<std::string>();
        this->pos_x = nodes[it]["position"][0].as<int>();
        this->pos_y = nodes[it]["position"][1].as<int>();
    }
}

bool MapParser::isTerroristSpawnZone() {
    return (this->type.compare("terrorist") == 0);
}

bool MapParser::isCounterSpawnZone() {
    return (this->type.compare("counter") == 0);
}

bool MapParser::isBlockZone() {
    return (this->type.compare("block") == 0);
}

bool MapParser::isBombZone() {
    return (this->type.compare("bomb") == 0);
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

bool MapParser::endFile() {
    return this->it == this->nodes.size();
}

MapParser::~MapParser() {}
*/