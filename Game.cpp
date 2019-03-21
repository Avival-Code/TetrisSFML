#include "Game.h"

Game::Game(sf::RenderWindow& wnd, TextureCodex& Codex_in, SoundCloud& Cloud_in )
	:
	wnd(&wnd),
	Codex( &Codex_in ),
	Cloud( &Cloud_in ),
	TetrisBackground( Vef2( 0.0f, 0.0f ), *Codex ),
	TetrisBoard( Vef2( 275.0f, 50.0f ), *Codex ),
	ScoreBoards( Vef2( 130.0f, 250.0f ), Vef2( 150.0f, 350.0f ), "AmaticSC-Regular.ttf" )
{
}

void Game::Go()
{
	UpdateLogic();
	ComposeFrame();
}

void Game::UpdateLogic()
{
	if( !GameOver )
	{
		float DeltaTime = Ft.Mark();
		TetrisBoard.Update(DeltaTime, ScoreBoards, *Cloud, GameOver );
		ScoreBoards.Update();
	}
}

void Game::ComposeFrame()
{
	TetrisBackground.Draw( *wnd );
	ScoreBoards.Draw( *wnd );
	TetrisBoard.Draw(*wnd);
}

bool Game::GameOverStatus()
{
	return GameOver;
}
