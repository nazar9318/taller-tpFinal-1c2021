#include "Character.h"
#include <algorithm>
#include <random>
#include <syslog.h>
#include "Bomb.h"
#include "WeaponWhite.h"
#include "WeaponPistol.h"
#include "WeaponShotgun.h"
#include "WeaponAutomatic.h"

Character::Character(Team team, b2World* world,
		 std::vector<Position*> available_positions)
		: life_points(CF::character_life_points),
		 money(CF::character_money), team(team),
		 number_weapons(2), angle(0) {
	std::unique_ptr<Weapon> knife(new WeaponWhite());
	std::unique_ptr<Weapon> pistol(new WeaponPistol());
	weapons.push_back(std::move(knife));
	weapons.push_back(std::move(pistol));
	current_weapon = 0;
	if (available_positions.size() == 0) {
		throw ExceptionInvalidCommand("No hay suficientes posiciones"
				" para ubicar a los jugadores", ServerError::MATCH_FULL);
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0,
					 available_positions.size() - 1);
	Position* position = available_positions[distrib(gen)];
	position->occupy();
	add_body(position->get_x(), position->get_y(), world);
	syslog(LOG_INFO, "[%s:%i]: Por agregar un character al world"
					 "con posicion (%d, %d) ", __FILE__, __LINE__,
					  position->get_x(), position->get_y());
	move_state = Direction::STOP_MOVING;
}

void Character::add_body(int x, int y, b2World* world) {
	b2BodyDef body_def;
	body_def.type = b2_dynamicBody;
	body_def.position.Set((int)x,(int)y);
	body_def.angle = 0;
	character_body = world->CreateBody(&body_def);

	b2CircleShape circle_shape;
	circle_shape.m_p.Set(0, 0);
	circle_shape.m_radius = CF::character_radius;
	b2FixtureDef fixture_def;
	fixture_def.shape = &circle_shape;
	fixture_def.density = 1;
	character_body->CreateFixture(&fixture_def);
}


void Character::set_move_state(Direction dir) {
	move_state = dir;
}

void Character::apply_impulses() {
	// Citamos iforce2d para esta funcion.
	if (life_points > 0) {
		b2Vec2 vel = character_body->GetLinearVelocity();
		b2Vec2 desired_vel(0.0, 0.0);
		switch (move_state) {
			case Direction::LEFT:
				desired_vel.x = -120.0f;
				desired_vel.y = 0.0;
				break;
			case Direction::RIGHT:
				desired_vel.x = 120.0f;
				desired_vel.y = 0.0;
				break;
			case Direction::UP:
				desired_vel.x = 0.0;
				desired_vel.y = 120.0f;
				break;
			case Direction::DOWN:
				desired_vel.x = 0.0;
				desired_vel.y = -120.0f;
				break;
			case Direction::STOP_MOVING:
				desired_vel.x = 0.0;
				desired_vel.y = 0.0;
		}
		b2Vec2 vel_change = desired_vel - vel;
		b2Vec2 impulse = character_body->GetMass() * vel_change;
		character_body->ApplyLinearImpulse
					(impulse, character_body->GetWorldCenter(), true);
	}
}

/*
void Character::attack(char self_id, std::list<Block>& blocks,
    	std::map<char, Character>& characters) {
	AttackInformation attack_info(self_id, this, get_opposite(team));
	if (is_alive())
		weapons[current_weapon]->attack(attack_info, blocks, characters);
	return attack_info;
}
*/


void Character::attack(AttackInformation& attack_info,
		 std::list<Block>& blocks, std::map<char, Character>& characters) {
	if (is_alive()) {
		attack_info.add_attacked_team(get_opposite(team));
		weapons[current_weapon]->attack(attack_info, blocks, characters);
	}
}

void Character::take_damage(char points) {
	if (life_points > points) {
		life_points -= points;
	} else {
		life_points = 0;
		character_body->GetWorld()->DestroyBody(character_body);
	}
}

/*
void Character::receive_damage(AttackInformation& attack) {
	if ((attack.get_team() == team) && is_alive()) {
		take_damage(attack.get_damage());

		if (life_points == 0) {
			attack.add_receiver(this, true);
		} else {
			attack.add_receiver(this, false);
		}
	}
}
*/



b2Vec2 Character::get_pos() {
	if (is_alive())
		return character_body->GetPosition();
	return b2Vec2(-10, 10); // una posicion fuera del mapa.
}

b2Fixture* Character::GetFixtureList() {
	return character_body->GetFixtureList();
}


void Character::start_attacking() {
	weapons[current_weapon]->activate();
		syslog(LOG_INFO, "[%s:%i]: START ATTACKING ", __FILE__, __LINE__);

}

void Character::stop_attacking() {
	weapons[current_weapon]->deactivate();
}

bool Character::has_enough_to_buy(std::unique_ptr<Weapon>& weapon_buy) {
	return (money >= weapon_buy->get_price());
}


bool Character::has_optative_weapon() {
	return (number_weapons == 3);
}

Weapon* Character::drop_optative_weapon() {
	Weapon* weapon = weapons[2].release();
	weapons.pop_back();
	number_weapons--;
	return weapon;
}

#define BONUS_KILL 50
void Character::add_kill_bonus() {
	money += BONUS_KILL;
}


void Character::buy_weapon(std::unique_ptr<Weapon> weapon) {
	money -= weapon->get_price();
	weapons.push_back(std::move(weapon));
	number_weapons++;
}


void Character::change_weapon() {
	if (is_alive())
		current_weapon = (current_weapon + 1) % number_weapons;
}


Team Character::get_team() {
	return team;
}





bool Character::is_alive() {
	return (life_points > 0);
}

void Character::add_weapon(std::unique_ptr<Weapon> weapon) {
	weapons.push_back(std::move(weapon));
	number_weapons++;
}


void Character::set_angle(int alfa) {
	angle = alfa;
}

int Character::get_angle() {
	return angle;
}

char Character::get_life(){
	return life_points;
}

int Character::get_money(){
	return money;
}

int Character::get_ammo(){
	return weapons[current_weapon]->get_ammo();
}

char Character::get_weapon_type(){
	return weapons[current_weapon]->get_type();
}

Character::~Character() {
}



/*


void Character::take(unsigned int money) {
	if (this->life_points > 0) {
		this->money += money;
	}
}
*/
/*

char Character::getLifePoints() {
	return life_points;
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

void Character::place(Bomb* bomb) {
	if (this->team == TERRORIST || bomb == this->weapons[3]) {
		bomb->place();
	}
}

void Character::deactivate(Bomb *bomb) {
	if (this->team == COUNTER_ENEMY) {
		bomb->deactivate();
	}
}*/
