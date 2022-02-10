#pragma once
#include <vector>
#include <cmath>
#include "Bullet.h"
#include "IBulletPattern.h"

class BulletManager
{
public:
	void factoryMethod(IBulletPattern* pattern);

	void update();
private:
	std::vector<Bullet> bullets;

	static double forceApplied;
};

