#include "StdAfx.h"
#include "CharacterSelect.h"
#include "GameObjectManager.h"
#include "Assassin.h"
#include "Warrior.h"
#include "Monk.h"
#include "Necromancer.h"
#include "Demon.h"
#pragma warning(disable : 4996)



CharacterSelect::CharacterSelect()
{
		//font
	if (!font.loadFromFile("Text/times.ttf")) return;



	//checks if the file loaded properly
	if (characterSelectTexture.loadFromFile("images/selection screen.png") != true) return;



	//checks to see if the assassin icon got loaded properly
	if (!assassinMini.loadFromFile("images/assassinFight.png"))
	{
		return;
	}



	//checks to see if the warrior icon got loaded properly
	if (!warriorMini.loadFromFile("images/warriorFight.png"))
	{
		return;
	}


	if (!monkMini.loadFromFile("images/monkFight.png"))
	{
		return;
	}

	if (!necromancerMini.loadFromFile("images/necromancerFight.png"))
	{
		return;
	}

	//checks to see if the assassin icon got loaded properly
	if (!demonMini.loadFromFile("images/demonFight.png"))
	{
		return;
	}



	warrior.setTexture(warriorMini);
	warrior.scale(.75, .6);
	warrior.setPosition(20, 250);


	assassin.setTexture(assassinMini);
	assassin.scale(.75, .6);
	assassin.setPosition(800, 250);


	monk.setTexture(monkMini);
	monk.scale(.75, .6);
	monk.setPosition(1408, 250);


	necromancer.setTexture(necromancerMini);
	necromancer.scale(.75, .6);
	necromancer.setPosition(300, 250);


	demon.setTexture(demonMini);
	demon.scale(1, 1);
	demon.setPosition(1000, 250);
	characterSelect.setTexture(characterSelectTexture);
}

void CharacterSelect::show(sf::RenderWindow & renderWindow)
{

sf::Vector2f windowSize(renderWindow.getView().getSize().x, renderWindow.getView().getSize().y);

	
	
	renderWindow.draw(characterSelect);



			renderWindow.draw(warrior);
			
	
			renderWindow.draw(assassin);
		

			renderWindow.draw(monk);

			renderWindow.draw(necromancer);

	
			renderWindow.draw(demon);


	//show the new render window
	renderWindow.display();

}




Player * CharacterSelect::setCharacter(sf::RenderWindow & renderWindow, bool & p, string & character, Multiplayer & _multiplayer) const
{

	//creates an event
	sf::Event event;

	//creates a vector that holds the mouses position
	sf::Vector2f mousePos = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));
	sf::FloatRect bounds1 = assassin.getGlobalBounds();
	sf::FloatRect bounds2 = warrior.getGlobalBounds();
	sf::FloatRect bounds3 = monk.getGlobalBounds();
	sf::FloatRect bounds4 = necromancer.getGlobalBounds();
	sf::FloatRect bounds5 = demon.getGlobalBounds();


	//fills the event
	while (renderWindow.pollEvent(event))
	{
		//checks to see if the event filled is the mouse being pressed
		if (event.type == sf::Event::MouseButtonPressed)
		{

			if (bounds1.contains(mousePos))
			{
				p = true;
				Player * player = NULL;
				Assassin * ass = new Assassin;
				player = ass;
				character = "assassin";
				if (_multiplayer.connection)
				{
					_multiplayer.send("a");
				}
				return player;
			}

			if (bounds2.contains(mousePos))
			{
				p = true;
				Warrior * warr = new Warrior;
				Player * player = NULL;
				player = warr;
				character = "warrior";
				if (_multiplayer.connection)
				{
					_multiplayer.send("w");
				}
				return player;

			}


			if (bounds3.contains(mousePos))
			{
				p = true;
				Monk * monk = new Monk;
				Player * player = NULL;
				player = monk;
				character = "monk";
				if (_multiplayer.connection)
				{
					_multiplayer.send("m");
				}
				return player;

			}

			if (bounds4.contains(mousePos))
			{
				p = true;
				Necromancer * necromancer = new Necromancer;
				Player * player = NULL;
				player = necromancer;
				character = "necromancer";
				if (_multiplayer.connection)
				{
					_multiplayer.send("n");
				}
				return player;

			}

			if (bounds5.contains(mousePos))
			{
				p = true;
				Demon * demon = new Demon;
				Player * player = NULL;
				player = demon;
				character = "demon";
				if (_multiplayer.connection)
				{
					_multiplayer.send("d");
				}
				return player;
			}
		}
	}
}


		
Player * CharacterSelect::forceSelect(sf::RenderWindow & renderWindow, bool & p, string & character, Multiplayer & _multiplayer, string choice) const
{

			if (choice == "assassin")
			{
				p = true;
				Player * player = NULL;
				Assassin * ass = new Assassin;
				player = ass;
				character = "assassin";
				return player;
			}
			else if (choice == "warrior")
			{
				p = true;
				Warrior * warr = new Warrior;
				Player * player = NULL;
				player = warr;
				character = "warrior";
				return player;
			}
			else if (choice == "monk")
			{
				p = true;
				Monk * monk = new Monk;
				Player * player = NULL;
				player = monk;
				character = "monk";
				return player;

			}
			else if (choice == "necromancer")
			{
				p = true;
				Necromancer * necromancer = new Necromancer;
				Player * player = NULL;
				player = necromancer;
				character = "necromancer";
				return player;

			}
			else if (choice == "demon")
			{
				p = true;
				Demon * demon = new Demon;
				Player * player = NULL;
				player = demon;
				character = "demon";
				return player;
			}
			
}

void CharacterSelect::drawPlayer1Logo(sf::RenderWindow & renderWindow)
{
	sf::Text player1Pick;
	player1Pick.setFont(font);
	player1Pick.setString("Player 1");
	player1Pick.setCharacterSize(200);
	player1Pick.setColor(sf::Color::White);
	player1Pick.setPosition(500,500);

	renderWindow.draw(player1Pick);
}

void CharacterSelect::drawPlayer2Logo(sf::RenderWindow & renderWindow)
{
		sf::Text player2Pick;
		player2Pick.setFont(font);
	player2Pick.setString("Player 2");
	player2Pick.setCharacterSize(200);
	player2Pick.setColor(sf::Color::White);
	player2Pick.setPosition(500,500);

	renderWindow.draw(player2Pick);
}




