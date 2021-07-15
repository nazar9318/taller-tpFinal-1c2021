#include "ReceiveSquadsHandler.h"

ReceiveSquadsHandler::ReceiveSquadsHandler() {}

void ReceiveSquadsHandler::handle(Event& event, GameMap& map) {
	std::vector<char> msg = event.get_msg();
	for (auto it = msg.begin() + 1; it != msg.end(); ++it) {
		/*
		char id = *it;
		int squad = (int)*(it + 1); // puede ser 1 o 2.
		map.add_squad(id, squad);
		*/
	}
}

ReceiveSquadsHandler::~ReceiveSquadsHandler() {}
