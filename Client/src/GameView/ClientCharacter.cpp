#include "ClientCharacter.h"

ClientCharacter::ClientCharacter(const std::string& _name) : name(_name) {

}

ClientCharacter::~ClientCharacter() {}


void ClientCharacter::set_team(Team team) {
	texture = &(SpriteContainer::getInstance()[team]);
	pos.w = texture->get_w();
	pos.h = texture->get_h();
}

SDL_Rect& ClientCharacter::getBox() {
	return pos;
}

void ClientCharacter::update_position(int pos_x, int pos_y) {
	pos.x = pos_x;
	pos.y = pos_y;
}
