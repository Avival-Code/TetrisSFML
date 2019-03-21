#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include "PieceO.h"
#include "PieceI.h"
#include "PieceS.h"
#include "PieceZ.h"
#include "PieceL.h"
#include "PieceJ.h"
#include "PieceT.h"
#include "SoundCloud.h"

class PieceContainer
{
public:
	PieceContainer( Vef2 Start_Pos, TextureCodex& Codex );
	~PieceContainer();
	void Draw(sf::RenderWindow& wnd);
	void UpdateActivePieces( std::vector<float> YCoordinates, SoundCloud& Cloud );
	void ShufflePieces();
	void RecyclePieces();
	Tetromino& GetRandomUnusedPiece();
	void LowerAllActivePieceBlockPositions( float YCoordinates );
	void AddActivePiece( Tetromino& CurrentPiece );
	void DeactivateBlocksFromActivePieces( float YCoordinates );
	std::vector<Tetromino*>& GetActivePieces();
	bool IsPieceActive( int PieceIndex );

private:
	void LoadTetrisPieces( Vef2 Start_Pos, TextureCodex& Codex );
	void LoadOPiece( Vef2 Start_Pos, sf::Texture& Texture );
	void LoadIPiece( Vef2 Start_Pos, sf::Texture& Texture );
	void LoadSPiece( Vef2 Start_Pos, sf::Texture& Texture );
	void LoadZPiece( Vef2 Start_Pos, sf::Texture& Texture );
	void LoadLPiece( Vef2 Start_Pos, sf::Texture& Texture );
	void LoadJPiece( Vef2 Start_Pos, sf::Texture& Texture );
	void LoadTPiece( Vef2 Start_Pos, sf::Texture& Texture );

private:
	const int EachPieceTotal = 10;
	std::vector<Tetromino*> TetrisPieces;
	std::vector<Tetromino*> ActivePieces;
};