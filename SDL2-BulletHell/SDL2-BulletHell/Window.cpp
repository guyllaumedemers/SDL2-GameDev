#include "Window.h"

Window* Window::instance = nullptr;

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

Window* Window::getInstance(int w, int h)
{
	if (instance == nullptr) return instance = new Window(w, h);
	else return instance;
}

SDL_Window* Window::getWindow()
{
	return window;
}
