#include "Ring.h"
#include "Bullet.h"

const int Ring::min_bullet = 3;

//CONSTRUCTOR

Ring::Ring(const Vector2d& location, int nb_bullets, double force_multiplier, double center_offset, double seed_angle, double angular_acceleration, SDL_Texture* shared_texture)
{
	double angle = (360 / max(min_bullet, nb_bullets)) + seed_angle;
	double rad = (M_PI / 180) * angle;

	double radian = rad;
	double angle_increment = angle;

	for (int i = 0; i < nb_bullets; ++i) {

		double x_offset = location.X() + center_offset * cos(radian);
		double y_offset = location.Y() + center_offset * sin(radian);
		Vector2d location_offset = Vector2d(x_offset, y_offset);
		Bullet* bullet = DBG_NEW Bullet(location_offset, angle_increment, angular_acceleration, force_multiplier, shared_texture);
		add(bullet);

		radian += rad;
		angle_increment += angle;
	}
}

Ring::~Ring() {}
