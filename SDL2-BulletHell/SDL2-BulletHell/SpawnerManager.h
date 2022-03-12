#pragma once
#include <vector>
#include "Spawner.h"
#include "Level.h"

using namespace std;
class SpawnerManager
{
private:

	//FIELDS

	static vector<Spawner*> spawners;

	//SPAWNER_LOGIC

	static Spawner* getSpawner();

	static void discard();

public:

	//GAME_LOGIC

	static void create(Level*);

	static void update();

	static void render(SDL_Renderer*);
};

