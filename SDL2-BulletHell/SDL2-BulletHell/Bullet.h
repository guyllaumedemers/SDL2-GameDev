#pragma once
#include <SDL.h>
#include "Vector2d.h"

struct Bullet
{
public:
	void update(const Vector2d& force_to_apply);

	void print(SDL_Renderer* ren);

	double getAngle() const;

	Bullet(double angle, int x, int y);
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

