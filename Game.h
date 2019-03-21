#pragma once
#include <SFML/Graphics.hpp>
#include "TextureCodex.h"
#include "FrameTimer.h"
#include "Background.h"
#include "Board.h"
#include "SoundCloud.h"
#include "ScoreBoard.h"
#include "Vec2.h"

class Game
{
public:
	Game(sf::RenderWindow& wnd, TextureCodex& Codex_in, SoundCloud& Cloud_in );
	void Go();
	void UpdateLogic();
	void ComposeFrame();
	bool GameOverStatus();

private:
	sf::RenderWindow* wnd;
	TextureCodex* Codex;
	SoundCloud* Cloud;
	bool GameOver = false;

private:
	/********************************
	***Include user variables here***
	*********************************/
	FrameTimer Ft;
	Background TetrisBackground;
	Board TetrisBoard;
	ScoreBoard ScoreBoards;
};