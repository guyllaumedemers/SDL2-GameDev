#pragma once
#include <SDL.h>

class Window
{
private:

	//FIELDS

	SDL_Window* window = nullptr;

	//CONSTRUCTOR

	Window(const Window&) = delete;

	Window(Window&&) = delete;

public:

	//CONSTRUCTOR

	Window(const int&, const int&);

	~Window();

	//GETTER

	SDL_Window* getWindow();
};

