#ifndef _GAME_MAP_H
#define _GAME_MAP_H

class ClientPlayer;

#include <string>
#include <vector>
#include "Event.h"

#include "TileContainer.h"
#include "SpriteContainer.h"
#include "ClientPlayer.h"
#include "ClientCharacter.h"
#include "Hud.h"
#include "Tile.h"
#include "WeaponSprite.h"    //VER SI HAGO WEAPON Y CHARACTER COMO UNA UNICA CLASE SPRITE
#include "Team.h"
#include "Camera.h"
#include "FinalPhase.h"

#include "BombState.h"

class GameMap {
	private:
		Renderer& renderer;
		Camera& camera;
		Hud& hud;
		FinalPhase& final_phase;

		/*Contenedores*/
		TileContainer& tile_container;
		SpriteContainer& sprite_container;

		/*Entidades*/
		std::vector<Tile> tiles;
		std::vector<WeaponSprite> weapons;
		ClientPlayer& player;
		std::map<char, ClientCharacter> &characters;

		int map_width;
		int map_height;

		// Area a renderizar
		int x_min = 0, x_max = 0, y_min = 0, y_max = 0;

	public:
		GameMap(Renderer& renderer, ClientPlayer& player, Camera& camera, std::map<char,
			 			ClientCharacter> &characters, Hud& hud, FinalPhase& final_phase);
		void create();
		void setSize(int& width, int& height);
		float distance(char id);
		void addTile(Tile tile);
		void addWeapon(WeaponSprite tile);
		void cleanWeapons();
		void loadMedia();
		void update_position(char id, int pos_x, int pos_y, int angle, char life, int money, char weapon_type, int ammo);
		void updateTimeToExplode(int time);
		/*------------Metodos para render--------------*/
		void setRenderArea();
		void renderCharacters();
		void renderPlayer();
		void renderGround();
		void renderWeapons();
		void add_character_team(char id, Team team);
		void add_stats(char id, int kills_round, int kills_total);
		void activate_bomb(char id_owner, char percentage);
		~GameMap();

	private:
		GameMap(const GameMap &other) = delete;
		GameMap& operator=(const GameMap &other) = delete;
};

#endif
