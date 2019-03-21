#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "TextureCodex.h"

class Background
{
public:
	Background( Vef2 Position_in, TextureCodex& Codex );
	void Draw( sf::RenderWindow& wnd );
	void SetPosition( Vef2 NewPosition );

private:
	Vef2 Position;
	sf::Sprite Sprite;
};