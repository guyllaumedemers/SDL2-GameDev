#pragma once
#include "Level.h"

using namespace std;
class LevelManager
{
private:

	//FIELDS

	static vector<Level*> levels;

public:

	//LEVEL_MANAGER_LOGIC

	static void create();

	static void destroy();

	//GAME_LOGIC

	static Level* getLevel(int id);
};

