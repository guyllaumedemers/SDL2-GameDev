#pragma once
#include "Debugger.h"

class TetrominoeImp
{
protected:

	//FIELDS

	bool** tiles = nullptr;

	//CONSTRUCTOR

	TetrominoeImp(const TetrominoeImp&) = delete;

	TetrominoeImp(TetrominoeImp&&) = delete;

public:

	//DESTRUCTOR

	virtual ~TetrominoeImp();

	//IMP_LOGIC

	virtual void flip() = 0;

	virtual void move() = 0;

	//FIELDS

	static int cols;

	static int rows;
};

