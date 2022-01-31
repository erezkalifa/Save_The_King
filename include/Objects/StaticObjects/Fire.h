#pragma once
#include "Objects/StaticObjects/StaticObject.h"

class King;
class Warrior;
class Mage;
class Midget;
class Thief;
class DynamicObject;


class Fire :public StaticObject
{
public:
	using StaticObject::StaticObject;
	void handleCollision(Object& Object) override;
	void handleCollision(DynamicObject& Object) override;
	void handleCollision(Mage& gameObject) override;
	void handleCollision(King& gameObject) override;
	void handleCollision(Midget& gameObject) override;
	void handleCollision(Warrior& gameObject) override;
	void handleCollision(Thief& gameObject) override;
	virtual ~Fire() {}

};
