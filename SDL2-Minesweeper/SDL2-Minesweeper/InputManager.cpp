#include "InputManager.h"
#include "GameManager.h"

void InputManager::getInputEvent(SDL_Event& myEvent)
{
	switch (myEvent.type)
	{
	case SDL_QUIT:
		GameManager::setIsRunning(false);
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (myEvent.button.button == SDL_BUTTON_LEFT) {

		}
		else if (myEvent.button.button == SDL_BUTTON_RIGHT) {

		}
		break;
	}
}

void InputManager::getMouseClickPos(unsigned short int &x, unsigned short int& y)
{

}
