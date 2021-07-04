#include "ReciveStepHandler.h"

ReciveStepHandler::ReciveStepHandler(){}


void ReciveStepHandler::handle(FaseType& fase, Event& event, GameMap& map){

  std::vector<char> event_msg = event.get_msg();

  fase = (FaseType)event_msg[1];

  if(fase == FaseType::INITIAL_FASE)
    handle_initial_fase(event_msg, map);

  if(fase == FaseType::PLAYING)
    handle_playing_fase(event_msg,map);

  if(fase == FaseType::END_ROUND)
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



void ReciveStepHandler::
handle_playing_fase(std::vector<char>& event_msg, GameMap& map) {
	for (auto it = event_msg.begin() + 2; it != event_msg.end(); it += 18) {
		char id = *it;
		int pos_x = *((int*)&(*(it + 1)));
		int pos_y = *((int*)&(*(it + 5)));
    int angle = *((int*)&(*(it + 9)));
    char life = *(it + 13);
    int money = *((int*)&(*(it + 14)));
		map.update_position(id, pos_x, pos_y, angle, life, money);
	}
}

void ReciveStepHandler::handle_end_round_fase(std::vector<char>& event_msg, GameMap& map){}

ReciveStepHandler::~ReciveStepHandler(){}
