#include "WeaponFactory.h"

Weapon* WeaponFactory::create(char type) {
	switch (type) {
		case PositionType::KNIFE:
			return new WeaponWhite();
		case PositionType::GLOCK:
			return new WeaponPistol();
		case PositionType::AK47:
			return new WeaponAutomatic();
		case PositionType::M3:
			return new WeaponShotgun();
		case PositionType::AWP:
			return new WeaponSniper();
		default:
			throw Exception("Ningun tipo de weapon es valida");
	}
}
