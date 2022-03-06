#include "LevelManager.h"

vector<Level*> LevelManager::levels;

//LEVEL_MANAGER_LOGIC

void LevelManager::create()
{
	//TODO Load levels from file
}

void LevelManager::destroy()
{
	for (auto& it : levels) {
		delete it;
		it = nullptr;
	}
	levels.clear();
}

//GAME_LOGIC

Level* LevelManager::getLevel(int id)
{
	if (id >= 0 && id < levels.size()) return levels[id];
	else return nullptr;
}
