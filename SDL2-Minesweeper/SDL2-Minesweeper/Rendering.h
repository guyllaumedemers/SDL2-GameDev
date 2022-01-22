#pragma once
#include <unordered_map>
#include "Util.h"
#include "Window.h"
#include "ImageLoader.h"
#include "TileMapGenerator.h"

class Rendering
{
private:

	static std::unordered_map<std::string, SDL_Texture*> m_Textures;

	static SDL_Renderer* m_Renderer;

	//APP_LOGIC

	static void initializeRendering();

	static void initializeTextures(SDL_Window* window);

	static void initializeIMG();

	//GAME_LOGIC

	static void updateTileMap(Tile** map, Panel* contentArea, const int& arrX, const int& arrY);

public:

	static void initializeRenderingCTX(SDL_Window* window);

	static void update(Tile** map, const std::vector<Panel*>& panels, Panel* contentArea, const int& arrX, const int& arrY);

	static void clear();

	static SDL_Texture* getTextureFromKey(std::string key);
};

