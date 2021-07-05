#include "GrabWeaponHandler.h"
#include <syslog.h>
GrabWeaponHandler::GrabWeaponHandler() {}

void GrabWeaponHandler::handle(Event& event, GameWorld& world){
	Character& character = world.get_character(event.get_id());
	if (character.is_alive()) {
		b2Vec2 pos = character.get_pos();
		// siempre es prioridad agarrar la bomba. 
		// solo la pueden agarrar los terroristas. 
		if (!world.grab_bomb(event.get_id(), character.get_team(), pos)) {
			Weapon* new_weapon;
			bool is_close = world.get_closest_weapon(pos, &new_weapon);
			if (is_close) {
				std::unique_ptr<Weapon> char_weapon(new_weapon);
				if (character.has_optative_weapon()) {
					Weapon* ground_weapon = character.drop_optative_weapon();
					world.add_weapon(pos, ground_weapon);
				}
				character.add_weapon(std::move(char_weapon)); 
			}
		}
	}
}

GrabWeaponHandler::~GrabWeaponHandler(){}
