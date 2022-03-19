#pragma once
#include "ITimerImp.h"

class SClockTimerImp : virtual public ITimerImp
{
private:

	//FIELDS

	time_point<system_clock> previous;

public:

	//CONSTRUCTOR

	SClockTimerImp();

	SClockTimerImp(const SClockTimerImp&) = delete;

	SClockTimerImp(SClockTimerImp&&) = delete;

	virtual ~SClockTimerImp();

	//TIMER LOGIC

	void ticks() override;

	double deltaTime() override;
};

