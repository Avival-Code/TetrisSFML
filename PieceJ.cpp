#include "PieceJ.h"

PieceJ::PieceJ(Vef2 & Start_Pos, sf::Texture & Texture)
	:
	Tetromino( Start_Pos, Texture )
{
	ArrangePieceBlocks();
}

void PieceJ::ResetBlockPositions()
{
	Tetromino::ResetBlockPositions();
	ArrangePieceBlocks();
}

void PieceJ::ArrangePieceBlocks()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x - BasicBlock::BlockSideLength, CenterPiecePosition.y ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x + BasicBlock::BlockSideLength, CenterPiecePosition.y ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x + BasicBlock::BlockSideLength, CenterPiecePosition.y + BasicBlock::BlockSideLength) );
}

void PieceJ::RotatePieceLeft()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y - BasicBlock::BlockSideLength ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + BasicBlock::BlockSideLength ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x - BasicBlock::BlockSideLength, CenterPiecePosition.y + BasicBlock::BlockSideLength ) );
}

void PieceJ::RotatePieceDown()
{
	ArrangePieceBlocks();
}

void PieceJ::RotatePieceRight()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + BasicBlock::BlockSideLength ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y - BasicBlock::BlockSideLength ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x + BasicBlock::BlockSideLength, CenterPiecePosition.y - BasicBlock::BlockSideLength ) );
}

void PieceJ::RotatePieceUp()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x + BasicBlock::BlockSideLength, CenterPiecePosition.y ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x - BasicBlock::BlockSideLength, CenterPiecePosition.y ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x - BasicBlock::BlockSideLength, CenterPiecePosition.y - BasicBlock::BlockSideLength ) );
}
