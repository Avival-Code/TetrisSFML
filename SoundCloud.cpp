#include "SoundCloud.h"

SoundCloud::SoundCloud()
{
	LoadAudioNames();
	LoadAudioFiles();
	Music.setVolume( 50 );
	Music.setLoop( true );
}

void SoundCloud::LoadAudioNames()
{
	AudioFileNames[0] = "Amo Pickup.ogg";
	AudioFileNames[1] = "Coin Pickup.wav";
	AudioFileNames[2] = "Slide Electronic.wav";
	AudioFileNames[3] = "Hack.ogg";
}

void SoundCloud::LoadAudioFiles()
{
	for( int Buff = 0; Buff < TotalSounds; Buff++ )
	{
		Buffers[ Buff ].loadFromFile( AudioFileNames[ Buff ] );
	}
	for( int Sound = 0; Sound < TotalSounds; Sound++ )
	{
		Sounds[ Sound ].setBuffer( Buffers[ Sound ] );
	}
	Music.openFromFile( AudioFileNames[ 3 ] );
}

sf::Sound& SoundCloud::GetSound(int Position)
{
	return Sounds[ Position ];
}

void SoundCloud::PlayMusic()
{
	Music.play();
}

void SoundCloud::StopMusic()
{
	Music.stop();
}
