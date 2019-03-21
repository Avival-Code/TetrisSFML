#include "UserPiece.h"

UserPiece::UserPiece(Tetromino& Piece, const Vef2& BoardPosition )
	:
	ControlledPiece( &Piece ),
	BoardPosition( BoardPosition )
{
	ControlledPiece->IsOnField = true;
}

void UserPiece::UpdatePiece(float DeltaTime, int Score, std::vector<Vef2>& BoardBottoms, PieceContainer& TetrisPieces )
{
	HoldTime += DeltaTime;
	UserMoveholdTime += DeltaTime;
	RotateHoldTime += DeltaTime;
	RotatePiece();
	MovePieceSides( BoardBottoms, TetrisPieces.GetActivePieces() );

	if( ReachedBoardBottom( BoardBottoms ) && HoldTime > TotalHoldTime )
	{
		ReleasePiece( TetrisPieces );
	}
	else
	{
		AutomaticMovePieceDown( BoardBottoms );
	}

	LowerHoldTime( Score );
	SetNewPiece( TetrisPieces );
}

bool UserPiece::ReachedBoardBottom( std::vector<Vef2>& BoardBottoms )
{
	for( int Block = 0; Block < Tetromino::TotalBlocks; Block++ )
	{
		if( TestBottomBlockCoordinates( BoardBottoms, Block ) )
		{
			return true;
		}
	
	}
	return false;
}

