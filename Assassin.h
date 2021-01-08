#pragma once
#include "Player.h"
#include "GameObjectManager.h"

class Assassin: public Player
{
public:
	Assassin(void);


	//returns the name of each ability
	string  getAbility1() const;
	string  getAbility2() const;
	string  getAbility3() const;
	string  getAbility4() const;
	string  getAbility5() const;
	string  getAbility6() const;
	string  getAbility7() const;
	string  getAbility8() const;

	//returns the time of each ability
	double getAbilityTime1();
	double getAbilityTime2();
	double getAbilityTime3();
	double getAbilityTime4();
	double getAbilityTime5();
	double getAbilityTime6();
	double getAbilityTime7();
	double getAbilityTime8();



	//hnadles the actual moves themselves
	void ability1(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability2(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability3(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability4(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability5(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability6(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability7(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);
	void ability8(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager);

	//returns current hp
	double getHp() const;

	//returns total hp
	double getTotalHp() const;

};

