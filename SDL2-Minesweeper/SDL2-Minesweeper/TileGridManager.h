#pragma once
#include <SDL.h>

enum class TileState {
	uncover,
	cover,
	flagged,
	empty,
	numbered,
	hasBomb
};

struct Tile {
public:
	TileState m_State;
	SDL_Texture* m_Texture;

	void UpdateState(TileState next);
};

void Tile::UpdateState(TileState next) {

}

class TileGridManager
{
private:
	static Tile** m_Grid;
public:
	static void initalize2dArray(unsigned short int n, unsigned short int m);
};

