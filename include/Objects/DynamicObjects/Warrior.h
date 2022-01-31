#pragma once
#include "Objects/DynamicObjects/DynamicObject.h"

class King;
class Wall;
class Mage;
class Midget;
class Thief;
class Thief;
class Gate;
class Orc;
class Chair;
class Teleport;


class Warrior : public DynamicObject {
public:

	using::DynamicObject::DynamicObject;
	void handleCollision(Object& Object) override;
	void handleCollision(Wall& gameObject) override;
	void handleCollision(King& gameObject) override;
	void handleCollision(Warrior& gameObject) override;
	void handleCollision(Mage& gameObject) override;
	void handleCollision(Midget& gameObject) override;
	void handleCollision(Thief& gameObject) override;
	void handleCollision(Gate& gameObject) override;
	void handleCollision(Key& gameObject) override;
	void handleCollision(Fire& gameObject) override;
	void handleCollision(Chair& gameObject) override;
	void handleCollision(Orc& gameObject) override;
	void handleCollision(Teleport& gameObject) override;
	void handleCollision(DynamicObject& Object) override;
	virtual ~Warrior() {}

};