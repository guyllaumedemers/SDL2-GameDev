#pragma once
#include <SDL.h>
#include <iostream>

class Window
{
public:
	static Window* getInstance(int w, int h);

	SDL_Window* getWindow();

	void operator=(const Window&) = delete;

	Window(const Window&) = delete;

	~Window();
private:
	static Window* instance;
	Window(int w, int h);
	SDL_Window* window = nullptr;
};

