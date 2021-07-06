#include "ClientPlayer.h"
#include <math.h>
#include <complex>
#include <iostream>
#define PI 3.14159265
#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 32

ClientPlayer::ClientPlayer(char& id, std::string& name):
id(id), name(name), current_clip(0) {
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

void ClientPlayer::set_team(Team team) {
	texture = &(SpriteContainer::getInstance()[team]);
	pos.x = 0;
	pos.y = 0;
	pos.w = PLAYER_WIDTH;
	pos.h = PLAYER_HEIGHT;
}

/*void ClientPlayer::set_weapon() {
	texture_weapon = &(SpriteContainer::getInstance()[weapon]);
}

void ClientPlayer::changeClip() {
	if (this->current_clip == LIMIT_POSES-1) {
		this->current_clip = 0;
	} else {
		this->current_clip++;
	}
}*/

void ClientPlayer::update_position(int pos_x, int pos_y, int angle,
		char life, int money, char weapon_type, int ammo) {
	pos.x = pos_x - PLAYER_WIDTH/2;
	pos.y = pos_y - PLAYER_HEIGHT/2;
	std::complex<double> z = std::polar (1.0, angle*PI/180);
	z = pow (z, -1);
	this->angle = (int)((std::arg(z) + PI/2)* 180/PI);
	this->life = life;
	this->money = money;
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

void ClientPlayer::render(Camera& camera) {
	/*Renderizo el player*/
	SDL_Rect renderQuad = { pos.x, pos.y, PLAYER_WIDTH, PLAYER_HEIGHT};
	camera.renderAddingOffset(texture->getTexture(), renderQuad, &clip[current_clip], angle);

	/*Renderizo su arma*/
	camera.render(texture_weapon->getTexture(), renderQuad, NULL, angle);

	/*Renderizo el stencil*/
}

double ClientPlayer::getAngle() { return (double)angle; }

char ClientPlayer::get_id() { return id; }

Texture& ClientPlayer::getTexture() { return *texture; }

Texture& ClientPlayer::getWeapon() { return *texture_weapon; }

SDL_Rect& ClientPlayer::getClip() { return clip[current_clip]; }

SDL_Rect& ClientPlayer::getBox() { return pos; }

ClientPlayer::~ClientPlayer() {}
