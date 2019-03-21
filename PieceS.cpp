#include "PieceS.h"

PieceS::PieceS(Vef2 & Start_Pos, sf::Texture & Texture)
	:
	Tetromino( Start_Pos, Texture )
{
	ArrangePieceBlocks();
}

void PieceS::ResetBlockPositions()
{
	Tetromino::ResetBlockPositions();
	ArrangePieceBlocks();
}

void PieceS::ArrangePieceBlocks()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x + 25.0f, CenterPiecePosition.y ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x - 25.0f, CenterPiecePosition.y + 25.0f) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + 25.0f ) );
}

void PieceS::RotatePieceLeft()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y - 25.0f ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x + 25.0f, CenterPiecePosition.y + 25.0f ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x + 25.0f, CenterPiecePosition.y ) );
}

void PieceS::RotatePieceDown()
{
	ArrangePieceBlocks();
}

void PieceS::RotatePieceRight()
{
	RotatePieceLeft();
}

void PieceS::RotatePieceUp()
{
	ArrangePieceBlocks();
}
