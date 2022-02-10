#include "Bullet.h"

const int Bullet::mass = 10;

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

void Bullet::update(const Vector2d& force_to_apply)
{
	applyForce(force_to_apply);
	applyAcceleration();
	applyVelocity();
	Vector2d::mul(acceleration, 0);
}

float Bullet::getAngle()
{
	return angle;
}

Bullet::Bullet(double angle)
{
	ptr_shared_texture = nullptr;
}
