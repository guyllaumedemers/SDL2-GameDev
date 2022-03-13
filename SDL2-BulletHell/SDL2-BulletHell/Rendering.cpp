#include "Rendering.h"
#include <iostream>

//CONSTRUCTOR

Rendering::Rendering(Window* window)
{
	renderer = SDL_CreateRenderer(window->getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
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

//GETTER

SDL_Renderer* Rendering::getRenderer()
{
	return renderer;
}