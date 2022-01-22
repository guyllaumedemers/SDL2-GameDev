#include "Panel.h"

Panel::Panel(const int& x, const int& y, const int& w, const int& h)
{
	m_Rect = new SDL_Rect{
		x,
		y,
		w,
		h
	};
	m_Texture = nullptr;
}

Panel::~Panel()
{
	SDL_DestroyTexture(m_Texture);
	m_Texture = nullptr;
	delete m_Rect;
	m_Rect = nullptr;
}

void Panel::setGraphic(SDL_Texture* texture)
{
	m_Texture = texture;
}

void Panel::addPanel(Panel* panel)
{
	m_Panels.push_back(panel);
}

void Panel::removePanel(Panel* panel)
{

}

void Panel::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, m_Rect);

	// render the background fill rect

	// blend the sub panels onto the main
}

SDL_Rect* Panel::getRect()
{
	return m_Rect;
}

std::vector<Panel*> Panel::getPanels()
{
	return m_Panels;
}
