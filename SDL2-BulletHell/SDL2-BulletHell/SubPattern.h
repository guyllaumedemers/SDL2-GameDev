#pragma once
#include <vector>
#include "Group.h"
#include "Vector2d.h"
#include "Debugger.h"

using namespace std;
class SubPattern : virtual public Group
{
protected:

	//CHILDREN_REFERENCE

	vector<Group*> childrens;

public:

	//DESTRUCTOR

	virtual ~SubPattern();

	//SUBPATTERN_LOGIC

	virtual void update() override;

	//CHILDREN_HANDLING

	virtual void add(Group*) override;

	virtual void remove(Group*) override;

	virtual bool isComposite() override;

	vector<Group*> getChildrens() { return childrens; }
};

