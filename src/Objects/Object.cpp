#include "Objects/Object.h"

const auto SCALE = 0.25f;

Object::Object(const sf::Texture& texture, const sf::Vector2f& position)
	:m_sprite(texture)
{
	m_sprite.setPosition(position);
	m_sprite.setScale(SCALE, SCALE);
}

void Object::draw(sf::RenderWindow& window)const
{
	window.draw(m_sprite);
}

bool Object::checkCollision(const Object& other) const
{
	if (&other == this) return false;

	return m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds());
}
