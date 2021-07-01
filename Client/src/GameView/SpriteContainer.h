#ifndef _SPRITE_CONTAINER_H
#define _SPRITE_CONTAINER_H

#include <syslog.h>
#include <map>
#include <string>
#include <memory>
#include "Renderer.h"
#include "Texture.h"
#include "TypesOfEvents.h"
#include "Exception.h"
#include "Team.h"

class SpriteContainer {
	private:
		std::map<char, Texture> container;

	public:
		/* Carga las texturas de los sprites */
		void loadMedia(Renderer& renderer);

		static SpriteContainer& getInstance();

		/* Obtiene la textura correspondiente */
		Texture& operator[](char id);
		
		~SpriteContainer();

	private:
		SpriteContainer();
		static std::unique_ptr<SpriteContainer> instance;

		SpriteContainer(const SpriteContainer &other) = delete;
		SpriteContainer& operator=(const SpriteContainer &other) = delete;
		SpriteContainer(SpriteContainer&& other) = delete;
		SpriteContainer& operator=(SpriteContainer&& other) = delete;
};

#endif
