#ifndef _WEAPON_FACTORY_H
#define _WEAPON_FACTORY_H

#include "TypesOfEvents.h"
#include "Exception.h"
#include "Weapon.h"
#include "WeaponAutomatic.h"
#include "WeaponPistol.h"
#include "WeaponShotgun.h"
#include "WeaponSniper.h"
#include "WeaponWhite.h"

class WeaponFactory {
	public:
		static Weapon* create(char type);

	private:
		WeaponFactory(const WeaponFactory &other) = delete;
		WeaponFactory& operator=(const WeaponFactory &other) = delete;
};



#endif