bool UserPiece::PieceIsOnRightSide( std::vector<Tetromino*>& ActivePieces )
{
	for( int SelectedBlock = 0; SelectedBlock < Tetromino::TotalBlocks; SelectedBlock++ )
	{
		for( int Piece = 0; Piece < (int)ActivePieces.size(); Piece++ )
		{
			for( int PieceBlock = 0; PieceBlock < Tetromino::TotalBlocks; PieceBlock++ )
			{
				if( TestRightBlockCoordinates( ActivePieces, Piece, PieceBlock, SelectedBlock ) )
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool UserPiece::PieceIsOnLeftSide(std::vector<Tetromino*>& ActivePieces)
{
	for (int SelectedBlock = 0; SelectedBlock < Tetromino::TotalBlocks; SelectedBlock++)
	{
		for (int Piece = 0; Piece < (int)ActivePieces.size(); Piece++)
		{
			for (int PieceBlock = 0; PieceBlock < Tetromino::TotalBlocks; PieceBlock++)
			{
				if ( TestLeftBlockCoordinates( ActivePieces, Piece, PieceBlock, SelectedBlock ) )
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool UserPiece::TestBottomBlockCoordinates(std::vector<Vef2>& BoardBottoms, int BlockIndex)
{
	int Index = int( (ControlledPiece->GetBottomBlockCoordinates( BlockIndex ).x - BoardPosition.x) / BasicBlock::BlockSideLength );
	if( ControlledPiece->CheckIfPieceIsActive() && ControlledPiece->GetBottomBlockCoordinates( BlockIndex ).y >= BoardBottoms[ Index ].y )
	{
		return true;
	}
	return false;
}

bool UserPiece::TestRightBlockCoordinates(std::vector<Tetromino*>& ActivePieces, int PieceIndex, int PieceBlockIndex, int SelectedBlockIndex)
{
	if( ActivePieces[ PieceIndex ]->CheckIfBlockIsActive( PieceBlockIndex ) &&
		ControlledPiece->GetRightHandBlockCoordinates( SelectedBlockIndex ) ==
		ActivePieces[ PieceIndex ]->GetBlockPositionCoordinates( PieceBlockIndex ) )
	{
		return true;
	}
	return false;
}

bool UserPiece::TestLeftBlockCoordinates(std::vector<Tetromino*>& ActivePieces, int PieceIndex, int PieceBlockIndex, int SelectedBlockIndex)
{
	if( ActivePieces[ PieceIndex ]->CheckIfBlockIsActive( PieceBlockIndex ) &&
	    ControlledPiece->GetLeftHandBlockCoordinates( SelectedBlockIndex ) ==
	    ActivePieces[ PieceIndex ]->GetBlockPositionCoordinates( PieceBlockIndex ) )
	{
		return true;
	}
	return false;
}

bool UserPiece::CanMoveLeft()
{
	bool CanMove = true;
	for( int Block = 0; Block < Tetromino::TotalBlocks; Block++ )
	{
		if( ControlledPiece->GetBlockPositionCoordinates( Block ).x  <= BoardPosition.x )
		{
			CanMove = false;
		}
	}
	return CanMove;
}

bool UserPiece::CanMoveRight()
{
	bool CanMove = true;
	for (int Block = 0; Block < Tetromino::TotalBlocks; Block++)
	{
		if (ControlledPiece->GetBlockPositionCoordinates( Block ).x >= 500.0f)
		{
			CanMove = false;
		}
	}
	return CanMove;
}

void UserPiece::ReleasePiece( PieceContainer& TetrisPieces )
{
	TetrisPieces.AddActivePiece( *ControlledPiece );
	ControlledPiece = nullptr;
	ResetHoldTime();
}

void UserPiece::SetNewPiece( PieceContainer& TetrisPieces )
{
	if( ControlledPiece == nullptr )
	{
		ControlledPiece = &TetrisPieces.GetRandomUnusedPiece();
		ControlledPiece->IsOnField = true;
	}
}

void UserPiece::ResetHoldTime()
{
	if( HoldTime > TotalHoldTime )
	{
		HoldTime = 0.0f;
	}
}

void UserPiece::ResetUserHoldTime()
{
	if( UserMoveholdTime > TotalUserHoldTime )
	{
		UserMoveholdTime = 0.0f;
	}
}

void UserPiece::ResetRotateHoldTime()
{
	if( RotateHoldTime > TotalRotateHoldTime )
	{
		RotateHoldTime = 0.0f;
	}
}

void UserPiece::RotatePiece()
{
	if( sf::Keyboard::isKeyPressed( sf::Keyboard::S )  && RotateHoldTime > TotalRotateHoldTime )
	{
		ControlledPiece->RotatePiece();
		ResetRotateHoldTime();
	}
}

void UserPiece::AutomaticMovePieceDown( std::vector<Vef2>& BoardBottoms )
{
	if( !ReachedBoardBottom( BoardBottoms ) && HoldTime > TotalHoldTime )
	{
		ControlledPiece->MovePiece( Vef2( 0.0f, BasicBlock::BlockSideLength ) );
		ResetHoldTime();
	}
}

void UserPiece::MovePieceSides( std::vector<Vef2>& BoardBottoms, std::vector<Tetromino*> ActivePieces )
{
	if (UserMoveholdTime > TotalUserHoldTime)
	{
		MovePieceLeft( ActivePieces );
		MovePieceRight( ActivePieces );
		MovePieceDown( BoardBottoms );
	}
}

void UserPiece::MovePieceLeft( std::vector<Tetromino*> ActivePieces )
{
	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) && CanMoveLeft() && !PieceIsOnLeftSide( ActivePieces ) )
	{
		ControlledPiece->MovePiece( Vef2( -BasicBlock::BlockSideLength, 0.0f ) );
		ResetUserHoldTime();
	}
}

void UserPiece::MovePieceRight( std::vector<Tetromino*> ActivePieces )
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) && CanMoveRight() && !PieceIsOnRightSide( ActivePieces ) )
	{
		ControlledPiece->MovePiece( Vef2( BasicBlock::BlockSideLength, 0.0f ) );
		ResetUserHoldTime();
	}
}

void UserPiece::MovePieceDown( std::vector<Vef2>& BoardBottoms )
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) && !ReachedBoardBottom( BoardBottoms ) )
	{
		ControlledPiece->MovePiece( Vef2( 0.0f, BasicBlock::BlockSideLength ) );
		ResetUserHoldTime();
	}
}

void UserPiece::LowerHoldTime(int Score)
{
	if( Score > ScoreToLowerHoldTime )
	{
		TotalHoldTime -= 0.08f;
		ScoreToLowerHoldTime += int( float(ScoreToLowerHoldTime) * 0.5f);
	}
}
