#include "Rendering.h"

SDL_Renderer* Rendering::m_Renderer = nullptr;

std::unordered_map<std::string, SDL_Texture*> Rendering::m_Textures;

void Rendering::initializeRendering(SDL_Window* window)
{
	m_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (m_Renderer == nullptr) {
		SDL_Log("Cannot initalize SDL_Renderer : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::initializeTextures()
{
	m_Textures.insert(std::make_pair("Flag", ImageLoader::loadGPURendering(m_Renderer, "../SDL2-Minesweeper/Assets/Flag.png")));
	m_Textures.insert(std::make_pair("Bomb", ImageLoader::loadGPURendering(m_Renderer, "../SDL2-Minesweeper/Assets/Bomb.png")));

	char buffer[50];
	for (int i = 1; i <= 8; ++i) {
		sprintf_s(buffer, "../SDL2-Minesweeper/Assets/%d.png", i);
		m_Textures.insert(std::make_pair("Number_" + std::to_string(i), ImageLoader::loadGPURendering(m_Renderer, buffer)));
	}

	m_Textures.insert(std::make_pair("Covered", ImageLoader::loadGPURendering(m_Renderer, "../SDL2-Minesweeper/Assets/CoveredTile.png")));
	m_Textures.insert(std::make_pair("Uncovered", ImageLoader::loadGPURendering(m_Renderer, "../SDL2-Minesweeper/Assets/UncoveredTile.png")));
	m_Textures.insert(std::make_pair("Hit", ImageLoader::loadGPURendering(m_Renderer, "../SDL2-Minesweeper/Assets/TileHit.png")));

	m_Textures.insert(std::make_pair("OnHooverEnter", ImageLoader::loadGPURendering(m_Renderer, "../SDL2-Minesweeper/Assets/OnHooverEnter.png")));
	m_Textures.insert(std::make_pair("OnButtonSelect", ImageLoader::loadGPURendering(m_Renderer, "../SDL2-Minesweeper/Assets/OnButtonSelect.png")));
}

void Rendering::initializeIMG()
{
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP) == 0) {
		SDL_Log("Cannot initalize SDL_image : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::draw(Tile** map, const std::vector<Panel*>& panels, Panel* contentArea, const int& arrX, const int& arrY)
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);

	(*panels.at(0)).draw(m_Renderer, SDL_Color{ 236,233,216,255 });
	(*panels.at(1)).draw(m_Renderer, SDL_Color{ 192,192,192,255 });
	(*panels.at(2)).draw(m_Renderer, SDL_Color{ 192,192,192,255 });
	drawTileMap(map, contentArea, arrX, arrY);

	SDL_RenderPresent(m_Renderer);
}

void Rendering::clear()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
	IMG_Quit();
}

void Rendering::drawTileMap(Tile** map, Panel* contentArea, const int& arrX, const int& arrY)
{
	for (int i = 0; i < arrX; ++i) {
		for (int j = 0; j < arrY; ++j) {

			int x = j * Tile::width;
			int y = i * Tile::height;

			SDL_Rect dest{
				x + (*(*contentArea).getRect()).x,
				y + (*(*contentArea).getRect()).y,
				Tile::width,
				Tile::height
			};

			Tile* tile = &map[i][j];

			SDL_Texture* target = SDL_CreateTexture(m_Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, Tile::width, Tile::height);
			SDL_SetRenderTarget(m_Renderer, target);

			SDL_RenderCopy(m_Renderer, (*tile).getTexture(), NULL, NULL);

			if (Util::checkBitMaskEquality(tile, TileBitMask::Flag)) {

				SDL_SetTextureBlendMode(m_Textures["Flag"], SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, m_Textures["Flag"], NULL, NULL);
			}
			else if (Util::checkBitMaskEquality(tile, TileBitMask::Numbered)) {

				char buffer[50];
				sprintf_s(buffer, "Number_%d", (*tile).getValue());

				SDL_SetTextureBlendMode(m_Textures[buffer], SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, m_Textures[buffer], NULL, NULL);
			}

			if (Util::checkBitMaskEquality(tile, TileBitMask::Uncovered | TileBitMask::Bomb)) {

				SDL_SetTextureBlendMode(m_Textures["Bomb"], SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, m_Textures["Bomb"], NULL, NULL);
			}

			SDL_SetRenderTarget(m_Renderer, NULL);
			SDL_RenderCopy(m_Renderer, target, NULL, &dest);

			SDL_DestroyTexture(target);
			target = nullptr;
		}
	}
}

SDL_Texture* Rendering::getTextureFromKey(std::string key)
{
	if (m_Textures.find(key) != m_Textures.end()) {
		return m_Textures[key];
	}
	return nullptr;
}
