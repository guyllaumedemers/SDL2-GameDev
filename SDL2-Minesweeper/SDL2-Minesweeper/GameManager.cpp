#include "GameManager.h"
#include "ImageLoader.h"
#include "InputManager.h"
#include "UIController.h"
#include "TileMapGenerator.h"
#include "Rendering.h"
#include <iostream>
#include <string>

bool GameManager::m_IsRunning = true;

void GameManager::initializeGame()
{
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Cannot initalize SDL : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	Rendering::initialize();
	TileMapGenerator::createMap(Rendering::m_Window, Rendering::m_Renderer, 8, 8);
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
	unsigned short int x, y;
	InputManager::getMouseClickPos(x, y);
}

void GameManager::renderFrame()
{
	SDL_RenderClear(Rendering::m_Renderer);
	Rendering::update();
	SDL_RenderPresent(Rendering::m_Renderer);
}

void GameManager::clear()
{
	TileMapGenerator::clear();
	Rendering::clear();
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

void GameManager::setIsRunning(const bool& value)
{
	m_IsRunning = value;
}
