#include "BulletPool.h"
#include <iostream>;

using namespace std;

BulletPool::BulletPool(int size) {

	m_pBullets = new Bullet[size];

	std::cout << "bullet pool created with size " << size << std::endl;

}

Bullet* BulletPool::Spawn() {
	Bullet* bullet = NULL;
	if (index < size) {
		bullet = &m_pBullets[index];
		index++;
	}
	else {
		std::cout << "error: max bullets spwawned" << std::endl;
	}

	return bullet;
}