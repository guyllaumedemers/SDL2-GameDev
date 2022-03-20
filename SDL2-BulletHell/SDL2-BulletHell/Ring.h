#pragma once
#include "SubPattern.h"

class Ring : virtual public SubPattern
{
public:

	//FIELDS

	static const int min_bullet;

	//CONSTRUCTOR

	Ring(const Vector2d&, int nb_bullets, double force_magnitude, double center_offset, double seed_angle, double angular_velocity, SDL_Texture*);

	virtual ~Ring();
};

