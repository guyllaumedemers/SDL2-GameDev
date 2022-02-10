#include "GameManager.h"
#include "Window.h"
#include "Rendering.h"
#include "InputManager.h"

bool GameManager::isRunning = true;

SDL_Window* GameManager::window = nullptr;

SDL_Renderer* GameManager::renderer = nullptr;

#define BOARD_HEIGHT 24
#define BOARD_WIDTH 10

#define TILE_SIZE 30

void GameManager::initialize()
{
	SDL_SetMainReady();

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {

		SDL_Log("Cannot initialize SDL_lib : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	window = Window::getInstance(BOARD_WIDTH * TILE_SIZE, BOARD_HEIGHT * TILE_SIZE)->getWindow();
	renderer = Rendering::getInstance(window)->getRenderer();
}

void GameManager::getInputs()
{
	InputManager::getInputs();
}

void GameManager::runGameLogic()
{
	//check for collision
	//update tetrominoe position in the tilemap
	//check for a complete row
}

void GameManager::renderFrame()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	//render frame here

	SDL_RenderPresent(renderer);
}

void GameManager::clear()
{
}

void GameManager::setIsRunning(const bool& value)
{
	isRunning = value;
}

int GameManager::onExecute()
{
	initialize();
	while (isRunning) {
		getInputs();
		runGameLogic();
		renderFrame();
	}
	clear();
	return 0;
}
