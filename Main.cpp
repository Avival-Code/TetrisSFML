#include <SFML/Graphics.hpp>
#include "Announcer.h"
#include "TextureCodex.h"
#include "SoundCloud.h"
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Tetris");
	Announcer Announce;
	TextureCodex Codex;
	SoundCloud Cloud;
	Game GameLoop = Game( window, Codex, Cloud );

	Announce.AnnounceGenInfo();
	Cloud.PlayMusic();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		GameLoop.Go();
		if( GameLoop.GameOverStatus() )
		{
			Cloud.StopMusic();
		}

		window.display();
	}

	return 0;
}