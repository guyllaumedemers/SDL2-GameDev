#pragma once
#include "IDanmaku.h"

using namespace std;
class Spawner
{
private:

	//FIELDS

	IDanmaku* danmaku;

	//CONSTRUCTOR

	Spawner();

	~Spawner();

public:

	//SPAWNER_LOGIC

	void create(IDanmaku*);

	void update();
};

