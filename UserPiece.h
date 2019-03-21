#pragma once
#include "PieceContainer.h"

class UserPiece
{
public:
	UserPiece() = default;
	UserPiece( Tetromino& Piece, const Vef2& BoardPosition );
	void UpdatePiece( float DeltaTime, int Score, std::vector<Vef2>& BoardBottoms, PieceContainer& TetrisPieces );
	bool ReachedBoardBottom( std::vector<Vef2>& BoardBottoms );
	bool PieceIsOnRightSide( std::vector<Tetromino*>& ActivePieces );
	bool PieceIsOnLeftSide( std::vector<Tetromino*>& ActivePieces );
	bool TestBottomBlockCoordinates( std::vector<Vef2>& BoardBottoms, int BlockIndex );
	bool TestRightBlockCoordinates( std::vector<Tetromino*>& ActivePieces, int PieceIndex, int PieceBlockIndex, int SelectedBlockIndex );
	bool TestLeftBlockCoordinates( std::vector<Tetromino*>& ActivePieces, int PieceIndex, int PieceBlockIndex, int SelectedBlockIndex );
	bool CanMoveLeft();
	bool CanMoveRight();
	void ReleasePiece( PieceContainer& TetrisPieces );
	void SetNewPiece( PieceContainer& TetrisPieces );
	void ResetHoldTime();
	void ResetUserHoldTime();
	void ResetRotateHoldTime();
	void RotatePiece();
	void AutomaticMovePieceDown( std::vector<Vef2>& BoardBottoms );
	void MovePieceSides( std::vector<Vef2>& BoardBottoms, std::vector<Tetromino*> ActivePieces );
	void MovePieceLeft( std::vector<Tetromino*> ActivePieces );
	void MovePieceRight( std::vector<Tetromino*> ActivePieces );
	void MovePieceDown( std::vector<Vef2>& BoardBottoms );
	void LowerHoldTime( int Score );

private:
	float HoldTime = 0.0f;
	float UserMoveholdTime = 0.0f;
	float RotateHoldTime = 0.0f;
	float TotalHoldTime = 1.0f;
	const float TotalUserHoldTime = 0.085f;
	const float TotalRotateHoldTime = 0.15f;
	int ScoreToLowerHoldTime = 500;
	const Vef2& BoardPosition;
	Tetromino* ControlledPiece = nullptr;

};