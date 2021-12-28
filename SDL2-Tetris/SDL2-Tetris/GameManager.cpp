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
	checkForCompleteAlignment(TileMapGenerator::getMap(), GRIDHEIGHT, GRIDWITDH);
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

int GameManager::checkForCompleteAlignment(bool** map, const int& row, const int& col)
{
	bool* temp = &map[row - 1][col - 1];

	int rowCount = 0;
	for (int i = row - 1; i >= 0; --i) {
		int colCount = 0;

		for (int j = col - 1; j >= 0; --j) {
			if ((*temp)) {
				++colCount;
			}
			--temp;
		}
		if (colCount >= col) {
			++rowCount;
		}
	}
	temp = nullptr;
	delete temp;
	return rowCount;
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
