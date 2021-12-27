#include "TileMapGenerator.h"

TileBuilder* TileMapGenerator::m_TileBuilder = nullptr;

Tile** TileMapGenerator::m_Map = nullptr;

Tile* TileMapGenerator::createTile(SDL_Window* window, SDL_Renderer* ren, const int& x, const int& y)
{
	if (m_TileBuilder == nullptr) {
		SDL_Log("Cannot access IBuilder instance : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	(*m_TileBuilder).buildTile(x, y);
	(*m_TileBuilder).buildGraphic(window, ren);

	return (*m_TileBuilder).getTile();
}

Tile** TileMapGenerator::createMap(SDL_Window* window, SDL_Renderer* ren, const int& x, const int& y)
{
	m_Map = new Tile * [x];
	m_TileBuilder = new EmptyTileBuilder();

	for (int i = 0; i < x; ++i) {
		m_Map[i] = new Tile[y];

		for (int j = 0; j < y; ++j) {

			m_Map[i][j] = *createTile(window, ren, i, j);
			//std::cout << i << j << " ";
		}
		//std::cout << std::endl;
	}

	return m_Map;
}

void TileMapGenerator::clear(const int& row)
{
	delete m_TileBuilder;
	m_TileBuilder = nullptr;

	for (int i = 0; i < row; ++i) {
		delete[] m_Map[i];
	}

	delete m_Map;
	m_Map = nullptr;
}

Tile** TileMapGenerator::getMap()
{
	return m_Map;
}