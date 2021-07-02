#include "ClientPlayer.h"

ClientPlayer::ClientPlayer(char& id, std::string& name):id(id), name(name) {

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

SDL_Rect ClientPlayer::getBox() {
	return pos;
}

void ClientPlayer::update_position(int pos_x, int pos_y) {
	pos.x = pos_x - texture->get_w()/2;
	pos.y = pos_y - texture->get_h()/2;
}


char ClientPlayer::get_id() {
	return id;
}
