#include "GameManager.h"

bool GameManager::m_IsRunning = true;

bool GameManager::m_IsFirstInitialize = true;

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

	startNewSession(Mode::hard);
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
	Rendering::update(
		TileMapGenerator::getMap(),
		Window::getPanels(),
		Window::getPlayAreaPanel(),
		(*m_Difficulty).m_Height,
		(*m_Difficulty).m_Width
	);
}

void GameManager::clear()
{
	TileMapGenerator::clear((*m_Difficulty).m_Height);
	Rendering::clear();
	delete m_Difficulty;
	m_Difficulty = nullptr;
	SDL_Quit();
}

void GameManager::setIsRunning(const bool& value)
{
	m_IsRunning = value;
}

Tile* GameManager::getTileAtPositionClicked(Tile** map, const int& screenPosX, const int& screenPosY)
{
	int x = (*(*Window::getPlayAreaPanel()).getRect()).x;
	int y = (*(*Window::getPlayAreaPanel()).getRect()).y;
	return &map[(screenPosY - y) / Tile::height][(screenPosX - x) / Tile::width];
}

Tile* GameManager::updateTileAtPositionClicked(Tile** map, Tile* clicked)
{
	int isInvalid = isInvalidMove(clicked);

	if (isInvalid > 0) {
		processInvalidMove(map, clicked, isInvalid);
		return nullptr;
	}
	else {
		if (m_IsFirstMove) {
			m_IsFirstMove = false;
		}
		processValidMoveInsideBoundaries(map, clicked);
	}
	return nullptr;
}

Tile* GameManager::updateFlagAtPositionClicked(Tile* clicked)
{
	if (Util::checkBitMaskEquality(clicked, TileBitMask::Uncovered)) {
		return nullptr;
	}
	else {
		bool hasFlagMask = Util::checkBitMaskEquality(clicked, TileBitMask::Flag);
		bool canPlaceFlag = m_FlagsLeft > 0;

		if (!canPlaceFlag) {

			if (hasFlagMask) {

				(*clicked).removeBitMaskValue(TileBitMask::Flag);
				(*clicked).addBitMaskValue(TileBitMask::Empty);
				m_FlagsLeft += 1;
			}
		}
		else {
			if (hasFlagMask) {
				(*clicked).removeBitMaskValue(TileBitMask::Flag);
				(*clicked).addBitMaskValue(TileBitMask::Empty);
				m_FlagsLeft += 1;
			}
			else {
				(*clicked).removeBitMaskValue(TileBitMask::Empty);
				(*clicked).addBitMaskValue(TileBitMask::Flag);
				m_FlagsLeft -= 1;
			}
		}
	}
	return clicked;
}

