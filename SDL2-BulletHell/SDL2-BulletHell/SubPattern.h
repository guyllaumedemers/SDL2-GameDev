#pragma once
#include <vector>
#include "Group.h"

using namespace std;
class SubPattern : virtual public Group
{
protected:

	//CHILDREN_REFERENCE

	vector<Group*> childrens;

public:

	SubPattern();

	virtual ~SubPattern();

	//SUBPATTERN_LOGIC

	virtual void update(IBulletBehaviour*) override;

	//CHILDREN_HANDLING

	virtual void add(Group*) override;

	virtual void remove(Group*) override;

	virtual bool isComposite() override;
};

