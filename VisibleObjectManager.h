#pragma once
#include <string>


using namespace std;


class VisibleObjectManager
{

public:


	//misc??
	sf::Sprite * returnSplashScreen();

	//constructor
	VisibleObjectManager(void);

	//destructor
	~VisibleObjectManager(void);


	void setImagePosition(sf::Sprite & sprite, int x, int y);
	void scaleImage(sf::Sprite & sprite, double x, double y);



	void draw(sf::Sprite & sprite, sf::RenderWindow & renderWindow);
	void drawBattleMap(sf::RenderWindow & renderWindow);

	void changeTexture(sf::Sprite & sprite, sf::Texture texture);


	//warrior sprites


	//assassin spirtes

	//monk sprites






	void loadMainMenu(int load, sf::RenderWindow & renderWindow);
	void loadCharacterSelect(int load, sf::RenderWindow & renderWindow);

	void loadBattleClock(sf::Texture & texture);


	void loadTextures();

	void loadAssassinTextures();
	void loadWarriorTextures();
	void loadDemonTextures();
	void loadMonkTextures();
	void loadNecroTextures();



	//loads Mana Bars
	void loadManaBar1Player1(sf::Texture & texture);
	void loadManaBar2Player1(sf::Texture & texture);
	void loadManaBar1Player2(sf::Texture & texture);
	void loadManaBar2Player2(sf::Texture & texture);


	void loadBattleArena(int load, sf::RenderWindow & renderWindow);


	void loadSplashScreen(int load);

	void loadFonts();

	void loadSoulBarPlayer1();
	void loadSoulBarPlayer2();

	//animations
	void manaAura(int &counter, int player);
	void showSkillAnimation(int counter, sf::RenderWindow & renderWindow, string & player1Choice, string & player2Choice);

	//warrior animations
	void warriorIdle(int &counter, int player);
	void warriorMove1(int &counter, int player);
	void warriorMove2(int &counter, int player);
	void warriorMove3(int &counter, int player);
	void warriorMove4(int &counter, int player);
	void warriorMove5(int &counter, int player);
	void warriorMove6(int &counter, int player);
	void warriorMove7(int &counter, int player);
	void warriorMove8(int &counter, int player);
	void warriorHurt(int &counter, int player);

	//assassin animations
	void assassinIdle(int &counter, int player);
	void assassinMove1(int &counter, int player);
	void assassinMove2(int &counter, int player);
	void assassinMove3(int &counter, int player);
	void assassinMove4(int &counter, int player);
	void assassinMove5(int &counter, int player);
	void assassinMove6(int &counter, int player);
	void assassinMove7(int &counter, int player);
	void assassinMove8(int &counter, int player);
	void assassinHit(int &counter, int player);
	void assassinBackStance(int &counter, int player);

	//monk animations
	void monkIdle(int &counter, int player);
	void monkMove1(int &counter, int player);
	void monkMove2(int &counter, int player);
	void monkMove3(int &counter, int player);
	void monkMove4(int &counter, int player);
	void monkMove5(int &counter, int player);
	void monkMove6(int &counter, int player);
	void monkMove7(int &counter, int player);
	void monkMove8(int &counter, int player);
	void monkStepinIdle(int &counter, int player);
	void monkHurt(int &counter, int player);

	//necromancer animations
	void necromancerIdle(int &counter, int player);
	void necromancerMove1(int &counter, int player);
	void necromancerMove2(int &counter, int player);
	void necromancerMove3(int &counter, int player);
	void necromancerMove4(int &counter, int player);
	void necromancerMove5(int &counter, int player);
	void necromancerMove6(int &counter, int player);
	void necromancerMove7(int &counter, int player);
	void necromancerMove8(int &counter, int player);
	void necromancerHit(int &counter, int player);

	//demon animations
	void demonIdle(int &counter, int player);
	void demonMove1(int &counter, int player);
	void demonMove2(int &counter, int player);
	void demonMove3(int &counter, int player);
	void demonMove4(int &counter, int player);
	void demonMove5(int &counter, int player);
	void demonMove6(int &counter, int player);
	void demonMove7(int &counter, int player);
	void demonMove8(int &counter, int player);
	void demonHit(int &counter, int player);

	//makes all sprites line up bottom right of image
	sf::Vector2f adjustPosition(sf::Vector2f vec1, sf::Sprite sprite, sf::Vector2f vec2);

	//makes all sprites line up bottom left of image
	sf::Vector2f adjustPositionPlayer2(sf::Vector2f vec1, sf::Sprite sprite, sf::Vector2f vec2);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


	//bool//

	//handles whether the animation is completed or not
	bool player1MoveFinished;
	bool player2MoveFinished;


