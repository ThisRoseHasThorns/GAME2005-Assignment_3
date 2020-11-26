#include "BulletPool.h"
#include <iostream>;

using namespace std;

BulletPool::BulletPool(int size) {

	m_pBullets = new Bullet[size];

	std::cout << "bullet pool created with size " << size << endl;
}
void BulletPool::populate() {
	int length = sizeof(m_pBullets) / sizeof(Bullet);
	for (int i = 0; i < length; i++) {
		std::cout << "create bullet" << i << std::endl;
	}
}