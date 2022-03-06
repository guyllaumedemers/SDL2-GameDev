#pragma once
#include "ILevelFactory.h"
#include <vector>
#include <string>

using namespace std;
struct Level
{
private:

	//FIELDS

	int id = 0;

	ILevelFactory* levelFactory = nullptr;

public:

	//CONSTRUCTOR

	Level(ILevelFactory*);

	~Level();

	//GAME_LOGIC

	vector<Spawner*> create();
};

