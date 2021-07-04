#include "ClientCharacter.h"
#include <math.h>
#include <complex>
#define PI 3.14159265

ClientCharacter::ClientCharacter(const std::string& _name) : name(_name) {
	pos = {0};
}

void ClientCharacter::set_team(Team team) {
	texture = &(SpriteContainer::getInstance()[team]);
	pos.w = texture->get_w();
	pos.h = texture->get_h();
}

SDL_Rect& ClientCharacter::getBox() {
	return pos;
}

Texture& ClientCharacter::getTexture() {
	return *texture;
}

double ClientCharacter::getAngle() {
	return angle;
}

void ClientCharacter::update_position(int pos_x, int pos_y, int angle) {
	pos.x = pos_x - texture->get_w()/2;
	pos.y = pos_y - texture->get_h()/2;

	std::complex<double>  z = std::polar (1.0, angle*PI/180);
	z = pow (z, -1);
	this->angle = (int) ((std::arg(z) + PI/2)* 180/PI);
}

ClientCharacter::~ClientCharacter() {}
