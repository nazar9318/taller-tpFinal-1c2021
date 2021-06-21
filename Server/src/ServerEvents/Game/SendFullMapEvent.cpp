#include "SendFullMapEvent.h"

SendFullMapEvent::SendFullMapEvent(std::vector<char> map_info) {
	this->msg.push_back((char)ModelTypeEvent::SEND_FULL_MAP);
	this->msg.insert(this->msg.end(), 
		std::make_move_iterator(map_info.begin()),
		std::make_move_iterator(map_info.end()));
}

SendFullMapEvent::~SendFullMapEvent() {}
