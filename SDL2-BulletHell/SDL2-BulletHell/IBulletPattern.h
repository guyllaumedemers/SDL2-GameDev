#pragma once
#include <vector>

class IBulletPattern
{
public:
	virtual std::vector<Bullet> create() = 0;
};

