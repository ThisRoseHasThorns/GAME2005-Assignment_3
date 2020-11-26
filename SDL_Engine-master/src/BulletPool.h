#pragma once
#ifndef __BULLETPOOL__
#define __BULLETPOOL__
#include "Bullet.h"

class BulletPool
{
public:
	BulletPool(int);
	~BulletPool();

	Bullet* Spawn();
	void Despawn(Bullet*);
private:

	std::vector<Bullet*> active;
	std::vector<Bullet*> inactive;

};

#endif

