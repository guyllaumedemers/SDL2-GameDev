#pragma once
#include <SDL.h>
#include "Tile.h"

class TileBuilder
{
protected:

	Tile* m_Tile = nullptr;

public:

	virtual void buildTile() = 0;

	virtual void buildGraphic(SDL_Renderer* ren) = 0;

	Tile* getTile() { return m_Tile; }
};

