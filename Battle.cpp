#include "stdafx.h"
#include "Battle.h"
#include "Warrior.h"
#include "Assassin.h"
#include "Monk.h"
#include "Necromancer.h"
#include "Demon.h"
#include "Player.h"
#include "GameObjectManager.h"
#include "AudioManager.h"
#include <sstream>
#include <queue>


//base constructor
Battle::Battle(void)
{

}


//handles what characters have been picked
Player * Battle::setCharacter(string & character) const
{

	Player * p = NULL;
	Warrior * warr = new Warrior;
	Assassin * ass = new Assassin;
	Monk * monk = new Monk;
	Necromancer * necro = new Necromancer;
	Demon * demon = new Demon;


	if (character == "warrior")
	{
		p = warr;
		delete ass;
		delete monk;
		delete necro;
		delete demon;
		ass = NULL;
		monk = NULL;
		necro = NULL;
		demon = NULL;

	}
	else if (character == "assassin")
	{
		p = ass;
		delete warr;
		delete monk;
		delete necro;
		delete demon;
		warr = NULL;
		monk = NULL;
		necro = NULL;
		demon = NULL;
	}
	else if (character == "monk")
	{
		p = monk;
		delete warr;
		delete ass;
		delete necro;
		delete demon;

		warr = NULL;
		ass = NULL;
		necro = NULL;
		demon = NULL;
	}
	else if (character == "necromancer")
	{
		p = necro;
		delete warr;
		delete ass;
		delete monk;
		delete demon;

		warr = NULL;
		ass = NULL;
		monk = NULL;
		demon = NULL;
	}
	else if (character == "demon")
	{
		p = demon;
		delete warr;
		delete ass;
		delete necro;
		delete monk;

		warr = NULL;
		ass = NULL;
		necro = NULL;
		monk = NULL;
	}
	return p;
}



