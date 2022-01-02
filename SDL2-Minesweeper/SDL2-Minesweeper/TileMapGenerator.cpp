#include "TileMapGenerator.h"

TileBuilder* TileMapGenerator::m_TileBuilder = nullptr;

Tile** TileMapGenerator::m_Map = nullptr;

Tile TileMapGenerator::createTile(const int& x, const int& y)
{
	Tile temp = (*m_TileBuilder).buildTile(x, y);
	(*m_TileBuilder).buildGraphic(temp);
	return temp;
}

Tile** TileMapGenerator::createEmptyMap(const int& x, const int& y)
{
	m_Map = DBG_NEW Tile * [x];

	for (int i = 0; i < x; ++i) {

		m_Map[i] = DBG_NEW Tile[y];
		for (int j = 0; j < y; ++j) {
			m_Map[i][j] = createTile(i, j);
		}
	}
	return m_Map;
}

Tile** TileMapGenerator::createBombMap(const int& x, const int& y, int nbBombs)
{
	while (nbBombs > 0) {
		int row = rand() % x;
		int col = rand() % y;

		while ((m_Map[row][col].getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb) {
			row = rand() % x;
			col = rand() % y;
		}

		m_Map[row][col] = createTile(row, col);
		--nbBombs;
	}
	return m_Map;
}

void TileMapGenerator::updateBombOnFirstMove(SDL_Texture* texture, const int& x, const int& y, int nbBombs)
{
	setBuilder(DBG_NEW BombTileBuilder(texture));
	createBombMap(x, y, nbBombs);
	destroyBuilder();
}

void TileMapGenerator::clear(const int& row)
{
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

void TileMapGenerator::setBuilder(TileBuilder* builder)
{
	resetBuilder();
	m_TileBuilder = builder;
}

void TileMapGenerator::resetBuilder()
{
	delete m_TileBuilder;
	m_TileBuilder = nullptr;
}

void TileMapGenerator::destroyBuilder()
{
	resetBuilder();
}