#include "Bullet.h"

//CONSTRUCTOR

Bullet::Bullet(Vector2d force, double mass, double angle, double angular_velocity) : ptr_shared_texture(nullptr)
{
	this->force = force;
	this->mass = mass;
	this->angle = angle;
	this->angular_velocity = angular_velocity;
	this->acceleration = Vector2d(0, 0);
	this->velocity = Vector2d(0, 0);
	this->location = Vector2d(0, 0);		//TODO Should be at position of spawner
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
