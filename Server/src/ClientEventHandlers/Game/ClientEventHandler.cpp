#include "ClientEventHandler.h"

ClientEventHandler::
	ClientEventHandler(GameWorld& game_world): world(game_world) {
}

void ClientEventHandler::handle(Event& event) {
	switch(event.get_type()) {
		case ClientTypeEvent::MOVE:
			{
				mover.handle(event, world);
				break;
			}
		case ClientTypeEvent::START_ATTACKING:
			{
				attacker.handle(event, world);
				break;
			} 
		case ClientTypeEvent::GRAB_WEAPON:
			{
				graber.handle(event, world);
				break;
			}
		case ClientTypeEvent::DROP_WEAPON:
			{
				droper.handle(event, world);
				break;
			}
		case ClientTypeEvent::EXCHANGE_WEAPON:
			{
				exchanger.handle(event, world);
				break;
			}
		case ClientTypeEvent::BUY_ARMOUR:
			{
				buyier.handle(event, world);
				break;
			}
		case ClientTypeEvent::QUIT_GAME:
			{
				quiter.handle(event, world);
				break;
			}	
		default:
			{
				throw Exception("No one matches");
			}
	}
} 


ClientEventHandler::~ClientEventHandler() {}