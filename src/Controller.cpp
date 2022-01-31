#include "Controller.h"
#include "FileManager/TexturesHandle.h"
#include "FileManager/SoundHandle.h"

const auto APP_TITLE = "SAVE THE KING"; //Screen title
const auto WINDOW_RESOLUTION = sf::Vector2u(1200, 800); //Screen resolutions

const auto FRAMES_LIMIT = 60;


Controller::Controller()
	:m_window({ WINDOW_RESOLUTION.x, WINDOW_RESOLUTION.y },
		APP_TITLE), m_background(TextureHandle::use().getTexture(textures_type::Background))
	
{
	m_window.setFramerateLimit(FRAMES_LIMIT);
}


void Controller::run()
{
	
	while (m_window.isOpen())
	{
		runMenu();
		if(m_window.isOpen())
		runGame();	
		
	}
}

void Controller::runGame()
{
	
	SoundHandle::instance().startGameMusic();
	
	while (m_window.isOpen())
	{			
		auto clock = sf::Clock();
		m_window.clear();
		draw();
		m_window.display();
		if (auto event = sf::Event{}; m_window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed:
			{
				switch (event.key.code)
				{
				case sf::Keyboard::P:
					m_board.nextPlayer();
					break;
				}
				break;
			}
			}
		}
		m_board.moveMidgets(clock);
		m_board.moveCurrentPlayer(clock.getElapsedTime());
		m_board.handleCollision();
	}
}

void Controller::runMenu()
{
	m_menu.runMenu(m_window);
}
void Controller::draw()
{
	
	m_window.draw(m_background);
	m_board.draw(m_window);
}


