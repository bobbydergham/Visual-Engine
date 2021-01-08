#include "stdafx.h"
#include "Game.h"
#include "Player.h"


	//sets offline mode
	static bool offlineMode;


void Game::Start()
{
	offlineMode = false;
	//if game state fails to initialize the program closes
	if(_gameState != uninitialized) return;
	sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
	//creates the window 
	_mainWindow.create(desktop, "Battle of Gaia"/*, sf::Style::Fullscreen*/);
	
	//sets max fps to 60
	_mainWindow.setFramerateLimit(60);



	//sets initial game state
	_gameState = Game::showingSplash;

	//loops the game unless the game state is set to isExiting
	while(!isExiting())
	{
		gameLoop(); //the main loop
	}

	//closes the game
	_mainWindow.close();
}


//handles the isExiting game state
bool Game::isExiting()
{
	if(_gameState == Game::exiting)
		return true;
	else
		return false;
}


void Game::gameLoop()
{

	//creates an event
	sf::Event event;
	sf::Event event2;
	//fills the event
	_mainWindow.pollEvent(event);
	_mainWindow.pollEvent(event2);


	

	switch(_gameState)
	{
		//main menu state
		case Game::showingMenu:
			{
				showMenu(event);
				_mainWindow.clear();
				break;
			}
		case Game::onlineMenuScreen:
			{
				onlineMenuInterface(event);
				_mainWindow.clear();
				break;
			}
		//splash screen state
		case Game::showingSplash:
			{
				showSplashScreen();
				_mainWindow.clear();
				break;
			}

		//character screen state
		case Game::characterSelect:
			{
				showCharacterSelect();
				_mainWindow.clear();
				break;
			}
		case Game::onlineCharacterSelect:
			{
				onlineCharSelect(event);
				_mainWindow.clear();
				break;
			}
		//load screen
		case Game::loadingScreen:
			{
				showLoadingScreen();
				_mainWindow.clear();
				break;
			}
		case Game::animator:
		{
			_mainWindow.display();
			showAnimator(event);
			break;
		}
		case Game::battle:
			{
					_mainWindow.display();
					
					
					showBattle(event);
						
		

					if(event.type == sf::Event::Closed) _gameState = Game::exiting;

					if(event.type == sf::Event::KeyPressed)
						{
							if(event.key.code == sf::Keyboard::Escape) showMenu(event);
						}
				
				break;


			}
	}
}


void Game::onlineMenuInterface(sf::Event event)
{
	 onlineMenu * onlineGameMenu = new onlineMenu;
	 switch (onlineGameMenu->showMenu(_mainWindow, event))
	 {
		 //create
	 case 1:
		 _multiplayer.server();

		 _gameState = Game::onlineCharacterSelect;
		 break;

		 //join
	 case 2:
		 _multiplayer.client();
		 _gameState = Game::onlineCharacterSelect;

		 break;
	 };


	
}

//splash screen
void Game::showSplashScreen()
{
	SplashScreen * splashScreen = new SplashScreen;
	splashScreen->show(_mainWindow, _visibleObjectManager);
	delete splashScreen;
	splashScreen = NULL;


	_gameState = Game::showingMenu;
	_audioManager.playIntro(1);


}



//main menu
void Game::showMenu(sf::Event event)
{
	
	static MainMenu * mainMenu = new MainMenu;

	

	switch(mainMenu->show(_mainWindow, event))
	{
	case 1:
		//switches to character select
		_gameState = Game::onlineMenuScreen;

		//cleans up memory
		delete mainMenu;
		mainMenu =  NULL;

		//sets the next screens music

		break;


	case 2:

		//switches to character select
		_gameState = Game::characterSelect;

		//sets to offline mode
		offlineMode = true;

		//cleans up memory
		delete mainMenu;
		mainMenu =  NULL;

		//sets the next screens music
		_audioManager.playIntro(0);
		_audioManager.playCharacterSelect(1);

		break;

	case 3:

		//options menu;
		_gameState = Game::options;
		break;

	case 4:

		//closes the game;
		_gameState = Game::exiting;
		break;

	case 5:
		//goes to animator debugger;
		//cleans up memory
		delete mainMenu;
		mainMenu = NULL;
		_mainWindow.clear(sf::Color::Black);
		_mainWindow.display();

		//loads basic textures
		_visibleObjectManager.loadTextures();
		_visibleObjectManager.loadBattleArena(1, _mainWindow);

		_gameState = Game::animator;
		break;
	}
}



