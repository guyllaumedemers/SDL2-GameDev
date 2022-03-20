#pragma once
#include "Group.h"

using namespace std;
class Bullet : virtual public Group
{
public:

	//BULLET_LOGIC

	virtual void update(const double&) override;

	virtual void render(SDL_Renderer*) override;

	//CHILDREN_HANDLING

	virtual void add(Group*) override;

	virtual void remove(Group*) override;

	virtual bool isComposite() override;

	//CONSTRUCTOR

	Bullet(const Vector2d& location, double angle, double angular_acceleration , double force_multiplier, SDL_Texture* shared_texture);

	virtual ~Bullet();

private:

	//FIELDS

	double angular_acceleration = 0.0f;

	double angular_velocity = 0.0f;

	double angle = 0.0f;

	double magnitude = 0.0f;

	static const double min_velocity;

	static const double max_velocity;

	static const double mass;

	Vector2d acceleration;

	Vector2d velocity;

	Vector2d location;

	//PHYSIC_LOGIC

	void applyForce();

	void applyAcceleration();

	void applyVelocity(const double&);

	void applyAngularVelocity(const double&);

	//FIELDS

	SDL_Texture* ptr_shared_texture = nullptr;

	static const int sprite_width;

	static const int sprite_height;

	static const double sprite_rot;
};

