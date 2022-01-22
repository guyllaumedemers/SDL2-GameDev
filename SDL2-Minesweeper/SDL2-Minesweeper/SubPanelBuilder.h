#pragma once
#include "PanelBuilder.h"

class SubPanelBuilder : public PanelBuilder
{
private:

	Panel* m_MainPanel = nullptr;

	SDL_Rect* m_Rect = nullptr;

	SDL_Texture* m_Texture = nullptr;

public:

	SubPanelBuilder(Panel* panel, const int& x, const int& y, const int& w, const int& h, SDL_Texture* texture);

	virtual ~SubPanelBuilder();

	Panel* buildPanel() override;

	void buildGraphic(Panel& panel) override;
};

