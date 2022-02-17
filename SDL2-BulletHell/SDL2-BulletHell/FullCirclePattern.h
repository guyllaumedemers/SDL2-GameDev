#pragma once
#include "IBulletPattern.h"

class FullCirclePattern : virtual public IBulletPattern
{
private :
	static int nb_bullets;

public:
	virtual ~FullCirclePattern() {};

	virtual std::vector<Bullet> create(int x, int y);
};

