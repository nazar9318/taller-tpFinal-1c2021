#include "Configuration.h"
#include <syslog.h>


YAML::Node CF::yaml_file = YAML::LoadFile("Configuration.yaml");

std::string CF::host = yaml_file["host"].as<std::string>();
std::string CF::port = yaml_file["port"].as<std::string>();
int CF::max_iterations_pop_events = 
				CF::yaml_file["max_iterations_pop_events"].as<int>();


double CF::character_life_points = CF::yaml_file["character_life_points"].as<double>();
double CF::character_money = CF::yaml_file["character_money"].as<double>();
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
double CF::glock_price = CF::yaml_file["glock_price"].as<double>();
double CF::ak47_price = CF::yaml_file["ak47_price"].as<double>();
double CF::m3_price = CF::yaml_file["m3_price"].as<double>();
double CF::awp_price = CF::yaml_file["awp_price"].as<double>();
int CF::glock_ammo = CF::yaml_file["glock_ammo"].as<int>();
int CF::ak47_ammo = CF::yaml_file["ak47_ammo"].as<int>();
int CF::m3_ammo = CF::yaml_file["m3_ammo"].as<int>();
int CF::awp_ammo = CF::yaml_file["awp_ammo"].as<int>();
double CF::glock_max_distance = CF::yaml_file["glock_max_distance"].as<double>();
double CF::ak47_max_distance = CF::yaml_file["ak47_max_distance"].as<double>();
double CF::m3_max_distance = CF::yaml_file["m3_max_distance"].as<double>();
double CF::awp_max_distance = CF::yaml_file["awp_max_distance"].as<double>();


Configuration::Configuration() {}
Configuration::~Configuration() {}

void Configuration::load_configuration(const std::string& file_path) {
	yaml_file =	YAML::LoadFile("../../../" + file_path);
	
	host = yaml_file["host"].as<std::string>();
	port = yaml_file["port"].as<std::string>();
	syslog(LOG_INFO, "[%s:%i]: Se cargo el port: %s"
			, __FILE__, __LINE__, port.c_str());
	max_iterations_pop_events = yaml_file["max_iterations_pop_events"].as<int>();


	character_life_points = yaml_file["character_life_points"].as<double>();
	character_money = yaml_file["character_money"].as<double>();
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
	glock_price = yaml_file["glock_price"].as<double>();
	ak47_price = yaml_file["ak47_price"].as<double>();
	m3_price = yaml_file["m3_price"].as<double>();
	awp_price = yaml_file["awp_price"].as<double>();
	glock_ammo = yaml_file["glock_ammo"].as<int>();
	ak47_ammo = yaml_file["ak47_ammo"].as<int>();
	m3_ammo = yaml_file["m3_ammo"].as<int>();
	awp_ammo = yaml_file["awp_ammo"].as<int>();
	glock_max_distance = yaml_file["glock_max_distance"].as<double>();
	ak47_max_distance = yaml_file["ak47_max_distance"].as<double>();
	m3_max_distance = yaml_file["m3_max_distance"].as<double>();
	awp_max_distance = yaml_file["awp_max_distance"].as<double>();
}