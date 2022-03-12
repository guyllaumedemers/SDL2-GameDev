#include "SubPattern.h"
#include <iostream>

//DESTRUCTOR

SubPattern::~SubPattern() {}

//SUBPATTERN_LOGIC

void SubPattern::update()
{
	for (auto& it : childrens) it->update();
}

//CHILDREN_HANDLING

void SubPattern::add(Group* instance) {
	childrens.push_back(instance);
}

void SubPattern::remove(Group* instance) {
	auto it = find(childrens.begin(), childrens.end(), instance);
	if (it != childrens.end()) childrens.erase(it);
}

bool SubPattern::isComposite()
{
	return true;
}