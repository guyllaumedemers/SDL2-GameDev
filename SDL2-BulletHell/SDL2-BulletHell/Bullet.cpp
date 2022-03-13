#include "Bullet.h"
#include "Timer.h"

const double Bullet::min_velocity = 0.0f;

const double Bullet::max_velocity = 20.0f;

const double Bullet::mass = 10.0f;

const int Bullet::sprite_width = 25;

const int Bullet::sprite_height = 25;

//CONSTRUCTOR

Bullet::Bullet(const Vector2d& location, const Vector2d& force, double angular_velocity, SDL_Texture* shared_texture)
{
	this->location = location;
	this->force = force;
	this->angular_velocity = angular_velocity;
	this->acceleration = Vector2d(0, 0);
	this->velocity = Vector2d(0, 0);
	this->ptr_shared_texture = shared_texture;
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

void Bullet::render(SDL_Renderer* ren)
{
	SDL_Texture* target = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, sprite_width, sprite_height);
	SDL_SetRenderTarget(ren, target);
	SDL_SetTextureBlendMode(target, SDL_BLENDMODE_BLEND);

	SDL_Rect dest = {
		location.X(),
		location.Y(),
		sprite_width,
		sprite_height
	};

	SDL_RenderCopy(ren, ptr_shared_texture, NULL, NULL);

	SDL_SetRenderTarget(ren, NULL);
	SDL_RenderCopy(ren, target, NULL, &dest);

	SDL_DestroyTexture(target);
	target = nullptr;
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
