#pragma once
#include <SDL.h>
#include "TileBitMask.h"

struct Tile
{
private:

	TileBitMask m_Bitmask = TileBitMask::None;

	int m_X = 0, m_Y = 0;

	SDL_Texture* m_Texture = nullptr;

public:

	Tile();

	Tile(SDL_Texture* texture, TileBitMask bitmask, int x, int y);

	~Tile();

	void setBitmaskValue(TileBitMask value, bool isRemoving);

	TileBitMask getBitmaskValue();

	void setGraphics(SDL_Texture* texture);

	SDL_Texture* getTexture();

	static const int width = 20, height = 20;
};