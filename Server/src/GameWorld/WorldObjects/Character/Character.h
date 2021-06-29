#ifndef CHARACTER_H
#define CHARACTER_H

#include "Position.h"
#include "Weapon.h"
#include "WeaponBomb.h"
#include "WeaponWhite.h"
#include "WeaponPistol.h"
#include "WeaponShotgun.h"
#include "WeaponAutomatic.h"
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

class Weapon;
class WeaponWhite;
class WeaponShotgun;
class WeaponPistol;
class WeaponSniper;
class WeaponAutomatic;

class Character {
	private:
		double life_points;
		double money;
		Team team;
		std::vector<Weapon*> weapons;
		Weapon* current_weapon;
		b2Body* character_body;
		Direction move_state;

	public:
		static float body_radius;
		Character(Team team, b2World* world,
			 std::vector<Position*> available_positions);
		
		Character(Character&&) = default;

		Character& operator = (Character&&) = default;

		void add_body(char x, char y, b2World* world);

		void set_move_state(Direction dir);

		void apply_impulses();

		void start_attacking();


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



		void takeDamage(double points);

		void changeCurrentWeapon(uint16_t pos);

		void buy(Weapon *new_weapon);
		
		void grab(Weapon *new_weapon);

		void grab(Bomb *bomb);

		void place(Bomb *bomb);

		void deactivate(Bomb *bomb);

		void removeSecondary();

		void take(uint16_t money);

		double getLifePoints();

		Team getTeam();

		/*acá habría que incluir la distancia entre jugadores*/
		//void attack(Character &enemy, Team my_team, uint16_t distance);
		void attack(std::list<Block>& blocks,
			 std::map<char, Character>& characters, StepInformation& step_info);
		~Character();
	private:
		Character(const Character &other) = delete;
		Character& operator=(const Character &other) = delete;

};

#endif
