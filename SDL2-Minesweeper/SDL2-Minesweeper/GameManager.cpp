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

	setDifficulty(Mode::medium);

	if (m_Difficulty == nullptr) {
		SDL_Log("Difficulty was not initialize : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_FlagsLeft = (*m_Difficulty).m_Flags;

	Rendering::initialize();
	Rendering::setWindowSize((*m_Difficulty).m_Width, (*m_Difficulty).m_Height);

	TileMapGenerator::setTileBuilder(new EmptyTileBuilder());
	TileMapGenerator::createEmptyMap(Rendering::m_Window, Rendering::m_Renderer, (*m_Difficulty).m_Height, (*m_Difficulty).m_Width);

	TileMapGenerator::setTileBuilder(new BombTileBuilder());
	TileMapGenerator::createBombMap(Rendering::m_Window, Rendering::m_Renderer, (*m_Difficulty).m_Height, (*m_Difficulty).m_Width, (*m_Difficulty).m_Bombs);
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

int GameManager::checkNeighbor(Tile** map, const int x, const int& y, std::queue<Tile*>& queue, std::unordered_map<std::string, Tile*>& memoizationMap)
{
	if (x < 0 || x >= (*m_Difficulty).m_Height || y < 0 || y >= (*m_Difficulty).m_Width) {
		return 0;
	}
	else {
		Tile* temp = &map[x][y];

		char buffer[50];
		sprintf_s(buffer, "%d%d", (*temp).getX(), (*temp).getY());

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
			int isValidMove =
				(((*temp).getBitmaskValue() & TileBitMask::Covered) == TileBitMask::Covered) +
				(((*temp).getBitmaskValue() & TileBitMask::Empty) == TileBitMask::Empty);

			if (isValidMove > 1) {

				memoizationMap.insert(std::make_pair(buffer, &(*temp)));
				queue.push(&(*temp));
			}
			temp = nullptr;
			delete temp;
			return 0;
		}
	}
}

void GameManager::removeOrAddFlagFromCount(const bool& value)
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

	if (((*temp).getBitmaskValue() & TileBitMask::Uncovered) == TileBitMask::Uncovered) {
		temp = nullptr;
		delete temp;
		return;
	}
	else {
		bool hasFlagMask = (((*temp).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag);

		if (!canPlaceFlag()) {

			if (hasFlagMask) {

				(*temp).setBitmaskValue(TileBitMask::Empty, false);
				(*temp).setBitmaskValue(TileBitMask::Flag, true);
				removeOrAddFlagFromCount(false);
			}
		}
		else {

			(*temp).setBitmaskValue(TileBitMask::Empty, !hasFlagMask);
			(*temp).setBitmaskValue(TileBitMask::Flag, hasFlagMask);
			removeOrAddFlagFromCount(!hasFlagMask);
		}

		temp = nullptr;
		delete temp;
	}
}

void GameManager::uncoverTile(Tile** map, const int& x, const int& y)
{
	Tile* temp = &map[y / Tile::height][x / Tile::width];

	int isValidMove =
		(((*temp).getBitmaskValue() & TileBitMask::Uncovered) == TileBitMask::Uncovered) +
		(((*temp).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag) +
		(((*temp).getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb);

	if (isValidMove > 0) {
		if (((*temp).getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb) {
			// you lost
			//
			(*temp).setBitmaskValue(TileBitMask::Uncovered, false);
			(*temp).setBitmaskValue(TileBitMask::Covered, true);
		}
		temp = nullptr;
		delete temp;
		return;
	}
	else {

		std::unordered_map<std::string, Tile*> memoizationMap;
		std::queue<Tile*> neighbors;

		neighbors.push(&(*temp));

		char buffer[50];
		sprintf_s(buffer, "%d%d", (*temp).getX(), (*temp).getY());

		memoizationMap.insert(std::make_pair(buffer, &(*temp)));

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
				(*temp).setBitmaskValue(TileBitMask::Numbered | TileBitMask::Uncovered, false);
				(*temp).setBitmaskValue(TileBitMask::Empty | TileBitMask::Covered, true);
				(*temp).setValue(value);
			}
			else {
				(*temp).setBitmaskValue(TileBitMask::Uncovered, false);
				(*temp).setBitmaskValue(TileBitMask::Covered, true);
			}

			SDL_Texture* texture = ImageLoader::loadGPURendering(Rendering::m_Renderer, SDL_GetWindowSurface(Rendering::m_Window), "../SDL2-Minesweeper/Assets/UncoveredTile.png");
			(*temp).setGraphics(texture);

			texture = nullptr;
			SDL_DestroyTexture(texture);

			neighbors.pop();
		}
		std::cout << memoizationMap.size() << std::endl;
		memoizationMap.clear();
	}

	temp = nullptr;
	delete temp;
}

void GameManager::setIsRunning(const bool& value)
{
	m_IsRunning = value;
}
