#include "ClientCharacter.h"

ClientCharacter::ClientCharacter(const std::string& _name) : name(_name) {
	pos = {0};
}

void ClientCharacter::set_team(Team team) {
	texture = &(SpriteContainer::getInstance()[team]);
	pos.w = texture->get_w();
	pos.h = texture->get_h();
}

void ClientCharacter::update_position(int pos_x, int pos_y, int angle) {
	pos.x = pos_x - texture->get_w()/2;
	pos.y = pos_y - texture->get_h()/2;
	this->angle = angle;
}

SDL_Rect& ClientCharacter::getBox() { return pos; }

Texture& ClientCharacter::getTexture() { return *texture; }

ClientCharacter::~ClientCharacter() {}