	//--strings----//
	string player1CurrentAnimation;
	string player2CurrentAnimation;

	sf::Text skillAnim1;
	sf::Text skillAnim2;


	sf::Text move1NamePlayer1;
	sf::Text move2NamePlayer1;
	sf::Text move3NamePlayer1;
	sf::Text move4NamePlayer1;
	sf::Text move5NamePlayer1;
	sf::Text move6NamePlayer1;
	sf::Text move7NamePlayer1;
	sf::Text move8NamePlayer1;

	sf::Text move1NamePlayer2;
	sf::Text move2NamePlayer2;
	sf::Text move3NamePlayer2;
	sf::Text move4NamePlayer2;
	sf::Text move5NamePlayer2;
	sf::Text move6NamePlayer2;
	sf::Text move7NamePlayer2;
	sf::Text move8NamePlayer2;

	sf::Text move1CoolDownPlayer1;
	sf::Text move2CoolDownPlayer1;
	sf::Text move3CoolDownPlayer1;
	sf::Text move4CoolDownPlayer1;
	sf::Text move5CoolDownPlayer1;
	sf::Text move6CoolDownPlayer1;
	sf::Text move7CoolDownPlayer1;
	sf::Text move8CoolDownPlayer1;

	sf::Text move1CoolDownPlayer2;
	sf::Text move2CoolDownPlayer2;
	sf::Text move3CoolDownPlayer2;
	sf::Text move4CoolDownPlayer2;
	sf::Text move5CoolDownPlayer2;
	sf::Text move6CoolDownPlayer2;
	sf::Text move7CoolDownPlayer2;
	sf::Text move8CoolDownPlayer2;

	sf::Text move1TimePlayer1;
	sf::Text move2TimePlayer1;
	sf::Text move3TimePlayer1;
	sf::Text move4TimePlayer1;
	sf::Text move5TimePlayer1;
	sf::Text move6TimePlayer1;
	sf::Text move7TimePlayer1;
	sf::Text move8TimePlayer1;

	sf::Text move1TimePlayer2;
	sf::Text move2TimePlayer2;
	sf::Text move3TimePlayer2;
	sf::Text move4TimePlayer2;
	sf::Text move5TimePlayer2;
	sf::Text move6TimePlayer2;
	sf::Text move7TimePlayer2;
	sf::Text move8TimePlayer2;



	//--integers--//
	int player1CurrentAnimationFrame;
	int player2CurrentAnimationFrame;

	//------SPRITES--------//


	sf::Sprite  SkillBoxAnim1;
	sf::Sprite  SkillBoxAnim2;

	sf::Sprite  SkillMenuPlayer1Skill1;
	sf::Sprite  SkillMenuPlayer1Skill2;
	sf::Sprite  SkillMenuPlayer1Skill3;
	sf::Sprite  SkillMenuPlayer1Skill4;
	sf::Sprite  SkillMenuPlayer1Skill5;
	sf::Sprite  SkillMenuPlayer1Skill6;
	sf::Sprite  SkillMenuPlayer1Skill7;
	sf::Sprite  SkillMenuPlayer1Skill8;

	sf::Sprite  SkillMenuPlayer2Skill1;
	sf::Sprite  SkillMenuPlayer2Skill2;
	sf::Sprite  SkillMenuPlayer2Skill3;
	sf::Sprite  SkillMenuPlayer2Skill4;
	sf::Sprite  SkillMenuPlayer2Skill5;
	sf::Sprite  SkillMenuPlayer2Skill6;
	sf::Sprite  SkillMenuPlayer2Skill7;
	sf::Sprite  SkillMenuPlayer2Skill8;

	sf::Sprite player1Character;
	sf::Sprite player2Character;

	sf::Sprite ManaBar1Player1;
	sf::Sprite ManaBar2Player1;
	sf::Sprite ManaBar1Player2;
	sf::Sprite ManaBar2Player2;

	sf::Sprite hpBarInsidePlayer1;
	sf::Sprite hpBarInsidePlayer2;

	//joystick button display
	sf::Sprite player1JoystickButtons;
	sf::Sprite player2JoystickButtons;

	//handles the hud displays for statuses
	sf::Sprite HUDBarPlayer1Buff;
	sf::Sprite HUDBarPlayer1Debuff;
	sf::Sprite HUDBarPlayer2Buff;
	sf::Sprite HUDBarPlayer2Debuff;


	//necro bar
	sf::Sprite necroBarBorderPlayer1;
	sf::Sprite necroBarBorderPlayer2;
	sf::Sprite necroBarPlayer1;
	sf::Sprite necroBarPlayer2;
	sf::Sprite boneWall;

