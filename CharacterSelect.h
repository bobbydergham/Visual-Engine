#ifndef CHARACTERSELECT
#define CHARACTERSELECT

#include <iostream>
#include <fstream>
#include "Player.h"
#include "GameObjectManager.h"
#include "Multiplayer.h"
using namespace std;

 class CharacterSelect
 {
 public:
	 CharacterSelect();
	

    void show(sf::RenderWindow & window);
    Player * setCharacter(sf::RenderWindow & renderWindow, bool & p, string & character, Multiplayer & _multiplayer) const;
	Player * forceSelect(sf::RenderWindow & renderWindow, bool & p, string & character, Multiplayer & _multiplayer, string choice) const;

	 void drawPlayer1Logo(sf::RenderWindow & renderWindow);
	 void drawPlayer2Logo(sf::RenderWindow & renderWindow);

	 //character select background
	 sf::Texture characterSelectTexture;
	 sf::Font font;



	 //creates an image for assassin icon
	 sf::Texture assassinMini;



	 //creates an image for the warrior icon
	 sf::Texture warriorMini;



	 sf::Texture monkMini;

	 sf::Texture necromancerMini;


	 //creates an image for assassin icon
	 sf::Texture demonMini;

	 sf::Sprite characterSelect;
	sf::Sprite warrior;
	sf::Sprite assassin;
	sf::Sprite monk;
	sf::Sprite necromancer;
	sf::Sprite demon;

 };


#endif