//displays the sprites
void Battle::showCharacters(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager)
{
	sf::Time clock;
	if (_gameObjectManager.char1 == "warrior")
	{

		_visibleObjectManager.warriorIdle(_visibleObjectManager.player1CurrentAnimationFrame, 1);

		//draws to screen
		renderWindow.draw(_visibleObjectManager.player1Character);

	}

	else if (_gameObjectManager.char1 == "assassin")
	{
		_visibleObjectManager.player1Character.setTexture(_visibleObjectManager.AssassinTexture);
		renderWindow.draw(_visibleObjectManager.player1Character);
	}
	else if (_gameObjectManager.char1 == "monk")
	{
		if (_gameObjectManager.player1->playerBuff == "Step in" || _gameObjectManager.player1->playerSecondBuff == "Step in" || _gameObjectManager.player1->playerThirdBuff == "Step in")
		{
			_visibleObjectManager.monkStepinIdle(_visibleObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visibleObjectManager.monkIdle(_visibleObjectManager.player1CurrentAnimationFrame, 1);
		}

		//draws to screen
		renderWindow.draw(_visibleObjectManager.player1Character);
	}

	else if (_gameObjectManager.char1 == "necromancer")
	{
		_visibleObjectManager.player1Character.setTexture(_visibleObjectManager.NecromancerTexture);
		renderWindow.draw(_visibleObjectManager.player1Character);
		_visibleObjectManager.loadSoulBarPlayer1();
	}
	else if (_gameObjectManager.char1 == "demon")
	{
		_visibleObjectManager.player1Character.setTexture(_visibleObjectManager.DemonTexture);
		renderWindow.draw(_visibleObjectManager.player1Character);
	}




	//player 2////////////
	if (_gameObjectManager.char2 == "warrior")
	{

		_visibleObjectManager.warriorIdle(_visibleObjectManager.player2CurrentAnimationFrame, 2);

		//draws to screen
		renderWindow.draw(_visibleObjectManager.player2Character);
	}
	else if (_gameObjectManager.char2 == "assassin")
	{
		_visibleObjectManager.player2Character.setTexture(_visibleObjectManager.AssassinTexture);
		renderWindow.draw(_visibleObjectManager.player2Character);
	}
	else if (_gameObjectManager.char2 == "monk")
	{
		if (_gameObjectManager.player2->playerBuff == "Step in" || _gameObjectManager.player2->playerSecondBuff == "Step in" || _gameObjectManager.player2->playerThirdBuff == "Step in")
		{
			_visibleObjectManager.monkStepinIdle(_visibleObjectManager.player2CurrentAnimationFrame, 1);
		}
		else
		{
			_visibleObjectManager.monkIdle(_visibleObjectManager.player2CurrentAnimationFrame, 1);
		}

		//draws to screen
		renderWindow.draw(_visibleObjectManager.player2Character);
	}

	else if (_gameObjectManager.char2 == "necromancer")
	{
		_visibleObjectManager.player2Character.setTexture(_visibleObjectManager.NecromancerTexture);
		renderWindow.draw(_visibleObjectManager.player2Character);
	}
	else if (_gameObjectManager.char2 == "demon")
	{
		_visibleObjectManager.player2Character.setTexture(_visibleObjectManager.DemonTexture);
		renderWindow.draw(_visibleObjectManager.player2Character);
	}

}


//main function for selecting move
void Battle::show(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, AudioManager & _audioManager, Multiplayer & _multiplayer, sf::Event & event, Player * playerA, Player * playerB)
{
	
	//sets the intial textures
	_visibleObjectManager.ManaBar1Player1.setTexture(_visibleObjectManager.ManaBarTexture);
	_visibleObjectManager.ManaBar2Player1.setTexture(_visibleObjectManager.ManaBarTexture);
	_visibleObjectManager.ManaBar1Player2.setTexture(_visibleObjectManager.ManaBarTexture);
	_visibleObjectManager.ManaBar2Player2.setTexture(_visibleObjectManager.ManaBarTexture);

	//creates a vector that holds the mouses position
	sf::Vector2f mousePos = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));

	//sets up a clickable response
	sf::FloatRect p1m1position = _visibleObjectManager.ManaBar1Player1.getGlobalBounds();
	sf::FloatRect p1m2position = _visibleObjectManager.ManaBar2Player1.getGlobalBounds();
	sf::FloatRect p2m1position = _visibleObjectManager.ManaBar1Player2.getGlobalBounds();
	sf::FloatRect p2m2position = _visibleObjectManager.ManaBar2Player2.getGlobalBounds();


	//checks to see if the event filled is the mouse being pressed
	//handles mana
	if (event.type == sf::Event::MouseButtonPressed && sf::Event::MouseLeft)
	{
		if (p1m1position.contains(mousePos) && (_gameObjectManager.player1Mana1 == true))
		{

			playerA->playerEnhancedMove = true;
			playerA->playerEnhanceUses--;
			_gameObjectManager.player1Mana1 = false;

		}
		else if (p1m2position.contains(mousePos) && (_gameObjectManager.player1Mana2 == true))
		{

			playerA->playerEnhancedMove = true;
			playerA->playerEnhanceUses--;
			_gameObjectManager.player1Mana2 = false;
		}

		else if (p2m1position.contains(mousePos) && (_gameObjectManager.player2Mana1 == true))
		{

			playerB->playerEnhancedMove = true;
			playerB->playerEnhanceUses--;
			_gameObjectManager.player2Mana1 = false;
		}
		else if (p2m2position.contains(mousePos) && (_gameObjectManager.player2Mana2 == true))
		{

			playerB->playerEnhancedMove = true;
			playerB->playerEnhanceUses--;
			_gameObjectManager.player2Mana2 = false;

		}
	}







	//booleans that check if the player is unable to attack this turn
	bool player1Disabled = false;
	bool player2Disabled = false;

	if (playerA->playerDebuff == "stunned" || playerA->playerSecondDebuff == "stunned" ||
		playerA->playerThirdDebuff == "stunned") player1Disabled = true;
	else player1Disabled = false;
	if (playerB->playerDebuff == "stunned" || playerB->playerSecondDebuff == "stunned" ||
		playerB->playerThirdDebuff == "stunned") player2Disabled = true;
	else player2Disabled = false;



	//creates 2 texts containers for a debuff
	sf::Text player1Debuff;
	sf::Text player2Debuff;

	//sets their font
	player1Debuff.setFont(_visibleObjectManager.font);
	player2Debuff.setFont(_visibleObjectManager.font);


	// sets the strings to display under a condition


	if (playerA->playerDebuff == "stunned") player1Debuff.setString(playerA->playerDebuff);
	else if (playerA->playerSecondDebuff == "stunned") player1Debuff.setString(playerA->playerSecondDebuff);
	else if (playerA->playerThirdDebuff == "stunned") player1Debuff.setString(playerA->playerThirdDebuff);

	if (playerB->playerDebuff == "stunned") player2Debuff.setString(playerB->playerDebuff);
	else if (playerB->playerSecondDebuff == "stunned") player2Debuff.setString(playerB->playerSecondDebuff);
	else if (playerB->playerThirdDebuff == "stunned") player2Debuff.setString(playerB->playerThirdDebuff);


	//sets the position
	player1Debuff.setPosition(100, 400);
	player2Debuff.setPosition(1200, 400);

	//sets the size
	player1Debuff.setCharacterSize(100);
	player2Debuff.setCharacterSize(100);


	//draws out the texts

	renderWindow.draw(player1Debuff);
	renderWindow.draw(player2Debuff);








	//sets up a clickable response
	sf::FloatRect boundsp1s1 = _visibleObjectManager.SkillMenuPlayer1Skill1.getGlobalBounds();
	sf::FloatRect boundsp1s2 = _visibleObjectManager.SkillMenuPlayer1Skill2.getGlobalBounds();
	sf::FloatRect boundsp1s3 = _visibleObjectManager.SkillMenuPlayer1Skill3.getGlobalBounds();
	sf::FloatRect boundsp1s4 = _visibleObjectManager.SkillMenuPlayer1Skill4.getGlobalBounds();
	sf::FloatRect boundsp1s5 = _visibleObjectManager.SkillMenuPlayer1Skill5.getGlobalBounds();
	sf::FloatRect boundsp1s6 = _visibleObjectManager.SkillMenuPlayer1Skill6.getGlobalBounds();
	sf::FloatRect boundsp1s7 = _visibleObjectManager.SkillMenuPlayer1Skill7.getGlobalBounds();
	sf::FloatRect boundsp1s8 = _visibleObjectManager.SkillMenuPlayer1Skill8.getGlobalBounds();

	sf::FloatRect boundsp2s1 = _visibleObjectManager.SkillMenuPlayer2Skill1.getGlobalBounds();
	sf::FloatRect boundsp2s2 = _visibleObjectManager.SkillMenuPlayer2Skill2.getGlobalBounds();
	sf::FloatRect boundsp2s3 = _visibleObjectManager.SkillMenuPlayer2Skill3.getGlobalBounds();
	sf::FloatRect boundsp2s4 = _visibleObjectManager.SkillMenuPlayer2Skill4.getGlobalBounds();
	sf::FloatRect boundsp2s5 = _visibleObjectManager.SkillMenuPlayer2Skill5.getGlobalBounds();
	sf::FloatRect boundsp2s6 = _visibleObjectManager.SkillMenuPlayer2Skill6.getGlobalBounds();
	sf::FloatRect boundsp2s7 = _visibleObjectManager.SkillMenuPlayer2Skill7.getGlobalBounds();
	sf::FloatRect boundsp2s8 = _visibleObjectManager.SkillMenuPlayer2Skill8.getGlobalBounds();









	//shows the highlighted skill boxes when you hover over them

	if (boundsp1s1.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s2.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s3.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s4.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s5.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s6.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s7.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s8.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);





	//handles the change of sprite for skills on cooldown  for player 1
	if (playerA->playerMove1Used) _visibleObjectManager.SkillMenuPlayer1Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove2Used) _visibleObjectManager.SkillMenuPlayer1Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove3Used) _visibleObjectManager.SkillMenuPlayer1Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove4Used) _visibleObjectManager.SkillMenuPlayer1Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove5Used) _visibleObjectManager.SkillMenuPlayer1Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove6Used) _visibleObjectManager.SkillMenuPlayer1Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove7Used) _visibleObjectManager.SkillMenuPlayer1Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove8Used) _visibleObjectManager.SkillMenuPlayer1Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);




	//renders skill buttons to screen
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill1);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill2);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill3);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill4);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill5);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill6);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill7);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill8);








	//Lets you know the skill is hovered over for player 2
	if (boundsp2s1.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s2.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s3.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s4.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s5.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s6.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s7.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s8.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);



	//handles the change of sprite for skills on cooldown  for player 2
	if (playerB->playerMove1Used) _visibleObjectManager.SkillMenuPlayer2Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove2Used) _visibleObjectManager.SkillMenuPlayer2Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove3Used) _visibleObjectManager.SkillMenuPlayer2Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove4Used) _visibleObjectManager.SkillMenuPlayer2Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove5Used) _visibleObjectManager.SkillMenuPlayer2Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove6Used) _visibleObjectManager.SkillMenuPlayer2Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove7Used) _visibleObjectManager.SkillMenuPlayer2Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove8Used) _visibleObjectManager.SkillMenuPlayer2Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);




	//only show skills if player 2 has yet to pick one

	//draws the new potential sprites for player 2
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill1);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill2);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill3);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill4);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill5);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill6);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill7);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill8);



	//makes it so you don't wait when both players are stunned, eventually just change the time to 3 seconds of idle
	if (player1Disabled && player2Disabled)
	{
		playerA->playerPicked = true;
		playerB->playerPicked = true;
	}



	renderWindow.pollEvent(event);

	//checks to see if the event filled is the mouse being pressed
	/*if(sf::Joystick::isConnected(0))
	{
	cout << "connected" << endl;
	}*/

	//A button is 0
	//B button is 1
	//X button is 2
	//Y button is 3
	//Lb button is 4
	//Rb is button 5
	//Back is button 6
	//start is button 7
	//L3 is button 8
	//R3 is button 9


	if (sf::Joystick::isButtonPressed(0, 11))
	{
		cout << "9" << endl;
	}

	if (sf::Joystick::isConnected(0))
	{
		cout << sf::Joystick::getButtonCount(0) << endl;
	}


	if (!_multiplayer.multiplayer)
	{
		if (!player1Disabled && !_gameObjectManager.player1Picked)
		{
			if (playerA->name != "Meditate" && playerA->name != "Bone Crusher")
			{

				//fills the event



				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && playerA->playerPicked == false && playerA->playerMove1Used == false)
				{

					_audioManager.playButtonClick(1);
					playerA->ability1(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

					playerA->playerPicked = true;
					if (playerA->name == "Bone Crusher")
					{
						playerA->playerPicked = false;
						_visibleObjectManager.bufferClock.restart();
					}

				}


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && playerA->playerPicked == false && playerA->playerMove2Used == false)
				{
					_audioManager.playButtonClick(1);
					playerA->ability2(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

					playerA->playerPicked = true;

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && playerA->playerPicked == false && playerA->playerMove3Used == false)
				{
					_audioManager.playButtonClick(1);
					playerA->ability3(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

					playerA->playerPicked = true;

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && playerA->playerPicked == false && playerA->playerMove4Used == false)
				{
					_audioManager.playButtonClick(1);
					playerA->ability4(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

					playerA->playerPicked = true;

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && playerA->playerPicked == false && playerA->playerMove5Used == false)
				{
					_audioManager.playButtonClick(1);
					playerA->ability5(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

					playerA->playerPicked = true;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && playerA->playerPicked == false && playerA->playerMove6Used == false)
				{
					_audioManager.playButtonClick(1);
					playerA->ability6(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

					playerA->playerPicked = true;

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && playerA->playerPicked == false && playerA->playerMove7Used == false)
				{
					_audioManager.playButtonClick(1);
					playerA->ability7(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

					playerA->playerPicked = true;

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && playerA->playerPicked == false && playerA->playerMove8Used == false)
				{
					_audioManager.playButtonClick(1);
					playerA->ability8(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

					playerA->playerPicked = true;
					if (playerA->name == "Meditate")
					{
						playerA->playerPicked = false;
						_visibleObjectManager.bufferClock.restart();
					}
				}




			}


			//end of if statement for if(!player1Disabled)
		}




		//if(_multiplayer)
		if (!player2Disabled && !_gameObjectManager.player2Picked)
		{
			if (playerB->name != "Meditate"  && playerB->name != "Bone Crusher")
			{




				//checks to see if the event filled is the mouse being pressed
				if (event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::MouseButtonPressed)
				{

					if ((boundsp2s1.contains(mousePos)) && (playerB->playerMove1Used == false) && !playerB->playerPicked)
					{
						_audioManager.playButtonClick(1);
						playerB->ability1(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

						playerB->playerPicked = true;

						if (playerB->name == "Bone Crusher")
						{
							playerB->playerPicked = false;
							_visibleObjectManager.bufferClock.restart();
						}

					}


					if ((boundsp2s2.contains(mousePos)) && (playerB->playerMove2Used == false) && !playerB->playerPicked)
					{
						_audioManager.playButtonClick(1);
						playerB->ability2(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

						playerB->playerPicked = true;

					}

					if ((boundsp2s3.contains(mousePos)) && (playerB->playerMove3Used == false) && !playerB->playerPicked)
					{
						_audioManager.playButtonClick(1);
						playerB->ability3(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

						playerB->playerPicked = true;

					}
					if ((boundsp2s4.contains(mousePos)) && (playerB->playerMove4Used == false) && !playerB->playerPicked)
					{
						_audioManager.playButtonClick(1);
						playerB->ability4(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

						playerB->playerPicked = true;

					}
					if ((boundsp2s5.contains(mousePos)) && (playerB->playerMove5Used == false) && !playerB->playerPicked)
					{
						_audioManager.playButtonClick(1);
						playerB->ability5(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

						playerB->playerPicked = true;
					}
					if ((boundsp2s6.contains(mousePos)) && (playerB->playerMove6Used == false) && !playerB->playerPicked)
					{
						_audioManager.playButtonClick(1);
						playerB->ability6(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

						playerB->playerPicked = true;

					}
					if ((boundsp2s7.contains(mousePos)) && (playerB->playerMove7Used == false) && !playerB->playerPicked)
					{
						_audioManager.playButtonClick(1);
						playerB->ability7(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

						playerB->playerPicked = true;

					}
					if ((boundsp2s8.contains(mousePos)) && (playerB->playerMove8Used == false) && !playerB->playerPicked)
					{
						_audioManager.playButtonClick(1);
						playerB->ability8(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

						playerB->playerPicked = true;

						if (playerB->name == "Meditate")
						{
							playerB->playerPicked = false;
							_visibleObjectManager.bufferClock.restart();
						}
					}
				}

			}

			//end of if statement for if(!player2Disabled)
		}
	}
	else
	{
		if (_multiplayer.host)
		{

			if (!player1Disabled)
			{
				if (playerA->name != "Meditate" && playerA->name != "Bone Crusher")
				{

					//fills the event

					//checks to see if the event filled is the mouse being pressed
					if (event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::MouseButtonPressed)
					{

						if ((boundsp1s1.contains(mousePos)) && playerA->playerPicked == false && playerA->playerMove1Used == false)
						{

							_audioManager.playButtonClick(1);
							playerA->ability1(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerA->playerPicked = true;
							if (playerA->name == "Bone Crusher")
							{
								playerA->playerPicked = false;
								_visibleObjectManager.bufferClock.restart();
							}
							_multiplayer.send("1");
						}


						if ((boundsp1s2.contains(mousePos)) && playerA->playerPicked == false && playerA->playerMove2Used == false)
						{
							_audioManager.playButtonClick(1);
							playerA->ability2(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerA->playerPicked = true;
							_multiplayer.send("2");
						}

						if ((boundsp1s3.contains(mousePos)) && playerA->playerPicked == false && playerA->playerMove3Used == false)
						{
							_audioManager.playButtonClick(1);
							playerA->ability3(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerA->playerPicked = true;
							_multiplayer.send("3");

						}
						if ((boundsp1s4.contains(mousePos)) && playerA->playerPicked == false && playerA->playerMove4Used == false)
						{
							_audioManager.playButtonClick(1);
							playerA->ability4(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerA->playerPicked = true;
							_multiplayer.send("4");

						}
						if ((boundsp1s5.contains(mousePos)) && playerA->playerPicked == false && playerA->playerMove5Used == false)
						{
							_audioManager.playButtonClick(1);
							playerA->ability5(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerA->playerPicked = true;
							_multiplayer.send("5");
						}
						if ((boundsp1s6.contains(mousePos)) && playerA->playerPicked == false && playerA->playerMove6Used == false)
						{
							_audioManager.playButtonClick(1);
							playerA->ability6(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerA->playerPicked = true;
							_multiplayer.send("6");

						}
						if ((boundsp1s7.contains(mousePos)) && playerA->playerPicked == false && playerA->playerMove7Used == false)
						{
							_audioManager.playButtonClick(1);
							playerA->ability7(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerA->playerPicked = true;
							_multiplayer.send("7");

						}
						if ((boundsp1s8.contains(mousePos)) && playerA->playerPicked == false && playerA->playerMove8Used == false)
						{
							_audioManager.playButtonClick(1);
							playerA->ability8(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerA->playerPicked = true;
							if (playerA->name == "Meditate")
							{
								playerA->playerPicked = false;
								_visibleObjectManager.bufferClock.restart();
							}
							_multiplayer.send("8");
						}
					}
				}




				


				//end of if statement for if(!player1Disabled)
			}
		}
		//clients choice
		else
		{
			if (!player2Disabled)
			{
				if (playerB->name != "Meditate"  && playerB->name != "Bone Crusher")
				{




					//checks to see if the event filled is the mouse being pressed
					if (event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::MouseButtonPressed)
					{

						if ((boundsp2s1.contains(mousePos)) && (playerB->playerMove1Used == false) && !playerB->playerPicked)
						{
							_audioManager.playButtonClick(1);
							playerB->ability1(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerB->playerPicked = true;

							if (playerB->name == "Bone Crusher")
							{
								playerB->playerPicked = false;
								_visibleObjectManager.bufferClock.restart();
							}
							_multiplayer.send("1");
						}


						if ((boundsp2s2.contains(mousePos)) && (playerB->playerMove2Used == false) && !playerB->playerPicked)
						{
							_audioManager.playButtonClick(1);
							playerB->ability2(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerB->playerPicked = true;
							_multiplayer.send("2");
						}

						if ((boundsp2s3.contains(mousePos)) && (playerB->playerMove3Used == false) && !playerB->playerPicked)
						{
							_audioManager.playButtonClick(1);
							playerB->ability3(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerB->playerPicked = true;
							_multiplayer.send("3");
						}
						if ((boundsp2s4.contains(mousePos)) && (playerB->playerMove4Used == false) && !playerB->playerPicked)
						{
							_audioManager.playButtonClick(1);
							playerB->ability4(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerB->playerPicked = true;
							_multiplayer.send("4");
						}
						if ((boundsp2s5.contains(mousePos)) && (playerB->playerMove5Used == false) && !playerB->playerPicked)
						{
							_audioManager.playButtonClick(1);
							playerB->ability5(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerB->playerPicked = true;
							_multiplayer.send("5");
						}
						if ((boundsp2s6.contains(mousePos)) && (playerB->playerMove6Used == false) && !playerB->playerPicked)
						{
							_audioManager.playButtonClick(1);
							playerB->ability6(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerB->playerPicked = true;
							_multiplayer.send("6");

						}
						if ((boundsp2s7.contains(mousePos)) && (playerB->playerMove7Used == false) && !playerB->playerPicked)
						{
							_audioManager.playButtonClick(1);
							playerB->ability7(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerB->playerPicked = true;
							_multiplayer.send("7");

						}
						if ((boundsp2s8.contains(mousePos)) && (playerB->playerMove8Used == false) && !playerB->playerPicked)
						{
							_audioManager.playButtonClick(1);
							playerB->ability8(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

							playerB->playerPicked = true;

							if (playerB->name == "Meditate")
							{
								playerB->playerPicked = false;
								_visibleObjectManager.bufferClock.restart();
							}
							_multiplayer.send("8");
						}
					}

				}

				//end of if statement for if(!player2Disabled)
			}
		}
	}

	double bufferTime = (double)(_visibleObjectManager.bufferClock.getElapsedTime().asSeconds());



	if (playerA->name == "Meditate" && (bufferTime > 0.1)) meditateHandler(renderWindow, _visibleObjectManager, _gameObjectManager, _audioManager, event, _gameObjectManager.player1, _gameObjectManager.player2);
	if (playerB->name == "Meditate" && (bufferTime > 0.1)) meditateHandler(renderWindow, _visibleObjectManager, _gameObjectManager, _audioManager, event, _gameObjectManager.player1, _gameObjectManager.player2);

	if (playerA->name == "Bone Crusher" && (bufferTime > 0.1)) boneCrusherHandler(renderWindow, _visibleObjectManager, _gameObjectManager, _audioManager, event, _gameObjectManager.player1, _gameObjectManager.player2);
	if (playerB->name == "Bone Crusher" && (bufferTime > 0.1)) boneCrusherHandler(renderWindow, _visibleObjectManager, _gameObjectManager, _audioManager, event, _gameObjectManager.player1, _gameObjectManager.player2);
}

void Battle::forceSelectMove(VisibleObjectManager  & _visibleObjectManager, GameObjectManager & _gameObjectManager, AudioManager & _audioManager, Multiplayer & _multiplayer, Player * playerA, Player * playerB, string str)
{

	if(!_multiplayer.host)
	{
			if (str == "1")
			{
				playerA->ability1(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;
				if (playerA->name == "Bone Crusher")
				{
					playerA->playerPicked = false;
					_visibleObjectManager.bufferClock.restart();
				}

			}


			if (str == "2")
			{
				playerA->ability2(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;

			}

			if (str == "3")
			{
				playerA->ability3(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;

			}
			if (str == "4")
			{
				playerA->ability4(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;

			}
			if (str == "5")
			{
				playerA->ability5(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;
			}
			if (str == "6")
			{
				playerA->ability6(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;

			}
			if (str == "7")
			{
				playerA->ability7(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;

			}
			if (str == "8")
			{
				playerA->ability8(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;
				if (playerA->name == "Meditate")
				{
					playerA->playerPicked = false;
					_visibleObjectManager.bufferClock.restart();
				}
			}
		}

	else
	{
		//player2

		if (str == "1")
		{

			playerB->ability1(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

			playerB->playerPicked = true;

			if (playerB->name == "Bone Crusher")
			{
				playerB->playerPicked = false;
				_visibleObjectManager.bufferClock.restart();
			}

		}


		if (str == "2")
		{

			playerB->ability2(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

			playerB->playerPicked = true;

		}

		if (str == "3")
		{

			playerB->ability3(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

			playerB->playerPicked = true;

		}
		if (str == "4")
		{

			playerB->ability4(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

			playerB->playerPicked = true;

		}
		if (str == "5")
		{

			playerB->ability5(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

			playerB->playerPicked = true;
		}
		if (str == "6")
		{

			playerB->ability6(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

			playerB->playerPicked = true;

		}
		if (str == "7")
		{

			playerB->ability7(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

			playerB->playerPicked = true;

		}
		if (str == "8")
		{
			playerB->ability8(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);
			playerB->playerPicked = true;
			if (playerB->name == "Meditate")
			{
				playerB->playerPicked = false;
				_visibleObjectManager.bufferClock.restart();
			}
		}
	}
}



void Battle::showHpBars(sf::RenderWindow & renderWindow, VisibleObjectManager  & _visibleObjectManager, GameObjectManager & _gameObjectManager)
{
	//player 1 hp/mp
	_visibleObjectManager.player1HpBar.setTexture(_visibleObjectManager.playerHpBarTexture);
	_visibleObjectManager.player1HpBar.setPosition(-8, 30);
	renderWindow.draw(_visibleObjectManager.player1HpBar);


	//player 2 hp/mp
	_visibleObjectManager.player2HpBar.setTexture(_visibleObjectManager.playerHpBarTexture);
	_visibleObjectManager.player2HpBar.setPosition(1068, 30);
	renderWindow.draw(_visibleObjectManager.player2HpBar);

}


//loads and tracks the health bars (will be called every frame)
void Battle::trackHealth(sf::RenderWindow & renderWindow, VisibleObjectManager  & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB)
{



	if (_gameObjectManager.player1->idle == "necromancerIdle")
	{
		_visibleObjectManager.loadSoulBarPlayer1();
		renderWindow.draw(_visibleObjectManager.necroBarPlayer1);
		renderWindow.draw(_visibleObjectManager.necroBarBorderPlayer1);
	}

	if (_gameObjectManager.player2->idle == "necromancerIdle")
	{
		_visibleObjectManager.loadSoulBarPlayer2();
		renderWindow.draw(_visibleObjectManager.necroBarPlayer2);
		renderWindow.draw(_visibleObjectManager.necroBarBorderPlayer2);
	}

	_visibleObjectManager.hpBarInsidePlayer1.setTexture(_visibleObjectManager.hpBarInsideTexture);
	_visibleObjectManager.hpBarInsidePlayer2.setTexture(_visibleObjectManager.hpBarInsideTexture);

	double healthPercentPlayer1 = playerA->getHp() / playerA->getTotalHp();
	double soulPercentPlayer1 = (playerA->necroMeter / playerA->necroMeterMax);

	//player 1 hp
	_visibleObjectManager.hpBarInsidePlayer1.setScale((1 * healthPercentPlayer1), 1);
	_visibleObjectManager.hpBarInsidePlayer1.setPosition(35, 40);
	renderWindow.draw(_visibleObjectManager.hpBarInsidePlayer1);

	//player 1 soul guage
	_visibleObjectManager.necroBarPlayer1.setScale((1 * soulPercentPlayer1), 1);
	renderWindow.draw(_visibleObjectManager.necroBarPlayer1);

	double healthPercentPlayer2 = playerB->getHp() / playerB->getTotalHp();
	double soulPercentPlayer2 = playerB->necroMeter / playerB->necroMeterMax;

	//player 2 hp


	_visibleObjectManager.hpBarInsidePlayer2.setScale((1 * healthPercentPlayer2), 1);
	_visibleObjectManager.hpBarInsidePlayer2.setPosition(1110, 40);
	renderWindow.draw(_visibleObjectManager.hpBarInsidePlayer2);

	//player 1 soul guage
	_visibleObjectManager.necroBarPlayer2.setScale((1 * soulPercentPlayer2), 1);
	renderWindow.draw(_visibleObjectManager.necroBarPlayer2);


	//creates 2 texts containers
	sf::Text hpPlayer1;
	sf::Text hpPlayer2;

	//sets the font to the containers
	hpPlayer1.setFont(_visibleObjectManager.font);
	hpPlayer2.setFont(_visibleObjectManager.font);




	string hp1Display;
	stringstream convert1;
	convert1 << playerA->getHp() << " / " << playerA->getTotalHp();
	hp1Display = convert1.str();

	string hp2Display;
	stringstream convert2;
	convert2 << playerB->getHp() << " / " << playerB->getTotalHp();
	hp2Display = convert2.str();



	//sets the message to show
	hpPlayer1.setString(hp1Display);
	hpPlayer2.setString(hp2Display);


	// set the character size
	hpPlayer1.setCharacterSize(30); // in pixels, not points!
	hpPlayer2.setCharacterSize(30); // in pixels, not points!
									//// set the color
	hpPlayer1.setColor(sf::Color::White);
	hpPlayer2.setColor(sf::Color::White);

	//set position
	hpPlayer1.setPosition(200, 40);
	hpPlayer2.setPosition(1600, 40);

	//draws to screen
	renderWindow.draw(hpPlayer1);
	renderWindow.draw(hpPlayer2);

}



void Battle::fpsTest(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager)
{
	//fps test int
	static int fpsTest;
	int maxFPS;


	fpsTest++;
	maxFPS = fpsTest;

	int time = (int)_gameObjectManager.clock2.getElapsedTime().asSeconds();
	if (time >= 1)
	{
		cout << maxFPS << endl;
		_gameObjectManager.clock2.restart();
		fpsTest = 0;
	}
}



//keeps track of time and displays it on the screen
void Battle::setTimeBar(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager _gameObjectManager)
{
	//renders clock
	_visibleObjectManager.battleClock.setTexture(_visibleObjectManager.battleClockTexture);


	sf::Text clock;


	string clockTime;
	stringstream timeConvert;
	int convert = (int)(_gameObjectManager.battleClock.asSeconds() - _gameObjectManager.clock.getElapsedTime().asSeconds());
	timeConvert << convert;
	clockTime = timeConvert.str();



	//sets the font to the containers
	clock.setFont(_visibleObjectManager.font);

	clock.setCharacterSize(80);
	clock.setPosition(925, 40);
	clock.setColor(sf::Color::Black);

	clock.setString(clockTime);

	renderWindow.draw(_visibleObjectManager.battleClock);
	renderWindow.draw(clock);

}

//checks to see if any player has died
bool Battle::checkDeath(Player * playerA, Player * playerB)
{
	if (playerA->getHp() <= 0) return true;
	else if (playerB->getHp() <= 0) return true;
	else return false;
}

//resets clock every turn
void Battle::updateTime(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager)
{
	int timeLoop = (int)_gameObjectManager.clock.getElapsedTime().asSeconds();

	if (timeLoop > 90) _gameObjectManager.clock.restart(); //set the amount of time before clock resets
}

//handles the clock reseting every turn
void Battle::updateFrame(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager, VisibleObjectManager & _visualObjectManager)
{
	//player 1
	if (_gameObjectManager.char1 == "warrior")
	{
		_visualObjectManager.warriorIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		renderWindow.draw(_visualObjectManager.player1Character);
	}
	else if (_gameObjectManager.char1 == "assassin")
	{
		_visualObjectManager.assassinIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		renderWindow.draw(_visualObjectManager.player1Character);
	}
	else if (_gameObjectManager.char1 == "monk")
	{
		if (_gameObjectManager.player1->playerBuff == "Step in" || _gameObjectManager.player1->playerSecondBuff == "Step in" || _gameObjectManager.player1->playerThirdBuff == "Step in")
		{
			_visualObjectManager.monkStepinIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}

		//draws to screen
		renderWindow.draw(_visualObjectManager.player1Character);
	}
	else if (_gameObjectManager.char1 == "necromancer")
	{
		_visualObjectManager.necromancerIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		renderWindow.draw(_visualObjectManager.player1Character);
	}
	else if (_gameObjectManager.char1 == "demon")
	{
		_visualObjectManager.demonIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		renderWindow.draw(_visualObjectManager.player1Character);
	}


	//player2
	if (_gameObjectManager.char2 == "warrior")
	{
		_visualObjectManager.warriorIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		renderWindow.draw(_visualObjectManager.player2Character);
	}
	else if (_gameObjectManager.char2 == "assassin")
	{
		_visualObjectManager.assassinIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		renderWindow.draw(_visualObjectManager.player2Character);

	}
	else if (_gameObjectManager.char2 == "monk")
	{
		if (_gameObjectManager.player2->playerBuff == "Step in" || _gameObjectManager.player2->playerSecondBuff == "Step in" || _gameObjectManager.player2->playerThirdBuff == "Step in")
		{
			_visualObjectManager.monkStepinIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}

		//draws to screen
		renderWindow.draw(_visualObjectManager.player2Character);

	}
	else if (_gameObjectManager.char2 == "necromancer")
	{
		_visualObjectManager.necromancerIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		renderWindow.draw(_visualObjectManager.player2Character);

	}
	else if (_gameObjectManager.char2 == "demon")
	{
		_visualObjectManager.demonIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		renderWindow.draw(_visualObjectManager.player2Character);

	}
}


//animations and sound
void Battle::updateBattleFrame(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager, VisibleObjectManager &_visualObjectManager, AudioManager & _audioManager)
{
	if (_gameObjectManager.player1->currentAnimation == "warriorMove1")
	{
		//the sound will play exactly once at frame 38
		if (_visualObjectManager.player1CurrentAnimationFrame == 38)
		{
			_audioManager.playWarrior1(1);
		}

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}

		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.warriorMove1(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "warriorMove2")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}

		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.warriorMove2(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "warriorMove3")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}

		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.warriorMove3(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "warriorMove4")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}

		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.warriorMove4(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "warriorMove5")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}

		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.warriorMove5(_visualObjectManager.player1CurrentAnimationFrame, 1);
			renderWindow.draw(_visualObjectManager.powerStanceChargePlayer1);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "warriorMove6")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}

		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.warriorMove6(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "warriorMove7")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}

		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.warriorMove7(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	//taunt
	else if (_gameObjectManager.player1->currentAnimation == "warriorMove8")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}

		if (_gameObjectManager.player2->getAbility1() == "Stun Strike") _audioManager.taunt(1);
		else if (_gameObjectManager.player2->getAbility1() == "Smoke Bomb") _audioManager.taunt(2);


		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.warriorMove8(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "warriorHurt")
	{
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.warriorHurt(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}

	else if (_gameObjectManager.player1->currentAnimation == "assassinMove1")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.assassinMove1(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "assassinMove2")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.assassinMove2(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "assassinMove3")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.assassinMove3(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "assassinMove4")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.assassinMove4(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "assassinMove5")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.assassinMove5(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "assassinMove6")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.assassinMove6(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "assassinMove7")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.assassinMove7(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "assassinMove8")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.assassinMove8(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}

	if (_gameObjectManager.player1->currentAnimation == "monkMove1")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.monkMove1(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "monkMove2")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.monkMove2(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "monkMove3")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.monkMove3(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "monkMove4")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.monkMove4(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "monkMove5")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.monkMove5(_visualObjectManager.player1CurrentAnimationFrame, 1);
			renderWindow.draw(_visualObjectManager.powerStanceChargePlayer1);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "monkMove6")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.monkMove6(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "monkMove7")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.monkMove7(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "monkMove8")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.monkMove8(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "monkHurt")
	{
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.monkHurt(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}

	//necro player 1////
	if (_gameObjectManager.player1->currentAnimation == "necromancerMove1")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.necromancerMove1(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "necromancerMove2")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.necromancerMove2(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "necromancerMove3")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.necromancerMove3(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "necromancerMove4")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.necromancerMove4(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "necromancerMove5")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.necromancerMove5(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "necromancerMove6")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.necromancerMove6(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "necromancerMove7")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.necromancerMove7(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "necromancerMove8")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.necromancerMove8(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}

	if (_gameObjectManager.player1->currentAnimation == "demonMove1")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.demonMove1(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "demonMove2")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.demonMove2(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "demonMove3")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.demonMove3(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "demonMove4")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.demonMove4(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "demonMove5")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.demonMove5(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "demonMove6")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.demonMove6(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "demonMove7")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.demonMove7(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}
	else if (_gameObjectManager.player1->currentAnimation == "demonMove8")
	{

		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player1CurrentAnimationFrame == (_gameObjectManager.player1->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 1 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player2->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player1MoveFinished)
		{
			_visualObjectManager.demonMove8(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player1CurrentAnimationFrame, 1);
		}
	}







	//////player 2/////////
	if (_gameObjectManager.player2->currentAnimation == "warriorMove1")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.warriorMove1(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "warriorMove2")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.warriorMove2(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "warriorMove3")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.warriorMove3(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "warriorMove4")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.warriorMove4(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "warriorMove5")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.warriorMove5(_visualObjectManager.player2CurrentAnimationFrame, 2);
			renderWindow.draw(_visualObjectManager.powerStanceChargePlayer2);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "warriorMove6")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.warriorMove6(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "warriorMove7")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.warriorMove7(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "warriorMove8")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.warriorMove8(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "warriorHurt")
	{
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.warriorHurt(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.warriorIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}


	else if (_gameObjectManager.player2->currentAnimation == "assassinMove1")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.assassinMove1(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "assassinMove2")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.assassinMove2(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "assassinMove3")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.assassinMove3(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}

	else if (_gameObjectManager.player2->currentAnimation == "assassinMove4")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.assassinMove4(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}

	else if (_gameObjectManager.player2->currentAnimation == "assassinMove5")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.assassinMove5(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}

	else if (_gameObjectManager.player2->currentAnimation == "assassinMove6")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}

		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.assassinMove6(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "assassinMove7")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.assassinMove7(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "assassinMove8")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.assassinMove8(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.assassinIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}


	//monk player 2
	if (_gameObjectManager.player2->currentAnimation == "monkMove1")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.monkMove1(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "monkMove2")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.monkMove2(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "monkMove3")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.monkMove3(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "monkMove4")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.monkMove4(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "monkMove5")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.monkMove5(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "monkMove6")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.monkMove6(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "monkMove7")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.monkMove7(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "monkMove8")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.monkMove8(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "monkHurt")
	{
	//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.monkHurt(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.monkIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}


	//necro player 2////
	if (_gameObjectManager.player2->currentAnimation == "necromancerMove1")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.necromancerMove1(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "necromancerMove2")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.necromancerMove2(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "necromancerMove3")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.necromancerMove3(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "necromancerMove4")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.necromancerMove4(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "necromancerMove5")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.necromancerMove5(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "necromancerMove6")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.necromancerMove6(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "necromancerMove7")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.necromancerMove7(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "necromancerMove8")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.necromancerMove8(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.necromancerIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}


	//demon player 2
	if (_gameObjectManager.player2->currentAnimation == "demonMove1")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.demonMove1(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "demonMove2")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.demonMove2(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "demonMove3")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.demonMove3(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "demonMove4")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.demonMove4(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "demonMove5")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.demonMove5(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "demonMove6")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.demonMove6(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "demonMove7")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.demonMove7(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}
	else if (_gameObjectManager.player2->currentAnimation == "demonMove8")
	{
		//handles the other player getting hurt at the right time
		if (_visualObjectManager.player2CurrentAnimationFrame == (_gameObjectManager.player2->keyFrame - 1))
		{
			if (_gameObjectManager.playerAttackSuccessful == 2 || _gameObjectManager.playerAttackSuccessful == 3)
			{
				_gameObjectManager.player1->switchToHurt = true;
			}
		}
		//checks to see if animation of the move is finished, once it has it plays out the idle animation
		if (!_visualObjectManager.player2MoveFinished)
		{
			_visualObjectManager.demonMove8(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
		else
		{
			_visualObjectManager.demonIdle(_visualObjectManager.player2CurrentAnimationFrame, 2);
		}
	}


	if (_gameObjectManager.player1->switchToHurt)
	{
		_gameObjectManager.player1->switchToHurt = false;
		_gameObjectManager.player1->currentAnimation = _gameObjectManager.player1->hurtAnimationName;
		_visualObjectManager.player1CurrentAnimationFrame = 0;
	}
	if (_gameObjectManager.player2->switchToHurt)
	{
		_gameObjectManager.player2->switchToHurt = false;
		_gameObjectManager.player2->currentAnimation = _gameObjectManager.player2->hurtAnimationName;
		_visualObjectManager.player2CurrentAnimationFrame = 0;
	}

	//draws the result
	renderWindow.draw(_visualObjectManager.player1Character);
	renderWindow.draw(_visualObjectManager.player2Character);

}
//displays player ones skill boxes
void Battle::characterSkillsLeft(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, Player * &playerA, Player * &playerB, GameObjectManager & _gameObjectManager)
{



	// sets the strings to display
	_visibleObjectManager.move1NamePlayer1.setString(playerA->getAbility1());
	_visibleObjectManager.move2NamePlayer1.setString(playerA->getAbility2());
	_visibleObjectManager.move3NamePlayer1.setString(playerA->getAbility3());
	_visibleObjectManager.move4NamePlayer1.setString(playerA->getAbility4());
	_visibleObjectManager.move5NamePlayer1.setString(playerA->getAbility5());
	_visibleObjectManager.move6NamePlayer1.setString(playerA->getAbility6());
	_visibleObjectManager.move7NamePlayer1.setString(playerA->getAbility7());
	_visibleObjectManager.move8NamePlayer1.setString(playerA->getAbility8());








	//draws the skills onto the menuz
	renderWindow.draw(_visibleObjectManager.move1NamePlayer1);
	renderWindow.draw(_visibleObjectManager.move2NamePlayer1);
	renderWindow.draw(_visibleObjectManager.move3NamePlayer1);
	renderWindow.draw(_visibleObjectManager.move4NamePlayer1);
	renderWindow.draw(_visibleObjectManager.move5NamePlayer1);
	renderWindow.draw(_visibleObjectManager.move6NamePlayer1);
	renderWindow.draw(_visibleObjectManager.move7NamePlayer1);
	renderWindow.draw(_visibleObjectManager.move8NamePlayer1);




	//--------COOLDOWNS--------


	//streams inputs from int to string
	stringstream convert1;
	stringstream convert2;
	stringstream convert3;
	stringstream convert4;
	stringstream convert5;
	stringstream convert6;
	stringstream convert7;
	stringstream convert8;


	//fills up the stringstream
	convert1 << playerA->playerMove1CD;
	convert2 << playerA->playerMove2CD;
	convert3 << playerA->playerMove3CD;
	convert4 << playerA->playerMove4CD;
	convert5 << playerA->playerMove5CD;
	convert6 << playerA->playerMove6CD;
	convert7 << playerA->playerMove7CD;
	convert8 << playerA->playerMove8CD;

	//sets their string
	_visibleObjectManager.move1CoolDownPlayer1.setString(convert1.str());
	_visibleObjectManager.move2CoolDownPlayer1.setString(convert2.str());
	_visibleObjectManager.move3CoolDownPlayer1.setString(convert3.str());
	_visibleObjectManager.move4CoolDownPlayer1.setString(convert4.str());
	_visibleObjectManager.move5CoolDownPlayer1.setString(convert5.str());
	_visibleObjectManager.move6CoolDownPlayer1.setString(convert6.str());
	_visibleObjectManager.move7CoolDownPlayer1.setString(convert7.str());
	_visibleObjectManager.move8CoolDownPlayer1.setString(convert8.str());



	if (playerA->playerMeditateChoice == "empty")
	{
		//call for when to display them


		if (playerA->playerMove1Used) renderWindow.draw(_visibleObjectManager.move1CoolDownPlayer1);
		if (playerA->playerMove2Used) renderWindow.draw(_visibleObjectManager.move2CoolDownPlayer1);
		if (playerA->playerMove3Used) renderWindow.draw(_visibleObjectManager.move3CoolDownPlayer1);
		if (playerA->playerMove4Used) renderWindow.draw(_visibleObjectManager.move4CoolDownPlayer1);
		if (playerA->playerMove5Used) renderWindow.draw(_visibleObjectManager.move5CoolDownPlayer1);
		if (playerA->playerMove6Used) renderWindow.draw(_visibleObjectManager.move6CoolDownPlayer1);
		if (playerA->playerMove7Used) renderWindow.draw(_visibleObjectManager.move7CoolDownPlayer1);
		if (playerA->playerMove8Used) renderWindow.draw(_visibleObjectManager.move8CoolDownPlayer1);

	}





}

//displays player twos skill boxes
void Battle::characterSkillsRight(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, Player * &playerA, Player * &playerB, GameObjectManager & _gameObjectManager)
{



	// sets the strings to display
	_visibleObjectManager.move1NamePlayer2.setString(playerB->getAbility1());
	_visibleObjectManager.move2NamePlayer2.setString(playerB->getAbility2());
	_visibleObjectManager.move3NamePlayer2.setString(playerB->getAbility3());
	_visibleObjectManager.move4NamePlayer2.setString(playerB->getAbility4());
	_visibleObjectManager.move5NamePlayer2.setString(playerB->getAbility5());
	_visibleObjectManager.move6NamePlayer2.setString(playerB->getAbility6());
	_visibleObjectManager.move7NamePlayer2.setString(playerB->getAbility7());
	_visibleObjectManager.move8NamePlayer2.setString(playerB->getAbility8());







	//draws the skills onto the menuz
	renderWindow.draw(_visibleObjectManager.move1NamePlayer2);
	renderWindow.draw(_visibleObjectManager.move2NamePlayer2);
	renderWindow.draw(_visibleObjectManager.move3NamePlayer2);
	renderWindow.draw(_visibleObjectManager.move4NamePlayer2);
	renderWindow.draw(_visibleObjectManager.move5NamePlayer2);
	renderWindow.draw(_visibleObjectManager.move6NamePlayer2);
	renderWindow.draw(_visibleObjectManager.move7NamePlayer2);
	renderWindow.draw(_visibleObjectManager.move8NamePlayer2);





	//--------COOLDOWNS--------


	//streams inputs from int to string
	stringstream convert1;
	stringstream convert2;
	stringstream convert3;
	stringstream convert4;
	stringstream convert5;
	stringstream convert6;
	stringstream convert7;
	stringstream convert8;


	//fills up the stringstream
	convert1 << playerB->playerMove1CD;
	convert2 << playerB->playerMove2CD;
	convert3 << playerB->playerMove3CD;
	convert4 << playerB->playerMove4CD;
	convert5 << playerB->playerMove5CD;
	convert6 << playerB->playerMove6CD;
	convert7 << playerB->playerMove7CD;
	convert8 << playerB->playerMove8CD;

	//sets their string
	_visibleObjectManager.move1CoolDownPlayer2.setString(convert1.str());
	_visibleObjectManager.move2CoolDownPlayer2.setString(convert2.str());
	_visibleObjectManager.move3CoolDownPlayer2.setString(convert3.str());
	_visibleObjectManager.move4CoolDownPlayer2.setString(convert4.str());
	_visibleObjectManager.move5CoolDownPlayer2.setString(convert5.str());
	_visibleObjectManager.move6CoolDownPlayer2.setString(convert6.str());
	_visibleObjectManager.move7CoolDownPlayer2.setString(convert7.str());
	_visibleObjectManager.move8CoolDownPlayer2.setString(convert8.str());



	if (playerB->playerMeditateChoice == "empty" && playerB->playerBoneCrusherChoice == "")
	{
		//renders only if player hasnt picked

		//call for when to display them
		if (playerB->playerMove1Used) renderWindow.draw(_visibleObjectManager.move1CoolDownPlayer2);
		if (playerB->playerMove2Used) renderWindow.draw(_visibleObjectManager.move2CoolDownPlayer2);
		if (playerB->playerMove3Used) renderWindow.draw(_visibleObjectManager.move3CoolDownPlayer2);
		if (playerB->playerMove4Used) renderWindow.draw(_visibleObjectManager.move4CoolDownPlayer2);
		if (playerB->playerMove5Used) renderWindow.draw(_visibleObjectManager.move5CoolDownPlayer2);
		if (playerB->playerMove6Used) renderWindow.draw(_visibleObjectManager.move6CoolDownPlayer2);
		if (playerB->playerMove7Used) renderWindow.draw(_visibleObjectManager.move7CoolDownPlayer2);
		if (playerB->playerMove8Used) renderWindow.draw(_visibleObjectManager.move8CoolDownPlayer2);


	}

}



//handles the post match screen
void Battle::battleMenu(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager, sf::Event & event, int & value, Player * playerA, Player * playerB)
{
	if (_gameObjectManager.player1->getHp() <= 0)
	{
		_gameObjectManager.player1Dead = true;
		cout << "player 1 died" << endl;
	}
	if (_gameObjectManager.player2->getHp() <= 0)
	{
		_gameObjectManager.player2Dead = true;
		cout << "player 2 died" << endl;
	}
	sf::Vector2f windowSize(renderWindow.getView().getSize().x, renderWindow.getView().getSize().y);


	//rematch menu texture
	sf::Texture battleMenuTexture;
	battleMenuTexture.loadFromFile("images/rematch_menu.png");

	//loads up the button textures
	sf::Texture rematchButtonTexture;
	rematchButtonTexture.loadFromFile("images/rematch_button.png");

	sf::Texture chartacterSelectButtonTexture;
	chartacterSelectButtonTexture.loadFromFile("images/character_select_button.png");

	sf::Texture mainMenuButtonTexture;
	mainMenuButtonTexture.loadFromFile("images/main_menu_button.png");


	//loads up left sides unused skills
	sf::Sprite battleMenu;
	sf::Sprite rematchButton;
	sf::Sprite mainMenuButton;
	sf::Sprite chartacterSelectButton;


	battleMenu.scale(windowSize.x / battleMenu.getLocalBounds().width, windowSize.y / battleMenu.getLocalBounds().height);

	battleMenu.setTexture(battleMenuTexture);

	renderWindow.draw(battleMenu);


	rematchButton.setTexture(rematchButtonTexture);
	rematchButton.move(550, 360);
	renderWindow.draw(rematchButton);

	chartacterSelectButton.setTexture(chartacterSelectButtonTexture);
	chartacterSelectButton.move(550, 460);
	renderWindow.draw(chartacterSelectButton);

	mainMenuButton.setTexture(mainMenuButtonTexture);
	mainMenuButton.move(550, 560);
	renderWindow.draw(mainMenuButton);








	//creates a vector that holds the mouses position
	sf::Vector2f mousePos = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));

	//sets up a clickable response
	sf::FloatRect boundsRematchButton = rematchButton.getGlobalBounds();
	sf::FloatRect boundsCharacterSelectButton = chartacterSelectButton.getGlobalBounds();
	sf::FloatRect boundsMainMenuButton = mainMenuButton.getGlobalBounds();



	//checks to see if the event filled is the mouse being pressed


	if (event.type == sf::Event::MouseButtonPressed && sf::Event::MouseLeft)
	{

		if (boundsRematchButton.contains(mousePos))
		{
			playerA->setHp(playerA->getTotalHp());
			playerB->setHp(playerB->getTotalHp());
			value = 1;
		}
		else if (boundsCharacterSelectButton.contains(mousePos))
		{
			value = 2;
		}

		else if (boundsMainMenuButton.contains(mousePos))
		{
			value = 3;
		}
	}
	else value = 0;

}

//displays move during the attack phase
void Battle::displayMoves(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager, VisibleObjectManager & _visibleObjectManager, Player * playerA, Player * playerB)
{



	//creates 2 texts containers
	static sf::Text move1;
	static sf::Text move2;

	//sets the font to the containers
	move1.setFont(_visibleObjectManager.font);
	move2.setFont(_visibleObjectManager.font);


	//sets the message to show
	move1.setString(playerA->name);
	move2.setString(playerB->name);


	// set the character size
	move1.setCharacterSize(80); // in pixels, not points!
	move2.setCharacterSize(80); // in pixels, not points!

								//// set the color
	move1.setColor(sf::Color::White);
	move2.setColor(sf::Color::White);

	//set position
	move1.setPosition(200, 400);
	move2.setPosition(1200, 400);

	//sets the message to show
	move1.setString(playerA->name);
	move2.setString(playerB->name);


	//draws to screen
	renderWindow.draw(move1);
	renderWindow.draw(move2);

}


void Battle::displayHUD(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager)
{
	_visibleObjectManager.HUDBarPlayer1Buff.setTexture(_visibleObjectManager.HUDBarBuffExpandedTexture);

	renderWindow.draw(_visibleObjectManager.HUDBarPlayer1Buff);

	_visibleObjectManager.HUDBarPlayer1Debuff.setTexture(_visibleObjectManager.HUDBarDebuffExpandedTexture);

	renderWindow.draw(_visibleObjectManager.HUDBarPlayer1Debuff);

	_visibleObjectManager.HUDBarPlayer2Buff.setTexture(_visibleObjectManager.HUDBarBuffExpandedTexture);

	renderWindow.draw(_visibleObjectManager.HUDBarPlayer2Buff);

	_visibleObjectManager.HUDBarPlayer2Debuff.setTexture(_visibleObjectManager.HUDBarDebuffExpandedTexture);

	renderWindow.draw(_visibleObjectManager.HUDBarPlayer2Debuff);


}

//displays all the active statuses for both players
void Battle::displayActiveStatuses(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB)
{


	//creates 3 texts containers for player 1 buffs
	static sf::Text player1Buff1;
	static sf::Text player1Buff2;
	static sf::Text player1Buff3;

	//creates 3 texts containers for player 1 debuffs
	static sf::Text player1Debuff1;
	static sf::Text player1Debuff2;
	static sf::Text player1Debuff3;

	//creates 3 texts containers for player 2 buffs
	static sf::Text player2Buff1;
	static sf::Text player2Buff2;
	static sf::Text player2Buff3;

	//creates 3 texts containers for player 2 debuffs
	static sf::Text player2Debuff1;
	static sf::Text player2Debuff2;
	static sf::Text player2Debuff3;

	//sets the font to the containers
	player1Debuff1.setFont(_visibleObjectManager.font);
	player1Debuff2.setFont(_visibleObjectManager.font);
	player1Debuff3.setFont(_visibleObjectManager.font);


	//sets the font to the containers
	player1Buff1.setFont(_visibleObjectManager.font);
	player1Buff2.setFont(_visibleObjectManager.font);
	player1Buff3.setFont(_visibleObjectManager.font);


	//sets the font to the containers
	player2Debuff1.setFont(_visibleObjectManager.font);
	player2Debuff2.setFont(_visibleObjectManager.font);
	player2Debuff3.setFont(_visibleObjectManager.font);


	//sets the font to the containers
	player2Buff1.setFont(_visibleObjectManager.font);
	player2Buff2.setFont(_visibleObjectManager.font);
	player2Buff3.setFont(_visibleObjectManager.font);

	// set the character size
	player1Buff1.setCharacterSize(40); // in pixels, not points!
	player1Buff2.setCharacterSize(40); // in pixels, not points!
	player1Buff3.setCharacterSize(40); // in pixels, not points!

	player1Debuff1.setCharacterSize(40); // in pixels, not points!
	player1Debuff2.setCharacterSize(40); // in pixels, not points!
	player1Debuff3.setCharacterSize(40); // in pixels, not points!

	player2Buff1.setCharacterSize(40); // in pixels, not points!
	player2Buff2.setCharacterSize(40); // in pixels, not points!
	player2Buff3.setCharacterSize(40); // in pixels, not points!

	player2Debuff1.setCharacterSize(40); // in pixels, not points!
	player2Debuff2.setCharacterSize(40); // in pixels, not points!
	player2Debuff3.setCharacterSize(40); // in pixels, not points!

										 //sets the message to show
	player1Buff1.setString(playerA->playerBuff);
	player1Buff2.setString(playerA->playerSecondBuff);
	player1Buff3.setString(playerA->playerThirdBuff);

	//sets the message to show
	player1Debuff1.setString(playerA->playerDebuff);
	player1Debuff2.setString(playerA->playerSecondDebuff);
	player1Debuff3.setString(playerA->playerThirdDebuff);

	//sets the message to show
	player2Buff1.setString(playerB->playerBuff);
	player2Buff2.setString(playerB->playerSecondBuff);
	player2Buff3.setString(playerB->playerThirdBuff);

	//sets the message to show
	player2Debuff1.setString(playerB->playerDebuff);
	player2Debuff2.setString(playerB->playerSecondDebuff);
	player2Debuff3.setString(playerB->playerThirdDebuff);





	//// set the color
	player1Buff1.setColor(sf::Color::White);
	player1Buff2.setColor(sf::Color::White);
	player1Buff3.setColor(sf::Color::White);

	player1Debuff1.setColor(sf::Color::White);
	player1Debuff2.setColor(sf::Color::White);
	player1Debuff3.setColor(sf::Color::White);

	player2Buff1.setColor(sf::Color::White);
	player2Buff2.setColor(sf::Color::White);
	player2Buff3.setColor(sf::Color::White);

	player2Debuff1.setColor(sf::Color::White);
	player2Debuff2.setColor(sf::Color::White);
	player2Debuff3.setColor(sf::Color::White);

	//set position
	player1Buff1.setPosition(60, 150);
	player1Buff2.setPosition(60, 200);
	player1Buff3.setPosition(60, 250);

	//set position
	player1Debuff1.setPosition(60, 400);
	player1Debuff2.setPosition(60, 450);
	player1Debuff3.setPosition(60, 500);

	//set position
	player2Buff1.setPosition(1650, 150);
	player2Buff2.setPosition(1650, 200);
	player2Buff3.setPosition(1650, 250);

	//set position
	player2Debuff1.setPosition(1650, 400);
	player2Debuff2.setPosition(1650, 450);
	player2Debuff3.setPosition(1650, 500);


	renderWindow.draw(player1Buff1);
	renderWindow.draw(player1Buff2);
	renderWindow.draw(player1Buff3);

	renderWindow.draw(player1Debuff1);
	renderWindow.draw(player1Debuff2);
	renderWindow.draw(player1Debuff3);

	renderWindow.draw(player2Buff1);
	renderWindow.draw(player2Buff2);
	renderWindow.draw(player2Buff3);

	renderWindow.draw(player2Debuff1);
	renderWindow.draw(player2Debuff2);
	renderWindow.draw(player2Debuff3);

}


void Battle::displaySkillEffects(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB)
{
	if (playerA->playerBuff == "Bone wall" || playerA->playerSecondBuff == "Bone wall" || playerA->playerThirdBuff == "Bone wall")
	{
		_visibleObjectManager.boneWall.setTexture(_visibleObjectManager.boneWallTexture);
		renderWindow.draw(_visibleObjectManager.boneWall);
	}
	else if (playerB->playerBuff == "Bone wall" || playerB->playerSecondBuff == "Bone wall" || playerB->playerThirdBuff == "Bone wall")
	{
		_visibleObjectManager.boneWall.setTexture(_visibleObjectManager.boneWallTexture);
		renderWindow.draw(_visibleObjectManager.boneWall);
	}
}

//if player 1 or player 2 joystick is connected this will show the buttons sprites next to the skills
void Battle::displayJoystickButtons(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB)
{
	_visibleObjectManager.player1JoystickButtons.setTexture(_visibleObjectManager.joystickButtonTexture);
	_visibleObjectManager.player2JoystickButtons.setTexture(_visibleObjectManager.joystickButtonTexture);

	//player 1 buttons
	if (sf::Joystick::isConnected(0))
	{
		renderWindow.draw(_visibleObjectManager.player1JoystickButtons);
	}

	//player 2 buttons
	if (sf::Joystick::isConnected(1))
	{
		renderWindow.draw(_visibleObjectManager.player2JoystickButtons);
	}

}


void Battle::joystickInputController(sf::RenderWindow & renderWindow, VisibleObjectManager  & _visibleObjectManager, GameObjectManager & _gameObjectManager, AudioManager & _audioManager, sf::Event & event, Player * playerA, Player * playerB)
{

	//sets the intial textures
	_visibleObjectManager.ManaBar1Player1.setTexture(_visibleObjectManager.ManaBarTexture);
	_visibleObjectManager.ManaBar2Player1.setTexture(_visibleObjectManager.ManaBarTexture);
	_visibleObjectManager.ManaBar1Player2.setTexture(_visibleObjectManager.ManaBarTexture);
	_visibleObjectManager.ManaBar2Player2.setTexture(_visibleObjectManager.ManaBarTexture);

	//creates a vector that holds the mouses position
	sf::Vector2f mousePos = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));

	//sets up a clickable response
	sf::FloatRect p1m1position = _visibleObjectManager.ManaBar1Player1.getGlobalBounds();
	sf::FloatRect p1m2position = _visibleObjectManager.ManaBar2Player1.getGlobalBounds();
	sf::FloatRect p2m1position = _visibleObjectManager.ManaBar1Player2.getGlobalBounds();
	sf::FloatRect p2m2position = _visibleObjectManager.ManaBar2Player2.getGlobalBounds();


	//checks to see if the event filled is the mouse being pressed
	if (event.type == sf::Event::MouseButtonPressed && sf::Event::MouseLeft)
	{
		if (p1m1position.contains(mousePos) && (_gameObjectManager.player1Mana1 == true))
		{

			playerA->playerEnhancedMove = true;
			playerA->playerEnhanceUses--;
			_gameObjectManager.player1Mana1 = false;

		}
		else if (p1m2position.contains(mousePos) && (_gameObjectManager.player1Mana2 == true))
		{

			playerA->playerEnhancedMove = true;
			playerA->playerEnhanceUses--;
			_gameObjectManager.player1Mana2 = false;
		}

		else if (p2m1position.contains(mousePos) && (_gameObjectManager.player2Mana1 == true))
		{

			playerB->playerEnhancedMove = true;
			playerB->playerEnhanceUses--;
			_gameObjectManager.player2Mana1 = false;
		}
		else if (p2m2position.contains(mousePos) && (_gameObjectManager.player2Mana2 == true))
		{

			playerB->playerEnhancedMove = true;
			playerB->playerEnhanceUses--;
			_gameObjectManager.player2Mana2 = false;

		}
	}







	//booleans that check if the player is unable to attack this turn
	bool player1Disabled = false;
	bool player2Disabled = false;

	if (playerA->playerDebuff == "stunned" || playerA->playerSecondDebuff == "stunned" ||
		playerA->playerThirdDebuff == "stunned") player1Disabled = true;
	else player1Disabled = false;
	if (playerB->playerDebuff == "stunned" || playerB->playerSecondDebuff == "stunned" ||
		playerB->playerThirdDebuff == "stunned") player2Disabled = true;
	else player2Disabled = false;



	//creates 2 texts containers for a debuff
	sf::Text player1Debuff;
	sf::Text player2Debuff;

	//sets their font
	player1Debuff.setFont(_visibleObjectManager.font);
	player2Debuff.setFont(_visibleObjectManager.font);


	// sets the strings to display under a condition


	if (playerA->playerDebuff == "stunned") player1Debuff.setString(playerA->playerDebuff);
	else if (playerA->playerSecondDebuff == "stunned") player1Debuff.setString(playerA->playerSecondDebuff);
	else if (playerA->playerThirdDebuff == "stunned") player1Debuff.setString(playerA->playerThirdDebuff);

	if (playerB->playerDebuff == "stunned") player2Debuff.setString(playerB->playerDebuff);
	else if (playerB->playerSecondDebuff == "stunned") player2Debuff.setString(playerB->playerSecondDebuff);
	else if (playerB->playerThirdDebuff == "stunned") player2Debuff.setString(playerB->playerThirdDebuff);


	//sets the position
	player1Debuff.setPosition(100, 400);
	player2Debuff.setPosition(1200, 400);

	//sets the size
	player1Debuff.setCharacterSize(100);
	player2Debuff.setCharacterSize(100);


	//draws out the texts

	renderWindow.draw(player1Debuff);
	renderWindow.draw(player2Debuff);








	//sets up a clickable response
	sf::FloatRect boundsp1s1 = _visibleObjectManager.SkillMenuPlayer1Skill1.getGlobalBounds();
	sf::FloatRect boundsp1s2 = _visibleObjectManager.SkillMenuPlayer1Skill2.getGlobalBounds();
	sf::FloatRect boundsp1s3 = _visibleObjectManager.SkillMenuPlayer1Skill3.getGlobalBounds();
	sf::FloatRect boundsp1s4 = _visibleObjectManager.SkillMenuPlayer1Skill4.getGlobalBounds();
	sf::FloatRect boundsp1s5 = _visibleObjectManager.SkillMenuPlayer1Skill5.getGlobalBounds();
	sf::FloatRect boundsp1s6 = _visibleObjectManager.SkillMenuPlayer1Skill6.getGlobalBounds();
	sf::FloatRect boundsp1s7 = _visibleObjectManager.SkillMenuPlayer1Skill7.getGlobalBounds();
	sf::FloatRect boundsp1s8 = _visibleObjectManager.SkillMenuPlayer1Skill8.getGlobalBounds();

	sf::FloatRect boundsp2s1 = _visibleObjectManager.SkillMenuPlayer2Skill1.getGlobalBounds();
	sf::FloatRect boundsp2s2 = _visibleObjectManager.SkillMenuPlayer2Skill2.getGlobalBounds();
	sf::FloatRect boundsp2s3 = _visibleObjectManager.SkillMenuPlayer2Skill3.getGlobalBounds();
	sf::FloatRect boundsp2s4 = _visibleObjectManager.SkillMenuPlayer2Skill4.getGlobalBounds();
	sf::FloatRect boundsp2s5 = _visibleObjectManager.SkillMenuPlayer2Skill5.getGlobalBounds();
	sf::FloatRect boundsp2s6 = _visibleObjectManager.SkillMenuPlayer2Skill6.getGlobalBounds();
	sf::FloatRect boundsp2s7 = _visibleObjectManager.SkillMenuPlayer2Skill7.getGlobalBounds();
	sf::FloatRect boundsp2s8 = _visibleObjectManager.SkillMenuPlayer2Skill8.getGlobalBounds();








	if (boundsp1s1.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s2.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s3.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s4.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s5.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s6.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s7.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp1s8.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer1Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer1Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);





	//handles the change of sprite for skills on cooldown  for player 1
	if (playerA->playerMove1Used) _visibleObjectManager.SkillMenuPlayer1Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove2Used) _visibleObjectManager.SkillMenuPlayer1Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove3Used) _visibleObjectManager.SkillMenuPlayer1Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove4Used) _visibleObjectManager.SkillMenuPlayer1Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove5Used) _visibleObjectManager.SkillMenuPlayer1Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove6Used) _visibleObjectManager.SkillMenuPlayer1Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove7Used) _visibleObjectManager.SkillMenuPlayer1Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerA->playerMove8Used) _visibleObjectManager.SkillMenuPlayer1Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);




	//renders skill buttons to screen
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill1);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill2);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill3);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill4);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill5);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill6);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill7);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer1Skill8);








	//Lets you know the skill is hovered over for player 2
	if (boundsp2s1.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s2.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s3.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s4.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s5.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s6.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s7.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);

	if (boundsp2s8.contains(mousePos))
	{
		_visibleObjectManager.SkillMenuPlayer2Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillSelectedTexture);
	}
	else _visibleObjectManager.SkillMenuPlayer2Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillTexture);



	//handles the change of sprite for skills on cooldown  for player 2
	if (playerB->playerMove1Used) _visibleObjectManager.SkillMenuPlayer2Skill1.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove2Used) _visibleObjectManager.SkillMenuPlayer2Skill2.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove3Used) _visibleObjectManager.SkillMenuPlayer2Skill3.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove4Used) _visibleObjectManager.SkillMenuPlayer2Skill4.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove5Used) _visibleObjectManager.SkillMenuPlayer2Skill5.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove6Used) _visibleObjectManager.SkillMenuPlayer2Skill6.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove7Used) _visibleObjectManager.SkillMenuPlayer2Skill7.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);
	if (playerB->playerMove8Used) _visibleObjectManager.SkillMenuPlayer2Skill8.setTexture(_visibleObjectManager.SkillMenuPlayerSkillUsedTexture);




	//only show skills if player 2 has yet to pick one

	//draws the new potential sprites for player 2
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill1);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill2);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill3);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill4);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill5);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill6);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill7);
	renderWindow.draw(_visibleObjectManager.SkillMenuPlayer2Skill8);



	//makes it so you don't wait when both players are stunned, eventually just change the time to 3 seconds of idle
	if (player1Disabled && player2Disabled)
	{
		playerA->playerPicked = true;
		playerB->playerPicked = true;
	}



	renderWindow.pollEvent(event);

	//checks to see if the event filled is the mouse being pressed
	/*if(sf::Joystick::isConnected(0))
	{
	cout << "connected" << endl;
	}*/

	//A button is 0
	//B button is 1
	//X button is 2
	//Y button is 3
	//Lb button is 4
	//Rb is button 5
	//Back is button 6
	//start is button 7
	//L3 is button 8
	//R3 is button 9


	/*
	I want
	X to be 1
	A to be 2
	Y to be 3
	B to be 4
	Lb to be 5
	Rb to be 6
	LT to be 7
	Rt to be 8
	...
	*/

	bool leftTriggerPlayer1 = false;
	bool rightTriggerPlayer1 = false;
	bool leftTriggerPlayer2 = false;
	bool rightTriggerPlayer2 = false;

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) > 5) leftTriggerPlayer1 = true;
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -5) rightTriggerPlayer1 = true;
	if (sf::Joystick::getAxisPosition(1, sf::Joystick::Z) > 5) leftTriggerPlayer2 = true;
	if (sf::Joystick::getAxisPosition(1, sf::Joystick::Z) < -5) rightTriggerPlayer2 = true;


	if (!player1Disabled)
	{
		if (playerA->name != "Meditate" && playerA->name != "Bone Crusher")
		{

			//fills the event



			if (sf::Joystick::isButtonPressed(0, 0) && playerA->playerPicked == false && playerA->playerMove1Used == false)
			{

				_audioManager.playButtonClick(1);
				playerA->ability1(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;
				if (playerA->name == "Bone Crusher")
				{
					playerA->playerPicked = false;
					_visibleObjectManager.bufferClock.restart();
				}

			}


			if (sf::Joystick::isButtonPressed(0, 1) && playerA->playerPicked == false && playerA->playerMove2Used == false)
			{
				_audioManager.playButtonClick(1);
				playerA->ability2(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;

			}

			if (sf::Joystick::isButtonPressed(0, 3) && playerA->playerPicked == false && playerA->playerMove3Used == false)
			{
				_audioManager.playButtonClick(1);
				playerA->ability3(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;

			}
			if (sf::Joystick::isButtonPressed(0, 2) && playerA->playerPicked == false && playerA->playerMove4Used == false)
			{
				_audioManager.playButtonClick(1);
				playerA->ability4(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;

			}
			if (sf::Joystick::isButtonPressed(0, 4) && playerA->playerPicked == false && playerA->playerMove5Used == false)
			{
				_audioManager.playButtonClick(1);
				playerA->ability5(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;
			}
			if (sf::Joystick::isButtonPressed(0, 5) && playerA->playerPicked == false && playerA->playerMove6Used == false)
			{
				_audioManager.playButtonClick(1);
				playerA->ability6(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;

			}
			if (leftTriggerPlayer1 && playerA->playerPicked == false && playerA->playerMove7Used == false)
			{
				_audioManager.playButtonClick(1);
				playerA->ability7(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerA->playerPicked = true;

			}
			if (rightTriggerPlayer1 && playerA->playerPicked == false && playerA->playerMove8Used == false)
			{
				playerA->ability8(playerA->playerEnhancedMove, _audioManager, _visibleObjectManager);
				if (playerA->name != "Meditate")
				{
					_audioManager.playButtonClick(1);
					playerA->playerPicked = true;

				}
				else
				{
					playerA->playerPicked = false;
					_visibleObjectManager.bufferClock.restart();
				}
			}




		}


		//end of if statement for if(!player1Disabled)
	}





	if (!player2Disabled)
	{
		if (playerB->name != "Meditate"  && playerB->name != "Bone Crusher")
		{

			if (sf::Joystick::isButtonPressed(1, 0) && (playerB->playerMove1Used == false) && !playerB->playerPicked)
			{
				_audioManager.playButtonClick(1);
				playerB->ability1(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerB->playerPicked = true;

				if (playerB->name == "Bone Crusher")
				{
					playerB->playerPicked = false;
					_visibleObjectManager.bufferClock.restart();
				}

			}


			if (sf::Joystick::isButtonPressed(1, 1) && (playerB->playerMove2Used == false) && !playerB->playerPicked)
			{
				_audioManager.playButtonClick(1);
				playerB->ability2(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerB->playerPicked = true;

			}

			if (sf::Joystick::isButtonPressed(1, 3) && (playerB->playerMove3Used == false) && !playerB->playerPicked)
			{
				_audioManager.playButtonClick(1);
				playerB->ability3(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerB->playerPicked = true;

			}
			if (sf::Joystick::isButtonPressed(1, 2) && (playerB->playerMove4Used == false) && !playerB->playerPicked)
			{
				_audioManager.playButtonClick(1);
				playerB->ability4(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerB->playerPicked = true;

			}
			if (sf::Joystick::isButtonPressed(1, 4) && (playerB->playerMove5Used == false) && !playerB->playerPicked)
			{
				_audioManager.playButtonClick(1);
				playerB->ability5(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerB->playerPicked = true;
			}
			if (sf::Joystick::isButtonPressed(1, 5) && (playerB->playerMove6Used == false) && !playerB->playerPicked)
			{
				_audioManager.playButtonClick(1);
				playerB->ability6(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerB->playerPicked = true;

			}
			if (leftTriggerPlayer2 && (playerB->playerMove7Used == false) && !playerB->playerPicked)
			{
				_audioManager.playButtonClick(1);
				playerB->ability7(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);

				playerB->playerPicked = true;

			}
			if (rightTriggerPlayer2 && (playerB->playerMove8Used == false) && !playerB->playerPicked)
			{

				playerB->ability8(playerB->playerEnhancedMove, _audioManager, _visibleObjectManager);
				if (playerB->name != "Meditate")
				{
					_audioManager.playButtonClick(1);
					playerB->playerPicked = true;

				}
				else
				{
					playerB->playerPicked = false;
					_visibleObjectManager.bufferClock.restart();
				}
			}


		}

		//end of if statement for if(!player2Disabled)
	}

	double bufferTime = (double)(_visibleObjectManager.bufferClock.getElapsedTime().asSeconds());



	if (playerA->name == "Meditate" && (bufferTime > 0.2)) meditateHandler(renderWindow, _visibleObjectManager, _gameObjectManager, _audioManager, event, _gameObjectManager.player1, _gameObjectManager.player2);
	if (playerB->name == "Meditate" && (bufferTime > 0.2)) meditateHandler(renderWindow, _visibleObjectManager, _gameObjectManager, _audioManager, event, _gameObjectManager.player1, _gameObjectManager.player2);

	if (playerA->name == "Bone Crusher" && (bufferTime > 0.2)) boneCrusherHandler(renderWindow, _visibleObjectManager, _gameObjectManager, _audioManager, event, _gameObjectManager.player1, _gameObjectManager.player2);
	if (playerB->name == "Bone Crusher" && (bufferTime > 0.2)) boneCrusherHandler(renderWindow, _visibleObjectManager, _gameObjectManager, _audioManager, event, _gameObjectManager.player1, _gameObjectManager.player2);

}



//resets the skill choice every round, and handles what skills are on cooldown and cant be used
void Battle::moveUpdate(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB)
{

	//puts the moves used on cooldown for player 1
	if (playerA->moveNumberUsed == 1)
	{
		playerA->playerMove1Used = true;
		playerA->playerMove1CD = playerA->moveNumberCD;
	}
	if (playerA->moveNumberUsed == 2)
	{
		playerA->playerMove2Used = true;
		playerA->playerMove2CD = playerA->moveNumberCD;
	}
	if (playerA->moveNumberUsed == 3)
	{
		playerA->playerMove3Used = true;
		playerA->playerMove3CD = playerA->moveNumberCD;
	}
	if (playerA->moveNumberUsed == 4)
	{
		playerA->playerMove4Used = true;
		playerA->playerMove4CD = playerA->moveNumberCD;
	}
	if (playerA->moveNumberUsed == 5)
	{
		playerA->playerMove5Used = true;
		playerA->playerMove5CD = playerA->moveNumberCD;
	}
	if (playerA->moveNumberUsed == 6)
	{
		playerA->playerMove6Used = true;
		playerA->playerMove6CD = playerA->moveNumberCD;
	}
	if (playerA->moveNumberUsed == 7)
	{
		playerA->playerMove7Used = true;
		playerA->playerMove7CD = playerA->moveNumberCD;
	}
	if (playerA->moveNumberUsed == 8)
	{
		playerA->playerMove8Used = true;
		playerA->playerMove8CD = playerA->moveNumberCD;
	}


	//puts the moves used on cooldown for player 2
	if (playerB->moveNumberUsed == 1)
	{
		playerB->playerMove1Used = true;
		playerB->playerMove1CD = playerB->moveNumberCD;
	}
	if (playerB->moveNumberUsed == 2)
	{
		playerB->playerMove2Used = true;
		playerB->playerMove2CD = playerB->moveNumberCD;
	}
	if (playerB->moveNumberUsed == 3)
	{
		playerB->playerMove3Used = true;
		playerB->playerMove3CD = playerB->moveNumberCD;
	}
	if (playerB->moveNumberUsed == 4)
	{
		playerB->playerMove4Used = true;
		playerB->playerMove4CD = playerB->moveNumberCD;
	}
	if (playerB->moveNumberUsed == 5)
	{
		playerB->playerMove5Used = true;
		playerB->playerMove5CD = playerB->moveNumberCD;
	}
	if (playerB->moveNumberUsed == 6)
	{
		playerB->playerMove6Used = true;
		playerB->playerMove6CD = playerB->moveNumberCD;
	}
	if (playerB->moveNumberUsed == 7)
	{
		playerB->playerMove7Used = true;
		playerB->playerMove7CD = playerB->moveNumberCD;
	}
	if (playerB->moveNumberUsed == 8)
	{
		playerB->playerMove8Used = true;
		playerB->playerMove8CD = playerB->moveNumberCD;
	}

	playerA->playerPicked = false;
	playerB->playerPicked = false;

	playerA->resetSkillChoice();
	playerB->resetSkillChoice();
}


//handles all active buffs for a player
void Battle::playerActiveBuffs(Player * playerA)
{
	//makes sure the buff isn't applied anywhere
	if ((playerA->buff != playerA->playerBuff) && (playerA->buff != playerA->playerSecondBuff) && (playerA->buff != playerA->playerThirdBuff))
	{
		if ((playerA->playerBuff == "") && (playerA->playerBuff != playerA->buff))
		{
			playerA->playerBuff = playerA->buff;
			playerA->playerBuff1Duration = playerA->buffTurns;
		}
		//if 0,
		else if ((playerA->playerBuff != "") && (playerA->playerSecondBuff == "")
			&& (playerA->playerSecondBuff != playerA->buff) && (playerA->playerBuff != playerA->buff))
		{
			playerA->playerSecondBuff = playerA->buff;
			playerA->playerBuff2Duration = playerA->buffTurns;
		}
		else if ((playerA->playerBuff != "") && (playerA->playerSecondBuff != "" &&
			playerA->playerThirdBuff == "") && (playerA->playerBuff != playerA->buff)
			&& (playerA->playerSecondBuff != playerA->buff) && (playerA->playerThirdBuff != playerA->buff))
		{
			playerA->playerThirdBuff = playerA->buff;
			playerA->playerBuff3Duration = playerA->buffTurns;
		}
	}
}




//handles all active debuffs for player
void Battle::playerActiveDebuffs(Player * playerA, Player * playerB)
{
	if ((playerA->playerDebuff == "") && (playerA->playerDebuff != playerB->appliedDebuff) &&
		(playerA->playerSecondDebuff != playerB->appliedDebuff) &&
		(playerA->playerThirdDebuff != playerB->appliedDebuff))
	{
		playerA->playerDebuff = playerB->appliedDebuff;
		playerA->playerDebuff1Duration = playerB->debuffTurns;
	}
	else if ((playerA->playerDebuff != "") && (playerA->playerSecondDebuff == "")
		&& (playerA->playerDebuff != playerB->appliedDebuff) &&
		(playerA->playerSecondDebuff != playerB->appliedDebuff) &&
		(playerA->playerThirdDebuff != playerB->appliedDebuff))
	{
		playerA->playerSecondDebuff = playerB->appliedDebuff;
		playerA->playerDebuff2Duration = playerB->debuffTurns;
	}
	else if ((playerA->playerDebuff != "") && (playerA->playerSecondDebuff != "" &&
		playerA->playerThirdDebuff == "") && (playerA->playerDebuff != playerB->appliedDebuff) &&
		(playerA->playerSecondDebuff != playerB->appliedDebuff) &&
		(playerA->playerThirdDebuff != playerB->appliedDebuff))
	{
		playerA->playerDebuff3Duration = playerB->debuffTurns;
		playerA->playerThirdDebuff = playerB->appliedDebuff;
	}

}





//displays player 1s skill times
void Battle::playerOneSkillTimes(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerA)
{

	sf::Text time1;
	sf::Text time2;
	sf::Text time3;
	sf::Text time4;
	sf::Text time5;
	sf::Text time6;
	sf::Text time7;
	sf::Text time8;

	double moveTime1 = playerA->getAbilityTime1();
	double moveTime2 = playerA->getAbilityTime2();
	double moveTime3 = playerA->getAbilityTime3();
	double moveTime4 = playerA->getAbilityTime4();
	double moveTime5 = playerA->getAbilityTime5();
	double moveTime6 = playerA->getAbilityTime6();
	double moveTime7 = playerA->getAbilityTime7();
	double moveTime8 = playerA->getAbilityTime8();

	//accounts for all changes to the numbers via buffs debuffs

	if (playerA->playerBuff == "Power Stance" || playerA->playerSecondBuff == "Power Stance" || playerA->playerThirdBuff == "Power Stance")
	{
		moveTime1 += .5;
		moveTime2 += .5;
		moveTime3 += .5;
		moveTime4 += .5;
		moveTime5 += .5;
		moveTime6 += .5;
		moveTime7 += .5;
		moveTime8 += .5;
	}
	if (playerA->playerBuff == "Step in" || playerA->playerSecondBuff == "Step in" || playerA->playerThirdBuff == "Step in")
	{
		moveTime1 -= .5;
		moveTime2 -= .5;
		moveTime3 -= .5;
		moveTime4 -= .5;
		moveTime5 -= .5;
		moveTime6 -= .5;
		moveTime7 -= .5;
		moveTime8 -= .5;
	}

	if (playerA->playerDebuff == "Knocked Down" || playerA->playerSecondDebuff == "Knocked Down" || playerA->playerThirdDebuff == "Knocked Down")
	{
		moveTime1 += 1;
		moveTime2 += 1;
		moveTime3 += 1;
		moveTime4 += 1;
		moveTime5 += 1;
		moveTime6 += 1;
		moveTime7 += 1;
		moveTime8 += 1;
	}

	if (playerA->playerDebuff == "Disarmed" || playerA->playerSecondDebuff == "Disarmed" || playerA->playerThirdDebuff == "Disarmed")
	{
		moveTime1 += .5;
		moveTime2 += .5;
		moveTime3 += .5;
		moveTime4 += .5;
		moveTime5 += .5;
		moveTime6 += .5;
		moveTime7 += .5;
		moveTime8 += .5;
	}


	if (playerA->playerDebuff == "Pushed" || playerA->playerSecondDebuff == "Pushed" || playerA->playerThirdDebuff == "Pushed")
	{
		moveTime1 += .3;
		moveTime2 += .3;
		moveTime3 += .3;
		moveTime4 += .3;
		moveTime5 += .3;
		moveTime6 += .3;
		moveTime7 += .3;
		moveTime8 += .3;
	}













	//////////////////////////////////////////////////////////////

	stringstream timeConvert1;
	stringstream timeConvert2;
	stringstream timeConvert3;
	stringstream timeConvert4;
	stringstream timeConvert5;
	stringstream timeConvert6;
	stringstream timeConvert7;
	stringstream timeConvert8;

	timeConvert1 << moveTime1;
	timeConvert2 << moveTime2;
	timeConvert3 << moveTime3;
	timeConvert4 << moveTime4;
	timeConvert5 << moveTime5;
	timeConvert6 << moveTime6;
	timeConvert7 << moveTime7;
	timeConvert8 << moveTime8;


	time1.setString(timeConvert1.str());
	time2.setString(timeConvert2.str());
	time3.setString(timeConvert3.str());
	time4.setString(timeConvert4.str());
	time5.setString(timeConvert5.str());
	time6.setString(timeConvert6.str());
	time7.setString(timeConvert7.str());
	time8.setString(timeConvert8.str());





	//sets the font to the containers
	time1.setFont(_visibleObjectManager.font);
	time2.setFont(_visibleObjectManager.font);
	time3.setFont(_visibleObjectManager.font);
	time4.setFont(_visibleObjectManager.font);
	time5.setFont(_visibleObjectManager.font);
	time6.setFont(_visibleObjectManager.font);
	time7.setFont(_visibleObjectManager.font);
	time8.setFont(_visibleObjectManager.font);


	time1.setCharacterSize(20);
	time2.setCharacterSize(20);
	time3.setCharacterSize(20);
	time4.setCharacterSize(20);
	time5.setCharacterSize(20);
	time6.setCharacterSize(20);
	time7.setCharacterSize(20);
	time8.setCharacterSize(20);

	time1.setPosition(700, 660);
	time2.setPosition(700, 710);
	time3.setPosition(700, 760);
	time4.setPosition(700, 810);
	time5.setPosition(700, 860);
	time6.setPosition(700, 910);
	time7.setPosition(700, 960);
	time8.setPosition(700, 1010);


	time1.setColor(sf::Color::White);
	time2.setColor(sf::Color::White);
	time3.setColor(sf::Color::White);
	time4.setColor(sf::Color::White);
	time5.setColor(sf::Color::White);
	time6.setColor(sf::Color::White);
	time7.setColor(sf::Color::White);
	time8.setColor(sf::Color::White);



	renderWindow.draw(time1);
	renderWindow.draw(time2);
	renderWindow.draw(time3);
	renderWindow.draw(time4);
	renderWindow.draw(time5);
	renderWindow.draw(time6);
	renderWindow.draw(time7);
	renderWindow.draw(time8);


}
void Battle::playerTwoSkillTimes(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, Player * playerB)
{

	sf::Text time1;
	sf::Text time2;
	sf::Text time3;
	sf::Text time4;
	sf::Text time5;
	sf::Text time6;
	sf::Text time7;
	sf::Text time8;

	double moveTime1 = playerB->getAbilityTime1();
	double moveTime2 = playerB->getAbilityTime2();
	double moveTime3 = playerB->getAbilityTime3();
	double moveTime4 = playerB->getAbilityTime4();
	double moveTime5 = playerB->getAbilityTime5();
	double moveTime6 = playerB->getAbilityTime6();
	double moveTime7 = playerB->getAbilityTime7();
	double moveTime8 = playerB->getAbilityTime8();

	//accounts for all changes to the numbers via buffs debuffs

	if (playerB->playerBuff == "Power Stance" || playerB->playerSecondBuff == "Power Stance" || playerB->playerThirdBuff == "Power Stance")
	{
		moveTime1 += .5;
		moveTime2 += .5;
		moveTime3 += .5;
		moveTime4 += .5;
		moveTime5 += .5;
		moveTime6 += .5;
		moveTime7 += .5;
		moveTime8 += .5;
	}
	if (playerB->playerBuff == "Step in" || playerB->playerSecondBuff == "Step in" || playerB->playerThirdBuff == "Step in")
	{
		moveTime1 -= .5;
		moveTime2 -= .5;
		moveTime3 -= .5;
		moveTime4 -= .5;
		moveTime5 -= .5;
		moveTime6 -= .5;
		moveTime7 -= .5;
		moveTime8 -= .5;
	}

	if (playerB->playerDebuff == "Knocked Down" || playerB->playerSecondDebuff == "Knocked Down" || playerB->playerThirdDebuff == "Knocked Down")
	{
		moveTime1 += 1;
		moveTime2 += 1;
		moveTime3 += 1;
		moveTime4 += 1;
		moveTime5 += 1;
		moveTime6 += 1;
		moveTime7 += 1;
		moveTime8 += 1;
	}

	if (playerB->playerDebuff == "Disarmed" || playerB->playerSecondDebuff == "Disarmed" || playerB->playerThirdDebuff == "Disarmed")
	{
		moveTime1 += .5;
		moveTime2 += .5;
		moveTime3 += .5;
		moveTime4 += .5;
		moveTime5 += .5;
		moveTime6 += .5;
		moveTime7 += .5;
		moveTime8 += .5;
	}


	if (playerB->playerDebuff == "Pushed" || playerB->playerSecondDebuff == "Pushed" || playerB->playerThirdDebuff == "Pushed")
	{
		moveTime1 += .3;
		moveTime2 += .3;
		moveTime3 += .3;
		moveTime4 += .3;
		moveTime5 += .3;
		moveTime6 += .3;
		moveTime7 += .3;
		moveTime8 += .3;
	}













	//////////////////////////////////////////////////////////////

	stringstream timeConvert1;
	stringstream timeConvert2;
	stringstream timeConvert3;
	stringstream timeConvert4;
	stringstream timeConvert5;
	stringstream timeConvert6;
	stringstream timeConvert7;
	stringstream timeConvert8;

	timeConvert1 << moveTime1;
	timeConvert2 << moveTime2;
	timeConvert3 << moveTime3;
	timeConvert4 << moveTime4;
	timeConvert5 << moveTime5;
	timeConvert6 << moveTime6;
	timeConvert7 << moveTime7;
	timeConvert8 << moveTime8;


	time1.setString(timeConvert1.str());
	time2.setString(timeConvert2.str());
	time3.setString(timeConvert3.str());
	time4.setString(timeConvert4.str());
	time5.setString(timeConvert5.str());
	time6.setString(timeConvert6.str());
	time7.setString(timeConvert7.str());
	time8.setString(timeConvert8.str());





	//sets the font to the containers
	time1.setFont(_visibleObjectManager.font);
	time2.setFont(_visibleObjectManager.font);
	time3.setFont(_visibleObjectManager.font);
	time4.setFont(_visibleObjectManager.font);
	time5.setFont(_visibleObjectManager.font);
	time6.setFont(_visibleObjectManager.font);
	time7.setFont(_visibleObjectManager.font);
	time8.setFont(_visibleObjectManager.font);


	time1.setCharacterSize(20);
	time2.setCharacterSize(20);
	time3.setCharacterSize(20);
	time4.setCharacterSize(20);
	time5.setCharacterSize(20);
	time6.setCharacterSize(20);
	time7.setCharacterSize(20);
	time8.setCharacterSize(20);

	time1.setPosition(1473, 660);
	time2.setPosition(1473, 710);
	time3.setPosition(1473, 760);
	time4.setPosition(1473, 810);
	time5.setPosition(1473, 860);
	time6.setPosition(1473, 910);
	time7.setPosition(1473, 960);
	time8.setPosition(1473, 1010);


	time1.setColor(sf::Color::White);
	time2.setColor(sf::Color::White);
	time3.setColor(sf::Color::White);
	time4.setColor(sf::Color::White);
	time5.setColor(sf::Color::White);
	time6.setColor(sf::Color::White);
	time7.setColor(sf::Color::White);
	time8.setColor(sf::Color::White);



	renderWindow.draw(time1);
	renderWindow.draw(time2);
	renderWindow.draw(time3);
	renderWindow.draw(time4);
	renderWindow.draw(time5);
	renderWindow.draw(time6);
	renderWindow.draw(time7);
	renderWindow.draw(time8);


}


//specifically handles the special abilities a warrior has and how it affects the turn
void Battle::warriorFunction(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB, AudioManager & _audioManager)
{


	if (_gameObjectManager.getTurnOperation() == false)
	{

		if (playerA->playerBuff == "Power Stance")
		{
			playerA->damage *= 1.5;
			playerA->time += 0.5;
			playerA->uninterruptable = true;

		}
		else if (playerA->playerSecondBuff == "Power Stance")
		{
			playerA->damage *= 1.5;
			playerA->time += 0.5;
			playerA->uninterruptable = true;

		}
		else if (playerA->playerThirdBuff == "Power Stance")
		{
			playerA->damage *= 1.5;
			playerA->time += 0.5;
			playerA->uninterruptable = true;

		}

		if (playerB->playerBuff == "Power Stance")
		{
			playerB->damage *= 1.5;
			playerB->time += 0.5;
			playerB->uninterruptable = true;

		}
		else if (playerB->playerSecondBuff == "Power Stance")
		{
			playerB->damage *= 1.5;
			playerB->time += 0.5;
			playerB->uninterruptable = true;

		}
		else if (playerB->playerThirdBuff == "Power Stance")
		{
			playerB->damage *= 1.5;
			playerB->time += 0.5;
			playerB->uninterruptable = true;

		}

		/////////////////////////////////////////////////////////////////////////

		if (playerA->playerDebuff == "Shout")
		{
			playerA->moveNumberCD += 2;
		}
		else if (playerA->playerSecondDebuff == "Shout")
		{
			playerA->moveNumberCD += 2;
		}
		else if (playerA->playerThirdDebuff == "Shout")
		{
			playerA->moveNumberCD += 2;
		}

		if (playerB->playerDebuff == "Shout")
		{
			playerB->moveNumberCD += 2;
		}
		else if (playerB->playerSecondDebuff == "Shout")
		{
			playerB->moveNumberCD += 2;
		}
		else if (playerB->playerThirdDebuff == "Shout")
		{
			playerB->moveNumberCD += 2;
		}

	}
}

//handles the application of poison to the opponent(to be called within attack order function)
void Battle::applyPoison(Player * playerA, Player * playerB)
{

	//player A giving player B the poison

	//accounts specifically for when poison has been applied to the next attack for player 1
	if ((playerA->damage > 0) && ((playerA->playerBuff == "poison") ||
		(playerA->playerSecondBuff == "poison") || (playerA->playerThirdBuff == "poison")))
	{
		if (playerB->playerDebuff == "")
		{
			playerB->playerDebuff = "poison";
			playerB->playerDebuff1Duration = 3;
		}
		else if (playerB->playerSecondDebuff == "")
		{
			playerB->playerSecondDebuff = "poison";
			playerB->playerDebuff2Duration = 3;
		}
		else if (playerB->playerThirdDebuff == "")
		{
			playerB->playerDebuff3Duration = 3;
			playerB->playerThirdDebuff = "poison";
		}


		//handles the removal of the poison buff
		if (playerA->playerBuff == "poison") playerA->playerBuff = "";
		else if (playerA->playerSecondBuff == "poison") playerA->playerSecondBuff = "";
		else if (playerA->playerThirdBuff == "poison") playerA->playerThirdBuff = "";
	}

	//accounts specifically for when poison has been applied to the next attack for player 1
	if ((playerA->damage > 0) && ((playerA->playerBuff == "deadly poison") ||
		(playerA->playerSecondBuff == "deadly poison") || (playerA->playerThirdBuff == "deadly poison")))
	{
		if (playerB->playerDebuff == "")
		{
			playerB->playerDebuff = "deadly poison";
			playerB->playerDebuff1Duration = 3;
		}
		else if (playerB->playerSecondDebuff == "")
		{
			playerB->playerSecondDebuff = "deadly poison";
			playerB->playerDebuff2Duration = 3;
		}
		else if (playerB->playerThirdDebuff == "")
		{
			playerB->playerDebuff3Duration = 3;
			playerB->playerThirdDebuff = "deadly poison";
		}


		//handles the removal of the poison buff
		if (playerA->playerBuff == "deadly poison") playerA->playerBuff = "";
		else if (playerA->playerSecondBuff == "deadly poison") playerA->playerSecondBuff = "";
		else if (playerA->playerThirdBuff == "deadly poison") playerA->playerThirdBuff = "";
	}

}

//specifically handles the special abilities an assassin has and how it affects the turn
void Battle::assassinFunction(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB)
{

	if (((playerA->playerBuff == "smoke") ||
		(playerA->playerSecondBuff == "smoke") || (playerA->playerThirdBuff == "smoke")))
	{

		playerA->state = "dodge";
		playerA->dodgeChance += 50;
	}


	if (((playerB->playerBuff == "smoke") ||
		(playerB->playerSecondBuff == "smoke") || (playerB->playerThirdBuff == "smoke")))
	{

		playerB->state = "dodge";
		playerB->dodgeChance += 50;
	}


	//checks to see if the player is staggered, if they are then this gives the enemy an additional 20% dodge chance
	if ((playerA->playerDebuff == "Stagger") || (playerA->playerSecondDebuff == "Stagger") || (playerA->playerThirdDebuff == "Stagger"))
	{
		playerB->state = "dodge";
		playerB->dodgeChance += 20;
	}

	if ((playerB->playerDebuff == "Stagger") || (playerB->playerSecondDebuff == "Stagger") || (playerB->playerThirdDebuff == "Stagger"))
	{
		playerA->state = "dodge";
		playerA->dodgeChance += 20;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////

	//checks to see if the player is magically staggered, if they are then this gives the enemy an additional 35% dodge chance
	if ((playerA->playerDebuff == "Magic Stagger") || (playerA->playerSecondDebuff == "Magic Stagger") || (playerA->playerThirdDebuff == "Magic Stagger"))
	{
		playerB->state = "dodge";
		playerB->dodgeChance += 35;
	}

	if ((playerB->playerDebuff == "Magic Stagger") || (playerB->playerSecondDebuff == "Magic Stagger") || (playerB->playerThirdDebuff == "Magic Stagger"))
	{
		playerA->state = "dodge";
		playerA->dodgeChance = +35;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////


	if (playerA->name == "Vital Strike")
	{
		if (playerA->time <= playerB->time) playerA->damage = 25;
	}

	if (playerB->name == "Vital Strike")
	{
		if (playerB->time <= playerA->time) playerB->damage = 25;
	}

	//checks to see if back blows special condition was met
	if (playerA->playerDodged == true && playerA->name == "Back Blow")
	{
		playerA->time = 1;
	}

	if (playerB->playerDodged == true && playerB->name == "Back Blow")
	{
		playerB->time = 1;
	}
	//resets state after check expression has passed
	playerA->playerDodged = false;
	playerB->playerDodged = false;
	//////////////////////////////////////////////////////////////////////////////////


	//accounts for the window where leg slice dodges a move
	if (((playerA->time - 0.2) == playerB->time) && (playerA->name == "Leg Slice"))
	{
		playerA->state = "dodge";
		playerA->dodgeChance = 100;
	}
	else if (((playerA->time - 0.1) == playerB->time) && (playerA->name == "Leg Slice"))
	{
		playerA->state = "dodge";
		playerA->dodgeChance = 100;
	}
	else if (((playerA->time) == playerB->time) && (playerA->name == "Leg Slice"))
	{
		playerA->state = "dodge";
		playerA->dodgeChance = 100;
	}
	else if (((playerA->time + 0.2) == playerB->time) && (playerA->name == "Leg Slice"))
	{
		playerA->state = "dodge";
		playerA->dodgeChance = 100;
	}
	else if (((playerA->time + 0.1) == playerB->time) && (playerA->name == "Leg Slice"))
	{
		playerA->state = "dodge";
		playerA->dodgeChance = 100;
	}


	//player 2
	if (((playerB->time - 0.2) == playerA->time) && (playerB->name == "Leg Slice"))
	{
		playerB->state = "dodge";
		playerB->dodgeChance = 100;
	}
	else if (((playerB->time - 0.1) == playerA->time) && (playerB->name == "Leg Slice"))
	{
		playerB->state = "dodge";
		playerB->dodgeChance = 100;
	}
	else if (((playerB->time) == playerA->time) && (playerB->name == "Leg Slice"))
	{
		playerB->state = "dodge";
		playerB->dodgeChance = 100;
	}
	else if (((playerB->time + 0.2) == playerA->time) && (playerB->name == "Leg Slice"))
	{
		playerB->state = "dodge";
		playerB->dodgeChance = 100;
	}
	else if (((playerB->time + 0.1) == playerA->time) && (playerB->name == "Leg Slice"))
	{
		playerB->state = "dodge";
		playerB->dodgeChance = 100;
	}
	/////////////////////////////////////////////////////////////////////////////////////


	//makes adjustments for when player has been disarmed
	if (playerA->name == "Disarm")
	{
		playerB->uninterruptable = false;
	}
	if (playerB->name == "Disarm")
	{
		playerA->uninterruptable = false;
	}


	//makes adjustments for the debuff called disarmed
	if ((playerA->playerDebuff == "Disarmed") || (playerA->playerSecondDebuff == "Disarmed") || (playerA->playerThirdDebuff == "Disarmed"))
	{
		playerA->time += 0.5;
		if (playerA->playerDebuff == "Disarmed") playerA->playerBuff = "";
		else if (playerA->playerSecondDebuff == "Disarmed") playerA->playerSecondDebuff = "";
		if (playerA->playerThirdDebuff == "Disarmed") playerA->playerThirdDebuff = "";
	}

	if ((playerB->playerDebuff == "Disarmed") || (playerB->playerSecondDebuff == "Disarmed") || (playerB->playerThirdDebuff == "Disarmed"))
	{
		playerB->time += 0.5;
		if (playerB->playerDebuff == "Disarmed") playerB->playerBuff = "";
		else if (playerB->playerSecondDebuff == "Disarmed") playerB->playerSecondDebuff = "";
		if (playerB->playerThirdDebuff == "Disarmed") playerB->playerThirdDebuff = "";
	}
	/////////////////////////////////////////////////////////


}

//specifically handles the special abilities a monk has and how it affects the turn
void Battle::monkFunction(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB)
{
	if (playerA->playerDebuff == "Pushed") playerA->time += 0.3;
	else if (playerA->playerSecondDebuff == "Pushed") playerA->time += 0.3;
	else if (playerA->playerThirdDebuff == "Pushed") playerA->time += 0.3;

	if (playerB->playerDebuff == "Pushed") playerB->time += 0.3;
	else if (playerB->playerSecondDebuff == "Pushed") playerB->time += 0.3;
	else if (playerB->playerThirdDebuff == "Pushed") playerB->time += 0.3;

	//////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////



	//accounts for all handled events pertaining to Step in
	if ((playerA->name == "Piercing Kick") || (playerA->name == "Interrupting Jab") || (playerA->name == "Elbow Parry") ||
		(playerA->name == "Heavenly Tackle") || (playerA->name == "Inhuman Speed") || (playerA->name == "Meditate"))
	{
		if (playerA->playerBuff == "Step in") playerA->playerBuff = "";
		else if (playerA->playerSecondBuff == "Step in") playerA->playerSecondBuff = "";
		else if (playerA->playerThirdBuff == "Step in") playerA->playerThirdBuff = "";
	}

	if ((playerB->name == "Piercing Kick") || (playerB->name == "Interrupting Jab") || (playerB->name == "Elbow Parry") ||
		(playerB->name == "Heavenly Tackle") || (playerB->name == "Inhuman Speed") || (playerB->name == "Meditate"))
	{
		if (playerB->playerBuff == "Step in") playerB->playerBuff = "";
		else if (playerB->playerSecondBuff == "Step in") playerB->playerSecondBuff = "";
		else if (playerB->playerThirdBuff == "Step in") playerB->playerThirdBuff = "";
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (playerA->name == "Piercing Kick") playerB->reductionPercent = 0;
	if (playerB->name == "Piercing Kick") playerA->reductionPercent = 0;

	//makes adjustments for when player has been disarmed
	if (playerA->name == "Piercing Kick")
	{
		playerB->uninterruptable = false;
	}
	if (playerB->name == "Piercing Kick")
	{
		playerA->uninterruptable = false;
	}


	if (playerA->name == "Heavenly Tackle") playerB->reductionPercent = 0;
	if (playerB->name == "Heavenly Tackle") playerA->reductionPercent = 0;

	//makes adjustments for when player has been heavenly tackled
	if (playerA->name == "Heavenly Tackle")
	{
		playerB->uninterruptable = false;
	}
	if (playerB->name == "Heavenly Tackle")
	{
		playerA->uninterruptable = false;
	}


	if (playerA->playerBuff == "Step in") playerA->time -= 0.5;
	else if (playerA->playerSecondBuff == "Step in") playerA->time -= 0.5;
	else if (playerA->playerThirdBuff == "Step in") playerA->time -= 0.5;

	if (playerB->playerBuff == "Step in") playerB->time -= 0.5;
	else if (playerB->playerSecondBuff == "Step in") playerB->time -= 0.5;
	else if (playerB->playerThirdBuff == "Step in") playerB->time -= 0.5;

	/////////////////////////////////////////////////////////////////////////////////////////////

	if (playerA->name == "Elbow Parry" && playerB->state == "attack")
	{
		playerB->uninterruptable = true;

		if (playerA->time > playerB->time)
		{
			playerB->damage = 0;
			playerB->appliedDebuff = "";
			playerB->buff = "";

		}
	}
	if (playerB->name == "Elbow Parry" && playerA->state == "attack")
	{
		playerA->uninterruptable = true;

		if (playerB->time > playerA->time)
		{
			playerA->damage = 0;
			playerA->appliedDebuff = "";
			playerA->buff = "";
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////

	if (playerA->playerDebuff == "Knocked Down") playerA->time += 1;
	else if (playerA->playerSecondDebuff == "Knocked Down") playerA->time += 1;
	else if (playerA->playerThirdDebuff == "Knocked Down") playerA->time += 1;

	if (playerB->playerDebuff == "Knocked Down") playerB->time += 1;
	else if (playerB->playerSecondDebuff == "Knocked Down") playerB->time += 1;
	else if (playerB->playerThirdDebuff == "Knocked Down") playerB->time += 1;

	///////////////////////////////////////////////////////////////////////////////////////////////

	if (playerA->playerMeditateChoice == playerB->name)
	{
		if (playerA->getHp() != playerA->getTotalHp())
			playerA->setHp(playerA->getHp() + playerB->damage);
		playerB->damage = 0;

		playerB->appliedDebuff = "";
		playerB->state = "attack";

		//empties meditate choice right after checks done
		playerA->playerMeditateChoice = "empty";
	}


	if (playerB->playerMeditateChoice == playerA->name)
	{
		if (playerB->getHp() != playerB->getTotalHp())
			playerB->setHp(playerB->getHp() + playerA->damage);
		playerA->damage = 0;

		playerA->appliedDebuff = "";
		playerA->state = "attack";

		//empties meditate choice right after checks done
		playerB->playerMeditateChoice = "empty";
	}

	//////////////////////////////////////////////////////////////////////////////////////////////




	if (playerA->name == "Inhuman Speed")
	{
		playerA->playerMove1CD = 1;
		playerA->playerMove2CD = 1;
		playerA->playerMove3CD = 1;
		playerA->playerMove4CD = 1;
		playerA->playerMove5CD = 1;
		playerA->playerMove6CD = 1;
		playerA->playerMove8CD = 1;
	}

	if (playerB->name == "Inhuman Speed")
	{
		playerB->playerMove1CD = 1;
		playerB->playerMove2CD = 1;
		playerB->playerMove3CD = 1;
		playerB->playerMove4CD = 1;
		playerB->playerMove5CD = 1;
		playerB->playerMove6CD = 1;
		playerB->playerMove8CD = 1;
	}

}

void Battle::necroFunction(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB)
{
	if (playerA->playerBuff == "Decay Aura")
	{
		playerB->setHp(playerB->getHp() - 5);

	}
	else if (playerA->playerSecondBuff == "Decay Aura")
	{
		playerB->setHp(playerB->getHp() - 5);

	}
	else if (playerA->playerThirdBuff == "Decay Aura")
	{
		playerB->setHp(playerB->getHp() - 5);
	}

	//player 2

	if (playerB->playerBuff == "Decay Aura")
	{
		playerA->setHp(playerA->getHp() - 5);

	}
	else if (playerB->playerSecondBuff == "Decay Aura")
	{
		playerA->setHp(playerA->getHp() - 5);

	}
	else if (playerB->playerThirdBuff == "Decay Aura")
	{
		playerA->setHp(playerA->getHp() - 5);
	}


	if ((playerA->playerBuff == "Bone wall") || (playerA->playerSecondBuff == "Bone wall") || (playerA->playerThirdBuff == "Bone wall"))
	{
		//creates a temp check
		bool wallHit = false;

		//handles when both people attacked
		if ((playerA->damage > 0) && (playerB->damage > 0))
		{
			//if both people attacked and player A was the slower attack then player B attacks the wall  thus doing no damage or buffs.
			if (playerA->time > playerB->time)
			{
				playerB->damage = 0;
				playerB->appliedDebuff = "";
				wallHit = true;
			}
			//if both people attacked and player B was the slower attack then player A attacks the wall  thus doing no damage or buffs.
			else if (playerA->time < playerB->time)
			{
				playerA->damage = 0;
				playerA->appliedDebuff = "";
				wallHit = true;
			}
			//they both break the wall at the same time, no one hurts anyone
			else if (playerA->time == playerB->time)
			{
				playerA->damage = 0;
				playerA->appliedDebuff = "";
				playerB->damage = 0;
				playerB->appliedDebuff = "";
				wallHit = true;
			}
		}
		//when player A breaks the wall
		else if ((playerA->damage > 0) && (playerB->damage == 0))
		{
			playerA->damage = 0;
			playerA->appliedDebuff = "";
			wallHit = true;
		}
		//when player B breaks the wall
		else if ((playerB->damage > 0) && (playerA->damage == 0))
		{
			playerB->damage = 0;
			playerB->appliedDebuff = "";
			wallHit = true;
		}


		if (wallHit == true)
		{
			if (playerA->playerBuff == "Bone wall") playerA->playerBuff = "";
			else if (playerA->playerSecondBuff == "Bone wall") playerA->playerSecondBuff = "";
			else if (playerA->playerThirdBuff == "Bone wall") playerA->playerThirdBuff = "";
		}
	}

	if ((playerB->playerBuff == "Bone wall") || (playerB->playerSecondBuff == "Bone wall") || (playerB->playerThirdBuff == "Bone wall"))
	{
		//creates a temp check
		bool wallHit = false;
		//handles when both people attacked
		if ((playerA->damage > 0) && (playerB->damage > 0))
		{
			//if both people attacked and player A was the slower attack then player B attacks the wall  thus doing no damage or buffs.
			if (playerA->time > playerB->time)
			{
				playerB->damage = 0;
				playerB->appliedDebuff = "";
				wallHit = true;
			}
			//if both people attacked and player B was the slower attack then player A attacks the wall  thus doing no damage or buffs.
			else if (playerA->time < playerB->time)
			{
				playerA->damage = 0;
				playerA->appliedDebuff = "";
				wallHit = true;
			}
			//they both break the wall at the same time, no one hurts anyone
			else if (playerA->time == playerB->time)
			{
				playerA->damage = 0;
				playerA->appliedDebuff = "";
				playerB->damage = 0;
				playerB->appliedDebuff = "";
				wallHit = true;
			}
		}
		//when player A breaks the wall
		else if ((playerA->damage > 0) && (playerB->damage == 0))
		{
			playerA->damage = 0;
			playerA->appliedDebuff = "";
			wallHit = true;
		}
		//when player B breaks the wall
		else if ((playerB->damage > 0) && (playerA->damage == 0))
		{
			playerB->damage = 0;
			playerB->appliedDebuff = "";
			wallHit = true;
		}


		if (wallHit == true)
		{
			if (playerB->playerBuff == "Bone wall") playerB->playerBuff = "";
			else if (playerB->playerSecondBuff == "Bone wall") playerB->playerSecondBuff = "";
			else if (playerB->playerThirdBuff == "Bone wall") playerB->playerThirdBuff = "";
		}
	}


}


void Battle::demonFunction(GameObjectManager & _gameObjectManager, Player * playerA, Player * playerB)
{
	//////////////////fury handler//////////////
	if (playerA->playerBuff == "Fury" || playerA->playerSecondBuff == "Fury" || playerA->playerThirdBuff == "Fury")
	{
		playerA->damage += playerA->furyDamage;
		playerA->furyDamage = 0;
	}

	if (playerB->playerBuff == "Fury" || playerB->playerSecondBuff == "Fury" || playerB->playerThirdBuff == "Fury")
	{
		playerB->damage += playerB->furyDamage;
		playerB->furyDamage = 0;
	}



	//////////////lava/////////////////
	if (playerA->playerDebuff == "Lava" || playerA->playerSecondDebuff == "Lava" || playerA->playerThirdDebuff == "Lava")
	{
		playerA->setHp(playerA->getHp() - 7);
	}

	if (playerB->playerDebuff == "Lava" || playerB->playerSecondDebuff == "Lava" || playerB->playerThirdDebuff == "Lava")
	{
		playerB->setHp(playerB->getHp() - 7);
	}

	//enraged
	if (playerA->playerBuff == "Enraged" || playerA->playerSecondBuff == "Enraged" || playerA->playerThirdBuff == "Enraged")
	{
		playerA->reductionPercent = .50;
	}

	if (playerB->playerBuff == "Enraged" || playerB->playerSecondBuff == "Enraged" || playerB->playerThirdBuff == "Enraged")
	{
		playerB->reductionPercent = .50;
	}

	//Fire skin

	if (playerA->playerBuff == "Fire Aura" || playerA->playerSecondBuff == "Fire Aura" || playerA->playerThirdBuff == "Fire Aura")
	{
		playerA->damage += 10;
	}

	if (playerB->playerBuff == "Fire Aura" || playerB->playerSecondBuff == "Fire Aura" || playerB->playerThirdBuff == "Fire Aura")
	{
		playerB->damage += 10;
	}

	//Mutilation
	if (playerA->name == "Mutilation") playerA->setHp(playerA->getHp() - 20);
	if (playerB->name == "Mutilation") playerB->setHp(playerB->getHp() - 20);

	if (playerA->name == "Demon Tackle") playerB->reductionPercent = 0;
	if (playerB->name == "Demon Tackle") playerA->reductionPercent = 0;
}

//handles the monks meditate function
void Battle::meditateHandler(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, AudioManager & _audioManager, sf::Event & event, Player * playerA, Player * playerB)
{


	bool leftTriggerPlayer1 = false;
	bool rightTriggerPlayer1 = false;
	bool leftTriggerPlayer2 = false;
	bool rightTriggerPlayer2 = false;

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) > 5) leftTriggerPlayer1 = true;
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -5) rightTriggerPlayer1 = true;
	if (sf::Joystick::getAxisPosition(1, sf::Joystick::Z) > 5) leftTriggerPlayer2 = true;
	if (sf::Joystick::getAxisPosition(1, sf::Joystick::Z) < -5) rightTriggerPlayer2 = true;

	/////////////////player 1/////////////////////
	if (playerA->name == "Meditate")
	{

		//sets the names for the 8 moves that will be shown
		_visibleObjectManager.move1NamePlayer1.setString(playerB->getAbility1());
		_visibleObjectManager.move2NamePlayer1.setString(playerB->getAbility2());
		_visibleObjectManager.move3NamePlayer1.setString(playerB->getAbility3());
		_visibleObjectManager.move4NamePlayer1.setString(playerB->getAbility4());
		_visibleObjectManager.move5NamePlayer1.setString(playerB->getAbility5());
		_visibleObjectManager.move6NamePlayer1.setString(playerB->getAbility6());
		_visibleObjectManager.move7NamePlayer1.setString(playerB->getAbility7());
		_visibleObjectManager.move8NamePlayer1.setString(playerB->getAbility8());








		////creates 9 texts containers
		//sf::Text indicator;

		////sets the font to the containers
		//indicator.setFont(_visibleObjectManager.font);


		//// sets the strings to display
		//indicator.setString("Guess Opponents Move");

		//// set the character size
		//indicator.setCharacterSize(60);




		////// set the color
		//indicator.setColor(sf::Color::White);

		////// set the text style
		//indicator.setStyle(sf::Text::Bold);

		////sets the positions
		//indicator.setPosition(250, 400);

		////shows the skills only if player hasn't picked yet
		//if(playerA->playerPicked == false)
		//{
		//	//draws the skill words onto the menu
		//	renderWindow.draw(_visibleObjectManager.move1NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move2NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move3NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move4NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move5NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move6NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move7NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move8NamePlayer1);
		//	renderWindow.draw(indicator);



		//}




		//creates a vector that holds the mouses position
		sf::Vector2f mousePos = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));

		//sets up a clickable response
		sf::FloatRect boundsp1s1 = _visibleObjectManager.SkillMenuPlayer1Skill1.getGlobalBounds();
		sf::FloatRect boundsp1s2 = _visibleObjectManager.SkillMenuPlayer1Skill2.getGlobalBounds();
		sf::FloatRect boundsp1s3 = _visibleObjectManager.SkillMenuPlayer1Skill3.getGlobalBounds();
		sf::FloatRect boundsp1s4 = _visibleObjectManager.SkillMenuPlayer1Skill4.getGlobalBounds();
		sf::FloatRect boundsp1s5 = _visibleObjectManager.SkillMenuPlayer1Skill5.getGlobalBounds();
		sf::FloatRect boundsp1s6 = _visibleObjectManager.SkillMenuPlayer1Skill6.getGlobalBounds();
		sf::FloatRect boundsp1s7 = _visibleObjectManager.SkillMenuPlayer1Skill7.getGlobalBounds();
		sf::FloatRect boundsp1s8 = _visibleObjectManager.SkillMenuPlayer1Skill8.getGlobalBounds();


		//renderWindow.pollEvent(event);


		if ((boundsp1s1.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 0))
		{
			_audioManager.playButtonClick(1);
			playerA->playerMeditateChoice = playerB->getAbility1();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility1();
		}


		if ((boundsp1s2.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 1))
		{
			_audioManager.playButtonClick(1);
			playerA->playerMeditateChoice = playerB->getAbility2();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility2();
		}

		if ((boundsp1s3.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 3))
		{
			_audioManager.playButtonClick(1);
			playerA->playerMeditateChoice = playerB->getAbility3();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility3();
		}
		if ((boundsp1s4.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 2))
		{
			_audioManager.playButtonClick(1);
			playerA->playerMeditateChoice = playerB->getAbility4();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility4();
		}
		if ((boundsp1s5.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 4))
		{
			_audioManager.playButtonClick(1);
			playerA->playerMeditateChoice = playerB->getAbility5();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility5();
		}
		if ((boundsp1s6.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 5))
		{
			_audioManager.playButtonClick(1);
			playerA->playerMeditateChoice = playerB->getAbility6();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility6();
		}
		if ((boundsp1s7.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || leftTriggerPlayer1)
		{
			_audioManager.playButtonClick(1);
			playerA->playerMeditateChoice = playerB->getAbility7();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility7();
		}
		if ((boundsp1s8.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || rightTriggerPlayer1)
		{
			_audioManager.playButtonClick(1);
			playerA->playerMeditateChoice = playerB->getAbility8();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility8();
		}




	}



	////player 2///////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if (playerB->name == "Meditate")
	{

		//sets the names for the 8 moves that will be shown
		_visibleObjectManager.move1NamePlayer2.setString(playerA->getAbility1());
		_visibleObjectManager.move2NamePlayer2.setString(playerA->getAbility2());
		_visibleObjectManager.move3NamePlayer2.setString(playerA->getAbility3());
		_visibleObjectManager.move4NamePlayer2.setString(playerA->getAbility4());
		_visibleObjectManager.move5NamePlayer2.setString(playerA->getAbility5());
		_visibleObjectManager.move6NamePlayer2.setString(playerA->getAbility6());
		_visibleObjectManager.move7NamePlayer2.setString(playerA->getAbility7());
		_visibleObjectManager.move8NamePlayer2.setString(playerA->getAbility8());








		//creates 9 texts containers
		sf::Text indicator;

		//sets the font to the containers
		indicator.setFont(_visibleObjectManager.font);


		// sets the strings to display
		indicator.setString("Guess Opponents Move");

		// set the character size
		indicator.setCharacterSize(60);




		//// set the color
		indicator.setColor(sf::Color::White);

		//// set the text style
		indicator.setStyle(sf::Text::Bold);

		//sets the positions
		indicator.setPosition(1250, 400);

		////shows the skills only if player hasn't picked yet
		//if(playerB->playerPicked == false)
		//{
		//	//draws the skill words onto the menu
		//	renderWindow.draw(_visibleObjectManager.move1NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move2NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move3NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move4NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move5NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move6NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move7NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move8NamePlayer2);
		//	renderWindow.draw(indicator);



		//}


		//creates a vector that holds the mouses position
		sf::Vector2f mousePos = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));

		//sets up a clickable response
		sf::FloatRect boundsp2s1 = _visibleObjectManager.SkillMenuPlayer2Skill1.getGlobalBounds();
		sf::FloatRect boundsp2s2 = _visibleObjectManager.SkillMenuPlayer2Skill2.getGlobalBounds();
		sf::FloatRect boundsp2s3 = _visibleObjectManager.SkillMenuPlayer2Skill3.getGlobalBounds();
		sf::FloatRect boundsp2s4 = _visibleObjectManager.SkillMenuPlayer2Skill4.getGlobalBounds();
		sf::FloatRect boundsp2s5 = _visibleObjectManager.SkillMenuPlayer2Skill5.getGlobalBounds();
		sf::FloatRect boundsp2s6 = _visibleObjectManager.SkillMenuPlayer2Skill6.getGlobalBounds();
		sf::FloatRect boundsp2s7 = _visibleObjectManager.SkillMenuPlayer2Skill7.getGlobalBounds();
		sf::FloatRect boundsp2s8 = _visibleObjectManager.SkillMenuPlayer2Skill8.getGlobalBounds();


		//renderWindow.pollEvent(event);


		if ((boundsp2s1.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 0))
		{
			_audioManager.playButtonClick(1);
			playerB->playerMeditateChoice = playerA->getAbility1();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility1();
		}


		if ((boundsp2s2.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 1))
		{
			_audioManager.playButtonClick(1);
			playerB->playerMeditateChoice = playerA->getAbility2();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility2();
		}

		if ((boundsp2s3.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 3))
		{
			_audioManager.playButtonClick(1);
			playerB->playerMeditateChoice = playerA->getAbility3();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility3();
		}
		if ((boundsp2s4.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 2))
		{
			_audioManager.playButtonClick(1);
			playerB->playerMeditateChoice = playerA->getAbility4();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility4();
		}
		if ((boundsp2s5.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 4))
		{
			_audioManager.playButtonClick(1);
			playerB->playerMeditateChoice = playerA->getAbility5();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility5();
		}
		if ((boundsp2s6.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 5))
		{
			_audioManager.playButtonClick(1);
			playerB->playerMeditateChoice = playerA->getAbility6();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility6();
		}
		if ((boundsp2s7.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || leftTriggerPlayer2)
		{
			_audioManager.playButtonClick(1);
			playerB->playerMeditateChoice = playerA->getAbility7();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility7();
		}
		if ((boundsp2s8.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || rightTriggerPlayer2)
		{
			_audioManager.playButtonClick(1);
			playerB->playerMeditateChoice = playerA->getAbility8();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility8();
		}




	}

}

void Battle::boneCrusherHandler(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, AudioManager & _audioManager, sf::Event & event, Player * playerA, Player * playerB)
{


	bool leftTriggerPlayer1 = false;
	bool rightTriggerPlayer1 = false;
	bool leftTriggerPlayer2 = false;
	bool rightTriggerPlayer2 = false;

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) > 5) leftTriggerPlayer1 = true;
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -5) rightTriggerPlayer1 = true;
	if (sf::Joystick::getAxisPosition(1, sf::Joystick::Z) > 5) leftTriggerPlayer2 = true;
	if (sf::Joystick::getAxisPosition(1, sf::Joystick::Z) < -5) rightTriggerPlayer2 = true;
	/////////////////player 1/////////////////////
	if (playerA->name == "Bone Crusher")
	{

		//sets the names for the 8 moves that will be shown
		_visibleObjectManager.move1NamePlayer1.setString(playerB->getAbility1());
		_visibleObjectManager.move2NamePlayer1.setString(playerB->getAbility2());
		_visibleObjectManager.move3NamePlayer1.setString(playerB->getAbility3());
		_visibleObjectManager.move4NamePlayer1.setString(playerB->getAbility4());
		_visibleObjectManager.move5NamePlayer1.setString(playerB->getAbility5());
		_visibleObjectManager.move6NamePlayer1.setString(playerB->getAbility6());
		_visibleObjectManager.move7NamePlayer1.setString(playerB->getAbility7());
		_visibleObjectManager.move8NamePlayer1.setString(playerB->getAbility8());








		////creates 9 texts containers
		//sf::Text indicator;

		////sets the font to the containers
		//indicator.setFont(_visibleObjectManager.font);


		//// sets the strings to display
		//indicator.setString("Guess Opponents Move");

		//// set the character size
		//indicator.setCharacterSize(60);




		////// set the color
		//indicator.setColor(sf::Color::White);

		////// set the text style
		//indicator.setStyle(sf::Text::Bold);

		////sets the positions
		//indicator.setPosition(250, 400);

		////shows the skills only if player hasn't picked yet
		//if(playerA->playerPicked == false)
		//{
		//	//draws the skill words onto the menu
		//	renderWindow.draw(_visibleObjectManager.move1NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move2NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move3NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move4NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move5NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move6NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move7NamePlayer1);
		//	renderWindow.draw(_visibleObjectManager.move8NamePlayer1);
		//	renderWindow.draw(indicator);



		//}


		//creates a vector that holds the mouses position
		sf::Vector2f mousePos = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));

		//sets up a clickable response
		sf::FloatRect boundsp1s1 = _visibleObjectManager.SkillMenuPlayer1Skill1.getGlobalBounds();
		sf::FloatRect boundsp1s2 = _visibleObjectManager.SkillMenuPlayer1Skill2.getGlobalBounds();
		sf::FloatRect boundsp1s3 = _visibleObjectManager.SkillMenuPlayer1Skill3.getGlobalBounds();
		sf::FloatRect boundsp1s4 = _visibleObjectManager.SkillMenuPlayer1Skill4.getGlobalBounds();
		sf::FloatRect boundsp1s5 = _visibleObjectManager.SkillMenuPlayer1Skill5.getGlobalBounds();
		sf::FloatRect boundsp1s6 = _visibleObjectManager.SkillMenuPlayer1Skill6.getGlobalBounds();
		sf::FloatRect boundsp1s7 = _visibleObjectManager.SkillMenuPlayer1Skill7.getGlobalBounds();
		sf::FloatRect boundsp1s8 = _visibleObjectManager.SkillMenuPlayer1Skill8.getGlobalBounds();


		//renderWindow.pollEvent(event);


		if ((boundsp1s1.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 0))
		{
			_audioManager.playButtonClick(1);
			playerA->playerBoneCrusherChoice = playerB->getAbility1();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility1();
			playerA->appliedDebuff = "Bone Crusher(1)";
		}


		if ((boundsp1s2.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 1))
		{
			_audioManager.playButtonClick(1);
			playerA->playerBoneCrusherChoice = playerB->getAbility2();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility2();
			playerA->appliedDebuff = "Bone Crusher(2)";
		}

		if ((boundsp1s3.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 3))
		{
			_audioManager.playButtonClick(1);
			playerA->playerBoneCrusherChoice = playerB->getAbility3();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility3();
			playerA->appliedDebuff = "Bone Crusher(3)";
		}
		if ((boundsp1s4.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 2))
		{
			_audioManager.playButtonClick(1);
			playerA->playerBoneCrusherChoice = playerB->getAbility4();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility4();
			playerA->appliedDebuff = "Bone Crusher(4)";
		}
		if ((boundsp1s5.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 4))
		{
			_audioManager.playButtonClick(1);
			playerA->playerBoneCrusherChoice = playerB->getAbility5();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility5();
			playerA->appliedDebuff = "Bone Crusher(5)";
		}
		if ((boundsp1s6.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(0, 5))
		{
			_audioManager.playButtonClick(1);
			playerA->playerBoneCrusherChoice = playerB->getAbility6();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility6();
			playerA->appliedDebuff = "Bone Crusher(6)";
		}
		if ((boundsp1s7.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || leftTriggerPlayer1)
		{
			_audioManager.playButtonClick(1);
			playerA->playerBoneCrusherChoice = playerB->getAbility7();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility7();
			playerA->appliedDebuff = "Bone Crusher(7)";
		}
		if ((boundsp1s8.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || rightTriggerPlayer1)
		{
			_audioManager.playButtonClick(1);
			playerA->playerBoneCrusherChoice = playerB->getAbility8();
			playerA->playerPicked = true;
			playerA->name = playerA->name + " - " + playerB->getAbility8();
			playerA->appliedDebuff = "Bone Crusher(8)";
		}




	}



	////player 2///////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	if (playerB->name == "Bone Crusher")
	{

		//sets the names for the 8 moves that will be shown
		_visibleObjectManager.move1NamePlayer2.setString(playerA->getAbility1());
		_visibleObjectManager.move2NamePlayer2.setString(playerA->getAbility2());
		_visibleObjectManager.move3NamePlayer2.setString(playerA->getAbility3());
		_visibleObjectManager.move4NamePlayer2.setString(playerA->getAbility4());
		_visibleObjectManager.move5NamePlayer2.setString(playerA->getAbility5());
		_visibleObjectManager.move6NamePlayer2.setString(playerA->getAbility6());
		_visibleObjectManager.move7NamePlayer2.setString(playerA->getAbility7());
		_visibleObjectManager.move8NamePlayer2.setString(playerA->getAbility8());








		//creates 9 texts containers
		sf::Text indicator;

		//sets the font to the containers
		indicator.setFont(_visibleObjectManager.font);


		// sets the strings to display
		indicator.setString("Guess Opponents Move");

		// set the character size
		indicator.setCharacterSize(60);




		//// set the color
		indicator.setColor(sf::Color::White);

		//// set the text style
		indicator.setStyle(sf::Text::Bold);

		//sets the positions
		indicator.setPosition(1250, 400);

		////shows the skills only if player hasn't picked yet
		//if(playerB->playerPicked == false)
		//{
		//	//draws the skill words onto the menu
		//	renderWindow.draw(_visibleObjectManager.move1NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move2NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move3NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move4NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move5NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move6NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move7NamePlayer2);
		//	renderWindow.draw(_visibleObjectManager.move8NamePlayer2);
		//	renderWindow.draw(indicator);



		//}


		//creates a vector that holds the mouses position
		sf::Vector2f mousePos = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));

		//sets up a clickable response
		sf::FloatRect boundsp2s1 = _visibleObjectManager.SkillMenuPlayer2Skill1.getGlobalBounds();
		sf::FloatRect boundsp2s2 = _visibleObjectManager.SkillMenuPlayer2Skill2.getGlobalBounds();
		sf::FloatRect boundsp2s3 = _visibleObjectManager.SkillMenuPlayer2Skill3.getGlobalBounds();
		sf::FloatRect boundsp2s4 = _visibleObjectManager.SkillMenuPlayer2Skill4.getGlobalBounds();
		sf::FloatRect boundsp2s5 = _visibleObjectManager.SkillMenuPlayer2Skill5.getGlobalBounds();
		sf::FloatRect boundsp2s6 = _visibleObjectManager.SkillMenuPlayer2Skill6.getGlobalBounds();
		sf::FloatRect boundsp2s7 = _visibleObjectManager.SkillMenuPlayer2Skill7.getGlobalBounds();
		sf::FloatRect boundsp2s8 = _visibleObjectManager.SkillMenuPlayer2Skill8.getGlobalBounds();


		//renderWindow.pollEvent(event);


		if ((boundsp2s1.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 0))
		{
			_audioManager.playButtonClick(1);
			playerB->playerBoneCrusherChoice = playerA->getAbility1();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility1();
			playerB->appliedDebuff = "Bone Crusher(1)";
		}


		if ((boundsp2s2.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 1))
		{
			_audioManager.playButtonClick(1);
			playerB->playerBoneCrusherChoice = playerA->getAbility2();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility2();
			playerB->appliedDebuff = "Bone Crusher(2)";
		}

		if ((boundsp2s3.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 3))
		{
			_audioManager.playButtonClick(1);
			playerB->playerBoneCrusherChoice = playerA->getAbility3();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility3();
			playerB->appliedDebuff = "Bone Crusher(3)";
		}
		if ((boundsp2s4.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 2))
		{
			_audioManager.playButtonClick(1);
			playerB->playerBoneCrusherChoice = playerA->getAbility4();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility4();
			playerB->appliedDebuff = "Bone Crusher(4)";
		}
		if ((boundsp2s5.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 4))
		{
			_audioManager.playButtonClick(1);
			playerB->playerBoneCrusherChoice = playerA->getAbility5();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility5();
			playerB->appliedDebuff = "Bone Crusher(5)";
		}
		if ((boundsp2s6.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || sf::Joystick::isButtonPressed(1, 5))
		{
			_audioManager.playButtonClick(1);
			playerB->playerBoneCrusherChoice = playerA->getAbility6();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility6();
			playerB->appliedDebuff = "Bone Crusher(6)";
		}
		if ((boundsp2s7.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || leftTriggerPlayer2)
		{
			_audioManager.playButtonClick(1);
			playerB->playerBoneCrusherChoice = playerA->getAbility7();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility7();
			playerB->appliedDebuff = "Bone Crusher(7)";
		}
		if ((boundsp2s8.contains(mousePos) && event.type == sf::Event::MouseButtonReleased) || rightTriggerPlayer2)
		{
			_audioManager.playButtonClick(1);
			playerB->playerBoneCrusherChoice = playerA->getAbility8();
			playerB->playerPicked = true;
			playerB->name = playerB->name + " - " + playerA->getAbility8();
			playerB->appliedDebuff = "Bone Crusher(8)";
		}




	}

}

//handles if one player attacks faster than another
void Battle::attackOrder(Player * playerA, Player  * playerB, sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager)
{


	int moveTime = (int)(playerB->playerSkillTime.asSeconds() - _gameObjectManager.clock.getElapsedTime().asSeconds());
	if (moveTime <= 0)
	{

		//when the faster player is using a debuff
		if (playerA->state == "debuff")
		{
			//applies debuff to player B
			playerActiveDebuffs(playerA, playerB);

			//applies debuff to player A
			playerActiveDebuffs(playerB, playerA);

			//player A gets poisoned of condition met
			applyPoison(playerB, playerA);

			//if player B has a move that does dmg then it will hurt player A
			playerA->setHp(playerA->getHp() - (playerB->damage - (playerB->damage * playerA->reductionPercent)));

			//both players get to buff
			playerActiveBuffs(playerA);
			playerActiveBuffs(playerB);

			//tells game who won the encounter
			playerA->playerMoveWasSuccessful = true;
			playerB->playerMoveWasSuccessful = true;

		}

		else if (playerA->state == "buff")
		{
			//sets fury damage
			playerA->furyDamage = playerB->damage;

			//accounts for fireskin/fire aura
			if (playerA->playerBuff == "Fire Aura" || playerA->playerSecondBuff == "Fire Aura" || playerA->playerThirdBuff == "Fire Aura")
			{
				playerB->setHp(playerB->getHp() -
					(20 - (20 * playerB->reductionPercent)));
			}
			else if (playerA->playerBuff == "Fire Skin" || playerA->playerSecondBuff == "Fire Skin" || playerA->playerThirdBuff == "Fire Skin")
			{
				playerB->setHp(playerB->getHp() -
					(20 - (20 * playerB->reductionPercent)));
			}

			playerA->setHp(playerA->getHp() - (playerB->damage - (playerB->damage *
				playerA->reductionPercent)));


			//player A gets poisoned if condition met
			applyPoison(playerB, playerA);

			playerActiveBuffs(playerB);
			playerActiveBuffs(playerA);
			playerActiveDebuffs(playerB, playerA);
			playerActiveDebuffs(playerA, playerB);

			playerA->playerMoveWasSuccessful = true;
			playerB->playerMoveWasSuccessful = true;
		}

		//accounts for when faster player blocks a move that can't be blocked
		else if (playerA->state == "block"  &&  playerB->unblockable == true)
		{

			//sets fury damage
			playerA->furyDamage = playerB->damage;

			//accounts for fireskin/fire aura
			if (playerA->playerBuff == "Fire Aura" || playerA->playerSecondBuff == "Fire Aura" || playerA->playerThirdBuff == "Fire Aura")
			{
				playerB->setHp(playerB->getHp() -
					(20 - (20 * playerB->reductionPercent)));
			}
			else if (playerA->playerBuff == "Fire Skin" || playerA->playerSecondBuff == "Fire Skin" || playerA->playerThirdBuff == "Fire Skin")
			{
				playerB->setHp(playerB->getHp() -
					(20 - (20 * playerB->reductionPercent)));
			}


			//player A gets poisoned if condition met
			applyPoison(playerB, playerA);

			playerActiveDebuffs(playerA, playerB);
			playerActiveDebuffs(playerB, playerA);


			playerA->setHp(playerA->getHp() - playerB->damage);

			playerActiveBuffs(playerB);
			playerActiveBuffs(playerA);


			playerA->playerMoveWasSuccessful = false;
			playerB->playerMoveWasSuccessful = true;
		}

		//accounts for when player A move is a block and will reduce damage by a set percent
		else if (playerA->state == "block")
		{

			//sets fury damage
			playerA->furyDamage = playerB->damage;

			//accounts for fireskin/fire aura
			if (playerA->playerBuff == "Fire Aura" || playerA->playerSecondBuff == "Fire Aura" || playerA->playerThirdBuff == "Fire Aura")
			{
				playerB->setHp(playerB->getHp() -
					(20 - (20 * playerB->reductionPercent)));
			}
			else if (playerA->playerBuff == "Fire Skin" || playerA->playerSecondBuff == "Fire Skin" || playerA->playerThirdBuff == "Fire Skin")
			{
				playerB->setHp(playerB->getHp() -
					(20 - (20 * playerB->reductionPercent)));
			}


			//accounts for player 2 using a debuff that ignores block
			if (playerB->state == "debuff") playerActiveDebuffs(playerA, playerB);

			playerA->setHp(playerA->getHp() - (playerB->damage - (playerB->damage *
				playerA->reductionPercent)));

			playerActiveBuffs(playerB);
			playerActiveBuffs(playerA);

			playerA->playerMoveWasSuccessful = true;
			playerB->playerMoveWasSuccessful = true;
		}


		//accounts for dodge states
		else if (playerA->state == "dodge" || playerB->state == "dodge")
		{
			srand(time(NULL));


			int playerAroll = std::rand() % 100;

			int playerBroll = std::rand() % 100;

			//for when player 1 goes first but his move isn't one that interrupts the opponent
			if (playerA->damage == 0)
			{

				playerActiveBuffs(playerA);
				playerActiveBuffs(playerB);
				playerActiveDebuffs(playerB, playerA);

				//player B gets poisoned if condition met
				applyPoison(playerA, playerB);

				//for when player 1 goes first but fails to dodge player 2
				if (playerAroll > playerA->dodgeChance)
				{
					//sets fury damage
					playerA->furyDamage = playerB->damage;

					//accounts for fireskin/fire aura
					if (playerA->playerBuff == "Fire Aura" || playerA->playerSecondBuff == "Fire Aura" || playerA->playerThirdBuff == "Fire Aura")
					{
						playerB->setHp(playerB->getHp() -
							(20 - (20 * playerB->reductionPercent)));
					}
					else if (playerA->playerBuff == "Fire Skin" || playerA->playerSecondBuff == "Fire Skin" || playerA->playerThirdBuff == "Fire Skin")
					{
						playerB->setHp(playerB->getHp() -
							(20 - (20 * playerB->reductionPercent)));
					}


					//player A gets poisoned if condition met
					applyPoison(playerB, playerA);

					playerA->setHp(playerA->getHp() - playerB->damage);
					playerActiveDebuffs(playerA, playerB);

					playerA->playerMoveWasSuccessful = false;
					playerB->playerMoveWasSuccessful = true;
				}
				else
				{
					playerA->dodged = true;

					playerA->playerMoveWasSuccessful = true;
					playerB->playerMoveWasSuccessful = true;
				}

			}

			//for when player A has a move that can interrupt
			else
			{
				//for when player A goes first and player B fails to dodge
				if (playerBroll > playerB->dodgeChance)
				{
					//sets fury damage
					playerB->furyDamage = playerA->damage;

					//accounts for fireskin/fire aura
					if (playerB->playerBuff == "Fire Aura" || playerB->playerSecondBuff == "Fire Aura" || playerB->playerThirdBuff == "Fire Aura")
					{
						playerA->setHp(playerA->getHp() -
							(20 - (20 * playerA->reductionPercent)));
					}
					else if (playerB->playerBuff == "Fire Skin" || playerB->playerSecondBuff == "Fire Skin" || playerB->playerThirdBuff == "Fire Skin")
					{
						playerA->setHp(playerA->getHp() -
							(20 - (20 * playerA->reductionPercent)));
					}

					playerB->setHp(playerB->getHp() - playerA->damage);

					playerA->playerMoveWasSuccessful = true;
					playerB->playerMoveWasSuccessful = false;

					//player B gets poisoned if condition met
					applyPoison(playerA, playerB);

					playerActiveBuffs(playerA);
					playerActiveDebuffs(playerB, playerA);
				}
				//for when player 1 goes first but player 2 dodged sucessfully
				else if (playerBroll < playerB->dodgeChance)
				{
					playerB->dodged = true;

					//for when player 1 went first, failed to hit, and then failed to dodge player 2s attack
					if (playerAroll > playerA->dodgeChance)
					{
						//sets fury damage
						playerA->furyDamage = playerB->damage;

						//accounts for fireskin/fire aura
						if (playerA->playerBuff == "Fire Aura" || playerA->playerSecondBuff == "Fire Aura" || playerA->playerThirdBuff == "Fire Aura")
						{
							playerB->setHp(playerB->getHp() -
								(20 - (20 * playerB->reductionPercent)));
						}
						else if (playerA->playerBuff == "Fire Skin" || playerA->playerSecondBuff == "Fire Skin" || playerA->playerThirdBuff == "Fire Skin")
						{
							playerB->setHp(playerB->getHp() -
								(20 - (20 * playerB->reductionPercent)));
						}

						playerA->setHp(playerA->getHp() - playerB->damage);
						playerActiveDebuffs(playerA, playerB);
						playerActiveBuffs(playerB);

						//player A gets poisoned if condition met
						applyPoison(playerB, playerA);

						playerA->playerMoveWasSuccessful = true;
						playerB->playerMoveWasSuccessful = true;
					}
					else
					{
						playerA->dodged = true;

						playerA->playerMoveWasSuccessful = true;
						playerB->playerMoveWasSuccessful = true;
					}
				}

			}
		}

		else if ((playerA->state == "attack") && (playerB->uninterruptable == true))
		{


			//player B gets poisoned if condition met
			applyPoison(playerA, playerB);

			//player A gets poisoned if condition met
			applyPoison(playerB, playerA);

			//sets fury damage
			playerA->furyDamage = playerB->damage;

			//sets fury damage
			playerB->furyDamage = playerA->damage;

			//accounts for fireskin/fire aura player1
			if (playerA->playerBuff == "Fire Aura" || playerA->playerSecondBuff == "Fire Aura" || playerA->playerThirdBuff == "Fire Aura")
			{
				playerB->setHp(playerB->getHp() -
					(20 - (20 * playerB->reductionPercent)));
			}
			else if (playerA->playerBuff == "Fire Skin" || playerA->playerSecondBuff == "Fire Skin" || playerA->playerThirdBuff == "Fire Skin")
			{
				playerB->setHp(playerB->getHp() -
					(20 - (20 * playerB->reductionPercent)));
			}

			//accounts for fireskin/fire aura player2
			if (playerB->playerBuff == "Fire Aura" || playerB->playerSecondBuff == "Fire Aura" || playerB->playerThirdBuff == "Fire Aura")
			{
				playerA->setHp(playerA->getHp() -
					(20 - (20 * playerA->reductionPercent)));
			}
			else if (playerB->playerBuff == "Fire Skin" || playerB->playerSecondBuff == "Fire Skin" || playerB->playerThirdBuff == "Fire Skin")
			{
				playerA->setHp(playerA->getHp() -
					(20 - (20 * playerA->reductionPercent)));
			}

			playerB->setHp(playerB->getHp() - (playerA->damage - (playerA->damage * playerB->reductionPercent)));
			playerA->setHp(playerA->getHp() - (playerB->damage - (playerB->damage * playerA->reductionPercent)));

			playerActiveBuffs(playerA);
			playerActiveDebuffs(playerA, playerB);
			playerActiveBuffs(playerB);
			playerActiveDebuffs(playerB, playerA);

			if(playerA->playerSkillTime > playerB->playerSkillTime) playerA->playerMoveWasSuccessful = false;
			else  playerA->playerMoveWasSuccessful = true;
			playerB->playerMoveWasSuccessful = true;

		}

		//accounts for when player attacks normally
		else if (playerA->state == "attack")
		{
			//sets fury damage
			playerB->furyDamage = playerA->damage;

			//accounts for fireskin/fire aura player2
			if (playerB->playerBuff == "Fire Aura" || playerB->playerSecondBuff == "Fire Aura" || playerB->playerThirdBuff == "Fire Aura")
			{
				playerA->setHp(playerA->getHp() -
					(20 - (20 * playerA->reductionPercent)));
			}
			else if (playerB->playerBuff == "Fire Skin" || playerB->playerSecondBuff == "Fire Skin" || playerB->playerThirdBuff == "Fire Skin")
			{
				playerA->setHp(playerA->getHp() -
					(20 - (20 * playerA->reductionPercent)));
			}

			//player B gets poisoned if condition met
			applyPoison(playerA, playerB);

			playerB->setHp(playerB->getHp() - playerA->damage);

			playerA->playerMoveWasSuccessful = true;
			playerB->playerMoveWasSuccessful = false;

			playerActiveBuffs(playerA);
			playerActiveDebuffs(playerB, playerA);
		}




	}

}


//handles the attack operation in full
void Battle::startTurn(sf::RenderWindow & renderWindow, GameObjectManager & _gameObjectManager, AudioManager & _audioManager)
{

	warriorFunction(_gameObjectManager, _gameObjectManager.player1, _gameObjectManager.player2, _audioManager);

	//handles the specific changes for assassins moves
	assassinFunction(_gameObjectManager, _gameObjectManager.player1, _gameObjectManager.player2);

	monkFunction(_gameObjectManager, _gameObjectManager.player1, _gameObjectManager.player2);

	necroFunction(_gameObjectManager, _gameObjectManager.player1, _gameObjectManager.player2);

	demonFunction(_gameObjectManager, _gameObjectManager.player1, _gameObjectManager.player2);



	//for when player 1 picked a move but player 2 failed to do so
	if (_gameObjectManager.player1->playerPicked == true && _gameObjectManager.player2->playerPicked == false)
	{
		//tells game who won the encounter
		_gameObjectManager.player1->playerMoveWasSuccessful = true;
		_gameObjectManager.player2->playerMoveWasSuccessful = false;

		//accounts for fireskin/fire aura player2
		if (_gameObjectManager.player2->playerBuff == "Fire Aura" || _gameObjectManager.player2->playerSecondBuff == "Fire Aura" || _gameObjectManager.player2->playerThirdBuff == "Fire Aura")
		{
			_gameObjectManager.player1->setHp(_gameObjectManager.player1->getHp() -
				(20 - (20 * _gameObjectManager.player1->reductionPercent)));
		}
		else if (_gameObjectManager.player2->playerBuff == "Fire Skin" || _gameObjectManager.player2->playerSecondBuff == "Fire Skin" || _gameObjectManager.player2->playerThirdBuff == "Fire Skin")
		{
			_gameObjectManager.player1->setHp(_gameObjectManager.player1->getHp() -
				(20 - (20 * _gameObjectManager.player1->reductionPercent)));
		}


		// if the move deals damage to the opponent this formula handles it
		_gameObjectManager.player2->setHp(_gameObjectManager.player2->getHp() - (_gameObjectManager.player1->damage - (_gameObjectManager.player1->damage * _gameObjectManager.player2->reductionPercent)));

		//if move gives player 1 a buff, this function adds it
		playerActiveBuffs(_gameObjectManager.player1);

		//if move gives player 2 a debuff, this function adds it
		playerActiveDebuffs(_gameObjectManager.player2, _gameObjectManager.player1);


	}
	//for when player 2 picked a move but player 1 failed to do so
	else if (_gameObjectManager.player1->playerPicked == false && _gameObjectManager.player2->playerPicked == true)
	{
		//tells game who won the encounter
		_gameObjectManager.player1->playerMoveWasSuccessful = false;
		_gameObjectManager.player2->playerMoveWasSuccessful = true;


		//tells game who won the encounter
		_gameObjectManager.playerAttackSuccessful = 2;

		//player 1 gets poisoned of condition met
		applyPoison(_gameObjectManager.player2, _gameObjectManager.player1);



		//accounts for fireskin/fire aura player2
		if (_gameObjectManager.player1->playerBuff == "Fire Aura" || _gameObjectManager.player1->playerSecondBuff == "Fire Aura" || _gameObjectManager.player1->playerThirdBuff == "Fire Aura")
		{
			_gameObjectManager.player2->setHp(_gameObjectManager.player2->getHp() -
				(20 - (20 * _gameObjectManager.player2->reductionPercent)));
		}
		else if (_gameObjectManager.player1->playerBuff == "Fire Skin" || _gameObjectManager.player1->playerSecondBuff == "Fire Skin" || _gameObjectManager.player1->playerThirdBuff == "Fire Skin")
		{
			_gameObjectManager.player2->setHp(_gameObjectManager.player2->getHp() -
				(20 - (20 * _gameObjectManager.player2->reductionPercent)));
		}


		// if the move deals damage to the opponent this formula handles it
		_gameObjectManager.player1->setHp(_gameObjectManager.player1->getHp() - (_gameObjectManager.player2->damage - (_gameObjectManager.player2->damage * _gameObjectManager.player1->reductionPercent)));

		//if move gives player 2 a buff, this function adds it
		playerActiveBuffs(_gameObjectManager.player2);

		//if move gives player 1 a debuff, this function adds it
		playerActiveDebuffs(_gameObjectManager.player1, _gameObjectManager.player2);

		
	}

	else
	{
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//when player 1 uses the quicker move
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (_gameObjectManager.player1->time < _gameObjectManager.player2->time)
		{
			//tells game who won the encounter
			_gameObjectManager.playerAttackSuccessful = 1;
			attackOrder(_gameObjectManager.player1, _gameObjectManager.player2, renderWindow, _gameObjectManager);
		}



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//when player 2 uses the quicker move
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (_gameObjectManager.player2->time < _gameObjectManager.player1->time)
		{
			//tells game who won the encounter
			_gameObjectManager.playerAttackSuccessful = 2;

			attackOrder(_gameObjectManager.player2, _gameObjectManager.player1, renderWindow, _gameObjectManager);
		}


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//when the players move times are the same
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (_gameObjectManager.player1->time == _gameObjectManager.player2->time)
		{
			//tells game who won the encounter
			_gameObjectManager.playerAttackSuccessful = 4;

			//player A gets poisoned of condition met
			applyPoison(_gameObjectManager.player2, _gameObjectManager.player1);



			//player B gets poisoned of condition met
			applyPoison(_gameObjectManager.player1, _gameObjectManager.player2);

			//accounts for fireskin/fire aura player
			if (_gameObjectManager.player2->playerBuff == "Fire Aura" || _gameObjectManager.player2->playerSecondBuff == "Fire Aura" || _gameObjectManager.player2->playerThirdBuff == "Fire Aura")
			{
				_gameObjectManager.player1->setHp(_gameObjectManager.player1->getHp() -
					(20 - (20 * _gameObjectManager.player1->reductionPercent)));
			}
			else if (_gameObjectManager.player2->playerBuff == "Fire Skin" || _gameObjectManager.player2->playerSecondBuff == "Fire Skin" || _gameObjectManager.player2->playerThirdBuff == "Fire Skin")
			{
				_gameObjectManager.player1->setHp(_gameObjectManager.player1->getHp() -
					(20 - (20 * _gameObjectManager.player1->reductionPercent)));
			}

			//accounts for fireskin/fire aura player
			if (_gameObjectManager.player1->playerBuff == "Fire Aura" || _gameObjectManager.player1->playerSecondBuff == "Fire Aura" || _gameObjectManager.player1->playerThirdBuff == "Fire Aura")
			{
				_gameObjectManager.player2->setHp(_gameObjectManager.player2->getHp() -
					(20 - (20 * _gameObjectManager.player2->reductionPercent)));
			}
			else if (_gameObjectManager.player1->playerBuff == "Fire Skin" || _gameObjectManager.player1->playerSecondBuff == "Fire Skin" || _gameObjectManager.player1->playerThirdBuff == "Fire Skin")
			{
				_gameObjectManager.player2->setHp(_gameObjectManager.player2->getHp() -
					(20 - (20 * _gameObjectManager.player2->reductionPercent)));
			}


			//checks to see if player 2 does damage
			if (_gameObjectManager.player2->damage > 0)
			{
				//sets fury damage
				_gameObjectManager.player1->furyDamage = _gameObjectManager.player2->damage;

				//lowers player 1s hp
				_gameObjectManager.player1->setHp(
					_gameObjectManager.player1->getHp() -
					(_gameObjectManager.player2->damage -
					(_gameObjectManager.player2->damage *
						_gameObjectManager.player1->reductionPercent)));
			}

			if (_gameObjectManager.player1->damage > 0)
			{
				//sets fury damage
				_gameObjectManager.player2->furyDamage = _gameObjectManager.player1->damage;


				//lowers player 2s hp
				_gameObjectManager.player2->setHp(
					_gameObjectManager.player2->getHp() -
					(_gameObjectManager.player1->damage -
					(_gameObjectManager.player1->damage *
						_gameObjectManager.player2->reductionPercent)));
			}

			playerActiveBuffs(_gameObjectManager.player1);
			playerActiveBuffs(_gameObjectManager.player2);

			playerActiveDebuffs(_gameObjectManager.player1, _gameObjectManager.player2);
			playerActiveDebuffs(_gameObjectManager.player2, _gameObjectManager.player1);

			_gameObjectManager.setTurnOperation(false);





		}


	}




	//handles who gets interrupted visually

		//when player1 interrupted player2
	if (_gameObjectManager.player1->playerMoveWasSuccessful && !_gameObjectManager.player2->playerMoveWasSuccessful) _gameObjectManager.playerAttackSuccessful = 1;
	//when player2 interrupted player1
	else if (!_gameObjectManager.player1->playerMoveWasSuccessful && _gameObjectManager.player2->playerMoveWasSuccessful) _gameObjectManager.playerAttackSuccessful = 2;
	//when neither player gets stopped
	else if (_gameObjectManager.player1->playerMoveWasSuccessful && _gameObjectManager.player2->playerMoveWasSuccessful) _gameObjectManager.playerAttackSuccessful = 0;
	//when both players gets a hurt animation
	else if (!_gameObjectManager.player1->playerMoveWasSuccessful && !_gameObjectManager.player2->playerMoveWasSuccessful) _gameObjectManager.playerAttackSuccessful = 3;
}


//handles every event and trigger that updates at the end of turn
void Battle::endTurn(VisibleObjectManager & _visibleObjectManager, Multiplayer & _multiplayer, Player * playerA, Player * playerB)
{

	//resets animation counter
	_visibleObjectManager.player1CurrentAnimationFrame = 1;
	_visibleObjectManager.player2CurrentAnimationFrame = 1;




	_multiplayer.buffer[0] = ' ';





	//handles soul meter gain 
	if (playerA->playerBuff == "soulMeter20" || playerA->playerSecondBuff == "soulMeter20" || playerA->playerThirdBuff == "soulMeter20")
	{
		playerA->necroMeter += 20;
		if (playerA->necroMeter > 40) playerA->necroMeter = 40;
	}
	else if (playerA->playerBuff == "soulMeter40" || playerA->playerSecondBuff == "soulMeter40" || playerA->playerThirdBuff == "soulMeter40") playerA->necroMeter = 40;

	//handles soul meter gain 
	if (playerB->playerBuff == "soulMeter20" || playerB->playerSecondBuff == "soulMeter20" || playerB->playerThirdBuff == "soulMeter20")
	{
		playerB->necroMeter += 20;
		if (playerB->necroMeter > 40) playerB->necroMeter = 40;
	}
	else if (playerB->playerBuff == "soulMeter40" || playerB->playerSecondBuff == "soulMeter40" || playerB->playerThirdBuff == "soulMeter40") playerB->necroMeter = 40;

	//emptys meter from moves that use it
	if (playerA->playerBuff == "emptySoulMeter" || playerA->playerSecondBuff == "emptySoulMeter" || playerA->playerThirdBuff == "emptySoulMeter") playerA->necroMeter = 0;
	if (playerB->playerBuff == "emptySoulMeter" || playerB->playerSecondBuff == "emptySoulMeter" || playerB->playerThirdBuff == "emptySoulMeter") playerB->necroMeter = 0;

	//player 1 necro heal
	if (playerA->playerBuff == "gainHp" || playerA->playerSecondBuff == "gainHp" || playerA->playerThirdBuff == "gainHp")
	{
		playerA->setHp(playerA->getHp() + playerA->necroMeter);
		playerA->necroMeter = 0;
		if (playerA->getHp() > playerA->getTotalHp()) playerA->setHp(playerA->getTotalHp());

		//removes the buff after the heal went through
		if (playerA->playerBuff == "gainHp") playerA->playerBuff == "";
		if (playerA->playerSecondBuff == "gainHp") playerA->playerSecondBuff == "";
		if (playerA->playerThirdBuff == "gainHp") playerA->playerThirdBuff == "";
	}
	else if (playerA->playerBuff == "gainHpEnhanced" || playerA->playerSecondBuff == "gainHpEnhanced" || playerA->playerThirdBuff == "gainHpEnhanced")
	{
		playerA->setHp(playerA->getHp() + playerA->necroMeter);
		if (playerA->getHp() > playerA->getTotalHp()) playerA->setHp(playerA->getTotalHp());

		//removes the buff after the heal went through
		if (playerA->playerBuff == "gainHpEnhanced") playerA->playerBuff == "";
		if (playerA->playerSecondBuff == "gainHpEnhanced") playerA->playerSecondBuff == "";
		if (playerA->playerThirdBuff == "gainHpEnhanced") playerA->playerThirdBuff == "";
	}

	//player 2 necro heal
	if (playerB->playerBuff == "gainHP" || playerB->playerSecondBuff == "gainHp" || playerB->playerThirdBuff == "gainHP")
	{
		playerB->setHp(playerB->getHp() + playerB->necroMeter);
		playerB->necroMeter = 0;
		if (playerB->getHp() > playerB->getTotalHp()) playerB->setHp(playerB->getTotalHp());

		if (playerB->playerBuff == "gainHp") playerB->playerBuff == "";
		if (playerB->playerSecondBuff == "gainHp") playerB->playerSecondBuff == "";
		if (playerB->playerThirdBuff == "gainHp") playerB->playerThirdBuff == "";
	}
	else if (playerB->playerBuff == "gainHPEnhanced" || playerB->playerSecondBuff == "gainHPEnhanced" || playerB->playerThirdBuff == "gainHPEnhanced")
	{
		playerB->setHp(playerB->getHp() + playerB->necroMeter);
		if (playerB->getHp() > playerB->getTotalHp()) playerB->setHp(playerB->getTotalHp());
		if (playerB->playerBuff == "gainHPEnhanced") playerB->playerBuff == "";
		if (playerB->playerSecondBuff == "gainHPEnhanced") playerB->playerSecondBuff == "";
		if (playerB->playerThirdBuff == "gainHPEnhanced") playerB->playerThirdBuff == "";
	}



	//applies poison damage at the end of turn
	if (playerA->playerDebuff == "poison") playerA->setHp(playerA->getHp() - 10);
	else if (playerA->playerSecondDebuff == "poison") playerA->setHp(playerA->getHp() - 10);
	else if (playerA->playerThirdDebuff == "poison") playerA->setHp(playerA->getHp() - 10);

	if (playerB->playerDebuff == "poison") playerB->setHp(playerB->getHp() - 10);
	else if (playerB->playerSecondDebuff == "poison") playerB->setHp(playerB->getHp() - 10);
	else if (playerB->playerThirdDebuff == "poison") playerB->setHp(playerB->getHp() - 10);

	//applies poison damage at the end of turn
	if (playerA->playerDebuff == "deadly poison") playerA->setHp(playerA->getHp() - 15);
	else if (playerA->playerSecondDebuff == "deadly poison") playerA->setHp(playerA->getHp() - 15);
	else if (playerA->playerThirdDebuff == "deadly poison") playerA->setHp(playerA->getHp() - 15);

	if (playerB->playerDebuff == "deadly poison") playerB->setHp(playerB->getHp() - 15);
	else if (playerB->playerSecondDebuff == "deadly poison") playerB->setHp(playerB->getHp() - 15);
	else if (playerB->playerThirdDebuff == "deadly poison") playerB->setHp(playerB->getHp() - 15);

	/////////////////////////////////////
	//handles Bone Crusher debuff player 1
	if (playerA->playerDebuff == "Bone Crusher(1)" || playerA->playerSecondDebuff == "Bone Crusher(1)" || playerA->playerThirdDebuff == "Bone Crusher(1)") { playerA->playerMove1CD += 3; playerA->playerMove1Used = true; }
	else if (playerA->playerDebuff == "Bone Crusher(2)" || playerA->playerSecondDebuff == "Bone Crusher(2)" || playerA->playerThirdDebuff == "Bone Crusher(2)") { playerA->playerMove2CD += 3; playerA->playerMove2Used = true; }
	else if (playerA->playerDebuff == "Bone Crusher(3)" || playerA->playerSecondDebuff == "Bone Crusher(3)" || playerA->playerThirdDebuff == "Bone Crusher(3)") { playerA->playerMove3CD += 3; playerA->playerMove3Used = true; }
	else if (playerA->playerDebuff == "Bone Crusher(4)" || playerA->playerSecondDebuff == "Bone Crusher(4)" || playerA->playerThirdDebuff == "Bone Crusher(4)") { playerA->playerMove4CD += 3; playerA->playerMove4Used = true; }
	else if (playerA->playerDebuff == "Bone Crusher(5)" || playerA->playerSecondDebuff == "Bone Crusher(5)" || playerA->playerThirdDebuff == "Bone Crusher(5)") { playerA->playerMove5CD += 3; playerA->playerMove5Used = true; }
	else if (playerA->playerDebuff == "Bone Crusher(6)" || playerA->playerSecondDebuff == "Bone Crusher(6)" || playerA->playerThirdDebuff == "Bone Crusher(6)") { playerA->playerMove6CD += 3; playerA->playerMove6Used = true; }
	else if (playerA->playerDebuff == "Bone Crusher(7)" || playerA->playerSecondDebuff == "Bone Crusher(7)" || playerA->playerThirdDebuff == "Bone Crusher(7)") { playerA->playerMove7CD += 3; playerA->playerMove7Used = true; }
	else if (playerA->playerDebuff == "Bone Crusher(8)" || playerA->playerSecondDebuff == "Bone Crusher(8)" || playerA->playerThirdDebuff == "Bone Crusher(8)") { playerA->playerMove8CD += 3; playerA->playerMove8Used = true; }

	//handles Bone Crusher debuff player 2
	if (playerB->playerDebuff == "Bone Crusher(1)" || playerB->playerSecondDebuff == "Bone Crusher(1)" || playerB->playerThirdDebuff == "Bone Crusher(1)") { playerB->playerMove1CD += 3; playerB->playerMove1Used = true; }
	else if (playerB->playerDebuff == "Bone Crusher(2)" || playerB->playerSecondDebuff == "Bone Crusher(2)" || playerB->playerThirdDebuff == "Bone Crusher(2)") { playerB->playerMove2CD += 3; playerB->playerMove2Used = true; }
	else if (playerB->playerDebuff == "Bone Crusher(3)" || playerB->playerSecondDebuff == "Bone Crusher(3)" || playerB->playerThirdDebuff == "Bone Crusher(3)") { playerB->playerMove3CD += 3; playerB->playerMove3Used = true; }
	else if (playerB->playerDebuff == "Bone Crusher(4)" || playerB->playerSecondDebuff == "Bone Crusher(4)" || playerB->playerThirdDebuff == "Bone Crusher(4)") { playerB->playerMove4CD += 3; playerB->playerMove4Used = true; }
	else if (playerB->playerDebuff == "Bone Crusher(5)" || playerB->playerSecondDebuff == "Bone Crusher(5)" || playerB->playerThirdDebuff == "Bone Crusher(5)") { playerB->playerMove5CD += 3; playerB->playerMove5Used = true; }
	else if (playerB->playerDebuff == "Bone Crusher(6)" || playerB->playerSecondDebuff == "Bone Crusher(6)" || playerB->playerThirdDebuff == "Bone Crusher(6)") { playerB->playerMove6CD += 3; playerB->playerMove6Used = true; }
	else if (playerB->playerDebuff == "Bone Crusher(7)" || playerB->playerSecondDebuff == "Bone Crusher(7)" || playerB->playerThirdDebuff == "Bone Crusher(7)") { playerB->playerMove7CD += 3; playerB->playerMove7Used = true; }
	else if (playerB->playerDebuff == "Bone Crusher(8)" || playerB->playerSecondDebuff == "Bone Crusher(8)" || playerB->playerThirdDebuff == "Bone Crusher(8)") { playerB->playerMove8CD += 3; playerB->playerMove8Used = true; }


	playerA->playerBoneCrusherChoice = "";
	playerB->playerBoneCrusherChoice = "";
	////////////////////////////////////




	//accounts for removal of debuffs at the end of the turn
	if (playerA->playerDebuff1Duration == 0) playerA->playerDebuff = "";
	else playerA->playerDebuff1Duration--;

	if (playerA->playerDebuff2Duration == 0) playerA->playerSecondDebuff = "";
	else playerA->playerDebuff2Duration--;

	if (playerA->playerDebuff3Duration == 0) playerA->playerThirdDebuff = "";
	else playerA->playerDebuff3Duration--;

	if (playerB->playerDebuff1Duration == 0) playerB->playerDebuff = "";
	else playerB->playerDebuff1Duration--;

	if (playerB->playerDebuff2Duration == 0) playerB->playerSecondDebuff = "";
	else playerB->playerDebuff2Duration--;

	if (playerB->playerDebuff3Duration == 0) playerB->playerThirdDebuff = "";
	else playerB->playerDebuff3Duration--;

	//accounts for removal of buffs at the end of the turn
	if (playerA->playerBuff1Duration == 0) playerA->playerBuff = "";
	else playerA->playerBuff1Duration--;

	if (playerA->playerBuff2Duration == 0) playerA->playerSecondBuff = "";
	else playerA->playerBuff2Duration--;

	if (playerA->playerBuff3Duration == 0) playerA->playerThirdBuff = "";
	else playerA->playerBuff3Duration--;

	if (playerB->playerBuff1Duration == 0) playerB->playerBuff = "";
	else playerB->playerBuff1Duration--;

	if (playerB->playerBuff2Duration == 0) playerB->playerSecondBuff = "";
	else playerB->playerBuff2Duration--;

	if (playerB->playerBuff3Duration == 0) playerB->playerThirdBuff = "";
	else playerB->playerBuff3Duration--;










	//updates player 1 move 1
	if (playerA->playerMove1Used)
	{

		if (playerA->playerMove1CD == 1)
		{
			playerA->playerMove1Used = false;
		}
		else playerA->playerMove1CD--;
	}

	//updates player 1 move 2
	if (playerA->playerMove2Used)
	{
		if (playerA->playerMove2CD == 1)
		{
			playerA->playerMove2Used = false;
		}
		else playerA->playerMove2CD--;
	}

	//updates player 1 move 3
	if (playerA->playerMove3Used)
	{
		if (playerA->playerMove3CD == 1)
		{
			playerA->playerMove3Used = false;
		}
		else playerA->playerMove3CD--;
	}

	//updates player 1 move 4
	if (playerA->playerMove4Used)
	{
		if (playerA->playerMove4CD == 1)
		{
			playerA->playerMove4Used = false;
		}
		else playerA->playerMove4CD--;
	}

	//updates player 1 move 5
	if (playerA->playerMove5Used)
	{
		if (playerA->playerMove5CD == 1)
		{
			playerA->playerMove5Used = false;
		}
		else playerA->playerMove5CD--;
	}

	//updates player 1 move 6
	if (playerA->playerMove6Used)
	{
		if (playerA->playerMove6CD == 1)
		{
			playerA->playerMove6Used = false;
		}
		else playerA->playerMove6CD--;
	}

	//updates player 1 move 7
	if (playerA->playerMove7Used)
	{
		if (playerA->playerMove7CD == 1)
		{
			playerA->playerMove7Used = false;
		}
		else playerA->playerMove7CD--;
	}

	//updates player 1 move 8
	if (playerA->playerMove8Used)
	{
		if (playerA->playerMove8CD == 1)
		{
			playerA->playerMove8Used = false;
		}
		else playerA->playerMove8CD--;
	}




	//updates player 2 move 1
	if (playerB->playerMove1Used)
	{
		if (playerB->playerMove1CD == 1)
		{
			playerB->playerMove1Used = false;
		}
		else playerB->playerMove1CD--;
	}

	//updates player 2 move 2
	if (playerB->playerMove2Used)
	{
		if (playerB->playerMove2CD == 1)
		{
			playerB->playerMove2Used = false;
		}
		else playerB->playerMove2CD--;
	}

	//updates player 2 move 3
	if (playerB->playerMove3Used)
	{
		if (playerB->playerMove3CD == 1)
		{
			playerB->playerMove3Used = false;
		}
		else playerB->playerMove3CD--;
	}

	//updates player 2 move 4
	if (playerB->playerMove4Used)
	{
		if (playerB->playerMove4CD == 1)
		{
			playerB->playerMove4Used = false;
		}
		else playerB->playerMove4CD--;
	}

	//updates player 2 move 5
	if (playerB->playerMove5Used)
	{
		if (playerB->playerMove5CD == 1)
		{
			playerB->playerMove5Used = false;
		}
		else playerB->playerMove5CD--;
	}

	//updates player 2 move 6
	if (playerB->playerMove6Used)
	{
		if (playerB->playerMove6CD == 1)
		{
			playerB->playerMove6Used = false;
		}
		else playerB->playerMove6CD--;
	}

	//updates player 2 move 7
	if (playerB->playerMove7Used)
	{
		if (playerB->playerMove7CD == 1)
		{
			playerB->playerMove7Used = false;
		}
		else playerB->playerMove7CD--;
	}

	//updates player 2 move 8
	if (playerB->playerMove8Used)
	{
		if (playerB->playerMove8CD == 1)
		{
			playerB->playerMove8Used = false;
		}
		else playerB->playerMove8CD--;
	}



	//handles a check to see if player is stunned
	if (playerA->playerDebuff == "stunned"
		|| playerA->playerSecondDebuff == "stunned" ||
		playerA->playerThirdDebuff == "stunned")
	{
		playerA->setStun(true);
	}
	else playerA->setStun(false);


	//handles a check to see if player is stunned
	if (playerB->playerDebuff == "stunned"
		|| playerB->playerSecondDebuff == "stunned" ||
		playerB->playerThirdDebuff == "stunned")
	{
		playerB->setStun(true);
	}
	else playerB->setStun(false);


	//////////Warrior TAUNT///////
	if (playerA->playerDebuff == "Taunted" || playerA->playerSecondDebuff == "Taunted" || playerA->playerThirdDebuff == "Taunted")
	{
		//handles warrior
		if (playerA->idle == "warriorIdle")
		{
			//power stance gets put on a 1 turn cooldown
			if (playerA->playerMove5Used == false)
			{
				playerA->playerMove5CD = 1;
				playerA->playerMove5Used = true;
			}


			//shout gets put on a 1 turn cooldown
			if (playerA->playerMove6Used == false)
			{
				playerA->playerMove6CD = 1;
				playerA->playerMove6Used = true;
			}

			//block gets put on a 1 turn cooldown
			if (playerA->playerMove7Used == false)
			{
				playerA->playerMove7CD = 1;
				playerA->playerMove7Used = true;
			}

			//Taunt gets put on a 1 turn cooldown
			if (playerA->playerMove8Used == false)
			{
				playerA->playerMove8CD = 1;
				playerA->playerMove8Used = true;
			}
		}
		//handles assassin
		else if (playerA->idle == "assassinIdle")
		{
			//Smoke bomb gets put on a 1 turn cooldown
			if (playerA->playerMove1Used == false)
			{
				playerA->playerMove1CD = 1;
				playerA->playerMove1Used = true;
			}


			//Apply poison gets put on a 1 turn cooldown
			if (playerA->playerMove2Used == false)
			{
				playerA->playerMove2CD = 1;
				playerA->playerMove2Used = true;
			}

			//Dodge gets put on a 1 turn cooldown
			if (playerA->playerMove6Used == false)
			{
				playerA->playerMove6CD = 1;
				playerA->playerMove6Used = true;
			}

		}

		//handles monk
		else if (playerA->idle == "monkIdle")
		{
			//step in gets put on a 1 turn cooldown
			if (playerA->playerMove2Used == false)
			{
				playerA->playerMove2CD = 1;
				playerA->playerMove2Used = true;
			}
			//elbow parry gets put on a 1 turn cooldown
			if (playerA->playerMove5Used == false)
			{
				playerA->playerMove5CD = 1;
				playerA->playerMove5Used = true;
			}

			//inhuman speed gets put on a 1 turn cooldown
			if (playerA->playerMove7Used == false)
			{
				playerA->playerMove7CD = 1;
				playerA->playerMove7Used = true;
			}

			//meditate gets put on a 1 turn cooldown
			if (playerA->playerMove8Used == false)
			{
				playerA->playerMove8CD = 1;
				playerA->playerMove8Used = true;
			}

		}

		//handles necro
		else if (playerA->idle == "necromancerIdle")
		{

			//soul harvest gets put on a 1 turn cooldown
			if (playerA->playerMove3Used == false)
			{
				playerA->playerMove3CD = 1;
				playerA->playerMove3Used = true;
			}


			//bone wall gets put on a 1 turn cooldown
			if (playerA->playerMove4Used == false)
			{
				playerA->playerMove4CD = 1;
				playerA->playerMove4Used = true;
			}

			//deadmans heal gets put on a 1 turn cooldown
			if (playerA->playerMove6Used == false)
			{
				playerA->playerMove6CD = 1;
				playerA->playerMove6Used = true;
			}

			//Decay Aura gets put on a 1 turn cooldown
			if (playerA->playerMove7Used == false)
			{
				playerA->playerMove7CD = 1;
				playerA->playerMove7Used = true;
			}
		}

		//handles demon
		else if (playerA->idle == "demonIdle")
		{

			//enraged gets put on a 1 turn cooldown
			if (playerA->playerMove5Used == false)
			{
				playerA->playerMove5CD = 1;
				playerA->playerMove5Used = true;
			}

			//fireskin gets put on a 1 turn cooldown
			if (playerA->playerMove6Used == false)
			{
				playerA->playerMove6CD = 1;
				playerA->playerMove6Used = true;
			}
		}

	}
	if (playerB->playerDebuff == "Taunted" || playerB->playerSecondDebuff == "Taunted" || playerB->playerThirdDebuff == "Taunted")
	{
		//handles warrior
		if (playerB->idle == "warriorIdle")
		{
			//power stance gets put on a 1 turn cooldown
			if (playerB->playerMove5Used == false)
			{
				playerB->playerMove5CD = 1;
				playerB->playerMove5Used = true;
			}


			//shout gets put on a 1 turn cooldown
			if (playerB->playerMove6Used == false)
			{
				playerB->playerMove6CD = 1;
				playerB->playerMove6Used = true;
			}

			//block gets put on a 1 turn cooldown
			if (playerB->playerMove7Used == false)
			{
				playerB->playerMove7CD = 1;
				playerB->playerMove7Used = true;
			}

			//Taunt gets put on a 1 turn cooldown
			if (playerB->playerMove8Used == false)
			{
				playerB->playerMove8CD = 1;
				playerB->playerMove8Used = true;
			}
		}
		//handles assassin
		else if (playerB->idle == "assassinIdle")
		{
			//Smoke bomb gets put on a 1 turn cooldown
			if (playerB->playerMove1Used == false)
			{
				playerB->playerMove1CD = 1;
				playerB->playerMove1Used = true;
			}


			//Apply poison gets put on a 1 turn cooldown
			if (playerB->playerMove2Used == false)
			{
				playerB->playerMove2CD = 1;
				playerB->playerMove2Used = true;
			}

			//Dodge gets put on a 1 turn cooldown
			if (playerB->playerMove6Used == false)
			{
				playerB->playerMove6CD = 1;
				playerB->playerMove6Used = true;
			}

		}

		//handles monk
		else if (playerB->idle == "monkIdle")
		{
			//step in gets put on a 1 turn cooldown
			if (playerB->playerMove2Used == false)
			{
				playerB->playerMove2CD = 1;
				playerB->playerMove2Used = true;
			}
			//elbow parry gets put on a 1 turn cooldown
			if (playerB->playerMove5Used == false)
			{
				playerB->playerMove5CD = 1;
				playerB->playerMove5Used = true;
			}

			//inhuman speed gets put on a 1 turn cooldown
			if (playerB->playerMove7Used == false)
			{
				playerB->playerMove7CD = 1;
				playerB->playerMove7Used = true;
			}

			//meditate gets put on a 1 turn cooldown
			if (playerB->playerMove8Used == false)
			{
				playerB->playerMove8CD = 1;
				playerB->playerMove8Used = true;
			}

		}

		//handles necro
		else if (playerB->idle == "necromancerIdle")
		{

			//soul harvest gets put on a 1 turn cooldown
			if (playerB->playerMove3Used == false)
			{
				playerB->playerMove3CD = 1;
				playerB->playerMove3Used = true;
			}


			//bone wall gets put on a 1 turn cooldown
			if (playerB->playerMove4Used == false)
			{
				playerB->playerMove4CD = 1;
				playerB->playerMove4Used = true;
			}

			//deadmans heal gets put on a 1 turn cooldown
			if (playerB->playerMove6Used == false)
			{
				playerB->playerMove6CD = 1;
				playerB->playerMove6Used = true;
			}

			//Decay Aura gets put on a 1 turn cooldown
			if (playerB->playerMove7Used == false)
			{
				playerB->playerMove7CD = 1;
				playerB->playerMove7Used = true;
			}
		}
		//handles demon
		else if (playerB->idle == "demonIdle")
		{

			//enraged gets put on a 1 turn cooldown
			if (playerB->playerMove5Used == false)
			{
				playerB->playerMove5CD = 1;
				playerB->playerMove5Used = true;
			}

			//fireskin gets put on a 1 turn cooldown
			if (playerB->playerMove6Used == false)
			{
				playerB->playerMove6CD = 1;
				playerB->playerMove6Used = true;
			}
		}
	}





	//handles rooted effects
	if (playerA->playerDebuff == "Rooted" || playerA->playerSecondDebuff == "Rooted" || playerA->playerThirdDebuff == "Rooted")
	{
		//handles warrior
		if (playerA->idle == "warriorIdle")
		{
			//power stance gets put on a 1 turn cooldown
			if (playerA->playerMove1Used == false)
			{
				playerA->playerMove1CD = 1;
				playerA->playerMove1Used = true;
			}


			//shout gets put on a 1 turn cooldown
			if (playerA->playerMove2Used == false)
			{
				playerA->playerMove2CD = 1;
				playerA->playerMove2Used = true;
			}

			//block gets put on a 1 turn cooldown
			if (playerA->playerMove3Used == false)
			{
				playerA->playerMove3CD = 1;
				playerA->playerMove3Used = true;
			}

			//Taunt gets put on a 1 turn cooldown
			if (playerA->playerMove4Used == false)
			{
				playerA->playerMove4CD = 1;
				playerA->playerMove4Used = true;
			}
		}
		//handles assassin
		else if (playerA->idle == "assassinIdle")
		{
			//vital strike gets put on a 1 turn cooldown
			if (playerA->playerMove4Used == false)
			{
				playerA->playerMove4CD = 1;
				playerA->playerMove4Used = true;
			}


			//back blowgets put on a 1 turn cooldown
			if (playerA->playerMove5Used == false)
			{
				playerA->playerMove5CD = 1;
				playerA->playerMove5Used = true;
			}

			//leg slice gets put on a 1 turn cooldown
			if (playerA->playerMove7Used == false)
			{
				playerA->playerMove7CD = 1;
				playerA->playerMove7Used = true;
			}
			//Disarm gets put on a 1 turn cooldown
			if (playerA->playerMove8Used == false)
			{
				playerA->playerMove8CD = 1;
				playerA->playerMove8Used = true;
			}

		}

		//handles monk
		else if (playerA->idle == "monkIdle")
		{
			//push strike gets put on a 1 turn cooldown
			if (playerA->playerMove1Used == false)
			{
				playerA->playerMove1CD = 1;
				playerA->playerMove1Used = true;
			}
			//Piercing Kick gets put on a 1 turn cooldown
			if (playerA->playerMove3Used == false)
			{
				playerA->playerMove3CD = 1;
				playerA->playerMove3Used = true;
			}

			//right elbow gets put on a 1 turn cooldown
			if (playerA->playerMove4Used == false)
			{
				playerA->playerMove4CD = 1;
				playerA->playerMove4Used = true;
			}

			//heavenly tackle gets put on a 1 turn cooldown
			if (playerA->playerMove6Used == false)
			{
				playerA->playerMove6CD = 1;
				playerA->playerMove6Used = true;
			}

		}
		//handles necro
		else if (playerA->idle == "necromancerIdle")
		{
			//soul swipe gets put on a 1 turn cooldown
			if (playerA->playerMove1Used == false)
			{
				playerA->playerMove1CD = 1;
				playerA->playerMove1Used = true;
			}
			//corpse pile gets put on a 1 turn cooldown
			if (playerA->playerMove2Used == false)
			{
				playerA->playerMove2CD = 1;
				playerA->playerMove2Used = true;
			}

			//soul blast gets put on a 1 turn cooldown
			if (playerA->playerMove5Used == false)
			{
				playerA->playerMove5CD = 1;
				playerA->playerMove5Used = true;
			}

			//scythe surge gets put on a 1 turn cooldown
			if (playerA->playerMove8Used == false)
			{
				playerA->playerMove8CD = 1;
				playerA->playerMove8Used = true;
			}

		}
	}
	if (playerB->playerDebuff == "Rooted" || playerB->playerSecondDebuff == "Rooted" || playerB->playerThirdDebuff == "Rooted")
	{
		//handles warrior
		if (playerB->idle == "warriorIdle")
		{
			//power stance gets put on a 1 turn cooldown
			if (playerB->playerMove1Used == false)
			{
				playerB->playerMove1CD = 1;
				playerB->playerMove1Used = true;
			}


			//shout gets put on a 1 turn cooldown
			if (playerB->playerMove2Used == false)
			{
				playerB->playerMove2CD = 1;
				playerB->playerMove2Used = true;
			}

			//block gets put on a 1 turn cooldown
			if (playerB->playerMove3Used == false)
			{
				playerB->playerMove3CD = 1;
				playerB->playerMove3Used = true;
			}

			//Taunt gets put on a 1 turn cooldown
			if (playerB->playerMove4Used == false)
			{
				playerB->playerMove4CD = 1;
				playerB->playerMove4Used = true;
			}
		}
		//handles assassin
		else if (playerB->idle == "assassinIdle")
		{
			//vital strike gets put on a 1 turn cooldown
			if (playerB->playerMove4Used == false)
			{
				playerB->playerMove4CD = 1;
				playerB->playerMove4Used = true;
			}


			//back blowgets put on a 1 turn cooldown
			if (playerB->playerMove5Used == false)
			{
				playerB->playerMove5CD = 1;
				playerB->playerMove5Used = true;
			}

			//leg slice gets put on a 1 turn cooldown
			if (playerB->playerMove7Used == false)
			{
				playerB->playerMove7CD = 1;
				playerB->playerMove7Used = true;
			}
			//Disarm gets put on a 1 turn cooldown
			if (playerB->playerMove8Used == false)
			{
				playerB->playerMove8CD = 1;
				playerB->playerMove8Used = true;
			}

		}

		//handles monk
		else if (playerB->idle == "monkIdle")
		{
			//push strike gets put on a 1 turn cooldown
			if (playerB->playerMove1Used == false)
			{
				playerB->playerMove1CD = 1;
				playerB->playerMove1Used = true;
			}
			//Piercing Kick gets put on a 1 turn cooldown
			if (playerB->playerMove3Used == false)
			{
				playerB->playerMove3CD = 1;
				playerB->playerMove3Used = true;
			}

			//right elbow gets put on a 1 turn cooldown
			if (playerB->playerMove4Used == false)
			{
				playerB->playerMove4CD = 1;
				playerB->playerMove4Used = true;
			}

			//heavenly tackle gets put on a 1 turn cooldown
			if (playerB->playerMove6Used == false)
			{
				playerB->playerMove6CD = 1;
				playerB->playerMove6Used = true;
			}

		}
		//handles necro
		else if (playerB->idle == "necromancerIdle")
		{
			//soul swipe gets put on a 1 turn cooldown
			if (playerB->playerMove1Used == false)
			{
				playerB->playerMove1CD = 1;
				playerB->playerMove1Used = true;
			}
			//corpse pile gets put on a 1 turn cooldown
			if (playerB->playerMove2Used == false)
			{
				playerB->playerMove2CD = 1;
				playerB->playerMove2Used = true;
			}

			//soul blast gets put on a 1 turn cooldown
			if (playerB->playerMove5Used == false)
			{
				playerB->playerMove5CD = 1;
				playerB->playerMove5Used = true;
			}

			//scythe surge gets put on a 1 turn cooldown
			if (playerB->playerMove8Used == false)
			{
				playerB->playerMove8CD = 1;
				playerB->playerMove8Used = true;
			}

		}
	}





	playerA->playerEnhancedMove = false;
	playerB->playerEnhancedMove = false;

	playerA->currentAnimation = playerA->idle;
	playerB->currentAnimation = playerB->idle;
}



//handles the mana essence
void Battle::manaBar(sf::RenderWindow & renderWindow, VisibleObjectManager & _visibleObjectManager, GameObjectManager & _gameObjectManager, sf::Event & event, Player * playerA, Player * playerB)
{





	//sets the intial textures
	_visibleObjectManager.ManaBar1Player1.setTexture(_visibleObjectManager.ManaBarTexture);
	_visibleObjectManager.ManaBar2Player1.setTexture(_visibleObjectManager.ManaBarTexture);
	_visibleObjectManager.ManaBar1Player2.setTexture(_visibleObjectManager.ManaBarTexture);
	_visibleObjectManager.ManaBar2Player2.setTexture(_visibleObjectManager.ManaBarTexture);

	//creates a vector that holds the mouses position
	sf::Vector2f mousePos = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));

	//sets up a clickable response
	sf::FloatRect p1m1position = _visibleObjectManager.ManaBar1Player1.getGlobalBounds();
	sf::FloatRect p1m2position = _visibleObjectManager.ManaBar2Player1.getGlobalBounds();
	sf::FloatRect p2m1position = _visibleObjectManager.ManaBar1Player2.getGlobalBounds();
	sf::FloatRect p2m2position = _visibleObjectManager.ManaBar2Player2.getGlobalBounds();


	//checks to see if the event filled is the mouse being pressed
	renderWindow.pollEvent(event);

	//makes it so you cant use mana twice in one turn by accident
	if (playerA->playerEnhancedMove != true)
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (p1m1position.contains(mousePos) && (_gameObjectManager.player1Mana1 == true))
			{

				playerA->playerEnhancedMove = true;
				playerA->playerEnhanceUses--;
				_gameObjectManager.player1Mana1 = false;

			}
			if (p1m2position.contains(mousePos) && (_gameObjectManager.player1Mana2 == true))
			{

				playerA->playerEnhancedMove = true;
				playerA->playerEnhanceUses--;
				_gameObjectManager.player1Mana2 = false;

			}
		}

	}

	if (playerB->playerEnhancedMove != true)
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (p2m1position.contains(mousePos) && (_gameObjectManager.player2Mana1 == true))
			{

				playerB->playerEnhancedMove = true;
				playerB->playerEnhanceUses--;
				_gameObjectManager.player2Mana1 = false;

			}
			if (p2m2position.contains(mousePos) && (_gameObjectManager.player2Mana2 == true))
			{

				playerB->playerEnhancedMove = true;
				playerB->playerEnhanceUses--;
				_gameObjectManager.player2Mana2 = false;

			}
		}

	}



	//draws the sprites to the screen
	if (_gameObjectManager.player1Mana1)
	{
		renderWindow.draw(_visibleObjectManager.ManaBar1Player1);
	}

	if (_gameObjectManager.player1Mana2)
	{
		renderWindow.draw(_visibleObjectManager.ManaBar2Player1);

	}

	if (_gameObjectManager.player2Mana1)
	{
		renderWindow.draw(_visibleObjectManager.ManaBar1Player2);
	}

	if (_gameObjectManager.player2Mana2)
	{
		renderWindow.draw(_visibleObjectManager.ManaBar2Player2);
	}


	if (playerA->playerEnhancedMove == true)
	{
		_visibleObjectManager.manaAura(_visibleObjectManager.manaAuraCounterPlayer1, 1);
		renderWindow.draw(_visibleObjectManager.player1ManaAura);
	}
	if (playerB->playerEnhancedMove == true)
	{
		_visibleObjectManager.manaAura(_visibleObjectManager.manaAuraCounterPlayer2, 2);
		renderWindow.draw(_visibleObjectManager.player2ManaAura);
	}
}


