#include "ClientCharacter.h"
#include <math.h>
#include <complex>

#define PI 3.14159265
#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 32

ClientCharacter::ClientCharacter(const std::string& _name)
: name(_name), current_clip(0), squad(0), dead(false) {
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
	if (team == TERRORIST) {
		this->team = "Terrorist";
	} else if (team == COUNTER_ENEMY) {
		this->team = "Counter";
	}
}

void ClientCharacter::setSquad(int squad) { this->squad = squad; }

int ClientCharacter::getSquad() const { return this->squad; }

SDL_Rect& ClientCharacter::getBox() { return pos; }

Texture& ClientCharacter::getTexture() { return *texture; }

double ClientCharacter::getAngle() { return angle; }

void ClientCharacter::update_position(int pos_x, int pos_y, int angle, char weapon_type, int life) {
	pos.x = pos_x - PLAYER_WIDTH/2;
	pos.y = pos_y - PLAYER_HEIGHT/2;
	std::complex<double>  z = std::polar (1.0, angle*PI/180);
	z = pow (z, -1);
	this->angle = (int) ((std::arg(z) + PI/2)* 180/PI);

	if(life <= 0) {
		dead = true;
	} else {
		dead = false;
	}

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

void ClientCharacter::render(Camera& camera){
	if(!dead){
		SDL_Rect renderQuad = { pos.x, pos.y, PLAYER_WIDTH, PLAYER_HEIGHT};
		camera.renderAddingOffset(texture->getTexture(), renderQuad, &clip[current_clip], angle);
	}
}

SDL_Rect& ClientCharacter::getClip() { return clip[current_clip]; }

std::string ClientCharacter::getTeam() { return team; }

std::string ClientCharacter::get_name() { return name; }

ClientCharacter::~ClientCharacter() {}
