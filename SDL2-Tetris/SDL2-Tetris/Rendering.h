#pragma once
#include <SDL.h>

class Rendering
{
private:

	static SDL_Window* m_Window;

	static SDL_Renderer* m_Renderer;

public:

	static void initializeContext(const int& w, const int& h);

	static void renderFrame();

	static void clear();
};

