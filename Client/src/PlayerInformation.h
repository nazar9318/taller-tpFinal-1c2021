#ifndef _PLAYER_INFORMATION_H
#define _PLAYER_INFORMATION_H

#include <string>


class PlayerInformation {
	bool is_self;
	std::string name;
	public:
		PlayerInformation(): is_self(false) {}
		PlayerInformation(std::string name);
		PlayerInformation(std::string name, bool is_self);
		~PlayerInformation();
		//PlayerInformation(PlayerInformation&&);

		//PlayerInformation& operator = (PlayerInformation&&);

	private:
		//PlayerInformation(const PlayerInformation &other) = delete;
		//PlayerInformation& operator=(const PlayerInformation &other) = delete;
};

#endif
