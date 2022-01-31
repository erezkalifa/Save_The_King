#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include "Objects/DynamicObjects/DynamicObjects.hpp"
#include "Objects/StaticObjects/StaticObjects.hpp"
#include "SFML/Graphics.hpp"
#include "FileManager/TexturesHandle.h"
#include "FileManager/SoundHandle.h"

class DynamicObject;

class King;
class Mage;
class Thief;
class Warrior;
class Midget;

class StaticObject;
class Orc;
class Key;
class Fire;
class Wall;
class Gate;
class Chair;
class Teleport;


enum class LEVELS : size_t
{
	LEVEL_1,
	LEVEL_2,
	LEVEL_3,
	LevelsCount
};


class Board
{
public:
	Board();
	void draw(sf::RenderWindow& window)const;
	void moveCurrentPlayer(const sf::Time& time);
	void moveMidgets(const sf::Clock& clock);
	void nextPlayer();
	void handleCollision();
	void afterCollision();
	void locateTeleportDest();
	bool isWin();
private:

	std::vector<std::unique_ptr<DynamicObject>> m_movingObjects;
	std::vector<Midget> m_midgets;
	std::vector <Teleport> m_teleports;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
	size_t m_currentPlayer = 0;
	bool m_win = false;
	void loadLevels();
	std::vector <std::ifstream> m_levels;
};

