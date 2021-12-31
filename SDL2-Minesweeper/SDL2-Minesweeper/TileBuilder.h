#pragma once
#include <SDL.h>
#include "Tile.h"

class TileBuilder
{
protected:

	Tile* m_Tile = nullptr;

	SDL_Texture* m_Texture = nullptr;

public:

	virtual ~TileBuilder() {
		// dont delete the reference the pointer is targeting otherwise the map will 
		m_Tile = nullptr;
		delete m_Tile;
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	};

	virtual void buildTile(int x, int y) = 0;

	virtual void buildGraphic(SDL_Window* window, SDL_Renderer* ren) = 0;

	Tile* getTile() { return m_Tile; }
};

