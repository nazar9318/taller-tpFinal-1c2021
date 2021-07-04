#include "ReciveWeaponHandler.h"

ReciveWeaponHandler::ReciveWeaponHandler(){}

void ReciveWeaponHandler::handle(Event& event, GameMap& map){
  //El msg tiene --> typo/psox/posy/block
  map.cleanWeapons();
  std::vector<char> event_msg = event.get_msg();

  char type;
  int x,y;

  for (size_t i = 1; i < event_msg.size(); i+=9) {
    x = *((int*)&(event_msg[i]));
    y = *((int*)&(event_msg[i+4]));
    type = event_msg[i+8];
    WeaponSprite weapon(x, y, type);
    map.addWeapon(std::move(weapon));
  }

}

ReciveWeaponHandler::~ReciveWeaponHandler(){}
