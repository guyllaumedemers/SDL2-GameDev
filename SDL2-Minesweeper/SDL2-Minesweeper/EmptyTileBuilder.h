#pragma once
#include <SDL.h>
#include "TileBuilder.h"

class EmptyTileBuilder : public TileBuilder
{
public:

	EmptyTileBuilder();

	~EmptyTileBuilder();

	void buildTile(int x, int y) override;

	void buildGraphic(SDL_Window* window, SDL_Renderer* ren) override;
};

