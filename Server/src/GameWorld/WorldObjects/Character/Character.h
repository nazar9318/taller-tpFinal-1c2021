#ifndef CHARACTER_H
#define CHARACTER_H

class AttackInformation;
class Weapon;
class WeaponBomb;
class WeaponWhite;
class WeaponPistol;
class WeaponShotgun;
class WeaponAutomatic;

#include "Position.h"
#include "Weapon.h"

#include "Team.h"
#include "StepInformation.h"
#include "Configuration.h"
#include "Block.h"
#include "TypesOfEvents.h"
#include "ExceptionInvalidCommand.h"
#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"
#include <vector>
#include <list>
#include <iostream>
#include <memory>

class Character {
	private:
		char life_points;
		unsigned int money;
		Team team;
		std::vector<std::unique_ptr<Weapon>> weapons;
		int current_weapon;
		int number_weapons;
		b2Body* character_body;
		Direction move_state;
		StepInformation& step_info;
		int angle;

	public:
		static float body_radius;
		Character(Team team, b2World* world,
			 std::vector<Position*> available_positions, 
			 StepInformation& step_info);
		
		Character(Character&&) = default;

		Character& operator = (Character&&) = default;

		void add_body(int x, int y, b2World* world);

		void set_move_state(Direction dir);

		Team get_team();

		void apply_impulses();

		bool has_enough_to_buy(std::unique_ptr<Weapon>& weapon_buy);

		bool has_optative_weapon();

		Weapon* drop_optative_weapon();

		void buy_weapon(std::unique_ptr<Weapon> weapon);

		void start_attacking();

		void change_weapon();

		b2Fixture* GetFixtureList();

		void receive_damage(AttackInformation& attack);

		b2Vec2 get_pos();

		void take_damage(char points);
		
		char getLifePoints();

		void attack(char self_id, std::list<Block>& blocks,
			 std::map<char, Character>& characters);

		bool is_alive();
		void add_weapon(std::unique_ptr<Weapon> weapon);

		void stop_attacking();

		void set_angle(int angle);

		int get_angle();

/*
disparo pistola ---. 
arma.attack(team.opposite(), pos.x, pos.y,
	 angulo, world, characters, stepinfo)
encuentra jugador/es
jugador{id}.recieveattack(calculoquehace)

80metros de ancho
cuchi 45grad 5metros
pistola normal busca en la recta ---->
sniper recto
area escopeta

*/



/*

		void buy(Weapon *new_weapon);
		
		void grab(Weapon *new_weapon);

		void grab(Bomb *bomb);

		void place(Bomb *bomb);

		void deactivate(Bomb *bomb);

		void removeSecondary();

		void take(unsigned int money);


		Team getTeam();
*/
		/*acá habría que incluir la distancia entre jugadores*/
		//void attack(Character &enemy, Team my_team, uint16_t distance);
		~Character();
	private:
		Character(const Character &other) = delete;
		Character& operator=(const Character &other) = delete;

};

#endif
