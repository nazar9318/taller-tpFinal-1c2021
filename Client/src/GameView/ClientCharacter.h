#ifndef _CLIENT_CHARACTER_H
#define _CLIENT_CHARACTER_H

#include <string>

class ClientCharacter {
	private:
		std::string name;

	public:
		ClientCharacter(const std::string& name);
		~ClientCharacter();

		ClientCharacter(ClientCharacter&& other) = default;
		ClientCharacter& operator=(ClientCharacter&& other) = default;

	private:
		ClientCharacter(const ClientCharacter &other) = delete;
		ClientCharacter& operator=(const ClientCharacter &other) = delete;
};


#endif
