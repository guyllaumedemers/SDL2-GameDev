#include "SubPattern.h"

//CONSTRUCTOR

SubPattern::SubPattern(const vector<Group*>& childrens) : childrens(childrens) {}

SubPattern::~SubPattern() {}

//SUBPATTERN_LOGIC

void SubPattern::update()
{
	for (auto& it : childrens) {
		it->update();
	}
}

//CHILDREN_HANDLING

void SubPattern::add(Group* instance) {
	childrens.push_back(instance);
}

void SubPattern::remove(Group* instance) {
	//TODO Remove Instance
}

bool SubPattern::isComposite()
{
	return true;
}