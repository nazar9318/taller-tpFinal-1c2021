#include "ClientConfiguration.h"


YAML::Node CCF::yaml_file = YAML::LoadFile(CLIENT_CONFIGURATION_PATH);
int CCF::widowed_x = CCF::yaml_file["widowed_x"].as<int>();
int CCF::widowed_y = CCF::yaml_file["widowed_y"].as<int>();

TerroristSkin CCF::terrorist_skin = TerroristSkin::Pheonix; 
CounterSkin CCF::counter_skin = CounterSkin::SealForce;
bool CCF::is_fullscreen = false;
bool CCF::sound_on = true;

void ClientConfiguration::activate_sound() {
	sound_on = true;
}

void ClientConfiguration::deactivate_sound() {
	sound_on = false;
}

void ClientConfiguration::set_terrorist_skin(TerroristSkin skin) {
	terrorist_skin = skin;
}

void ClientConfiguration::set_counter_skin(CounterSkin skin) {
	counter_skin = skin;
}

