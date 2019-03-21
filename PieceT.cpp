#include "PieceT.h"

PieceT::PieceT(Vef2 & Start_Pos, sf::Texture & Texture)
	:
	Tetromino( Start_Pos, Texture )
{
	ArrangePieceBlocks();
}

void PieceT::ResetBlockPositions()
{
	Tetromino::ResetBlockPositions();
	ArrangePieceBlocks();
}

void PieceT::ArrangePieceBlocks()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x - BasicBlock::BlockSideLength, CenterPiecePosition.y ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + BasicBlock::BlockSideLength ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x + BasicBlock::BlockSideLength, CenterPiecePosition.y ) );
}

void PieceT::RotatePieceLeft()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y - BasicBlock::BlockSideLength ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x - BasicBlock::BlockSideLength, CenterPiecePosition.y ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + BasicBlock::BlockSideLength ) );
}

void PieceT::RotatePieceDown()
{
	ArrangePieceBlocks();
}

void PieceT::RotatePieceRight()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y - BasicBlock::BlockSideLength ) );
	ShapeBlocks[2].SetPosition( Vef2( CenterPiecePosition.x + BasicBlock::BlockSideLength, CenterPiecePosition.y ) );
	ShapeBlocks[3].SetPosition( Vef2( CenterPiecePosition.x, CenterPiecePosition.y + BasicBlock::BlockSideLength ) );
}

void PieceT::RotatePieceUp()
{
	Vef2 CenterPiecePosition = ShapeBlocks[0].GetPosition();
	ShapeBlocks[1].SetPosition(Vef2(CenterPiecePosition.x - BasicBlock::BlockSideLength, CenterPiecePosition.y));
	ShapeBlocks[2].SetPosition(Vef2(CenterPiecePosition.x, CenterPiecePosition.y - BasicBlock::BlockSideLength));
	ShapeBlocks[3].SetPosition(Vef2(CenterPiecePosition.x + BasicBlock::BlockSideLength, CenterPiecePosition.y));
}
