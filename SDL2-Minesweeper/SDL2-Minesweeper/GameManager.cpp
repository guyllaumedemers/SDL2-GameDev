#include "GameManager.h"

bool GameManager::m_IsRunning = true;

int GameManager::m_FlagsLeft = -1;

Difficulty* GameManager::m_Difficulty = nullptr;

void GameManager::initializeGame()
{
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Log("Cannot initalize SDL : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	setDifficulty(Mode::beginner);

	if (m_Difficulty == nullptr) {
		SDL_Log("Difficulty was not initialize : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_FlagsLeft = (*m_Difficulty).m_Flags;

	Rendering::initialize();
	Rendering::setWindowSize((*m_Difficulty).m_Width, (*m_Difficulty).m_Height);

	TileMapGenerator::createMap(Rendering::m_Window, Rendering::m_Renderer, (*m_Difficulty).m_Width, (*m_Difficulty).m_Height);
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
}

void GameManager::renderFrame()
{
	Rendering::update(TileMapGenerator::getMap(), (*m_Difficulty).m_Width, (*m_Difficulty).m_Height);
}

void GameManager::clear()
{
	TileMapGenerator::clear();
	Rendering::clear();
	delete m_Difficulty;
	m_Difficulty = nullptr;
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

void GameManager::setDifficulty(Mode mode)
{
	m_Difficulty = new Difficulty(mode);
}

bool GameManager::canPlaceFlag()
{
	return m_FlagsLeft > 0;
}

void GameManager::updateFlagCount(const bool& value)
{
	if (value) {
		m_FlagsLeft -= 1;
	}
	else {
		m_FlagsLeft += 1;
	}
}

void GameManager::doFlagCheck(Tile** map, const int& x, const int& y)
{
	Tile* temp = &map[y / Tile::width][x / Tile::height];
	bool hasFlagMask = (((*temp).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag);

	if (!canPlaceFlag()) {

		if (hasFlagMask) {

			(*temp).setBitmaskValue(TileBitMask::Flag, hasFlagMask);
			updateFlagCount(!hasFlagMask);
		}
	}
	else {

		(*temp).setBitmaskValue(TileBitMask::Flag, hasFlagMask);
		updateFlagCount(!hasFlagMask);
	}

	temp = nullptr;
	delete temp;
}

void GameManager::uncoverTile(Tile** map, const int& x, const int& y)
{
	Tile* temp = &map[y / Tile::width][x / Tile::height];

	// run the algorithm for searching neighbors

	temp = nullptr;
	delete temp;
}

void GameManager::setIsRunning(const bool& value)
{
	m_IsRunning = value;
}
