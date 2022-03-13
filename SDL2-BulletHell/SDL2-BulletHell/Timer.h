#pragma once
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
struct Timer
{
private:

	//TIMER_LOGIC

	milliseconds getDeltaTime();

	//FIELDS

	high_resolution_clock::time_point last;
	milliseconds threshold;

public:

	//CONSTRUCTOR

	Timer(milliseconds threshold);

	~Timer();

	//TIMER_LOGIC

	bool hasFinished();

	//PERFORMENCE_TESTING

	static steady_clock::time_point setTimestamp();

	static void printExecutionTime(steady_clock::time_point&);
};

