#ifndef _CLIENT_PLAYER_H
#define _CLIENT_PLAYER_H
#define LIMIT_POSES 3

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
		SDL_Rect clip[3];
		int current_clip;
		int angle;
		int money;
		char life;

	public:
		ClientPlayer(char& id, std::string& name);
		ClientPlayer();
		~ClientPlayer();
		char get_id();
		void changeClip();
		void set_team(Team team);
		Texture& getTexture();
		SDL_Rect& getBox();
		SDL_Rect& getClip();
		double getAngle();
		void update_position(int pos_x, int pos_y, int angle, char life, int money);
		void render(Renderer& renderer);
	private:
		ClientPlayer(const ClientPlayer &other) = delete;
		ClientPlayer& operator=(const ClientPlayer &other) = delete;
};

#endif
