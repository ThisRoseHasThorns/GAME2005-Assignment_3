#pragma once
#ifndef __BULLET__
#define __BULLET__

#include "Sprite.h"
#include "BulletPool.h"

class Bullet final : public Sprite
{
public:
	Bullet();
	~Bullet();

	// Life Cycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	void Reset();
	void Despawn();

	bool active = false;

private:
	BulletPool* m_pPool;
	void m_buildAnimations();
};

#endif /* defined (__PLANE__) */
