#include "Menu.h"

//-----------------------------------------------------------------------------
Menu::Menu()
	:m_background(TextureHandle::use().getTexture(textures_type::Background)),
	m_instructions(TextureHandle::use().getTexture(textures_type::Instruction)),
	m_eventType(event_type::Menu)
	
{
	loadButtons();
}



void Menu::loadButtons()
 {	
		
	m_buttons.emplace_back(TextureHandle::use()
		.getTexture((textures_type::PlayButton))).setPosition(450, 400);
	m_buttons.emplace_back(TextureHandle::use()
		.getTexture(textures_type::ExitButton)).setPosition(450,300);
	m_buttons.emplace_back(TextureHandle::use()
		.getTexture(textures_type::InstructionButton)).setPosition(450, 200);
	m_buttons.emplace_back(TextureHandle::use()
		.getTexture(textures_type::GoBackButton)).setPosition(450, 650);
}

void Menu::runMenu(sf::RenderWindow& window)
{
	buttons_type type;
	SoundHandle::instance().startMenuMusic();

	while (window.isOpen())
	{	
		
		window.clear();
		m_eventType == event_type::Menu ? drawMenu(window) : drawInstruction(window);
		window.display();
		sf::Event event;
		while (window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
			{
				type = eventLocation(window, event);
				SoundHandle::instance().mouseClick();
				break;
			} 
				
			}
			eventType(window, type);
			if (m_endMenu) {
				SoundHandle::instance().pauseMenuSound();
				return;
			}
			break;
		}
	}
}



void Menu::drawInstruction(sf::RenderWindow& window)
{
	window.draw(m_instructions);
	window.draw(m_buttons[3]);
}
void Menu::drawMenu(sf::RenderWindow& window)
{
	window.draw(m_background);
	window.draw(m_buttons[0]);
	window.draw(m_buttons[1]);
	window.draw(m_buttons[2]);

}

void Menu::eventType(sf::RenderWindow& window, const buttons_type& type)
{
	
	switch (type)
	{
	case buttons_type::Play:
		m_endMenu = true;
		break;
	case buttons_type::Exit:
		window.close();
		break;
	case buttons_type::Instruction:
		m_eventType = event_type::Instruction;
		break;
	case buttons_type::GoBack:
		m_eventType = event_type::Menu;
		break;
	case buttons_type::None:
		break;
	}

}

buttons_type Menu::eventLocation(sf::RenderWindow& window, sf::Event event)
{
	auto location = window.mapPixelToCoords({ event.mouseButton.x,event.mouseButton.y });

	
		if (m_buttons[0].getGlobalBounds().contains(location))
			return buttons_type::Exit;
		else if (m_buttons[1].getGlobalBounds().contains(location))
			return buttons_type::Instruction;
		else if (m_buttons[2].getGlobalBounds().contains(location))
			return buttons_type::Play;
		else if(m_buttons[3].getGlobalBounds().contains(location))
			return buttons_type::GoBack;
		else
			return buttons_type::None;

}
