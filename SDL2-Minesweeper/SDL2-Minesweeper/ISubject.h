#pragma once
#include "IObserver.h"

class ISubject {
public:

	virtual void AddSubscriber(IObserver subscriber) = 0;

	virtual void RemoveSubscriber(IObserver subscriber) = 0;

	virtual void NotifyAllSubscribers() = 0;
};