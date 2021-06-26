/*#ifndef MAP_PARSER_H
#define MAP_PARSER_H

#include <string>
#include <iostream>
#include <vector>
#include "yaml-cpp/yaml.h"
#include "Position.h"
#include "WeaponType.h"

class MapParser {
    private:
        std::vector<YAML::Node> nodes;
        int pos_x;
        int pos_y;
        std::string type;
        size_t it;
        void getNext();
        const std::string& getName();
        const int getPosX();        
        const int getPosY();
        const WEAPON_TYPE getWeaponType();
        bool endFile();
        bool isCounterSpawnZone();
        bool isTerroristSpawnZone();
        bool isBlockZone();
        bool isBombZone();

    public:
        MapParser(const std::string &type,
        std::vector<Position> &list, int &x, int &y);

        ~MapParser();
};

#endif
*/