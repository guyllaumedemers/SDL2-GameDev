#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "TileMapGenerator.h"
#include "EmptyTileBuilder.h"
#include "BombTileBuilder.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Rendering
{
private:

	static void initializeWindow();

	static void initializeRendering();

	static void initializeIMG();

	static void addGraphicLayer(Tile* tile, std::string path);

public:

	static SDL_Window* m_Window;

	static SDL_Renderer* m_Renderer;

	static void initialize();

	static void setWindowSize(const int& x, const int& y);

	static void updateTileGraphic(const int& x, const int& y);

	static void update(Tile** map, const int& arrX, const int& arrY);

	static void clear();
};

