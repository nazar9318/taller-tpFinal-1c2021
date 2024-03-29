#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <fstream>
#include <iostream>
#include <string>

#include "yaml-cpp/yaml.h"
#include "Paths.h"
#define AMMO_CARTRIDGE_SIZE 10
#define SIZE_POSITION 64

class Configuration;
typedef Configuration CF;

class Configuration {
	public:
		Configuration();
		~Configuration();
		static void load_configuration(const std::string& file_path);
		static YAML::Node yaml_file;

		static std::string port;
		static int size_position;
		static int character_radius;

		static int stencil_angle;
		static int stencil_radio;
		static int alpha_blending;

		static int TIME_BOMB_EXPLOTE;
		static int TIME_BOMB_ACTIVATE;
		static int TIME_BOMB_DEACTIVATE;

		static double time_preparation;
		static double time_finish;
		static double time_between;
		static int number_rounds;

		static int players_allowed;

		static int bonus_kill;
		static int max_distance_grab;

		static int character_life_points;
		static int character_money;
		static int end_round_bonification;
		static int win_round_bonification;

		static double knife_damage_min;
		static double glock_damage_min;
		static double ak47_damage_min;
		static double m3_damage_min;
		static double awp_damage_min;

		static double knife_damage_max;
		static double glock_damage_max;
		static double ak47_damage_max;
		static double m3_damage_max;
		static double awp_damage_max;

		static double glock_accuracy;
		static double ak47_accuracy;
		static double m3_accuracy;
		static double awp_accuracy;

		static int ak47_shoot_rate;

		static double ak47_shoot_freq;

		static double glock_distance_penalty;
		static double ak47_distance_penalty;
		static double m3_distance_penalty;
		static double awp_distance_penalty;
		static double knife_distance_penalty;

		static int ak47_price;
		static int m3_price;
		static int awp_price;

		static int ak47_10_bullets_price;
		static int m3_10_bullets_price;
		static int awp_10_bullets_price;
		static int glock_10_bullets_price;

		static int glock_ammo;
		static int ak47_ammo;
		static int m3_ammo;
		static int awp_ammo;

		static int glock_max_ammo;
		static int ak47_max_ammo;
		static int m3_max_ammo;
		static int awp_max_ammo;

		static double glock_max_distance;
		static double ak47_max_distance;
		static double m3_max_distance;
		static double awp_max_distance;
		static double knife_max_distance;

		static double awp_retard_time;

		static int m3_angle_covered;
};

#endif
