#include "ReceiveBombStateHandler.h"

#define HAS_OWNER true
#define HAS_NOT_OWNER false
#define NO_OWNER -1
#define NO_X_POS -1
#define NO_Y_POS -1

ReceiveBombStateHandler::ReceiveBombStateHandler(){}


void ReceiveBombStateHandler::handle(FaseType& fase, Event& event, GameMap& map, ClientBomb& bomb){
	fase = FaseType::PLAYING;
	map.updateTimeToExplode(-1);

	std::vector<char> event_msg = event.get_msg();
	BombState state = (BombState)event_msg[1];

	if (state == BombState::NORMAL) {
		bool has_owner = (bool)event_msg[2];
		if (has_owner) {
			char id_owner = event_msg[3];
			bomb.set_normal_state(HAS_OWNER, id_owner, NO_X_POS, NO_Y_POS);
		} else {
			int x = *((int*)&(event_msg[3]));
			int y = *((int*)&(event_msg[7]));
			bomb.set_normal_state(HAS_NOT_OWNER, NO_OWNER, x, y);
		}
	} else if (state == BombState::ACTIVATING) {
		char id_owner = event_msg[2];
		char percentage = event_msg[3];
		bomb.set_activating_state(id_owner, (int)percentage);
	} else if (state == BombState::ACTIVATED) {
		char id_owner = event_msg[2];
		char time_until_explote = event_msg[3];
		int x = *((int*)&(event_msg[4]));
		int y = *((int*)&(event_msg[8]));
		map.updateTimeToExplode((int)time_until_explote);
		bomb.set_activated_state(id_owner, x, y, (int)time_until_explote);
	} else if (state == BombState::DEACTIVATING) {
		char id_owner = event_msg[2];
		char percentage = event_msg[3];
		char time_until_explote = event_msg[4];
		bomb.set_deactivating_state(id_owner, (int)percentage);
		map.updateTimeToExplode((int)time_until_explote);

	}
}


ReceiveBombStateHandler::~ReceiveBombStateHandler(){}
