#include "stdafx.h"
#include "Necromancer.h"



Necromancer::Necromancer()
{
	move1 = "Soul Swipe";
	move2 = "Corpse Pile";
	move3 = "Soul Harvest";
	move4 = "Bone wall";
	move5 = "Soul Blast";
	move6 = "Deadmans Heal";
	move7 = "Decay Aura";
	move8 = "Scythe Surge";

	idle = "necromancerIdle";
	stunned = false;

	moveTime1 = 1.2;
	moveTime2 = 1.5;
	moveTime3 = 1;
	moveTime4 = 1.3;
	moveTime5 = 1.3;
	moveTime6 = 1;
	moveTime7 = 1;
	moveTime8 = 1.8;

	hp = 300;
	totalHp = 300;


	hurtAnimationName = "necromancerHurt";
}

double Necromancer::getHp() const
{
	return hp;
}

double Necromancer::getTotalHp() const
{
	return totalHp;
}



void Necromancer::ability1(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Soul Swipe";
	//also have to account for stances

	damage = 10;
	buff = "soulMeter20";
	state = "attack";
	reductionPercent = 0;


	time = 1.2;

	unblockable = false;
	uninterruptable = false;


	//makes stunning blow unblockable
	if (isEnhanced)
	{
		buff = "soulMeter40";
	}


	//puts move on cooldown
	moveNumberUsed = 1;
	moveNumberCD = 2;

	//allocates a time to the debuff
	buffTurns = 0;


	currentAnimation = "necromancerMove1";

	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 28;
}

void Necromancer::ability2(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Corpse Pile";
	//also have to account for stances

	damage = 10;
	state = "attack";
	appliedDebuff = "Rooted";
	debuffTurns = 1;
	reductionPercent = 0;
	time = 1.5;
	unblockable = false;
	uninterruptable = false;

	if (isEnhanced)
	{
		time = 1.2;
	}



	//puts move on cooldown
	moveNumberUsed = 2;
	moveNumberCD = 3;
	currentAnimation = "necromancerMove2";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	keyFrame = 19;
}

void Necromancer::ability3(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Soul Harvest";
	//also have to account for stances

	damage = 0;
	state = "buff";
	buffTurns = 0;
	buff = "soulMeter40";
	reductionPercent = 0;
	time = 1;
	unblockable = false;
	uninterruptable = true;


	if (isEnhanced)
	{
		reductionPercent = 1;
	}


	//puts move on cooldown
	moveNumberUsed = 3;
	moveNumberCD = 1;
	currentAnimation = "necromancerMove3";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
}

void Necromancer::ability4(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Bone wall";
	damage = 0;
	buff = "Bone wall";
	buffTurns = 3;
	state = "buff";
	dodgeChance = 0;
	reductionPercent = 0;
	time = 1.3;
	unblockable = false;
	uninterruptable = false;


	//changes to the skill when enhanced
	if (isEnhanced) uninterruptable = true;


	//puts move on cooldown
	moveNumberUsed = 4;
	moveNumberCD = 6;
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	currentAnimation = "necromancerMove4";
}

void Necromancer::ability5(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{

	name = "Soul Blast";


	damage = 10 + necroMeter;
	buff = "emptySoulMeter";
	unblockable = false;

	if (isEnhanced) unblockable = true;



	state = "attack";
	reductionPercent = 0;
	dodgeChance = 0;
	time = 1.3;
	uninterruptable = false;


	moveNumberUsed = 5;
	moveNumberCD = 2;

	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	currentAnimation = "necromancerMove5";

	keyFrame = 19;
}

void Necromancer::ability6(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Deadmans Heal";
	damage = 0;

	state = "buff";

	buff = "gainHp";
	if (isEnhanced)
	{
		buff = "gainHpEnhanced";
	}

	reductionPercent = 0;
	time = 1;
	unblockable = false;
	uninterruptable = false;



	//puts move on cooldown
	moveNumberUsed = 6;
	moveNumberCD = 2;

	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	currentAnimation = "necromancerMove6";
}

void Necromancer::ability7(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Decay Aura";
	damage = 0;
	buff = "Decay Aura";
	state = "buff";
	reductionPercent = 0;
	time = 1;

	unblockable = false;
	uninterruptable = false;


	buffTurns = 4;
	moveNumberCD = 3;
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	if (isEnhanced) buffTurns = 8;
	currentAnimation = "necromancerMove7";
}

void Necromancer::ability8(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Scythe Surge";
	damage = 40;
	appliedDebuff = "";
	state = "attack";
	buff = "emptySoulMeter";


	uninterruptable = true;
	reductionPercent = 0;
	if (necroMeter == 20) reductionPercent = .25;
	if (necroMeter == 40) reductionPercent = .50;


	time = 1.9;
	buffTurns = 0;
	debuffTurns = 0;
	moveNumberCD = 2;

	//handles enhanced
	if (isEnhanced)
	{
		appliedDebuff = "Death Mark";
		debuffTurns = 2;
	}

	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	currentAnimation = "necromancerMove8";

	keyFrame = 9;
}




string  Necromancer::getAbility1() const
{
	return move1;
}

string  Necromancer::getAbility2() const
{
	return move2;
}

string  Necromancer::getAbility3() const
{
	return move3;
}

string  Necromancer::getAbility4() const
{
	return move4;
}

string  Necromancer::getAbility5() const
{
	return move5;
}

string  Necromancer::getAbility6() const
{
	return move6;
}

string  Necromancer::getAbility7() const
{
	return move7;
}

string  Necromancer::getAbility8() const
{
	return move8;
}


double Necromancer::getAbilityTime1()
{
	return moveTime1;
}

double Necromancer::getAbilityTime2()
{
	return moveTime2;
}

double Necromancer::getAbilityTime3()
{
	return moveTime3;
}

double Necromancer::getAbilityTime4()
{
	return moveTime4;
}

double Necromancer::getAbilityTime5()
{
	return moveTime5;
}

double Necromancer::getAbilityTime6()
{
	return moveTime6;
}

double Necromancer::getAbilityTime7()
{
	return moveTime7;
}

double Necromancer::getAbilityTime8()
{
	return moveTime8;
}