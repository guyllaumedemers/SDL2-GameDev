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

	bool isAlive = false;

public:

	//CONSTRUCTOR

	Spawner(IDanmaku*, Timer*);

	~Spawner();

	//SPAWNER_LOGIC

	void create();

	void update();

	void die();
};

