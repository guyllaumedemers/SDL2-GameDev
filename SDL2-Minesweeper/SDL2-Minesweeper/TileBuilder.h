#pragma once
#include "Tile.h"

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

