#include "ClientCharacter.h"
#include <math.h>
#include <complex>
#define PI 3.14159265

ClientCharacter::ClientCharacter(const std::string& _name)
: name(_name), current_clip(0) {
	pos = {0};
	for (int i = 0; i < LIMIT_POSES; i++) { clip[i] = {0}; }
	for (int i = 0; i < LIMIT_POSES; i++) {
		clip[i].w = 32;
		clip[i].h = 32;
	}
	clip[0].x = 32;
	clip[0].y = 0;
	clip[1].x = 32;
	clip[1].y = 32;
	clip[2].x = 0;
	clip[2].y = 0;
}

void ClientCharacter::set_team(Team team) {
	texture = &(SpriteContainer::getInstance()[team]);
	pos.w = 32;
	pos.h = 32;
}

SDL_Rect& ClientCharacter::getBox() { return pos; }

Texture& ClientCharacter::getTexture() { return *texture; }

double ClientCharacter::getAngle() { return angle; }

void ClientCharacter::update_position(int pos_x, int pos_y, int angle, char weapon_type) {
	pos.x = pos_x - texture->get_w()/2;
	pos.y = pos_y - texture->get_h()/2;
	std::complex<double>  z = std::polar (1.0, angle*PI/180);
	z = pow (z, -1);
	this->angle = (int) ((std::arg(z) + PI/2)* 180/PI);
	switch (weapon_type) {
		case PositionType::KNIFE : {
			this->current_clip = 0;
			texture_weapon = &(SpriteContainer::getInstance()[Equipped_Weapon::KNIFE_EQUIPPED]);
			break;
		}
		case PositionType::GLOCK : {
			this->current_clip = 1;
			texture_weapon = &(SpriteContainer::getInstance()[Equipped_Weapon::GLOCK_EQUIPPED]);
			break;
		}
		case PositionType::AK47 : {
			this->current_clip = 2;
			texture_weapon = &(SpriteContainer::getInstance()[Equipped_Weapon::AK47_EQUIPPED]);
			break;
		}
		case PositionType::M3 : {
			this->current_clip = 2;
			texture_weapon = &(SpriteContainer::getInstance()[Equipped_Weapon::M3_EQUIPPED]);
			break;
		}
		case PositionType::AWP : {
			this->current_clip = 2;
			texture_weapon = &(SpriteContainer::getInstance()[Equipped_Weapon::AWP_EQUIPPED]);
			break;
		}
		default: break;
	}
}

SDL_Rect& ClientCharacter::getClip() { return clip[current_clip]; }

ClientCharacter::~ClientCharacter() {}
