#include "Objects/Objects.hpp"
//#include "Objects/StaticObjects/Teleport.h"

void Teleport::handleCollision(Object& Object)
{
	Object.handleCollision(*this);
}

void Teleport::locateDest(const sf::Vector2f& teleport)
{
	m_teleportDest = teleport;

}

sf::Vector2f Teleport::getLocation()
{
	return m_sprite.getPosition();
}

sf::Vector2f Teleport::getDestination()
{
	return m_teleportDest;
}

void Teleport::handleCollision(King& gameObject) {
	gameObject.handleCollision(*this);

}
void Teleport::handleCollision(Midget& gameObject) {}
void Teleport::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}
void Teleport::handleCollision(Mage& gameObject) {}


void Teleport::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}
void Teleport::handleCollision(DynamicObject& gameObject) {
	gameObject.handleCollision(*this);
}
