#include "stdafx.h"
#include "Monk.h"


Monk::Monk()
{
	move1 = "Push Strike";
	move2 = "Step in";
	move3 = "Piercing Kick";
	move4 = "Right elbow";
	move5 = "Elbow parry";
	move6 = "Heavenly Tackle";
	move7 = "Inhuman Speed";
	move8 = "Meditate";
	idle = "monkIdle";
	stunned = false;

	moveTime1 = 1;
	moveTime2 = 1.3;
	moveTime3 = 1.6;
	moveTime4 = 1.7;
	moveTime5 = 1.8;
	moveTime6 = 2;
	moveTime7 = 0.7;
	moveTime8 = 0.5;

	hp = 280;
	totalHp = 280;

	hurtAnimationName = "monkHurt";
}



double Monk::getHp() const
{
	return hp;
}

double Monk::getTotalHp() const
{
	return totalHp;
}

void Monk::ability1(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Push Strike";
	appliedDebuff = "Pushed";
	state = "attack";
	time = 1;
	damage = 10;
	debuffTurns = 1;


	moveNumberUsed = 1;
	moveNumberCD = 3;

	//make it interrupt anything
	if (isEnhanced)
	{

	}
	currentAnimation = "monkMove1";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;


	keyFrame = 10;
}
void Monk::ability2(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Step in";
	buff = "Step in";
	state = "buff";



	damage = 0;

	time = 1.30;
	buffTurns = 30;


	moveNumberUsed = 2;
	moveNumberCD = 1;

	//makes it so it cant be stopped
	if (isEnhanced)
	{
		uninterruptable = true;
	}
	currentAnimation = "monkMove2";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 0;
}

void Monk::ability3(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Piercing Kick";
	buff = "";
	state = "attack";
	time = 1.6;
	damage = 25;
	unblockable = true;


	moveNumberUsed = 3;
	moveNumberCD = 2;


	//makes damage increase
	if (isEnhanced)
	{
		damage = 40;
	}
	currentAnimation = "monkMove3";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 7;
}
void Monk::ability4(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Right Elbow";
	buff = "Step in";
	state = "attack";
	time = 1.7;
	damage = 25;

	buffTurns = 30;

	moveNumberUsed = 4;
	moveNumberCD = 1;


	//makes it as quick as if you were already in stance
	if (isEnhanced)
	{
		time = 1.2;
	}
	currentAnimation = "monkMove4";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;


	keyFrame = 12;
}
void Monk::ability5(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Elbow Parry";
	buff = "";
	state = "attack";
	time = 1.8;
	damage = 20;



	moveNumberUsed = 5;
	moveNumberCD = 3;


	//make them pushed
	if (isEnhanced)
	{

	}
	currentAnimation = "monkMove5";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 23;
}
void Monk::ability6(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Heavenly Tackle";
	appliedDebuff = "Knocked Down";
	state = "attack";
	time = 2;
	damage = 40;
	unblockable = true;

	debuffTurns = 1;


	moveNumberUsed = 6;
	moveNumberCD = 4;


	if (isEnhanced)
	{
		buff = "Step in";
	}
	currentAnimation = "monkMove6";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 12;
}
void Monk::ability7(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Inhuman Speed";
	appliedDebuff = "";
	state = "buff";
	time = 0.7;
	damage = 0;





	moveNumberUsed = 7;
	moveNumberCD = 3;

	//make it so you get a buff that makes it so the next move you use has no CD
	if (isEnhanced)
	{

	}
	currentAnimation = "monkMove7";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 0;
}
void Monk::ability8(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Meditate";
	appliedDebuff = "";
	state = "dodge";
	time = 0.5;
	damage = 0;




	moveNumberUsed = 8;
	moveNumberCD = 2;

	//make it heal you
	if (isEnhanced)
	{

	}
	currentAnimation = "monkMove8";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 0;
}


string  Monk::getAbility1() const
{
	return move1;
}

string  Monk::getAbility2() const
{
	return move2;
}

string  Monk::getAbility3() const
{
	return move3;
}

string  Monk::getAbility4() const
{
	return move4;
}

string  Monk::getAbility5() const
{
	return move5;
}

string  Monk::getAbility6() const
{
	return move6;
}

string  Monk::getAbility7() const
{
	return move7;
}

string  Monk::getAbility8() const
{
	return move8;
}

double Monk::getAbilityTime1()
{
	return moveTime1;
}

double Monk::getAbilityTime2()
{
	return moveTime2;
}

double Monk::getAbilityTime3()
{
	return moveTime3;
}

double Monk::getAbilityTime4()
{
	return moveTime4;
}

double Monk::getAbilityTime5()
{
	return moveTime5;
}

double Monk::getAbilityTime6()
{
	return moveTime6;
}

double Monk::getAbilityTime7()
{
	return moveTime7;
}

double Monk::getAbilityTime8()
{
	return moveTime8;
}