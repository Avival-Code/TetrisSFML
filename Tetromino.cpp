#include "Tetromino.h"

Tetromino::Tetromino(Vef2& Start_Pos, sf::Texture & Texture)
	:
	BoardStartPos( &Start_Pos )
{
	LoadBlocks( Texture );
}

void Tetromino::LoadBlocks( sf::Texture & texture)
{
	for( int i = 0; i < TotalBlocks; i++)
	{
		ShapeBlocks.emplace_back( BasicBlock( Vef2( BoardStartPos->x + ( CenterBlockPosition.x * 25 ), 
													BoardStartPos->y + ( CenterBlockPosition.y * 25 ) ), texture ) );
	}
}

void Tetromino::Draw(sf::RenderWindow & wnd)
{
	assert( !ShapeBlocks.empty() );
	for( int i = 0; i < TotalBlocks; i++ )
	{
		ShapeBlocks[i].Draw( wnd );
	}
}

void Tetromino::MovePiece( Vef2 PositionOffset )
{
	for( int i = 0; i < TotalBlocks; i++ )
	{
		ShapeBlocks[i].MoveBlock( PositionOffset );
	}
}

void Tetromino::MoveBlockAt(int BlockIndex, float Offset)
{
	ShapeBlocks[BlockIndex].MoveBlock( Vef2( 0.0f, Offset ) );
}

void Tetromino::SetBlockPosition(int BlockIndex, Vef2 NewPosition)
{
	ShapeBlocks[ BlockIndex ].SetPosition( NewPosition );
}

void Tetromino::ResetBlockPositions()
{
	for( int Block = 0; Block < TotalBlocks; Block++ )
	{
		Vef2 BoardPos = Vef2( 275.0f, 50.0f );
		Vef2 temp = Vef2( BoardPos.x + ( CenterBlockPosition.x * 25 ), BoardPos.y + ( CenterBlockPosition.y * 25 ) );
		SetBlockPosition( Block, temp );
		ShapeBlocks[ Block ].ActivateBlock();
	}
	IsOnField = false;
}

void Tetromino::RotatePiece()
{
	if( ShapeBlocks[ 0 ].GetPosition().x != 275.0f && ShapeBlocks[ 0 ].GetPosition().x != 500.0f )
	{
		switch ((int)Direction)
		{
		case  0:
			RotatePieceRight();
			Direction = ShapeDirection::Right;
			break;

		case 1:
			RotatePieceUp();
			Direction = ShapeDirection::Up;
			break;

		case 2:
			RotatePieceLeft();
			Direction = ShapeDirection::Left;
			break;

		case 3:
			RotatePieceDown();
			Direction = ShapeDirection::Down;
			break;
		}
	}
}

void Tetromino::RotatePieceLeft()
{
}

void Tetromino::RotatePieceDown()
{
}

void Tetromino::RotatePieceRight()
{
}

void Tetromino::RotatePieceUp()
{
}

void Tetromino::ArrangePieceBlocks()
{
}

Vef2 Tetromino::GetBlockPositionCoordinates( int BlockIndex )
{
	assert( !ShapeBlocks.empty() );
	return ShapeBlocks[ BlockIndex ].GetPosition();
}

Vef2 Tetromino::GetBottomBlockCoordinates(int BlockIndex)
{
	assert( !ShapeBlocks.empty() );
	return Vef2( ShapeBlocks[ BlockIndex ].GetPosition().x, ShapeBlocks[BlockIndex].GetPosition().y + BasicBlock::BlockSideLength );
}

Vef2 Tetromino::GetRightHandBlockCoordinates(int BlockIndex)
{
	assert( !ShapeBlocks.empty() );
	return Vef2( ShapeBlocks[ BlockIndex ].GetPosition().x + BasicBlock::BlockSideLength, ShapeBlocks[ BlockIndex ].GetPosition().y );
}

Vef2 Tetromino::GetLeftHandBlockCoordinates(int BlockIndex)
{
	assert( !ShapeBlocks.empty() );
	return Vef2( ShapeBlocks[ BlockIndex ].GetPosition().x - BasicBlock::BlockSideLength, ShapeBlocks[ BlockIndex ].GetPosition().y );
}

bool Tetromino::CheckIfBlockIsActive(int BlockIndex)
{
	return ShapeBlocks[ BlockIndex ].CheckActiveStatus();
}

bool Tetromino::CheckIfPieceIsActive()
{
	for( int Block = 0; Block < TotalBlocks; Block++)
	{
		if( CheckIfBlockIsActive( Block ) )
		{
			return true;
		}
	}
	return false;
}

void Tetromino::DeactivateBlockAt( int BlockIndex )
{
	ShapeBlocks[ BlockIndex ].DeactivateBlock();
}
