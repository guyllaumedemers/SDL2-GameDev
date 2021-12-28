#include "TileMapGenerator.h"

bool** TileMapGenerator::m_Map = nullptr;

void TileMapGenerator::createMap(const int& row, const int& col)
{
	m_Map = new bool* [row];

	for (int i = 0; i < row; ++i) {
		m_Map[i] = new bool[col];

		for (int j = 0; j < col; ++j) {

			m_Map[i][j] = false;
		}
	}
}

Tetrominoe* TileMapGenerator::createTetrominoe(Shape* shape)
{
	return new Tetrominoe(shape);
}

bool** TileMapGenerator::getMap()
{
	return m_Map;
}
