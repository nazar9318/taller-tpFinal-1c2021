#include "ModelEventHandler.h"

ModelEventHandler::ModelEventHandler() {}

void ModelEventHandler::handle(FaseType& fase, Event& event, GameMap& map, ClientBomb& bomb, AttackEffect& attack_effects) {
  switch (event.get_type()) {
    case ModelTypeEvent::SEND_FULL_MAP:
      recive_map.handle(event, map);
      break;
    case ModelTypeEvent::SEND_WEAPONS:
      recive_weapons.handle(event, map);
      break;
      /*case ModelTypeEvent::STEP_INFO:
      recive_step.handle(fase, event, map);
      break;*/
    case ModelTypeEvent::PLAYING_STEP:
      playing_step.handle(fase, event, map);
      //sound_handler.handleWalk();
      break;
    case ModelTypeEvent::INIT_STEP:
      init_step.handle(fase, event, map);
      break;
    case ModelTypeEvent::INITIAL_PLAYERS:
      player_init.handle(fase, event, map);
      break;
    case ModelTypeEvent::BOMB_INFO: {
      bomb_state.handle(fase, event, map, bomb);
      sound_handler.handleBomb(event);
      break;
    }
    case ModelTypeEvent::STATISTICS:
      stats.handle(fase, event, map);
      break;
    case ModelTypeEvent::SEND_SQUADS:
      squads_receiver.handle(event, map);
      break;
    case ModelTypeEvent::FINAL_STATE: {
      final_state_receiver.handle(fase, event, map, bomb);
      sound_handler.handleBomb(event);
      break;
    }
    case ModelTypeEvent::ATTACKS_INFO: {
      attacks_receiver.handle(fase, event, map, attack_effects);
      sound_handler.handleAttack(event);
      break;
    }
    case ModelTypeEvent::INITIAL_CONFIGS: {
      configs.handle(event, map);
      break;
    }

    
    default:
      break;
  }
}

ModelEventHandler::~ModelEventHandler() {}
