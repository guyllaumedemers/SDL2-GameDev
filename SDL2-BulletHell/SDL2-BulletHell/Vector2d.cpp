#include "Vector2d.h"

//CONSTRUCTOR

Vector2d::Vector2d() : x(0), y(0) {}

Vector2d::Vector2d(double x, double y) : x(x), y(y) {}

//VECTOR_LOGIC

void Vector2d::add(Vector2d& target, const Vector2d& add)
{
	target.x += add.x;
	target.y += add.y;
}

void Vector2d::sub(Vector2d& target, const Vector2d& sub)
{
	target.x -= sub.x;
	target.y -= sub.y;
}

void Vector2d::mul(Vector2d& target, double mul)
{
	target.x *= mul;
	target.y *= mul;
}

void Vector2d::div(Vector2d& target, double div)
{
	target.x /= div;
	target.y /= div;
}
