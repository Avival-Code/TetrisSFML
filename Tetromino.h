#pragma once
#include <SFMl/Graphics.hpp>
#include <vector>
#include <cassert>
#include "TextureCodex.h"
#include "BasicBlock.h"

class Tetromino
{
public:
	enum class ShapeDirection
	{
		Down,
		Right,
		Up,
		Left
	};

	Tetromino() = default;
	Tetromino( Vef2& Start_Pos, sf::Texture& Texture );
	void LoadBlocks( sf::Texture& texture );
	void Draw( sf::RenderWindow& wnd );
	void MovePiece( Vef2 PositionOffset );
	void MoveBlockAt( int BlockIndex, float Offset );
	void SetBlockPosition( int BlockIndex, Vef2 NewPosition );
	virtual void ResetBlockPositions();
	virtual void RotatePiece();
	virtual void RotatePieceLeft();
	virtual void RotatePieceDown();
	virtual void RotatePieceRight();
	virtual void RotatePieceUp();
	virtual void ArrangePieceBlocks();
	Vef2 GetBlockPositionCoordinates( int BlockIndex );
	Vef2 GetBottomBlockCoordinates( int BlockIndex );
	Vef2 GetRightHandBlockCoordinates( int BlockIndex );
	Vef2 GetLeftHandBlockCoordinates( int BlockIndex );
	bool CheckIfBlockIsActive( int BlockIndex );
	bool CheckIfPieceIsActive();
	void DeactivateBlockAt( int BlockIndex );

public:
	static constexpr int TotalBlocks = 4;
	bool IsOnField = false;

private:
	const Vef2* BoardStartPos;

protected:
	ShapeDirection Direction = ShapeDirection::Down;
	std::vector<BasicBlock> ShapeBlocks;
	Vef2 CenterBlockPosition = Vef2( 5, 0 );
};