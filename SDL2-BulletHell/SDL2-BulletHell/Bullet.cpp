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

void Bullet::print(SDL_Renderer* ren)
{
	SDL_Rect* rect = new SDL_Rect();
	rect->x = location.X();
	rect->y = location.Y();
	rect->w = 10;
	rect->h = 10;
	SDL_RenderFillRect(ren, rect);
}

double Bullet::getAngle() const
{
	return angle;
}

Bullet::Bullet(double angle, int x, int y) : angle(angle), acceleration(0, 0), velocity(0, 0), location(x, y)
{
	ptr_shared_texture = nullptr;
}
