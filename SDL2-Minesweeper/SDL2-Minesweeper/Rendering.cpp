#include "Rendering.h"
#include <iostream>

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

			if ((map[i][j].getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag) {
				SDL_Texture* image_1 = ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), "../SDL2-Minesweeper/Assets/CoveredTile.png");
				SDL_Texture* image_2 = ImageLoader::loadGPURendering(m_Renderer, SDL_GetWindowSurface(m_Window), "../SDL2-Minesweeper/Assets/Flag.png");

				SDL_Texture* target = SDL_CreateTexture(m_Renderer, SDL_PIXELFORMAT_RGBX8888, SDL_TEXTUREACCESS_TARGET, Tile::width, Tile::height);
				SDL_SetRenderTarget(m_Renderer, target);

				SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0);
				SDL_RenderClear(m_Renderer);

				SDL_RenderCopy(m_Renderer, image_1, NULL, NULL);
				SDL_RenderCopy(m_Renderer, image_2, NULL, NULL);

				SDL_SetRenderTarget(m_Renderer, NULL);
				SDL_RenderCopy(m_Renderer, target, NULL, &dest);
			}

			//SDL_RenderCopy(m_Renderer, map[i][j].getTexture(), NULL, &dest);
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
