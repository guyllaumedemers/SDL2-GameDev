#pragma once
#include <SDL.h>
#include "IBulletPattern.h"

class BulletManager
{
public:
	static void factoryMethod(IBulletPattern* pattern, int x, int y);

	static void update();

	static void print(SDL_Renderer* ren);
private:
	static std::vector<Bullet> bullets;
};

