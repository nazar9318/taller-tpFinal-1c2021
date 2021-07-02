#include "GrabWeaponHandler.h"
#include <syslog.h>
GrabWeaponHandler::GrabWeaponHandler() {}

void GrabWeaponHandler::handle(Event& event, GameWorld& world){
	Character& character = world.get_character(event.get_id());
	if (character.is_alive()) {
		Weapon* new_weapon;
		bool is_close = 
			world.get_closest_weapon(character.get_pos(), &new_weapon);
		if (is_close) {
		syslog(LOG_INFO, "[%s:%i]: esta cerca"
				, __FILE__, __LINE__);
			std::unique_ptr<Weapon> char_weapon(new_weapon);
			if (character.has_optative_weapon()) {
				syslog(LOG_INFO, "[%s:%i]: entra if"
				, __FILE__, __LINE__);

				Weapon* ground_weapon = character.drop_optative_weapon();
				world.add_weapon(character.get_pos(), ground_weapon);
			}
			syslog(LOG_INFO, "[%s:%i]: sale if"
				, __FILE__, __LINE__);
			if (char_weapon ) {
				syslog(LOG_INFO, "[%s:%i]: viene bien"
				, __FILE__, __LINE__);
			}
			character.add_weapon(std::move(char_weapon)); 
			syslog(LOG_INFO, "[%s:%i]: recontra sale if"
				, __FILE__, __LINE__);
		}
	}

}

GrabWeaponHandler::~GrabWeaponHandler(){}
