#pragma once
#include "Objects/Object.h"

class King;
class Wall;
class Warrior;
class Mage;
class Midget;
class Thief;
class Gate;
class Orc;
class Key;
class Fire;
class Teleport;

class DynamicObject : public Object {
public:
	virtual void choose(bool state);
	using Object::Object;
	virtual ~DynamicObject() = default;
	virtual void move(const sf::Time& time);
	virtual void notOnTeleport();
	virtual void handleCollision(Object& Object) override = 0;
	virtual void handleCollision(King& Object)  override = 0;
	virtual void handleCollision(Wall& Object) override = 0;
	//virtual void handleCollision(Warrior& gameObject) override = 0;
	//virtual void handleCollision(Midget& gameObject) override = 0;
	// void handleCollision(Mage& gameObject) override = 0;
	//virtual void handleCollision(Thief& gameObject) override = 0;
	virtual void handleCollision(Gate& gameObject) override = 0;
	virtual void handleCollision(Key& gameObject) override = 0;
	virtual void handleCollision(Fire& gameObject) override = 0;
	virtual void handleCollision(Orc& gameObject) override = 0;
	virtual void handleCollision(Teleport& gameObject) override = 0;
protected:
	sf::Vector2f m_prevLocation = m_sprite.getPosition();
	bool m_onTeleport;
};