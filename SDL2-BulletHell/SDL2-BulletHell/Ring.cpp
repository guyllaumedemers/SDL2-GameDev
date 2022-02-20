#include "Ring.h"
#include "Bullet.h"

//CONSTRUCTOR

Ring::Ring(int nb_bullets, double offset, double radius, double seed_angle, double angular_velocity) :
	nb_bullets(nb_bullets),
	offset(offset),
	radius(radius),
	seed_angle(seed_angle),
	angular_velocity(angular_velocity) {

	double angle = 360 / nb_bullets;

	for (int i = 0; i < nb_bullets; ++i) {
		add(new Bullet(angle, angular_velocity));
		angle += angle;
	}

	//TODO How to integrate Radius variation into the equation

	//TODO What should the offset do

	//TODO How does the seed_angle behave

	//TODO How do we add the angular velocity to the update method
}

Ring::~Ring() {}
