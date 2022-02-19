#pragma once

class Group
{
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

