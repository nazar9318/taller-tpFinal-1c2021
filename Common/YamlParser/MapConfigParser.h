#ifndef MAP_PARSER_H
#define MAP_PARSER_H

#include <string>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include "Position.h"
#include "WeaponType.h"

class MapParser {
    private:
        std::vector<YAML::Node> nodes;
        int pos_x;
        int pos_y;
        std::string type;
        int it;

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
