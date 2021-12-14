#include "TileMapGenerator.h"
#include <iostream>

TileBuilder* TileMapGenerator::m_TileBuilder = nullptr;

Tile** TileMapGenerator::m_Map = nullptr;

Tile* TileMapGenerator::createTile(SDL_Window* window, SDL_Renderer* ren, const int& x, const int& y)
{
	if (m_TileBuilder == nullptr) {
		SDL_Log("Cannot access IBuilder instance : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	(*m_TileBuilder).buildTile(x, y);
	(*m_TileBuilder).buildGraphic(window, ren);

	return (*m_TileBuilder).getTile();
}

Tile** TileMapGenerator::createMap(SDL_Window* window, SDL_Renderer* ren, const int& x, const int& y)
{
	m_Map = new Tile * [x];
	m_TileBuilder = new EmptyTileBuilder();

	for (int i = 0; i < x; ++i) {
		m_Map[i] = new Tile[y];

		for (int j = 0; j < y; ++j) {
			// once in a while the Builder needs to swap his reference to create bomb
			// 
			// amt of bombs are set depending on the level
			//
			m_Map[i][j] = *createTile(window, ren, j, i);
		}
	}
	return m_Map;
}

void TileMapGenerator::clear()
{
	delete m_TileBuilder;
	delete m_Map;
}

void TileMapGenerator::swapBuilder(TileBuilder* ibuilder)
{
	m_TileBuilder = nullptr;
	delete m_TileBuilder;

	m_TileBuilder = ibuilder;
}

Tile** TileMapGenerator::getMap()
{
	return m_Map;
}

void TileMapGenerator::doFlagCheck(const int& x, const int& y)
{
	Tile* temp = &m_Map[y / Tile::width][x / Tile::height];

	(*temp).setBitmaskValue(TileBitMask::Flag, ((*temp).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag);

	temp = nullptr;
	delete temp;
}

void TileMapGenerator::uncoverTile(const int& x, const int& y)
{
	Tile* temp = &m_Map[y / Tile::width][x / Tile::height];
	TileBitMask bitmask = (*temp).getBitmaskValue();

	if ((bitmask & TileBitMask::Flag) == TileBitMask::Flag) {
		// do nothing
		//
	}
	else if ((bitmask & TileBitMask::Bomb) == TileBitMask::Bomb) {
		// hit
		//
	}
	else {
		if ((bitmask & TileBitMask::Covered) == TileBitMask::Covered) {
			// run algorithm logic for empty neighbor dicovery
			//
		}
	}

	temp = nullptr;
	delete temp;
}