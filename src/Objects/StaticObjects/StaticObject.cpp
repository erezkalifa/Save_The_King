#include "Objects/StaticObjects/StaticObject.h"

void StaticObject::handleCollision(Wall& Object) {};
void StaticObject::handleCollision(Gate& Object) {};
void StaticObject::handleCollision(Key& Object) {};
void StaticObject::handleCollision(Fire& Object) {};
void StaticObject::handleCollision(Chair& Object) {};
void StaticObject::handleCollision(Orc& Object) {};
void StaticObject::handleCollision(Teleport& Object) {};
void StaticObject::remove()
{
	m_exsit = false;
}

bool StaticObject::isExsit()
{
	return m_exsit;
}






