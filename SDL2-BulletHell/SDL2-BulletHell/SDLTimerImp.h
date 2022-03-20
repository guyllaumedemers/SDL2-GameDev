#pragma once
#include "ITimerImp.h"

class SDLTimerImp : virtual public ITimerImp
{
private:

	//FIELDS

	Uint64 previous = 0;

	Uint64 start = 0;

	Uint64 nb_second_passed = 0;

public:

	//CONSTRUCTOR

	SDLTimerImp();

	SDLTimerImp(const SDLTimerImp&) = delete;

	SDLTimerImp(SDLTimerImp&&) = delete;

	virtual ~SDLTimerImp();

	//SDL_TIMER LOGIC

	void ticks() override;

	double deltaTime() override;

	void print() override;
};

