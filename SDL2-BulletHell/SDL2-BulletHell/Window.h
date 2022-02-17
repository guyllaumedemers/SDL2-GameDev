#pragma once
#include <SDL.h>

class Window
{
public:
	SDL_Window* getWindow();

	Window(int w, int h);

	~Window();
private:
	SDL_Window* window = nullptr;
};

