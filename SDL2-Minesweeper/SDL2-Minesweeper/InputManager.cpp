#include "InputManager.h"
#include "GameManager.h"
#include "Rendering.h"

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
			uncoverTile(x, y);

			Rendering::updateTileGraphic(x, y);
		}
		else if (myEvent.button.button == SDL_BUTTON_RIGHT) {
			int x = 0;
			int y = 0;

			SDL_GetMouseState(&x, &y);
			doFlagCheck(x, y);

			Rendering::updateTileGraphic(x, y);
		}
		break;
	}
}

void InputManager::doFlagCheck(const int& x, const int& y)
{
	TileMapGenerator::doFlagCheck(x, y);
}

void InputManager::uncoverTile(const int& x, const int& y)
{
	TileMapGenerator::uncoverTile(x, y);
}
