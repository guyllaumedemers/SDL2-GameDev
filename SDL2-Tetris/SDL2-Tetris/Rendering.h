#pragma once
#include <SDL.h>

class Rendering
{
public:

	~Rendering();

	static Rendering* getInstance(SDL_Window* window);

	void operator=(const Rendering&) = delete;

	SDL_Renderer* getRenderer();

private:

	Rendering(SDL_Window* window);

	static Rendering* instance;

	SDL_Renderer* sdl_renderer = nullptr;
};

