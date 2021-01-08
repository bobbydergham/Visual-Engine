#include "StdAfx.h"
#include "SplashScreen.h"


void SplashScreen::show(sf::RenderWindow & renderWindow, VisibleObjectManager _visibleObjectManager)
{

	sf::Texture splashTexture;
	splashTexture.loadFromFile("images/SplashScreen.png");

	sf::Sprite sprite;
	sprite.setTexture(splashTexture);

	sf::Vector2f windowSize(renderWindow.getView().getSize().x, renderWindow.getView().getSize().y);
	sprite.scale(windowSize.x /
		sprite.getLocalBounds().width, windowSize.y /
		sprite.getLocalBounds().height);
	
	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	
	while(true)
	{
		while(renderWindow.pollEvent(event))
		{
			if(event.type == sf::Event::EventType::KeyPressed
			|| event.type == sf::Event::EventType::MouseButtonPressed
			|| event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}

SplashScreen::~SplashScreen()
{


}