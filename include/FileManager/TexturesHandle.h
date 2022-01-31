#pragma once
#include <SFML/Graphics.hpp>
#include <array>
// Singelton


enum class textures_type : size_t
{
	Background,
	Chair,
	Fire,
	Gate,
	GateOpen,
	Key,
	King,
	Mage,
	Midget,
	Orc,
	Teleport,
	Thief,
	ThiefWithKey,
	Wall,
	Warrior,
	PlayButton,
	ExitButton,
	InstructionButton,
	GoBackButton,
	Instruction,
	TextureCount
};


class TextureHandle {
public:
	static TextureHandle& use();
	const sf::Texture& getTexture(textures_type type) const;
private:
	TextureHandle();
	TextureHandle(const TextureHandle&) = default;
	TextureHandle& operator=(const TextureHandle&) = default;
	void loadTextures();
	std::array <sf::Texture, (size_t)textures_type::TextureCount> m_textures;
};