#include "Renderer.h"
#include <iostream>

//CONSTRUCTOR

Renderer::Renderer(Window* window)
{
	renderer = SDL_CreateRenderer(
		window->getWindow(),
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE
	);

	if (renderer == nullptr) {
		std::cout << "ERROR::RENDERER_CREATION_FAILED" << std::endl;
		exit(EXIT_FAILURE);
	}
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
	renderer = nullptr;
}

//GETTER

SDL_Renderer* Renderer::getRenderer()
{
    return renderer;
}
