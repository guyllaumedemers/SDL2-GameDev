#include "BombTileBuilder.h"

BombTileBuilder::BombTileBuilder(SDL_Texture* texture)
{
	m_Texture = texture;
}

BombTileBuilder::~BombTileBuilder()
{
	m_Texture = nullptr;
}

Tile BombTileBuilder::buildTile(int x, int y)
{
	return Tile(
		nullptr,
		TileBitMask::Covered | TileBitMask::Bomb,
		x,
		y
	);
}

void BombTileBuilder::buildGraphic(Tile& tile)
{
	if (m_Texture != nullptr) {
		tile.setGraphics(m_Texture);
	}
}
