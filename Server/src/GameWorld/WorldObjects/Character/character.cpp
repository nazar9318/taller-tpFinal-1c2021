#include "character.h"
#include <algorithm>
#include <random>

float Character::body_radius = 0.5;

Character::Character(Team team, b2World* world,
		 std::vector<Position*> available_positions)
		: life_points(CF::character_life_points),
		 money(CF::character_money), team(team) {
	this->weapons.push_back(new WeaponWhite());
	this->weapons.push_back(new WeaponPistol());
	this->current_weapon = this->weapons[0];
	if (available_positions.size() == 0) {
		throw Exception("No hay suficientes posiciones"
					" para ubicar a los jugadores");
	}
	std::random_device rd;  
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0,
					 available_positions.size() - 1);
	Position* position = available_positions[distrib(gen)];
	position->occupy();
	add_body(position->get_x(), position->get_y(), world);
}

void Character::add_body(char x, char y, b2World* world) {
	b2BodyDef body_def;
	body_def.type = b2_dynamicBody; 
	body_def.position.Set((int)x,(int)y); 
	body_def.angle = 0; 
	character_body = world->CreateBody(&body_def);
	
	b2CircleShape circle_shape;
	circle_shape.m_p.Set(0, 0);
	circle_shape.m_radius = body_radius;
	b2FixtureDef fixture_def;
	fixture_def.shape = &circle_shape; 
	character_body->CreateFixture(&fixture_def);
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
	if (this->life_points > 0 && !new_weapon->taken()) {
		if (this->weapons.size() == 2) {
			this->weapons.push_back(new_weapon);
		} else {
			this->weapons[2]->beNotTaken();
			this->weapons[2] = new_weapon;
		}
		new_weapon->beTaken();
	}
}

void Character::grab(Bomb* bomb) {
	if (this->team == TERRORIST) {
		if (this->weapons.size() == 3) {
			this->weapons.push_back(bomb);
		} else {
			this->weapons.push_back(NULL);
			this->weapons.push_back(bomb);
			//this->weapons.insert(this->weapons.begin() + 4, bomb);
		}
	}
}

void Character::removeSecondary() {
	if (this->weapons.size() > 2) {
		this->weapons[2]->beNotTaken();
		this->weapons[2] = NULL;
		this->current_weapon = this->weapons[1];
	}
}

void Character::buy(Weapon *new_weapon) {
	if (this->money >= new_weapon->getPrice()) {
		this->grab(new_weapon);
		this->money -= new_weapon->getPrice();
	}
}

void Character::place(Bomb* bomb) {
	if (this->team == TERRORIST || bomb == this->weapons[3]) {
		bomb->place();
	}
}

void Character::deactivate(Bomb *bomb) {
	if (this->team == COUNTER_ENEMY) {
		bomb->deactivate();
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
	for (const auto &weapon : this->weapons) {
		delete weapon;
	}
}
