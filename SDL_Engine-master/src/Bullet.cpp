#include "Bullet.h"
#include "TextureManager.h"

Bullet::Bullet()
{
	TextureManager::Instance()->loadSpriteSheet(
		"../Assets/sprites/atlas.txt",
		"../Assets/sprites/atlas.png", 
		"spritesheet");

	setSpriteSheet(TextureManager::Instance()->getSpriteSheet("spritesheet"));

	// set frame width
	setWidth(65);

	// set frame height
	setHeight(65);

	getTransform()->position = glm::vec2(400.0f, 200.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLANE);

	m_buildAnimations();
}

Bullet::~Bullet()
= default;

void Bullet::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the plane sprite with simple propeller animation
	TextureManager::Instance()->playAnimation(
		"spritesheet", getAnimation("plane"),
		x, y, 0.5f, 0, 255, true);
}

void Bullet::update()
{
	float deltaTime = 1.0f / 60.f;

	getRigidBody()->acceleration = glm::vec2(0, 9.8);

	getRigidBody()->velocity = getRigidBody()->velocity + (getRigidBody()->acceleration * deltaTime);
	getTransform()->position = getTransform()->position + getRigidBody()->velocity * deltaTime;
}

void Bullet::clean()
{
}

void Bullet::m_buildAnimations()
{
	Animation planeAnimation = Animation();

	planeAnimation.name = "plane";
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("plane1"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("plane2"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("plane3"));

	setAnimation(planeAnimation);
}