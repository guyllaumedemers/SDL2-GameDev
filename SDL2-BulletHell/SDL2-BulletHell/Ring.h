#pragma once
#define _USE_MATH_DEFINES
#include <SDL.h>
#include "SubPattern.h"

class Ring : virtual public SubPattern
{
public:

	//FIELDS

	static const int min_bullet;

	//CONSTRUCTOR

	Ring(const Vector2d&, int nb_bullets, double force_multiplier, double center_offset, double seed_angle, double angular_velocity, SDL_Texture*);

	virtual ~Ring();
};

