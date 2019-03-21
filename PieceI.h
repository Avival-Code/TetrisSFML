#pragma once
#include "Tetromino.h"

class PieceI : public Tetromino
{
public:
	PieceI(Vef2& Start_Pos, sf::Texture& Texture);
	void RotatePiece() override;
	void ResetBlockPositions() override;
	void ArrangePieceBlocks() override;
	void RotatePieceLeft() override;
	void RotatePieceDown() override;
	void RotatePieceRight() override;
	void RotatePieceUp() override;
};