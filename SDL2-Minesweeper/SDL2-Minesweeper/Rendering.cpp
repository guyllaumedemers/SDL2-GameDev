#include "Rendering.h"
#include "TextureManager.h"

SDL_Renderer* Rendering::m_Renderer = nullptr;

void Rendering::initializeRendering(SDL_Window* window)
{
	m_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (m_Renderer == nullptr) {
		SDL_Log("Cannot initalize SDL_Renderer : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	TextureManager::create(m_Renderer);
}

void Rendering::draw(Tile** map, const int& arrX, const int& arrY)
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);
	drawTileMap(map, arrX, arrY);
	SDL_RenderPresent(m_Renderer);
}

void Rendering::clear()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
	TextureManager::destroy();
}

SDL_Renderer* Rendering::getRenderer()
{
	return m_Renderer;
}

void Rendering::drawTileMap(Tile** map, const int& arrX, const int& arrY)
{
	for (int i = 0; i < arrX; ++i) {
		for (int j = 0; j < arrY; ++j) {

			int x = j * Tile::width;
			int y = i * Tile::height;

			SDL_Rect dest{
				x,
				y,
				Tile::width,
				Tile::height
			};

			Tile* tile = &map[i][j];

			SDL_Texture* target = SDL_CreateTexture(m_Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, Tile::width, Tile::height);
			SDL_SetRenderTarget(m_Renderer, target);

			SDL_RenderCopy(m_Renderer, (*tile).getTexture(), NULL, NULL);

			if (Util::checkBitMaskEquality(tile, TileBitMask::Flag)) {

				SDL_SetTextureBlendMode(TextureManager::getTexture("Flag"), SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, TextureManager::getTexture("Flag"), NULL, NULL);
			}
			else if (Util::checkBitMaskEquality(tile, TileBitMask::Numbered)) {

				char buffer[50];
				sprintf_s(buffer, "%d", (*tile).getValue());

				SDL_SetTextureBlendMode(TextureManager::getTexture(buffer), SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, TextureManager::getTexture(buffer), NULL, NULL);
			}

			if (Util::checkBitMaskEquality(tile, TileBitMask::Uncovered | TileBitMask::Bomb)) {

				SDL_SetTextureBlendMode(TextureManager::getTexture("Bomb"), SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, TextureManager::getTexture("Bomb"), NULL, NULL);
			}

			SDL_SetRenderTarget(m_Renderer, NULL);
			SDL_RenderCopy(m_Renderer, target, NULL, &dest);

			SDL_DestroyTexture(target);
			target = nullptr;
		}
	}
}
