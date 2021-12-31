#pragma once
#define SDL_MAIN_HANDLED
#include "GameManager.h"

int main(int argc, char* argv[]){
	std:srand(time(NULL));
	return GameManager::onExecute();
}
