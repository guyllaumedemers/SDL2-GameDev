#pragma once
#include <SDL.h>

struct Shape
{
protected:

	SDL_Texture* m_Texture = nullptr;

	const int m_NbTiles = 4;

public:

	Shape(SDL_Texture* texture);

	~Shape();

	virtual void flip() = 0;
};

