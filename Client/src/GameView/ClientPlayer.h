#ifndef _CLIENT_PLAYER_H
#define _CLIENT_PLAYER_H

#include <string>
#include "Texture.h"
#include "Team.h"
#include "SpriteContainer.h"

class ClientPlayer {
	private:
		char& id;
		std::string& name;
		Texture* texture;

	public:
		ClientPlayer(char& id, std::string& name);
		ClientPlayer();
		~ClientPlayer();
		char get_id();
		void set_team(Team team);
		Texture& getTexture();
		SDL_Rect getBox();

	private:
		ClientPlayer(const ClientPlayer &other) = delete;
		ClientPlayer& operator=(const ClientPlayer &other) = delete;
};

#endif
