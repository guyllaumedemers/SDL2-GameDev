#pragma once
#include <unordered_map>
#include "ImageLoader.h"
#include "TileMapGenerator.h"

class Rendering
{
private:

	static std::unordered_map<std::string, SDL_Texture*> m_Textures;

	static SDL_Renderer* m_Renderer;

	static SDL_Window* m_Window;

	static void initializeWindow(const int& width, const int& height);

	static void initializeRendering();

	static void initializeTextures();

	static void initializeIMG();

	static void updateTileMap(Tile** map, const int& arrX, const int& arrY);

public:

	static void initialize(const int& width, const int& height);

	static void setWindowSize(const int& x, const int& y);

	static void update(Tile** map, const int& arrX, const int& arrY);

	static void clear();

	static SDL_Texture* getTextureFromKey(std::string key);
};

