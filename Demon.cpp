#include "stdafx.h"
#include "Demon.h"


Demon::Demon()
{
	move1 = "Bone Crusher";
	move2 = "Heat Fumation";
	move3 = "Demon fist";
	move4 = "Lava Ball";
	move5 = "Enraged";
	move6 = "Fire Skin";
	move7 = "Mutalation";
	move8 = "Demon Tackle";
	idle = "demonIdle";
	stunned = false;

	moveTime1 = 1.5;
	moveTime2 = 1;
	moveTime3 = 1.4;
	moveTime4 = 1.3;
	moveTime5 = 1.4;
	moveTime6 = 1.2;
	moveTime7 = 1.2;
	moveTime8 = 2.4;

	hp = 300;
	totalHp = 300;


	hurtAnimationName = "demonHurt";
}

double Demon::getHp() const
{
	return hp;
}

double Demon::getTotalHp() const
{
	return totalHp;
}



void Demon::ability1(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{	
	name = "Bone Crusher";
	//also have to account for stances

	damage = 30;
	appliedDebuff = "";
	state = "attack";
	reductionPercent = 0;

	debuffTurns = 1;
	time = 1.5;
	unblockable = false;
	uninterruptable = false;
	

	//makes stunning blow unblockable
	if(isEnhanced)
	{
		uninterruptable = true;
	}


	//puts move on cooldown
	moveNumberUsed = 1;
	moveNumberCD = 4;


	
	currentAnimation = "demonMove1";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;


	keyFrame = 17;
}

void Demon::ability2(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Heat Fumation";
	//also have to account for stances

	damage = 5;
	state = "attack";
	reductionPercent = 0;
	time = 1;
	unblockable = false;
	uninterruptable = false;
	moveNumberCD = 4;
	
	if(isEnhanced)
	{
		appliedDebuff = "Charred";
		debuffTurns = 3;
	}



	//puts move on cooldown
	moveNumberUsed = 2;
	moveNumberCD = 3;
	currentAnimation = "demonMove2";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;


	keyFrame = 15;
}

void Demon::ability3(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Demon fist";
	//also have to account for stances

	damage = 20;
	state = "attack";
	reductionPercent = 0;
	time = 1.4;
	unblockable = false;
	uninterruptable = true;
	buff = "Fury";
	buffTurns = 1;

	if(isEnhanced)
	{
	 time = 1.9;
	 damage = 35;
	}


	//puts move on cooldown
	moveNumberUsed = 3;
	moveNumberCD = 2;
	currentAnimation = "demonMove3";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 23;
}

void Demon::ability4(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Lava Ball";
	damage = 10;
	buff = "";
	appliedDebuff = "Lava";
	state = "attack";
	dodgeChance = 0;
	reductionPercent = 0;
	time = 1.3;
	unblockable = false;
	uninterruptable = false;

	debuffTurns = 2;

	//changes to the skill when enhanced
	if(isEnhanced) debuffTurns = 4;


	//puts move on cooldown
	moveNumberUsed = 4;
	moveNumberCD = 3;
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	currentAnimation = "demonMove4";

	keyFrame = 21;
}

void Demon::ability5(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	
	name = "Enraged";
	
	damage = 0;
	appliedDebuff = "";
	state = "buff";
	buff = "Enraged";
	reductionPercent = 0;
	dodgeChance = 0;
	time = 1.4;
	unblockable = false;
	uninterruptable = false;

	buffTurns = 3;



	if(isEnhanced)
	{
		reductionPercent = .50;
		uninterruptable = true;
	}

	moveNumberUsed = 5;
	moveNumberCD = 5;
	buffTurns = 2;
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	currentAnimation = "demonMove5";
}

void Demon::ability6(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Fire Skin";
	damage = 0;
	state = "buff";
	reductionPercent = 0;
	time = 1.2;
	buff = "Fire Skin";
	unblockable = false;
	uninterruptable = false;

	buffTurns = 2;

	if(isEnhanced)  buff = "Fire Aura";


	//puts move on cooldown
	moveNumberUsed = 6;
	moveNumberCD = 3;

	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	currentAnimation = "demonMove6";
}

void Demon::ability7(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Mutilation";
	damage = 30;
	appliedDebuff = "";
	state = "attack";
	time = 1.2;
	unblockable = true;
	uninterruptable = false;
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	if(isEnhanced) damage = 45;
	currentAnimation = "demonMove7";

	keyFrame = 18;
}

void Demon::ability8(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Demonic Tackle";
	damage = 30;
	appliedDebuff = "";
	state = "attack";
	reductionPercent = 0;
	time = 2.4;
	debuffTurns = 0;
	
	unblockable = false;
	uninterruptable = true;

	if(isEnhanced) appliedDebuff = "Knocked Down";


	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	currentAnimation = "demonMove8";

	keyFrame = 15;
}




string  Demon::getAbility1() const
{
	return move1;
}

string  Demon::getAbility2() const
{
	return move2;
}

string  Demon::getAbility3() const
{
	return move3;
}

string  Demon::getAbility4() const
{
	return move4;
}

string  Demon::getAbility5() const
{
	return move5;
}

string  Demon::getAbility6() const
{
	return move6;
}

string  Demon::getAbility7() const
{
	return move7;
}

string  Demon::getAbility8() const
{
	return move8;
}


double Demon::getAbilityTime1()
{
	return moveTime1;
}

double Demon::getAbilityTime2()
{
	return moveTime2;
}

double Demon::getAbilityTime3()
{
	return moveTime3;
}

double Demon::getAbilityTime4()
{
	return moveTime4;
}

double Demon::getAbilityTime5()
{
	return moveTime5;
}

double Demon::getAbilityTime6()
{
	return moveTime6;
}

double Demon::getAbilityTime7()
{
	return moveTime7;
}

double Demon::getAbilityTime8()
{
	return moveTime8;
}