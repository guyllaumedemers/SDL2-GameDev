#include "BombTileBuilder.h"
#include "Rendering.h"

BombTileBuilder::BombTileBuilder(SDL_Texture* texture)
{
	m_Texture = texture;
	m_Tile = nullptr;
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