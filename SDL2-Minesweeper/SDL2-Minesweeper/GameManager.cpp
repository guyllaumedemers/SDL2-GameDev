#include "GameManager.h"
#include "ImageLoader.h"
#include "InputManager.h"
#include <iostream>
#include "UIController.h"

bool GameManager::m_IsRunning = true;

SDL_Window* GameManager::m_Window = nullptr;

SDL_Renderer* GameManager::m_Renderer = nullptr;

SDL_Surface* GameManager::m_SurfaceDisplay = nullptr;

SDL_Surface* GameManager::m_ImgSurfaceDisplay = nullptr;

SDL_Texture* GameManager::m_Texture = nullptr;

Timer* GameManager::m_Timer = nullptr;

void GameManager::initializeGame()
{
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Cannot initalize SDL : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_Window = SDL_CreateWindow(
		"Minesweeper",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		0
	);

	if (m_Window == nullptr) {
		SDL_Log("Cannot initalize SDL_Window : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);

	if (m_Renderer == nullptr) {
		SDL_Log("Cannot initalize SDL_Renderer : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0);

	m_SurfaceDisplay = SDL_GetWindowSurface(m_Window);

	if (m_SurfaceDisplay == nullptr) {
		SDL_Log("Cannot initalize SDL_Surface : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP) == 0) {
		SDL_Log("Cannot initalize SDL_image : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_Texture = ImageLoader::loadGPURendering(m_Renderer, m_SurfaceDisplay, "../SDL2-Minesweeper/stretch.bmp");

	if (m_Texture == nullptr) {
		SDL_Log("Cannot initalize SDL_Texture : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_Timer = new Timer(2.0f);
	if (m_Timer == nullptr) {
		SDL_Log("Cannot initalize Timer : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_Timer->RegisterToTimerCallback([]() {});
}

void GameManager::getInputEvents()
{
	SDL_Event myEvent;
	while (SDL_PollEvent(&myEvent) > 0) {
		InputManager::getInputEvent(myEvent);
	}
}

void GameManager::runGameLogic()
{
	if (m_Timer != nullptr) {
		if (m_Timer->run()) {
			UIController::UpdateTimerView(m_Timer->getTime());
		}
		else {
			m_Timer->onTimerCallback();
			m_Timer = nullptr;
		}
	}
}

void GameManager::renderFrame()
{
	// CPU Rendering
	//SDL_BlitSurface(m_ImgSurfaceDisplay, NULL, m_SurfaceDisplay, NULL);
	//SDL_UpdateWindowSurface(m_Window);

	// GPU Rendering
	SDL_RenderClear(m_Renderer);
	SDL_RenderCopy(m_Renderer, m_Texture, NULL, NULL);
	SDL_RenderPresent(m_Renderer);
}

void GameManager::clear()
{
	m_Timer = nullptr;
	SDL_FreeSurface(m_SurfaceDisplay);
	m_SurfaceDisplay = nullptr;
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	IMG_Quit();
	SDL_Quit();
}

int GameManager::onExecute()
{
	initializeGame();
	while (m_IsRunning) {
		getInputEvents();
		runGameLogic();
		renderFrame();
	}
	clear();
	return 0;
}

void GameManager::setIsRunning(bool value)
{
	m_IsRunning = value;
}
