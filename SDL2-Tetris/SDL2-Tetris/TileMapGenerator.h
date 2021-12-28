#pragma once
#include <SDL.h>
#include <iostream>
#include "Tetrominoe.h"
#include "Shape.h"

class TileMapGenerator
{
private:

	static bool** m_Map;

public:

	static void createMap(const int& row, const int& col);

	static Tetrominoe* createTetrominoe(Shape* shape);

	static bool** getMap();
};

