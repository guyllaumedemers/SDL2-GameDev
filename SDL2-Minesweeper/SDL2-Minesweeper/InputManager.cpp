#include "InputManager.h"

void InputManager::getInputEvent(SDL_Event& myEvent, Tile** map)
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
			GameManager::uncoverTile(map, &map[y / Tile::height][x / Tile::width]);
		}
		else if (myEvent.button.button == SDL_BUTTON_RIGHT) {
			int x = 0;
			int y = 0;

			SDL_GetMouseState(&x, &y);
			GameManager::doFlagCheck(&map[y / Tile::height][x / Tile::width]);
		}
		break;
	}
}
