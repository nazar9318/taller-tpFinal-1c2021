#include "SendUserNameEvent.h"



SendUserNameEvent::SendUserNameEvent(std::string user_name) {
	this->msg.push_back((char)ClientTypeEvent::USER_NAME);
	std::copy(user_name.begin(), user_name.end(), std::back_inserter(this->msg));
	this->msg.push_back('\0');
}
SendUserNameEvent::~SendUserNameEvent() {
}
