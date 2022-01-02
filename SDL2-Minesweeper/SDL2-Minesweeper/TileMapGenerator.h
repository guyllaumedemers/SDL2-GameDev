#pragma once
#include "TileBuilder.h"
#include "EmptyTileBuilder.h"
#include "BombTileBuilder.h"

class TileMapGenerator
{
private:

	static TileBuilder* m_TileBuilder;

	static Tile** m_Map;

	static void resetBuilder();

public:

	static Tile createTile(const int& x, const int& y);

	static Tile** createEmptyMap(const int& x, const int& y);

	static Tile** createBombMap(const int& x, const int& y, int nbBombs);

	static void updateBombOnFirstMove(SDL_Texture* texture, const int& x, const int& y, int nbBombs);

	static void clear(const int& row);

	static Tile** getMap();

	static void setBuilder(TileBuilder* builder);

	static void destroyBuilder();
};

