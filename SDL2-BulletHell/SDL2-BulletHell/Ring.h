#pragma once
#include "SubPattern.h"

class Ring : virtual public SubPattern
{
public:

	//CONSTRUCTOR

	Ring(const Vector2d&, int nb_bullets, double force_multiplier, double center_offset, double seed_angle, double angular_velocity);

	virtual ~Ring();
};

