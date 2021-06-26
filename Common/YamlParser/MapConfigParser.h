#ifndef MAP_PARSER_H
#define MAP_PARSER_H

#include <string>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include "../../Server/src/GameWorld/WorldObjects/GroundMap/Position.h"
#include "WeaponType.h"

class MapParser {
    private:
        std::vector<YAML::Node> nodes;
        int pos_x;
        int pos_y;
        std::string type;
        size_t it;

    public:
        MapParser(const std::string &file_name);

        void getNext();

        const std::string& getName();

        const int getPosX();
        
        const int getPosY();

        const WEAPON_TYPE getWeaponType();

        ~MapParser();
};

#endif
