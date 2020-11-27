#include "Bullet.h"
#include "TextureManager.h"

Bullet::Bullet()
{
	TextureManager::Instance()->load("../Assets/sprites/shroom.png", "bullet");

	auto size = TextureManager::Instance()->getTextureSize("bullet");

	// set frame width
	setWidth(65);

	// set frame height
	setHeight(65);

	getTransform()->position = glm::vec2(700.0f, 300.0f);
	setType(PLANE);

	Reset();
}

Bullet::~Bullet()
= default;

void Bullet::draw()
{
	if (active) {
		// alias for x and y
		const auto x = getTransform()->position.x;
		const auto y = getTransform()->position.y;

		// draw the plane sprite with simple propeller animation
		
	}

}

void Bullet::update()
{
	if (active) {
		float deltaTime = 1.0f / 60.f;
		getRigidBody()->velocity = getRigidBody()->velocity + (getRigidBody()->acceleration * deltaTime);
		getTransform()->position = getTransform()->position + getRigidBody()->velocity * deltaTime;

		
	}
}

void Bullet::clean()
{
}

void Bullet::Reset() {
	active = false;
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0., 9.8);
	getRigidBody()->isColliding = false;
}
