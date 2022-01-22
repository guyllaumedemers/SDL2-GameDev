#pragma once
#include "PanelBuilder.h"

class MainPanelBuilder : public PanelBuilder
{
private:

	SDL_Rect* m_Rect = nullptr;

	SDL_Texture* m_Texture = nullptr;

public:

	MainPanelBuilder(const int& x, const int& y, const int& w, const int& h, SDL_Texture* texture);

	virtual ~MainPanelBuilder();

	Panel* buildPanel() override;

	void buildGraphic(Panel& panel) override;
};

