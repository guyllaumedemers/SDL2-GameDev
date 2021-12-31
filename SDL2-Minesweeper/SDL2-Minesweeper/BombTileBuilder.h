#pragma once
#include "TileBuilder.h"

class BombTileBuilder : public TileBuilder
{
public:

	BombTileBuilder(SDL_Texture* texture);

	void buildTile(int x, int y) override;
};

