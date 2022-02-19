#pragma once

struct Vector2d
{
private:

	//FIELDS

	double x, y;

public:

	//CONSTRUCTOR

	Vector2d();

	Vector2d(double x, double y);

	//VECTOR_LOGIC

	static void add(Vector2d& target, const Vector2d& add);

	static void sub(Vector2d& target, const Vector2d& sub);

	static void mul(Vector2d& target, double mul);

	static void div(Vector2d& target, double div);

	double X() { return x; };

	double Y() { return y; };
};

