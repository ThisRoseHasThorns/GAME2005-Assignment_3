#include "BulletPool.h"
#include <iostream>;

using namespace std;

BulletPool::BulletPool(int size) {

	m_pBullets = new Bullet[size];

	std::cout << "bullet pool created with size " << size << endl;

}

Bullet* BulletPool::Spawn() {
	if (index < size) {
		return &m_pBullets[index];
	}

	return NULL;
}