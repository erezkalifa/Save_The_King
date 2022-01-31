#include "Objects/Objects.hpp"
#include "SFML/Graphics.hpp"

void Orc::handleCollision(Object& Object)
{
	Object.handleCollision(*this);
}
void Orc::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

//Midget can touch the Orc (they are friends).
void Orc::handleCollision(Midget& gameObject) {
}

void Orc::handleCollision(King& gameObject) {
	gameObject.handleCollision(*this);
}
void Orc::handleCollision(Thief& gameObject) {
	gameObject.handleCollision(*this);
}
void Orc::handleCollision(Mage& gameObject) {
	gameObject.handleCollision(*this);
}
void Orc::handleCollision(DynamicObject& gameObject) {
	gameObject.handleCollision(*this);
}
sf::Vector2f Orc::getLocation()
{
	return m_orcLocation;
}
