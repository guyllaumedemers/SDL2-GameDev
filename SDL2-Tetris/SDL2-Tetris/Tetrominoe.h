#pragma once
#include <SDL.h>

using namespace std;
class Tetrominoe
{
private:

	//FIELDS

	SDL_Texture* texture = nullptr;

	int* map = nullptr;

	//CONSTRUCTOR

	Tetrominoe(const Tetrominoe&) = delete;

	Tetrominoe(Tetrominoe&&) = delete;

public:

	//CONSTRUCTOR

	Tetrominoe(int*);

	~Tetrominoe();

	//TETROMINOE_LOGIC

	void flip();

	void move();
};

