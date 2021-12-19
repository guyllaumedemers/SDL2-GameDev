#pragma once
#include "TileBuilder.h"
#include "EmptyTileBuilder.h"
#include "Tile.h"

class TileMapGenerator
{
private:

	static TileBuilder* m_TileBuilder;

	static Tile** m_Map;

public:

	static Tile* createTile(SDL_Window* window, SDL_Renderer* ren, const int& x, const int& y);

	static Tile** createMap(SDL_Window* window, SDL_Renderer* ren, const int& x, const int& y);

	static void clear();

	static void swapBuilder(TileBuilder* ibuilder);

	static Tile** getMap();
};

