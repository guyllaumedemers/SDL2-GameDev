#pragma once
#include <SDL.h>
#include <vector>

struct Panel
{
private:

	std::vector<Panel*> m_Panels;

	SDL_Rect* m_Rect = nullptr;

	SDL_Texture* m_Texture = nullptr;

public:

	Panel(const int& x, const int& y, const int& w, const int& h);

	~Panel();

	void setGraphic(SDL_Texture* texture);

	void AddPanel(Panel* panel);

	void RemovePanel(Panel* panel);

	SDL_Rect* getRect();
};

