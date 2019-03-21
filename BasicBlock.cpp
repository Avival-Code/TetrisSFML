#include "BasicBlock.h"

BasicBlock::BasicBlock(Vef2 Pos_in, sf::Texture & Texture_in)
	:
	Position(Pos_in),
	Sprite(sf::Sprite(Texture_in))
{
	Sprite.setPosition({ Position.x, Position.y });
	IsActive = true;
}

void BasicBlock::Draw(sf::RenderWindow & wnd)
{
	if( IsActive )
	{
		wnd.draw( Sprite );
	}
}

void BasicBlock::MoveBlock(Vef2 PositionOffset)
{
	Position += PositionOffset;
	Sprite.setPosition( { Position.x, Position.y } );
}

void BasicBlock::ActivateBlock()
{
	IsActive = true;
}

void BasicBlock::DeactivateBlock()
{
	IsActive = false;
}

void BasicBlock::SetPosition( Vef2 NewPosition )
{
	Position = NewPosition;
	Sprite.setPosition( { Position.x, Position.y } );
}

Vef2 & BasicBlock::GetPosition()
{
	return Position;
}

bool BasicBlock::CheckActiveStatus()
{
	return IsActive;
}
