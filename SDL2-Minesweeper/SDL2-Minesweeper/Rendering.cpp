#include "Rendering.h"

SDL_Window* Rendering::m_Window = nullptr;

SDL_Renderer* Rendering::m_Renderer = nullptr;

std::unordered_map<std::string, SDL_Texture*> Rendering::m_Textures;

void Rendering::initializeWindow(const int& width, const int& height)
{
	m_Window = SDL_CreateWindow(
		"Minesweeper",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		0
	);

	if (m_Window == nullptr) {
		SDL_Log("Cannot initalize SDL_Window : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::initializeRendering()
{
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

	if (m_Renderer == nullptr) {
		SDL_Log("Cannot initalize SDL_Renderer : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::intializeTextures()
{
	m_Textures.insert(std::make_pair("Flag", ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), "../SDL2-Minesweeper/Assets/Flag.png")));
	m_Textures.insert(std::make_pair("Bomb", ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), "../SDL2-Minesweeper/Assets/Bomb.png")));

	for (int i = 1; i <= 8; ++i) {
		char buffer[50];
		sprintf_s(buffer, "../SDL2-Minesweeper/Assets/%d.png", i);
		m_Textures.insert(std::make_pair("Number_" + std::to_string(i), ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), buffer)));
	}

	m_Textures.insert(std::make_pair("Covered", ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), "../SDL2-Minesweeper/Assets/CoveredTile.png")));
	m_Textures.insert(std::make_pair("Uncovered", ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), "../SDL2-Minesweeper/Assets/UncoveredTile.png")));
	m_Textures.insert(std::make_pair("Hit", ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), "../SDL2-Minesweeper/Assets/TileHit.png")));
}

void Rendering::initializeIMG()
{
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP) == 0) {
		SDL_Log("Cannot initalize SDL_image : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::initialize(const int& width, const int& height)
{
	initializeWindow(width, height);
	initializeRendering();
	intializeTextures();
	initializeIMG();
}

void Rendering::setWindowSize(const int& x, const int& y)
{
	SDL_SetWindowSize(m_Window, Tile::width * x, Tile::height * y);
}

void Rendering::update(Tile** map, const int& arrX, const int& arrY)
{
	SDL_RenderClear(m_Renderer);
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

			SDL_RenderClear(m_Renderer);
			SDL_RenderCopy(m_Renderer, (*tile).getTexture(), NULL, NULL);

			if (((*tile).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag) {

				SDL_SetTextureBlendMode(m_Textures["Flag"], SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, m_Textures["Flag"], NULL, NULL);
			}
			else if (((*tile).getBitmaskValue() & TileBitMask::Numbered) == TileBitMask::Numbered) {

				char buffer[50];
				sprintf_s(buffer, "Number_%d", (*tile).getValue());
				SDL_SetTextureBlendMode(m_Textures[buffer], SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, m_Textures[buffer], NULL, NULL);
			}

			if (((*tile).getBitmaskValue() & (TileBitMask::Uncovered | TileBitMask::Bomb)) == (TileBitMask::Uncovered | TileBitMask::Bomb)) {

				SDL_SetTextureBlendMode(m_Textures["Bomb"], SDL_BLENDMODE_BLEND);
				SDL_RenderCopy(m_Renderer, m_Textures["Bomb"], NULL, NULL);
			}

			SDL_SetRenderTarget(m_Renderer, NULL);
			SDL_RenderCopy(m_Renderer, target, NULL, &dest);

			SDL_DestroyTexture(target);
			target = nullptr;

			tile = nullptr;
			delete tile;
		}
	}
	SDL_RenderPresent(m_Renderer);
}

void Rendering::clear()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	IMG_Quit();
}

SDL_Texture* Rendering::getTextureFromKey(std::string key)
{
	if (m_Textures.find(key) != m_Textures.end()) {
		return m_Textures[key];
	}
	return nullptr;
}
