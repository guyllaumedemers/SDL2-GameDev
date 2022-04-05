#pragma once
#include <vector>
#include "Tetrominoe.h"
#include "Renderer.h"

using namespace std;
class TileMapManager
{
private:

	//FIELDS

	static bool** tilemap;

	static vector<Tetrominoe*> tetrominoes;

	//INTERNAL_LOGIC

	static bool checkRowState(const int&);

	static Tetrominoe* spawn();

public:

	//GAME_LOGIC

	static void create(const int&, const int&);

	static void update(const int&, const int&);

	static void render(SDL_Renderer*, const int&, const int&);

	static void clear(const int&);
};

