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

	Bullet(Vector2d force, double mass, double angle, double angular_velocity);

	virtual ~Bullet();

private:

	//PHYSIC_LOGIC

	void applyForce(const Vector2d&);

	void applyAcceleration();

	void applyVelocity();

	//FIELDS

	SDL_Texture* ptr_shared_texture = nullptr;
};

