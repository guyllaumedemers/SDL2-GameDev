#pragma once
#include "TileBuilder.h"
#include "EmptyTileBuilder.h"
#include "Tile.h"

class TileMapGenerator
{
private:

	static TileBuilder* m_TileBuilder;

	static Tile** m_Map;

	static Tile* createTile(SDL_Window* window, SDL_Renderer* ren, int x, int y);

public:

	static Tile** createMap(SDL_Window* window, SDL_Renderer* ren, int x, int y);

	static void clear();

	static Tile** getMap();
};

