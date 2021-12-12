#pragma once
#include <SDL.h>
#include "Tile.h"

class TileBuilder
{
public:

	virtual void buildTile() {}

	virtual void buildGraphic(SDL_Renderer* ren) {}

	virtual Tile* GetTile() { return 0; }
};

