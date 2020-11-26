#pragma once
#include "Bullet.h"

class BulletPool
{
public:
	BulletPool(int);
	~BulletPool();

	int size;
	int index = 0;

	Bullet* Spawn();
private:
	Bullet* m_pBullets;

};

