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
		static double step_time;
		static int size_position;
		static int character_radius;

		/**************************************/


		static double time_preparation;
		static int number_rounds;

		static int players_allowed;
		static int velocity_iterations;
		static int position_iterations;

		static int max_distance_grab;

		static int character_life_points;
		static int character_money;

		static int bomb_clock_count;

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

		static int glock_range;
		static int ak47_range;
		static int m3_range;
		static int awp_range;

		static double glock_accuracy;
		static double ak47_accuracy;
		static double m3_accuracy;
		static double awp_accuracy;

		static int glock_shoot_rate;
		static int ak47_shoot_rate;
		static int m3_shoot_rate;
		static int awp_shoot_rate;

		static int glock_shoot_freq;
		static int ak47_shoot_freq;
		static int m3_shoot_freq;
		static int awp_shoot_freq;

		static double glock_distance_penalty;
		static double ak47_distance_penalty;
		static double m3_distance_penalty;
		static double awp_distance_penalty;
		static double knife_distance_penalty;

		static double glock_price;
		static double ak47_price;
		static double m3_price;
		static double awp_price;

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
