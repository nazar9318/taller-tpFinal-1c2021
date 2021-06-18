#include "Configuration.h"


YAML::Node CF::yaml_file = YAML::LoadFile("Configuration.yaml");

int CF::number_bullets = CF::yaml_file["number_bullets"].as<int>();

double CF::ak47_range = CF::yaml_file["ak47_range"].as<double>(); 

