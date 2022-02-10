#include "Rendering.h"

Rendering* Rendering::instance = nullptr;

Rendering::Rendering(SDL_Window* window)
{
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == nullptr) {
		std::cout << "ERROR::RENDERER_CREATION_FAILED" << std::endl;
		exit(1);
	}
}

Rendering::~Rendering()
{
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
}

Rendering* Rendering::getInstance(SDL_Window* window)
{
	if (instance == nullptr) return instance = new Rendering(window);
	else return instance;
}

SDL_Renderer* Rendering::getRenderer()
{
	return renderer;
}
