#ifndef GAME
#define GAME

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "CharacterSelect.h"
#include "Battle.h"
#include "Player.h"
#include "GameObjectManager.h"
#include "AudioManager.h"
#include "onlineMenu.h"
#include "Multiplayer.h"
#include "Animator.h"

 class Game
 {
 public:
	
	 static void Start();
 private:
	 static bool isExiting();
	 static void gameLoop();
	 static void onlineMenuInterface(sf::Event event);
	 static void showSplashScreen();
	 static void showCharacterSelect();
	 static void onlineCharSelect(sf::Event event);
	 static void onlineVersus(sf::Event event);
	 static void showBattle(sf::Event event);
	 static void showMenu(sf::Event event);
	 static void showLoadingScreen();
	 static void showAnimator(sf::Event event);


	 enum gameState
	 {
		 uninitialized,
		 showingSplash,
		 onlineMenuScreen, 
		 onlineCharacterSelect,
		 characterSelect,
		 loadingScreen,
		 paused,
		 showingMenu,
		 playing,
		 battle,
		 options,
		 animator,
		 exiting
	 };

	

	 static gameState _gameState;
	 static sf::RenderWindow _mainWindow;
	 static GameObjectManager _gameObjectManager;
	 static Multiplayer _multiplayer;
	 static AudioManager _audioManager;
	 static VisibleObjectManager _visibleObjectManager;
 };

#endif
