#include "Bullet.h"
#include <algorithm>

const double Bullet::min_velocity = -20.0f;

const double Bullet::max_velocity = 20.0f;

const double Bullet::mass = 10.0f;

const int Bullet::sprite_width = 20;

const int Bullet::sprite_height = 20;

const double Bullet::sprite_rot = 90;

//CONSTRUCTOR

Bullet::Bullet(const Vector2d& displacement, double angle, double angular_acceleration, double force_magnitude, double force_spread, SDL_Texture* shared_texture)
{
	this->displacement = displacement;
	this->angle = angle;
	this->angular_acceleration = angular_acceleration;
	this->angular_velocity = 0.0f;
	this->force_magnitude = force_magnitude;
	this->force_spread = force_spread;
	this->acceleration = Vector2d(0, 0);
	this->velocity = Vector2d(0, 0);
	this->ptr_shared_texture = shared_texture;
}

Bullet::~Bullet() {}

//BULLET_LOGIC

void Bullet::update(const double& ms)
{
	applyForce(ms);
	applyAcceleration(ms);
	applyVelocity(ms);
	//applyAngularVelocity(ms);
	Vector2d::mul(acceleration, 0);
}

void Bullet::render(SDL_Renderer* ren)
{
	SDL_Texture* target = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, sprite_width, sprite_height);
	SDL_SetRenderTarget(ren, target);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	SDL_RenderClear(ren);

	SDL_Rect dest = {
		displacement.X(),
		displacement.Y(),
		sprite_width,
		sprite_height
	};

	SDL_SetTextureBlendMode(target, SDL_BLENDMODE_BLEND);
	SDL_RenderCopyExF(ren, ptr_shared_texture, NULL, NULL, angle - sprite_rot, NULL, SDL_FLIP_NONE);

	SDL_SetRenderTarget(ren, NULL);
	SDL_RenderCopy(ren, target, NULL, &dest);

	SDL_DestroyTexture(target);
	target = nullptr;
}

//CHILDREN_HANDLING

void Bullet::add(Group*)
{
	return;
}

void Bullet::remove(Group*)
{
	return;
}

bool Bullet::isComposite()
{
	return false;
}

//PHYSIC_LOGIC

void Bullet::applyForce(const double& ms)
{
	double rad = (M_PI / 180) * angle;
	Vector2d force = Vector2d(cos(rad), sin(rad));

	Vector2d::mul(force, force_magnitude);
	Vector2d::div(force, mass);
	Vector2d::mul(force, ms);
	Vector2d::add(acceleration, force);
}

void Bullet::applyAcceleration(const double& ms)
{
	if (velocity.X() > min_velocity &&
		velocity.X() < max_velocity &&
		velocity.Y() > min_velocity &&
		velocity.Y() < max_velocity) {
		Vector2d::add(velocity, acceleration);
	}
	Vector2d::mul(acceleration, 0);
}

void Bullet::applyVelocity(const double& ms)
{
	Vector2d::mul(velocity, ms);
	Vector2d::add(displacement, velocity);
}

void Bullet::applyAngularVelocity(const double& ms)
{
	angular_velocity += angular_acceleration;
	angle += angular_velocity;

	//TODO Issue #3 -- I want to be able to increment my bullet angle orientation so it curves over time without resolving on itself. Force is being recalculated above to handle the new direction. A solution could simply

	//be to clamp the angle of the bullet 
}
