#include <iostream>
#include "GameManager.h"

int main(int argc, char* argv[]) {
	srand(time(NULL));
	return GameManager::onExecute();
}