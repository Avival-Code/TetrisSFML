#include "PieceL.h"

PieceL::PieceL(Vef2 & Start_Pos, sf::Texture & Texture)
	:
	Tetromino( Start_Pos, Texture )
{
	ArrangePieceBlocks();
}

void PieceL::ResetBlockPositions()
{
	Tetromino::ResetBlockPositions();
	ArrangePieceBlocks();
}

void PieceL::ArrangePieceBlocks()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x + 25.0f, CenterPiecePosition.y ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x - 25.0f, CenterPiecePosition.y ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x - 25.0f, CenterPiecePosition.y + 25.0f ) );
}

void PieceL::RotatePieceLeft()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + 25.0f ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y - 25.0f ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x - 25.0f, CenterPiecePosition.y - 25.0f));
}

void PieceL::RotatePieceDown()
{
	ArrangePieceBlocks();
}

void PieceL::RotatePieceRight()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y - 25.0f ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + 25.0f ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x + 25.0f, CenterPiecePosition.y + 25.0f ) );
}

void PieceL::RotatePieceUp()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x - 25.0f, CenterPiecePosition.y ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x + 25.0f, CenterPiecePosition.y ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x + 25.0f, CenterPiecePosition.y - 25.0f ) );
}
