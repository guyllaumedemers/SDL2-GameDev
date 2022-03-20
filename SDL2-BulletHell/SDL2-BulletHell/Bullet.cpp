#include "Bullet.h"
#include <algorithm>

const double Bullet::min_velocity = 0.0f;

const double Bullet::max_velocity = 20.0f;

const double Bullet::mass = 10.0f;

const int Bullet::sprite_width = 20;

const int Bullet::sprite_height = 20;

const double Bullet::sprite_rot = 90;

//CONSTRUCTOR

Bullet::Bullet(const Vector2d& location, const Vector2d& force, double angle, double angular_acceleration, double force_multiplier, SDL_Texture* shared_texture)
{
	this->location = location;
	this->force = force;
	this->angle = angle;
	this->angular_acceleration = angular_acceleration;
	this->angular_velocity = 0.0f;
	this->force_multiplier = force_multiplier;
	this->acceleration = Vector2d(0, 0);
	this->velocity = Vector2d(0, 0);
	this->ptr_shared_texture = shared_texture;
	Vector2d::mul(this->force, force_multiplier);
}

Bullet::~Bullet() {}

//BULLET_LOGIC

void Bullet::update(const double& ms)
{
	applyForce();
	applyAcceleration();
	applyVelocity(ms);
	applyAngularVelocity(ms);
	Vector2d::mul(acceleration, 0);
}

void Bullet::render(SDL_Renderer* ren)
{
	SDL_Texture* target = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, sprite_width, sprite_height);
	SDL_SetRenderTarget(ren, target);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	SDL_RenderClear(ren);

	SDL_Rect dest = {
		location.X(),
		location.Y(),
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

void Bullet::applyForce()
{
	Vector2d temp = force;

	Vector2d::div(temp, mass);
	Vector2d::add(acceleration, temp);
}

void Bullet::applyAcceleration()
{
	Vector2d::add(velocity, acceleration);
}

void Bullet::applyVelocity(const double& ms)
{
	Vector2d::mul(velocity, ms);
	Vector2d::add(location, velocity);
}

void Bullet::applyAngularVelocity(const double& ms)
{
	angular_velocity += angular_acceleration;
	angular_velocity = clamp(angular_velocity, -1.0, 1.0);
	angle += (angular_velocity * ms);

	double radian = (M_PI / 180) * angle;
	force = Vector2d(cos(radian), sin(radian));
	Vector2d::mul(force, force_multiplier);
}
