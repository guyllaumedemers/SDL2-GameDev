#include "EmptyTileBuilder.h"
#include <iostream>

EmptyTileBuilder::EmptyTileBuilder()
{
	m_Tile = nullptr;
	m_Texture = nullptr;
}

EmptyTileBuilder::~EmptyTileBuilder()
{
	delete m_Tile;
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

void EmptyTileBuilder::buildGraphic(SDL_Window* window, SDL_Renderer* ren)
{
	SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
	if (m_Texture == nullptr) {
		m_Texture = ImageLoader::loadGPURendering(ren, windowSurface, "../SDL2-Minesweeper/Assets/CoveredTile.png");
	}

	(*m_Tile).setGraphics(m_Texture);

	SDL_FreeSurface(windowSurface);
	windowSurface = nullptr;
}
