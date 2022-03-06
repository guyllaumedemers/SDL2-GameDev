#pragma once
#include "GameManager.h"
#include <time.h>
#include "Ring.h"

int main(int argv, char* argc[]) {
	srand(time(NULL));
	return GameManager::onExecute();
}