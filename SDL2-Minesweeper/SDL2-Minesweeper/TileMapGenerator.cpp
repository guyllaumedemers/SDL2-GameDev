#include "TileMapGenerator.h"

TileBuilder* TileMapGenerator::m_TileBuilder = nullptr;

Tile** TileMapGenerator::m_Map = nullptr;

Tile* TileMapGenerator::createTile(SDL_Renderer* ren)
{
	if (m_TileBuilder == nullptr) {
		SDL_Log("Cannot access IBuilder instance : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	(*m_TileBuilder).buildTile();
	(*m_TileBuilder).buildGraphic(ren);

	return (*m_TileBuilder).getTile();
}

Tile** TileMapGenerator::createMap(SDL_Renderer* ren, int x, int y)
{
	m_Map = new Tile * [x];

	for (int i = 0; i < x; ++i) {
		m_Map[i] = new Tile[y];

		for (int j = 0; j < y; ++j) {
			m_Map[i][j] = *createTile(ren);
		}
	}
	return m_Map;
}

void TileMapGenerator::clear()
{
	delete m_TileBuilder;
	delete m_Map;
}
