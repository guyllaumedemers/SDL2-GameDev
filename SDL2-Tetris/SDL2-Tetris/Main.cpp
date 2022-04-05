#pragma once
#include "GameManager.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
	srand(time(NULL));
	return GameManager::onExecute();
}