#include "InputManager.h"

void InputManager::getInputs()
{
	SDL_Event myEvent;
	while (SDL_PollEvent(&myEvent) > 0) {
		switch (myEvent.type)
		{
		case SDL_QUIT:
			GameManager::setIsRunning(false);
			break;
		case SDLK_SPACE:
			/// <summary>
			/// flip shape
			/// </summary>
			break;
		case SDLK_a:
			/// <summary>
			/// move left
			/// </summary>
			break;
		case SDLK_s:
			/// <summary>
			/// drop down
			/// </summary>
			break;
		case SDLK_d:
			/// <summary>
			/// move right
			/// </summary>
			break;
		default:
			break;
		}
	}
}
