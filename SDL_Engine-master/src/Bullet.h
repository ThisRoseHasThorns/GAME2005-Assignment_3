#pragma once
#ifndef __PLANE__
#define __PLANE__

#include "Sprite.h"

class Bullet final : public Sprite
{
public:
	Bullet();
	~Bullet();

	// Life Cycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

private:
	void m_buildAnimations();
};

#endif /* defined (__PLANE__) */
