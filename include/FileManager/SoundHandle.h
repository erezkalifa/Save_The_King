#pragma once
#include <SFML/Audio.hpp>
#include <array>
// Singelton



enum class sound_type : size_t
	{
		GameSound,
		MenuSound,
		mouseClick,
		Teleport,
		KeyPick,
		Orc,
		SoundCount
	
	};


class SoundHandle
{
public:

	~SoundHandle() = default;
	

	static SoundHandle& instance();

	void startMenuMusic();
	void startGameMusic();
	void mouseClick();
	void teleportSound();
	void orcSound();
	void keyPickSound();
	void pauseMenuSound();
	

private:
	SoundHandle();
	std::array <sf::SoundBuffer, (size_t)sound_type::SoundCount> m_buffers;
	std::array<sf::Sound, (size_t)sound_type::SoundCount> m_sounds;
	SoundHandle(const SoundHandle&) = delete;
	SoundHandle& operator=(const SoundHandle&) = delete;
};
