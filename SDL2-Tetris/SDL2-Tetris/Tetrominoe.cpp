#include "Tetrominoe.h"

Tetrominoe::Tetrominoe(TetrominoeType type, SDL_Texture* texture)
{
	this->shape = new Shape(type);
	this->texture = texture;
}

Tetrominoe::~Tetrominoe()
{
	SDL_DestroyTexture(texture);
	texture = nullptr;
}

void Tetrominoe::update()
{
}

void Tetrominoe::draw()
{
}
