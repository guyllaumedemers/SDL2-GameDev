#pragma once
#include "Tile.h"
#include "ImageLoader.h"

class TileBuilder
{
protected:

	Tile* m_Tile = nullptr;

	SDL_Texture* m_Texture = nullptr;

public:

	virtual ~TileBuilder() {
		delete m_Tile;
		m_Tile = nullptr;
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	};

	virtual void buildTile(int x, int y) = 0;

	virtual void buildGraphic(SDL_Window* window, SDL_Renderer* ren)
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
	};

	Tile* getTile() { return m_Tile; }
};

