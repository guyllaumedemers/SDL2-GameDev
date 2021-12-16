#include "Tile.h"

Tile::Tile()
{
	m_Texture = nullptr;
	m_Bitmask = TileBitMask::None;
	m_X = 0;
	m_Y = 0;
}

Tile::Tile(SDL_Texture* texture, TileBitMask bitmask, const int& x, const int& y)
{
	m_Texture = texture;
	m_Bitmask = bitmask;
	m_X = x;
	m_Y = y;
}

Tile::~Tile()
{
	delete m_Texture;
}

void Tile::setBitmaskValue(TileBitMask value, bool isRemoving)
{
	if (isRemoving) {
		m_Bitmask &= ~value;
	}
	else {
		m_Bitmask |= value;
	}
}

TileBitMask Tile::getBitmaskValue()
{
	return m_Bitmask;
}

void Tile::setGraphics(SDL_Texture* texture) {
	m_Texture = texture;
}

SDL_Texture* Tile::getTexture()
{
	return m_Texture;
}

int Tile::getX()
{
	return m_X;
}

int Tile::getY()
{
	return m_Y;
}
