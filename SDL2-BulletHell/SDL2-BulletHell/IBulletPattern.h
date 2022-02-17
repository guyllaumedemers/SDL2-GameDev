#pragma once
#include <vector>
#include "Bullet.h"

class IBulletPattern
{
public:
	virtual ~IBulletPattern() {};

	virtual std::vector<Bullet> create(int x, int y) = 0;
};

