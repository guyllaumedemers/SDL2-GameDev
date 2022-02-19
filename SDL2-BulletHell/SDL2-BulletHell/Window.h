#pragma once
#include <SDL.h>

class Window
{
private:

	//FIELDS

	SDL_Window* window = nullptr;
public:

	//GETTER

	SDL_Window* getWindow();

	//CONSTRUCTOR

	Window(int w, int h);

	~Window();
};

