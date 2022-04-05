#include "InputManager.h"
#include "GameManager.h"

void InputManager::processEvent(SDL_Event& myEvent)
{
	switch (myEvent.type)
	{
	case SDL_QUIT:
		GameManager::setIsRunning(false);
		break;
	case SDL_KEYUP:
		switch (myEvent.key.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			break;
		case SDL_SCANCODE_A:
			break;
		case SDL_SCANCODE_S:
			break;
		case SDL_SCANCODE_D:
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
