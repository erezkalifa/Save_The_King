#include "Objects/Objects.hpp"
#include <iostream>

void Key::handleCollision(Object& Object)
{
	Object.handleCollision(*this);
}
void Key::handleCollision(King& gameObject) {}
void Key::handleCollision(Midget& gameObject) {}
void Key::handleCollision(Warrior& gameObject) {}
void Key::handleCollision(Mage& gameObject) {}
void Key::handleCollision(Thief& gameObject)
{
	if (!m_exsit) { m_sprite.setColor(sf::Color::Transparent); }
	gameObject.handleCollision(*this);
}

void Key::handleCollision(DynamicObject& gameObject)
{
	//gameObject.handleCollision(*this);
}
