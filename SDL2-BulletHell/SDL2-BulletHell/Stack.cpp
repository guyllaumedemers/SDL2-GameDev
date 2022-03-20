#include "Stack.h"

const int Stack::min_bullet = 1;

//CONSTRUCTOR

Stack::Stack(const Vector2d& displacement, int nb_bullets, double force_magnitude, double center_offset, double aimed_angle, double seed_angle, double angular_acceleration, SDL_Texture* shared_texture)
{
	double angle = aimed_angle + seed_angle;
	double radian = (M_PI / 180) * angle;

	double force_spread = force_magnitude / nb_bullets;
	double increment = force_spread;

	for (int i = 0; i < nb_bullets; ++i) {

		double x_offset = displacement.X() + center_offset * cos(radian);
		double y_offset = displacement.Y() + center_offset * sin(radian);
		Vector2d location_offset = Vector2d(x_offset, y_offset);
		Bullet* bullet = DBG_NEW Bullet(location_offset, angle, angular_acceleration, force_magnitude, force_spread, shared_texture);
		add(bullet);

		force_spread += increment;
	}
}

Stack::~Stack() {}
