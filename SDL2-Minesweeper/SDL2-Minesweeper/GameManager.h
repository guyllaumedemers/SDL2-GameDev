#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>

#include "Difficulty.h"
#include "Rendering.h"
#include "InputManager.h"

class GameManager
{
private:

	static bool m_IsRunning;

	static int m_FlagsLeft;

	static Difficulty* m_Difficulty;

	static void initializeGame();

	static void getInputEvents();

	static void runGameLogic();

	static void renderFrame();

	static void clear();

	static bool canPlaceFlag();

	static int checkNeighbor(Tile** map, const int x, const int& y, std::queue<Tile*>& queue, std::unordered_map<std::string, Tile*>& memoizationMap);

public:

	static void setIsRunning(const bool& value);

	static void setDifficulty(Mode mode);

	static void doFlagCheck(Tile* tile);

	static void removeOrAddFlagFromCount(const bool& value);

	static void uncoverTile(Tile** map, Tile* currentTile);

	static int onExecute();
};

