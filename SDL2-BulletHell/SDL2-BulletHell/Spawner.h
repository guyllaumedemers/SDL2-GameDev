#pragma once
#include <SDL.h>
#include "IDanmaku.h"
#include "Timer.h"
#include "Vector2d.h"

class Spawner
{
private:

	//FIELDS

	IDanmaku* danmaku = nullptr;

	Timer* spawnRate = nullptr;

	Vector2d location;

public:

	//CONSTRUCTOR

	Spawner(IDanmaku*, Timer*, const Vector2d&);

	~Spawner();

	//SPAWNER_LOGIC

	void create();

	void update();

	void render(SDL_Renderer*);

	void die();
};

