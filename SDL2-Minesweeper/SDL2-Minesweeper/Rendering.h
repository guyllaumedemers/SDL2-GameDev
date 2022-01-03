#pragma once
#include <unordered_map>
#include "Util.h"
#include "ImageLoader.h"
#include "TileMapGenerator.h"

class Rendering
{
private:

	static std::unordered_map<std::string, SDL_Texture*> m_Textures;

	static SDL_Renderer* m_Renderer;

	static SDL_Window* m_Window;

//APP_LOGIC

	static void initializeWindow(const int& width, const int& height);

	static void initializeRendering();

	static void initializeTextures();

	static void initializeIMG();

//GAME_LOGIC

	static void updateTileMap(Tile** map, const int& arrX, const int& arrY);

public:

	static void setWindowSize(const int& x, const int& y);

	static void initialize(const int& width, const int& height);

	static void update(Tile** map, const int& arrX, const int& arrY);

	static void clear();

	static SDL_Texture* getTextureFromKey(std::string key);
};

