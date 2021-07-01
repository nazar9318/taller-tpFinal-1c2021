#include "ReciveStepHandler.h"

ReciveStepHandler::ReciveStepHandler(){}


void ReciveStepHandler::handle(Event& event, GameMap& map){

  std::vector<char> event_msg = event.get_msg();

  char fase_type = event_msg[1];

  if(fase_type == FaseType::INITIAL_FASE)
    handle_initial_fase(event_msg, map);

  if(fase_type == FaseType::PLAYING)
    handle_playing_fase(event_msg,map);

  if(fase_type == FaseType::END_ROUND)
    handle_end_round_fase(event_msg, map);
}

void ReciveStepHandler::
		handle_initial_fase(std::vector<char>& event_msg, GameMap& map) {
	
	int wait_time = *((int*)&(event_msg[2]));
	if (wait_time <= 0) {
		for (auto it = event_msg.begin() + 6; it != event_msg.end(); it += 2) {
			char id = *it;
			Team team = (Team)*(it + 1);
			map.add_character_team(id, team);
		}
	} else {
		for (auto it = event_msg.begin() + 6; it != event_msg.end(); it += 2) {
			// leer compras. 
		}
	}



}

void ReciveStepHandler::handle_playing_fase(std::vector<char>& event_msg, GameMap& map){



}

void ReciveStepHandler::handle_end_round_fase(std::vector<char>& event_msg, GameMap& map){}

ReciveStepHandler::~ReciveStepHandler(){}
