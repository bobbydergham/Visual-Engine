#include "stdafx.h"
#include "PlayerSkillChoice.h"


PlayerSkillChoice::PlayerSkillChoice(void)
{
	damage = 0.0;
	time = 0.0;
	reductionPercent = 0;
	uninterruptable = false;
	unblockable = false;
	dodgeChance = 0;
	moveNumberUsed = 0;
	moveNumberCD = 0;

}


PlayerSkillChoice::~PlayerSkillChoice(void)
{
}



void PlayerSkillChoice::reset()
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


	int debuffTurns;
	name = "";
	buff = "";
	appliedDebuff = "";
	moveNumberCD = 0;
	moveNumberUsed = 0;
}