	//warrior effects
	sf::Sprite powerStanceChargePlayer1;
	sf::Sprite powerStanceChargePlayer2;

	//hp bars
	sf::Sprite  player1HpBar;
	sf::Sprite  player2HpBar;

	//mana aura
	sf::Sprite player1ManaAura;
	sf::Sprite player2ManaAura;
	int manaAuraCounterPlayer1;
	int manaAuraCounterPlayer2;

	//clock
	sf::Sprite battleClock;

	sf::Sprite * characterSelect;
	sf::Sprite * mainMenu;
	sf::Sprite battleMap;
	sf::Sprite * splashScreen;

	sf::Sprite loadingBar;



	//--------TEXTURES--------//
	sf::Texture skillMenuSlot;
	sf::Texture splashTexture;
	sf::Texture battleMapTexture;

	sf::Texture playerHpBarTexture;

	sf::Texture battleClockTexture;

	sf::Texture HUDBarBuffExpandedTexture;
	sf::Texture HUDBarDebuffExpandedTexture;
	sf::Texture HUDBarBuffMinimizedTexture;
	sf::Texture HUDBarDebuffMinimizedTexture;

	//joystick button texture
	sf::Texture joystickButtonTexture;

	sf::Texture hpBarInsideTexture;

	//character sprite sheets
	sf::Texture warriorIdleTexture;
	sf::Texture warriorHurtTexture;
	sf::Texture warriorMove1Texture;
	sf::Texture warriorMove2Texture;
	sf::Texture warriorMove3Texture;
	sf::Texture warriorMove4Texture;
	sf::Texture warriorMove5Texture;
	sf::Texture warriorMove5Texture2;
	sf::Texture warriorMove6Texture;
	sf::Texture warriorMove7Texture;
	sf::Texture warriorMove8Texture;

	sf::Texture assassinIdleTexture;
	sf::Texture assassinMove1Texture;
	sf::Texture assassinMove2Texture;
	sf::Texture assassinMove3Texture;
	sf::Texture assassinMove4Texture;
	sf::Texture assassinMove5Texture;
	sf::Texture assassinMove6Texture;
	sf::Texture assassinMove7Texture;
	sf::Texture assassinMove8Texture;

	sf::Texture monkIdleTexture;
	sf::Texture monkMove1Texture;
	sf::Texture monkMove2Texture;
	sf::Texture monkMove3Texture;
	sf::Texture monkMove4Texture;
	sf::Texture monkMove5Texture;
	sf::Texture monkMove6Texture;
	sf::Texture monkMove7Texture;
	sf::Texture monkMove8Texture;
	sf::Texture monkStepinIdleTexture;


	sf::Texture necromancerIdleTexture;
	sf::Texture necromancerMove1Texture;
	sf::Texture necromancerMove2Texture;
	sf::Texture necromancerMove3Texture;
	sf::Texture necromancerMove4Texture;
	sf::Texture necromancerMove5Texture;
	sf::Texture necromancerMove6Texture;
	sf::Texture necromancerMove7Texture;
	sf::Texture necromancerMove8Texture;

	sf::Texture demonIdleTexture;
	sf::Texture demonMove1Texture;
	sf::Texture demonMove2Texture;
	sf::Texture demonMove3Texture;
	sf::Texture demonMove4Texture;
	sf::Texture demonMove5Texture;
	sf::Texture demonMove6Texture;
	sf::Texture demonMove7Texture;
	sf::Texture demonMove8Texture;


	//special effect textures
	sf::Texture boneWallTexture;
	sf::Texture powerStanceCharge;

	//soul bar textures
	sf::Texture necroBarBorderTexture;
	sf::Texture necroBarTexture;

	//mana aura texture
	sf::Texture manaAuraTexture;

	///////////////////////
	sf::Texture SkillMenuPlayerSkillTexture;
	sf::Texture SkillMenuPlayerSkillSelectedTexture;
	sf::Texture SkillMenuPlayerSkillUsedTexture;

	sf::Texture WarriorTexture;
	sf::Texture AssassinTexture;
	sf::Texture MonkTexture;
	sf::Texture NecromancerTexture;
	sf::Texture DemonTexture;

	sf::Texture ManaBarTexture;
	sf::Texture ManaBarUsedTexture;





	//----Fonts---//
	sf::Font font;




	//---TIMER---//
	sf::Time frameClock;

	sf::Clock player1Clock;
	sf::Clock player2Clock;

	//mana orb clock
	sf::Clock player1ManaClock;
	sf::Clock player2ManaClock;

	sf::Clock bufferClock;
};
