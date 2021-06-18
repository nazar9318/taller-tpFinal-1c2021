#include "EventHandlerFactory.h"

std::unique_ptr<ClientEventHandler> EventHandlerFactory::create(ClientEvent& event) {
	switch (event.get_type()) {
		case TypeOfEvent::MOVE:
			return std::unique_ptr<ClientEventHandler> (new MoveHandler(event.to_string(), event.get_id()));
			// return new MoveHandler(event.to_string(), event.get_id());
		case TypeOfEvent::START_GAME:
			return std::unique_ptr<ClientEventHandler> (new StartGameHandler(event.to_string(), event.get_id()));
			// return new StartGameHandler(event.to_string(), event.get_id());
		default:
			throw Exception("Event Handler Factory Error");
	}
}
