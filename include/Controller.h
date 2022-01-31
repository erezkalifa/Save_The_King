#pragma once 
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Menu.h"



class Controller
{
public:
	Controller();
	void run();
	
	
private:
	void runGame();
	void runMenu();
	sf::RenderWindow m_window;
	Board m_board;
	Menu m_menu;
	sf::Sprite m_background;
	void draw();
	
	
};