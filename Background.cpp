#include "Background.h"

Background::Background(Vef2 Position_in, TextureCodex & Codex)
	:
	Position( Position_in ),
	Sprite( Codex.GetbackgroundTexture() )
{
	sf::IntRect TextureBoundary = sf::IntRect(0, 0, 800, 600);
	Sprite.setPosition( { Position.x, Position.y } );
	Sprite.setTextureRect( TextureBoundary );
}

void Background::Draw(sf::RenderWindow & wnd)
{
	wnd.draw( Sprite );
}

void Background::SetPosition(Vef2 NewPosition)
{
	Position = NewPosition;
	Sprite.setPosition( { Position.x, Position.y } );
}
