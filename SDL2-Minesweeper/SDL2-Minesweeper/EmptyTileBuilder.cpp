#include "EmptyTileBuilder.h"

EmptyTileBuilder::EmptyTileBuilder()
{
	m_Tile = nullptr;
	m_Texture = nullptr;
}

EmptyTileBuilder::~EmptyTileBuilder()
{
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
