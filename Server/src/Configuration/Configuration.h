#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <fstream>
#include <iostream>
#include <string>

#include "yaml-cpp/yaml.h"

class Confuguration;
typedef Confuguration CF;

class Confuguration {
	public:
		Confuguration();
		~Confuguration();
		static YAML::Node yaml_file;
		
		static int number_bullets;
		static double ak47_range;
};

#endif
