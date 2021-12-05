#include "TileGridManager.h"

void TileGridManager::initalize2dArray(unsigned short int n, unsigned short int m)
{
	m_Grid = new Tile * [n];

	for (int i = 0; i < n; ++i) {
		m_Grid[i] = new Tile[m];
	}
}
