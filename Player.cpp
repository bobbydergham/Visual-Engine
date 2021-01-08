#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	hp = 100;
	totalHp = 100;
	mp = 100;
	keyFrame = 0;

	//tells the game to switch to hurtAnimation or not
	switchToHurt = false;

	////////////
	damage = 0.0;
	time = 0.0;
	reductionPercent = 0;
	uninterruptable = false;
	unblockable = false;
	dodgeChance = 0;
	moveNumberUsed = 0;
	moveNumberCD = 0;

	 

	playerBuff = "";
	playerSecondBuff = "";
	playerThirdBuff = "";
	
	playerDebuff = "";
	playerSecondDebuff = "";
	playerThirdDebuff = "";

	playerMeditateChoice = "empty";
	playerBoneCrusherChoice = "empty";

	playerEnhancedMove = false;

	playerDodged = false;

	playerMove1Used = false;
	playerMove2Used = false;
	playerMove3Used = false;
	playerMove4Used = false;
	playerMove5Used = false;
	playerMove6Used = false;
	playerMove7Used = false;
	playerMove8Used = false;

	playerMove1CD = 0;
	playerMove2CD = 0;
	playerMove3CD = 0;
	playerMove4CD = 0;
	playerMove5CD = 0;
	playerMove6CD = 0;
	playerMove7CD = 0;
	playerMove8CD = 0;


	playerDebuff1Duration = 0;
	playerDebuff2Duration = 0;
	playerDebuff3Duration = 0;



	playerBuff1Duration = 0;
	playerBuff2Duration = 0;
	playerBuff3Duration = 0;

	playerPicked = false;

	necroMeter = 0;
	necroMeterMax = 40;

	furyDamage = 0;


	playerMoveWasSuccessful = false;

}

Player::Player(double setHp, double setMp)
{
	hp = setHp;
	mp = setMp;

}


bool Player::isStunned()
{
	return stunned;
}

void Player::setHp(double newHp)
{
	hp = newHp;
}


double Player::getHp() const
{
	return hp;
}

void Player::setMp(double newMp)
{
	mp = newMp;
}

double Player::getMp() const
{
	return mp;
}


void Player::setStun(bool check)
{
	stunned = check;
}


double Player::getTotalHp() const
{
	return totalHp;
}

void Player::resetSkillChoice()
{
	damage = 0;
	time = 0;
	reductionPercent = 0;
	uninterruptable = false;
	unblockable = false;
	state = "";
	dodgeChance = 0;

	moveNumberUsed = 0;
	moveNumberCD = 0;


	debuffTurns;
	name = "";
	buff = "";
	appliedDebuff = "";
	moveNumberCD = 0;
	moveNumberUsed = 0;
}