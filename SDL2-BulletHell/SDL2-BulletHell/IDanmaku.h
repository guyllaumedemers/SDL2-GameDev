#pragma once
#include <vector>
#include "Group.h"

using namespace std;
class IDanmaku
{
private:

	//FIELDS

	vector<Group*> subPatterns;

	//CONSTRUCTOR

	IDanmaku();

	~IDanmaku();

public:

	//DANMAKU_LOGIC

	void update();
};

