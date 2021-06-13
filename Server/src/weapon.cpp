#include "weapon.hpp"

Weapon::Weapon(uint16_t price, uint16_t damage, uint16_t accuracy, 
uint16_t shoot_rate, uint16_t shoot_freq, 
uint16_t distance_penalty, bool automatic) : 
price(price), damage(damage), accuracy(accuracy), shoot_rate(shoot_rate),
shoot_freq(shoot_freq), distance_penalty(distance_penalty), automatic(automatic) {}

Weapon::Weapon(Weapon& other) {
    this->damage = other.damage;
    this->price = other.price;
    this->accuracy = other.accuracy;
    this->shoot_rate = other.shoot_rate;
    this->shoot_freq = other.shoot_freq;
    this->distance_penalty = other.distance_penalty;
    this->automatic = other.automatic;
}

uint16_t Weapon::getPrice() { return this->price; }

void Weapon::shoot(Player &player) {
    player.takeDamage(this->damage);
}
