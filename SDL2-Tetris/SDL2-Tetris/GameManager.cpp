#include "GameManager.h"
#include "Debugger.h"
#include "InputManager.h"
#include "TileMapManager.h"

#define TILE_SIZE 20
#define ROWS 24
#define COLS 10

//FIELDS

bool GameManager::isRunning = true;

Window* GameManager::window = nullptr;

Renderer* GameManager::ren = nullptr;

//APP_LOGIC

void GameManager::initialize()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_Log("ERROR::SDL_INIT::FAILED : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	int width = TILE_SIZE * COLS;
	int height = TILE_SIZE * ROWS;

	window = DBG_NEW Window(height, width);
	ren = DBG_NEW Renderer(window);
	TileMapManager::create(ROWS, COLS);
}

void GameManager::getInputs()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event) > 0) { InputManager::processEvent(_event); }
}

void GameManager::runGameLogic()
{
	TileMapManager::update();
}

void GameManager::renderFrame()
{
	SDL_Renderer* temp = ren->getRenderer();
	
	SDL_RenderClear(temp);
	SDL_SetRenderDrawColor(temp, 0, 0, 0, 255);

	TileMapManager::render(temp);

	SDL_RenderPresent(temp);
}

void GameManager::clear()
{
	TileMapManager::clear(ROWS);
	delete window;
	window = nullptr;
	delete ren;
	ren = nullptr;
}

//GAME_LOGIC

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

void GameManager::setIsRunning(bool value)
{
	isRunning = value;
}