void Game::showCharacterSelect()
{

	bool player1Picked = false;
	bool player2Picked = false;


	CharacterSelect * characterSelect = new CharacterSelect;
	
	
	//renders the character select screen
	characterSelect->show(_mainWindow);

	//waits for player one to pick
	while(!player1Picked)
	{
		_mainWindow.clear(sf::Color::Black);
		characterSelect->show(_mainWindow);
		_gameObjectManager.player1 = characterSelect->setCharacter(_mainWindow, player1Picked, _gameObjectManager.char1, _multiplayer);
		characterSelect->drawPlayer1Logo(_mainWindow);

		_mainWindow.display();
	}

	//waits for player two to pick
	while(!player2Picked)
	{
		_gameObjectManager.player2 = characterSelect->setCharacter(_mainWindow, player2Picked, _gameObjectManager.char2, _multiplayer);
		characterSelect->drawPlayer2Logo(_mainWindow);

	}

	//switches to loading screen
	_gameState = loadingScreen;


	//displays a black screen
	_mainWindow.clear(sf::Color::Black);
	_mainWindow.display();

	//cleans up memory
	delete characterSelect;
	characterSelect = NULL;


}

void Game::onlineCharSelect(sf::Event event)
{
	
	bool player1Picked = false;
	bool player2Picked = false;
	

	CharacterSelect * characterSelect = new CharacterSelect;

	//renders the character select screen
	characterSelect->show(_mainWindow);

	if(_multiplayer.host)
	{
		while (!player2Picked || !player1Picked)
		{
			if (!player1Picked)_gameObjectManager.player1 = characterSelect->setCharacter(_mainWindow, player1Picked, _gameObjectManager.char1, _multiplayer);
			_multiplayer.receive();
			cout << _multiplayer.buffer;
			if(_multiplayer.buffer[0] == 'a')
			{
				_gameObjectManager.player2 = characterSelect->forceSelect(_mainWindow, player2Picked, _gameObjectManager.char2, _multiplayer, "assassin");
			}
			else if (_multiplayer.buffer[0] == 'w')
			{
				_gameObjectManager.player2 = characterSelect->forceSelect(_mainWindow, player2Picked, _gameObjectManager.char2, _multiplayer, "warrior");
			}
			else if (_multiplayer.buffer[0] == 'd')
			{
				_gameObjectManager.player2 = characterSelect->forceSelect(_mainWindow, player2Picked, _gameObjectManager.char2, _multiplayer, "demon");
			}
			else if (_multiplayer.buffer[0] == 'n')
			{
				_gameObjectManager.player2 = characterSelect->forceSelect(_mainWindow, player2Picked, _gameObjectManager.char2, _multiplayer, "necromancer");
			}
			else if (_multiplayer.buffer[0] == 'm')
			{
				_gameObjectManager.player2 = characterSelect->forceSelect(_mainWindow, player2Picked, _gameObjectManager.char2, _multiplayer, "monk");
			}
		}
	}
	else
	{
		while (!player2Picked || !player1Picked)
		{

			if(!player2Picked) _gameObjectManager.player2 = characterSelect->setCharacter(_mainWindow, player2Picked, _gameObjectManager.char2, _multiplayer);
			_multiplayer.receive();
			cout << _multiplayer.buffer;
			if (_multiplayer.buffer[0] == 'a')
			{
				_gameObjectManager.player1 = characterSelect->forceSelect(_mainWindow, player1Picked, _gameObjectManager.char1, _multiplayer, "assassin");
			}
			else if (_multiplayer.buffer[0] == 'w')
			{
				_gameObjectManager.player1 = characterSelect->forceSelect(_mainWindow, player1Picked, _gameObjectManager.char1, _multiplayer, "warrior");
			}
			else if (_multiplayer.buffer[0] == 'd')
			{
				_gameObjectManager.player1 = characterSelect->forceSelect(_mainWindow, player1Picked, _gameObjectManager.char1, _multiplayer, "demon");
			}
			else if (_multiplayer.buffer[0] == 'n')
			{
				_gameObjectManager.player1 = characterSelect->forceSelect(_mainWindow, player1Picked, _gameObjectManager.char1, _multiplayer, "necromancer");
			}
			else if (_multiplayer.buffer[0] == 'm')
			{
				_gameObjectManager.player1 = characterSelect->forceSelect(_mainWindow, player1Picked, _gameObjectManager.char1, _multiplayer, "monk");
			}
		}
		
	}

	//switches to loading screen
	_gameState = loadingScreen;


	//displays a black screen
	_mainWindow.clear(sf::Color::Black);
	_mainWindow.display();

	//cleans up memory
	delete characterSelect;
	characterSelect = NULL;

}
//pre loads everything the game is going to use
void Game::showLoadingScreen()
{
	_mainWindow.draw(_visibleObjectManager.loadingBar);

	//loads basic textures
	_visibleObjectManager.loadTextures();


	//loads warrior textures if hes picked 
	if (_gameObjectManager.char1 == "warrior" || _gameObjectManager.char2 == "warrior")
	{
		_visibleObjectManager.loadWarriorTextures();

		//makes sure the warrior sprite sheets are loaded and cropped properly from frame 1 for player 1
		if (_gameObjectManager.char1 == "warrior")
		{
			_visibleObjectManager.player1Character.setPosition(500, 300);
			_visibleObjectManager.player1Character.setTextureRect(sf::IntRect(3553, 550, 393, 550));
		}

		//makes sure the warrior sprite sheets are loaded and cropped properly from frame 1 for player 2
		if (_gameObjectManager.char2 == "warrior")
		{
			_visibleObjectManager.player2Character.setPosition(1420, 300);
			_visibleObjectManager.player2Character.setTextureRect(sf::IntRect(3553, 550, 393, 550));
		}
	}

	//loads assassin textures if hes picked
	if(_gameObjectManager.char1 == "assassin" || _gameObjectManager.char2 == "assassin")
	{
		_visibleObjectManager.loadAssassinTextures();
	}

	//loads monk textures if hes picked
	if(_gameObjectManager.char1 == "monk" || _gameObjectManager.char2 == "monk")
	{
		_visibleObjectManager.loadMonkTextures();
	}

	//loads assassin textures if hes picked
	if(_gameObjectManager.char1 == "necromancer" || _gameObjectManager.char2 == "necromancer")
	{
		_visibleObjectManager.loadNecroTextures();
	}


	//loads assassin textures if hes picked
	if(_gameObjectManager.char1 == "demon" || _gameObjectManager.char2 == "demon")
	{
		_visibleObjectManager.loadDemonTextures();
	}

	//loads fonts
	_visibleObjectManager.loadFonts();

	//switches music 
	_audioManager.playCharacterSelect(0);
	_audioManager.playArenaMusic(1);

	//resets clock
	_gameObjectManager.clock.restart();




	_visibleObjectManager.loadBattleArena(1, _mainWindow);




	_visibleObjectManager.player1HpBar.move(100,50);
	_visibleObjectManager.player2HpBar.move(870,50);

	if(_gameObjectManager.char1 == "assassin") _visibleObjectManager.player1Character.scale(.88, .88);
	if(_gameObjectManager.char2 == "assassin") _visibleObjectManager.player2Character.scale(.88, .88);


		if (_multiplayer.multiplayer)
		{
			_gameState = Game::battle;
		}
		else if (offlineMode)
		{
			//handles both online and offline
			_gameState = Game::battle;
		}
}



