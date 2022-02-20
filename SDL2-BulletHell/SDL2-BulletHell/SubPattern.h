#pragma once
#include <vector>
#include "Group.h"

using namespace std;
class SubPattern : virtual public Group
{
protected:

	//FIELDS

	//CHILDREN_REFERENCE

	vector<Group*> childrens;

public:

	//CONSTRUCTOR

	SubPattern();

	SubPattern(const vector<Group*>&);

	virtual ~SubPattern();

	//SUBPATTERN_LOGIC

	virtual void update() override;

	//CHILDREN_HANDLING

	virtual void add(Group*) override;

	virtual void remove(Group*) override;

	virtual bool isComposite() override;
};

