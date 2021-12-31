#include "TileMapGenerator.h"

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

Tile** TileMapGenerator::createEmptyMap(SDL_Window* window, SDL_Renderer* ren, const int& x, const int& y)
{
	m_Map = new Tile * [x];

	for (int i = 0; i < x; ++i) {
		m_Map[i] = new Tile[y];

		for (int j = 0; j < y; ++j) {

			m_Map[i][j] = *createTile(window, ren, i, j);
		}
	}
	return m_Map;
}

Tile** TileMapGenerator::createBombMap(SDL_Window* window, SDL_Renderer* ren, const int& x, const int& y, int nbBombs)
{
	int mod = (x * y) / nbBombs;

	while (nbBombs > 0) {
		int row = rand() % x;
		int col = rand() % y;

		while ((m_Map[row][col].getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb) {
			row = rand() % x;
			col = rand() % y;
		}

		m_Map[row][col] = *createTile(window, ren, row, col);
		--nbBombs;
	}
	return m_Map;
}

void TileMapGenerator::clear(const int& row)
{
	delete m_TileBuilder;
	m_TileBuilder = nullptr;

	for (int i = 0; i < row; ++i) {
		delete[] m_Map[i];
		m_Map[i] = nullptr;
	}

	delete[] m_Map;
	m_Map = nullptr;
}

Tile** TileMapGenerator::getMap()
{
	return m_Map;
}

void TileMapGenerator::setTileBuilder(TileBuilder* builder)
{
	delete m_TileBuilder;
	m_TileBuilder = nullptr;

	m_TileBuilder = builder;
}
