#include "GameManager.h"
#include "Window.h"
#include "Rendering.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

bool GameManager::isRunning = true;

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
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "ERROR::SDL_INIT::FAILED" << std::endl;
		exit(1);
	}

	Window* window = Window::getInstance(SCREEN_WIDTH, SCREEN_HEIGHT);
	Rendering* ren = Rendering::getInstance(window->getWindow());
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
	SDL_SetRenderDrawColor(Rendering::getInstance(nullptr)->getRenderer(), 0, 0, 0, 255);
	SDL_RenderClear(Rendering::getInstance(nullptr)->getRenderer());

	//render here

	SDL_RenderPresent(Rendering::getInstance(nullptr)->getRenderer());
}

void GameManager::clear()
{
	SDL_Quit();
}