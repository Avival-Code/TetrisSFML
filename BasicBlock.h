#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"

class BasicBlock
{
public:
	BasicBlock() = default;
	BasicBlock( Vef2 Pos_in, sf::Texture& Texture_in );
	void Draw( sf::RenderWindow& wnd );
	void MoveBlock( Vef2 PositionOffset );
	void ActivateBlock();
	void DeactivateBlock();
	void SetPosition( Vef2 NewPosition );
	Vef2& GetPosition();
	bool CheckActiveStatus();

public:
	static constexpr float BlockSideLength = 25.0f;

private:
	bool IsActive = false;
	Vef2 Position;
	sf::Sprite Sprite;
};
