#pragma once
#include <SDL.h>
#include "Group.h"
#include "Vector2d.h"

class Bullet : virtual public Group
{
public:

	//BULLET_LOGIC

	virtual void update() override;

	//CHILDREN_HANDLING

	virtual void add(Group*) override;

	virtual void remove(Group*) override;

	virtual bool isComposite() override;

	//CONSTRUCTOR

	Bullet(const Vector2d&, const Vector2d&, double angle, double angular_velocity);

	virtual ~Bullet();

private:

	//FIELDS

	double angle = 0;

	double angular_velocity = 0;

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
};

