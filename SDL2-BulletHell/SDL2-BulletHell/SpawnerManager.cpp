#include "SpawnerManager.h"
#include "LevelManager.h"
#include <iostream>

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
	//auto start = Timer::setTimestamp();
	spawners.clear();
	spawners = level->create();
	for (const auto& it : spawners) it->create();
	//Timer::printExecutionTime(start);
}

void SpawnerManager::update()
{
	//auto start = Timer::setTimestamp();
	for (auto& it : spawners) it->update();
	//Timer::printExecutionTime(start);
}

void SpawnerManager::render(SDL_Renderer* ren)
{
	//auto start = Timer::setTimestamp();
	for (auto& it : spawners) it->render(ren);
	//Timer::printExecutionTime(start);
}
