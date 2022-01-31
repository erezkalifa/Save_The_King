#include "FileManager/SoundHandle.h"
#include <iostream>

SoundHandle::SoundHandle()
	
{
	
	std::array <std::string, (size_t)sound_type::SoundCount> soundNames =
	{
		"GameSound.ogg",
		"MenuSound.wav",
		"mouseClick.wav",
		"Teleport.wav", 
		"KeyPick.wav",
		"Orc.wav"
		
	};

	for (int i = 0; i < soundNames.size(); i++)
	{
		m_buffers[i].loadFromFile(soundNames[i]);
	}

}
//------------------------------------------------------------
SoundHandle& SoundHandle::instance()
{
	static SoundHandle soundHandle;
	return soundHandle;
}
//------------------------------------------------------------
void SoundHandle::startGameMusic()
{
	m_sounds[0].setBuffer(m_buffers[0]);
	m_sounds[0].play();
	m_sounds[0].setLoop(true);
}
//------------------------------------------------------------
void SoundHandle::startMenuMusic()
{
	m_sounds[1].setBuffer(m_buffers[1]);
	m_sounds[1].play();
	m_sounds[1].setLoop(true);
}
//------------------------------------------------------------
void SoundHandle::mouseClick()
{
	m_sounds[2].setBuffer(m_buffers[2]);
	m_sounds[2].play();
}
void SoundHandle::teleportSound()
{
	m_sounds[3].setBuffer(m_buffers[3]);
	m_sounds[3].play();
}

void SoundHandle::keyPickSound()
{
	m_sounds[4].setBuffer(m_buffers[4]);
	m_sounds[4].play();
}
void SoundHandle::orcSound()
{
	m_sounds[5].setBuffer(m_buffers[5]);
	m_sounds[5].play();
}
//---------------------------------------------
void SoundHandle::pauseMenuSound()
{
	m_sounds[1].pause();
}

