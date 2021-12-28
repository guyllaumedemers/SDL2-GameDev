#include "Shape.h"

Shape::Shape(SDL_Texture* texture)
{
	m_Texture = texture;
}

Shape::~Shape()
{
	SDL_DestroyTexture(m_Texture);
	m_Texture = nullptr;
}
