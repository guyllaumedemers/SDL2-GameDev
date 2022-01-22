#include "SubPanelBuilder.h"

SubPanelBuilder::SubPanelBuilder(Panel* panel, const int& x, const int& y, const int& w, const int& h, SDL_Texture* texture)
{
	m_MainPanel = panel;
	m_Rect = new SDL_Rect{
		x,
		y,
		w,
		h
	};
	m_Texture = texture;
}

SubPanelBuilder::~SubPanelBuilder()
{
	m_MainPanel = nullptr;
	m_Texture = nullptr;
}

Panel* SubPanelBuilder::buildPanel()
{
	return new Panel(
		(*m_Rect).x,
		(*m_Rect).y,
		(*m_Rect).w,
		(*m_Rect).h
	);
}

void SubPanelBuilder::buildGraphic(Panel& panel)
{
	panel.setGraphic(m_Texture);
}
