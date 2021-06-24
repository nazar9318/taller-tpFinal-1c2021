#include "EntrySuccessfulEvent.h"


EntrySuccessfulEvent::EntrySuccessfulEvent(char self_id) {
	this->msg.push_back(ModelTypeEvent::SUCCESSFUL_ENTRY);
	this->msg.push_back(self_id);
}

EntrySuccessfulEvent::~EntrySuccessfulEvent() {
}