#pragma once
#include "TileBuilder.h"

class EmptyTileBuilder : public TileBuilder
{
private:

	SDL_Texture* m_Texture = nullptr;

public:

	EmptyTileBuilder(SDL_Texture* texture);

	~EmptyTileBuilder();

	Tile buildTile(int x, int y) override;

	void buildGraphic(Tile& tile) override;
};

