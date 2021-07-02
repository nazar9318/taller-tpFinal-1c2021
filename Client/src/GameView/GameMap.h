#ifndef _GAME_MAP_H
#define _GAME_MAP_H

#include <string>
#include <vector>
#include "Event.h"

#include "TileContainer.h"
#include "SpriteContainer.h"
#include "ClientPlayer.h"
#include "ClientCharacter.h"
#include "Tile.h"
#include "WeaponSprite.h"    //VER SI HAGO WEAPON Y CHARACTER COMO UNA UNICA CLASE SPRITE
#include "Team.h"

class GameMap {
	private:
		Renderer& renderer;
		ClientPlayer& player;
		std::map<char, ClientCharacter> &characters;

		/*Contenedores*/
		TileContainer& tile_container;
		SpriteContainer& sprite_container;

		/*Entidades*/
		std::vector<Tile> tiles;
		std::vector<WeaponSprite> weapons;
		// std::vector<Character> weapons;

		int map_width;
		int map_height;

		// Area a renderizar
		int x_min = 0, x_max = 0, y_min = 0, y_max = 0;

	public:
		GameMap(Renderer& renderer, ClientPlayer& player, std::map<char, ClientCharacter> &characters);
		void create();
		void setSize(int& width, int& height);

		void addTile(Tile tile);
		void addWeapon(WeaponSprite tile);
		void cleanWeapons();
		void loadMedia();
		void update_position(char id, int pos_x, int pos_y, int angle);
		/*------------Metodos para render--------------*/
		void setRenderArea();
		void renderCharacters();
		void renderPlayer();
		void renderGround();
		void renderWeapons();
		void add_character_team(char id, Team team);
		~GameMap();

	private:
		GameMap(const GameMap &other) = delete;
		GameMap& operator=(const GameMap &other) = delete;
};


#endif
