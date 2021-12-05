#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "GameManager.h"

int main(int argc, char* argv[]) {

	return GameManager::onExecute();
}
