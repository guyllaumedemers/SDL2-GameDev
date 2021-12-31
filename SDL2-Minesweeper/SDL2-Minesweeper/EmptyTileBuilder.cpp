#include "EmptyTileBuilder.h"

EmptyTileBuilder::EmptyTileBuilder(SDL_Texture* texture)
{
	m_Texture = texture;
	m_Tile = nullptr;
}

void EmptyTileBuilder::buildTile(int x, int y)
{
	m_Tile = DBG_NEW Tile(
		nullptr,
		TileBitMask::Empty | TileBitMask::Covered,
		x,
		y
	);
}
