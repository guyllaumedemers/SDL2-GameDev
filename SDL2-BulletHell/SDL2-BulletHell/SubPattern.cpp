#include "SubPattern.h"

//DESTRUCTOR

SubPattern::~SubPattern()
{
	for (auto& it : childrens) {
		delete it;
		it = nullptr;
	}
	childrens.clear();
}

//SUBPATTERN_LOGIC

void SubPattern::update()
{
	for (auto& it : childrens) it->update();
}

void SubPattern::render(SDL_Renderer* ren)
{
	for (auto& it : childrens) it->render(ren);
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
