#include "FullCirclePattern.h"

int FullCirclePattern::nb_bullets = 360;

std::vector<Bullet> FullCirclePattern::create(int x, int y)
{
	std::vector<Bullet> bullets;
	for (int i = 0; i < nb_bullets; ++i) {
		Bullet b(i, x, y);
		bullets.push_back(b);
	}
	return bullets;
}
