#include "SubPattern.h"

//CONSTRUCTOR

SubPattern::SubPattern()
{
}

SubPattern::~SubPattern()
{
}

//SUBPATTERN_LOGIC

void SubPattern::update(IBulletBehaviour* instance) {
	
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