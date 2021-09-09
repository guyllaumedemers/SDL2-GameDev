#pragma once

#include <SDL.h>
#include <iostream>

class CEvent
{
public:
	// Constructor
	CEvent();
	// Deestructor
	virtual ~CEvent();
	// Functions
	virtual void OnEvent(SDL_Event* Event);

	virtual void OnInputFocus();	// Input OnEnter

	virtual void OnInputBlur();		// Input OnExit

	virtual void OnKeyDown(SDL_Keysym key);

	virtual void OnKeyUp(SDL_Keysym key);

	virtual void OnMouseFocus();

	virtual void OnMouseBlur();

	virtual void OnMouseMove(uint16_t mX, uint16_t mY, uint16_t relX, uint16_t relY, bool left, bool right, bool middle);		// declaration doesnt make much sense
	// dig deeper to justify the bool arguments and the release position addded as arguments
	// Is this for draggin? Is this while holding down left-mouse key or right0mouse key?

	virtual void OnLButtonDown(uint16_t mX, uint16_t mY);

	virtual void OnLButtonUp(uint16_t mX, uint16_t mY);

	virtual void OnRButtonDown(uint16_t mX, uint16_t mY);

	virtual void OnRButtonUp(uint16_t mX, uint16_t mY);

	virtual void OnMButtonDown(uint16_t mX, uint16_t mY);

	virtual void OnMButtonUp(uint16_t mX, uint16_t mY);

	virtual void OnMinimize();

	virtual void OnRestore();

	virtual void OnResize(uint16_t w, uint16_t h);

	virtual void OnExpose();

	virtual void OnExit();

	virtual void OnUser(uint8_t type, uint16_t code, void* data1, void* data2);
};

