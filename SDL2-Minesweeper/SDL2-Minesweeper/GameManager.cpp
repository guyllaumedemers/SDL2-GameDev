#include "GameManager.h"
#include "ImageLoader.h"
#include "InputManager.h"
#include "UIController.h"
#include "TileMapGenerator.h"
#include "Rendering.h"
#include "Difficulty.h"
#include <iostream>
#include <string>

bool GameManager::m_IsRunning = true;

int GameManager::m_FlagsLeft = 0;

Difficulty* GameManager::m_Difficulty;

void GameManager::initializeGame()
{
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Log("Cannot initalize SDL : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	setDifficulty(Mode::beginner);

	if (m_Difficulty == nullptr) {
		SDL_Log("Difficulty was not initialize : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	m_FlagsLeft = (*m_Difficulty).m_Flags;

	Rendering::initialize();
	Rendering::setWindowSize((*m_Difficulty).m_Width, (*m_Difficulty).m_Height);

	TileMapGenerator::createMap(Rendering::m_Window, Rendering::m_Renderer, (*m_Difficulty).m_Width, (*m_Difficulty).m_Height);
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
	Rendering::update(TileMapGenerator::getMap(), (*m_Difficulty).m_Width, (*m_Difficulty).m_Height);
}

void GameManager::clear()
{
	TileMapGenerator::clear();
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

void GameManager::setIsRunning(const bool& value)
{
	m_IsRunning = value;
}
