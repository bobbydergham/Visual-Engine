#pragma once
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
using namespace std; 

class Multiplayer
{
public:
	
	string text;
	char buffer[2000];
	size_t received;
	sf::TcpSocket socket;
	sf::TcpListener listener;

	char connectionType, mode;

	Multiplayer();
	void receive();
	void server();
	void client();
	void send(string str);
	sf::IpAddress hostIp;

	//sets whos host
	bool host;

	//lets the game know, multiplayer mode is active
	bool multiplayer;


	bool connection;
};

