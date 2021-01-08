#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
class onlineMenu
{
public:
	onlineMenu();
	int showMenu(sf::RenderWindow& window, sf::Event & event);

	sf::Texture createRoomTexture;
	sf::Texture joinRoomTexture;

	sf::Sprite createRoom;
	sf::Sprite joinRoom;
	enum menuResult {join, create};
};

