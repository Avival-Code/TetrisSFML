#include "PieceZ.h"

PieceZ::PieceZ(Vef2 & Start_Pos, sf::Texture & Texture)
	:
	Tetromino( Start_Pos, Texture )
{
	ArrangePieceBlocks();
}

void PieceZ::ResetBlockPositions()
{
	Tetromino::ResetBlockPositions();
	ArrangePieceBlocks();
}

void PieceZ::ArrangePieceBlocks()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x - 25.0f, CenterPiecePosition.y ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + 25.0f ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x + 25.0f, CenterPiecePosition.y + 25.0f ) );
}

void PieceZ::RotatePieceLeft()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + 25.0f ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x + 25.0f, CenterPiecePosition.y ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x + 25.0f, CenterPiecePosition.y - 25.0f ) );
}

void PieceZ::RotatePieceDown()
{
	ArrangePieceBlocks();
}

void PieceZ::RotatePieceRight()
{
	RotatePieceLeft();
}

void PieceZ::RotatePieceUp()
{
	RotatePieceDown();
}
