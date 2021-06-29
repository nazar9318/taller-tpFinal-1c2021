#include "Weapon.h"

Weapon::Weapon(uint16_t price, uint16_t damage_min, uint16_t damage_max) :
price(price), damage_min(damage_min), damage_max(damage_max) { 
	this->with_owner = false; 
	activated = false;
}

void Weapon::activate() {
	activated = true;
}

void Weapon::deactivate() {
	activated = false;
}



void Weapon::beTaken() { this->with_owner = true; }

const bool Weapon::taken() { return this->with_owner; }

void Weapon::beNotTaken() { this->with_owner = true; }

const uint16_t Weapon::getPrice() { return this->price; }

void Weapon::shoot(Character &character, uint16_t distance) {}


void Weapon::attack(AttackInformation attack_info, std::list<Block>& blocks,
									 std::map<char, Character>& characters) {
	float angle = attack_info.get_angle();
	angle += 0.1;
}




Weapon::~Weapon() {}
