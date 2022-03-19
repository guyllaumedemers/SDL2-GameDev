#include "SClockTimerImp.h"

//CONSTRUCTOR

SClockTimerImp::SClockTimerImp() : previous(system_clock::now()) {}

SClockTimerImp::~SClockTimerImp() {}

//SYSTEM_TIMER LOGIC

void SClockTimerImp::ticks()
{
	delta = (duration_cast<milliseconds>(system_clock::now() - previous) * (fps / 1000.0f)).count();
	if (delta > threshold) delta = threshold;
	previous = system_clock::now();
}

double SClockTimerImp::deltaTime()
{
	return delta;
}
