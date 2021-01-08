#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <dirent.h>
#include <vector>




using namespace std;

struct frame
{
	int x;
	int y;
	int width;
	int height;
	int moveLeft = 0;
	int moveUp = 0;
};




struct oneMove
{
	string nameOfFile;
	nlohmann::json jsonFile;
	std::vector<frame> move;
};


struct MoveGroup
{
	std::vector<oneMove> moveGroup;
};

class Animator
{
public:

	//enum menuResult {nothing, exit, play, playOffline, options, animator};
	std::vector<string> nameOfImageFiles;
	std::vector<string> nameOfJSONFiles;

	std::vector<oneMove> listOfAllMoves;

	sf::Time frameClockTime;
	sf::Clock frameClock;

	Animator();

	sf::Texture backgroundImageTexture;
	sf::Sprite backgroundImage;
	sf::Texture player1SpriteTexture;
	sf::Sprite player1Sprite;

	//buttons
	sf::Sprite pauseButton;
	sf::Texture pauseButtonTextureOn;
	sf::Texture pauseButtonTextureOff;

	sf::Sprite moveAllFrames;
	sf::Texture moveAllFramesTexture;

	sf::Sprite moveSingleFrame;
	sf::Texture moveSingleFrameTexture;

	sf::Sprite TurnOnGhost;
	sf::Texture TurnOnGhostTextureOn;
	sf::Texture TurnOnGhostTextureOff;

	sf::Sprite nextAnimation;
	sf::Texture nextAnimationTexture;

	sf::Sprite prevAnimation;
	sf::Texture prevAnimationTexture;

	sf::Sprite nextFrame;
	sf::Texture nextFrameTexture;

	sf::Sprite prevFrame;
	sf::Texture prevFrameTexture;

	sf::Sprite Save;
	sf::Texture SaveTexture;


	sf::Sprite upButton;
	sf::Texture upTexture;

	sf::Sprite downButton;
	sf::Texture downTexture;

	sf::Sprite leftButton;
	sf::Texture leftTexture;

	sf::Sprite rightButton;
	sf::Texture rightTexture;

	int readInputForButtons(sf::RenderWindow& renderWindow, sf::Event);
	void list_dir();

	void drawBackground();
	void loadAllFiles(); 
	void fillAllMoves();
	void SaveMove(oneMove currentMove);

	vector<sf::Texture> loadAllTextures(vector<MoveGroup> moveGroups);

	void animateCurrentMove(sf::RenderWindow& renderWindow, sf::Event);
	vector<MoveGroup> groupMultiSheetGroupsTogether();

	int getTotalFrameCount(vector<oneMove> group);

	//json stream buffer object

	//dynamic array of json stream buffers

	//bucket drop down list to select which animation will currently play
};


