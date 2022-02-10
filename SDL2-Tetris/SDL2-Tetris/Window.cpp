#include "Window.h"
#include <iostream>

Window* Window::instance = nullptr;

Window::Window(const int& w, const int& h)
{
	sdl_window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_RESIZABLE);
	if (sdl_window == nullptr) {
		std::cout << "ERROR::SDL_WINDOW::CREATION_FAILED" << std::endl;
		exit(0);
	}
}

Window::~Window()
{
	SDL_DestroyWindow(sdl_window);
	sdl_window = nullptr;
}

Window* Window::getInstance(const int& w, const int& h)
{
	if (instance == nullptr) return instance = new Window(w, h);
	else return instance;
}

SDL_Window* Window::getWindow()
{
	return sdl_window;
}
