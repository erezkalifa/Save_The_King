#include "Objects/Objects.hpp"

void Warrior::handleCollision(Object& Object)
{
	Object.handleCollision(*this); // double dispatch
}

void Warrior::handleCollision(Wall& gameObject)
{
	m_sprite.setPosition(m_prevLocation);//can't step on this tile
}

void Warrior::handleCollision(Gate& gameObject)
{
	if (!gameObject.isOpen())
		m_sprite.setPosition(m_prevLocation);
}

void Warrior::handleCollision(Midget& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}

void Warrior::handleCollision(Fire& gameObject)
{
	if (gameObject.isExsit()) {
		m_sprite.setPosition(m_prevLocation);
	}
}

void Warrior::handleCollision(Chair& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}

void Warrior::handleCollision(Teleport& gameObject)
{
	if (!m_onTeleport)
	{
		m_sprite.setPosition(gameObject.getDestination());
		SoundHandle::instance().teleportSound();
		m_onTeleport = true;
	}
}

void Warrior::handleCollision(DynamicObject& gameObject) {}
void Warrior::handleCollision(King& gameObject) {}
void Warrior::handleCollision(Warrior& gameObject) {}
void Warrior::handleCollision(Mage& gameObject) {}
void Warrior::handleCollision(Thief& gameObject) {}
void Warrior::handleCollision(Key& gameObject) {}
void Warrior::handleCollision(Orc& gameObject)
{
	gameObject.remove();
	//gameObject.m_sp
}

