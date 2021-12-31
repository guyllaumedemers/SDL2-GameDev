#pragma once
#include <iostream>
#include "Tile.h"
#include "TileBuilder.h"
#include "BombTileBuilder.h"
#include "EmptyTileBuilder.h"

class TileMapGenerator
{
private:

	static TileBuilder* m_TileBuilder;

	static Tile** m_Map;

public:

	static Tile* createTile(SDL_Window* window, SDL_Renderer* ren, const int& x, const int& y);

	static Tile** createEmptyMap(SDL_Window* window, SDL_Renderer* ren, const int& x, const int& y);

	static Tile** createBombMap(SDL_Window* window, SDL_Renderer* ren, const int& x, const int& y, int nbBombs);

	static void clear(const int& row);

	static Tile** getMap();

	static void setTileBuilder(TileBuilder* builder);
};

