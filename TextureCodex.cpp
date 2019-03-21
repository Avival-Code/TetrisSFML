#include "TextureCodex.h"

TextureCodex::TextureCodex()
{
	LoadStrings();
	LoadTextures();
}

void TextureCodex::LoadTextures()
{
	BackgroundTexture.loadFromFile( "GreenStriped Background.png" );
	for( int i = 0; i < TotalBlockTextures; i++)
	{
		BlockTextures[i].loadFromFile( BlockStrings[i] );
	}
}

void TextureCodex::LoadStrings()
{
	BlockStrings[0] = "Red Block Sprite 25x25.png";
	BlockStrings[1] = "Blue Block Sprite 25x25.png";
	BlockStrings[2] = "Green Block Sprite 25x25.png";
	BlockStrings[3] = "Orange Block Sprite 25x25.png";
	BlockStrings[4] = "Purple Block Sprite 25x25.png";
	BlockStrings[5] = "Cyan Block Sprite 25x25.png";
	BlockStrings[6] = "Yellow Block Sprite 25x25.png";
}

sf::Texture& TextureCodex::GetTexture(int Texture_AtPos)
{
	assert( Texture_AtPos > -1 );
	assert( Texture_AtPos < 7 );

	return BlockTextures[ Texture_AtPos ];
}

sf::Texture& TextureCodex::GetbackgroundTexture()
{
	return BackgroundTexture;
}
