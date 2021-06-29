#include "SendStepInfoEvent.h"

SendStepInfoEvent::SendStepInfoEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::STEP_INFO);
	char type = step.get_type();
	this->msg.push_back(type);
	//this->msg.push_back(step.get_number_players());
	if (type == FaseType::PLAYING) {
		/*
		std::vector<char> players_info = step.get_players_info();
		std::vector<char> attacks_info = step.get_attacks_info();
		std::vector<char> ground_info = step.get_ground_info();
		*/
	} else if (type == FaseType::INITIAL_FASE) {
		//std::vector
	} else if (type == FaseType::END_ROUND) {

	} else {
		throw Exception("[%s:%i]: Se recibe un step sin fase valida"
					 	, __FILE__, __LINE__);
	}
}

SendStepInfoEvent::~SendStepInfoEvent() {}
