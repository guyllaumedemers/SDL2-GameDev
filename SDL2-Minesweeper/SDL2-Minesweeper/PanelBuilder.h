#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
#include <SDL.h>
#include "Panel.h"

class PanelBuilder
{
public:

	virtual ~PanelBuilder() {}

	virtual Panel* buildPanel() = 0;

	virtual void buildGraphic(Panel& panel) = 0;
};
