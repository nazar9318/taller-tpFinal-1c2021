#include "ClientCharacter.h"

ClientCharacter::ClientCharacter(const std::string& _name) : name(_name) {

}

ClientCharacter::~ClientCharacter() {}


void ClientCharacter::set_team(Team team) {
	texture = &(SpriteContainer::getInstance()[team]);
}
