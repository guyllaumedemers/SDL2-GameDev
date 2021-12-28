#include "GameManager.h"

bool GameManager::m_IsRunning = true;

Timer* GameManager::m_TetrominoeGenerationIntervalTimer = nullptr;

Timer* GameManager::m_TetrominoeTranslationIntervalTimer = nullptr;

std::vector<Tetrominoe*> GameManager::m_Tetrominoes{};

void GameManager::initialize()
{
	SDL_SetMainReady();

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {

		SDL_Log("Cannot initialize SDL_lib : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	Rendering::initializeContext(GRIDWITDH * TILESIZE, GRIDHEIGHT * TILESIZE);
	TileMapGenerator::createMap(GRIDWITDH, GRIDHEIGHT);
	m_TetrominoeGenerationIntervalTimer = new Timer(INTERVAL_IN_MS);
	m_TetrominoeTranslationIntervalTimer = new Timer(INTERVAL_IN_MS * 0.75);
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
	delete m_TetrominoeGenerationIntervalTimer;
	m_TetrominoeGenerationIntervalTimer = nullptr;
}

void GameManager::generateTetrominoes()
{
	if ((*m_TetrominoeGenerationIntervalTimer).getTimeElapse()) {
		// use builder pattern to generate random shaped
		std::cout << "I have generated a new shape" << std::endl;
		(*m_TetrominoeGenerationIntervalTimer).reset();
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

void GameManager::updateTetrominoesPosition()
{
	for (auto& it : m_Tetrominoes) {
		// update the position occupied on the screen

		// update the tilemap status
	}
}

bool GameManager::checkForCollision(const Tetrominoe& tetrominoe)
{
	// tetrominoe cannot go more than the number of row

	// will have to check the status of the row and col to prevent from going down

	// can only confirm movement down or sideways if the neighbor is free

	// check 3 neightbors - left, right, down

	return false;
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
