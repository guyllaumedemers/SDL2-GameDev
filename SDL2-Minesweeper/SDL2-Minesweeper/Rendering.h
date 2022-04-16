#pragma once
#include <unordered_map>
#include "Util.h"
#include "ImageLoader.h"
#include "TileMapGenerator.h"

class Rendering
{
private:
	static SDL_Renderer* m_Renderer;

	//GAME_LOGIC

	static void drawTileMap(Tile** map, const int& arrX, const int& arrY);

public:

	//APP_LOGIC

	static void initializeRendering(SDL_Window* window);

	static void draw(Tile** map, const int& arrX, const int& arrY);

	static void clear();

	static SDL_Renderer* getRenderer();
};

