#include "EmptyTileBuilder.h"

EmptyTileBuilder::EmptyTileBuilder()
{
	m_Tile = nullptr;
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
	SDL_Texture* texture = ImageLoader::loadGPURendering(ren, windowSurface, "../SDL2-Minesweeper/Assets/CoveredTile.png");

	(*m_Tile).setGraphics(texture);

	SDL_FreeSurface(windowSurface);
	windowSurface = nullptr;
}
