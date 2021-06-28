#ifndef _MAP_PARSER_H
#define _MAP_PARSER_H

#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <dirent.h>

#include "yaml-cpp/yaml.h"
#include "Position.h"
#include "Configuration.h"

class MapParser {
		std::vector<YAML::Node> nodes;

	public:
		MapParser();
		
		// PRE: El type debe ser alguno del MAPS_PATH. 
		// POST: Agrega todas las posiciones del mapa 
		//       de tipo type a la lista de posiciones. 
		//       Carga en x e y, las dimensiones del mapa. 
		void build_positions(const std::string &type,
			std::vector<Position>& list, int& x, int& y);

		// POST: Retorna los nombres de todos los mapas disponibles. 
		std::list<std::string> get_maps();
		
		~MapParser();
	private:
		char get_type(const std::string& type);
};

#endif
