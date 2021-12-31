#include "BombTileBuilder.h"

BombTileBuilder::BombTileBuilder(SDL_Texture* texture)
{
	m_Texture = texture;
	m_Tile = nullptr;
}

void BombTileBuilder::buildTile(int x, int y)
{
	m_Tile = DBG_NEW Tile(
		nullptr,
		TileBitMask::Covered | TileBitMask::Bomb,
		x,
		y
	);
}