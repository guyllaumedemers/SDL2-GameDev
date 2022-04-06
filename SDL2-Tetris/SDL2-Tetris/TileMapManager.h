#pragma once
#include <vector>
#include "Tetrominoe.h"
#include "Renderer.h"

using namespace std;
class TileMapManager
{
private:

	//FIELDS

	static bool* map;

	static vector<Tetrominoe*> tetrominoes;

public:

	//GAME_LOGIC

	static void create(const int&, const int&);

	static void update(const int&, const int&);

	static void render(SDL_Renderer*, const int&, const int&, const int&);

	static void clear(const int&);
};

