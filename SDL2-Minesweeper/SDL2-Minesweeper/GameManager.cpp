#include "GameManager.h"

bool GameManager::m_IsRunning = true;

int GameManager::m_FlagsLeft = -1;

bool GameManager::m_IsFirstMove = true;

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

	Rendering::initialize((*m_Difficulty).m_Width * Tile::width, (*m_Difficulty).m_Height * Tile::height);

	TileMapGenerator::setBuilder(DBG_NEW EmptyTileBuilder(Rendering::getTextureFromKey("Covered")));
	TileMapGenerator::createEmptyMap((*m_Difficulty).m_Height, (*m_Difficulty).m_Width);

	TileMapGenerator::setBuilder(DBG_NEW BombTileBuilder(Rendering::getTextureFromKey("Covered")));
	TileMapGenerator::createBombMap((*m_Difficulty).m_Height, (*m_Difficulty).m_Width, (*m_Difficulty).m_Bombs);

	TileMapGenerator::destroyBuilder();
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
	m_Difficulty = DBG_NEW Difficulty(mode);
}

bool GameManager::canPlaceFlag()
{
	return m_FlagsLeft > 0;
}

bool GameManager::isInsideBounds(Tile** map, const int& x, const int& y, std::unordered_map<std::string, Tile*>& edgeMap)
{
	if (edgeMap.empty()) {
		return true;
	}
	else {
		int smallestX = INT_MAX;
		int smallestY = INT_MAX;
		int biggestX = INT_MIN;
		int biggestY = INT_MIN;

		for (const auto& it : edgeMap) {
			int x = (*it.second).getX();
			int y = (*it.second).getY();

			if (x < smallestX) smallestX = x;
			if (y < smallestY) smallestY = y;
			if (x > biggestX) biggestX = x;
			if (y > biggestY) biggestY = y;
		}

		if (x > biggestX + 1 || x < smallestX - 1 || y > biggestY + 1 || y < smallestY - 1) {
			return false;
		}
		return true;
	}
}

