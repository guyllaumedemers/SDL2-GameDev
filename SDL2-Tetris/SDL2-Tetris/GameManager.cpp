#include "GameManager.h"

bool GameManager::m_IsRunning = true;

void GameManager::initialize()
{
	SDL_SetMainReady();

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {

		SDL_Log("Cannot initialize SDL_lib : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	Rendering::initializeContext(600, 400);
}

void GameManager::getInputs()
{
	InputManager::getInputs();
}

void GameManager::runGameLogic()
{
}

void GameManager::renderFrame()
{
	Rendering::renderFrame();
}

void GameManager::clear()
{
	Rendering::clear();
}

void GameManager::setIsRunning(const bool& value)
{
	m_IsRunning = value;
}

int GameManager::onExecute()
{
	initialize();
	while (m_IsRunning) {
		getInputs();
		runGameLogic();
		renderFrame();
	}
	clear();
	return 0;
}
