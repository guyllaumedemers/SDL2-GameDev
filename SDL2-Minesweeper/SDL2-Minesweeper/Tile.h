#pragma once
#include <SDL.h>
#include "TileBitMask.h"

struct Tile
{
public:

	static const int width;

	static const int height;

private:

	TileBitMask m_Bitmask = TileBitMask::None;

	int m_X = 0;

	int m_Y = 0;

	int m_Value = 0;

	SDL_Texture* m_Texture = nullptr;

public:

	Tile();

	Tile(SDL_Texture* texture, TileBitMask bitmask, const int& x, const int& y);

	~Tile();

	void setBitmaskValue(TileBitMask value, bool isRemoving);

	TileBitMask getBitmaskValue();

	void setGraphics(SDL_Texture* texture);

	SDL_Texture* getTexture();

	int getX();

	int getY();

	int getValue();

	void setValue(const int& val);
};