#pragma once
#include <SDL.h>
#include "TileBuilder.h"
#include "ImageLoader.h"

class EmptyTileBuilder : public TileBuilder
{
public:

	EmptyTileBuilder();

	~EmptyTileBuilder();

	void buildTile();

	void buildGraphic(SDL_Renderer* ren);
};

