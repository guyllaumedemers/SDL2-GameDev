#include "Bullet.h"

const double Bullet::min_velocity = 0.0f;

const double Bullet::max_velocity = 20.0f;

const double Bullet::mass = 10.0f;

//CONSTRUCTOR

Bullet::Bullet(const Vector2d& location, const Vector2d& force, double angular_velocity) : ptr_shared_texture(nullptr)
{
	this->location = location;
	this->force = force;
	this->angular_velocity = angular_velocity;
	this->acceleration = Vector2d(0, 0);
	this->velocity = Vector2d(0, 0);
}

Bullet::~Bullet() {}

//BULLET_LOGIC

void Bullet::update()
{
	applyForce(force);
	applyAcceleration();
	applyVelocity();
	Vector2d::mul(acceleration, 0);
}

//CHILDREN_HANDLING

void Bullet::add(Group*)
{
	//TODO Define what a leaf should do
	return;
}

void Bullet::remove(Group*)
{
	//TODO Define what a leaf should do
	return;
}

bool Bullet::isComposite()
{
	return false;
}

//PHYSIC_LOGIC

void Bullet::applyForce(const Vector2d& force_to_apply)
{
	Vector2d temp = force_to_apply;

	Vector2d::div(temp, mass);
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
