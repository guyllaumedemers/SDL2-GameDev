#pragma once
#include "TileBuilder.h"
#include "ImageLoader.h"

class BombTileBuilder : TileBuilder
{
public:

	BombTileBuilder();

	~BombTileBuilder();

	void buildTile();

	void buildGraphic(SDL_Renderer* ren);
};

