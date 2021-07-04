#ifndef _CLIENT_CHARACTER_H
#define _CLIENT_CHARACTER_H

#include <string>
#include <SDL2/SDL.h>
#include "SpriteContainer.h"
#include "Team.h"

class ClientCharacter {
	private:
		std::string name;
		char type;
		Texture* texture;
		SDL_Rect pos;
		int angle;

	public:
		ClientCharacter(const std::string& name);
		~ClientCharacter();

		SDL_Rect& getBox();
		char getType();
		Texture& getTexture();
		void set_team(Team team);
		void update_position(int pos_x, int pos_y, int angle);

		ClientCharacter(ClientCharacter&& other) = default;
		ClientCharacter& operator=(ClientCharacter&& other) = default;

	private:
		ClientCharacter(const ClientCharacter &other) = delete;
		ClientCharacter& operator=(const ClientCharacter &other) = delete;
};

#endif
