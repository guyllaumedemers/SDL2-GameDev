#include "Ring.h"
#include "Bullet.h"
#include <iostream>

const int Ring::min_bullet = 3;

//CONSTRUCTOR

Ring::Ring(const Vector2d& location, int nb_bullets, double force_multiplier, double center_offset, double seed_angle, double angular_velocity)
{
	double angle = (360 / max(min_bullet, nb_bullets)) + seed_angle;
	double rad = (M_PI / 180) * angle;

	for (int i = 0; i < nb_bullets; ++i) {
		double x_offset = location.X() + center_offset * cos(rad);
		double y_offset = location.Y() + center_offset * sin(rad);
		Vector2d location_offset = Vector2d(x_offset, y_offset);
		Vector2d force = Vector2d(cos(rad), sin(rad));
		Vector2d::mul(force, force_multiplier);
		Bullet* bullet = DBG_NEW Bullet(location_offset, force, angular_velocity);
		add(bullet);

		rad += rad;
	}
}

Ring::~Ring() {}
