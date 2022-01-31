#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "FileManager/TexturesHandle.h"
#include "FileManager/SoundHandle.h"

class King;
class Wall;
class Warrior;
class Mage;
class Midget;
class Thief;
class Gate;
class Key;
class Fire;
class Chair;
class Orc;
class Teleport;
class Present;
class DynamicObject;

class Object {
public:
	Object(const sf::Texture& texture, const sf::Vector2f& position);
	void draw(sf::RenderWindow& window)const;
	bool checkCollision(const Object& other) const;
	virtual void handleCollision(Object& Object) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(King& gameObject) = 0;
	virtual void handleCollision(Warrior& gameObject) = 0;
	virtual void handleCollision(Midget& gameObject) = 0;
	virtual void handleCollision(Mage& gameObject) = 0;
	virtual void handleCollision(Thief& gameObject) = 0;
	virtual void handleCollision(Gate& gameObject) = 0;
	virtual void handleCollision(Key& gameObject) = 0;
	virtual void handleCollision(Fire& gameObject) = 0;
	virtual void handleCollision(Chair& gameObject) = 0;
	virtual void handleCollision(Orc& gameObject) = 0;
	virtual void handleCollision(Teleport& gameObject) = 0;
	virtual void handleCollision(DynamicObject& gameObject) = 0;


	virtual ~Object() = default;
protected:
	sf::Sprite m_sprite;
private:
};