#ifndef MAINMENU
#define MAINMENU

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>

class MainMenu
{
public:
	enum menuResult {nothing, exit, play, playOffline, options, animator};
	MainMenu();
	int show(sf::RenderWindow& window, sf::Event & event);

	~MainMenu();


	sf::Texture mainMenutexture1;
	sf::Texture mainMenutexture2;
	sf::Texture mainMenutexture3;
	sf::Texture mainMenutexture4;
	sf::Texture mainMenutexture5;
	sf::Texture mainMenutexture6;
	sf::Texture mainMenutexture7;
	sf::Texture mainMenutexture8;
	sf::Texture mainMenutexture9;
	sf::Texture mainMenu;
	sf::Sprite menuButton;
	sf::Texture mainMenuBack;
	sf::Sprite menuBackdrop;

	sf::Texture animatorButtonTexture;
	sf::Sprite animatorButton;

	//load exit button from file
	sf::Texture twoPlayerOfflineTexture;
	sf::Sprite twoPlayerOfflineButton;


	//load exit button from file
	sf::Texture optionsTexture;

	sf::Sprite optionsButton;

	//load exit button from file
	sf::Texture exitGameTexture;
	sf::Sprite exitButton;

};







#endif