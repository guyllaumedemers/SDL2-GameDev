#pragma once
#include <vector>
#include "Group.h"

using namespace std;
class IDanmaku
{
protected:

	//FIELDS

	vector<Group*> subPatterns;

public:

	//DESTRUCTOR

	virtual ~IDanmaku() {};

	//DANMAKU_LOGIC

	virtual void create() = 0;

	virtual void update() = 0;
};

