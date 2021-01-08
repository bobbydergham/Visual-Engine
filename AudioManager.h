#pragma once

#include "VisibleObjectManager.h"

class AudioManager
{
public:
	AudioManager(void);
	~AudioManager(void);

	void playArenaMusic(int go);
	void playIntro(int go);
	void playCharacterSelect(int go);
	void playButtonClick(int go);
	void playSlash();
	void playWarrior1(int go);

	//handles all the warriors taunts
	void AudioManager::taunt(int go);
private:
	sf::Music arenaMusic;
	sf::Music introMusic;
	sf::Music slash;
	sf::Music characterSelectMusic;
	sf::Music buttonClick;
	sf::Music warriorHit1;

	sf::Music tauntWarrior;
	sf::Music tauntAssassin;
	sf::Music tauntMonk;
	sf::Music tauntNecromancer;
	sf::Music tauntDemon;

};

