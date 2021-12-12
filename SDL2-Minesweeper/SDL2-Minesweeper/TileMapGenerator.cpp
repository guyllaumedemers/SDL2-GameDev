#include "TileMapGenerator.h"

TileBuilder* TileMapGenerator::m_TileBuilder = nullptr;

Tile** TileMapGenerator::m_Map = nullptr;

Tile* TileMapGenerator::createTile(SDL_Renderer* ren, TileBuilder* iBuilder)
{
	(*iBuilder).buildTile();
	(*iBuilder).buildGraphic(ren);

	return (*iBuilder).GetTile();
}

Tile** TileMapGenerator::createMap(SDL_Renderer* ren, int x, int y)
{
	m_Map = new Tile * [x];

	for (int i = 0; i < x; ++i) {
		m_Map[i] = new Tile[y];

		for (int j = 0; j < y; ++j) {
			m_Map[i][j] = *createTile(ren, m_TileBuilder);
		}
	}
	return m_Map;
}

void TileMapGenerator::clear()
{
	delete m_TileBuilder;
	delete m_Map;
}
