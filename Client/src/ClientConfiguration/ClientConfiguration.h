#ifndef _CLIENT_CONFIGURATION_H
#define _CLIENT_CONFIGURATION_H 

enum TerroristSkin {
	Pheonix,
	L337Krew, 
	ArticAvenger,
	Guerrilla
};

enum CounterSkin: char {
	SealForce,
	GermanGSG9,
	UKSAS, 
	FrenchGIGN
};

enum WindowSize: char{
	FullScreen, 
	Windowed
};

class ClientConfiguration;
typedef ClientConfiguration CCF;

class ClientConfiguration {
	public:
		static TerroristSkin terrorist_skin;
		static CounterSkin counter_skin;
		static WindowSize window_size;
		static bool sound_on;

		static void activate_sound();
		static void deactivate_sound();
		static void set_terrorist_skin(TerroristSkin skin);
		static void set_counter_skin(CounterSkin skin);
};

#endif
