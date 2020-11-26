#include "BulletPool.h"
#include <iostream>;

using namespace std;

BulletPool::BulletPool(int size) {

	for (int i = 0; i < size; i++) {
		inactive.push_back(new Bullet());
	}
	
	std::cout << "bullet pool created with size " << size << std::endl;

}

Bullet* BulletPool::Spawn() {
	Bullet* bullet = NULL;
	if (inactive.size() > 0) {
		bullet = inactive.back();
		bullet->active = true;
		inactive.pop_back();
		active.push_back(bullet);
	}
	else {
		std::cout << "error: max bullets spwawned" << std::endl;
	}

	return bullet;
}

void BulletPool::Despawn(Bullet* bullet) {
	bullet->Reset();
	inactive.push_back(bullet);

	for (int i = 0; i < active.size(); i++) {
		if (active.at(i) == bullet) {
			active.at(i) = active.back();
			active.pop_back();
		}
	}
}