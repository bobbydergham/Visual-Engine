#include "stdafx.h"
#include "MainMenu.h"
#include <iostream>
using namespace std;

MainMenu::MainMenu()
{
	mainMenutexture1.loadFromFile("images/mainMenu1.png");
	mainMenutexture2.loadFromFile("images/mainMenu2.png");
	mainMenutexture3.loadFromFile("images/mainMenu3.png");
	mainMenutexture4.loadFromFile("images/mainMenu4.png");
	mainMenutexture5.loadFromFile("images/mainMenu5.png");
	mainMenu.loadFromFile("images/startGameButton.png");
	mainMenuBack.loadFromFile("images/mainMenu.png");
	menuButton.setPosition(650, 100);
	//load exit button from file
	twoPlayerOfflineTexture.loadFromFile("images/2PlayerOffline.png");
	animatorButtonTexture.loadFromFile("images/animator.png");


	twoPlayerOfflineButton.setPosition(650, 400);

	//load exit button from file

	optionsTexture.loadFromFile("images/options.png");
	optionsButton.setPosition(650, 600);

	//load exit button from file
	exitGameTexture.loadFromFile("images/endGameButton.png");
	exitButton.setPosition(650, 800);


	twoPlayerOfflineButton.setTexture(twoPlayerOfflineTexture);
	optionsButton.setTexture(optionsTexture);
	exitButton.setTexture(exitGameTexture);
	menuButton.setTexture(mainMenu);

	
	animatorButton.setTexture(animatorButtonTexture);
	animatorButton.setPosition(150, 800);
}

int MainMenu::show(sf::RenderWindow& window, sf::Event & event)
{	
	
	//main menu backdrop animation
	static int count = 0;
	
	
	if (count <= 0)
	{
		menuBackdrop.setTexture(mainMenutexture1);
	}
	else if (count <= 20)
	{
		menuBackdrop.setTexture(mainMenutexture2);
	}
	else if (count <= 40)
	{
		menuBackdrop.setTexture(mainMenutexture3);
	}
	else if (count <= 60)
	{
		menuBackdrop.setTexture(mainMenutexture4);
	}
	else if (count <= 80)
	{
		menuBackdrop.setTexture(mainMenutexture5);
	}

	else if (count <= 100)
	{
		menuBackdrop.setTexture(mainMenutexture5);
	}
	else if (count <= 120)
	{
		menuBackdrop.setTexture(mainMenutexture4);
	}
	else if (count <= 140)
	{
		menuBackdrop.setTexture(mainMenutexture3);
	}
	else if (count <= 160)
	{
		menuBackdrop.setTexture(mainMenutexture2); 
	}
	count++;
	if (count == 160) count = 0;




	

	

	
	//setting size of screen
	static sf::Vector2f windowSize(window.getView().getSize().x, window.getView().getSize().y);
	menuBackdrop.setScale(windowSize.x / menuBackdrop.getLocalBounds().width, windowSize.y / menuBackdrop.getLocalBounds().height);
	

	//draws the buttons to screen
	window.draw(menuBackdrop);
	window.draw(menuButton);
	window.draw(twoPlayerOfflineButton);
	window.draw(optionsButton);
	window.draw(exitButton);
	window.draw(animatorButton);
	window.display();

	//creates an event
	//sf::Event event;

	//creates a vector that holds the mouses position
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	//gets the bounds of the sprite
	sf::FloatRect bounds1 = menuButton.getGlobalBounds();
	sf::FloatRect bounds2 = twoPlayerOfflineButton.getGlobalBounds();
	sf::FloatRect bounds3 = optionsButton.getGlobalBounds();
	sf::FloatRect bounds4 = exitButton.getGlobalBounds();
	sf::FloatRect bounds5 = animatorButton.getGlobalBounds();


		//fills the event
		while(window.pollEvent(event))
		{
			//checks to see if the event filled is the mouse being pressed
			if(event.type == sf::Event::MouseButtonPressed)
			{					
				if(bounds1.contains(mousePos))
				{
						return 1;
				}
				else if(bounds2.contains(mousePos))
				{
						return 2;
				}
				else if(bounds3.contains(mousePos))
				{
						return 3;
				}
				else if(bounds4.contains(mousePos))
				{
						return 4;
				}
				else if (bounds5.contains(mousePos))
				{
					return 5;
				}

			}
		}
}





MainMenu::~MainMenu()
{

}



