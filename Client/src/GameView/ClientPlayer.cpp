#include "ClientPlayer.h"

ClientPlayer::ClientPlayer(char& id, std::string& name):id(id), name(name) {
    
}

ClientPlayer::~ClientPlayer() {

}


void ClientPlayer::set_team(Team team) {
	texture = &(SpriteContainer::getInstance()[id]);
	
}

Texture& ClientPlayer::getTexture() {
	return *texture;
}

SDL_Rect ClientPlayer::getBox() {
	SDL_Rect quad = {20, 20, texture->get_w(), texture->get_h()};
	return quad;
}

char ClientPlayer::get_id() {
	return id;
}