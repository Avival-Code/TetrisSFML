#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Vec2.h"

class ScoreBoard
{
public:
	ScoreBoard( Vef2 ScorePosition_in, Vef2 LineTypePosition_in, std::string FontFileName );
	void SetBorder( sf::RectangleShape& Rect, Vef2 Position, Vef2 Size, sf::Color OutlineColor, sf::Color FillColor);
	void SetLineTypeText();
	void SetText( sf::Text& Text, std::string Output, int Value, sf::Color Color, Vef2 Position );
	void UpdateStrings();
	void Draw( sf::RenderWindow& wnd );
	std::string ConcatStrings( std::string Output, int Value );
	void Update();
	void UpdateScore( int Value );
	int GetScore();

private:
	Vef2 ScorePosition;
	Vef2 LineTypePosition;
	sf::RectangleShape ScoreBorder;
	sf::RectangleShape LineTypeborder;
	std::string Strings[ 5 ] = { "Score: ", "Single: ", "Double: ", "Triple: ", "Tetris: " };
	sf::Text ScoreText;
	sf::Text LineTypeText[ 4 ];
	sf::Font Font;
	int Values[ 5 ] = { 0, 0, 0, 0, 0 };
};