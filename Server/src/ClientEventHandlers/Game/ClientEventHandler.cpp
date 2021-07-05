#include "ClientEventHandler.h"

ClientEventHandler::
	ClientEventHandler(GameWorld& game_world): world(game_world) {
}

void ClientEventHandler::handle(Event& event) {
	switch(event.get_type()) {
		case ClientTypeEvent::ROTATE:
			{
				rotator.handle(event, world);
				break;
			}
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
		case ClientTypeEvent::CHANGE_WEAPON:
			{
				changer.handle(event, world);
				break;
			}
		case ClientTypeEvent::BUY_WEAPON:
			{
				buyier.handle(event, world);
				break;
			}
		case ClientTypeEvent::STOP_ATTACKING:
			{
				attack_stoper.handle(event, world);
				break;
			}
		case ClientTypeEvent::START_PLANTING_BOMB:
			{
				bomb_activator.handle(event, world);
				break;
			}
		case ClientTypeEvent::STOP_PLANTING_BOMB:
			{
				attack_stoper.handle(event, world);
				break;
			}
		case ClientTypeEvent::START_DEACTIVATING_BOMB:
			{
				bomb_deactivator.handle(event, world);
				break;
			}
		case ClientTypeEvent::STOP_DEACTIVATING_BOMB:
			{
				bomb_deactivator_stopper.handle(event, world);
				break;
			}
		default:
			{
				throw Exception("[%s:%i]:No hay ningun"
						" evento con esta caracteristica: %d", 
						__FILE__, __LINE__, (int)event.get_type());
			}
	}
}


ClientEventHandler::~ClientEventHandler() {}
