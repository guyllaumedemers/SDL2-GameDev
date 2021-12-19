#include "InputManager.h"

void InputManager::getInputEvent(SDL_Event& myEvent)
{
	switch (myEvent.type)
	{
	case SDL_QUIT:
		GameManager::setIsRunning(false);
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (myEvent.button.button == SDL_BUTTON_LEFT) {
			int x = 0;
			int y = 0;

			SDL_GetMouseState(&x, &y);
			GameManager::uncoverTile(TileMapGenerator::getMap(), x, y);
		}
		else if (myEvent.button.button == SDL_BUTTON_RIGHT) {
			int x = 0;
			int y = 0;

			SDL_GetMouseState(&x, &y);
			GameManager::doFlagCheck(TileMapGenerator::getMap(), x, y);
		}
		break;
	}
}
