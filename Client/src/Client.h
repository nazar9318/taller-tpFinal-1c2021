#ifndef _CLIENT_H
#define _CLIENT_H

#include <string>
#include <iostream>

class Client {
	public:
		Client(const std::string& host, const std::string& port);
		
		
		void execute();

		~Client();

	private:
		Client(const Client &other) = delete;
		Client& operator=(const Client &other) = delete;
};


#endif

