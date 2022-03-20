#pragma once
#include "Group.h"
#include "Bullet.h"

using namespace std;
class SubPattern : virtual public Group
{
protected:

	//CHILDREN_REFERENCE

	vector<Group*> childrens;

	//CONSTRUCTOR

	SubPattern() = default;

public:

	//CONSTRUCTOR

	SubPattern(const SubPattern&) = delete;

	SubPattern(SubPattern&&) = delete;

	virtual ~SubPattern();

	//SUBPATTERN_LOGIC

	virtual void update(const double&) override;

	virtual void render(SDL_Renderer*) override;

	//CHILDREN_HANDLING

	virtual void add(Group*) override;

	virtual void remove(Group*) override;

	virtual bool isComposite() override;

	vector<Group*> getChildrens() { return childrens; }
};

