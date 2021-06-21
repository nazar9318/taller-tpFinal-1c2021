#include "SendPlayersInfoEvent.h"

SendPlayersInfoEvent::SendPlayersInfoEvent(std::vector<char> players_info) {
	this->msg.push_back((char)ModelTypeEvent::PLAYERS_INFO);
	this->msg.insert(this->msg.end(), 
		std::make_move_iterator(players_info.begin()),
		std::make_move_iterator(players_info.end()));
}

SendPlayersInfoEvent::~SendPlayersInfoEvent() {}
