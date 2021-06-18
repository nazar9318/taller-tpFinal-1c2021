#include "GameWorldFactory.h"


GameWorld* GameWorldFactory::create(GameWorldType type) {
	switch (type) {
		case DEFAULT:
			return new GameWorld();
		default:
			throw Exception("Packet Factory Error");
	}
}