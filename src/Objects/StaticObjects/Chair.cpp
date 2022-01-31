#include "Objects/Objects.hpp"
void Chair::handleCollision(Object& Object)
{
	Object.handleCollision(*this);
}
void Chair::handleCollision(King& gameObject)
{
	m_sprite.setColor(sf::Color::Transparent);
	gameObject.handleCollision(*this);
}

void Chair::handleCollision(Midget& gameObject) {
	gameObject.handleCollision(*this);
}
void Chair::handleCollision(Warrior& gameObject) {
	gameObject.handleCollision(*this);
}
void Chair::handleCollision(Thief& gameObject) {
	gameObject.handleCollision(*this);
}
void Chair::handleCollision(Mage& gameObject) {
	gameObject.handleCollision(*this);
}
void Chair::handleCollision(DynamicObject& gameObject) {
	gameObject.handleCollision(*this);
}
