#include "GameManager.h"

bool GameManager::m_IsRunning = true;

Timer* GameManager::m_Timer = nullptr;

void GameManager::initialize()
{
	SDL_SetMainReady();

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {

		SDL_Log("Cannot initialize SDL_lib : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	Rendering::initializeContext(GRIDWITDH * TILESIZE, GRIDHEIGHT * TILESIZE);
	TileMapGenerator::createMap(GRIDWITDH, GRIDHEIGHT);
	m_Timer = new Timer(INTERVAL_IN_MS);
}

void GameManager::getInputs()
{
	InputManager::getInputs();
}

void GameManager::runGameLogic()
{
	generateTetrominoes();
	checkForCompleteAlignment(TileMapGenerator::getMap());
}

void GameManager::renderFrame()
{
	Rendering::renderFrame();
}

void GameManager::clear()
{
	Rendering::clear();
}

void GameManager::generateTetrominoes()
{
	if ((*m_Timer).getTimeElapse()) {
		// use builder pattern to generate random shaped
		std::cout << "I have generated a new shape" << std::endl;
		(*m_Timer).reset();
	}
}

int GameManager::checkForCompleteAlignment(bool** map)
{
	return 0;
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
