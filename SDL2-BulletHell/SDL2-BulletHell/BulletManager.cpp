#include "BulletManager.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <chrono>
#include <thread>

std::vector<Bullet> BulletManager::bullets;

void BulletManager::update()
{
	for (auto& it : bullets) {
		double rad = (M_PI / 180) * it.getAngle();
		Vector2d force_dir = Vector2d(cos(rad), sin(rad));
		it.update(force_dir);	//TODO Find Scalar Value that would represent the force magnitude so it doesnt sit in a unit circle
	}
}

void BulletManager::print(SDL_Renderer* ren)
{
	for (auto& it : bullets) {
		it.print(ren);
		//TODO Create interval updates for each group created, this process should be done async to not slow down the main thread
		//TODO Async management should involve using multithreading as we want to create bullets overtime with different spawning rate for different pattern and groups
	}
}

void BulletManager::factoryMethod(IBulletPattern* pattern, int x, int y)
{
	std::vector<Bullet> next_wave = pattern->create(x, y);
	bullets.insert(bullets.end(), next_wave.begin(), next_wave.end());
}
