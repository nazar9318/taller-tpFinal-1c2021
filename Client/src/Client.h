#ifndef _CLIENT_H
#define _CLIENT_H

#include <string>
#include <iostream>
#include "BlockingQueue.h"

class Client {
	public:
		Client(const std::string& host, const std::string& port);
		
		// POST: Executes the Counter Strike game.  
		void execute();

		~Client();

	private:
		// POST: Initializes the game. 
		//       Returns true if the player made a 
		//       successfull login. 
		bool execute_lobby();
		
		// POST: Executes the Counter Strike game. 
		void execute_game();

		Client(const Client &other) = delete;
		Client& operator=(const Client &other) = delete;
};


#endif

