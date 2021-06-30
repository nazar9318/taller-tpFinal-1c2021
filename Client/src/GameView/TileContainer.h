#ifndef _TILE_CONTAINER_H
#define _TILE_CONTAINER_H

#include <syslog.h>
#include <map>
#include <string>
#include <memory>
#include "Renderer.h"
#include "Texture.h"
#include "TypesOfEvents.h"
#include "Exception.h"

class TileContainer {
	private:
		std::map<char, Texture> container;

	public:

		/* Carga las texturas de los tiles */
		void loadMedia(Renderer& renderer);

		static TileContainer& getInstance();

		/* Obtiene la textura correspondiente */
		Texture& operator[](char id);
		~TileContainer();

	private:
		TileContainer();
		static std::unique_ptr<TileContainer> instance;

		TileContainer(const TileContainer &other) = delete;
		TileContainer& operator=(const TileContainer &other) = delete;
		TileContainer(TileContainer&& other) = delete;
		TileContainer& operator=(TileContainer&& other) = delete;
};

#endif
