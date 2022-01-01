#include "EmptyTileBuilder.h"

EmptyTileBuilder::EmptyTileBuilder(SDL_Texture* texture)
{
	m_Texture = texture;
}

EmptyTileBuilder::~EmptyTileBuilder()
{
	m_Texture = nullptr;
}

Tile EmptyTileBuilder::buildTile(int x, int y)
{
	return Tile(
		nullptr,
		TileBitMask::Empty | TileBitMask::Covered,
		x,
		y
	);
}

void EmptyTileBuilder::buildGraphic(Tile& tile)
{
	if (m_Texture != nullptr) {
		tile.setGraphics(m_Texture);
	}
}
