#include "Objects/Objects.hpp"

void Mage::handleCollision(Object& Object)
{
	Object.handleCollision(*this);
}

void Mage::handleCollision(Wall& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}
void Mage::handleCollision(Gate& gameObject)
{
	if (!gameObject.isOpen())
		m_sprite.setPosition(m_prevLocation);
}
void Mage::handleCollision(Midget& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}
void Mage::handleCollision(Chair& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}
void Mage::handleCollision(Orc& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}


void Mage::handleCollision(DynamicObject& gameObject) {}
void Mage::handleCollision(Teleport& gameObject) {}
void Mage::handleCollision(King& gameObject) {}
void Mage::handleCollision(Warrior& gameObject) {}
void Mage::handleCollision(Mage& gameObject) {}
void Mage::handleCollision(Thief& gameObject) {}
void Mage::handleCollision(Key& gameObject) {}
void Mage::handleCollision(Fire& gameObject)
{
	if (gameObject.isExsit())
		gameObject.remove();
}




