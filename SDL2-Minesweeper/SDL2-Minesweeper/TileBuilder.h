#pragma once
#include <SDL.h>
#include <iostream>
#include "Tile.h"

class TileBuilder
{
protected:

	Tile* m_Tile = nullptr;

	SDL_Texture* m_Texture = nullptr;

public:

	virtual ~TileBuilder() {
		delete m_Tile;
		m_Tile = nullptr;
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	};

	virtual void buildTile(int x, int y) = 0;

	virtual void buildGraphic(SDL_Window* window, SDL_Renderer* ren) = 0;

	Tile* getTile() { return m_Tile; }
};

