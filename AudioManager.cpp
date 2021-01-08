#include "stdafx.h"
#include "AudioManager.h"


AudioManager::AudioManager(void)
{

	if (!arenaMusic.openFromFile("Audio/indRev.ogg")) return; // error
	if (!warriorHit1.openFromFile("Audio/hit1.ogg")) return; // error


	//loads the warriors taunts
	if (!tauntWarrior.openFromFile("Audio/warriorTaunt.ogg")) return; // error
	if (!tauntAssassin.openFromFile("Audio/assassinTaunt.ogg")) return; // error
	if (!tauntMonk.openFromFile("Audio/monkTaunt.ogg")) return; // error
	if (!tauntNecromancer.openFromFile("Audio/demonTaunt.ogg")) return; // error
	if (!tauntDemon.openFromFile("Audio/necroTaunt.ogg")) return; // error

}


AudioManager::~AudioManager(void)
{
}


void AudioManager::playArenaMusic(int go)
{
	arenaMusic.setVolume(30);
if(go == 1) arenaMusic.play();
else arenaMusic.stop();
}



void AudioManager::playIntro(int go)
{

if(!introMusic.openFromFile("Audio/Tempting_Secrets.ogg")) return; // error

	if(go == 1) introMusic.play();
	else introMusic.stop();
}

void AudioManager::playCharacterSelect(int go)
{

if(!characterSelectMusic.openFromFile("Audio/The_Descent.ogg")) return; // error
	if(go == 1) characterSelectMusic.play();
	else characterSelectMusic.stop();
}


void AudioManager::playButtonClick(int go)
{
	if(!buttonClick.openFromFile("Audio/buttonClick.ogg")) return; // error
	if(go == 1) buttonClick.play();
	else buttonClick.stop();

}


void AudioManager::playSlash()
{
	if(!slash.openFromFile("Audio/slash.ogg")) return; // error
	slash.play();
}

void AudioManager::playWarrior1(int go)
{
	if (go == 1) warriorHit1.play();

}

void AudioManager::taunt(int go)
{
	if(go == 1 && tauntWarrior.getStatus() == sf::Sound::Stopped)tauntWarrior.play();
	else if (go == 2 && tauntAssassin.getStatus() == sf::Sound::Stopped) tauntAssassin.play();
	else if (go == 3 && tauntWarrior.getStatus() == sf::Sound::Stopped) tauntMonk.play();
	else if (go == 4 && tauntWarrior.getStatus() == sf::Sound::Stopped) tauntNecromancer.play();
	else if (go == 5 && tauntWarrior.getStatus() == sf::Sound::Stopped) tauntDemon.play();

}
