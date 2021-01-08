#include "Multiplayer.h"



Multiplayer::Multiplayer()
{
	hostIp = sf::IpAddress("192.168.1.252");
	host = false;
	text = "howdy neighbor";
	connection = true;
}


void Multiplayer::server()
{

	host = true;
	multiplayer = true;
	//listener.setBlocking(false);
	listener.listen(8000);
	if (listener.accept(socket) == sf::Socket::Done)
	{
		cout << "connection accepted" << std::endl;
	}
	else cout << "it didnt work";
}

void Multiplayer::client()
{
	host = false;
	multiplayer = true;
	sf::Socket::Status status = socket.connect(hostIp, 8000);
	if (status != sf::Socket::Done) {
		std::cout << "Could Not Connect to server" << std::endl;
	}
	else {
		std::cout << "Connected to server" << std::endl;
	}
}


void Multiplayer::send(string str)
{
	socket.send(str.c_str(), str.length() + 1);
}

void Multiplayer::receive()
{
	socket.setBlocking(false);
	socket.receive(buffer, sizeof(buffer), received);
	cout << buffer;
}