#pragma once
#include <vector>
#include "Tetrominoe.h"

class TileMapManager
{
public:

	~TileMapManager();

	static TileMapManager* getInstance(const int& row, const int col);

	void operator=(const TileMapManager&) = delete;

	//GAME_LOGIC

	Tetrominoe* create();

private:

	TileMapManager(const int& row, const int col);

	static TileMapManager* instance;

	bool** tilemap = nullptr;

	std::vector<Tetrominoe*> tetrominoes;
};

