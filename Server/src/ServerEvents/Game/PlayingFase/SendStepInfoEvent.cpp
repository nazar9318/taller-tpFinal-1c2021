/*
#include "SendStepInfoEvent.h"
#include <syslog.h>

SendStepInfoEvent::SendStepInfoEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::STEP_INFO);


	char type = step.get_type();
	this->msg.push_back(type);
	//this->msg.push_back(step.get_number_players());
	if (type == FaseType::PLAYING) {
		std::vector<char> players_info = step.get_players_info();
		std::copy(players_info.begin(),
				 players_info.end(), std::back_inserter(this->msg));

		// std::vector<char> attacks_info = step.get_attacks();
		// std::copy(attacks_info.begin(), attacks_info.end(), std::back_inserter(this->msg));
		*//*std::vector<char> ground_info = step.get_ground_info();
		*/
	/*} else if (type == FaseType::INITIAL_FASE) {
		int wait = step.get_wait();
		push_back(wait);
		if (wait <= 0) {
			// ID(char), counter / anticounter;
			std::vector<char> v = step.get_players_init();
			std::copy(v.begin(), v.end(), std::back_inserter(msg));
		}
		//std::vector<char> players_info = step.get_players_info();
		// id_player(char), pos_x(int), pos_y(int), life(char),
		// std::map<id, player*>
		//std::vector<char> attacks_info = step.get_buying_things_info();


		//std::vector
	} else if (type == FaseType::END_ROUND) {

	} else {
		throw Exception("[%s:%i]: Se recibe un step sin fase valida"
					 	, __FILE__, __LINE__);
	}
}

SendStepInfoEvent::~SendStepInfoEvent() {}
*/