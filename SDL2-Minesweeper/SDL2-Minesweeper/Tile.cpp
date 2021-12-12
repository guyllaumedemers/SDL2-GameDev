#include "Tile.h"

Tile::Tile()
{
	m_Texture = nullptr;
	m_Bitmask = TileBitMask::None;
}

Tile::Tile(SDL_Texture* texture, TileBitMask bitmask)
{
	m_Texture = texture;
	m_Bitmask = bitmask;
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

void Tile::setGraphics(SDL_Texture* texture) {
	m_Texture = texture;
}