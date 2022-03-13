#pragma once
#include "Group.h"
#include "Vector2d.h"

class Bullet : virtual public Group
{
public:

	//BULLET_LOGIC

	virtual void update() override;

	virtual void render(SDL_Renderer*) override;

	//CHILDREN_HANDLING

	virtual void add(Group*) override;

	virtual void remove(Group*) override;

	virtual bool isComposite() override;

	//CONSTRUCTOR

	Bullet(const Vector2d& location, const Vector2d& force, double orientation, double angular_velocity, SDL_Texture* shared_texture);

	virtual ~Bullet();

	Vector2d getForce() { return force; }

private:

	//FIELDS

	double angular_velocity = 0.0f;

	double orientation = 0.0f;

	static const double min_velocity;

	static const double max_velocity;

	static const double mass;

	Vector2d force;

	Vector2d acceleration;

	Vector2d velocity;

	Vector2d location;

	//PHYSIC_LOGIC

	void applyForce(const Vector2d&);

	void applyAcceleration();

	void applyVelocity();

	//FIELDS

	SDL_Texture* ptr_shared_texture = nullptr;

	static const int sprite_width;

	static const int sprite_height;

	static const double sprite_rot;
};

