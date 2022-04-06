#pragma once
#include <SDL.h>
#include "Debugger.h"

class TetrominoeImp
{
protected:

	//FIELDS

	SDL_Texture* texture = nullptr;

	bool** tiles = nullptr;		//I should probably only keep track of the anchor position and flip/move according to that point and do proper checks

	static int cols;

	static int rows;

public:

	//CONSTRUCTOR

	TetrominoeImp();

	virtual ~TetrominoeImp();

	//IMP_LOGIC

	virtual void flip() = 0;

	virtual void move() = 0;
};

