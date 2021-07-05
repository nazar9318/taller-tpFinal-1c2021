#include "Configuration.h"
#include <syslog.h>


YAML::Node CF::yaml_file = YAML::LoadFile("../Server/src/Configuration/Configuration.yaml");

YAML::Node CF::common_yaml_file = YAML::LoadFile("../Common/Configuration/CommonConfiguration.yaml");

/*****************************************************************/
/**************************COMMON*********************************/

std::string CF::port = common_yaml_file["port"].as<std::string>();
int CF::max_iterations_pop_events =
				CF::common_yaml_file["max_iterations_pop_events"].as<int>();
int CF::size_position = CF::common_yaml_file["size_position"].as<int>();
int CF::character_radius = CF::common_yaml_file["character_radius"].as<int>();

/*****************************************************************/

int CF::TIME_BOMB_EXPLOTE = CF::yaml_file["TIME_BOMB_EXPLOTE"].as<int>();
int CF::TIME_BOMB_ACTIVATE = CF::yaml_file["TIME_BOMB_ACTIVATE"].as<int>();
int CF::TIME_BOMB_DEACTIVATE = CF::yaml_file["TIME_BOMB_DEACTIVATE"].as<int>();



int CF::velocity_iterations = CF::yaml_file["velocity_iterations"].as<int>();
int CF::position_iterations = CF::yaml_file["position_iterations"].as<int>();

int CF::max_distance_grab = CF::yaml_file["max_distance_grab"].as<int>();
int CF::bonus_kill = CF::yaml_file["bonus_kill"].as<int>();
double CF::time_preparation = CF::yaml_file["time_preparation"].as<double>();
double CF::time_finish = CF::yaml_file["time_finish"].as<double>();
int CF::number_rounds = CF::yaml_file["number_rounds"].as<int>();
int CF::players_allowed = CF::yaml_file["players_allowed"].as<int>();

int CF::character_life_points = CF::yaml_file["character_life_points"].as<int>();
int CF::character_money = CF::yaml_file["character_money"].as<int>();
int CF::bomb_clock_count = CF::yaml_file["bomb_clock_count"].as<int>();
int CF::glock_bullets = CF::yaml_file["glock_bullets"].as<int>();
int CF::ak47_bullets = CF::yaml_file["ak47_bullets"].as<int>();
int CF::m3_bullets = CF::yaml_file["m3_bullets"].as<int>();
int CF::awp_bullets = CF::yaml_file["awp_bullets"].as<int>();
int CF::glock_range = CF::yaml_file["glock_range"].as<int>();
int CF::ak47_range = CF::yaml_file["ak47_range"].as<int>();
int CF::m3_range = CF::yaml_file["m3_range"].as<int>();
int CF::awp_range = CF::yaml_file["awp_range"].as<int>();
double CF::glock_accuracy = CF::yaml_file["glock_accuracy"].as<double>();
double CF::ak47_accuracy = CF::yaml_file["ak47_accuracy"].as<double>();
double CF::m3_accuracy = CF::yaml_file["m3_accuracy"].as<double>();
double CF::awp_accuracy = CF::yaml_file["awp_accuracy"].as<double>();
double CF::knife_damage_min = CF::yaml_file["knife_damage_min"].as<double>();
double CF::glock_damage_min = CF::yaml_file["glock_damage_min"].as<double>();
double CF::ak47_damage_min = CF::yaml_file["ak47_damage_min"].as<double>();
double CF::m3_damage_min = CF::yaml_file["m3_damage_min"].as<double>();
double CF::awp_damage_min = CF::yaml_file["awp_damage_min"].as<double>();
double CF::knife_damage_max = CF::yaml_file["knife_damage_max"].as<double>();
double CF::glock_damage_max = CF::yaml_file["glock_damage_max"].as<double>();
double CF::ak47_damage_max = CF::yaml_file["ak47_damage_max"].as<double>();
double CF::m3_damage_max = CF::yaml_file["m3_damage_max"].as<double>();
double CF::awp_damage_max = CF::yaml_file["awp_damage_max"].as<double>();
int CF::glock_shoot_rate = CF::yaml_file["glock_shoot_rate"].as<int>();
int CF::ak47_shoot_rate = CF::yaml_file["ak47_shoot_rate"].as<int>();
int CF::m3_shoot_rate = CF::yaml_file["m3_shoot_rate"].as<int>();
int CF::awp_shoot_rate = CF::yaml_file["awp_shoot_rate"].as<int>();
int CF::glock_shoot_freq = CF::yaml_file["glock_shoot_freq"].as<int>();
int CF::ak47_shoot_freq = CF::yaml_file["ak47_shoot_freq"].as<int>();
int CF::m3_shoot_freq = CF::yaml_file["m3_shoot_freq"].as<int>();
int CF::awp_shoot_freq = CF::yaml_file["awp_shoot_freq"].as<int>();
double CF::glock_distance_penalty = CF::yaml_file["glock_distance_penalty"].as<double>();
double CF::ak47_distance_penalty = CF::yaml_file["ak47_distance_penalty"].as<double>();
double CF::m3_distance_penalty = CF::yaml_file["m3_distance_penalty"].as<double>();
double CF::awp_distance_penalty = CF::yaml_file["awp_distance_penalty"].as<double>();
double CF::knife_distance_penalty = CF::yaml_file["knife_distance_penalty"].as<double>();

