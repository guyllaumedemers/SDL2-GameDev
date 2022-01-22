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
			Tile* clicked = GameManager::getTileAtPositionClicked(map, x, y);
			if (clicked == nullptr) {
				return;
			}
			GameManager::updateTileAtPositionClicked(map, clicked);
		}
		else if (myEvent.button.button == SDL_BUTTON_RIGHT) {
			int x = 0;
			int y = 0;

			SDL_GetMouseState(&x, &y);
			Tile* clicked = GameManager::getTileAtPositionClicked(map, x, y);
			if (clicked == nullptr) {
				return;
			}
			GameManager::updateFlagAtPositionClicked(clicked);
		}
		break;
	case SDL_KEYDOWN:
		switch (myEvent.key.keysym.scancode)
		{
		case SDL_SCANCODE_F1:
			GameManager::startNewSession(Mode::beginner);
			break;
		case SDL_SCANCODE_F2:
			GameManager::startNewSession(Mode::medium);
			break;
		case SDL_SCANCODE_F3:
			GameManager::startNewSession(Mode::hard);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
