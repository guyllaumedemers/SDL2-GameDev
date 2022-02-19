#include "Window.h"
#include <iostream>

//CONSTRUCTOR

Window::Window(int w, int h)
{
	window = SDL_CreateWindow(
		"Bullet Hell",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		w,
		h,
		0
	);
	if (window == nullptr) {
		std::cout << "ERROR::WINDOW_CREATION_FAILED" << std::endl;
		exit(1);
	}
}

Window::~Window()
{
	SDL_DestroyWindow(window);
	window = nullptr;
}

//GETTER

SDL_Window* Window::getWindow()
{
	return window;
}
