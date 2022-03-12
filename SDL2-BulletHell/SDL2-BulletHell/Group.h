#pragma once
#define _USE_MATH_DEFINES
#include <SDL.h>

class Group
{
public:

	//DESTRUCTOR

	virtual ~Group() {};

	//COMPONENT_LOGIC

	virtual void update() = 0;

	virtual void render(SDL_Renderer*) = 0;

	//CHILDREN_HANDLING

	virtual void add(Group*) = 0;

	virtual void remove(Group*) = 0;

	virtual bool isComposite() = 0;
};

