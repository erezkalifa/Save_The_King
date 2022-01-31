#include "Objects/Objects.hpp"
#include <iostream>

void King::handleCollision(Object& Object)
{
    Object.handleCollision(*this);
}

void King::handleCollision(Wall& gameObject)
{
    m_sprite.setPosition(m_prevLocation);
}

void King::handleCollision(Gate& gameObject)
{
    if (!gameObject.isOpen())
        m_sprite.setPosition(m_prevLocation);
}
void King::handleCollision(Midget& gameObject)
{
    m_sprite.setPosition(m_prevLocation);
}
void King::handleCollision(Fire& gameObject)
{
    if (gameObject.isExsit()) {
        m_sprite.setPosition(m_prevLocation);

    }
}
void King::handleCollision(Orc& gameObject)
{
    m_sprite.setPosition(m_prevLocation);
}

void King::handleCollision(Teleport& gameObject)
{

    if(!m_onTeleport)
    {
        m_sprite.setPosition(gameObject.getDestination());
        SoundHandle::instance().teleportSound();
        m_onTeleport = true;
    }

}

void King::handleCollision(King& gameObject) {}
void King::handleCollision(Warrior& gameObject) {}
void King::handleCollision(Mage& gameObject) {}
void King::handleCollision(Thief& gameObject) {}
void King::handleCollision(Key& gameObject) {}

void King::handleCollision(Chair& gameObject)
{
    m_win = true;
}
void King::handleCollision(DynamicObject& gameObject) {}


bool King::win()
{
    return m_win;
}

