#pragma once
#include "TileBuilder.h"

class EmptyTileBuilder : public TileBuilder
{
public:

	EmptyTileBuilder(SDL_Texture* texture);

	void buildTile(int x, int y) override;
};

