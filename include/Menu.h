#pragma once
#include <SFML/Graphics.hpp>
#include "FileManager/TexturesHandle.h"
#include "FileManager/SoundHandle.h"
#include<vector>


enum class buttons_type : size_t
{
	
	Play,
	Exit,
	Instruction,
	None,
	GoBack,
	ButtonsCount
};

enum class event_type : size_t
{
	Menu,
	Instruction
};


class Menu
{
public:
	Menu();
	void runMenu(sf::RenderWindow& window);

private:
	buttons_type eventLocation(sf::RenderWindow& window, sf::Event event);
	void eventType(sf::RenderWindow& window, const buttons_type& type);
	void loadButtons();
	void drawMenu(sf::RenderWindow& window);
	void drawInstruction(sf::RenderWindow& window);
	sf::Sprite m_background;
	sf::Sprite m_instructions;
	std::vector<sf::Sprite> m_buttons;
	bool m_endMenu = false;
	event_type m_eventType;
};