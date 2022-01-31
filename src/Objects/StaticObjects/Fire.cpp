#include "Objects/Objects.hpp"

void Fire::handleCollision(Object& Object)
{
	Object.handleCollision(*this);
}
void Fire::handleCollision(Mage& gameObject)
{
	if (m_exsit) { m_sprite.setColor(sf::Color::Transparent); }
	gameObject.handleCollision(*this);
}

void Fire::handleCollision(King& gameObject) {
	gameObject.handleCollision(*this);
}
void Fire::handleCollision(Midget& gameObject) {
	gameObject.handleCollision(*this);
}
void Fire::handleCollision(Warrior& gameObject) {
	gameObject.handleCollision(*this);
}
void Fire::handleCollision(Thief& gameObject) {
	gameObject.handleCollision(*this);
}

void Fire::handleCollision(DynamicObject& gameObject) {
	if (!m_exsit) m_sprite.setColor(sf::Color::Transparent);
	if (m_exsit)
	{
		gameObject.handleCollision(*this);
	}
}
