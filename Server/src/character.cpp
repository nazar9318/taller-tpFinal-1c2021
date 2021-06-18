#include "character.h"

Character::Character(double life_points, uint16_t money, Team team) :
life_points(life_points), money(money), team(team) {
    this->weapons.push_back(new WeaponWhite(0, 15));
    this->weapons.push_back(new WeaponManual(0, 30, 10, 0.8, 0.8, 18));
    this->current_weapon = this->weapons[0];
}

void Character::take(uint16_t money) {
    if (this->life_points > 0) {
        this->money += money;
    }
}

void Character::takeDamage(double life_points) {
    if (this->life_points > 0) {
        if (this->life_points > life_points) {
            this->life_points -= life_points;
        } else {
            this->life_points = 0;
        }
    }
}

void Character::changeCurrentWeapon(uint16_t pos) {
    if (this->life_points > 0) {
        if (pos <= this->weapons.size()) {
            current_weapon = this->weapons[pos-1];
        }
    }
}

double Character::getLifePoints() { return this->life_points; }

Team Character::getTeam() { return this->team; }

void Character::grab(Weapon *new_weapon) {
    if (this->life_points > 0) {
        this->weapons.push_back(new_weapon);
    }
}

void Character::buy(Weapon *new_weapon) {
    if (this->life_points > 0 && this->money >= new_weapon->getPrice()) {
        this->weapons.push_back(new_weapon);
        this->money -= new_weapon->getPrice();
    }
}

void Character::attack(Character &enemy, Team my_team, uint16_t distance) {
    if (this->life_points > 0) {
        if (enemy.getTeam() != this->getTeam()) {
            this->current_weapon->shoot(enemy, distance);
        }
    }
}

Character::~Character() {
/*    for (const auto &weapon : this->weapons) {
        delete weapon;
    }*/
}