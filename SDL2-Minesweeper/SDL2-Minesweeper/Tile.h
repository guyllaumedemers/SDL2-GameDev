#pragma once
#include <SDL.h>
#include "TileBitMask.h"

struct Tile
{
private:

	SDL_Texture* m_Texture = nullptr;

	TileBitMask m_Bitmask = TileBitMask::None;

public:
	Tile();

	Tile(SDL_Texture* texture, TileBitMask bitmask);

	~Tile();

	void setBitmaskValue(TileBitMask value, bool isRemoving);

	void setGraphics(SDL_Texture* texture);
};