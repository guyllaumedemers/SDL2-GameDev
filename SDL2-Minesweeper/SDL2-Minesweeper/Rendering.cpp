#include "Rendering.h"
#include <SDL_image.h>

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
		0
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

void Rendering::update()
{
	int rows = sizeof(TileMapGenerator::getMap()) / sizeof(TileMapGenerator::getMap()[0]);
	int cols = sizeof(TileMapGenerator::getMap()[0]) / sizeof(Tile);

	Tile* temp = &TileMapGenerator::getMap()[0][0];

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			int x = j * Tile::width;
			int y = i * Tile::height;

			SDL_Rect dest{
				x,
				y,
				Tile::width,
				Tile::height
			};

			SDL_RenderCopy(m_Renderer, (*temp).getTexture(), NULL, &dest);
			++temp;
		}
	}

	temp = nullptr;
	delete temp;
}

void Rendering::clear()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	IMG_Quit();
}
