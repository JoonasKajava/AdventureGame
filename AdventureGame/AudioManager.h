#pragma once

#include <SFML\Audio.hpp>
#include <map>

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	sf::Music* CurrentMusic;
	sf::Sound CurrentSoundEffect;

	enum Musics {
		Adventure,
		Battle,
		Death,
		Win
	};
	std::map<Musics, sf::Music*> Music;

	enum SoundEffects {
		Swing,
		Miss,
		ItemPickup
	};
	std::map<SoundEffects, sf::SoundBuffer*> SoundEffect;


	void SetMusic(Musics m);

	void PlayEffect(SoundEffects s);

};

