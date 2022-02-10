#include "TileMapManager.h"
#include "TetrominoeFactory.h"

TileMapManager::TileMapManager(const int& row, const int col)
{
	tilemap = new bool* [row];
	for (int i = 0; i < row; ++i) {
		tilemap[i] = new bool[col];
		for (int j = 0; j < col; ++j) {
			tilemap[i][j] = false;
		}
	}
}

TileMapManager::~TileMapManager()
{
}

TileMapManager* TileMapManager::getInstance(const int& row, const int col)
{
	if (instance == nullptr) return instance = new TileMapManager(row, col);
	else return instance;
}

Tetrominoe* TileMapManager::create()
{
	return TetrominoeFactory::createTetrominoe(static_cast<TetrominoeType>(rand() % (int)TetrominoeType::T));
}
