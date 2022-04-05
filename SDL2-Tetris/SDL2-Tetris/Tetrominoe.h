#pragma once
#include "TetrominoeImp.h"

using namespace std;
class Tetrominoe
{
private:

	//FIELDS

	TetrominoeImp* imp = nullptr;

	//CONSTRUCTOR

	Tetrominoe(const Tetrominoe&) = delete;

	Tetrominoe(Tetrominoe&&) = delete;

public:

	//CONSTRUCTOR

	Tetrominoe(TetrominoeImp*);

	~Tetrominoe();

	//TETROMINOE_LOGIC

	void flip() const;

	void move() const;
};

