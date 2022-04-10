#pragma once
#pragma once
#include <SDL.h>
#include <vector>
#include <iostream>
#include "Tile.h"
#include "Rendering.h"

class Window
{
private:

	static SDL_Window* m_Window;

public:

	//APP_LOGIC

	static void initializeWindow(const int& x, const int& y, const int& width, const int& height);

	static void setWindowSize(const int& width, const int& height);

	static void clear();

	static SDL_Window* getWindow();
};

