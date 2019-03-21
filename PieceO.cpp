#include "PieceO.h"

PieceO::PieceO(Vef2 & Start_Pos, sf::Texture & Texture)
	:
	Tetromino( Start_Pos, Texture )
{
	ArrangePieceBlocks();
}

void PieceO::ResetBlockPositions()
{
	Tetromino::ResetBlockPositions();
	ArrangePieceBlocks();
}

void PieceO::ArrangePieceBlocks()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x - 25.0f, CenterPiecePosition.y ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x - 25.0f, CenterPiecePosition.y + 25.0f ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + 25.0f ) );
}

void PieceO::RotatePieceLeft()
{
}

void PieceO::RotatePieceDown()
{
}

void PieceO::RotatePieceRight()
{
}

void PieceO::RotatePieceUp()
{
}
