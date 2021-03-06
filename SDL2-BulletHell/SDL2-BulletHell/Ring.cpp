#include "Ring.h"

const int Ring::min_bullet = 3;

//CONSTRUCTOR

Ring::Ring(const Vector2d& displacement, int nb_bullets, double force_magnitude, double center_offset, double seed_angle, double angular_acceleration, SDL_Texture* shared_texture)
{
	double angle = (360 / max(min_bullet, nb_bullets)) + seed_angle;
	double rad = (M_PI / 180) * angle;

	double angle_increment = angle;
	double radian = rad;

	for (int i = 0; i < nb_bullets; ++i) {

		double x_offset = displacement.X() + center_offset * cos(radian);
		double y_offset = displacement.Y() + center_offset * sin(radian);
		Vector2d location_offset = Vector2d(x_offset, y_offset);
		Bullet* bullet = DBG_NEW Bullet(location_offset, angle_increment, angular_acceleration, force_magnitude, 0.0f, shared_texture);
		add(bullet);

		radian += rad;
		angle_increment += angle;
	}
}

Ring::~Ring() {}