void GameManager::startNewSession(const Mode& mode)
{
	clearGame();

	if ((m_Difficulty = new Difficulty(mode)) == nullptr) {
		SDL_Log("Difficulty was not initialize : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	int height = (*m_Difficulty).m_Height;
	int width = (*m_Difficulty).m_Width;
	int bombs = (*m_Difficulty).m_Bombs;
	int flags = (*m_Difficulty).m_Flags;

	m_FlagsLeft = flags;

	if (m_IsFirstInitialize) {
		Window::intializeWindowCTX(width * Tile::width, height * Tile::height);
		Rendering::initializeRenderingCTX(Window::getWindow());
		m_IsFirstInitialize = false;
	}
	else {
		Window::setWindowSize(width * Tile::width, height * Tile::height);
	}

	TileMapGenerator::setBuilder(DBG_NEW EmptyTileBuilder(Rendering::getTextureFromKey("Covered")));
	TileMapGenerator::createEmptyMap(height, width);

	TileMapGenerator::setBuilder(DBG_NEW BombTileBuilder(Rendering::getTextureFromKey("Covered")));
	TileMapGenerator::createBombMap(height, width, bombs);

	TileMapGenerator::destroyBuilder();
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

bool GameManager::isInvalidMove(Tile* tile)
{
	return
		Util::checkBitMaskEquality(tile, TileBitMask::Uncovered) +
		Util::checkBitMaskEquality(tile, TileBitMask::Flag) +
		Util::checkBitMaskEquality(tile, TileBitMask::Bomb);
}

bool GameManager::isBomb(Tile* tile, const int& isInvalid)
{
	return (isInvalid == 1) && Util::checkBitMaskEquality(tile, TileBitMask::Bomb | TileBitMask::Covered);
}

void GameManager::resetFirstMove()
{
	TileMapGenerator::updateBombOnFirstMove(Rendering::getTextureFromKey("Covered"), (*m_Difficulty).m_Height, (*m_Difficulty).m_Width, 1);
}

void GameManager::processInvalidMove(Tile** map, Tile* clicked, const int& isInvalid)
{
	if (m_IsFirstMove && isBomb(clicked, isInvalid)) {
		m_IsFirstMove = false;
		resetFirstMove();
		(*clicked).removeBitMaskValue(TileBitMask::Bomb);
		updateTileAtPositionClicked(map, clicked);
	}
	else if (!m_IsFirstMove && isBomb(clicked, isInvalid)) {
		processAllTiles(map, clicked);
		updateProcessedTileGraphic(clicked, "Hit");
	}
}

void GameManager::processValidMoveInsideBoundaries(Tile** map, Tile* clicked)
{
	std::unordered_map<std::string, Tile*> memoizationMap;
	std::unordered_map<std::string, Tile*> edgeLookup;
	std::queue<Tile*> neighbors;

	neighbors.push(&(*clicked));

	char buffer[50];
	sprintf_s(buffer, "%p", clicked);

	memoizationMap.insert(std::make_pair(buffer, &(*clicked)));

	while (!neighbors.empty()) {

		clicked = neighbors.front();

		if (!isInsideBounds(map, clicked, edgeLookup)) {
			neighbors.pop();
			continue;
		}

		int nbBombsNearBy = checkAllNeighbors(map, clicked, neighbors, memoizationMap);

		processValidMoveResult(clicked, nbBombsNearBy, edgeLookup, true);
		updateProcessedTileGraphic(clicked, "Uncovered");

		if (edgeLookup.empty()) {
			break;
		}
		memoizationMap.insert(std::make_pair(buffer, &(*clicked)));
		neighbors.pop();
	}
	memoizationMap.clear();
	edgeLookup.clear();
}

bool GameManager::isInsideBounds(Tile** map, Tile* current, std::unordered_map<std::string, Tile*>& edgeMap)
{
	if (edgeMap.empty()) {
		return true;
	}
	else {
		for (const auto& it : edgeMap) {

			int x = (*current).getX();
			int y = (*current).getY();

			int value =
				(x == (*it.second).getX() + 1 && y == (*it.second).getY()) +
				(x == (*it.second).getX() - 1 && y == (*it.second).getY()) +
				(x == (*it.second).getX() && y == (*it.second).getY() + 1) +
				(x == (*it.second).getX() && y == (*it.second).getY() - 1) +
				(x == (*it.second).getX() + 1 && y == (*it.second).getY() + 1) +
				(x == (*it.second).getX() - 1 && y == (*it.second).getY() + 1) +
				(x == (*it.second).getX() + 1 && y == (*it.second).getY() - 1) +
				(x == (*it.second).getX() - 1 && y == (*it.second).getY() - 1);

			if (value > 0) {
				return true;
			}
		}
		return false;
	}
}

int GameManager::checkAllNeighbors(Tile** map, Tile* clicked, std::queue<Tile*>& neighbors, std::unordered_map<std::string, Tile*>& memoizationMap)
{
	int x = (*clicked).getX();
	int y = (*clicked).getY();

	return
		checkNeighbor(map, x + 1, y, neighbors, memoizationMap) +
		checkNeighbor(map, x - 1, y, neighbors, memoizationMap) +
		checkNeighbor(map, x, y + 1, neighbors, memoizationMap) +
		checkNeighbor(map, x, y - 1, neighbors, memoizationMap) +
		checkNeighbor(map, x + 1, y + 1, neighbors, memoizationMap) +
		checkNeighbor(map, x - 1, y + 1, neighbors, memoizationMap) +
		checkNeighbor(map, x + 1, y - 1, neighbors, memoizationMap) +
		checkNeighbor(map, x - 1, y - 1, neighbors, memoizationMap);
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

		if (Util::checkBitMaskEquality(temp, TileBitMask::Bomb)) {
			return 1;
		}
		else {
			int isValidMove =
				Util::checkBitMaskEquality(temp, TileBitMask::Covered) +
				Util::checkBitMaskEquality(temp, TileBitMask::Empty);

			if (isValidMove > 1) {
				queue.push(&(*temp));
			}
			return 0;
		}
	}
}

void GameManager::processValidMoveResult(Tile* current, const int& result, std::unordered_map<std::string, Tile*>& edgeMap, const bool& isHandlingEdges)
{
	if (result > 0 && !isBomb(current, 1)) {

		(*current).addBitMaskValue(TileBitMask::Numbered | TileBitMask::Uncovered);
		(*current).removeBitMaskValue(TileBitMask::Empty | TileBitMask::Covered);

		if ((*current).getValue() < result) {

			(*current).setValue(result);
		}
	}
	else {

		(*current).removeBitMaskValue(TileBitMask::Covered);
		(*current).addBitMaskValue(TileBitMask::Uncovered);

		if (result == 0 && isHandlingEdges) {

			char buffer[50];
			sprintf_s(buffer, "%p", current);
			edgeMap.insert(std::make_pair(buffer, current));
		}
	}
}

void GameManager::updateProcessedTileGraphic(Tile* current, std::string key)
{
	(*current).setGraphics(Rendering::getTextureFromKey(key));
}

void GameManager::processAllTiles(Tile** map, Tile* clicked)
{
	std::unordered_map<std::string, Tile*> memoizationMap;
	std::queue<Tile*> neighbors;
	std::unordered_map<std::string, Tile*> placeholder;

	neighbors.push(&(*clicked));

	char buffer[50];
	sprintf_s(buffer, "%p", clicked);

	memoizationMap.insert(std::make_pair(buffer, &(*clicked)));

	while (!neighbors.empty()) {

		clicked = neighbors.front();
		int x = (*clicked).getX();
		int y = (*clicked).getY();

		int value = checkAllNeighborsWithoutConstraint(map, clicked, neighbors, memoizationMap);
		processValidMoveResult(clicked, value, placeholder, false);

		updateProcessedTileGraphic(clicked, "Uncovered");
		neighbors.pop();
	}
	memoizationMap.clear();
}

int GameManager::checkAllNeighborsWithoutConstraint(Tile** map, Tile* current, std::queue<Tile*>& neighbors, std::unordered_map<std::string, Tile*>& memoizationMap)
{
	int x = (*current).getX();
	int y = (*current).getY();

	return
		checkNeighborWithoutConstraint(map, x + 1, y, neighbors, memoizationMap) +
		checkNeighborWithoutConstraint(map, x - 1, y, neighbors, memoizationMap) +
		checkNeighborWithoutConstraint(map, x, y + 1, neighbors, memoizationMap) +
		checkNeighborWithoutConstraint(map, x, y - 1, neighbors, memoizationMap) +
		checkNeighborWithoutConstraint(map, x + 1, y + 1, neighbors, memoizationMap) +
		checkNeighborWithoutConstraint(map, x - 1, y + 1, neighbors, memoizationMap) +
		checkNeighborWithoutConstraint(map, x + 1, y - 1, neighbors, memoizationMap) +
		checkNeighborWithoutConstraint(map, x - 1, y - 1, neighbors, memoizationMap);
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

		if (Util::checkBitMaskEquality(temp, TileBitMask::Bomb)) {

			updateProcessedTileGraphic(temp, "Uncovered");
			(*temp).removeBitMaskValue(TileBitMask::Covered | TileBitMask::Flag);
			(*temp).addBitMaskValue(TileBitMask::Uncovered);
			return 1;
		}
		else {
			if (Util::checkBitMaskEquality(temp, TileBitMask::Flag)) {

				(*temp).removeBitMaskValue(TileBitMask::Flag);
			}
			memoizationMap.insert(std::make_pair(buffer, &(*temp)));
			queue.push(&(*temp));
			return 0;
		}
	}
}

void GameManager::clearGame()
{
	if (m_Difficulty != nullptr) {
		TileMapGenerator::clear((*m_Difficulty).m_Height);
		delete m_Difficulty;
		m_Difficulty = nullptr;
	}
}
