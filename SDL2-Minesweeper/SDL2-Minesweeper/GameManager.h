#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>

#include "Difficulty.h"
#include "Window.h"
#include "Rendering.h"
#include "InputManager.h"
#include "ISubject.h"

class GameManager
{
private:

	static bool m_IsRunning;

	static bool m_IsFirstInitialize;

	static int m_FlagsLeft;

	static bool m_IsFirstMove;

	static Difficulty* m_Difficulty;

	//APP_LOGIC

	static void initializeGame();

	static void getInputEvents();

	static void runGameLogic();

	static void renderFrame();

	static void clear();

	//GAME_LOGIC

	static bool isInvalidMove(Tile* tile);

	static bool isBomb(Tile* tile, const int& isValidMove);

	static void resetFirstMove();

	static void processInvalidMove(Tile** map, Tile* clicked, const int& isInvalid);

	static void processValidMoveInsideBoundaries(Tile** map, Tile* clicked);

	static bool isInsideBounds(Tile** map, Tile* current, std::unordered_map<std::string, Tile*>& edgeMap);

	static int checkAllNeighbors(Tile** map, Tile* current, std::queue<Tile*>& neighbors, std::unordered_map<std::string, Tile*>& memoizationMap);

	static int checkNeighbor(Tile** map, const int& x, const int& y, std::queue<Tile*>& queue, std::unordered_map<std::string, Tile*>& memoizationMap);

	static void processValidMoveResult(Tile* current, const int& result, std::unordered_map<std::string, Tile*>& edgeMap, const bool& isHandlingEdges);

	static void updateProcessedTileGraphic(Tile* current, std::string key);

	static void processAllTiles(Tile** map, Tile* clicked);

	static int checkAllNeighborsWithoutConstraint(Tile** map, Tile* current, std::queue<Tile*>& neighbors, std::unordered_map<std::string, Tile*>& memoizationMap);

	static int checkNeighborWithoutConstraint(Tile** map, const int& x, const int& y, std::queue<Tile*>& queue, std::unordered_map<std::string, Tile*>& memoizationMap);

	static void clearGame();

public:

	static void setIsRunning(const bool& value);

	static Tile* getTileAtPositionClicked(Tile** map, const int& screenPosX, const int& screenPosY);

	static Tile* updateTileAtPositionClicked(Tile** map, Tile* clicked);

	static Tile* updateFlagAtPositionClicked(Tile* clicked);

	static void startNewSession(const Mode& mode);

	static int onExecute();
};

