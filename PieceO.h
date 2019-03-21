#pragma once
#include "Tetromino.h"

class PieceO: public Tetromino
{
public:
	PieceO( Vef2& Start_Pos, sf::Texture& Texture );
	void ResetBlockPositions() override;
	void ArrangePieceBlocks() override;
	void RotatePieceLeft() override;
	void RotatePieceDown() override;
	void RotatePieceRight() override;
	void RotatePieceUp() override;
};