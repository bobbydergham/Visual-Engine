#include "stdafx.h"
#include "Warrior.h"





Warrior::Warrior()
{
	move1 = "Stun Strike";
	move2 = "Fast Strike";
	move3 = "Charging Strike";
	move4 = "Thrust Strike";
	move5 = "Power Stance";
	move6 = "Shout";
	move7 = "Block";
	move8 = "Taunt";
	idle = "warriorIdle";
	stunned = false;

	moveTime1 = 1.3;
	moveTime2 = 1.1;
	moveTime3 = 2.2;
	moveTime4 = 1.8;
	moveTime5 = 0.4;
	moveTime6 = 1;
	moveTime7 = 0;
	moveTime8 = 1;

	hp = 300;
	totalHp = 300;


	hurtAnimationName = "warriorHurt";
}

double Warrior::getHp() const
{
	return hp;
}

double Warrior::getTotalHp() const
{
	return totalHp;
}



void Warrior::ability1(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{	
	name = "Stun Strike";
	//also have to account for stances


	
	damage = 10;
	appliedDebuff = "stunned";
	state = "attack";
	reductionPercent = 0;


	time = 1.3;
	unblockable = false;
	uninterruptable = false;
	

	//makes stunning 1.1 second speed if enhanced
	if(isEnhanced)
	{
	   time = 1.1;
	}


	//puts move on cooldown
	moveNumberUsed = 1;
	moveNumberCD = 4;

	//allocates a time to the debuff
	debuffTurns = 1;

	
	currentAnimation = "warriorMove1";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	hurtAnimationName = "warriorHurt";


	//the frame this move strikes the opponent
	keyFrame = 42;
}

void Warrior::ability2(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Fast Strike";
	//also have to account for stances


	//the frame this move strikes the opponent
	keyFrame = 21;

	damage = 15;
	state = "attack";
	reductionPercent = 0;
	time = 1.1;
	unblockable = false;
	uninterruptable = false;
	
	//makes damage formidable, maybe charging/thrust strike are on cooldown
	if(isEnhanced)
	{
	damage = 30;
	}



	//puts move on cooldown
	moveNumberUsed = 2;
	moveNumberCD = 2;
	currentAnimation = "warriorMove2";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
}

void Warrior::ability3(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Charging Strike";
	//also have to account for stances


	//the frame this move strikes the opponent
	keyFrame = 60;

	damage = 40;
	state = "attack";
	reductionPercent = 0;
	time = 2.2;
	unblockable = false;
	uninterruptable = true;
	

	//makes it unblockable, so now its unstoppable and unblockable
	if(isEnhanced)
	{
		unblockable = true;
	}


	//puts move on cooldown
	moveNumberUsed = 3;
	moveNumberCD = 3;
	currentAnimation = "warriorMove3";
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
}

void Warrior::ability4(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Thrust Strike";
	damage = 28;
	buff = "";
	state = "attack";
	dodgeChance = 0;
	reductionPercent = 0;
	time = 1.8;


	//the frame this move strikes the opponent
	keyFrame = 27;


	unblockable = true;
	uninterruptable = false;


	//effectively a weaker enhanced charging strike when enhanced, but faster(maybe needs a tweak)
	//maybe program it so that it removes stun strikes cd or something
	if(isEnhanced) uninterruptable = true;


	//puts move on cooldown
	moveNumberUsed = 4;
	moveNumberCD = 1;
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	currentAnimation = "warriorMove4";
}

void Warrior::ability5(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	
		//power stance gives the warrior 1.5x damage and uninterruptable properties for 2 turns
	
	name = "Power Stance";
	
	damage = 0;
	appliedDebuff = "";
	state = "buff";
	buff = "Power Stance";
	dodgeChance = 0;
	reductionPercent = .3;
	time = 0.4;
	unblockable = false;
	uninterruptable = false;

	//the frame this move strikes the opponent
	keyFrame = 0;

	//blocks 80% if damage the turn you do it if you enhance
	if(isEnhanced)
	{
		reductionPercent = .8;
	}

	moveNumberUsed = 5;
	moveNumberCD = 1;
	buffTurns = 2;
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	currentAnimation = "warriorMove5";
}

void Warrior::ability6(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Shout";
	damage = 0;
	appliedDebuff = "Shout";
	state = "debuff";
	reductionPercent = 0;
	time = 1;
	unblockable = false;
	uninterruptable = false;

	debuffTurns = 4;

	//the frame this move strikes the opponent
	keyFrame = 0;


	//adds two more turns to shouts debuff
	if(isEnhanced) debuffTurns = 6;


	//puts move on cooldown
	moveNumberUsed = 6;
	moveNumberCD = 7;

	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	currentAnimation = "warriorMove6";
}

void Warrior::ability7(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Block";
	damage = 0;
	appliedDebuff = "";
	state = "block";
	reductionPercent = .80;
	time = 0;

	moveNumberUsed = 7;
	moveNumberCD = 1;
	
	//the frame this move strikes the opponent
	keyFrame = 0;


	unblockable = false;
	uninterruptable = false;
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;

	//make a debuff that staggers opponent because of perfect guarding?
	if(isEnhanced) reductionPercent = 1;

	currentAnimation = "warriorMove7";
}

void Warrior::ability8(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager)
{
	name = "Taunt";
	damage = 0;
	appliedDebuff = "Taunted";
	state = "debuff";
	reductionPercent = 0;
	time = 1;
	debuffTurns = 2;
	unblockable = true;
	uninterruptable = false;

	//the frame this move strikes the opponent
	keyFrame = 0;

	//taunt lasts 1 more turn
	if(isEnhanced) debuffTurns = 3;


	//also consider that taunt has too short a CD
	_visibleObjectManager.player1MoveFinished = false;
	_visibleObjectManager.player2MoveFinished = false;
	currentAnimation = "warriorMove8";
}




string  Warrior::getAbility1() const
{
	return move1;
}

string  Warrior::getAbility2() const
{
	return move2;
}

string  Warrior::getAbility3() const
{
	return move3;
}

string  Warrior::getAbility4() const
{
	return move4;
}

string  Warrior::getAbility5() const
{
	return move5;
}

string  Warrior::getAbility6() const
{
	return move6;
}

string  Warrior::getAbility7() const
{
	return move7;
}

string  Warrior::getAbility8() const
{
	return move8;
}


double Warrior::getAbilityTime1()
{
	return moveTime1;
}

double Warrior::getAbilityTime2()
{
	return moveTime2;
}

double Warrior::getAbilityTime3()
{
	return moveTime3;
}

double Warrior::getAbilityTime4()
{
	return moveTime4;
}

double Warrior::getAbilityTime5()
{
	return moveTime5;
}

double Warrior::getAbilityTime6()
{
	return moveTime6;
}

double Warrior::getAbilityTime7()
{
	return moveTime7;
}

double Warrior::getAbilityTime8()
{
	return moveTime8;
}
