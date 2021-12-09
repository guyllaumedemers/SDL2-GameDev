#include "TileGridManager.h"

Tile** TileGridManager::m_Grid = nullptr;

TileGridManager::~TileGridManager()
{
	delete m_Grid;
	m_Grid = nullptr;
}

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

Tile* TileGridManager::getGridAtIndex(const unsigned short int index)
{
	return nullptr;
}
