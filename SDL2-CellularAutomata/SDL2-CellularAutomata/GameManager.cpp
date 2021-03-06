#include "GameManager.h"
#include "CellularAutomata.h"

SDL_Window* GameManager::m_Window = nullptr;

SDL_Renderer* GameManager::m_Renderer = nullptr;

bool GameManager::m_IsRunning = true;

void GameManager::onInitialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Could not initialize SDL lib : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_Window = SDL_CreateWindow(
		"Cellular Automata",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		COLUMNS,
		ROWS,
		NULL
	);

	if (m_Window == nullptr) {
		SDL_Log("Could not instantiate a new window : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_Renderer = SDL_CreateRenderer(m_Window, 0, NULL);

	if (m_Renderer == nullptr) {
		SDL_Log("Could not instantiate a new renderer : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	CellularAutomata::onInitialize(m_Renderer);
}

void GameManager::onRun()
{
	while (m_IsRunning) {
		// poll events
		SDL_Event myEvent;
		while (SDL_PollEvent(&myEvent) > 0) {
			// retrieve inputs
			switch (myEvent.type)
			{
			case SDL_QUIT:
				m_IsRunning = false;
				break;
			}
		}
		onDraw();

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

void GameManager::onDraw()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0);
	// clear the screen
	SDL_RenderClear(m_Renderer);
	// fill the color buffer
	SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);
	// run automata rendering logic in-between
	CellularAutomata::onUpdate(m_Renderer);
	// render the back buffer frame to the front buffer frame
	SDL_RenderPresent(m_Renderer);
}

int GameManager::onExecute()
{
	// initialize SDL
	onInitialize();

	// run loop
	onRun();

	// exit game loop
	onClear();

	return 0;
}

void GameManager::onClear()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}
