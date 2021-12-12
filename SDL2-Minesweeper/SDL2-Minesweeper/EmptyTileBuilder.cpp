#include "EmptyTileBuilder.h"

EmptyTileBuilder::EmptyTileBuilder()
{
	m_Tile = nullptr;
}

EmptyTileBuilder::~EmptyTileBuilder()
{
	delete m_Tile;
}

void EmptyTileBuilder::buildTile()
{
	m_Tile = new Tile(
		nullptr,
		TileBitMask::Empty | TileBitMask::Covered
	);
}

void EmptyTileBuilder::buildGraphic(SDL_Renderer* ren)
{
	SDL_Texture* texture = ImageLoader::loadGPURendering(ren, nullptr, "");

	(*m_Tile).setGraphics(texture);
}

Tile* EmptyTileBuilder::getTile()
{
	return m_Tile;
}
