#include "PlayerInformation.h"


PlayerInformation::PlayerInformation(std::string usr_name):
			 name(usr_name), is_self(false) {
}

PlayerInformation::PlayerInformation(std::string usr_name, bool this_usr):
			 name(usr_name), is_self(this_usr) {
}
/*
PlayerInformation::PlayerInformation(PlayerInformation&&)

PlayerInformation::PlayerInformation& operator = (PlayerInformation&&) = default;
*/

PlayerInformation::~PlayerInformation() {
}
