#include "TileMapManager.h"
#include "TextureManager.h"

bool** TileMapManager::tilemap = nullptr;

vector<Tetrominoe*> TileMapManager::tetrominoes;

//GAME_LOGIC

void TileMapManager::create(const int& row, const int& col)
{
	tilemap = DBG_NEW bool* [row];
	for (int i = 0; i < row; ++i) {
		tilemap[i] = DBG_NEW bool[col];
		for (int j = 0; j < col; ++j) {
			tilemap[i][j] = false;
		}
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
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {

			int x = j * tile_s;
			int y = i * tile_s;

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
}

void TileMapManager::clear(const int& row)
{
	for (auto& it : tetrominoes) {
		delete it;
		it = nullptr;
	}
	for (int i = 0; i < row; ++i) {
		delete[] tilemap[i];
		tilemap[i] = nullptr;
	}
	delete[] tilemap;
	tilemap = nullptr;
}

//INTERNAL_LOGIC

bool TileMapManager::checkRowState(const int& pos)
{
	return false;
}

Tetrominoe* TileMapManager::spawn()
{
	//TODO Create a randomized function for creating tetrominoes pattern
	return nullptr;
}
