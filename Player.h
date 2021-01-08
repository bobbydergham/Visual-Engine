
#ifndef PLAYER
#define PLAYER

#include <string>

#include "AudioManager.h"




using namespace std;


class Player
{
public:
	Player();
	Player(double setHp, double setMp);
	void setHp(double newHp);
	double getHp() const;

	void setMp(double newMp);
	double getMp() const;

	bool isStunned();
	void setStun(bool check);
	double getTotalHp() const;
	

	//resets skill choice
	void resetSkillChoice();

	//determines if a move was successful during the turn or not
	bool playerMoveWasSuccessful;


	

	////////////////////// HANDLES CURRENT SKILL CHOICE//////////////////////////////
		//move name
		string name;

		//buff that the move provides
		string buff;

		//debuff that the skill applies to the enemy
		string appliedDebuff;

		//amount of turns the buff lasts
		int buffTurns;

		//holds the value of the frame where the animation would actually hit someone 
		int keyFrame;

		//amount of turns the debuff lasts
		int debuffTurns;

		//damage the skill does
		double damage;


		//chance to dodge
		double dodgeChance;

		//time the move takes to come out
		double time;


		//damage the move mitigates
		double reductionPercent;

		//type of move being performed(allows generalization)
		string state;

		//check to see if player dodged
		bool dodged;

		//checks to see if the move can be interrupted
		bool uninterruptable;

		//checks to see if the move is unblockable
		bool unblockable;

		//holds a value for the move number
		int moveNumberUsed;

		//amount of turns on cooldown
		int moveNumberCD;


		//base animation
		string idle;


		//name of the animation of getting hurt for that character
		string hurtAnimationName;


		//tells the game to switch to hurt animation or not
		bool switchToHurt;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//virtual string getHurtAnimationName()const = 0;

	virtual string getAbility1()const = 0;
	virtual string getAbility2()const = 0;
	virtual string getAbility3()const = 0;
	virtual string getAbility4()const = 0;
	virtual string getAbility5()const = 0;
	virtual string getAbility6()const = 0;
	virtual string getAbility7()const = 0;
	virtual string getAbility8()const = 0;

	virtual double getAbilityTime1() = 0;
	virtual double getAbilityTime2() = 0;
	virtual double getAbilityTime3() = 0;
	virtual double getAbilityTime4() = 0;
	virtual double getAbilityTime5() = 0;
	virtual double getAbilityTime6() = 0;
	virtual double getAbilityTime7() = 0;
	virtual double getAbilityTime8() = 0;


	virtual void ability1(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager) = 0;
	virtual void ability2(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager) = 0;
	virtual void ability3(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager) = 0;
	virtual void ability4(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager) = 0;
	virtual void ability5(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager) = 0;
	virtual void ability6(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager) = 0;
	virtual void ability7(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager) = 0;
	virtual void ability8(bool isEnhanced, AudioManager & _audioManager, VisibleObjectManager & _visibleObjectManager) = 0;

	//sets up times for the players moves
	sf::Time playerSkillTime;


	//determines if player has enhanced there move or not
	int player1Enhance;
	int player2Enhance;

	//determines if player have recieved a buff to themselves
	string playerBuff;
	string playerSecondBuff;
	string playerThirdBuff;


	//determines if players have been stunned or knocked down(ect) for player 
	string playerDebuff;
	string playerSecondDebuff;
	string playerThirdDebuff;



	//accounts for the length of player 1s debuffs
	int playerDebuff1Duration;
	int playerDebuff2Duration;
	int playerDebuff3Duration;

	//accounts for the length of player 1s buffs
	int playerBuff1Duration;
	int playerBuff2Duration;
	int playerBuff3Duration;


	//necro meter
	double necroMeter;
	double necroMeterMax;

	//check to see if the meditate choice matches the move
	string playerMeditateChoice;

	//Bone Crusher choice
	string playerBoneCrusherChoice;
	
	//fury damage
	int furyDamage;

	

	//checks to see if players have picked there skill choice for the turn
	bool playerPicked;

	//checks to see if the player enhanced a move with magic or not
	bool playerEnhancedMove;
	
	//accounts for how many uses of magic the player has left
	int playerEnhanceUses;

	//keeps track of if the player had sucessfully dodged last turn
	bool playerDodged;

	//keeps track of what moves are on cooldown for player 
	bool playerMove1Used;
	bool playerMove2Used;
	bool playerMove3Used;
	bool playerMove4Used;
	bool playerMove5Used;
	bool playerMove6Used;
	bool playerMove7Used;
	bool playerMove8Used;
	
	//cool down length
	int playerMove1CD;
	int playerMove2CD;
	int playerMove3CD;
	int playerMove4CD;
	int playerMove5CD;
	int playerMove6CD;
	int playerMove7CD;
	int playerMove8CD;

	//player current Animation
	string currentAnimation;


protected:

	string move1;
	string move2;
	string move3;
	string move4;
	string move5;
	string move6;
	string move7;
	string move8;

	double moveTime1;
	double moveTime2;
	double moveTime3;
	double moveTime4;
	double moveTime5;
	double moveTime6;
	double moveTime7;
	double moveTime8;


	double totalHp;
	double hp;
	double mp;
	bool stunned;

	
};



#endif