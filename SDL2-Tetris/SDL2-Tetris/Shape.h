#pragma once
#include <SDL.h>

struct Shape
{
protected:

	SDL_Texture* m_Texture = nullptr;

public:

	Shape(SDL_Texture* texture);

	~Shape();

	virtual void flip() = 0;
};

