#include "TetrominoeImp.h"
#include "Debugger.h"

int TetrominoeImp::cols = 3;

int TetrominoeImp::rows = 2;

//CONSTRUCTOR

TetrominoeImp::TetrominoeImp()
{
	tiles = DBG_NEW bool* [rows];
	for (int i = 0; i < rows; ++i) {
		tiles[i] = DBG_NEW bool[cols];
		for (int j = 0; j < cols; ++j) {
			tiles[i][j] = false;
		}
	}
}

TetrominoeImp::~TetrominoeImp()
{
	for (int i = 0; i < rows; ++i) {
		delete tiles[i];
		tiles[i] = nullptr;
	}
	delete tiles;
	tiles = nullptr;
}
