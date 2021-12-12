#pragma once
#include <SDL.h>
#include "TileBuilder.h"
#include "ImageLoader.h"

class EmptyTileBuilder : TileBuilder
{
private:

	Tile* m_Tile = nullptr;

public:

	EmptyTileBuilder();

	~EmptyTileBuilder();

	virtual void buildTile();

	virtual void buildGraphic(SDL_Renderer* ren);

	virtual Tile* getTile();
};

