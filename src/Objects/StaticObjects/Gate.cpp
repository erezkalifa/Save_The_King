#include "Objects/Objects.hpp"
#include <iostream>

void Gate::handleCollision(Object& Object)
{
	Object.handleCollision(*this);
}

void Gate::handleCollision(King& gameObject) {
	gameObject.handleCollision(*this);
}
void Gate::handleCollision(Midget& gameObject) {
	gameObject.handleCollision(*this);
}
void Gate::handleCollision(Warrior& gameObject) {
	gameObject.handleCollision(*this);
}
void Gate::handleCollision(Mage& gameObject) {
	gameObject.handleCollision(*this);
}
void Gate::handleCollision(Thief& gameObject) {

	gameObject.handleCollision(*this);
}

bool Gate::isOpen()
{
	return m_isOpen;
}

void Gate::openGate()
{
	m_isOpen = true;
	m_sprite.setTexture(TextureHandle::use().getTexture(textures_type::GateOpen));
}
void Gate::handleCollision(DynamicObject& gameObject)
{
	gameObject.handleCollision(*this);
}
