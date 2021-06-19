#include "EventHandlerFactory.h"

std::unique_ptr<ClientEventHandler> EventHandlerFactory::create(Event& event) {
	switch (event.get_type()) {
		case TypeOfEvent::MOVE:
			return std::unique_ptr<ClientEventHandler> (new MoveHandler(event.get_msg(), event.get_id()));
		case TypeOfEvent::START_GAME:
			return std::unique_ptr<ClientEventHandler> (new StartGameHandler(event.get_msg(), event.get_id()));
		default:
			throw Exception("Event Handler Factory Error");
	}
}
