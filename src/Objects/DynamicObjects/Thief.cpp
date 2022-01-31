#include "Objects/Objects.hpp"
#include "Objects/DynamicObjects/Thief.h"
#include "SFML/Graphics.hpp"
#include <iostream>

void Thief::choose(bool state)
{
	if (!state && !hasKey())
		m_sprite.setTexture(TextureHandle::use().getTexture(textures_type::Thief));
	else if (state && !hasKey())
		m_sprite.setTexture(TextureHandle::use().getTexture(textures_type::Thief));
	else if (!state && hasKey())
		m_sprite.setTexture(TextureHandle::use().getTexture(textures_type::ThiefWithKey));
	else if (state && hasKey())
		m_sprite.setTexture(TextureHandle::use().getTexture(textures_type::ThiefWithKey));
}
void Thief::handleCollision(Object& Object)
{
	Object.handleCollision(*this);
}
void Thief::handleCollision(Wall& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}
void Thief::handleCollision(Midget& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}
void Thief::handleCollision(Fire& gameObject)
{
	if (gameObject.isExsit()) {
		m_sprite.setPosition(m_prevLocation);
	}
}
void Thief::handleCollision(Chair& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}
void Thief::handleCollision(Orc& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}

void Thief::handleCollision(King& gameObject) {}
void Thief::handleCollision(Warrior& gameObject) {}
void Thief::handleCollision(Mage& gameObject) {}
void Thief::handleCollision(Thief& gameObject) {}

void Thief::handleCollision(Key& gameObject)
{
	if (gameObject.isExsit()) {
		if (peekKey())
		{
			SoundHandle::instance().keyPickSound();
			gameObject.remove();
		}
	}
}

void Thief::handleCollision(Gate& gameObject)
{
	if (!gameObject.isOpen())
	{
		if (hasKey())
		{
			gameObject.openGate();
			m_key = false;
			m_sprite.setTexture(TextureHandle::use().getTexture(textures_type::Thief));
		}
		else
			m_sprite.setPosition(m_prevLocation);
	}
}

void Thief::handleCollision(Teleport& gameObject)
{
	if (!m_onTeleport)
	{
		m_sprite.setPosition(gameObject.getDestination());
		SoundHandle::instance().teleportSound();
		m_onTeleport = true;
	}
}
void Thief::handleCollision(DynamicObject& gameObject) {}

bool Thief::hasKey()
{
	return m_key;
}

bool Thief::peekKey()
{
	m_sprite.setTexture(TextureHandle::use().getTexture(textures_type::ThiefWithKey));
	if (!hasKey())
	{
		m_key = true;
		return true;
	}
	return false;
}
