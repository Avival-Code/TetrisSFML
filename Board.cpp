#include "Board.h"

Board::Board(Vef2 Start_pos, TextureCodex& Codex)
	:
	Position(Start_pos),
	TetrisPieces( Position, Codex ),
	User( TetrisPieces.GetRandomUnusedPiece(), Position )
{
	SetBorder( Position );
	SetBottomPositionLimit();
}

void Board::SetBorder( Vef2& Position )
{
	Border.setPosition( { Position.x, Position.y } );
	Border.setSize( { BoardLength, BoardHeight } );
	Border.setOutlineThickness( BorderThickness );
	Border.setOutlineColor( sf::Color::Blue );
}

void Board::Draw(sf::RenderWindow & wnd)
{
	wnd.draw( Border );
	TetrisPieces.Draw( wnd );
}

void Board::Update( float DeltaTime, ScoreBoard& ScoreBoard, SoundCloud& Cloud, bool& GameOverStatus )
{
	User.UpdatePiece( DeltaTime, ScoreBoard.GetScore(), BoardBottoms, TetrisPieces );
	UpdateBoardBottomPositionLimit( TetrisPieces.GetActivePieces() );
	TetrisPieces.UpdateActivePieces( CheckBoardRowsIfFull( TetrisPieces.GetActivePieces(), ScoreBoard ), Cloud );
	EndGame( GameOverStatus );
}

void Board::SetBottomPositionLimit()
{
	Vef2 Bottoms = Vef2( Position.x, Position.y + BoardHeight );
	for( int i = 0; i < BlocksPerLine; i++ )
	{
		BoardBottoms.emplace_back( Bottoms.x + (float)( BasicBlock::BlockSideLength * i ), Bottoms.y );
	}
}

void Board::UpdateBoardBottomPositionLimit(std::vector<Tetromino*>& ActivePieces)
{
	for( int Piece = 0; Piece < (int)ActivePieces.size(); Piece++ )
	{
		RaiseBottomPositionLimit( *ActivePieces[ Piece ] );
	}
	RemoveEmptyBottomPositions( ActivePieces );
}

void Board::RaiseBottomPositionLimit( Tetromino& ActivePiece )
{
	for( int Block = 0; Block < Tetromino::TotalBlocks; Block++ )
	{
		Vef2 Temp = ActivePiece.GetBlockPositionCoordinates( Block );
		const int Index = int( (Temp.x - Position.x) / BasicBlock::BlockSideLength );
		if( ActivePiece.CheckIfBlockIsActive( Block ) && BoardBottoms[ Index ].y > Temp.y )
		{
			BoardBottoms[ Index ].y = Temp.y;
		}
	}
}

void Board::RemoveEmptyBottomPositions(std::vector<Tetromino*>& ActivePieces)
{
	Vef2 HighestPos = Vef2( 275.0f, 550.0f );
	for( int BottomPos = 0; BottomPos < (int)BoardBottoms.size(); BottomPos++ )
	{
		for( int Piece = 0; Piece < (int)ActivePieces.size(); Piece++ )
		{
			for( int PieceBlock = 0; PieceBlock < Tetromino::TotalBlocks; PieceBlock++ )
			{
				if( HighestPos.x == ActivePieces[ Piece ]->GetBlockPositionCoordinates( PieceBlock ).x && 
					HighestPos.y > ActivePieces[ Piece ]->GetBlockPositionCoordinates( PieceBlock ).y )
				{
					HighestPos = ActivePieces[ Piece ]->GetBlockPositionCoordinates( PieceBlock );
				}
			}
		}

		BoardBottoms[ BottomPos ] = HighestPos;
		HighestPos.x += BasicBlock::BlockSideLength;
		HighestPos.y = 550.0f;
	}
}

void Board::LowerBottomPositionLimit()
{
	for( int Position = 0; Position < (int)BoardBottoms.size(); Position++ )
	{
		if( BoardBottoms[ Position ].y < ( Board::Position.y + Board::BoardHeight) )
		{
			BoardBottoms[ Position ] += Vef2( 0.0f, BasicBlock::BlockSideLength );
		}
	}
}

void Board::EndGame(bool & GameOverStatus)
{
	if( GetHighestBottomPosition().y <= Position.y )
	{
		GameOverStatus = true;
	}
}

std::vector<float> Board::CheckBoardRowsIfFull( std::vector<Tetromino*>& ActivePieces, ScoreBoard& ScoreBoard )
{
	std::vector<float> YCoordinates;
	Vef2 TempPosition = Vef2( Position.x , ( Position.y + Board::BoardHeight ) - BasicBlock::BlockSideLength );
	int BlocksOnRow = 0;

	for( int Row = 0; Row < 20; Row++ )
	{
		for (int Column = 0; Column < 10; Column++)
		{
			for (int Piece = 0; Piece < (int)ActivePieces.size(); Piece++)
			{
				for (int Block = 0; Block < Tetromino::TotalBlocks; Block++)
				{
					if (ActivePieces[ Piece ]->CheckIfBlockIsActive( Block ) &&
						ActivePieces[ Piece ]->GetBlockPositionCoordinates( Block ) == TempPosition)
					{
						BlocksOnRow += 1;
					}
				}
			}
			TempPosition += Vef2( BasicBlock::BlockSideLength, 0.0f );
		}

		if (BlocksOnRow == 10)
		{
			LowerBottomPositionLimit();
			YCoordinates.emplace_back( TempPosition.y );
		}

		TempPosition -= Vef2( 0.0f, BasicBlock::BlockSideLength );
		TempPosition.x = Position.x;
		BlocksOnRow = 0;
	}
	ScoreBoard.UpdateScore( int( YCoordinates.size() ) );
	return YCoordinates;
}

Vef2 Board::GetHighestBottomPosition()
{
	Vef2 Temp = Vef2( 500.0f, 500.0f );
	for( auto Position = BoardBottoms.begin(); Position != BoardBottoms.end(); )
	{
		if( Position->y < Temp.y )
		{
			Temp = *Position;
		}
		else
		{
			++Position;
		}
	}
	return Temp;
}
