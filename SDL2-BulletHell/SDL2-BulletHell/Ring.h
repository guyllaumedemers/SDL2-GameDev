#pragma once
#include "SubPattern.h"

class Ring : virtual public SubPattern
{
private:

	//FIELDS

	int nb_bullets = 0;

	const int min_bullet = 3;

	double offset = 0.0f;

	double radius = 0.0f;

	double seed_angle = 0.0f;

public:

	//CONSTRUCTOR

	Ring(const vector<Group*>& childrens, int nb_bullets, double offset, double radius, double seed_angle);

	virtual ~Ring();

	//RING_LOGIC

	virtual void update() override;
};

