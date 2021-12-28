#pragma once
#include <SDL.h>

class Timer
{
private:

	unsigned int  m_CurrentTime = 0.0f;

	unsigned int  m_Threshold = 0.0f;

public:

	Timer(unsigned int threshold);

	~Timer();

	bool getTimeElapse();

	void reset();
};

