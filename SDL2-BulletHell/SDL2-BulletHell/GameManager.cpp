#include "GameManager.h"
#include "TextureManager.h"
#include "LevelManager.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

bool GameManager::isRunning = true;

Window* GameManager::window = nullptr;

Rendering* GameManager::ren = nullptr;

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

void GameManager::initialize()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Log("ERROR::SDL_INIT::FAILED : %s", SDL_GetError());
		exit(1);
	}

	window = DBG_NEW Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	ren = DBG_NEW Rendering(window);

	TextureManager::create(ren->getRenderer());
	LevelManager::create();
}

void GameManager::getInputs()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event) > 0) {
		switch (_event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
		}
	}
}

void GameManager::runGameLogic()
{
}

void GameManager::renderFrame()
{
	SDL_Renderer* _ren = ren->getRenderer();

	SDL_SetRenderDrawColor(_ren, 0, 0, 0, 255);
	SDL_RenderClear(_ren);

	SDL_RenderPresent(_ren);
}

void GameManager::clear()
{
	TextureManager::destroy();
	SDL_Quit();
}