#include "FileManager\TexturesHandle.h"
#include <iostream>

TextureHandle::TextureHandle() {
	loadTextures();
}

void TextureHandle::loadTextures() {
	const auto fileNames = std::array <std::string, (size_t)textures_type::TextureCount>{ 
			"Background.png"			,
			"Chair.png"			,
			"Fire.png"			,
			"Gate.png"			,
			"GateOpen.png",
			"Key.png"			,
			"King.png"			,
			"Mage.png"			,
			"Midget.png"			,
			"Orc.png",
			"Teleport.png",
			"Thief.png"			,
			"ThiefWithKey.png",
			"Wall.png",
			"Warrior.png",
			"ExitButton.png",	
			"InstructionsButton.png",
			"PlayButton.png",
			"GoBackButton.png",
			"Instruction.png"
	};






	for (auto i = std::make_pair(m_textures.begin(), fileNames.cbegin()); 
		i.first < m_textures.end(); ++i.first, ++i.second) {
		i.first->loadFromFile(*i.second);
	}

	//std::cout << m_textures.size();
}

TextureHandle& TextureHandle::use()
{
	static TextureHandle textureHandleObj;
	return textureHandleObj;
}

const sf::Texture& TextureHandle::getTexture(textures_type type) const
{
	return m_textures[(size_t)type];
}
