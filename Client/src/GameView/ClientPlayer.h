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
		SDL_Rect pos;
		int angle;
		int money;
		char life;
	public:
		ClientPlayer(char& id, std::string& name);
		ClientPlayer();
		~ClientPlayer();
		char get_id();
		void set_team(Team team);
		Texture& getTexture();
		SDL_Rect& getBox();
		double getAngle();
		void update_position(int pos_x, int pos_y, int angle, char life, int money);

		void render(Renderer& renderer, int cam_x, int cam_y);
	private:
		ClientPlayer(const ClientPlayer &other) = delete;
		ClientPlayer& operator=(const ClientPlayer &other) = delete;
};

#endif
