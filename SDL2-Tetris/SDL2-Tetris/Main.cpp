#pragma once
#include "GameManager.h"
#include <time.h>

int main(int argc, char* argv[]) {
	srand(time(NULL));
	return GameManager::onExecute();
}