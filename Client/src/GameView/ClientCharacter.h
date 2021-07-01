#ifndef _CLIENT_CHARACTER_H
#define _CLIENT_CHARACTER_H

#include <string>
#include <SDL2/SDL.h>
#include "SpriteContainer.h"

class ClientCharacter {
	private:
		std::string name;
		SDL_Rect box;
		char type;
		//Texture& texture;

	public:
		ClientCharacter(const std::string& name);
		~ClientCharacter();

		SDL_Rect& getBox();
		char getType();
		Texture& getTexture();

		ClientCharacter(ClientCharacter&& other) = default;
		ClientCharacter& operator=(ClientCharacter&& other) = default;

	private:
		ClientCharacter(const ClientCharacter &other) = delete;
		ClientCharacter& operator=(const ClientCharacter &other) = delete;
};

#endif
