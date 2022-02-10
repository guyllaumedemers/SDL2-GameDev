#pragma once

struct Vector2d
{
public:
	static void add(Vector2d& target, const Vector2d& add);

	static void sub(Vector2d& target, const Vector2d& sub);

	static void mul(Vector2d& target, double mul);

	static void div(Vector2d& target, double div);

	Vector2d();

	Vector2d(double x, double y);

	Vector2d(const Vector2d&) = default;

	Vector2d(Vector2d&&) = default;
private:
	double x, y;
};

