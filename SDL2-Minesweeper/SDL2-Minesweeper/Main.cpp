#pragma once
#define SDL_MAIN_HANDLED
#define _CRTDBG_MAP_ALLOC
#include <SDL.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "GameManager.h"

int main(int argc, char* argv[]) {
	std:srand(time(NULL));
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return GameManager::onExecute();
}
