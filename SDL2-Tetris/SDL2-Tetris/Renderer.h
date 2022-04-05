#pragma once
#include <SDL.h>
#include "Window.h"

class Renderer
{
private:

	//FIELDS

	SDL_Renderer* renderer = nullptr;

	//CONSTRUCTOR

	Renderer(const Renderer&) = delete;

	Renderer(Renderer&&) = delete;

public:

	//CONSTRUCTOR

	Renderer(Window* window);

	~Renderer();

	//GETTER

	SDL_Renderer* getRenderer();
};

