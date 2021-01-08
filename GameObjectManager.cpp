#include "stdafx.h"
#include "GameObjectManager.h"
#include "Warrior.h"
#include "Assassin.h"
#include "Monk.h"


GameObjectManager::GameObjectManager(void)
{
	player1 = NULL;
	player2 = NULL;
	battleClock = sf::seconds(90); //sets the clock timer during the turn
	animationClock = sf::seconds(5);

	bool player1Picked = false;
	bool player2Picked = false;

	sf::Time player1SkillTime = sf::seconds(0);
	sf::Time player2SkillTime = sf::seconds(0);

	int player1Enhance = 2;
	int player2Enhance = 2;

	player1Debuff1Duration = 0;
	player1Debuff2Duration = 0;
	player1Debuff3Duration = 0;

	player2Debuff1Duration = 0;
	player2Debuff2Duration = 0;
	player2Debuff3Duration = 0;

	
	player1Buff1Duration = 0;
	player1Buff2Duration = 0;
	player1Buff3Duration = 0;


	player2Buff1Duration = 0;
	player2Buff2Duration = 0;
	player2Buff3Duration = 0;

	player1Mana1 = true;
	player1Mana2 = true;
	player2Mana1 = true;
	player2Mana2 = true;

	player1Dead = false;
	player2Dead = false;


	bool turnOperationFulfilled = false;

	int playerAttackSuccessful = 0;

}

void GameObjectManager::setTurnOperation(bool temp)
{
	turnOperationFulfilled = temp;
}

bool GameObjectManager::getTurnOperation()
{
	return turnOperationFulfilled;
}

GameObjectManager::~GameObjectManager(void)
{
}


void GameObjectManager::reset()
{
	player1 = NULL;
	player2 = NULL;

	char1 = "";
	char2 = "";

	battleClock = sf::seconds(10);
	animationClock = sf::seconds(5);

	bool player1Picked = false;
	bool player2Picked = false;

	sf::Time player1SkillTime = sf::seconds(0);
	sf::Time player2SkillTime = sf::seconds(0);

	int player1Enhance = 2;
	int player2Enhance = 2;

	player1Buff = " ";
	player1SecondBuff = " ";
	player1ThirdBuff = " ";
	
	player2Buff = " ";
	player2SecondBuff = " ";
	player2ThirdBuff = " ";

	player1Debuff = " ";
	player1SecondDebuff = " ";
	player1ThirdDebuff = " ";
	
	player2Debuff = " ";
	player2SecondDebuff = " ";
	player2ThirdDebuff = " ";

	player1MeditateChoice = "";
	player2MeditateChoice = "";

	player1EnhancedMove = false;
	player2EnhancedMove = false;

	player1Dodged = false;
	player2Dodged = false;

	player1Move1Used = false;
	player1Move2Used = false;
	player1Move3Used = false;
	player1Move4Used = false;
	player1Move5Used = false;
	player1Move6Used = false;
	player1Move7Used = false;
	player1Move8Used = false;

	player2Move1Used = false;
	player2Move2Used = false;
	player2Move3Used = false;
	player2Move4Used = false;
	player2Move5Used = false;
	player2Move6Used = false;
	player2Move7Used = false;
	player2Move8Used = false;

	player1Move1CD = 0;
	player1Move2CD = 0;
	player1Move3CD = 0;
	player1Move4CD = 0;
	player1Move5CD = 0;
	player1Move6CD = 0;
	player1Move7CD = 0;
	player1Move8CD = 0;

	player2Move1CD = 0;
	player2Move2CD = 0;
	player2Move3CD = 0;
	player2Move4CD = 0;
	player2Move5CD = 0;
	player2Move6CD = 0;
	player2Move7CD = 0;
	player2Move8CD = 0;

	player1Debuff1Duration = 0;
	player1Debuff2Duration = 0;
	player1Debuff3Duration = 0;

	player2Debuff1Duration = 0;
	player2Debuff2Duration = 0;
	player2Debuff3Duration = 0;

	player1Buff1Duration = 0;
	player1Buff2Duration = 0;
	player1Buff3Duration = 0;


	player2Buff1Duration = 0;
	player2Buff2Duration = 0;
	player2Buff3Duration = 0;
}


void GameObjectManager::rematchReset()
{
	battleClock = sf::seconds(99);
	animationClock = sf::seconds(3);

	sf::Time player1SkillTime = sf::seconds(0);
	sf::Time player2SkillTime = sf::seconds(0);

	int player1Enhance = 2;
	int player2Enhance = 2;

	player1Buff = " ";
	player1SecondBuff = " ";
	player1ThirdBuff = " ";
	
	player2Buff = " ";
	player2SecondBuff = " ";
	player2ThirdBuff = " ";

	player1Debuff = " ";
	player1SecondDebuff = " ";
	player1ThirdDebuff = " ";
	
	player2Debuff = " ";
	player2SecondDebuff = " ";
	player2ThirdDebuff = " ";

	player1MeditateChoice = "";
	player2MeditateChoice = "";

	player1EnhancedMove = false;
	player2EnhancedMove = false;

	player1Dodged = false;
	player2Dodged = false;

	player1Move1Used = false;
	player1Move2Used = false;
	player1Move3Used = false;
	player1Move4Used = false;
	player1Move5Used = false;
	player1Move6Used = false;
	player1Move7Used = false;
	player1Move8Used = false;

	player2Move1Used = false;
	player2Move2Used = false;
	player2Move3Used = false;
	player2Move4Used = false;
	player2Move5Used = false;
	player2Move6Used = false;
	player2Move7Used = false;
	player2Move8Used = false;

	player1Move1CD = 0;
	player1Move2CD = 0;
	player1Move3CD = 0;
	player1Move4CD = 0;
	player1Move5CD = 0;
	player1Move6CD = 0;
	player1Move7CD = 0;
	player1Move8CD = 0;

	player2Move1CD = 0;
	player2Move2CD = 0;
	player2Move3CD = 0;
	player2Move4CD = 0;
	player2Move5CD = 0;
	player2Move6CD = 0;
	player2Move7CD = 0;
	player2Move8CD = 0;

	player1Buff1Duration = 0;
	player1Buff2Duration = 0;
	player1Buff3Duration = 0;

	player2Buff1Duration = 0;
	player2Buff2Duration = 0;
	player2Buff3Duration = 0;

	player1Debuff1Duration = 0;
	player1Debuff2Duration = 0;
	player1Debuff3Duration = 0;

	player2Debuff1Duration = 0;
	player2Debuff2Duration = 0;
	player2Debuff3Duration = 0;

	player1Mana1 = true;
	player1Mana2 = true;
	player2Mana1 = true;
	player2Mana2 = true;
}