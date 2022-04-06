#include "TileMapManager.h"
#include "TextureManager.h"
#include "Debugger.h"

bool* TileMapManager::map = nullptr;

vector<Tetrominoe*> TileMapManager::tetrominoes;

//GAME_LOGIC

void TileMapManager::create(const int& row, const int& col)
{
	map = DBG_NEW bool[row * col];
	for (int i = 0; i < row * col; ++i) {
		map[i] = false;
	}
}

void TileMapManager::update(const int& row, const int& col)
{
	//TODO Update the tilemap, check for available slot
	//TODO Update tetrominoes position
}

void TileMapManager::render(SDL_Renderer* ren, const int& row, const int& col, const int& tile_s)
{
	SDL_RenderClear(ren);
	for (int i = 0; i < row * col; ++i) {
		int x = (i % col) * tile_s;
		int y = (i / col) * tile_s;

		SDL_Rect dest = {
			x,
			y,
			tile_s,
			tile_s
		};

		SDL_Texture* target = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, tile_s, tile_s);
		SDL_SetRenderTarget(ren, target);
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);

		SDL_Texture* temp = TextureManager::getTexture("Black");
		SDL_RenderCopy(ren, temp, NULL, NULL);

		SDL_SetRenderTarget(ren, NULL);
		SDL_RenderCopy(ren, target, NULL, &dest);

		SDL_DestroyTexture(target);
		target = nullptr;
	}
}

void TileMapManager::clear(const int& row)
{
	for (auto& it : tetrominoes) {
		delete it;
		it = nullptr;
	}
	delete[] map;
	map = nullptr;
}
