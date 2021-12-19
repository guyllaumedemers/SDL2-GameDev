#include "GameManager.h"
#include "ImageLoader.h"
#include "InputManager.h"
#include "UIController.h"
#include "TileMapGenerator.h"
#include "Rendering.h"
#include "Difficulty.h"
#include <iostream>
#include <string>

#define GRIDCOLUMNS 16
#define GRIDROWS 16

bool GameManager::m_IsRunning = true;

void GameManager::initializeGame()
{
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Log("Cannot initalize SDL : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	Rendering::initialize();
	Rendering::setWindowSize(GRIDCOLUMNS, GRIDROWS);
	Difficulty dif(Mode::medium);
	TileMapGenerator::createMap(Rendering::m_Window, Rendering::m_Renderer, dif.m_Width, dif.m_Height);
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
	Rendering::update(TileMapGenerator::getMap(), GRIDROWS, GRIDCOLUMNS);
}

void GameManager::clear()
{
	TileMapGenerator::clear();
	Rendering::clear();
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

void GameManager::setIsRunning(const bool& value)
{
	m_IsRunning = value;
}
