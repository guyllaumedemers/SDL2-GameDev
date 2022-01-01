#pragma once
#include "TileBuilder.h"

class BombTileBuilder : public TileBuilder
{
private:

	SDL_Texture* m_Texture = nullptr;

public:

	BombTileBuilder(SDL_Texture* texture);

	~BombTileBuilder();

	Tile buildTile(int x, int y) override;

	void buildGraphic(Tile& tile) override;
};

