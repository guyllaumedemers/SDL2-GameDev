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

	setDifficulty(Mode::hard);

	if (m_Difficulty == nullptr) {
		SDL_Log("Difficulty was not initialize : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_FlagsLeft = (*m_Difficulty).m_Flags;

	Rendering::initialize();
	Rendering::setWindowSize((*m_Difficulty).m_Width, (*m_Difficulty).m_Height);

	TileMapGenerator::createMap(Rendering::m_Window, Rendering::m_Renderer, (*m_Difficulty).m_Height, (*m_Difficulty).m_Width);
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
	Rendering::update(TileMapGenerator::getMap(), (*m_Difficulty).m_Height, (*m_Difficulty).m_Width);
}

void GameManager::clear()
{
	TileMapGenerator::clear((*m_Difficulty).m_Height);
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

int GameManager::checkNeighbor(Tile** map, const int& x, const int& y, std::queue<Tile*>& queue, std::unordered_map<std::string, Tile*>& memoizationMap)
{
	if (x < 0 || x >= (*m_Difficulty).m_Height || y < 0 || y >= (*m_Difficulty).m_Width) {
		return 0;
	}
	else {
		Tile* temp = &map[x][y];

		char buffer[50];
		sprintf_s(buffer, "%c%c", x, y);

		if (memoizationMap.find(buffer) != memoizationMap.end()) {
			temp = nullptr;
			delete temp;
			return 0;
		}

		if (((*temp).getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb) {
			temp = nullptr;
			delete temp;
			return 1;
		}
		else {
			if (((*temp).getBitmaskValue() & TileBitMask::Empty) == TileBitMask::Empty) {
				queue.push(&(*temp));
			}
			temp = nullptr;
			delete temp;
			return 0;
		}
	}
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
	Tile* temp = &map[y / Tile::height][x / Tile::width];
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
	//std::cout << (y / Tile::height) << (x / Tile::width) << std::endl;
	temp = nullptr;
	delete temp;
}

void GameManager::uncoverTile(Tile** map, const int& x, const int& y)
{
	Tile* temp = &map[y / Tile::height][x / Tile::width];
	std::cout << (y / Tile::height) << (x / Tile::width) << std::endl;

	if (((*temp).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag) {
		temp = nullptr;
		delete temp;
		return;
	}
	else if (((*temp).getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb) {
		temp = nullptr;
		delete temp;
		return;
	}
	else {

		std::unordered_map<std::string, Tile*> memoizationMap;
		std::queue<Tile*> neighbors;
		neighbors.push(temp);

		while (!neighbors.empty()) {

			temp = neighbors.front();
			int x = (*temp).getX();
			int y = (*temp).getY();

			int value =
				checkNeighbor(map, x + 1, y, neighbors, memoizationMap) +
				checkNeighbor(map, x - 1, y, neighbors, memoizationMap) +
				checkNeighbor(map, x, y + 1, neighbors, memoizationMap) +
				checkNeighbor(map, x, y - 1, neighbors, memoizationMap) +
				checkNeighbor(map, x + 1, y + 1, neighbors, memoizationMap) +
				checkNeighbor(map, x - 1, y + 1, neighbors, memoizationMap) +
				checkNeighbor(map, x + 1, y - 1, neighbors, memoizationMap) +
				checkNeighbor(map, x - 1, y - 1, neighbors, memoizationMap);

			if (value > 0) {
				(*temp).setBitmaskValue(TileBitMask::Empty | TileBitMask::Covered, true);
				(*temp).setBitmaskValue(TileBitMask::Numbered | TileBitMask::Uncovered, false);
				(*temp).setValue(value);
			}
			else {
				(*temp).setBitmaskValue(TileBitMask::Covered, true);
				(*temp).setBitmaskValue(TileBitMask::Uncovered, false);
			}

			SDL_Texture* texture = ImageLoader::loadGPURendering(Rendering::m_Renderer, SDL_GetWindowSurface(Rendering::m_Window), "../SDL2-Minesweeper/Assets/UncoveredTile.png");
			(*temp).setGraphics(texture);

			char buffer[50];
			sprintf_s(buffer, "%d%d", x, y);

			memoizationMap.insert(std::pair(std::string(buffer), &(*temp)));
			neighbors.pop();
		}

		memoizationMap.clear();
	}

	temp = nullptr;
	delete temp;
}

void GameManager::setIsRunning(const bool& value)
{
	m_IsRunning = value;
}
