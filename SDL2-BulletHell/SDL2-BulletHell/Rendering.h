#pragma once
#include "Window.h"

class Rendering
{
private:

	//FIELDS

	SDL_Renderer* renderer = nullptr;

public:

	//GETTER

	SDL_Renderer* getRenderer();

	//CONSTRUCTOR

	Rendering(Window* window);

	~Rendering();
};

