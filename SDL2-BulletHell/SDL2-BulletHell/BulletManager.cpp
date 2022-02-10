#include "BulletManager.h"

double BulletManager::forceApplied = 0.5f;

void BulletManager::factoryMethod(IBulletPattern* pattern)
{
	bullets = pattern->create();	//TODO Find a proper return type and better handling of bullets considering that their wiill eventualy be waves
}

void BulletManager::update()
{
	for (auto& it : bullets) {
		Vector2d force_dir = Vector2d(cos(it.getAngle()), sin(it.getAngle()));
		Vector2d::mul(force_dir, forceApplied);
		it.update(force_dir);
	}
}
