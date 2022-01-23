#include "Window.h"

SDL_Window* Window::m_Window = nullptr;

std::vector<Panel*> Window::m_Panels;

PanelBuilder* Window::m_PanelBuilder = nullptr;

int Window::m_TopMenuBarHeight = Tile::height;

int Window::m_GameContentInfoHeight = Tile::height * 3;

void Window::initializeWindow(const int& x, const int& y, const int& width, const int& height)
{
	m_Window = SDL_CreateWindow(
		"Minesweeper",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		x + width,
		y + height,
		0
	);

	if (m_Window == nullptr) {
		SDL_Log("Cannot initalize SDL_Window : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Window::setWindowSize(const int& width, const int& height)
{
	resetPanels();
	SDL_Rect* rect = initializeContentArea(width, height);
	SDL_SetWindowSize(m_Window, (*rect).w, getNextPanelHeightPosition(rect));
}

SDL_Rect* Window::initializeContentArea(const int& width, const int& height)
{
	SDL_Rect* rect = nullptr;
	rect = buildTopMenuPanel(0, 0, width, m_TopMenuBarHeight);
	rect = buildGameInfoPanel(0, getNextPanelHeightPosition(rect), width, m_GameContentInfoHeight);
	rect = buildGamePanel(0, getNextPanelHeightPosition(rect), width, height);
	destroyBuilder();
	return rect;
}

void Window::addPanel(Panel* panel)
{
	m_Panels.push_back(panel);
}

void Window::removePanel(Panel* panel)
{
}

void Window::resetBuilder()
{
	delete m_PanelBuilder;
	m_PanelBuilder = nullptr;
}

void Window::setBuilder(PanelBuilder* builder)
{
	resetBuilder();
	m_PanelBuilder = builder;
}

void Window::destroyBuilder()
{
	resetBuilder();
}

SDL_Rect* Window::buildTopMenuPanel(const int& x, const int& y, const int& width, const int& height)
{
	setBuilder(DBG_NEW MainPanelBuilder(x, y, width, height, nullptr));

	Panel* topMenuPanel = (*m_PanelBuilder).buildPanel();
	(*m_PanelBuilder).buildGraphic(*topMenuPanel);

	SDL_Rect* rect = (*topMenuPanel).getRect();
	int widthPerCell = 2 * Tile::width;

	rect = buildSubPanel(topMenuPanel, (*rect).x, (*rect).y, widthPerCell, (*rect).h, Rendering::getTextureFromKey("Game"));							//TODO Improve this
	rect = buildSubPanel(topMenuPanel, getNextPanelWidthPosition(rect), (*rect).y, widthPerCell, (*rect).h, Rendering::getTextureFromKey("Help"));
	addPanel(topMenuPanel);

	return (*topMenuPanel).getRect();
}

SDL_Rect* Window::buildGameInfoPanel(const int& x, const int& y, const int& width, const int& height)
{
	setBuilder(DBG_NEW MainPanelBuilder(x, y, width, height, nullptr));

	Panel* gameInfoPanel = (*m_PanelBuilder).buildPanel();
	(*m_PanelBuilder).buildGraphic(*gameInfoPanel);

	SDL_Rect* rect = (*gameInfoPanel).getRect();
	int widthPerCell = ((*rect).w / 3);

	rect = buildSubPanel(gameInfoPanel, (*rect).x, (*rect).y, widthPerCell, (*rect).h, nullptr);
	rect = buildSubPanel(gameInfoPanel, getNextPanelWidthPosition(rect), (*rect).y, widthPerCell, (*rect).h, nullptr);
	rect = buildSubPanel(gameInfoPanel, getNextPanelWidthPosition(rect), (*rect).y, widthPerCell, (*rect).h, nullptr);
	addPanel(gameInfoPanel);

	return (*gameInfoPanel).getRect();
}

SDL_Rect* Window::buildGamePanel(const int& x, const int& y, const int& width, const int& height)
{
	setBuilder(DBG_NEW MainPanelBuilder(x, y, width, height, nullptr));

	Panel* gamePanel = (*m_PanelBuilder).buildPanel();
	(*m_PanelBuilder).buildGraphic(*gamePanel);
	addPanel(gamePanel);

	return (*gamePanel).getRect();
}

SDL_Rect* Window::buildSubPanel(Panel* panel, const int& x, const int& y, const int& width, const int& height, SDL_Texture* texture)
{
	setBuilder(DBG_NEW SubPanelBuilder(panel, x, y, width, height, texture));

	Panel* subPanel = (*m_PanelBuilder).buildPanel();
	(*m_PanelBuilder).buildGraphic(*subPanel);
	(*panel).addPanel(subPanel);

	return (*subPanel).getRect();
}

void Window::resetPanels()
{
	for (auto& it : m_Panels) {
		(*it).reset();
	}
	for (auto& it : m_Panels) {
		delete it;
	}
	m_Panels.clear();
}

int Window::getNextPanelHeightPosition(SDL_Rect* rect)
{
	return (*rect).y + (*rect).h;
}

int Window::getNextPanelWidthPosition(SDL_Rect* rect)
{
	return (*rect).x + (*rect).w;
}

SDL_Window* Window::getWindow()
{
	return m_Window;
}

std::vector<Panel*> Window::getPanels()
{
	return m_Panels;
}

Panel* Window::getPlayAreaPanel()
{
	return m_Panels.at(m_Panels.size() - 1);
}
