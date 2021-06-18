#ifndef _CLIENT_EVENT_HANDLER_H
#define _CLIENT_EVENT_HANDLER_H

#include <vector>

class ClientEventHandler{
	public:
		ClientEventHandler(); //Ver si recibimos referencias o no

    virtual void handle() = 0; //Lo implementan si o si las clases hijas

		~ClientEventHandler();

	private:
		ClientEventHandler(const ClientEventHandler &other) = delete;
		ClientEventHandler& operator=(const ClientEventHandler &other) = delete;
};

#endif
