//#include <Windows.h>
#include "Objects/Objects.hpp"

const auto DIRECTIONS = 4;
const auto SPEED = 4.f;


void Midget::handleCollision(Object& Object)
{
	Object.handleCollision(*this);
}

void Midget::move(const sf::Time& time)
{
	
	switch (rand() % DIRECTIONS) {

	case 0:	for (size_t i = 0; i < 60; i++)
		m_sprite.move(0.f, -SPEED * time.asSeconds());
		break;

	case 1:
		for (size_t i = 0; i < 60; i++)
			m_sprite.move(0.f, SPEED * time.asSeconds());
		break;

	case 2:
		for (size_t i = 0; i < 60; i++)
			m_sprite.move(-SPEED * time.asSeconds(), 0.f);
		break;

	case 3:
		for (size_t i = 0; i < 60; i++)
			m_sprite.move(SPEED * time.asSeconds(), 0.f);

	}
}
void Midget::handleCollision(Wall& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}
void Midget::handleCollision(Gate& gameObject)
{
	m_sprite.setPosition(m_prevLocation);
}

void Midget::handleCollision(Fire& gameObject)
{
	if (gameObject.isExsit())
		m_sprite.setPosition(m_prevLocation);
}

void Midget::handleCollision(Teleport& gameObject) {}
void Midget::handleCollision(Midget& gameObject) {}
void Midget::handleCollision(Key& gameObject) {}
void Midget::handleCollision(Chair& gameObject) {}
void Midget::handleCollision(Orc& gameObject) {}




void Midget::handleCollision(King& gameObject) {
	gameObject.handleCollision(*this);
}

void Midget::handleCollision(Warrior& gameObject) {
	gameObject.handleCollision(*this);
}
void Midget::handleCollision(Mage& gameObject) {
	gameObject.handleCollision(*this);
}
void Midget::handleCollision(Thief& gameObject) {
	gameObject.handleCollision(*this);
}
void Midget::handleCollision(DynamicObject& gameObject)
{
	gameObject.handleCollision(*this);
}
