#pragma once
#include "Objects/StaticObjects/StaticObject.h"


class King;
class Wall;
class Warrior;
class Mage;
class Midget;
class Thief;
class Key;
class DynamicObject;



class Teleport :public StaticObject
{
public:
	using StaticObject::StaticObject;
	void handleCollision(Object& Object) override;
	void handleCollision(Mage& gameObject) override;
	void handleCollision(King& gameObject) override;
	void handleCollision(Midget& gameObject) override;
	void handleCollision(Warrior& gameObject) override;
	void handleCollision(Thief& gameObject) override;
	void handleCollision(DynamicObject& gameObject) override;

	void locateDest(const sf::Vector2f& teleport);
	sf::Vector2f getLocation();
	sf::Vector2f getDestination();
	virtual ~Teleport() {}

private:
	sf::Vector2f m_teleportDest;

};
