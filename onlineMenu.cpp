#include "onlineMenu.h"



onlineMenu::onlineMenu()
{
	createRoomTexture.loadFromFile("images/createRoom.png");
	joinRoomTexture.loadFromFile("images/joinRoom.png");
	


	createRoom.setTexture(createRoomTexture);
	joinRoom.setTexture(joinRoomTexture);

	createRoom.setPosition(650, 600);
	joinRoom.setPosition(650, 800);

}


int onlineMenu::showMenu(sf::RenderWindow& window, sf::Event & event)
{

	//setting size of screen
	static sf::Vector2f windowSize(window.getView().getSize().x, window.getView().getSize().y);

	//draws the buttons to screen
	window.draw(createRoom);
	window.draw(joinRoom);

	window.display();

	//creates an event
	//sf::Event event;

	//creates a vector that holds the mouses position
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	//gets the bounds of the sprite
	sf::FloatRect joinRoomBounds = joinRoom.getGlobalBounds();
	sf::FloatRect createRoomBounds = createRoom.getGlobalBounds();


	//fills the event
	while (window.pollEvent(event))
	{
		//checks to see if the event filled is the mouse being pressed
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (createRoomBounds.contains(mousePos))
			{
				return 1;
			}
			else if (joinRoomBounds.contains(mousePos))
			{
				return 2;
			}
		}
	}
}