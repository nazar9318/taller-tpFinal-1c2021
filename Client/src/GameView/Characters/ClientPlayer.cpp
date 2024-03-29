#include "ClientPlayer.h"
#include <math.h>
#include <complex>

#define PI 3.14159265
#define STENCIL_WIDTH 2*window_width
#define STENCIL_HEIGHT 2*window_width

ClientPlayer::ClientPlayer(char& id, std::string& name, int window_width, int window_height):
	id(id),
 	name(name),
 	current_clip(0),
	bomb_owner(false),
 	squad(0),
 	dead(false),
	window_width(window_width),
	window_height(window_height) {
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

void ClientPlayer::createStencil(Renderer& renderer, double angle, int alpha, int radius){
	Stencil::buildStencil(renderer, stencil, angle, alpha, radius);
}

void ClientPlayer::set_team(Team team) {
	texture = &(SpriteContainer::getInstance()[team]);
	pos.x = 0;
	pos.y = 0;
	pos.w = PLAYER_WIDTH;
	pos.h = PLAYER_HEIGHT;
	if (team == TERRORIST) {
		this->team = "Terrorist";
	} else if (team == COUNTER_ENEMY) {
		this->team = "Counter";
	}
}

std::string ClientPlayer::getTeam() { return team; }

void ClientPlayer::setSquad(int squad) { this->squad = squad; }

int ClientPlayer::getSquad() const { return this->squad; }

void ClientPlayer::update_position(int pos_x, int pos_y, int angle,
		char life, int money, char weapon_type, int ammo) {
	pos.x = pos_x - PLAYER_WIDTH/2;
	pos.y = pos_y - PLAYER_HEIGHT/2;
	std::complex<double> z = std::polar (1.0, angle*PI/180);
	z = pow (z, -1);
	this->angle = (int)((std::arg(z) + PI/2)* 180/PI);
	this->life = life;
	if(life <= 0){
		dead = true;
	} else {
		dead = false;
	}

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
	if(dead){
		return;
	}
	/*Renderizo el player*/
	SDL_Rect renderQuad = { pos.x, pos.y, PLAYER_WIDTH, PLAYER_HEIGHT};
	camera.renderAddingOffset(texture->getTexture(), renderQuad, &clip[current_clip], angle);

	/*Renderizo su arma*/
	SDL_Rect quad = {pos.x, pos.y, texture_weapon->get_w(), texture_weapon->get_h()};
	camera.renderAddingOffset(texture_weapon->getTexture(), quad, NULL, angle + 180);

	/*Renderizo el stencil*/
	renderQuad = { pos.x + PLAYER_WIDTH/2 - STENCIL_WIDTH/2, pos.y + PLAYER_HEIGHT/2 - STENCIL_HEIGHT/2,
		 						STENCIL_WIDTH, STENCIL_HEIGHT};
	camera.renderAddingOffset(stencil.getTexture(), renderQuad, NULL, angle-90);

}

double ClientPlayer::getAngle() { return (double)angle; }

char ClientPlayer::get_id() { return id; }

Texture& ClientPlayer::getTexture() { return *texture; }

Texture& ClientPlayer::getWeapon() { return *texture_weapon; }

SDL_Rect& ClientPlayer::getClip() { return clip[current_clip]; }

SDL_Rect& ClientPlayer::getBox() { return pos; }

std::string ClientPlayer::get_name() {
	return name;
}

void ClientPlayer::change_bomb_ownership(bool is_owner){
	bomb_owner = is_owner;
}

bool ClientPlayer::has_bomb(){
	return bomb_owner;
}

ClientPlayer::~ClientPlayer() {}
