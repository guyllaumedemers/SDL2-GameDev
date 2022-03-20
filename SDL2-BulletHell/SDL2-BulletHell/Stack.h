#pragma once
#include "SubPattern.h"

class Stack : virtual public SubPattern
{
public:

	//FIELDS

	static const int min_bullet;

	//CONSTRUCTOR

	Stack(const Vector2d&, int nb_bullets, double force_magnitude, double center_offset, double aimed_angle, double seed_angle, double angular_acceleration, SDL_Texture*);

	virtual ~Stack();
};

