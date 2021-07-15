#include "ClientConfiguration.h"


TerroristSkin CCF::terrorist_skin = TerroristSkin::Pheonix; 
CounterSkin CCF::counter_skin = CounterSkin::SealForce;
WindowSize CCF::window_size = WindowSize::Windowed;
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

