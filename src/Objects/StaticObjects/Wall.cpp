#include "Objects/Objects.hpp"

void Wall::handleCollision(Object& Object)
{
	Object.handleCollision(*this);
}

void Wall::handleCollision(King& gameObject) {
	gameObject.handleCollision(*this);
}
void Wall::handleCollision(Midget& gameObject) {
	gameObject.handleCollision(*this);
}
void Wall::handleCollision(Warrior& gameObject) {
	gameObject.handleCollision(*this);
}
void Wall::handleCollision(Mage& gameObject) {
	gameObject.handleCollision(*this);
}
void Wall::handleCollision(Thief& gameObject) {
	gameObject.handleCollision(*this);
}
void Wall::handleCollision(DynamicObject& gameObject) {
	gameObject.handleCollision(*this);
}
