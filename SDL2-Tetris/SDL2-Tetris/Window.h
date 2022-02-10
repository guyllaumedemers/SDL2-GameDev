#pragma once
#include <SDL.h>

class Window
{
public:

	~Window();

	static Window* getInstance(const int& w, const int& h);

	void operator=(const Window&) = delete;

	SDL_Window* getWindow();

private:

	Window(const int& w, const int& h);

	static Window* instance;

	SDL_Window* sdl_window = nullptr;
};

