#pragma once

const double Group::min_velocity = 0.0f;

const double Group::max_velocity = 20.0f;

class Group
{
protected:

	//FIELDS

	double angle = 0;

	double angular_velocity = 0;

	static const double min_velocity;

	static const double max_velocity;

	double mass;

	Vector2d force;

	Vector2d acceleration;

	Vector2d velocity;

	Vector2d location;

public:

	//DESTRUCTOR

	virtual ~Group() {};

	//COMPONENT_LOGIC

	virtual void update() = 0;

	//CHILDREN_HANDLING

	virtual void add(Group*) = 0;

	virtual void remove(Group*) = 0;

	virtual bool isComposite() = 0;
};

