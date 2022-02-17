#pragma once
#include <SDL.h>
#include "Window.h"

class Rendering
{
public:
	SDL_Renderer* getRenderer();

	Rendering(Window* window);

	~Rendering();
private:
	SDL_Renderer* renderer = nullptr;
};

