#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

class SoundCloud
{
public:
	SoundCloud();
	void LoadAudioNames();
	void LoadAudioFiles();
	sf::Sound& GetSound( int Position );
	void PlayMusic();
	void StopMusic();

private:
	const int TotalSounds = 3;
	std::string AudioFileNames[ 4 ];
	sf::Music Music;
	sf::SoundBuffer Buffers[ 3 ];
	sf::Sound Sounds[ 3 ];
};