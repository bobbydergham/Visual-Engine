#include "stdafx.h"
#include "Assassin.h"


Assassin::Assassin()
{
	move1 = "Smoke Bomb";
	move2 = "Apply Poison";
	move3 = "kunais";
	move4 = "Vital Strike";
	move5 = "Back Blow";
	move6 = "Dodge";
	move7 = "Leg Slice";
	move8 = "Disarm";

	idle = "assassinIdle";

	moveTime1 = 1;
	moveTime2 = 1.2;
	moveTime3 = 1.3;
	moveTime4 = 1.2;
	moveTime5 = 2;
	moveTime6 = 0;
	moveTime7 = 1.5;
	moveTime8 = 0.9;

	hp = 270;
	totalHp = 270;
	bool stunned = false;

	hurtAnimationName = "assassinHurt";
}

double Assassin::getHp() const
{
	return hp;
}

double Assassin::getTotalHp() const
{
	return totalHp;
}




void Assassin::ability1(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Smoke Bomb";
	buff = "smoke";
	dodgeChance = dodgeChance + 50;
	state = "dodge";
	time = 1;
	

	buffTurns = 3;
	moveNumberUsed = 1;
	moveNumberCD = 6;
	currentAnimation = "assassinMove1";

	//makes dodge chance the turn you do it 100%
	if(isEnhanced)
	{
		dodgeChance = 100;
		moveNumberCD = 4;
	}
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
}

void Assassin::ability2(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Apply poison";
	buff = "poison";
	state = "buff";
	time = 1.2;

	buffTurns = 10;
	moveNumberUsed = 2;
	moveNumberCD = 2;
	currentAnimation = "assassinMove2";

	//gives you deadly poison
	if(isEnhanced)
	{
		buff = "deadly poison";
	}


	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
}

void Assassin::ability3(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "kunais";
	appliedDebuff = "Stagger";
	state = "attack";
	damage = 15;
	time = 1.3;

	moveNumberUsed = 3;
	moveNumberCD = 2;

	debuffTurns = 3;
	currentAnimation = "assassinMove3";

	//stronger stagger
	if(isEnhanced)
	{
		appliedDebuff = "Magic Stagger";
		damage = 30;
	}
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 14;
}

void Assassin::ability4(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Vital Strike";
	appliedDebuff = "";
	state = "attack";
	damage = 10;
	time = 1.2;

	moveNumberUsed = 4;
	moveNumberCD = 2;
	currentAnimation = "assassinMove4";
	
	//causes bleeding
	if(isEnhanced)
	{
		appliedDebuff = "Bleeding";
	}
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 10;
}

void Assassin::ability5(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Back Blow";
	appliedDebuff = "";
	state = "attack";
	damage = 30;
	time = 2.0;

	moveNumberUsed = 5;
	moveNumberCD = 3;

	//makes cooldown reset
	if(isEnhanced)
	{
		moveNumberCD = 1;
	}
	currentAnimation = "assassinMove5";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 16;
}

void Assassin::ability6(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Dodge";
	appliedDebuff = "";
	state = "dodge";
	dodgeChance = dodgeChance + 50;
	damage = 0;
	time = 0;

	moveNumberUsed = 6;
	moveNumberCD = 1;
	currentAnimation = "assassinMove6";

	//dodge chance of 100%
	if(isEnhanced)
	{
		dodgeChance = 100;
	}
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
}

void Assassin::ability7(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Leg Slice";
	appliedDebuff = "";
	state = "attack";
	damage = 15;
	time = 1.5;

	moveNumberUsed = 7;
	moveNumberCD = 2;
	currentAnimation = "assassinMove7";

	//does more damage
	if(isEnhanced)
	{
		damage = 25;
	}
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 21;
}

void Assassin::ability8(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Disarm";
	appliedDebuff = "Disarmed";
	state = "attack";
	damage = 10;
	time = .9;

	moveNumberUsed = 8;
	moveNumberCD = 6;
	debuffTurns = 1;
	currentAnimation = "assassinMove8";

	
	//greatly lowers CD
	if(isEnhanced)
	{
		moveNumberCD = 2;
	}
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;


	keyFrame = 18;
}


string  Assassin::getAbility1() const
{
	return move1;
}

string  Assassin::getAbility2() const
{
	return move2;
}

string  Assassin::getAbility3() const
{
	return move3;
}

string  Assassin::getAbility4() const
{
	return move4;
}

string  Assassin::getAbility5() const
{
	return move5;
}

string  Assassin::getAbility6() const
{
	return move6;
}

string  Assassin::getAbility7() const
{
	return move7;
}

string  Assassin::getAbility8() const
{
	return move8;
}

double Assassin::getAbilityTime1()
{
	return moveTime1;
}

double Assassin::getAbilityTime2()
{
	return moveTime2;
}

double Assassin::getAbilityTime3()
{
	return moveTime3;
}

double Assassin::getAbilityTime4()
{
	return moveTime4;
}

double Assassin::getAbilityTime5()
{
	return moveTime5;
}

double Assassin::getAbilityTime6()
{
	return moveTime6;
}

double Assassin::getAbilityTime7()
{
	return moveTime7;
}

double Assassin::getAbilityTime8()
{
	return moveTime8;
}