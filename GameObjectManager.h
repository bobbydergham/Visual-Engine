#pragma once

#include <iostream>
#include "Player.h"
using namespace std;


class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	//resets all game objects so that the game may be reset
	void reset();

	//resets just the right variables to allow a fresh rematch
	void rematchReset();

	void setTurnOperation(bool temp);

	bool getTurnOperation();




	//creates player 1 and player 2
	Player * player1;
	Player * player2;

	//holds what character the players have selected
	string char1;
	string char2;

	//accounts for the turn time
	sf::Time battleClock;
	sf::Time animationClock;


	//fps test clock
	sf::Clock clock2;

	//sets up times for the players moves
	sf::Time player1SkillTime;
	sf::Time player2SkillTime;

	//sets up a global clock that gets reset at certain times
	sf::Clock clock;


	//determines which player, if any attacked sucessfully
	//0 = neither player gets an interrupt animation
	//1 = player 1 interrupts player 2
	//2 = player 2 interrupts player 1
	//3 = both players attack successfully but get a hurt animation
	int playerAttackSuccessful;


	//determines if player has enhanced there move or not
	int player1Enhance;
	int player2Enhance;

	//determines if player1 have recieved a buff to themselves
	string player1Buff;
	string player1SecondBuff;
	string player1ThirdBuff;

	//determines if player2 have recieved a buff to themselves
	string player2Buff;
	string player2SecondBuff;
	string player2ThirdBuff;


	//determines if players have been stunned or knocked down(ect) for player 1
	string player1Debuff;
	string player1SecondDebuff;
	string player1ThirdDebuff;




	//determines if players have been stunned or knocked down(ect) for player 2
	string player2Debuff;
	string player2SecondDebuff;
	string player2ThirdDebuff;

	//accounts for the length of player 1s debuffs
	int player1Debuff1Duration;
	int player1Debuff2Duration;
	int player1Debuff3Duration;

	//accounts for the length of player 2s debuffs
	int player2Debuff1Duration;
	int player2Debuff2Duration;
	int player2Debuff3Duration;

	//accounts for the length of player 1s buffs
	int player1Buff1Duration;
	int player1Buff2Duration;
	int player1Buff3Duration;

	//accounts for the length of player 2s buffs
	int player2Buff1Duration;
	int player2Buff2Duration;
	int player2Buff3Duration;



	//check to see if the meditate choice matches the move
	string player1MeditateChoice;
	string player2MeditateChoice;
	

	//checks to see if players have picked there skill choice for the turn
	bool player1Picked;
	bool player2Picked;



	//checks to see if the player enhanced a move with magic or not
	bool player1EnhancedMove;
	bool player2EnhancedMove;
	
	//accounts for how many uses of magic the player has left
	int player1EnhanceUses;
	int player2EnhanceUses;

	//keeps track of if the player had sucessfully dodged last turn
	bool player1Dodged;
	bool player2Dodged;

	//mana essence tracker
	bool player1Mana1;
	bool player1Mana2;
	bool player2Mana1;
	bool player2Mana2;


	//keeps track of what moves are on cooldown for player 1
	bool player1Move1Used;
	bool player1Move2Used;
	bool player1Move3Used;
	bool player1Move4Used;
	bool player1Move5Used;
	bool player1Move6Used;
	bool player1Move7Used;
	bool player1Move8Used;
	
	int player1Move1CD;
	int player1Move2CD;
	int player1Move3CD;
	int player1Move4CD;
	int player1Move5CD;
	int player1Move6CD;
	int player1Move7CD;
	int player1Move8CD;


	//keeps track of what moves are on cooldown for player 2
	bool player2Move1Used;
	bool player2Move2Used;
	bool player2Move3Used;
	bool player2Move4Used;
	bool player2Move5Used;
	bool player2Move6Used;
	bool player2Move7Used;
	bool player2Move8Used;
	
	int player2Move1CD;
	int player2Move2CD;
	int player2Move3CD;
	int player2Move4CD;
	int player2Move5CD;
	int player2Move6CD;
	int player2Move7CD;
	int player2Move8CD;


	//turn operation
	bool turnOperationFulfilled;

	//death
	bool player1Dead;
	bool player2Dead;
};

