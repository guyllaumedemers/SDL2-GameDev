#pragma once
#include "ITimerImp.h"
#include "SDLTimerImp.h"
#include "SClockTimerImp.h"

class Timer
{
private:

	//FIELDS

	ITimerImp* imp = nullptr;

public:

	//CONSTRUCTOR

	Timer(ITimerImp*);

	~Timer();

	//TIMER LOGIC

	void ticks() const;

	double deltaTime() const;
};

