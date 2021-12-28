#include "Rendering.h"

SDL_Window* Rendering::m_Window = nullptr;

SDL_Renderer* Rendering::m_Renderer = nullptr;

void Rendering::initializeContext(const int& w, const int& h)
{
	m_Window = SDL_CreateWindow(
		"Tetris",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		w,
		h,
		NULL
	);

	if (m_Window == nullptr) {
		SDL_Log("Window was not initialize : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

	if (m_Renderer == nullptr) {
		SDL_Log("Renderer was not initialize : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Rendering::clear()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
}

void Rendering::renderFrame()
{
	SDL_RenderClear(m_Renderer);
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0);

	// update tetris

	SDL_RenderPresent(m_Renderer);
}
