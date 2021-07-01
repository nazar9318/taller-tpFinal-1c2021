#include "Character.h"
#include "StepInformation.h"

StepInformation::
StepInformation(std::map<char,Character>& players):
						characters(players) {
}

void StepInformation::clear() {
	//
}

void StepInformation::set_type(FaseType fase_type) {
	fase = fase_type;
}

FaseType StepInformation::get_type() {
	return fase;
}

void StepInformation::set_waiting_time(int wait) {
	waiting_time = wait;
}

int StepInformation::get_waiting_time() {
	return waiting_time;
}

void StepInformation::add_position(char id, int x, int y) {
	std::pair<int, int> pos(x, y * (-1));
	positions[id] = pos;
}


std::vector<char> StepInformation::get_players_info() {
	std::vector<char> players_info;
	for (auto it = characters.begin(); it != characters.end(); ++it) {
		players_info.push_back(it->first); // ID
		b2Vec2 pos = it->second.get_pos();
		
		int x = (int)pos.x; // POS_X 
		players_info.push_back(*((char*)(&x)));
		players_info.push_back(*((char*)(&x) + 1));
		players_info.push_back(*((char*)(&x) + 2));
		players_info.push_back(*((char*)(&x) + 3)); 

		int y = (int)pos.y * (-1); // POS_Y
		players_info.push_back(*((char*)(&y)));
		players_info.push_back(*((char*)(&y) + 1));
		players_info.push_back(*((char*)(&y) + 2));
		players_info.push_back(*((char*)(&y) + 3)); 

		
	}	

	return players_info;
}



StepInformation::~StepInformation() {
}



