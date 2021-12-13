#pragma once
#include "TileBuilder.h"
#include "ImageLoader.h"

class BombTileBuilder : TileBuilder
{
public:

	BombTileBuilder();

	~BombTileBuilder();

	void buildTile(int x, int y) override;

	void buildGraphic(SDL_Window* window, SDL_Renderer* ren) override;
};

