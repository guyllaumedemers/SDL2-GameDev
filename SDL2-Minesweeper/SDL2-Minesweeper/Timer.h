#pragma once
#include "GameManager.h"

typedef std::function<void()> EventHandler;

class Timer
{
private:

	EventHandler m_EventHandler;

	std::clock_t m_StartTic;

	double m_ResetTime;

public:

	Timer(const double& maxTime);

	~Timer();

	bool run();

	void RegisterToTimerCallback(const EventHandler& myEvent);

	void onTimerCallback();

	double getTime();
};

