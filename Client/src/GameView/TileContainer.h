#ifndef _TILE_CONTAINER_H
#define _TILE_CONTAINER_H

#include <syslog.h>
#include <map>
#include <string>
#include "Renderer.h"
#include "Texture.h"
#include "TypesOfEvents.h"
#include "Exception.h"

class TileContainer {
	private:
		Renderer& renderer;
		std::map<char, Texture> container;

	public:
		TileContainer(Renderer& renderer);

		/* Carga las texturas de los tiles */
		void loadMedia();

		/* Obtiene la textura correspondiente */
		Texture& operator[](const char id);

		~TileContainer();

	private:
		TileContainer(const TileContainer &other) = delete;
		TileContainer& operator=(const TileContainer &other) = delete;
		TileContainer(TileContainer&& other) = delete;
		TileContainer& operator=(TileContainer&& other) = delete;
};


#endif
