#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <cassert>

class TextureCodex
{
public:
	TextureCodex();
	void LoadTextures();
	void LoadStrings();
	sf::Texture& GetTexture( int Texture_AtPos );
	sf::Texture& GetbackgroundTexture();

private:
	const int TotalBlockTextures = 7;
	std::string BlockStrings[7];
	sf::Texture BlockTextures[7];
	sf::Texture BackgroundTexture;
};