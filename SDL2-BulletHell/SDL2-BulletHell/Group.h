#pragma once
#define _USE_MATH_DEFINES
#include <SDL.h>
#include <vector>
#include <chrono>
#include "Debugger.h"
#include "Vector2d.h"
#include "Timer.h"

using namespace std;
using namespace chrono;
class Group
{
public:

	//DESTRUCTOR

	virtual ~Group() {};

	//COMPONENT_LOGIC

	virtual void update(const double&) = 0;

	virtual void render(SDL_Renderer*) = 0;

	//CHILDREN_HANDLING

	virtual void add(Group*) = 0;

	virtual void remove(Group*) = 0;

	virtual bool isComposite() = 0;
};

