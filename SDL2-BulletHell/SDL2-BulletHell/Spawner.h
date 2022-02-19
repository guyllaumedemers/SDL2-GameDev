#pragma once
#include "IDanmaku.h"
#include "Timer.h"

using namespace std;
class Spawner
{
private:

	//FIELDS

	IDanmaku* danmaku = nullptr;

	Timer* spawnRate = nullptr;

public:

	//CONSTRUCTOR

	Spawner(IDanmaku*);

	~Spawner();

	//SPAWNER_LOGIC

	void create();

	void update();
};

