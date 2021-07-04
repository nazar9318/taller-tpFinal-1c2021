#include "ClientPlayer.h"
#include <math.h>
#include <complex>
#include <iostream>
#define PI 3.14159265

ClientPlayer::ClientPlayer(char& id, std::string& name):
id(id), name(name), current_clip(0) {
	pos = {0};
	for (int i = 0; i < LIMIT_POSES; i++) { clip[i] = {0}; }

	clip[0].w = 32;
	clip[0].h = 32;
	clip[1].w = 32;
	clip[1].h = 32;
	clip[2].w = 32;
	clip[2].h = 32;

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
	pos.w = 32;
	pos.h = 32;
}

void ClientPlayer::changeClip() {
	if (this->current_clip == LIMIT_POSES-1) {
		this->current_clip = 0;
	} else {
		this->current_clip++;
	}
}

void ClientPlayer::update_position(int pos_x, int pos_y, int angle, char life, int money) {
	pos.x = pos_x - texture->get_w()/2;
	pos.y = pos_y - texture->get_h()/2;
	std::complex<double> z = std::polar (1.0, angle*PI/180);
	z = pow (z, -1);
	this->angle = (int)((std::arg(z) + PI/2)* 180/PI);
	this->life = life;
	this->money = money;
}

void ClientPlayer::render(Renderer& renderer) {
	SDL_Rect renderQuad = { 
		pos.x,
		pos.y,
		pos.w,
		pos.h
	};
	SDL_RenderCopy(renderer.getRenderer(), texture->getTexture(), &pos, &renderQuad);
	//renderer.render(texture->getTexture(), NULL, &renderQuad, angle);
}

double ClientPlayer::getAngle() { return (double)angle; }

char ClientPlayer::get_id() { return id; }

Texture& ClientPlayer::getTexture() { return *texture; }

SDL_Rect& ClientPlayer::getClip() { return clip[current_clip];}

SDL_Rect& ClientPlayer::getBox() { return pos; }

ClientPlayer::~ClientPlayer() {}
