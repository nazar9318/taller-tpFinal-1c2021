#ifndef _CLIENT_PLAYER_H
#define _CLIENT_PLAYER_H

#define LIMIT_POSES 3
#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 32

#include <string>
#include "Texture.h"
#include "Team.h"
#include "SpriteContainer.h"
#include "Camera.h"
#include "Renderer.h"
#include "SoundHandler.h"
#include "Stencil.h"

class ClientPlayer {
	private:
		char& id;
		std::string name;
		std::string team;
		Texture* texture;
		Texture* texture_weapon;
		Texture stencil;
		SDL_Rect pos;
		SDL_Rect clip[3];
		int current_clip;
		int angle;
		int money;
		char life;
		char weapon_type;
		bool bomb_owner = false;

	public:
		ClientPlayer(char& id, std::string& name);

		ClientPlayer();

		~ClientPlayer();

		void createStencil(Renderer& renderer, double angle, int alpha);

		char get_id();

		void changeClip();

		void set_team(Team team);

		void set_weapon();

		void change_bomb_ownership(bool is_owner);

		bool has_bomb();

		Texture& getTexture();

		Texture& getWeapon();

		SDL_Rect& getBox();

		SDL_Rect& getClip();

		std::string getTeam();

		double getAngle();

		void update_position(int pos_x, int pos_y, int angle,
				char life, int money, char weapon_type, int ammo);

		void playWeaponSound();

		void render(Camera& camera);
		std::string get_name();

	private:
		ClientPlayer(const ClientPlayer &other) = delete;
		ClientPlayer& operator=(const ClientPlayer &other) = delete;
};

#endif
