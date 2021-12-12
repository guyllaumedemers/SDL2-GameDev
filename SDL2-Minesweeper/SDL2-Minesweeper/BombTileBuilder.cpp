#include "BombTileBuilder.h"

BombTileBuilder::BombTileBuilder()
{
	m_Tile = nullptr;
}

BombTileBuilder::~BombTileBuilder()
{
	delete m_Tile;
}

void BombTileBuilder::buildTile()
{
	m_Tile = new Tile();
}

void BombTileBuilder::buildGraphic(SDL_Renderer* ren)
{
	SDL_Texture* texture = ImageLoader::loadGPURendering(ren, nullptr, "");

	(*m_Tile).setGraphics(nullptr);
}
