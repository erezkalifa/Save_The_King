#pragma once
#include "Objects/StaticObjects/StaticObject.h"

class King;
class Warrior;
class Mage;
class Midget;
class Thief;
class DynamicObject;



class Orc :public StaticObject
{
public:
	using StaticObject::StaticObject;


	sf::Vector2f getLocation();

	void handleCollision(Object& Object) override;
	void handleCollision(Mage& gameObject) override;
	void handleCollision(King& gameObject) override;
	void handleCollision(Midget& gameObject) override;
	void handleCollision(Warrior& gameObject) override;
	void handleCollision(Thief& gameObject) override;
	void handleCollision(DynamicObject& gameObject) override;
	virtual ~Orc() {}

private:
	sf::Vector2f m_orcLocation = m_sprite.getPosition();
};
