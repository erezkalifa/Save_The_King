#pragma once
#include "Objects/Object.h"
#include "Objects/DynamicObjects/DynamicObject.h"


class King;
class Wall;
class Warrior;
class Mage;
class Midget;
class Thief;
class Orc;
class Gate;
class Key;
class Fire;
class Chair;
class Orc;
class Teleport;
class DynamicObject;



class StaticObject :public Object
{
public:
	using Object::Object;
	virtual void handleCollision(DynamicObject& gameObject) = 0;
	virtual void handleCollision(Object& Object) override = 0;
	virtual void handleCollision(King& Object) override = 0;
	virtual void handleCollision(Mage& Object) override = 0;
	virtual void handleCollision(Warrior& Object) override = 0;
	virtual void handleCollision(Midget& Object) override = 0;
	virtual void handleCollision(Thief& gameObject) override = 0;
	virtual void handleCollision(Wall& Object) override;
	virtual void handleCollision(Teleport& Object) override;
	virtual void handleCollision(Fire& Object) override;
	virtual void handleCollision(Gate& Object) override;
	virtual void handleCollision(Key& Object) override;
	virtual void handleCollision(Chair& Object) override;
	virtual void handleCollision(Orc& Object) override;
	virtual ~StaticObject() = default;

	void remove();
	virtual bool isExsit();

protected:
	bool m_exsit = true;

};