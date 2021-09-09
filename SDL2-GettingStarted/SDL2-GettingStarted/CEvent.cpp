#include "CEvent.h"

CEvent::CEvent()
{
	// base constructor
}

CEvent::~CEvent()
{
	// virtual destructor that is overriten when derived from
}

void CEvent::OnEvent(SDL_Event* Event)
{
	switch (Event->type)
	{
		// Handle Window Event
	case SDL_WINDOWEVENT:
		// Handle various type of actions for the window Event, focus -> blur -> window resize
		switch (Event->window.event)
		{
			// SDL_APPMOUSEFOCUS
		case SDL_WINDOWEVENT_ENTER:
			OnMouseFocus();
			break;
			// SDL_APPMOUSEBLUR
		case SDL_WINDOWEVENT_LEAVE:
			OnMouseBlur();
			break;
			// SDL_APPINPUTFOCUS
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			OnInputFocus();
			break;
			// SDL_APPINPUTBLUR
		case SDL_WINDOWEVENT_FOCUS_LOST:
			OnInputBlur();
			break;
			// SDL_APPACTIVE
		case SDL_WINDOWEVENT_MAXIMIZED:
			OnRestore();
			break;
			// SDL_APPINACTIVE
		case SDL_WINDOWEVENT_MINIMIZED:
			OnMinimize();
			break;
			// SDL_WINDOWRESIZE
		case SDL_WINDOW_RESIZABLE:
			OnResize(Event->window.data1, Event->window.data2);
			break;
		}
		break;
	case SDL_KEYDOWN:
		OnKeyDown(Event->key.keysym);
		break;
	case SDL_KEYUP:
		OnKeyUp(Event->key.keysym);
		break;
	case SDL_MOUSEMOTION:
	{															// be sure to only initialize variables inside the scope of the case
		bool l = false, r = false, m = false;
		l = (Event->motion.state & SDL_BUTTON_LEFT) != 0;		// & operator, Bitwise AND operator, compare bit from first operant to second and return 1 is equals
		r = (Event->motion.state & SDL_BUTTON_RIGHT) != 0;
		m = (Event->motion.state & SDL_BUTTON_MIDDLE) != 0;
		OnMouseMove(Event->motion.x, Event->motion.y, Event->motion.xrel, Event->motion.yrel, l, r, m);
		break;
	}
	case SDL_MOUSEBUTTONDOWN:
		switch (Event->button.button)
		{
		case SDL_BUTTON_LEFT:
			OnLButtonDown(Event->button.x, Event->button.y);	// pass the position clicked as arguments
			break;
		case SDL_BUTTON_RIGHT:
			OnRButtonDown(Event->button.x, Event->button.y);
			break;
		case SDL_BUTTON_MIDDLE:
			OnMButtonDown(Event->button.x, Event->button.y);
			break;
		}
		break;
	case SDL_MOUSEBUTTONUP:
		switch (Event->button.button)
		{
		case SDL_BUTTON_LEFT:
			OnLButtonUp(Event->button.x, Event->button.y);		// pass the position released as arguments
			break;
		case SDL_BUTTON_RIGHT:
			OnRButtonUp(Event->button.x, Event->button.y);
			break;
		case SDL_BUTTON_MIDDLE:
			OnMButtonUp(Event->button.x, Event->button.y);
			break;
		}
		break;
	case SDL_QUIT:
		OnExit();
		break;
	default:
		OnUser(Event->user.type, Event->user.code, Event->user.data1, Event->user.data2);
		break;
	}
}

void CEvent::OnInputFocus()
{
}

void CEvent::OnInputBlur()
{
}

void CEvent::OnKeyDown(SDL_Keysym key)
{
}

void CEvent::OnKeyUp(SDL_Keysym key)
{
}

void CEvent::OnMouseFocus()
{
}

void CEvent::OnMouseBlur()
{
}

void CEvent::OnMouseMove(uint16_t mX, uint16_t mY, uint16_t relX, uint16_t relY, bool left, bool right, bool middle)
{
}

void CEvent::OnLButtonDown(uint16_t mX, uint16_t mY)
{
}

void CEvent::OnLButtonUp(uint16_t mX, uint16_t mY)
{
}

void CEvent::OnRButtonDown(uint16_t mX, uint16_t mY)
{
}

void CEvent::OnRButtonUp(uint16_t mX, uint16_t mY)
{
}

void CEvent::OnMButtonDown(uint16_t mX, uint16_t mY)
{
}

void CEvent::OnMButtonUp(uint16_t mX, uint16_t mY)
{
}

void CEvent::OnMinimize()
{
}

void CEvent::OnRestore()
{
}

void CEvent::OnResize(uint16_t w, uint16_t h)
{
}

void CEvent::OnExpose()
{
}

void CEvent::OnExit()
{
}

void CEvent::OnUser(uint8_t type, uint16_t code, void* data1, void* data2)
{
}