int GameManager::checkNeighbor(Tile** map, const int& x, const int& y, std::queue<Tile*>& queue, std::unordered_map<std::string, Tile*>& memoizationMap)
{
	if (x < 0 || x >= (*m_Difficulty).m_Height || y < 0 || y >= (*m_Difficulty).m_Width) {
		return 0;
	}
	else {
		Tile* temp = &map[x][y];
		char buffer[50];
		sprintf_s(buffer, "%p", temp);

		if (memoizationMap.find(buffer) != memoizationMap.end()) {
			return 0;
		}

		if (((*temp).getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb) {
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
			return 0;
		}
	}
}

int GameManager::checkNeighborWithoutConstraint(Tile** map, const int& x, const int& y, std::queue<Tile*>& queue, std::unordered_map<std::string, Tile*>& memoizationMap)
{
	if (x < 0 || x >= (*m_Difficulty).m_Height || y < 0 || y >= (*m_Difficulty).m_Width) {
		return 0;
	}
	else {
		Tile* temp = &map[x][y];
		char buffer[50];
		sprintf_s(buffer, "%p", temp);

		if (memoizationMap.find(buffer) != memoizationMap.end()) {
			return 0;
		}

		if (((*temp).getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb) {

			(*temp).setGraphics(Rendering::getTextureFromKey("Uncovered"));
			(*temp).setBitmaskValue(TileBitMask::Uncovered, false);
			(*temp).setBitmaskValue(TileBitMask::Covered, true);
			return 1;
		}
		else {
			if (((*temp).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag) {
				(*temp).setBitmaskValue(TileBitMask::Flag, true);
			}

			memoizationMap.insert(std::make_pair(buffer, &(*temp)));
			queue.push(&(*temp));
			return 0;
		}
	}
}

void GameManager::showMap(Tile** map, Tile* current)
{
	std::unordered_map<std::string, Tile*> memoizationMap;
	std::queue<Tile*> neighbors;

	neighbors.push(&(*current));

	char buffer[50];
	sprintf_s(buffer, "%p", current);

	memoizationMap.insert(std::make_pair(buffer, &(*current)));

	while (!neighbors.empty()) {

		current = neighbors.front();
		int x = (*current).getX();
		int y = (*current).getY();

		int value =
			checkNeighborWithoutConstraint(map, x + 1, y, neighbors, memoizationMap) +
			checkNeighborWithoutConstraint(map, x - 1, y, neighbors, memoizationMap) +
			checkNeighborWithoutConstraint(map, x, y + 1, neighbors, memoizationMap) +
			checkNeighborWithoutConstraint(map, x, y - 1, neighbors, memoizationMap) +
			checkNeighborWithoutConstraint(map, x + 1, y + 1, neighbors, memoizationMap) +
			checkNeighborWithoutConstraint(map, x - 1, y + 1, neighbors, memoizationMap) +
			checkNeighborWithoutConstraint(map, x + 1, y - 1, neighbors, memoizationMap) +
			checkNeighborWithoutConstraint(map, x - 1, y - 1, neighbors, memoizationMap);

		if (value > 0) {
			(*current).setBitmaskValue(TileBitMask::Numbered | TileBitMask::Uncovered, false);
			(*current).setBitmaskValue(TileBitMask::Empty | TileBitMask::Covered, true);
			(*current).setValue(value);
		}
		else {
			(*current).setBitmaskValue(TileBitMask::Uncovered, false);
			(*current).setBitmaskValue(TileBitMask::Covered, true);
		}

		(*current).setGraphics(Rendering::getTextureFromKey("Uncovered"));
		neighbors.pop();
	}

	memoizationMap.clear();
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

void GameManager::doFlagCheck(Tile* current)
{
	if (((*current).getBitmaskValue() & TileBitMask::Uncovered) == TileBitMask::Uncovered) {
		return;
	}
	else {
		bool hasFlagMask = (((*current).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag);

		if (!canPlaceFlag()) {

			if (hasFlagMask) {

				(*current).setBitmaskValue(TileBitMask::Empty, false);
				(*current).setBitmaskValue(TileBitMask::Flag, true);
				removeOrAddFlagFromCount(false);
			}
		}
		else {

			(*current).setBitmaskValue(TileBitMask::Empty, !hasFlagMask);
			(*current).setBitmaskValue(TileBitMask::Flag, hasFlagMask);
			removeOrAddFlagFromCount(!hasFlagMask);
		}
	}
}

void GameManager::uncoverTile(Tile** map, Tile* current)
{
	int isValidMove =
		(((*current).getBitmaskValue() & TileBitMask::Uncovered) == TileBitMask::Uncovered) +
		(((*current).getBitmaskValue() & TileBitMask::Flag) == TileBitMask::Flag) +
		(((*current).getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb);

	if (isValidMove > 0) {
		if (isValidMove == 1 && ((*current).getBitmaskValue() & TileBitMask::Bomb) == TileBitMask::Bomb) {

			if (m_IsFirstMove) {
				TileMapGenerator::setBuilder(DBG_NEW BombTileBuilder(Rendering::getTextureFromKey("Covered")));
				TileMapGenerator::createBombMap((*m_Difficulty).m_Height, (*m_Difficulty).m_Width, 1);
				TileMapGenerator::destroyBuilder();

				(*current).setBitmaskValue(TileBitMask::Bomb, true);

				m_IsFirstMove = false;

				uncoverTile(map, current);
				return;
			}

			(*current).setBitmaskValue(TileBitMask::Uncovered, false);
			(*current).setBitmaskValue(TileBitMask::Covered, true);

			showMap(map, current);

			(*current).setGraphics(Rendering::getTextureFromKey("Hit"));
		}
		return;
	}
	else {
		m_IsFirstMove = false;

		std::unordered_map<std::string, Tile*> memoizationMap;
		std::unordered_map<std::string, Tile*> edgeLookup;
		std::queue<Tile*> neighbors;

		neighbors.push(&(*current));

		char buffer[50];
		sprintf_s(buffer, "%p", current);

		memoizationMap.insert(std::make_pair(buffer, &(*current)));

		while (!neighbors.empty()) {

			current = neighbors.front();
			int x = (*current).getX();
			int y = (*current).getY();

			if (!isInsideBounds(map, x, y, edgeLookup)) {
				neighbors.pop();
				continue;
			}

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
				(*current).setBitmaskValue(TileBitMask::Numbered | TileBitMask::Uncovered, false);
				(*current).setBitmaskValue(TileBitMask::Empty | TileBitMask::Covered, true);
				(*current).setValue(value);

				if (edgeLookup.empty()) {
					(*current).setGraphics(Rendering::getTextureFromKey("Uncovered"));
					break;
				}
			}
			else {
				(*current).setBitmaskValue(TileBitMask::Uncovered, false);
				(*current).setBitmaskValue(TileBitMask::Covered, true);

				sprintf_s(buffer, "%p", current);
				edgeLookup.insert(std::make_pair(buffer, current));
			}

			(*current).setGraphics(Rendering::getTextureFromKey("Uncovered"));
			neighbors.pop();
		}

		memoizationMap.clear();
	}
}

void GameManager::setIsRunning(const bool& value)
{
	m_IsRunning = value;
}
