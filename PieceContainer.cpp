#include "PieceContainer.h"
#include <algorithm>
#include <random>

PieceContainer::PieceContainer( Vef2 Start_Pos, TextureCodex& Codex )
{
	LoadTetrisPieces( Start_Pos, Codex );
	ShufflePieces();
}

PieceContainer::~PieceContainer()
{
	for( size_t i = 0; i < TetrisPieces.size(); i++ )
	{
		delete TetrisPieces[i];
	}
}

void PieceContainer::Draw(sf::RenderWindow & wnd)
{
	for( size_t i = 0; i < TetrisPieces.size(); i++ )
	{
		if ( TetrisPieces[i]->IsOnField )
		{
			TetrisPieces[i]->Draw(wnd);
		}
	}
}

void PieceContainer::UpdateActivePieces( std::vector<float> YCoordinates, SoundCloud& Cloud )
{
	RecyclePieces();
	if( !YCoordinates.empty() )
	{
		for( int Position = 0; Position < (int)YCoordinates.size(); Position++ )
		{
			DeactivateBlocksFromActivePieces( YCoordinates[ Position ] );
		}
		for(int Position = ( (int)YCoordinates.size() - 1 ); Position > -1 ; Position--)
		{
			LowerAllActivePieceBlockPositions( YCoordinates[ Position ] );
		}
		Cloud.GetSound( 3 ).play();
	}
}

void PieceContainer::ShufflePieces()
{
	auto rng = std::default_random_engine {};
	std::shuffle( std::begin( TetrisPieces ), std::end( TetrisPieces ), rng );
	std::shuffle( std::begin( TetrisPieces ), std::end( TetrisPieces ), rng );
}

Tetromino & PieceContainer::GetRandomUnusedPiece()
{
	std::random_device rd;
	std::mt19937 rng( rd() );
	std::uniform_int_distribution<int> NumDist( 0, (int)TetrisPieces.size() - 1 );
	int Index;

	do
	{
		Index = NumDist( rng );
	} 
	while ( TetrisPieces[ Index ]->IsOnField == true );
	return *TetrisPieces[ Index ];
}

void PieceContainer::LowerAllActivePieceBlockPositions( float YCoordinates)
{
	for( int Piece = 0; Piece < (int)ActivePieces.size(); Piece++ )
	{
		for( int Block = 0; Block < Tetromino::TotalBlocks; Block++ )
		{
			if( ActivePieces[ Piece ]->CheckIfBlockIsActive( Block ) &&
				ActivePieces[ Piece ]->GetBlockPositionCoordinates( Block ).y <= YCoordinates )
			{
				ActivePieces[ Piece ]->MoveBlockAt( Block, BasicBlock::BlockSideLength );
			}
		}
	}
}

void PieceContainer::AddActivePiece(Tetromino & CurrentPiece)
{
	ActivePieces.emplace_back( &CurrentPiece );
}

void PieceContainer::DeactivateBlocksFromActivePieces(float YCoordinates)
{
	for( int Piece = 0; Piece < ( int )ActivePieces.size(); Piece++ )
	{
		for( int Block = 0; Block < Tetromino::TotalBlocks; Block++ )
		{
			if( ActivePieces[ Piece ]->CheckIfBlockIsActive( Block ) && 
				ActivePieces[ Piece ]->GetBlockPositionCoordinates( Block ).y == YCoordinates )
			{
				ActivePieces[ Piece ]->DeactivateBlockAt( Block );
				ActivePieces[ Piece ]->SetBlockPosition( Block, Vef2( 0.0f, 0.0f ) );
			}
		}
	}
}

std::vector<Tetromino*>& PieceContainer::GetActivePieces()
{
	return ActivePieces;
}

void PieceContainer::RecyclePieces()
{
	for( auto Piece = ActivePieces.begin(); Piece != ActivePieces.end(); )
	{
		if( !(*Piece)->CheckIfPieceIsActive() )
		{
			(*Piece)->ResetBlockPositions();
			Piece = ActivePieces.erase(Piece);
		}
		else
		{
			++Piece;
		}
	}
}

bool PieceContainer::IsPieceActive(int PieceIndex)
{
	if( ActivePieces[ PieceIndex ]->CheckIfPieceIsActive() )
	{
		return true;
	}
	return false;
}

void PieceContainer::LoadTetrisPieces( Vef2 Start_Pos, TextureCodex& Codex )
{
	LoadOPiece( Start_Pos, Codex.GetTexture( 6 ) );
	LoadIPiece( Start_Pos, Codex.GetTexture( 0 ) );
	LoadSPiece( Start_Pos, Codex.GetTexture( 4 ) );
	LoadZPiece( Start_Pos, Codex.GetTexture( 2 ) );
	LoadLPiece( Start_Pos, Codex.GetTexture( 1 ) );
	LoadJPiece( Start_Pos, Codex.GetTexture( 3 ) );
	LoadTPiece( Start_Pos, Codex.GetTexture( 5 ) );
}

void PieceContainer::LoadOPiece( Vef2 Start_Pos, sf::Texture& Texture )
{
	for(int i = 0; i < EachPieceTotal; i++ )
	{
		TetrisPieces.emplace_back( new PieceO( Start_Pos, Texture ) );
	}
}

void PieceContainer::LoadIPiece( Vef2 Start_Pos, sf::Texture& Texture )
{
	for (int i = 0; i < EachPieceTotal; i++)
	{
		TetrisPieces.emplace_back( new PieceI( Start_Pos, Texture ) );
	}
}

void PieceContainer::LoadSPiece( Vef2 Start_Pos, sf::Texture& Texture )
{
	for (int i = 0; i < EachPieceTotal; i++)
	{
		TetrisPieces.emplace_back( new PieceS( Start_Pos, Texture ) );
	}
}

void PieceContainer::LoadZPiece( Vef2 Start_Pos, sf::Texture& Texture )
{
	for (int i = 0; i < EachPieceTotal; i++)
	{
		TetrisPieces.emplace_back( new PieceZ( Start_Pos, Texture ) );
	}
}

void PieceContainer::LoadLPiece( Vef2 Start_Pos, sf::Texture& Texture )
{
	for (int i = 0; i < EachPieceTotal; i++)
	{
		TetrisPieces.emplace_back( new PieceL( Start_Pos, Texture ) );
	}
}

void PieceContainer::LoadJPiece( Vef2 Start_Pos, sf::Texture& Texture )
{
	for (int i = 0; i < EachPieceTotal; i++)
	{
		TetrisPieces.emplace_back( new PieceJ( Start_Pos, Texture ) );
	}
}

void PieceContainer::LoadTPiece( Vef2 Start_Pos, sf::Texture& Texture )
{
	for (int i = 0; i < EachPieceTotal; i++)
	{
		TetrisPieces.emplace_back( new PieceT( Start_Pos, Texture ) );
	}
}
