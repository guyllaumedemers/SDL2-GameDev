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

	SDL_Texture* m_Texture;

	TileState m_State;

	~Tile();

	bool hasBomb();

	void updateState(const TileState& next);
};

Tile::~Tile() {
	delete m_Texture;
	m_Texture = nullptr;
}

bool Tile::hasBomb() {
	return  (m_State == TileState::hasBomb);
}

void Tile::updateState(const TileState& next) {
	m_State = next;
}

class TileGridManager
{
private:
	static Tile** m_Grid;
public:
	~TileGridManager();

	static void initalize2dArray(const unsigned short int& n, const unsigned short int& m);

	static unsigned short int getGridIndexAtMousePosition(const unsigned short& x, const unsigned short& y);
};

