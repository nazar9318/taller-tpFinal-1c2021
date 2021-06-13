#include "player.hpp"

Player::Player(uint16_t life_points, uint16_t money, Team team) :
life_points(life_points), money(money), team(team) {}

void Player::take(uint16_t money) {
    this->money += money;
}

void Player::takeDamage(uint16_t life_points) {
    this->life_points -= life_points;
}

void Player::grab(Weapon *new_weapon) {
    this->weapons.push_back(new_weapon);
}

void Player::buy(Weapon& new_weapon) {
    this->weapons.push_back(new Weapon(new_weapon));
    this->money -= new_weapon.getPrice();
}

void Player::attack(Player &enemy, Team my_team) {
    this->current_weapon->shoot(enemy);
}
