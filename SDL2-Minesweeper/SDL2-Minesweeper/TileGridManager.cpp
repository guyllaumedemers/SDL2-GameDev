#include "TileGridManager.h"

void TileGridManager::initalize2dArray(const unsigned short int& n, const unsigned short int& m)
{
	m_Grid = new Tile * [n];

	for (int i = 0; i < n; ++i) {
		m_Grid[i] = new Tile[m];
	}
}

unsigned short int TileGridManager::getGridIndexAtMousePosition(const unsigned short& x, const unsigned short& y)
{
	return 0;
}
