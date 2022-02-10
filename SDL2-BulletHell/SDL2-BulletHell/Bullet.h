#pragma once
#include <SDL.h>
#include "Vector2d.h"

struct Bullet
{
public:
	void update(const Vector2d& force_to_apply);

	float getAngle();

	Bullet(double angle);

	Bullet(const Bullet&) = default;

	Bullet(Bullet&&) = default;
private:
	void applyForce(const Vector2d& force_to_apply);

	void applyAcceleration();

	void applyVelocity();

	static const int mass;

	Vector2d acceleration;

	Vector2d velocity;

	Vector2d location;

	SDL_Texture* ptr_shared_texture = nullptr;

	double angle = 0.0f;
};

