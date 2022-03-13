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
	ThreadManager::workers->push_task([&] {
		spawners.clear();
		spawners = level->create();
		});
	ThreadManager::workers->wait_for_tasks();
	for (auto& it : spawners) {
		it->create();
	}
}

void SpawnerManager::update()
{
	for (auto& it : spawners) {
		ThreadManager::workers->push_task([&] {it->update(); });
	}
	ThreadManager::workers->wait_for_tasks();
}

void SpawnerManager::render(SDL_Renderer* ren)
{
	for (auto& it : spawners) {
		ThreadManager::workers->push_task([&] {it->render(ren); });
	}
	ThreadManager::workers->wait_for_tasks();
}
