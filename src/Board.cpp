#include "Board.h"


const auto FILE_INPUT = "Board.txt";


enum class ObjectType : char
{
	Chair = '@',
	Empty = ' ',
	Fire = '*',
	Gate = '#',
	Key = 'F',
	King = 'K',
	Mage = 'M',
	Orc = '!',
	Teleport = 'X',
	Thief = 'T',
	Wall = '=',
	Warrior = 'W',
	Midget = '^',
	//Present = '?'
};

bool isDynamic(ObjectType type)
{
	switch (type) {
	case ObjectType::King:
	case ObjectType::Mage:
	case ObjectType::Warrior:
	case ObjectType::Thief:
	case ObjectType::Midget:
		return true;
	default:
		return false;
	}
}


std::unique_ptr<DynamicObject> createDynamicObject(ObjectType type, const sf::Vector2f& location)
{
	switch (type)
	{
	case ObjectType::King:
		return std::make_unique<King>(TextureHandle::use().getTexture(textures_type::King),
			location);
	case ObjectType::Mage:
		return std::make_unique<Mage>(TextureHandle::use().getTexture(textures_type::Mage),
			location);
	case ObjectType::Thief:
		return std::make_unique<Thief>(TextureHandle::use().getTexture(textures_type::Thief),
			location);
	case ObjectType::Warrior:
		return std::make_unique<Warrior>(TextureHandle::use().getTexture(textures_type::Warrior),
			location);
	case ObjectType::Midget:
		return std::make_unique<Midget>(TextureHandle::use().getTexture(textures_type::Midget),
			location);
	}
	return nullptr;
}

std::unique_ptr<StaticObject> createStaticObject(ObjectType type, const sf::Vector2f& location)
{
	switch (type)
	{
	case ObjectType::Chair:
		return std::make_unique<Chair>(TextureHandle::use().getTexture(textures_type::Chair),
			location);
	case ObjectType::Fire:
		return std::make_unique<Fire>(TextureHandle::use().getTexture(textures_type::Fire),
			location);
	case ObjectType::Gate:
		return std::make_unique<Gate>(TextureHandle::use().getTexture(textures_type::Gate),
			location);
	case ObjectType::Key:
		return std::make_unique<Key>(TextureHandle::use().getTexture(textures_type::Key),
			location);
	case ObjectType::Orc:
		return std::make_unique<Orc>(TextureHandle::use().getTexture(textures_type::Orc),
			location);
	case ObjectType::Teleport:
		return std::make_unique<Teleport>(TextureHandle::use().getTexture(textures_type::Teleport),
			location);
	case ObjectType::Wall:
		return std::make_unique<Wall>(TextureHandle::use().getTexture(textures_type::Wall),
			location);
		
	}
	return nullptr;
}


void Board::loadLevels()
{
	std::array <std::string, (size_t)LEVELS::LevelsCount> levelNames =
	{
		"Board.txt"
	};

	for (int i = 0; i < levelNames.size(); i++)
	{
		m_levels.emplace_back(levelNames[i]);
	}

}

Board::Board() {
	auto file = std::fstream(FILE_INPUT);
	auto line = std::string();
	for (size_t i = 0; std::getline(file, line); i++)
	{
		for (size_t j = 0; j < line.size(); j++)
		{
			auto type = (ObjectType)line[j];
			if (type == ObjectType::Empty)
				continue;
			else if (type == ObjectType::Midget)
				m_midgets.emplace_back(TextureHandle::use().getTexture(textures_type::Midget),
					sf::Vector2f{ j * 50.f, i * 50.f });
			else if (type == ObjectType::Teleport)
				m_teleports.emplace_back(TextureHandle::use().getTexture(textures_type::Teleport),
					sf::Vector2f{ j * 50.f, i * 50.f });
			else {
				isDynamic(type) ? m_movingObjects.push_back(createDynamicObject(type, { j * 50.f, i * 50.f })) :
					m_staticObjects.push_back(createStaticObject(type, { j * 50.f, i * 50.f }));
			}
		}
	}
	locateTeleportDest();
};

void Board::draw(sf::RenderWindow& window) const
{
	for (const auto& obj : m_movingObjects) {
		obj->draw(window);
	}
	for (const auto& midget : m_midgets) {
		midget.draw(window);
	}
	for (const auto& obj : m_staticObjects) {
		obj->draw(window);
	}

	for (const auto& teleport : m_teleports)
		teleport.draw(window);

}

void Board::moveCurrentPlayer(const sf::Time& time)
{
	m_movingObjects[m_currentPlayer]->move(time);
}

void Board::moveMidgets(const sf::Clock& clock)
{
	for (auto& midget : m_midgets) {
		midget.move(clock.getElapsedTime());
	}
}

void Board::nextPlayer()
{
	m_currentPlayer++;
	m_currentPlayer %= m_movingObjects.size();
}

void Board::handleCollision()
{
	for (auto& movingObj : m_movingObjects)
	{
		//Collision of dynamic object Vs static object 
		for (auto& staticObj : m_staticObjects)
		{
			if (movingObj->checkCollision(*staticObj))
				movingObj->handleCollision(*staticObj);

		}
		//Collision of dynamic object Vs Midget 
		for (auto& movingMidg : m_midgets)
		{
			if (movingObj->checkCollision(movingMidg))
				movingObj->handleCollision(movingMidg);
		}
		//Collision of dynamic object Vs Teleport
		bool teleportCollision = false;
		for (auto& teleport : m_teleports)
		{
			if (movingObj->checkCollision(teleport))
			{
				movingObj->handleCollision(teleport);
				teleportCollision = true;
			}
		}
		if (!teleportCollision)
			movingObj->notOnTeleport();

	}
	// Collision of Midget Vs static object
	for (auto& movingMidg : m_midgets) {
		for (auto& staticObj : m_staticObjects)
		{
			if (movingMidg.checkCollision(*staticObj))
				movingMidg.handleCollision(*staticObj);
		}
	}

	afterCollision();
}

void Board::afterCollision()
{
	
	for (int i = 0; i < m_staticObjects.size(); i++)
	{
		auto& staticObj = m_staticObjects[i];
		if (!staticObj->isExsit())
		{
			auto orc = dynamic_cast <Orc*>(staticObj.get());
			staticObj.release();
			m_staticObjects.erase(m_staticObjects.begin() + i);

			if (orc)
			{
				m_staticObjects.emplace_back(createStaticObject(ObjectType::Key, orc->getLocation()));
			}

		}
	}

}
void Board::locateTeleportDest()
{
	for (size_t currTeleport = 0; currTeleport < m_teleports.size(); currTeleport++)
	{
		if (currTeleport % 2 == 0 && (currTeleport + 1) < m_teleports.size())
			m_teleports[currTeleport].locateDest(m_teleports[(currTeleport + 1)].getLocation());
		else
			m_teleports[currTeleport].locateDest(m_teleports[(currTeleport - 1)].getLocation());
	}
}

bool Board::isWin()
{
	return m_win;
}
