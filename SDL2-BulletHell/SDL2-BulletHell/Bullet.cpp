#include "Bullet.h"

//STATIC_FIELD

const double Bullet::min_velocity = 0.0f;

const double Bullet::max_velocity = 20.0f;

const double Bullet::mass = 10.0f;

//CONSTRUCTOR

Bullet::Bullet(const Bullet& instance) :
	angle(instance.angle),
	angular_velocity(instance.angular_velocity),
	acceleration(instance.acceleration),
	velocity(instance.velocity),
	location(instance.location),
	ptr_shared_texture(nullptr) {}

Bullet::~Bullet() {}

//BULLET_LOGIC

void Bullet::update()
{
	//TODO Given Force retrieve acceleration to apply to velocity and blah blah blah
}

//CHILDREN_HANDLING

void Bullet::add(Group*)
{
	//TODO Define what a leaf should do
}

void Bullet::remove(Group*)
{
	//TODO Define what a leaf should do
}

bool Bullet::isComposite()
{
	return false;
}

//PHYSIC_LOGIC

void Bullet::applyForce(const Vector2d& force_to_apply)
{
	Vector2d temp = force_to_apply;

	Vector2d::div(temp, Bullet::mass);
	Vector2d::add(acceleration, temp);
}

void Bullet::applyAcceleration()
{
	Vector2d::add(velocity, acceleration);
}

void Bullet::applyVelocity()
{
	Vector2d::add(location, velocity);
}
