#include "GameManager.h"
#include <iostream>
#include "BulletManager.h"
#include "FullCirclePattern.h"
#include "Timer.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

bool GameManager::isRunning = true;

Window* GameManager::window = nullptr;

Rendering* GameManager::ren = nullptr;

int GameManager::onExecute()
{
	initialize();
	BulletManager::factoryMethod(new FullCirclePattern(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	Timer frame_capping(std::chrono::milliseconds{ 16 });
	while (isRunning) {
		getInputs();
		runGameLogic();
		renderFrame();
		while (!frame_capping.hasFinished()) {}
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

	window = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	ren = new Rendering(window);
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
	BulletManager::update();
}

void GameManager::renderFrame()
{
	SDL_Renderer* temp = ren->getRenderer();

	SDL_SetRenderDrawColor(temp, 0, 0, 0, 255);
	SDL_RenderClear(temp);

	SDL_SetRenderDrawColor(temp, 255, 0, 0, 255);
	BulletManager::print(temp);

	SDL_RenderPresent(temp);
}

void GameManager::clear()
{
	SDL_Quit();
}