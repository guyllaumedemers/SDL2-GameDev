#include "TileMapManager.h"

bool** TileMapManager::tilemap = nullptr;

vector<Tetrominoe*> TileMapManager::tetrominoes;

//GAME_LOGIC

void TileMapManager::create(const int& row, const int& col)
{
	tilemap = DBG_NEW bool* [row];
	for (int i = 0; i < row; ++i) {
		tilemap[i] = DBG_NEW bool[col];
		for (int j = 0; j < col; ++j) {
			tilemap[i][j] = false;
		}
	}
}

void TileMapManager::update(const int& row, const int& col)
{
	//TODO Update the tilemap, check for available slot
	//TODO Update tetrominoes position
}

void TileMapManager::render(SDL_Renderer* ren, const int& row, const int& col)
{
	//TODO Render tetrominoes at position
}

void TileMapManager::clear(const int& row)
{
	for (auto& it : tetrominoes) {
		delete it;
		it = nullptr;
	}
	for (int i = 0; i < row; ++i) {
		delete[] tilemap[i];
		tilemap[i] = nullptr;
	}
	delete[] tilemap;
	tilemap = nullptr;
}

//INTERNAL_LOGIC

bool TileMapManager::checkRowState(const int& pos)
{
	return false;
}

Tetrominoe* TileMapManager::spawn()
{
	//TODO Create a randomized function for creating tetrominoes pattern
	return nullptr;
}
