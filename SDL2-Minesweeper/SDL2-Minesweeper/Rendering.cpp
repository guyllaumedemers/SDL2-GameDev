#include "Rendering.h"

SDL_Window* Rendering::m_Window = nullptr;

SDL_Renderer* Rendering::m_Renderer = nullptr;

void Rendering::initializeWindow()
{
	m_Window = SDL_CreateWindow(
		"Minesweeper",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE
	);

	if (m_Window == nullptr) {
		SDL_Log("Cannot initalize SDL_Window : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::initializeRendering()
{
	m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);

	if (m_Renderer == nullptr) {
		SDL_Log("Cannot initalize SDL_Renderer : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::initializeIMG()
{
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP) == 0) {
		SDL_Log("Cannot initalize SDL_image : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::addGraphicLayer(Tile* tile, std::string path)
{
	SDL_Texture* dest = SDL_CreateTexture(m_Renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, Tile::width, Tile::height);

	SDL_Texture* src = ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), path);

	SDL_SetRenderTarget(m_Renderer, dest);
	SDL_SetTextureBlendMode(src, SDL_BLENDMODE_MOD);

	SDL_RenderCopy(m_Renderer, (*tile).getTexture(), NULL, NULL);
	SDL_RenderCopy(m_Renderer, src, NULL, NULL);

	SDL_SetRenderTarget(m_Renderer, NULL);

	SDL_RenderPresent(m_Renderer);

	(*tile).setGraphics(dest);

	SDL_DestroyTexture(src);
	src = nullptr;
}

void Rendering::initialize()
{
	initializeWindow();
	initializeRendering();
	initializeIMG();
}

void Rendering::setWindowSize(const int& x, const int& y)
{
	SDL_SetWindowSize(m_Window, Tile::width * x, Tile::height * y);
}

void Rendering::updateTileGraphic(const int& x, const int& y)
{
	Tile* temp = &TileMapGenerator::getMap()[y / Tile::width][x / Tile::height];
	TileBitMask bitmask = (*temp).getBitmaskValue();

	if ((bitmask & TileBitMask::Uncovered) == TileBitMask::Uncovered) {

		// do nothing
	}
	else if ((bitmask & TileBitMask::Covered) == TileBitMask::Covered) {

		if ((bitmask & TileBitMask::Flag) == TileBitMask::Flag) {

			// need a way to update properly the graphics for unchecking

			addGraphicLayer(temp, "../SDL2-Minesweeper/Assets/Flag.png");
		}
		else if ((bitmask & TileBitMask::Bomb) == TileBitMask::Bomb) {

			addGraphicLayer(temp, "../SDL2-Minesweeper/Assets/Bomb.png");
		}
		else {

			// swap to uncover

			// add number of bomb neighbors
		}
	}

	temp = nullptr;
	delete temp;
}

void Rendering::update(Tile** map, const int& arrX, const int& arrY)
{
	SDL_RenderClear(Rendering::m_Renderer);
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

			SDL_RenderCopy(m_Renderer, map[i][j].getTexture(), NULL, &dest);
		}
	}
	SDL_RenderPresent(Rendering::m_Renderer);
}

void Rendering::clear()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	IMG_Quit();
}
