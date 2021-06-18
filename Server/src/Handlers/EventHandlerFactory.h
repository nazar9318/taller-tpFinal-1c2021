#ifndef EVENT_HANDLER_FACTORY_H
#define EVENT_HANDLER_FACTORY_H

#include "TypesOfEvents.h"
#include "ClientEvent.h"
#include "ClientEventHandler.h"
#include "Exception.h"

#include "MoveHandler.h"
#include "StartGameHandler.h"

#include <memory>

class EventHandlerFactory {
	public:
		EventHandlerFactory() = delete;
		~EventHandlerFactory() = delete;
		static std::unique_ptr<ClientEventHandler> create(ClientEvent& event);
};

#endif
