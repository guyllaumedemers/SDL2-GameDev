#include "BombTileBuilder.h"

BombTileBuilder::BombTileBuilder()
{
	m_Tile = nullptr;
	m_Texture = nullptr;
}

BombTileBuilder::~BombTileBuilder()
{
	delete m_Tile;
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

void BombTileBuilder::buildGraphic(SDL_Window* window, SDL_Renderer* ren)
{
	SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
	if (m_Texture == nullptr) {
		m_Texture = ImageLoader::loadGPURendering(ren, windowSurface, "SDL2-Minesweeper/Assets/Bomb.png");
	}

	(*m_Tile).setGraphics(m_Texture);

	SDL_FreeSurface(windowSurface);
	windowSurface = nullptr;
}
