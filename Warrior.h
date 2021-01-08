#ifndef WARRIOR
#define WARRIOR
#include "player.h"
#include "GameObjectManager.h"
#include <SFML/Graphics.hpp>


class Warrior: public Player
{
public:
	Warrior();
	
	string  getAbility1() const;
	string  getAbility2() const;
	string  getAbility3() const;
	string  getAbility4() const;
	string  getAbility5() const;
	string  getAbility6() const;
	string  getAbility7() const;
	string  getAbility8() const;

	double getAbilityTime1();
	double getAbilityTime2();
	double getAbilityTime3();
	double getAbilityTime4();
	double getAbilityTime5();
	double getAbilityTime6();
	double getAbilityTime7();
	double getAbilityTime8();


	void ability1(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability2(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability3(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability4(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability5(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability6(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability7(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability8(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	double getHp() const;
	double getTotalHp() const;




	//variables

	sf::Texture idleSheet;

	sf::Sprite sprite;
	

};

#endif