void Game::showBattle(sf::Event event)
{
	
	static bool turnPhase = false;
	static Battle battle;
	static int switchNumber = 1;
	bool death = false;
	sf::Time elapsed1 = _gameObjectManager.clock.getElapsedTime();


	switch (switchNumber)
	{
	case 1:




		if (turnPhase)
		{
			battle.endTurn(_visibleObjectManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2);
			turnPhase = false;
		}

		//fps test function
		battle.fpsTest(_mainWindow, _gameObjectManager);


		//renders backround image
		_visibleObjectManager.drawBattleMap(_mainWindow);

		//shows mana bars
		battle.manaBar(_mainWindow, _visibleObjectManager, _gameObjectManager, event, _gameObjectManager.player1, _gameObjectManager.player2);

		//handles HUD overlay for display of statuses
		battle.displayHUD(_mainWindow, _visibleObjectManager, _gameObjectManager);

		//handles turn timer???
		battle.updateTime(_mainWindow, _gameObjectManager);



		//handles idle animations
		battle.updateFrame(_mainWindow, _gameObjectManager, _visibleObjectManager);


		if (sf::Joystick::isConnected(0) || sf::Joystick::isConnected(1))
		{
			//handles joystick input
			battle.joystickInputController(_mainWindow, _visibleObjectManager, _gameObjectManager, _audioManager, event, _gameObjectManager.player1, _gameObjectManager.player2);
		}
		else
		{
			//handles if players can't attack, display of buffs/debuffs, handles event handler for clicking of the skill buttons
			battle.show(_mainWindow, _visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, event, _gameObjectManager.player1, _gameObjectManager.player2); //currently lowers fps by 3
		}
		//checks to see if player has picked in an online match
		_multiplayer.receive();
		//sets there move for when they have
		if (_multiplayer.host)
		{
			if (_multiplayer.buffer[0] == '1') battle.forceSelectMove( _visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "1");
			else if (_multiplayer.buffer[0] == '2') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "2");
			else if (_multiplayer.buffer[0] == '3') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "3");
			else if (_multiplayer.buffer[0] == '4') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "4");
			else if (_multiplayer.buffer[0] == '5') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "5");
			else if (_multiplayer.buffer[0] == '6') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "6");
			else if (_multiplayer.buffer[0] == '7') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "7");
			else if (_multiplayer.buffer[0] == '8') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "8");
		}
		else
		{
			if (_multiplayer.buffer[0] == '1') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "1");
			else if (_multiplayer.buffer[0] == '2') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "2");
			else if (_multiplayer.buffer[0] == '3') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "3");
			else if (_multiplayer.buffer[0] == '4') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "4");
			else if (_multiplayer.buffer[0] == '5') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "5");
			else if (_multiplayer.buffer[0] == '6') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "6");
			else if (_multiplayer.buffer[0] == '7') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "7");
			else if (_multiplayer.buffer[0] == '8') battle.forceSelectMove(_visibleObjectManager, _gameObjectManager, _audioManager, _multiplayer, _gameObjectManager.player1, _gameObjectManager.player2, "8");
		}
		//handles health bar display
		battle.trackHealth(_mainWindow, _visibleObjectManager, _gameObjectManager, _gameObjectManager.player1, _gameObjectManager.player2);

		//displays hp bars
		battle.showHpBars(_mainWindow, _visibleObjectManager, _gameObjectManager);



		//handles the rendering of images related to player ones skill bar
		battle.characterSkillsLeft(_mainWindow, _visibleObjectManager, _gameObjectManager.player1, _gameObjectManager.player2, _gameObjectManager);	//lowers by 1

																																					//handles the rendering of images related to player ones skill bar
		battle.characterSkillsRight(_mainWindow, _visibleObjectManager, _gameObjectManager.player1, _gameObjectManager.player2, _gameObjectManager);	//lowers by 1

																																						//displays skill times for player 1(adjusts depending on buffs/debuffs)
		battle.playerOneSkillTimes(_mainWindow, _visibleObjectManager, _gameObjectManager, _gameObjectManager.player1);

		//displays skill times for player 2(adjusts depending on buffs/debuffs)
		battle.playerTwoSkillTimes(_mainWindow, _visibleObjectManager, _gameObjectManager, _gameObjectManager.player2);


		//draws the joystick buttons
		battle.displayJoystickButtons(_mainWindow, _visibleObjectManager, _gameObjectManager, _gameObjectManager.player1, _gameObjectManager.player2);




		//handles render and countdown of turn
		battle.setTimeBar(_mainWindow, _visibleObjectManager, _gameObjectManager);


		//handles display of buffs/debuffs
		battle.displayActiveStatuses(_mainWindow, _visibleObjectManager, _gameObjectManager, _gameObjectManager.player1, _gameObjectManager.player2);

		//handles display of buffs/debuffs
		battle.displaySkillEffects(_mainWindow, _visibleObjectManager, _gameObjectManager, _gameObjectManager.player1, _gameObjectManager.player2);




		//handles skill choices and transistion to battle animations
		if ((_gameObjectManager.player1->playerPicked == true && _gameObjectManager.player2->playerPicked == true)
			|| (int)elapsed1.asSeconds() > 90 //turn time
			|| (_gameObjectManager.player1->playerPicked == true && _gameObjectManager.player2->isStunned() == true)
			|| (_gameObjectManager.player2->playerPicked == true && _gameObjectManager.player1->isStunned() == true)) switchNumber = 2;
		break;

	case 2:

		//changes the clock to handle the battle phase
		_gameObjectManager.clock.restart();

		_gameObjectManager.setTurnOperation(false);

		//switches off to the next step
		switchNumber = 3;
		_visibleObjectManager.player1CurrentAnimationFrame = 1;
		_visibleObjectManager.player2CurrentAnimationFrame = 1;

		break;


		//damage exchange and math
	case 3:
		battle.startTurn(_mainWindow, _gameObjectManager, _audioManager);

		_gameObjectManager.clock.restart();
		_gameObjectManager.player1->playerPicked = false;
		_gameObjectManager.player2->playerPicked = false;

		turnPhase = true;

		switchNumber = 4;

		_gameObjectManager.clock.restart();
		break;

		//animation of the skill boxes 
	case 4:
		//renders backround image
		_visibleObjectManager.drawBattleMap(_mainWindow);

		//handles the animation
		_visibleObjectManager.showSkillAnimation(0, _mainWindow, _gameObjectManager.player1->name, _gameObjectManager.player2->name);

		//sets the time for the animation window(default 2 seconds)
		if (_gameObjectManager.clock.getElapsedTime().asSeconds() > 2)
		{
			switchNumber = 5;
		}


		break;

		//animation of the fight
	case 5:


		//resets the sprites used in skill box animation back to their original states
		_visibleObjectManager.SkillMenuPlayer1Skill1.setColor(sf::Color::White);
		_visibleObjectManager.SkillMenuPlayer2Skill1.setColor(sf::Color::White);
		_visibleObjectManager.SkillMenuPlayer1Skill1.setPosition(410, 650);
		_visibleObjectManager.SkillMenuPlayer2Skill1.setPosition(1185, 650);
		_visibleObjectManager.skillAnim1.setPosition(460, 650);
		_visibleObjectManager.skillAnim2.setPosition(1238, 650);

		//renders backround image
		_visibleObjectManager.drawBattleMap(_mainWindow);


		//handles attack animations
		battle.updateBattleFrame(_mainWindow, _gameObjectManager, _visibleObjectManager, _audioManager);


		//displays move names during attack phase
		battle.displayMoves(_mainWindow, _gameObjectManager, _visibleObjectManager, _gameObjectManager.player1, _gameObjectManager.player2);



		//sets the time for the animation window(default 3 seconds)
		if (_gameObjectManager.clock.getElapsedTime().asSeconds() > 5)
		{

			//resets move choices and lowers cd by 1 ect
			battle.moveUpdate(_gameObjectManager, _gameObjectManager.player1, _gameObjectManager.player2);
			switchNumber = 1;
		}




		//if somebody has died, transistions to the match over screen
		if (battle.checkDeath(_gameObjectManager.player1, _gameObjectManager.player2)) switchNumber = 6;

		break;



		//post fight screen
	case 6:

		int value;
		battle.battleMenu(_mainWindow, _gameObjectManager, event, value, _gameObjectManager.player1, _gameObjectManager.player2);

		//handles rematch 
		if (value == 1)
		{

			switchNumber = 1;
			_gameObjectManager.rematchReset();
			_audioManager.playArenaMusic(0);
			_audioManager.playArenaMusic(1);


		}

		//handles charatcer select from post fight screen
		else if (value == 2)
		{
			switchNumber = 1;
			_gameState = Game::characterSelect;
			_gameObjectManager.reset();
			_audioManager.playArenaMusic(0);
			_audioManager.playCharacterSelect(1);
		}

		//handles going back to main menu from post fight screen
		else if (value == 3)
		{
			switchNumber = 1;
			_audioManager.playArenaMusic(0);
			_audioManager.playIntro(1);
			_gameState = Game::showingMenu;
			_gameObjectManager.reset();
		}



		break;
	}










}


void Game::showAnimator(sf::Event event)
{
	static Animator * _animator = new Animator;
	cout << "test";
	static int switchNumber = 1;
	switch (switchNumber)
	{
	case 1:
		//loads basic textures
		_visibleObjectManager.loadTextures();
		switchNumber = 2;
	case 2:
		_animator->list_dir();
		_animator->loadAllFiles();
		_visibleObjectManager.drawBattleMap(_mainWindow);
		_animator->animateCurrentMove(_mainWindow, event);
	}
}


Game::gameState Game::_gameState = uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;

AudioManager Game::_audioManager;
VisibleObjectManager Game::_visibleObjectManager;
Multiplayer Game::_multiplayer;

