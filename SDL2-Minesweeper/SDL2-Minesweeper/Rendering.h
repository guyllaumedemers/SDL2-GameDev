#pragma once
#include "GameManager.h"

class Rendering
{
private:

	static std::unordered_map<std::string, SDL_Texture*> m_Textures;

	static void initializeWindow(const int& width, const int& height);

	static void initializeRendering();

	static void intializeTextures();

	static void initializeIMG();

public:

	static SDL_Window* m_Window;

	static SDL_Renderer* m_Renderer;

	static void initialize(const int& width, const int& height);

	static void setWindowSize(const int& x, const int& y);

	static void update(Tile** map, const int& arrX, const int& arrY);

	static void clear();
};

