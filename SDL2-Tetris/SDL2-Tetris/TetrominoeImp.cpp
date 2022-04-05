#include "TetrominoeImp.h"

int TetrominoeImp::cols = 3;

int TetrominoeImp::rows = 2;

//DESTRUCTOR

TetrominoeImp::~TetrominoeImp()
{
	for (int i = 0; i < rows; ++i) {
		delete tiles[i];
		tiles[i] = nullptr;
	}
	delete tiles;
	tiles = nullptr;
}
