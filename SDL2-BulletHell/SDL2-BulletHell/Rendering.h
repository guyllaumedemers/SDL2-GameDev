#pragma once
#include <SDL.h>
#include <iostream>

class Rendering
{
public:
	static Rendering* getInstance(SDL_Window* window);

	SDL_Renderer* getRenderer();

	void operator=(const Rendering&) = delete;

	Rendering(const Rendering&) = delete;

	~Rendering();
private:
	static Rendering* instance;
	Rendering(SDL_Window* window);
	SDL_Renderer* renderer = nullptr;
};

