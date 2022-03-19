#include "Timer.h"

//CONSTRUCTOR

Timer::Timer(ITimerImp* imp) : imp(imp) {}

Timer::~Timer()
{
	delete imp;
	imp = nullptr;
}

//TIMER LOGIC

void Timer::ticks() const
{
	imp->ticks();
}

double Timer::deltaTime() const
{
	return imp->deltaTime();
}
