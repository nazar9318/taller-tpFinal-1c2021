#include "weapon.h"

Weapon::Weapon(uint16_t price, uint16_t damage, uint16_t max_distance) : 
price(price), damage(damage), max_distance(max_distance) {}

uint16_t Weapon::getPrice() { return this->price; }

void Weapon::shoot(Character &character, uint16_t distance) {}

Weapon::~Weapon() {}
