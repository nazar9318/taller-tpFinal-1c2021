#ifndef _GAME_MAP_H
#define _GAME_MAP_H

#include <string>
#include <vector>
#include "Event.h"

#include "TileContainer.h"
#include "SpriteContainer.h"
#include "ClientPlayer.h"
#include "Tile.h"
 #include "WeaponSprite.h"    //VER SI HAGO WEAPON Y CHARACTER COMO UNA UNICA CLASE SPRITE

class GameMap {
	private:
		Renderer& renderer;

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
		GameMap(Renderer& renderer);
		void create();
		void setSize(int& width, int& height);

		void addTile(Tile tile);
		void addWeapon(WeaponSprite tile);
		void cleanWeapons();
		void loadMedia();

		/*------------Metodos para render--------------*/
		void setRenderArea();

		void renderGround();
		void renderWeapons();
		~GameMap();

	private:
		GameMap(const GameMap &other) = delete;
		GameMap& operator=(const GameMap &other) = delete;
};


#endif
