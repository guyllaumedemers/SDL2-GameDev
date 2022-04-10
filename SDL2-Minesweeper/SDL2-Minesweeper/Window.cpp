#include "Window.h"
#include "Debugger.h"

SDL_Window* Window::m_Window = nullptr;

void Window::initializeWindow(const int& x, const int& y, const int& width, const int& height)
{
	m_Window = SDL_CreateWindow(
		"Minesweeper",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		x + width,
		y + height,
		0
	);

	if (m_Window == nullptr) {
		SDL_Log("Cannot initalize SDL_Window : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Window::setWindowSize(const int& width, const int& height)
{
	SDL_SetWindowSize(m_Window, width, height);
}

void Window::clear()
{
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
}

SDL_Window* Window::getWindow()
{
	return m_Window;
}