#ifndef MAP_PARSER_H
#define MAP_PARSER_H

#include <string>
#include <iostream>
#include <vector>
#include <dirent.h>


#include "yaml-cpp/yaml.h"
#include "Position.h"
#include "WeaponType.h"
#include "Configuration.h"

class MapParser {
        std::vector<YAML::Node> nodes;

    public:
        MapParser();
        void build_positions(const std::string &type,
        std::vector<Position> &list, int &x, int &y);
        std::list<std::string> get_maps();
        ~MapParser();
    private:
        char get_type(const std::string& type);


};

#endif
