#include "EmptyTileBuilder.h"
#include "Rendering.h"

EmptyTileBuilder::EmptyTileBuilder(SDL_Texture* texture)
{
	m_Texture = texture;
	m_Tile = nullptr;
}

void EmptyTileBuilder::buildTile(int x, int y)
{
	m_Tile = new Tile(
		nullptr,
		TileBitMask::Empty | TileBitMask::Covered,
		x,
		y
	);
}
