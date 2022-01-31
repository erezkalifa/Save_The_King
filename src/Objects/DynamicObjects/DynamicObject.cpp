#include "Objects/DynamicObjects/DynamicObject.h"

const auto SPEED = 300.f;
void DynamicObject::choose(bool state) {}

void DynamicObject::move(const sf::Time& time)
{
	m_prevLocation = m_sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_sprite.move(0.f, -SPEED * time.asSeconds());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_sprite.move(0.f, SPEED * time.asSeconds());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_sprite.move(-SPEED * time.asSeconds(), 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_sprite.move(SPEED * time.asSeconds(), 0.f);
	}
}
void DynamicObject::notOnTeleport()
{
	m_onTeleport = false;
}