int CF::glock_price = CF::yaml_file["glock_price"].as<int>();
int CF::ak47_price = CF::yaml_file["ak47_price"].as<int>();
int CF::m3_price = CF::yaml_file["m3_price"].as<int>();
int CF::awp_price = CF::yaml_file["awp_price"].as<int>();
int CF::glock_ammo = CF::yaml_file["glock_ammo"].as<int>();
int CF::ak47_ammo = CF::yaml_file["ak47_ammo"].as<int>();
int CF::m3_ammo = CF::yaml_file["m3_ammo"].as<int>();
int CF::awp_ammo = CF::yaml_file["awp_ammo"].as<int>();

double CF::glock_max_distance = CF::yaml_file["glock_max_distance"].as<double>();
double CF::ak47_max_distance = CF::yaml_file["ak47_max_distance"].as<double>();
double CF::m3_max_distance = CF::yaml_file["m3_max_distance"].as<double>();
double CF::awp_max_distance = CF::yaml_file["awp_max_distance"].as<double>();
double CF::knife_max_distance = CF::yaml_file["knife_max_distance"].as<double>();


Configuration::Configuration() {}
Configuration::~Configuration() {}

void Configuration::load_configuration(const std::string& file_path) {
	yaml_file =	YAML::LoadFile("../../../" + file_path);

	syslog(LOG_INFO, "[%s:%i]: Se cargo el port: %s"
			, __FILE__, __LINE__, port.c_str());
	time_preparation = yaml_file["time_preparation"].as<double>();
	time_finish = yaml_file["time_finish"].as<double>();
	number_rounds = yaml_file["number_rounds"].as<int>();
	players_allowed = yaml_file["players_allowed"].as<int>();

	max_distance_grab = yaml_file["max_distance_grab"].as<int>();


	TIME_BOMB_EXPLOTE = yaml_file["TIME_BOMB_EXPLOTE"].as<int>();
	TIME_BOMB_ACTIVATE = yaml_file["TIME_BOMB_ACTIVATE"].as<int>();
	TIME_BOMB_DEACTIVATE = yaml_file["TIME_BOMB_DEACTIVATE"].as<int>();


	velocity_iterations = yaml_file["velocity_iterations"].as<int>();
	position_iterations = yaml_file["position_iterations"].as<int>();

	bonus_kill = yaml_file["bonus_kill"].as<int>();
	
	character_life_points = yaml_file["character_life_points"].as<int>();
	character_money = yaml_file["character_money"].as<int>();
	bomb_clock_count = yaml_file["bomb_clock_count"].as<int>();
	glock_bullets = yaml_file["glock_bullets"].as<int>();
	ak47_bullets = yaml_file["ak47_bullets"].as<int>();
	m3_bullets = yaml_file["m3_bullets"].as<int>();
	awp_bullets = yaml_file["awp_bullets"].as<int>();
	glock_range = yaml_file["glock_range"].as<int>();
	ak47_range = yaml_file["ak47_range"].as<int>();
	m3_range = yaml_file["m3_range"].as<int>();
	awp_range = yaml_file["awp_range"].as<int>();
	glock_accuracy = yaml_file["glock_accuracy"].as<double>();
	ak47_accuracy = yaml_file["ak47_accuracy"].as<double>();
	m3_accuracy = yaml_file["m3_accuracy"].as<double>();
	awp_accuracy = yaml_file["awp_accuracy"].as<double>();
	knife_damage_min = yaml_file["knife_damage_min"].as<double>();
	glock_damage_min = yaml_file["glock_damage_min"].as<double>();
	ak47_damage_min = yaml_file["ak47_damage_min"].as<double>();
	m3_damage_min = yaml_file["m3_damage_min"].as<double>();
	awp_damage_min = yaml_file["awp_damage_min"].as<double>();
	knife_damage_max = yaml_file["knife_damage_max"].as<double>();
	glock_damage_max = yaml_file["glock_damage_max"].as<double>();
	ak47_damage_max = yaml_file["ak47_damage_max"].as<double>();
	m3_damage_max = yaml_file["m3_damage_max"].as<double>();
	awp_damage_max = yaml_file["awp_damage_max"].as<double>();
	glock_shoot_rate = yaml_file["glock_shoot_rate"].as<int>();
	ak47_shoot_rate = yaml_file["ak47_shoot_rate"].as<int>();
	m3_shoot_rate = yaml_file["m3_shoot_rate"].as<int>();
	awp_shoot_rate = yaml_file["awp_shoot_rate"].as<int>();
	glock_shoot_freq = yaml_file["glock_shoot_freq"].as<int>();
	ak47_shoot_freq = yaml_file["ak47_shoot_freq"].as<int>();
	m3_shoot_freq = yaml_file["m3_shoot_freq"].as<int>();
	awp_shoot_freq = yaml_file["awp_shoot_freq"].as<int>();
	glock_distance_penalty = yaml_file["glock_distance_penalty"].as<double>();
	ak47_distance_penalty = yaml_file["ak47_distance_penalty"].as<double>();
	m3_distance_penalty = yaml_file["m3_distance_penalty"].as<double>();
	awp_distance_penalty = yaml_file["awp_distance_penalty"].as<double>();
	knife_distance_penalty = yaml_file["knife_distance_penalty"].as<double>();


	glock_price = yaml_file["glock_price"].as<int>();
	ak47_price = yaml_file["ak47_price"].as<int>();
	m3_price = yaml_file["m3_price"].as<int>();
	awp_price = yaml_file["awp_price"].as<int>();
	glock_ammo = yaml_file["glock_ammo"].as<int>();
	ak47_ammo = yaml_file["ak47_ammo"].as<int>();
	m3_ammo = yaml_file["m3_ammo"].as<int>();
	awp_ammo = yaml_file["awp_ammo"].as<int>();
	
	glock_max_distance = yaml_file["glock_max_distance"].as<double>();
	ak47_max_distance = yaml_file["ak47_max_distance"].as<double>();
	m3_max_distance = yaml_file["m3_max_distance"].as<double>();
	awp_max_distance = yaml_file["awp_max_distance"].as<double>();
	knife_max_distance = yaml_file["knife_max_distance"].as<double>();

}
