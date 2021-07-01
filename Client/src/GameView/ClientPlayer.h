#ifndef _CLIENT_PLAYER_H
#define _CLIENT_PLAYER_H

#include <string>

class ClientPlayer {
	private:
		char& id;
		std::string& name;

	public:
		ClientPlayer(char& id, std::string& name);
		ClientPlayer();
		~ClientPlayer();

	private:
		ClientPlayer(const ClientPlayer &other) = delete;
		ClientPlayer& operator=(const ClientPlayer &other) = delete;
};

#endif
