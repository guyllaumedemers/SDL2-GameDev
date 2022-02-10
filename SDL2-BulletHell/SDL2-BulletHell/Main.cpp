#pragma once
#include "GameManager.h"

int main(int argv, char* argc[]) {
	srand(time(NULL));
	return GameManager::onExecute();
}