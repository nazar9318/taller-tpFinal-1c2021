#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <fstream>
#include <iostream>
#include <string>

#include "yaml-cpp/yaml.h"

class Configuration;
typedef Configuration CF;

class Configuration {
	public:
		Configuration();
		~Configuration();
		static void load_configuration(const std::string& file_path);
		static YAML::Node yaml_file;

		/**************************************/
		/**************COMMON******************/
		static YAML::Node common_yaml_file;
		static std::string port;
		static int max_iterations_pop_events;
		static int size_position;
		static int character_radius;

		/**************************************/
		static int TIME_BOMB_EXPLOTE;
		static int TIME_BOMB_ACTIVATE;
		static int TIME_BOMB_DEACTIVATE;

		static double time_preparation;
		static double time_finish;
		static int number_rounds;

		static int players_allowed;
		static int velocity_iterations;
		static int position_iterations;

		static int bonus_kill;
		static int max_distance_grab;

		static int character_life_points;
		static int character_money;

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

		static int glock_bullets;
		static int ak47_bullets;
		static int m3_bullets;
		static int awp_bullets;

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

		static int glock_price;
		static int ak47_price;
		static int m3_price;
		static int awp_price;

		static int glock_ammo;
		static int ak47_ammo;
		static int m3_ammo;
		static int awp_ammo;

		static double glock_max_distance;
		static double ak47_max_distance;
		static double m3_max_distance;
		static double awp_max_distance;
		static double knife_max_distance;
};

#endif
