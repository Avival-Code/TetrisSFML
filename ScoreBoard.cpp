#include "ScoreBoard.h"
#include <cassert>

ScoreBoard::ScoreBoard(Vef2 ScorePosition_in, Vef2 LineTypePosition_in, std::string FontFileName)
	:
	ScorePosition( ScorePosition_in ),
	LineTypePosition( LineTypePosition_in )
{
	Font.loadFromFile( FontFileName );
	SetBorder( ScoreBorder, ScorePosition, Vef2( 120.0f, 50.0f ), sf::Color::Blue , sf::Color::Black );
	SetBorder( LineTypeborder, LineTypePosition, Vef2( 100.0f, 200.0f ), sf::Color::Blue, sf::Color::Black );
	SetText( ScoreText, Strings[ 0 ], Values[ 0 ], sf::Color::White, Vef2( ScorePosition.x + 5.0f, ScorePosition.y + 5.0f ) );
	SetLineTypeText();
}

void ScoreBoard::SetBorder(sf::RectangleShape& Rect, Vef2 Position, Vef2 Size, sf::Color OutlineColor, sf::Color FillColor )
{
	Rect.setPosition( { Position.x, Position.y } );
	Rect.setSize( { Size.x, Size.y } );
	Rect.setFillColor( FillColor );
	Rect.setOutlineThickness( 5.0f );
	Rect.setOutlineColor( OutlineColor );
}

void ScoreBoard::SetLineTypeText()
{
	for( int Text = 0; Text < 4; Text++ )
	{
		SetText( LineTypeText[ Text ], Strings[ Text + 1 ], Values[ Text + 1 ], sf::Color::White, 
				 Vef2( LineTypePosition.x + 15.0f, LineTypePosition.y + ( Text * 50.0f ) ) );
	}
}

void ScoreBoard::SetText(sf::Text & Text, std::string Output, int Value, sf::Color Color, Vef2 Position )
{
	Text.setFont( Font );
	Text.setString( ConcatStrings( Output, Value ) );
	Text.setFillColor( Color );
	Text.setPosition( { Position.x, Position.y } );
}

void ScoreBoard::UpdateStrings()
{
	for( int Text = 0; Text < 5; Text++ )
	{
		if( Text == 0)
		{
			ScoreText.setString( ConcatStrings( Strings[ Text ], Values[ Text ] ) );
		}
		else
		{
			LineTypeText[ Text - 1 ].setString( ConcatStrings( Strings[ Text ], Values[ Text ] ) );
		}
	}
}

void ScoreBoard::Draw(sf::RenderWindow & wnd)
{
	wnd.draw( ScoreBorder );
	wnd.draw( ScoreText );
	wnd.draw( LineTypeborder );
	for( int i = 0; i < 4; i++ )
	{
		wnd.draw( LineTypeText[ i ] );
	}
}

std::string ScoreBoard::ConcatStrings(std::string Output, int Value)
{
	std::string temp = Output + std::to_string( Value );
	return temp;
}

void ScoreBoard::Update()
{
	UpdateStrings();
}

void ScoreBoard::UpdateScore(int Value)
{
	assert( Value < 5 );
	switch( Value )
	{
	case 1:
		Values[ 0 ] += 100;
		Values[ Value ] += 1;
		break;

	case 2:
		Values[ 0 ] += 250;
		Values[ Value ] += 1;
		break;

	case 3:
		Values[ 0 ] += 750;
		Values[ Value ] += 1;
		break;

	case 4:
		if( Values[ 0 ] > 16000)
		{
			Values[ 0 ] += int(float(Values[0]) * 1.1f);
		}
		else
		{
			Values[ 0 ] += 1600;
		}
		Values[ Value ] += 1;
		break;
	}
}

int ScoreBoard::GetScore()
{
	return Values[0];
}
