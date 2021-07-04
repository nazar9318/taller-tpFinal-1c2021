#include "ClientPlayer.h"

ClientPlayer::ClientPlayer(char& id, std::string& name):id(id), name(name) {
	pos = {0};
}

ClientPlayer::~ClientPlayer() {

}


void ClientPlayer::set_team(Team team) {
	texture = &(SpriteContainer::getInstance()[team]);
	pos.x = 0;
	pos.y = 0;
	pos.w = texture->get_w();
	pos.h = texture->get_h();
}

Texture& ClientPlayer::getTexture() {
	return *texture;
}

SDL_Rect& ClientPlayer::getBox() {
	return pos;
}

#include <math.h>
#include <complex> 
#define PI 3.14159265

void ClientPlayer::update_position(int pos_x, int pos_y, int angle, char life, int money) {
	pos.x = pos_x - texture->get_w()/2;
	pos.y = pos_y - texture->get_h()/2;
	std::complex<double>  z = std::polar (1.0, angle*PI/180);
	z = pow (z, -1);
	this->angle = (int) ((std::arg(z) + PI/2)* 180/PI);
	this->life = life;
	this->money = money;
}

void ClientPlayer::render(Renderer& renderer, int cam_x, int cam_y){
	SDL_Rect renderQuad = { pos.x - cam_x, pos.y - cam_y, texture->get_w(), texture->get_h() };


	renderer.render(texture->getTexture(), NULL, &renderQuad, angle);
}

double ClientPlayer::getAngle(){
	return (double)angle;
}

char ClientPlayer::get_id() {
	return id;
}
