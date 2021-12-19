#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <functional>
#include "ImageLoader.h"
#include "InputManager.h"
#include "UIController.h"
#include "TileMapGenerator.h"
#include "Rendering.h"
#include "Difficulty.h"
#include "Mode.h"
#include "Timer.h"

// Hint :	SDL_Surface is use for software rendering *CPU and is stored in system RAM which is less efficient than using the GPU
//			while SDL_Texture is use for hardware rendering *GPU and is store in the GPU Ram

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

public:

	static void setIsRunning(const bool& value);

	static void setDifficulty(Mode mode);

	static void doFlagCheck(Tile** map, const int& x, const int& y);

	static void updateFlagCount(const bool& value);

	static void uncoverTile(Tile** map, const int& x, const int& y);

	static int onExecute();
};

