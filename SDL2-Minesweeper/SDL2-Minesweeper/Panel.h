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

	void draw(SDL_Renderer* renderer);

	void reset();

	void addPanel(Panel* panel);

	void removePanel(Panel* panel);

	void setGraphic(SDL_Texture* texture);

	SDL_Rect* getRect();

	std::vector<Panel*> getPanels();
};

