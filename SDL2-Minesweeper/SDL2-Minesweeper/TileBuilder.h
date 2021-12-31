#pragma once
#include "Tile.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

class TileBuilder
{
protected:

	SDL_Texture* m_Texture = nullptr;

	Tile* m_Tile = nullptr;

public:

	virtual ~TileBuilder() {
		delete m_Tile;
		m_Tile = nullptr;
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	}

	virtual void buildTile(int x, int y) = 0;

	virtual void buildGraphic() {

		if (m_Texture != nullptr) {
			(*m_Tile).setGraphics(m_Texture);
		}
	};

	virtual Tile* getTile() { return m_Tile; };
};

