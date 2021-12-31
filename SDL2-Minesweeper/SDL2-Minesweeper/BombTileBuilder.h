#pragma once
#include "TileBuilder.h"

class BombTileBuilder : public TileBuilder
{
public:

	BombTileBuilder();

	~BombTileBuilder();

	void buildTile(int x, int y) override;
};

