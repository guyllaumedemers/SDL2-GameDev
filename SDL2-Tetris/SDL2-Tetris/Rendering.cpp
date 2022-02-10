#include "Rendering.h"
#include <iostream>

Rendering* Rendering::instance = nullptr;

Rendering::Rendering(SDL_Window* window)
{
	sdl_renderer = SDL_CreateRenderer(window, -1, 0);
	if (sdl_renderer == nullptr) {
		std::cout << "ERROR::SDL_RENDERER::CREATION_FAILED" << std::endl;
		exit(0);
	}
}

Rendering::~Rendering()
{
	SDL_DestroyRenderer(sdl_renderer);
	sdl_renderer = nullptr;
}

Rendering* Rendering::getInstance(SDL_Window* window)
{
	if (instance == nullptr) return instance = new Rendering(window);
	else return instance;
}

SDL_Renderer* Rendering::getRenderer()
{
	return sdl_renderer;
}
