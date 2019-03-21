#pragma once
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "TextureCodex.h"
#include "UserPiece.h"
#include "PieceContainer.h"
#include "ScoreBoard.h"
#include "SoundCloud.h"

class Board
{
public:
	Board( Vef2 Start_pos, TextureCodex& Codex );
	void SetBorder( Vef2& Position );
	void Draw( sf::RenderWindow& wnd );
	void Update( float DeltaTime, ScoreBoard& ScoreBoard, SoundCloud& Cloud, bool& GameOverStatus );
	void SetBottomPositionLimit();
	void UpdateBoardBottomPositionLimit( std::vector<Tetromino*>& ActivePieces );
	void RaiseBottomPositionLimit( Tetromino& ActivePiece );
	void RemoveEmptyBottomPositions( std::vector<Tetromino*>& ActivePieces );
	void LowerBottomPositionLimit();
	void EndGame( bool& GameOverStatus );
	std::vector<float> CheckBoardRowsIfFull( std::vector<Tetromino*>& ActivePieces, ScoreBoard& ScoreBoard );
	Vef2 GetHighestBottomPosition();

private:
	static constexpr float BoardLength = 250.0f;
	static constexpr float BoardHeight = 500.0f;
	const float BorderThickness = 5.0f;
	const int BlocksPerColumn = 20;
	const int BlocksPerLine = 10;
	sf::RectangleShape Border;
	std::vector<Vef2> BoardBottoms;
	Vef2 Position;
	PieceContainer TetrisPieces;
	UserPiece User;
};