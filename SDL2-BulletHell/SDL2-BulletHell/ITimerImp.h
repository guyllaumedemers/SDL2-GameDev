#pragma once
#include <SDL.h>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;
class ITimerImp
{
protected:

	//FIELDS

	double delta = 0.0f;

	const double threshold = 1.5f;

	const double fps = 60.0f;

	//CONSTRUCTOR

	ITimerImp() = default;

public:

	//CONSTRUCTOR

	ITimerImp(const ITimerImp&) = delete;

	ITimerImp(ITimerImp&&) = delete;

	virtual ~ITimerImp() {};

	//TIMER LOGIC

	virtual void ticks() = 0;

	virtual double deltaTime() = 0;
};