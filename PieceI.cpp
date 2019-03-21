#include "PieceI.h"

PieceI::PieceI(Vef2 & Start_Pos, sf::Texture & Texture)
	:
	Tetromino( Start_Pos, Texture )
{
	ArrangePieceBlocks();
}

void PieceI::RotatePiece()
{
	if( ShapeBlocks[ 0 ].GetPosition().x != 300.0f )
	{
		Tetromino::RotatePiece();
	}
}

void PieceI::ResetBlockPositions()
{
	Tetromino::ResetBlockPositions();
	ArrangePieceBlocks();
}

void PieceI::ArrangePieceBlocks()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x + 25.0f, CenterPiecePosition.y ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x - 25.0f, CenterPiecePosition.y ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x - 50.0f, CenterPiecePosition.y ) );
}

void PieceI::RotatePieceLeft()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y - 25.0f ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + 25.0f ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + 50.0f ) );
}

void PieceI::RotatePieceDown()
{
	ArrangePieceBlocks();
}

void PieceI::RotatePieceRight()
{
	RotatePieceLeft();
}

void PieceI::RotatePieceUp()
{
	RotatePieceDown();
}
