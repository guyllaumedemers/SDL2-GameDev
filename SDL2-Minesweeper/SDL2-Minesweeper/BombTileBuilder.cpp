#include "BombTileBuilder.h"

BombTileBuilder::BombTileBuilder()
{
	m_Tile = nullptr;
	m_Texture = nullptr;
}

BombTileBuilder::~BombTileBuilder()
{
}

void BombTileBuilder::buildTile(int x, int y)
{
	m_Tile = new Tile(
		nullptr,
		TileBitMask::Covered | TileBitMask::Bomb,
		x,
		y
	);
}
