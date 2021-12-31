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

	Rendering::initialize((*m_Difficulty).m_Width * Tile::width, (*m_Difficulty).m_Height * Tile::width);

	SDL_Texture* texture = Rendering::getTextureFromKey("Covered");

	TileMapGenerator::setTileBuilder(new EmptyTileBuilder(texture));
	TileMapGenerator::createEmptyMap((*m_Difficulty).m_Height, (*m_Difficulty).m_Width);

	TileMapGenerator::setTileBuilder(new BombTileBuilder(texture));
	TileMapGenerator::createBombMap((*m_Difficulty).m_Height, (*m_Difficulty).m_Width, (*m_Difficulty).m_Bombs);

	texture = nullptr;
}

void GameManager::getInputEvents()
{
	SDL_Event myEvent;
	while (SDL_PollEvent(&myEvent) > 0) {

		InputManager::getInputEvent(myEvent, TileMapGenerator::getMap());
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
		char buffer[50];
		sprintf_s(buffer, "%d%d", map[x][y].getX(), map[x][y].getY());

		if (memoizationMap.find(buffer) != memoizationMap.end()) {
			return 0;
		}

		if ((map[x][y].getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb) {
			return 1;
		}
		else {
			int isValidMove =
				((map[x][y].getBitmaskValue() & TileBitMask::Covered) == TileBitMask::Covered) +
				((map[x][y].getBitmaskValue() & TileBitMask::Empty) == TileBitMask::Empty);

			if (isValidMove > 1) {

				memoizationMap.insert(std::make_pair(buffer, &map[x][y]));
				queue.push(&map[x][y]);
			}
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

void GameManager::doFlagCheck(Tile* currentTile)
{
	if (((*currentTile).getBitmaskValue() & TileBitMask::Uncovered) == TileBitMask::Uncovered) {
		return;
	}
	else {
		bool hasFlagMask = (((*currentTile).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag);

		if (!canPlaceFlag()) {

			if (hasFlagMask) {

				(*currentTile).setBitmaskValue(TileBitMask::Empty, false);
				(*currentTile).setBitmaskValue(TileBitMask::Flag, true);
				removeOrAddFlagFromCount(false);
			}
		}
		else {

			(*currentTile).setBitmaskValue(TileBitMask::Empty, !hasFlagMask);
			(*currentTile).setBitmaskValue(TileBitMask::Flag, hasFlagMask);
			removeOrAddFlagFromCount(!hasFlagMask);
		}
	}
}

void GameManager::uncoverTile(Tile** map, Tile* currentTile)
{
	int isValidMove =
		(((*currentTile).getBitmaskValue() & TileBitMask::Uncovered) == TileBitMask::Uncovered) +
		(((*currentTile).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag) +
		(((*currentTile).getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb);

	if (isValidMove > 0) {
		if (isValidMove == 1 && ((*currentTile).getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb) {
			// you lost
			//
			(*currentTile).setBitmaskValue(TileBitMask::Uncovered, false);
			(*currentTile).setBitmaskValue(TileBitMask::Covered, true);
			(*currentTile).setGraphics(Rendering::getTextureFromKey("Hit"));
		}
		return;
	}
	else {

		std::unordered_map<std::string, Tile*> memoizationMap;
		std::queue<Tile*> neighbors;

		neighbors.push(&(*currentTile));

		char buffer[50];
		sprintf_s(buffer, "%d%d", (*currentTile).getX(), (*currentTile).getY());

		memoizationMap.insert(std::make_pair(buffer, &(*currentTile)));

		while (!neighbors.empty()) {

			currentTile = neighbors.front();
			int x = (*currentTile).getX();
			int y = (*currentTile).getY();

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
				(*currentTile).setBitmaskValue(TileBitMask::Numbered | TileBitMask::Uncovered, false);
				(*currentTile).setBitmaskValue(TileBitMask::Empty | TileBitMask::Covered, true);
				(*currentTile).setValue(value);
			}
			else {
				(*currentTile).setBitmaskValue(TileBitMask::Uncovered, false);
				(*currentTile).setBitmaskValue(TileBitMask::Covered, true);
			}

			(*currentTile).setGraphics(Rendering::getTextureFromKey("Uncovered"));
			neighbors.pop();
		}
		std::cout << memoizationMap.size() << std::endl;
		memoizationMap.clear();
	}
}

void GameManager::setIsRunning(const bool& value)
{
	m_IsRunning = value;
}
