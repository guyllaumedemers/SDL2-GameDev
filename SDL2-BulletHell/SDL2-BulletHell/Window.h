#pragma once
#include <SDL.h>

class Window
{
private:

	//FIELDS

	SDL_Window* window = nullptr;

public:

	//CONSTRUCTOR

	Window(int w, int h);

	~Window();

	//GETTER

	SDL_Window* getWindow();
};

