#include "Panel.h"
#include <iostream>

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
	m_Texture = nullptr;
	delete m_Rect;
	m_Rect = nullptr;
}

void Panel::draw(SDL_Renderer* renderer, SDL_Color color)
{
	SDL_Texture* target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, (*m_Rect).w, (*m_Rect).h);
	SDL_SetRenderTarget(renderer, target);

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(renderer);

	SDL_SetTextureBlendMode(m_Texture, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(renderer, m_Texture, NULL, NULL);

	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, target, NULL, m_Rect);

	for (const auto& it : m_Panels) {
		(*it).draw(renderer, color);
	}

	SDL_DestroyTexture(target);
	target = nullptr;
}

void Panel::reset()
{
	for (auto& it : m_Panels) {
		(*it).reset();
	}
	for (auto& p : m_Panels) {
		delete p;
	}
	m_Panels.clear();
}

void Panel::addPanel(Panel* panel)
{
	m_Panels.push_back(panel);
}

void Panel::removePanel(Panel* panel)
{

}

void Panel::setGraphic(SDL_Texture* texture)
{
	m_Texture = texture;
}

SDL_Rect* Panel::getRect()
{
	return m_Rect;
}

std::vector<Panel*> Panel::getPanels()
{
	return m_Panels;
}
