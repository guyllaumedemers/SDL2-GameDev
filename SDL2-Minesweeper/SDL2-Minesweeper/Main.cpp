#pragma once
#define SDL_MAIN_HANDLED
#include "GameManager.h"
#include "Debugger.h"
#include "MinesweeperConfig.h"

int main(int argc, char* argv[]) {
	srand(time(NULL));
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return GameManager::onExecute();
}
