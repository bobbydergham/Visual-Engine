#pragma once
#include "Player.h"
#include "GameObjectManager.h"
#include "AudioManager.h"
#include "Multiplayer.h"

#include "VisibleObjectManager.h"




class Battle
{
public:

	//constructor
	Battle();



	//sets the players character
	Player * setCharacter(string & character) const;




	//loads and tracks the health bars (will be called every frame)
	void trackHealth(sf::RenderWindow & renderWindow, VisibleObjectManager  & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB);

	//loads and keeps track of the changing skill menu
	void characterSkillsLeft(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, Player * &playerA, Player * &playerB, GameObjectManager & _gameObjectManager);

	//loads and keeps track of the changing skill menu
	void characterSkillsRight(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, Player * &playerA, Player * &playerB, GameObjectManager & _gameObjectManager);

	//keeps track of time
	void setTimeBar(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager _gameObjectManager);

	//checks to see if any player has died
	bool checkDeath(Player * p1, Player * p2);

	//updates timer
	void updateTime(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager);

	//updates the frames for idle animations during move selection
	void updateFrame(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager, VisibleObjectManager &_visualObjectManager);

	void updateBattleFrame(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager, VisibleObjectManager &_visualObjectManager, AudioManager & _audioManager);

	//displays the moves during the attack screen
	void displayMoves(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager, VisibleObjectManager & _visibleObjectManager, Player * playerA, Player * playerB);

	void displayHUD(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager);

	void displayActiveStatuses(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB);

	void displaySkillEffects(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB);

	void displayJoystickButtons(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB);

	void joystickInputController(sf::RenderWindow & renderWindow, VisibleObjectManager  & _visibleObjectManager, GameObjectManager & _gameObjectManager, AudioManager & _audioManager, sf::Event & event, Player * playerA, Player * playerB);


	void playerActiveBuffs(Player * playerA);

	void playerActiveDebuffs(Player * playerA, Player * playerB);





	void playerOneSkillTimes(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerA);

	void playerTwoSkillTimes(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerB);

	void fpsTest(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager);



	//specifically handles the special abilities a warrior has and how it affects the turn
	void warriorFunction(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB, AudioManager & _audioManager);

	//handles the assassins complex poison application system
	void applyPoison(Player * playerA, Player * playerB);

	//specifically handles the special abilities an assassin has and how it affects the turn
	void assassinFunction(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB);

	//specifically handles the special abilities a monk has and how it affects the turn
	void monkFunction(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB);

	void necroFunction(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB);

	void demonFunction(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB);

	void meditateHandler(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, AudioManager & _audioManager, sf::Event & event, Player * playerA, Player * playerB);

	void boneCrusherHandler(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, AudioManager & _audioManager, sf::Event & event, Player * playerA, Player * playerB);

	//handles the realtime attack exchange when one player goes before another
	void attackOrder(Player * playerA, Player * playerB, sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager);

	//formula for the actual exchange of damage
	void startTurn(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager, AudioManager & _audioManager);



	//displays the characters
	void showCharacters(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager);

	//displays the skill menus
	void show(sf::RenderWindow & renderWindow, VisibleObjectManager  & _visibleObjectManager, GameObjectManager & _gameObjectManager, AudioManager & _audioManager, Multiplayer & _multiplayer, sf::Event & event, Player * playerA, Player * playerB);

	//for multiplayer
	void forceSelectMove(VisibleObjectManager  & _visibleObjectManager, GameObjectManager & _gameObjectManager, AudioManager & _audioManager, Multiplayer & _multiplayer, Player * playerA, Player * playerB,  string str);


	void showHpBars(sf::RenderWindow & renderWindow, VisibleObjectManager  & _visibleObjectManager, GameObjectManager & _gameObjectManager);

	void moveUpdate(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB);

	void manaBar(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, sf::Event & event, Player * playerA, Player * playerB);

	void battleMenu(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager, sf::Event & event, int & value, Player * playerA, Player * playerB);

	//ends the turn and updates cooldowns ect
	void endTurn(VisibleObjectManager & _visibleObjectManager, Multiplayer & _multiplayer, Player * playerA, Player * playerB);



};


