#pragma once
#include <SDL.h>
#include "TetrominoeType.h"
#include "Shape.h"

struct Tetrominoe
{
public:

	Tetrominoe(TetrominoeType type, SDL_Texture* texture);

	~Tetrominoe();

	void update();

	void draw();

private:

	Shape* shape = nullptr;

	SDL_Texture* texture = nullptr;
};

