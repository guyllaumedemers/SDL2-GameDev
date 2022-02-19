#include "Rendering.h"
#include <iostream>

//CONSTRUCTOR

Rendering::Rendering(Window* window)
{
	renderer = SDL_CreateRenderer(window->getWindow(), -1, 0);
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