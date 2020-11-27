#include "Player.h"
#include "TextureManager.h"

Player::Player()
{
	TextureManager::Instance()->load("../Assets/sprites/ship.png", "player");

	auto size = TextureManager::Instance()->getTextureSize("player");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLAYER);
}

Player::~Player()
= default;

void Player::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;
	
}

void Player::update()
{
}

void Player::clean()
{
}


void Player::moveLeft() {
	m_direction.x = -1;
}

void Player::moveRight() {
	m_direction.x = 1;
}

void Player::moveUp() {
	m_direction.y = -1;
}

void Player::moveDown() {
	m_direction.y = 1;
}

void Player::stopMovingX() {
	m_direction.x = 0;
}

void Player::stopMovingY() {
	m_direction.y = 0;
}


