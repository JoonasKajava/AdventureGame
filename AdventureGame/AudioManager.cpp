#include "stdafx.h"
#include "AudioManager.h"


AudioManager::AudioManager()
{
	sf::Music* AdventureMusic = new sf::Music();
	AdventureMusic->openFromFile("Sounds/main.ogg");
	AdventureMusic->setLoop(true);
	Music[Adventure] = AdventureMusic;


	sf::Music* BattleMusic = new sf::Music();
	BattleMusic->openFromFile("Sounds/Blackmoor_Tides_Loop.wav");
	BattleMusic->setLoop(true);
	Music[Battle] = BattleMusic;

	sf::Music* DeathMusic = new sf::Music();
	DeathMusic->openFromFile("Sounds/died.ogg");
	DeathMusic->setLoop(true);
	Music[Death] = DeathMusic;

	sf::Music* WinMusic = new sf::Music();
	WinMusic->openFromFile("Sounds/Victory.ogg");
	WinMusic->setLoop(true);
	Music[Win] = WinMusic;

	sf::SoundBuffer* SwingSound = new sf::SoundBuffer();
	SwingSound->loadFromFile("Sounds/swing.wav");
	SoundEffect[Swing] = SwingSound;


	sf::SoundBuffer* MissSound = new sf::SoundBuffer();
	MissSound->loadFromFile("Sounds/miss.wav");
	SoundEffect[Miss] = MissSound;

	CurrentMusic = AdventureMusic;
	CurrentMusic->play();
}


AudioManager::~AudioManager()
{
}

void AudioManager::SetMusic(Musics m)
{
	CurrentMusic->pause();
	CurrentMusic = Music[m];
	if (m == Battle) CurrentMusic->stop();
	CurrentMusic->play();
}

void AudioManager::PlayEffect(SoundEffects s)
{
	CurrentSoundEffect.setBuffer(*SoundEffect[s]);

	CurrentSoundEffect.play();
}
