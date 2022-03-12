#include "SpawnerManager.h"
#include "LevelManager.h"

vector<Spawner*> SpawnerManager::spawners;

//SPAWNER_LOGIC

void SpawnerManager::getSpawners(Level* level)
{
	spawners.clear();
	spawners = level->create();
}

Spawner* SpawnerManager::getSpawner()
{
	if (!spawners.empty()) return spawners.front();
	else return nullptr;
}

void SpawnerManager::discardFront()
{
	if (!spawners.empty()) spawners.erase(spawners.begin());
}

//GAME_LOGIC

void SpawnerManager::create(Level* level)
{
	//TODO Create and fill the spawner collection from the level args
	getSpawners(level);

	//TODO Spawners will have to be added following specific timestamps

	//TODO Spawners needs to be updated on in a way that wont block the main thread

	//TODO each Spawners needs to handle his own sets of bullets which imply that their update is handle on the same thread that will update spawners
}

void SpawnerManager::update()
{
	for (auto& it : spawners) it->update();
}

void SpawnerManager::render(SDL_Renderer* ren)
{
	for (auto& it : spawners) it->render(ren);
}
