#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <unordered_map>
#include "ImageLoader.h"
#include "InputManager.h"
#include "UIController.h"
#include "Tile.h"
#include "TileMapGenerator.h"
#include "Rendering.h"
#include "Difficulty.h"
#include "Mode.h"
#include "Timer.h"

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

	static int checkNeighbor(Tile** map, const int& x, const int& y, std::queue<Tile*>& queue, std::unordered_map<std::string, Tile*>& memoizationMap);

public:

	static void setIsRunning(const bool& value);

	static void setDifficulty(Mode mode);

	static void doFlagCheck(Tile** map, const int& x, const int& y);

	static void removeOrAddFlagFromCount(const bool& value);

	static void uncoverTile(Tile** map, const int& x, const int& y);

	static int onExecute();
};

