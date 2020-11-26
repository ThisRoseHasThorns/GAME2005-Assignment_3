#pragma once
#include "Bullet.h"

class BulletPool
{
public:

	BulletPool(int);
	~BulletPool();
private:
	void populate();

	Bullet* m_pBullets;

};

