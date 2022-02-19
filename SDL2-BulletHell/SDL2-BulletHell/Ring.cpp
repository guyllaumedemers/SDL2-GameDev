#include "Ring.h"

//CONSTRUCTOR

Ring::Ring(const vector<Group*>& childrens, int nb_bullets, double offset, double radius, double seed_angle) :
	SubPattern(childrens),
	nb_bullets(nb_bullets),
	offset(offset),
	radius(radius),
	seed_angle(seed_angle) {}

Ring::~Ring() {}

//RING_LOGIC

void Ring::update()
{
}
