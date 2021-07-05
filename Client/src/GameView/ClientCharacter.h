#ifndef _CLIENT_CHARACTER_H
#define _CLIENT_CHARACTER_H
#define LIMIT_POSES 3

#include <string>
#include <SDL2/SDL.h>
#include "SpriteContainer.h"
#include "Team.h"

class ClientCharacter {
	private:
		std::string name;
		char type;
		Texture* texture;
		Texture* texture_weapon;
		SDL_Rect pos;
		SDL_Rect clip[3];
		int angle;
		int current_clip;

	public:
		ClientCharacter(const std::string& name);
		~ClientCharacter();
		SDL_Rect& getClip();
		SDL_Rect& getBox();
		char getType();
		Texture& getTexture();
		double getAngle();
		void set_team(Team team);
		void update_position(int pos_x, int pos_y, int angle, char weapon_type);

		ClientCharacter(ClientCharacter&& other) = default;
		ClientCharacter& operator=(ClientCharacter&& other) = default;

	private:
		ClientCharacter(const ClientCharacter &other) = delete;
		ClientCharacter& operator=(const ClientCharacter &other) = delete;
};

#endif
