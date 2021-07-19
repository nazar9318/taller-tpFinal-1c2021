#ifndef _CLIENT_CONFIGURATION_H
#define _CLIENT_CONFIGURATION_H

#include "yaml-cpp/yaml.h"

#include "Paths.h"

enum TerroristSkin {
	PHEONIX,
	L337KREW,
	ARTIC_AVENGER,
	GUERRILLA
};

enum CounterSkin: char {
	SEAL_FORCE,
	GERMAN_GSG9,
	UKSAS,
	FRENCH_GIGN
};

class ClientConfiguration;
typedef ClientConfiguration CCF;

class ClientConfiguration {
	public:
		static YAML::Node yaml_file;
		static TerroristSkin terrorist_skin;
		static CounterSkin counter_skin;
		static bool is_fullscreen;
		static bool sound_on;
		static int widowed_x;
		static int widowed_y;

		static void activate_sound();
		static void deactivate_sound();
		static void set_terrorist_skin(TerroristSkin skin);
		static void set_counter_skin(CounterSkin skin);
};

#endif
