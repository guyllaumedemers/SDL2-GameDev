#include "EmptyTileBuilder.h"
#include <iostream>

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

void EmptyTileBuilder::buildGraphic(SDL_Window* window, SDL_Renderer* ren)
{
	SDL_Surface* windowSurface = SDL_GetWindowSurface(window);

	SDL_Texture* texture = ImageLoader::loadGPURendering(ren, windowSurface, "../SDL2-Minesweeper/Assets/CoveredTile.png");
	if (texture != nullptr) {

		(*m_Tile).setGraphics(texture);
	}
	texture = nullptr;
	SDL_DestroyTexture(texture);

	SDL_FreeSurface(windowSurface);
	windowSurface = nullptr;
}
