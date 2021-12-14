#pragma once
#include <SDL.h>
#include "TileMapGenerator.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Rendering
{
private:

	static void initializeWindow();

	static void initializeRendering();

	static void initializeIMG();

public:

	static SDL_Window* m_Window;

	static SDL_Renderer* m_Renderer;

	static void initialize();

	static void setWindowSize(int x, int y);

	static void update(Tile** map, int arrX, int arrY);

	static void clear();
};

