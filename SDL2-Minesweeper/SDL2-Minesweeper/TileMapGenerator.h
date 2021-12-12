#pragma once
#include "TileBuilder.h"
#include "EmptyTileBuilder.h"
#include "Tile.h"

class TileMapGenerator
{
private:

	static TileBuilder* m_TileBuilder;

	static Tile** m_Map;

	static Tile* createTile(SDL_Renderer* ren);

public:

	static Tile** createMap(SDL_Renderer* ren, int x, int y);

	static void clear();
};

