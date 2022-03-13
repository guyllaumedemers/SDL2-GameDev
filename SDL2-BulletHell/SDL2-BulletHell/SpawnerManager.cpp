#include "SpawnerManager.h"
#include "LevelManager.h"
#include "ThreadManager.h"

vector<Spawner*> SpawnerManager::spawners;

//SPAWNER_LOGIC

Spawner* SpawnerManager::getSpawner()
{
	if (!spawners.empty()) return spawners.front();
	else return nullptr;
}

void SpawnerManager::discard()
{
	if (!spawners.empty()) spawners.erase(spawners.begin());
}

//GAME_LOGIC

void SpawnerManager::create(Level* level)
{
	spawners.clear();
	spawners = level->create();

	for (auto& it : spawners) {
		it->create();
	}
}

void SpawnerManager::update()
{
	for (auto& it : spawners) {
		it->update();
	}
}

void SpawnerManager::render(SDL_Renderer* ren)
{
	for (auto& it : spawners) {
		it->render(ren);
	}
}
