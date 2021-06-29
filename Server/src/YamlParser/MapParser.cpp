#include "MapParser.h"
#include <syslog.h>
#include <string>
#include <list>
#include <vector>

#define MAPS_PATH "../Editor/configs/"

MapParser::MapParser() {
}

// PRE: El type debe ser alguno del MAPS_PATH. 
// POST: Agrega todas las posiciones del mapa 
//       de tipo type a la lista de posiciones. 
//       Carga en x e y, las dimensiones del mapa.
void MapParser::build_positions(const std::string &type,
	std::vector<Position> &list, int &x, int &y) {
	syslog(LOG_INFO, "[%s:%i]: Por cargar la info del mapa"
					" %s desde el path %s", __FILE__, __LINE__,
					 type.c_str(), (MAPS_PATH + type + ".yaml").c_str());
	
	nodes = YAML::LoadAllFromFile(MAPS_PATH + type + ".yaml");
	x = nodes[0]["width"].as<int>() * CF::size_position;
	y = nodes[0]["height"].as<int>() * CF::size_position;
	syslog(LOG_INFO, "[%s:%i]: Mapa con largo %d y ancho %d"
		, __FILE__, __LINE__, y, x);

	for (auto it = nodes.begin() + 1; it != nodes.end(); ++it) {
		const YAML::Node& obj = *it;
		char type = get_type(obj["item"].as<std::string>());
		int x = obj["position"][0].as<int>() * CF::size_position;
		int y = obj["position"][1].as<int>() * CF::size_position;
		list.push_back(Position(x, y, type));
	}
}

// POST: Retorna los nombres de todos los mapas disponibles. 
std::list<std::string> MapParser::get_maps() {
	std::list<std::string> maps_names;
	DIR* dir;
	struct dirent* entry;
	dir = opendir(MAPS_PATH);
	if (dir == NULL) {
		throw Exception("No se pudo abrir el directorio de mapas.");
	}
	while ((entry = readdir(dir)) != NULL) {
		std::string map_name(entry->d_name);
		size_t pos = map_name.find(".yaml");
		if (pos != std::string::npos) {
			syslog(LOG_INFO, "[%s:%i]: Se leyo el file %s"
						, __FILE__, __LINE__, map_name.c_str());
			maps_names.push_back(map_name.substr(0, pos));
		}
	}
	closedir(dir);
	return maps_names;
}


char MapParser::get_type(const std::string& type) {
	if (type == "base_inferno")
				return PositionType::INFIERNO;
	if (type == "base_dust")
				return PositionType::DUST;
	if (type == "base_aztec")
				return PositionType::AZTEC;
	if (type == "bomb_area_a")
				return PositionType::BOMB_AREA_A;
	if (type == "bomb_area_b")
				return PositionType::BOMB_AREA_B;
	if (type == "bomb_area_c")
				return PositionType::BOMB_AREA_C;
	if (type == "box_area_c")
				return PositionType::BOX_BLACK;
	if (type == "box_black")
				return PositionType::BOX_BROWN;
	if (type == "box_brown")
				return PositionType::BOX_METAL;
	if (type == "box_metal")
				return PositionType::BOX_WOOD_METAL;
	if (type == "box_wood_metal")
				return PositionType::BOX_WOOD;
	if (type == "T_spawn")
				return PositionType::TERRORIST_SPAWN;
	if (type == "C_spawn")
				return PositionType::COUNTER_SPAWN;
	if (type == "glock_weapon")
				return PositionType::GLOCK;
	if (type == "ak47_weapon")
				return PositionType::AK47;
	if (type == "m3_weapon")
				return PositionType::M3;
	if (type == "awp_weapon")
				return PositionType::AWP;
	throw Exception("[%s:%i]: No existe"
	 			"un tipo para esta posicion",
			 		 __FILE__, __LINE__);
}

MapParser::~MapParser() {}
