#include "MainPanelBuilder.h"

MainPanelBuilder::MainPanelBuilder(const int& x, const int& y, const int& w, const int& h, SDL_Texture* texture)
{
	m_Rect = new SDL_Rect{
		x,
		y,
		w,
		h
	};
	m_Texture = texture;
}

MainPanelBuilder::~MainPanelBuilder()
{
	delete m_Rect;
	m_Rect = nullptr;
}

Panel* MainPanelBuilder::buildPanel()
{
	return new Panel(
		(*m_Rect).x,
		(*m_Rect).y,
		(*m_Rect).w,
		(*m_Rect).h
	);
}

void MainPanelBuilder::buildGraphic(Panel& panel)
{
	panel.setGraphic(m_Texture);
}
