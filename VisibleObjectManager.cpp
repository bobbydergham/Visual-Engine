#include "stdafx.h"
#include "VisibleObjectManager.h"




VisibleObjectManager::VisibleObjectManager(void)
{
	player1CurrentAnimationFrame = 0;
	player2CurrentAnimationFrame = 0;

	player2Character.scale(-1.f, 1.f);
	frameClock = sf::seconds(0.1);


	player1MoveFinished = false;
	player2MoveFinished = false;


	//set font
	move1NamePlayer1.setFont(font);
	move2NamePlayer1.setFont(font);
	move3NamePlayer1.setFont(font);
	move4NamePlayer1.setFont(font);
	move5NamePlayer1.setFont(font);
	move6NamePlayer1.setFont(font);
	move7NamePlayer1.setFont(font);
	move8NamePlayer1.setFont(font);

	move1NamePlayer2.setFont(font);
	move2NamePlayer2.setFont(font);
	move3NamePlayer2.setFont(font);
	move4NamePlayer2.setFont(font);
	move5NamePlayer2.setFont(font);
	move6NamePlayer2.setFont(font);
	move7NamePlayer2.setFont(font);
	move8NamePlayer2.setFont(font);

	move1CoolDownPlayer1.setFont(font);
	move2CoolDownPlayer1.setFont(font);
	move3CoolDownPlayer1.setFont(font);
	move4CoolDownPlayer1.setFont(font);
	move5CoolDownPlayer1.setFont(font);
	move6CoolDownPlayer1.setFont(font);
	move7CoolDownPlayer1.setFont(font);
	move8CoolDownPlayer1.setFont(font);

	move1CoolDownPlayer2.setFont(font);
	move2CoolDownPlayer2.setFont(font);
	move3CoolDownPlayer2.setFont(font);
	move4CoolDownPlayer2.setFont(font);
	move5CoolDownPlayer2.setFont(font);
	move6CoolDownPlayer2.setFont(font);
	move7CoolDownPlayer2.setFont(font);
	move8CoolDownPlayer2.setFont(font);

	move1TimePlayer1.setFont(font);
	move2TimePlayer1.setFont(font);
	move3TimePlayer1.setFont(font);
	move4TimePlayer1.setFont(font);
	move5TimePlayer1.setFont(font);
	move6TimePlayer1.setFont(font);
	move7TimePlayer1.setFont(font);
	move8TimePlayer1.setFont(font);

	move1TimePlayer2.setFont(font);
	move2TimePlayer2.setFont(font);
	move3TimePlayer2.setFont(font);
	move4TimePlayer2.setFont(font);
	move5TimePlayer2.setFont(font);
	move6TimePlayer2.setFont(font);
	move7TimePlayer2.setFont(font);
	move8TimePlayer2.setFont(font);


	//set font size
	move1NamePlayer1.setCharacterSize(30);
	move2NamePlayer1.setCharacterSize(30);
	move3NamePlayer1.setCharacterSize(30);
	move4NamePlayer1.setCharacterSize(30);
	move5NamePlayer1.setCharacterSize(30);
	move6NamePlayer1.setCharacterSize(30);
	move7NamePlayer1.setCharacterSize(30);
	move8NamePlayer1.setCharacterSize(30);

	move1NamePlayer2.setCharacterSize(30);
	move2NamePlayer2.setCharacterSize(30);
	move3NamePlayer2.setCharacterSize(30);
	move4NamePlayer2.setCharacterSize(30);
	move5NamePlayer2.setCharacterSize(30);
	move6NamePlayer2.setCharacterSize(30);
	move7NamePlayer2.setCharacterSize(30);
	move8NamePlayer2.setCharacterSize(30);

	move1CoolDownPlayer1.setCharacterSize(30);
	move2CoolDownPlayer1.setCharacterSize(30);
	move3CoolDownPlayer1.setCharacterSize(30);
	move4CoolDownPlayer1.setCharacterSize(30);
	move5CoolDownPlayer1.setCharacterSize(30);
	move6CoolDownPlayer1.setCharacterSize(30);
	move7CoolDownPlayer1.setCharacterSize(30);
	move8CoolDownPlayer1.setCharacterSize(30);

	move1CoolDownPlayer2.setCharacterSize(30);
	move2CoolDownPlayer2.setCharacterSize(30);
	move3CoolDownPlayer2.setCharacterSize(30);
	move4CoolDownPlayer2.setCharacterSize(30);
	move5CoolDownPlayer2.setCharacterSize(30);
	move6CoolDownPlayer2.setCharacterSize(30);
	move7CoolDownPlayer2.setCharacterSize(30);
	move8CoolDownPlayer2.setCharacterSize(30);

	move1TimePlayer1.setCharacterSize(30);
	move2TimePlayer1.setCharacterSize(30);
	move3TimePlayer1.setCharacterSize(30);
	move4TimePlayer1.setCharacterSize(30);
	move5TimePlayer1.setCharacterSize(30);
	move6TimePlayer1.setCharacterSize(30);
	move7TimePlayer1.setCharacterSize(30);
	move8TimePlayer1.setCharacterSize(30);

	move1TimePlayer2.setCharacterSize(30);
	move2TimePlayer2.setCharacterSize(30);
	move3TimePlayer2.setCharacterSize(30);
	move4TimePlayer2.setCharacterSize(30);
	move5TimePlayer2.setCharacterSize(30);
	move6TimePlayer2.setCharacterSize(30);
	move7TimePlayer2.setCharacterSize(30);
	move8TimePlayer2.setCharacterSize(30);


	//set color
	move1NamePlayer1.setColor(sf::Color::White);
	move2NamePlayer1.setColor(sf::Color::White);
	move3NamePlayer1.setColor(sf::Color::White);
	move4NamePlayer1.setColor(sf::Color::White);
	move5NamePlayer1.setColor(sf::Color::White);
	move6NamePlayer1.setColor(sf::Color::White);
	move7NamePlayer1.setColor(sf::Color::White);
	move8NamePlayer1.setColor(sf::Color::White);

	move1NamePlayer2.setColor(sf::Color::White);
	move2NamePlayer2.setColor(sf::Color::White);
	move3NamePlayer2.setColor(sf::Color::White);
	move4NamePlayer2.setColor(sf::Color::White);
	move5NamePlayer2.setColor(sf::Color::White);
	move6NamePlayer2.setColor(sf::Color::White);
	move7NamePlayer2.setColor(sf::Color::White);
	move8NamePlayer2.setColor(sf::Color::White);

	move1CoolDownPlayer1.setColor(sf::Color::White);
	move2CoolDownPlayer1.setColor(sf::Color::White);
	move3CoolDownPlayer1.setColor(sf::Color::White);
	move4CoolDownPlayer1.setColor(sf::Color::White);
	move5CoolDownPlayer1.setColor(sf::Color::White);
	move6CoolDownPlayer1.setColor(sf::Color::White);
	move7CoolDownPlayer1.setColor(sf::Color::White);
	move8CoolDownPlayer1.setColor(sf::Color::White);

	move1CoolDownPlayer2.setColor(sf::Color::White);
	move2CoolDownPlayer2.setColor(sf::Color::White);
	move3CoolDownPlayer2.setColor(sf::Color::White);
	move4CoolDownPlayer2.setColor(sf::Color::White);
	move5CoolDownPlayer2.setColor(sf::Color::White);
	move6CoolDownPlayer2.setColor(sf::Color::White);
	move7CoolDownPlayer2.setColor(sf::Color::White);
	move8CoolDownPlayer2.setColor(sf::Color::White);

	move1TimePlayer1.setColor(sf::Color::White);
	move2TimePlayer1.setColor(sf::Color::White);
	move3TimePlayer1.setColor(sf::Color::White);
	move4TimePlayer1.setColor(sf::Color::White);
	move5TimePlayer1.setColor(sf::Color::White);
	move6TimePlayer1.setColor(sf::Color::White);
	move7TimePlayer1.setColor(sf::Color::White);
	move8TimePlayer1.setColor(sf::Color::White);

	move1TimePlayer2.setColor(sf::Color::White);
	move2TimePlayer2.setColor(sf::Color::White);
	move3TimePlayer2.setColor(sf::Color::White);
	move4TimePlayer2.setColor(sf::Color::White);
	move5TimePlayer2.setColor(sf::Color::White);
	move6TimePlayer2.setColor(sf::Color::White);
	move7TimePlayer2.setColor(sf::Color::White);
	move8TimePlayer2.setColor(sf::Color::White);


	//set style
	move1NamePlayer1.setStyle(sf::Text::Bold);
	move2NamePlayer1.setStyle(sf::Text::Bold);
	move3NamePlayer1.setStyle(sf::Text::Bold);
	move4NamePlayer1.setStyle(sf::Text::Bold);
	move5NamePlayer1.setStyle(sf::Text::Bold);
	move6NamePlayer1.setStyle(sf::Text::Bold);
	move7NamePlayer1.setStyle(sf::Text::Bold);
	move8NamePlayer1.setStyle(sf::Text::Bold);

	move1NamePlayer2.setStyle(sf::Text::Bold);
	move2NamePlayer2.setStyle(sf::Text::Bold);
	move3NamePlayer2.setStyle(sf::Text::Bold);
	move4NamePlayer2.setStyle(sf::Text::Bold);
	move5NamePlayer2.setStyle(sf::Text::Bold);
	move6NamePlayer2.setStyle(sf::Text::Bold);
	move7NamePlayer2.setStyle(sf::Text::Bold);
	move8NamePlayer2.setStyle(sf::Text::Bold);

	move1CoolDownPlayer1.setStyle(sf::Text::Bold);
	move2CoolDownPlayer1.setStyle(sf::Text::Bold);
	move3CoolDownPlayer1.setStyle(sf::Text::Bold);
	move4CoolDownPlayer1.setStyle(sf::Text::Bold);
	move5CoolDownPlayer1.setStyle(sf::Text::Bold);
	move6CoolDownPlayer1.setStyle(sf::Text::Bold);
	move7CoolDownPlayer1.setStyle(sf::Text::Bold);
	move8CoolDownPlayer1.setStyle(sf::Text::Bold);

	move1CoolDownPlayer2.setStyle(sf::Text::Bold);
	move2CoolDownPlayer2.setStyle(sf::Text::Bold);
	move3CoolDownPlayer2.setStyle(sf::Text::Bold);
	move4CoolDownPlayer2.setStyle(sf::Text::Bold);
	move5CoolDownPlayer2.setStyle(sf::Text::Bold);
	move6CoolDownPlayer2.setStyle(sf::Text::Bold);
	move7CoolDownPlayer2.setStyle(sf::Text::Bold);
	move8CoolDownPlayer2.setStyle(sf::Text::Bold);

	move1TimePlayer1.setStyle(sf::Text::Bold);
	move2TimePlayer1.setStyle(sf::Text::Bold);
	move3TimePlayer1.setStyle(sf::Text::Bold);
	move4TimePlayer1.setStyle(sf::Text::Bold);
	move5TimePlayer1.setStyle(sf::Text::Bold);
	move6TimePlayer1.setStyle(sf::Text::Bold);
	move7TimePlayer1.setStyle(sf::Text::Bold);
	move8TimePlayer1.setStyle(sf::Text::Bold);

	move1TimePlayer2.setStyle(sf::Text::Bold);
	move2TimePlayer2.setStyle(sf::Text::Bold);
	move3TimePlayer2.setStyle(sf::Text::Bold);
	move4TimePlayer2.setStyle(sf::Text::Bold);
	move5TimePlayer2.setStyle(sf::Text::Bold);
	move6TimePlayer2.setStyle(sf::Text::Bold);
	move7TimePlayer2.setStyle(sf::Text::Bold);
	move8TimePlayer2.setStyle(sf::Text::Bold);

	//set position
	move1NamePlayer1.setPosition(460, 650);
	move2NamePlayer1.setPosition(460, 700);
	move3NamePlayer1.setPosition(460, 750);
	move4NamePlayer1.setPosition(460, 800);
	move5NamePlayer1.setPosition(460, 850);
	move6NamePlayer1.setPosition(460, 900);
	move7NamePlayer1.setPosition(460, 950);
	move8NamePlayer1.setPosition(460, 1000);

	move1NamePlayer2.setPosition(1238, 650);
	move2NamePlayer2.setPosition(1238, 700);
	move3NamePlayer2.setPosition(1238, 750);
	move4NamePlayer2.setPosition(1238, 800);
	move5NamePlayer2.setPosition(1238, 850);
	move6NamePlayer2.setPosition(1238, 900);
	move7NamePlayer2.setPosition(1238, 950);
	move8NamePlayer2.setPosition(1238, 1000);

	move1CoolDownPlayer1.setPosition(414, 655);
	move2CoolDownPlayer1.setPosition(414, 705);
	move3CoolDownPlayer1.setPosition(414, 755);
	move4CoolDownPlayer1.setPosition(414, 805);
	move5CoolDownPlayer1.setPosition(414, 855);
	move6CoolDownPlayer1.setPosition(414, 905);
	move7CoolDownPlayer1.setPosition(414, 955);
	move8CoolDownPlayer1.setPosition(414, 1005);

	move1CoolDownPlayer2.setPosition(1197, 655);
	move2CoolDownPlayer2.setPosition(1197, 705);
	move3CoolDownPlayer2.setPosition(1197, 755);
	move4CoolDownPlayer2.setPosition(1197, 805);
	move5CoolDownPlayer2.setPosition(1197, 855);
	move6CoolDownPlayer2.setPosition(1197, 905);
	move7CoolDownPlayer2.setPosition(1197, 955);
	move8CoolDownPlayer2.setPosition(1197, 1005);

	move1TimePlayer1.setPosition(0, 0);
	move2TimePlayer1.setPosition(0, 0);
	move3TimePlayer1.setPosition(0, 0);
	move4TimePlayer1.setPosition(0, 0);
	move5TimePlayer1.setPosition(0, 0);
	move6TimePlayer1.setPosition(0, 0);
	move7TimePlayer1.setPosition(0, 0);
	move8TimePlayer1.setPosition(0, 0);

	move1TimePlayer2.setPosition(0, 0);
	move2TimePlayer2.setPosition(0, 0);
	move3TimePlayer2.setPosition(0, 0);
	move4TimePlayer2.setPosition(0, 0);
	move5TimePlayer2.setPosition(0, 0);
	move6TimePlayer2.setPosition(0, 0);
	move7TimePlayer2.setPosition(0, 0);
	move8TimePlayer2.setPosition(0, 0);


	//for skillbox animation
	SkillBoxAnim1.setPosition(410, 650);
	SkillBoxAnim2.setPosition(1185, 650);

	SkillMenuPlayer1Skill1.setPosition(410, 650);
	SkillMenuPlayer1Skill2.setPosition(410, 700);
	SkillMenuPlayer1Skill3.setPosition(410, 750);
	SkillMenuPlayer1Skill4.setPosition(410, 800);
	SkillMenuPlayer1Skill5.setPosition(410, 850);
	SkillMenuPlayer1Skill6.setPosition(410, 900);
	SkillMenuPlayer1Skill7.setPosition(410, 950);
	SkillMenuPlayer1Skill8.setPosition(410, 1000);

	SkillMenuPlayer2Skill1.setPosition(1185, 650);
	SkillMenuPlayer2Skill2.setPosition(1185, 700);
	SkillMenuPlayer2Skill3.setPosition(1185, 750);
	SkillMenuPlayer2Skill4.setPosition(1185, 800);
	SkillMenuPlayer2Skill5.setPosition(1185, 850);
	SkillMenuPlayer2Skill6.setPosition(1185, 900);
	SkillMenuPlayer2Skill7.setPosition(1185, 950);
	SkillMenuPlayer2Skill8.setPosition(1185, 1000);

	//base character positions
	// player1Character.setPosition(300,300);
	// player2Character.setPosition(1700,300);

	//mana aura 
	manaAuraCounterPlayer1 = 0;
	manaAuraCounterPlayer2 = 0;
	player1ManaAura.setTexture(manaAuraTexture);
	player2ManaAura.setTexture(manaAuraTexture);

	//mana bar pos
	ManaBar1Player1.setPosition(330, 90);
	ManaBar2Player1.setPosition(430, 90);
	ManaBar1Player2.setPosition(1400, 90);
	ManaBar2Player2.setPosition(1500, 90);

	//joystick buttons
	player1JoystickButtons.setPosition(370, 650);
	player2JoystickButtons.setPosition(1145, 650);


	//
	// hpBarInsidePlayer1.setPosition();
	// hpBarInsidePlayer2.setPosition();

	////handles the hud displays for statuses
	HUDBarPlayer1Buff.setPosition(0, 100);
	HUDBarPlayer1Debuff.setPosition(0, 360);
	HUDBarPlayer2Buff.setPosition(1590, 100);
	HUDBarPlayer2Debuff.setPosition(1590, 360);
	//

	////necro bar
	// necroBarBorderPlayer1.setPosition();
	// necroBarBorderPlayer2.setPosition();
	// necroBarPlayer1.setPosition();
	// necroBarPlayer2.setPosition();
	boneWall.setPosition(900, 300);

	////hp bars
	//player1HpBar.setPosition(-8,30);
	//  player2HpBar.setPosition();


	//mana aura positions
	player1ManaAura.setPosition(550, 330);
	player2ManaAura.setPosition(1150, 330);

	////clock
	battleClock.setPosition(885, 20);


	//skill box animation text
	skillAnim1.setColor(sf::Color::White);
	skillAnim2.setColor(sf::Color::White);
	skillAnim1.setFont(font);
	skillAnim2.setFont(font);
	skillAnim1.setCharacterSize(30);
	skillAnim2.setCharacterSize(30);
	skillAnim1.setPosition(460, 650);
	skillAnim2.setPosition(1238, 650);

	SkillBoxAnim1.setPosition(410, 650);
	SkillBoxAnim1.setPosition(1188, 650);
	SkillBoxAnim1.setTexture(SkillMenuPlayerSkillTexture);
	SkillBoxAnim2.setTexture(SkillMenuPlayerSkillTexture);
}


VisibleObjectManager::~VisibleObjectManager(void)
{
}




void VisibleObjectManager::draw(sf::Sprite & sprite, sf::RenderWindow & renderWindow)
{
	renderWindow.draw(sprite);
}


void VisibleObjectManager::drawBattleMap(sf::RenderWindow & renderWindow)
{

	//applies the changes to the renderWindow
	renderWindow.draw(battleMap);
}






void VisibleObjectManager::loadMainMenu(int load, sf::RenderWindow & renderWindow)
{

}

void VisibleObjectManager::loadCharacterSelect(int load, sf::RenderWindow & renderWindow)
{

}

void VisibleObjectManager::loadBattleClock(sf::Texture & texture)
{
	battleClock.setTexture(texture);
}



void VisibleObjectManager::loadTextures()
{
	

	hpBarInsideTexture.loadFromFile("images/hpBar.png");

	battleClockTexture.loadFromFile("images/battleClock.png");

	battleMapTexture.loadFromFile("images/battleMap.png");

	SkillMenuPlayerSkillTexture.loadFromFile("images/skillMenu.png");

	SkillMenuPlayerSkillSelectedTexture.loadFromFile("images/skillMenuSelect.png");

	SkillMenuPlayerSkillUsedTexture.loadFromFile("images/skillMenuUsed.png");

	splashTexture.loadFromFile("images/SplashScreen.png");

	WarriorTexture.loadFromFile("images/warriorFight.png");

	AssassinTexture.loadFromFile("images/assassinFight.png");

	MonkTexture.loadFromFile("images/monkFight.png");

	NecromancerTexture.loadFromFile("images/necromancerFight.png");

	DemonTexture.loadFromFile("images/demonFight.png");

	//joystick texture
	joystickButtonTexture.loadFromFile("images/joystickButtons.png");


	ManaBarTexture.loadFromFile("images/manaOrb.png");

	ManaBarUsedTexture.loadFromFile("images/manaOrbUsed.png");

	playerHpBarTexture.loadFromFile("images/statsBar.png");

	HUDBarBuffExpandedTexture.loadFromFile("images/hudWindow.png");

	HUDBarDebuffExpandedTexture.loadFromFile("images/hudWindow.png");

	HUDBarBuffMinimizedTexture.loadFromFile("images/HUDBuffMinimized.png");

	HUDBarDebuffMinimizedTexture.loadFromFile("images/HUDDebuffMinimized.png");

	//font
	if (!font.loadFromFile("Text/times.ttf")) return;


	//mana aura texture
	manaAuraTexture.loadFromFile("Images/manaAura.png");

	//loading screen
	loadingBar.setTexture(playerHpBarTexture);
	loadingBar.setPosition(800, 600);
}

void VisibleObjectManager::loadAssassinTextures()
{
	assassinIdleTexture.loadFromFile("Images/assassinIdleSheet.png");
	assassinMove1Texture.loadFromFile("Images/smokeBombSheet.png");
	assassinMove2Texture.loadFromFile("Images/applyPoisonSheet.png");
	assassinMove3Texture.loadFromFile("Images/kunaisSheet.png");
	assassinMove4Texture.loadFromFile("Images/vitalStrikeSheet.png");
	assassinMove5Texture.loadFromFile("Images/backBlowSheet.png");
	assassinMove6Texture.loadFromFile("Images/dodgeSheet.png");
	assassinMove7Texture.loadFromFile("Images/legSliceSheet.png");
	assassinMove8Texture.loadFromFile("Images/disarmSheet.png");
}
void VisibleObjectManager::loadWarriorTextures()
{

	//loads all the sprite sheets 
	warriorIdleTexture.loadFromFile("Images/warriorIdleSheet.png");
	warriorHurtTexture.loadFromFile("Images/KnightHurt.png");
	warriorMove1Texture.loadFromFile("Images/stunStrikeSheet.png");
	warriorMove2Texture.loadFromFile("Images/warriorQuickStrikeSheet.png");
	warriorMove3Texture.loadFromFile("Images/warriorChargingStrikeSheet.png");
	warriorMove4Texture.loadFromFile("Images/warriorThrustStrikeSheet.png");
	warriorMove5Texture.loadFromFile("Images/warriorPowerStanceSheet.png");
	warriorMove5Texture2.loadFromFile("Images/warriorPowerStanceSheet2.png");
	warriorMove6Texture.loadFromFile("Images/warriorShoutSheet.png");
	warriorMove7Texture.loadFromFile("Images/warriorGuardSheet.png");
	warriorMove8Texture.loadFromFile("Images/warriorTauntSheet.png");


	powerStanceCharge.loadFromFile("Images/warriorPowerStanceEffect.png");
}
void VisibleObjectManager::loadDemonTextures()
{
	//loads all the sprite sheets 
	demonIdleTexture.loadFromFile("Images/demonIdleSheet.png");
	demonMove1Texture.loadFromFile("Images/boneCrusherSheet.png");
	demonMove2Texture.loadFromFile("Images/heatFumationSheet.png");
	demonMove3Texture.loadFromFile("Images/demonFistSheet.png");
	demonMove4Texture.loadFromFile("Images/lavaBallSheet.png");
	demonMove5Texture.loadFromFile("Images/enragedSheet.png");
	demonMove6Texture.loadFromFile("Images/fireSkinSheet.png");
	demonMove7Texture.loadFromFile("Images/mutilationSheet.png");
	demonMove8Texture.loadFromFile("Images/demonTackleSheet.png");

}
void VisibleObjectManager::loadMonkTextures()
{
	//loads all the sprite sheets 
	monkIdleTexture.loadFromFile("Images/monkIdleSheet.png");
	monkMove1Texture.loadFromFile("Images/pushStrikeSheet.png");
	monkMove2Texture.loadFromFile("Images/stepinSheet.png");
	monkMove3Texture.loadFromFile("Images/piercingKickSheet.png");
	monkMove4Texture.loadFromFile("Images/rightElbowSheet.png");
	monkMove5Texture.loadFromFile("Images/elbowParrySheet.png");
	monkMove6Texture.loadFromFile("Images/heavenlyTackleSheet.png");
	monkMove7Texture.loadFromFile("Images/inhumanSpeedSheet.png");
	monkMove8Texture.loadFromFile("Images/meditateSheet.png");

	monkStepinIdleTexture.loadFromFile("Images/stepinIdleSheet.png");
}
void VisibleObjectManager::loadNecroTextures()
{
	//necro idle
	//loads all the sprite sheets 
	necromancerIdleTexture.loadFromFile("Images/necroIdleSheet.png");
	necromancerMove1Texture.loadFromFile("Images/soulSwipeSheet.png");
	necromancerMove2Texture.loadFromFile("Images/corpsePileSheet.png");
	necromancerMove3Texture.loadFromFile("Images/soulHarvestSheet.png");
	necromancerMove4Texture.loadFromFile("Images/boneWallSheet.png");
	necromancerMove5Texture.loadFromFile("Images/soulBlastSheet.png");
	necromancerMove6Texture.loadFromFile("Images/deadmansHealSheet.png");
	necromancerMove7Texture.loadFromFile("Images/decayAuraSheet.png");
	necromancerMove8Texture.loadFromFile("Images/scytheStormSheet.png");



	//necro bar textures
	necroBarBorderTexture.loadFromFile("Images/soulBarBorder.png");
	necroBarTexture.loadFromFile("Images/soulBar.png");

	//bone wall texture
	boneWallTexture.loadFromFile("Images/boneWall.png");
}



void  VisibleObjectManager::loadManaBar1Player1(sf::Texture & texture)
{
	//Loads backround image and applies it to a sprite

	ManaBar1Player1.setTexture(texture);
}

void  VisibleObjectManager::loadManaBar2Player1(sf::Texture & texture)
{
	//Loads backround image and applies it to a sprite
	ManaBar2Player1.setTexture(texture);
}

void  VisibleObjectManager::loadManaBar1Player2(sf::Texture & texture)
{
	//Loads backround image and applies it to a sprite
	ManaBar1Player2.setTexture(texture);
}

void  VisibleObjectManager::loadManaBar2Player2(sf::Texture & texture)
{
	//Loads backround image and applies it to a sprite
	ManaBar2Player2.setTexture(texture);
}


void VisibleObjectManager::loadBattleArena(int load, sf::RenderWindow & renderWindow)
{

	//Loads backround image and applies it to a sprite
	battleMap.setTexture(battleMapTexture);

	//creates a vector to holds the screens x and y positions
	sf::Vector2f windowSize(renderWindow.getView().getSize().x, renderWindow.getView().getSize().y);

	//scales them to the size of the users window bounds
	battleMap.scale(windowSize.x / battleMap.getLocalBounds().width, windowSize.y / battleMap.getLocalBounds().height);

}




void VisibleObjectManager::loadSplashScreen(int load)
{
	splashScreen->setTexture(splashTexture);
}

sf::Sprite * VisibleObjectManager::returnSplashScreen()
{
	return splashScreen;
}

void VisibleObjectManager::loadFonts()
{
	if (!font.loadFromFile("Text/times.ttf")) return;
}

void VisibleObjectManager::loadSoulBarPlayer1()
{
	necroBarPlayer1.setTexture(necroBarTexture);
	necroBarBorderPlayer1.setTexture(necroBarBorderTexture);
	necroBarPlayer1.setPosition(635, 112);
	necroBarBorderPlayer1.setPosition(550, 90);
}

void VisibleObjectManager::loadSoulBarPlayer2()
{
	necroBarPlayer2.setTexture(necroBarTexture);
	necroBarBorderPlayer2.setTexture(necroBarBorderTexture);
	necroBarPlayer2.setPosition(1235, 112);
	necroBarBorderPlayer2.setPosition(1150, 90);
}



//mana aura
void VisibleObjectManager::manaAura(int &counter, int player)
{
	double player1PassedTime = (double)(player1ManaClock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2ManaClock.getElapsedTime().asSeconds());



	//Caps frame speed
	if (player1PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1ManaAura.setTexture(manaAuraTexture);
			player1ManaAura.setScale(2, 2);



			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				player1ManaAura.setTextureRect(sf::IntRect(18, 19, 225, 233));
			}
			else if (counter == 2)
			{
				player1ManaAura.setTextureRect(sf::IntRect(276, 19, 225, 233));
			}
			else if (counter == 3)
			{
				player1ManaAura.setTextureRect(sf::IntRect(527, 19, 225, 233));
			}
			else if (counter == 4)
			{
				player1ManaAura.setTextureRect(sf::IntRect(784, 19, 225, 233));
			}
			else if (counter == 5)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1034, 19, 225, 233));
			}
			else if (counter == 6)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1293, 19, 225, 233));
			}
			else if (counter == 7)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1547, 19, 225, 233));
			}
			else if (counter == 8)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1800, 19, 225, 233));
			}
			else if (counter == 9)
			{
				player1ManaAura.setTextureRect(sf::IntRect(276, 263, 225, 233));
			}
			else if (counter == 10)
			{
				player1ManaAura.setTextureRect(sf::IntRect(527, 263, 225, 233));
			}
			else if (counter == 11)
			{
				player1ManaAura.setTextureRect(sf::IntRect(784, 263, 225, 233));
			}
			else if (counter == 12)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1034, 263, 225, 233));
			}
			else if (counter == 13)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1293, 263, 225, 233));
			}
			else if (counter == 14)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1547, 263, 225, 233));
			}
			else if (counter == 15)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1800, 263, 225, 233));
			}
			else if (counter == 16)
			{
				player1ManaAura.setTextureRect(sf::IntRect(276, 263, 225, 233));
			}
			else if (counter == 17)
			{
				player1ManaAura.setTextureRect(sf::IntRect(527, 523, 225, 233));
			}
			else if (counter == 18)
			{
				player1ManaAura.setTextureRect(sf::IntRect(784, 523, 225, 233));
			}
			else if (counter == 19)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1034, 523, 225, 233));
			}
			else if (counter == 20)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1293, 523, 225, 233));
			}
			else if (counter == 21)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1547, 523, 225, 233));
			}
			else if (counter == 22)
			{
				player1ManaAura.setTextureRect(sf::IntRect(1800, 523, 225, 233));
			}
			else if (counter == 23)
			{
				player1ManaAura.setTextureRect(sf::IntRect(18, 523, 225, 233));
			}
			else if (counter == 24)
			{
				player1ManaAura.setTextureRect(sf::IntRect(18, 523, 225, 233));
			}
			else if (counter >= 24)
			{
				counter = 0;
			}
			player1ManaClock.restart();
			counter++;
		}
	}

	//Caps frame speed
	if (player2PassedTime >= 0.04)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2ManaAura.setTexture(manaAuraTexture);
			player2ManaAura.setScale(2, 2);



			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				player2ManaAura.setTextureRect(sf::IntRect(18, 19, 225, 233));
			}
			else if (counter == 2)
			{
				player2ManaAura.setTextureRect(sf::IntRect(276, 19, 225, 233));
			}
			else if (counter == 3)
			{
				player2ManaAura.setTextureRect(sf::IntRect(527, 19, 225, 233));
			}
			else if (counter == 4)
			{
				player2ManaAura.setTextureRect(sf::IntRect(784, 19, 225, 233));
			}
			else if (counter == 5)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1034, 19, 225, 233));
			}
			else if (counter == 6)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1293, 19, 225, 233));
			}
			else if (counter == 7)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1547, 19, 225, 233));
			}
			else if (counter == 8)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1800, 19, 225, 233));
			}
			else if (counter == 9)
			{
				player2ManaAura.setTextureRect(sf::IntRect(276, 263, 225, 233));
			}
			else if (counter == 10)
			{
				player2ManaAura.setTextureRect(sf::IntRect(527, 263, 225, 233));
			}
			else if (counter == 11)
			{
				player2ManaAura.setTextureRect(sf::IntRect(784, 263, 225, 233));
			}
			else if (counter == 12)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1034, 263, 225, 233));
			}
			else if (counter == 13)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1293, 263, 225, 233));
			}
			else if (counter == 14)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1547, 263, 225, 233));
			}
			else if (counter == 15)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1800, 263, 225, 233));
			}
			else if (counter == 16)
			{
				player2ManaAura.setTextureRect(sf::IntRect(276, 263, 225, 233));
			}
			else if (counter == 17)
			{
				player2ManaAura.setTextureRect(sf::IntRect(527, 523, 225, 233));
			}
			else if (counter == 18)
			{
				player2ManaAura.setTextureRect(sf::IntRect(784, 523, 225, 233));
			}
			else if (counter == 19)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1034, 523, 225, 233));
			}
			else if (counter == 20)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1293, 523, 225, 233));
			}
			else if (counter == 21)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1547, 523, 225, 233));
			}
			else if (counter == 22)
			{
				player2ManaAura.setTextureRect(sf::IntRect(1800, 523, 225, 233));
			}
			else if (counter == 23)
			{
				player2ManaAura.setTextureRect(sf::IntRect(18, 523, 225, 233));
			}
			else if (counter == 24)
			{
				player2ManaAura.setTextureRect(sf::IntRect(18, 523, 225, 233));
			}
			else if (counter >= 24)
			{
				counter = 0;
			}
			player2ManaClock.restart();
			counter++;
		}
	}
}


void VisibleObjectManager::showSkillAnimation(int counter, sf::RenderWindow & renderWindow, string & player1Choice, string & player2Choice)
{
	skillAnim1.setString(player1Choice);
	skillAnim2.setString(player2Choice);

	SkillBoxAnim1.setTexture(SkillMenuPlayerSkillTexture);
	SkillBoxAnim2.setTexture(SkillMenuPlayerSkillTexture);

	if (SkillMenuPlayer1Skill1.getPosition().y > 300)
	{

		skillAnim1.move(0, -10);
		skillAnim2.move(0, -10);
	
		SkillMenuPlayer1Skill1.move(0, -10);
		SkillMenuPlayer2Skill1.move(0, -10);
	}
	else if(SkillMenuPlayer1Skill1.getPosition().x < 630)
	{
		skillAnim1.move(5, 0);
		skillAnim2.move(-5, 0);
		SkillMenuPlayer1Skill1.move(5, 0);
		SkillMenuPlayer2Skill1.move(-5, 0);
	}
	else if(SkillMenuPlayer1Skill1.getPosition().x >= 630)
	{
		static int switchCase = 0;
		if (switchCase == 10)
		{
			SkillMenuPlayer1Skill1.setColor(sf::Color::Transparent);
			SkillMenuPlayer2Skill1.setColor(sf::Color::Transparent);
		}
		else if (switchCase == 15)
		{
			SkillMenuPlayer1Skill1.setColor(sf::Color::White);
			SkillMenuPlayer2Skill1.setColor(sf::Color::White);
			switchCase = 0;
		}
		switchCase++;
	}

	renderWindow.draw(SkillMenuPlayer1Skill1);
	renderWindow.draw(SkillMenuPlayer2Skill1);
	renderWindow.draw(skillAnim1);
	renderWindow.draw(skillAnim2);
}


//MONK//////////////
void VisibleObjectManager::monkIdle(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 310;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 320;
	vec1Player2.y = 310;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1350;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.11)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(monkIdleTexture);
			player1Character.setTextureRect(sf::IntRect(7, 0, 319, 585));


			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(7, 587, 318, 585));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 0);
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(663, 587, 318, 585));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, 0);
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(331, 1176, 318, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(1, 0);
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(977, 1177, 319, 579));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -1);
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(980, 0, 316, 579));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -2);
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1299, 0, 316, 579));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(1, 0);
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1303, 583, 314, 576));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, 0);
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1618, 1163, 307, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -1);
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1930, 1156, 306, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2242, 1155, 303, 568));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2240, 2, 304, 565));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2547, 0, 304, 565));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(1, 0);
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2550, 1135, 302, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, -2);
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2856, 567, 299, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2856, 1131, 299, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2855, 2, 301, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(1, -2);
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2549, 570, 302, 561));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(1, -1);
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2241, 572, 304, 565));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(1, 1);
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1932, 3, 307, 565));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, -1);
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1932, 582, 307, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, 0);
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1619, 581, 310, 573));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, 1);
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1619, 2, 311, 574));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, -1);
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1302, 1168, 311, 576));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -1);
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(985, 587, 315, 576));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(1, -1);
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(657, 2, 321, 581));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(3, 1);
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(652, 1175, 323, 581));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, -1);
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1175, 323, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -1);
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(327, 589, 326, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(1, -1);
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(329, 2, 326, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, -1);
			}
			else if (counter > 29)
			{
				player1Character.move(6, -2);
				counter = 0;
			}
			player1Clock.restart();
			counter++;
		}
	}


	//Caps frame speed
	if (player2PassedTime >= 0.11)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(monkIdleTexture);
			player2Character.setTextureRect(sf::IntRect(7, 0, 319, 585));


			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(7, 587, 318, 585));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 0);
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(663, 587, 318, 585));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, 0);
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(331, 1176, 318, 582));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-1, 0);
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(977, 1177, 319, 579));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -1);
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(980, 0, 316, 579));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -2);
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1299, 0, 316, 579));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-1, 0);
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1303, 583, 314, 576));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, 0);
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1618, 1163, 307, 572));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -1);
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1930, 1156, 306, 571));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2242, 1155, 303, 568));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2240, 2, 304, 565));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2547, 0, 304, 565));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-1, 0);
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2550, 1135, 302, 560));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, -2);
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2856, 567, 299, 560));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2856, 1131, 299, 560));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2855, 2, 301, 559));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-1, -2);
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2549, 570, 302, 561));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-1, -1);
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2241, 572, 304, 565));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-1, 1);
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1932, 3, 307, 565));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, -1);
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1932, 582, 307, 569));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, 0);
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1619, 581, 310, 573));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, 1);
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1619, 2, 311, 574));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, -1);
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1302, 1168, 311, 576));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -1);
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(985, 587, 315, 576));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-1, -1);
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(657, 2, 321, 581));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-3, 1);
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(652, 1175, 323, 581));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, -1);
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1175, 323, 582));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -1);
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(327, 589, 326, 582));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-1, -1);
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(329, 2, 326, 582));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, -1);
			}
			else if (counter > 29)
			{
				player2Character.move(-6, -2);
				counter = 0;
			}
			player2Clock.restart();
			counter++;
		}
	}


}

//push strike
void VisibleObjectManager::monkMove1(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 360;
	vec1.y = 334;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 320;
	vec1Player2.y = 310;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1350;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(monkMove1Texture);
			player1Character.setTextureRect(sf::IntRect(942, 554, 372, 601));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1281, 1719, 376, 586));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 3334, 394, 580));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(399, 3335, 405, 574));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1615, 0, 407, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1110, 3330, 418, 570));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 1);
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1316, 576, 433, 573));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1280, 1160, 372, 556));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(488, 2785, 473, 544));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1092, 0, 516, 541));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1730, 530, 528));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1, 2263, 541, 517));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(550, 2258, 487, 522));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(968, 2786, 338, 542));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(832, 1160, 440, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1154, 523, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(6, 579, 540, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(7, 1, 545, 573));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(562, 1, 526, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(6, 2785, 474, 543));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1656, 1145, 380, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(812, 3334, 291, 568));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(527, 1156, 296, 567));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1693, 2294, 295, 596));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1662, 1685, 362, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1535, 2901, 384, 553));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(906, 1722, 372, 522));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(532, 1728, 367, 525));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(549, 580, 390, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1309, 2309, 379, 586));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 29)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "monkIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}



	//Caps frame speed
	if (player2PassedTime >= 0.04)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(monkMove1Texture);
			player2Character.setTextureRect(sf::IntRect(942, 554, 372, 601));
			//player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1281, 1719, 376, 586));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 3334, 394, 580));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(399, 3335, 405, 574));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1615, 0, 407, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1110, 3330, 418, 570));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1316, 576, 433, 545));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1280, 1160, 372, 556));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(488, 2785, 473, 544));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1092, 0, 516, 541));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1730, 530, 528));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1, 2263, 541, 517));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(550, 2258, 487, 522));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(968, 2786, 338, 542));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(832, 1160, 440, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1154, 523, 572));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(6, 579, 540, 572));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(7, 1, 545, 573));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(562, 1, 526, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(6, 2785, 474, 543));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1656, 1145, 380, 534));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(812, 3334, 291, 568));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(527, 1156, 296, 567));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1693, 2294, 295, 596));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1662, 1685, 362, 604));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1535, 2901, 384, 553));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(906, 1722, 372, 522));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(532, 1728, 367, 525));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(549, 580, 390, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1309, 2309, 379, 586));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 29)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "monkIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//step in
void VisibleObjectManager::monkMove2(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.02)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(monkMove2Texture);
			player1Character.setTextureRect(sf::IntRect(1277, 1039, 320, 581));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1277, 1039, 320, 581));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(955, 1015, 315, 578));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(631, 990, 315, 576));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(319, 974, 304, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3, 955, 306, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1282, 488, 300, 545));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(976, 477, 300, 536));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(669, 465, 304, 522));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(342, 459, 316, 510));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 457, 334, 494));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1456, 0, 334, 482));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1098, 0, 347, 472));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(740, 0, 351, 462));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(374, 0, 357, 458));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(6, 0, 360, 456));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter >= 15)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "monkStepinIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}

	//Caps frame speed
	if (player2PassedTime >= 0.02)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(monkMove2Texture);
			player2Character.setTextureRect(sf::IntRect(1277, 1039, 320, 581));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1277, 1039, 320, 581));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(955, 1015, 315, 578));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(631, 990, 315, 576));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(319, 974, 304, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3, 955, 306, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1282, 488, 300, 545));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(976, 477, 300, 536));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(669, 465, 304, 522));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(342, 459, 316, 510));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 457, 334, 494));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1456, 0, 334, 482));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1098, 0, 347, 472));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(740, 0, 351, 462));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(374, 0, 357, 458));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(6, 0, 360, 456));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter >= 15)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "monkStepinIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//piercing kick
void VisibleObjectManager::monkMove3(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(monkMove3Texture);
			player1Character.setTextureRect(sf::IntRect(895, 587, 372, 588));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(895, 587, 372, 588));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2758, 580, 356, 548));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1958, 1131, 357, 536));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1581, 0, 507, 566));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 542, 566));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 571, 520, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(544, 1, 518, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1064, 0, 510, 579));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2091, 0, 494, 579));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1158, 475, 577));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2585, 0, 452, 577));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3038, 0, 424, 568));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1636, 569, 390, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2404, 582, 349, 550));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3113, 573, 349, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2687, 1136, 360, 528));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3049, 1131, 366, 525));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2315, 1135, 369, 535));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1219, 1179, 367, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1587, 1168, 371, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2029, 583, 370, 541));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(847, 1178, 370, 551));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(523, 585, 371, 570));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(475, 1157, 371, 581));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1267, 578, 369, 586));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 25)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "monkIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.04)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(monkMove3Texture);
			player2Character.setTextureRect(sf::IntRect(895, 587, 372, 588));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(895, 587, 372, 588));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2758, 580, 356, 548));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1958, 1131, 357, 536));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1581, 0, 507, 566));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 542, 566));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 571, 520, 582));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(544, 1, 518, 582));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1064, 0, 510, 579));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2091, 0, 494, 579));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1158, 475, 577));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2585, 0, 452, 577));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3038, 0, 424, 568));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1636, 569, 390, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2404, 582, 349, 550));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3113, 573, 349, 537));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2687, 1136, 360, 528));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3049, 1131, 366, 525));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2315, 1135, 369, 535));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1219, 1179, 367, 537));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1587, 1168, 371, 537));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2029, 583, 370, 541));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(847, 1178, 370, 551));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(523, 585, 371, 570));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(475, 1157, 371, 581));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1267, 578, 369, 586));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 25)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "monkIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//right elbow
void VisibleObjectManager::monkMove4(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.03)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(monkMove4Texture);
			player1Character.setTextureRect(sf::IntRect(0, 2328, 398, 590));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1, 1740, 411, 585));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1160, 422, 576));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(893, 0, 431, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1492, 3485, 435, 558));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(770, 3519, 441, 546));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3, 3522, 447, 546));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1325, 0, 453, 542));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 453, 570));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(861, 573, 369, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(401, 2328, 342, 591));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 572, 431, 586));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(458, 0, 433, 573));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(435, 576, 423, 566));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(808, 1182, 424, 566));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(775, 1753, 424, 566));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1236, 1173, 424, 566));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1201, 1748, 425, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1493, 2916, 417, 567));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1630, 1741, 399, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(427, 1160, 378, 568));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(413, 1739, 357, 578));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1685, 2307, 329, 586));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1396, 2322, 291, 591));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1612, 545, 264, 594));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1667, 1141, 268, 594));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(748, 2320, 302, 594));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1056, 2320, 330, 592));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1138, 2917, 351, 595));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(773, 2918, 361, 595));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1233, 572, 372, 596));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(389, 2922, 378, 598));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 2924, 385, 598));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 32)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "monkIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.03)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(monkMove4Texture);
			player2Character.setTextureRect(sf::IntRect(0, 2328, 398, 590));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1, 1740, 411, 585));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1160, 422, 576));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(893, 0, 431, 569));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1492, 3485, 435, 558));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(770, 3519, 441, 546));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3, 3522, 447, 546));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1325, 0, 453, 542));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 453, 570));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(861, 573, 369, 604));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(401, 2328, 342, 591));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 572, 431, 586));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(458, 0, 433, 573));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(435, 576, 423, 566));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(808, 1182, 424, 566));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(775, 1753, 424, 566));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1236, 1173, 424, 566));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1201, 1748, 425, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1493, 2916, 417, 567));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1630, 1741, 399, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(427, 1160, 378, 568));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(413, 1739, 357, 578));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1685, 2307, 329, 586));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1396, 2322, 291, 591));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1612, 545, 264, 594));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1667, 1141, 268, 594));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(748, 2320, 302, 594));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1056, 2320, 330, 592));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1138, 2917, 351, 595));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(773, 2918, 361, 595));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1233, 572, 372, 596));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(389, 2922, 378, 598));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 2924, 385, 598));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 32)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "monkIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//elbow parry
void VisibleObjectManager::monkMove5(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(monkMove5Texture);
			player1Character.setTextureRect(sf::IntRect(467, 2266, 372, 585));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(540, 597, 373, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1500, 3374, 367, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1552, 2254, 360, 526));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(517, 1750, 373, 486));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(894, 1750, 383, 469));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 3403, 402, 550));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 2829, 444, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1224, 2800, 411, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(453, 2854, 407, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			//actual moment of blocking
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(544, 1182, 409, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(544, 1182, 409, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(544, 1182, 409, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(544, 1182, 409, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(544, 1182, 409, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			//end blocking sequence


			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1130, 3411, 367, 545));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1292, 546, 288, 532));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(801, 3423, 321, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1560, 1711, 361, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1585, 587, 344, 540));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1637, 2782, 256, 533));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(402, 3423, 391, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3, 0, 537, 594));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(4, 598, 533, 570));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(546, 0, 533, 552));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2, 1173, 532, 542));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1084, 0, 531, 541));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1721, 510, 541));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 2267, 463, 555));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1331, 1132, 419, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1178, 2223, 368, 578));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1626, 3, 306, 580));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(841, 2240, 335, 578));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(862, 2824, 359, 583));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(917, 558, 369, 583));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(955, 1146, 371, 585));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter >= 35)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "monkIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.04)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(monkMove5Texture);
			player2Character.setTextureRect(sf::IntRect(467, 2266, 372, 585));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(540, 597, 373, 582));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1500, 3374, 367, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1552, 2254, 360, 526));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(517, 1750, 373, 486));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(894, 1750, 383, 469));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 3403, 402, 550));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 2829, 444, 569));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1224, 2800, 411, 569));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(453, 2854, 407, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			//actual moment of blocking
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(544, 1182, 409, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(544, 1182, 409, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(544, 1182, 409, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(544, 1182, 409, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(544, 1182, 409, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			//end blocking sequence


			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1130, 3411, 367, 545));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1292, 546, 288, 532));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(801, 3423, 321, 537));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1560, 1711, 361, 537));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1585, 587, 344, 540));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1637, 2782, 256, 533));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(402, 3423, 391, 537));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3, 0, 537, 594));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(4, 598, 533, 570));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(546, 0, 533, 552));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2, 1173, 532, 542));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1084, 0, 531, 541));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1721, 510, 541));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 2267, 463, 555));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1331, 1132, 419, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1178, 2223, 368, 578));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1626, 3, 306, 580));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(841, 2240, 335, 578));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(862, 2824, 359, 583));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(917, 558, 369, 583));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(955, 1146, 371, 585));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter >= 35)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "monkIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}


//heavenly tackle
void VisibleObjectManager::monkMove6(int &counter, int player)

{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(monkMove6Texture);
			player1Character.setTextureRect(sf::IntRect(491, 1026, 365, 585));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1099, 1469, 363, 578));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1615, 366, 547));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1468, 1079, 355, 504));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(962, 997, 422, 468));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(498, 565, 455, 459));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1041, 0, 464, 485));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(6, 503, 482, 529));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1511, 0, 374, 531));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(738, 1616, 355, 533));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(372, 1618, 358, 533));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1515, 542, 376, 529));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1046, 489, 457, 506));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(5, 0, 532, 498));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(550, 0, 487, 558));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1470, 1586, 350, 547));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1035, 356, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1035, 356, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1470, 1586, 350, 547));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(550, 0, 487, 558));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(5, 0, 532, 498));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1046, 489, 457, 506));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1515, 542, 376, 529));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(372, 1618, 358, 533));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(738, 1616, 355, 533));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1511, 0, 374, 531));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(6, 503, 482, 529));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1041, 0, 464, 485));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(498, 565, 455, 459));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(962, 997, 422, 468));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1468, 1079, 355, 504));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1615, 366, 547));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1099, 1469, 363, 578));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 32)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "monkIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.04)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(monkMove6Texture);
			player2Character.setTextureRect(sf::IntRect(491, 1026, 365, 585));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1099, 1469, 363, 578));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1615, 366, 547));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1468, 1079, 355, 504));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(962, 997, 422, 468));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(498, 565, 455, 459));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1041, 0, 464, 485));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(6, 503, 482, 529));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1511, 0, 374, 531));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(738, 1616, 355, 533));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(372, 1618, 358, 533));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1515, 542, 376, 529));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1046, 489, 457, 506));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(5, 0, 532, 498));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(550, 0, 487, 558));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1470, 1586, 350, 547));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1035, 356, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1035, 356, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1470, 1586, 350, 547));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(550, 0, 487, 558));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(5, 0, 532, 498));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1046, 489, 457, 506));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1515, 542, 376, 529));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(372, 1618, 358, 533));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(738, 1616, 355, 533));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1511, 0, 374, 531));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(6, 503, 482, 529));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1041, 0, 464, 485));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(498, 565, 455, 459));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(962, 997, 422, 468));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1468, 1079, 355, 504));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1615, 366, 547));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1099, 1469, 363, 578));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 32)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "monkIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//inhuman speed
void VisibleObjectManager::monkMove7(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(monkMove7Texture);
			player1Character.setTextureRect(sf::IntRect(1407, 0, 318, 584));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1082, 0, 318, 584));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(737, 0, 338, 584));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 582, 356, 584));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 364, 584));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(369, 0, 364, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2061, 0, 357, 532));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2429, 0, 367, 516));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3191, 519, 368, 501));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2961, 1059, 366, 493));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3341, 1069, 367, 496));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2581, 1087, 370, 498));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2202, 1096, 369, 500));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1066, 1119, 368, 502));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1825, 1095, 368, 505));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1814, 585, 368, 507));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1446, 1101, 368, 512));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1435, 586, 368, 512));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2806, 0, 369, 515));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3187, 0, 369, 515));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3565, 0, 369, 515));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(691, 590, 369, 512));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(690, 1105, 368, 516));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1072, 589, 350, 524));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2824, 518, 337, 536));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3571, 519, 326, 546));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2190, 536, 319, 556));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2513, 520, 319, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(362, 582, 319, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1407, 0, 318, 584));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 29)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "monkIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.04)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(monkMove7Texture);
			player2Character.setTextureRect(sf::IntRect(1407, 0, 318, 584));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1082, 0, 318, 584));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(737, 0, 338, 584));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 582, 356, 584));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 364, 584));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(369, 0, 364, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2061, 0, 357, 532));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2429, 0, 367, 516));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3191, 519, 368, 501));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2961, 1059, 366, 493));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3341, 1069, 367, 496));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2581, 1087, 370, 498));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2202, 1096, 369, 500));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1066, 1119, 368, 502));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1825, 1095, 368, 505));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1814, 585, 368, 507));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1446, 1101, 368, 512));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1435, 586, 368, 512));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2806, 0, 369, 515));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3187, 0, 369, 515));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3565, 0, 369, 515));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(691, 590, 369, 512));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(690, 1105, 368, 516));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1072, 589, 350, 524));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2824, 518, 337, 536));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3571, 519, 326, 546));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2190, 536, 319, 556));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2513, 520, 319, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(362, 582, 319, 572));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1407, 0, 318, 584));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 29)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "monkIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}


//meditate
void VisibleObjectManager::monkMove8(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(monkMove8Texture);
			player1Character.setTextureRect(sf::IntRect(6, 1265, 308, 583));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(317, 1265, 331, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1398, 919, 384, 514));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(998, 388, 408, 484));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(654, 1354, 391, 492));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1049, 877, 346, 504));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(654, 829, 337, 522));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1411, 387, 381, 529));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(5, 750, 426, 512));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(520, 330, 476, 495));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 287, 517, 460));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1224, 0, 551, 383));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(638, 0, 582, 326));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}


			//start of mid meditate
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));


			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(638, 0, 582, 326));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1224, 0, 551, 383));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 287, 517, 460));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(520, 330, 476, 495));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(5, 750, 426, 512));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1411, 387, 381, 529));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(654, 829, 337, 522));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1049, 877, 346, 504));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(654, 1354, 391, 492));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(998, 388, 408, 484));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1398, 919, 384, 514));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(317, 1265, 331, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 31)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "monkIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.04)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(monkMove8Texture);
			player2Character.setTextureRect(sf::IntRect(6, 1265, 308, 583));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(317, 1265, 331, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1398, 919, 384, 514));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(998, 388, 408, 484));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(654, 1354, 391, 492));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1049, 877, 346, 504));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(654, 829, 337, 522));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1411, 387, 381, 529));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(5, 750, 426, 512));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(520, 330, 476, 495));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 287, 517, 460));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1224, 0, 551, 383));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(638, 0, 582, 326));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}


			//start of mid meditate
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));


			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 633, 281));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(638, 0, 582, 326));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1224, 0, 551, 383));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 287, 517, 460));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(520, 330, 476, 495));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(5, 750, 426, 512));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1411, 387, 381, 529));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(654, 829, 337, 522));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1049, 877, 346, 504));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(654, 1354, 391, 492));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(998, 388, 408, 484));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1398, 919, 384, 514));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(317, 1265, 331, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 31)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "monkIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}

}

//stepin idle
void VisibleObjectManager::monkStepinIdle(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(monkStepinIdleTexture);
			player1Character.setTextureRect(sf::IntRect(1596, 1422, 396, 486));
			//player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1596, 1422, 396, 486));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1196, 1418, 401, 486));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1410, 400, 483));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2436, 943, 399, 482));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1628, 939, 402, 478));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(818, 936, 403, 475));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 933, 409, 472));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2090, 467, 409, 468));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1260, 465, 411, 468));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3, 464, 415, 465));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2133, 0, 416, 465));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1283, 0, 420, 465));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(5, 0, 420, 462));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(432, 0, 420, 462));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(859, 0, 420, 462));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1707, 0, 420, 462));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));


			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2555, 0, 417, 462));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(424, 463, 415, 467));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(843, 466, 412, 466));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1676, 466, 412, 470));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2503, 467, 407, 474));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(409, 934, 406, 471));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1223, 937, 402, 478));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2033, 941, 402, 478));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2836, 944, 400, 482));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(402, 1410, 395, 486));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(800, 1413, 395, 485));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1990, 1425, 398, 487));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2786, 1429, 395, 487));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 29)
			{
				counter = 1;
				player1MoveFinished = false;

			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.04)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(monkStepinIdleTexture);
			player2Character.setTextureRect(sf::IntRect(1596, 1422, 396, 486));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1596, 1422, 396, 486));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1196, 1418, 401, 486));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1410, 400, 483));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2436, 943, 399, 482));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1628, 939, 402, 478));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(818, 936, 403, 475));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 933, 409, 472));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2090, 467, 409, 468));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1260, 465, 411, 468));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3, 464, 415, 465));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2133, 0, 416, 465));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1283, 0, 420, 465));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(5, 0, 420, 462));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(432, 0, 420, 462));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(859, 0, 420, 462));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1707, 0, 420, 462));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));


			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2555, 0, 417, 462));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(424, 463, 415, 467));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(843, 466, 412, 466));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1676, 466, 412, 470));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2503, 467, 407, 474));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(409, 934, 406, 471));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1223, 937, 402, 478));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2033, 941, 402, 478));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2836, 944, 400, 482));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(402, 1410, 395, 486));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(800, 1413, 395, 485));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1990, 1425, 398, 487));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2786, 1429, 395, 487));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 29)
			{
				counter = 1;
				player2MoveFinished = false;

			}
			player2Clock.restart();
			counter++;
		}
	}

}


//right elbow
void VisibleObjectManager::monkHurt(int& counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.05)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(monkMove4Texture);
			player1Character.setTextureRect(sf::IntRect(0, 2328, 398, 590));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1, 1740, 411, 585));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1160, 422, 576));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(893, 0, 431, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1492, 3485, 435, 558));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(770, 3519, 441, 546));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3, 3522, 447, 546));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1325, 0, 453, 542));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 453, 570));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(861, 573, 369, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(401, 2328, 342, 591));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 10)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "monkIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.05)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(monkMove4Texture);
			player2Character.setTextureRect(sf::IntRect(0, 2328, 398, 590));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1, 1740, 411, 585));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1160, 422, 576));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(893, 0, 431, 569));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1492, 3485, 435, 558));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(770, 3519, 441, 546));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3, 3522, 447, 546));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1325, 0, 453, 542));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 453, 570));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(861, 573, 369, 604));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(401, 2328, 342, 591));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 10)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "monkIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}


//WARRIOR///////////


//idle
void VisibleObjectManager::warriorIdle(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());
	

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;

	sf::Vector2f vec2;
	vec2.x = 393;
	vec2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.15)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(warriorIdleTexture);




			//controls current sprite showing on the sprite sheet

			if (counter == 1)
			{
				player1Character.setPosition(500, 300);
				player1Character.setTextureRect(sf::IntRect(3553, 550, 393, 550));


			}
			else if (counter == 2)
			{
				player1Character.setPosition(501, 301);
				player1Character.setTextureRect(sf::IntRect(2769, 550, 394, 550));


			}
			else if (counter == 3)
			{
				player1Character.setPosition(500, 302);
				player1Character.setTextureRect(sf::IntRect(1982, 550, 396, 550));


			}
			else if (counter == 4)
			{
				player1Character.setPosition(501, 305);
				player1Character.setTextureRect(sf::IntRect(796, 551, 395, 550));


			}
			else if (counter == 5)
			{
				player1Character.setPosition(502, 302);
				player1Character.setTextureRect(sf::IntRect(1194, 548, 395, 550));


			}
			else if (counter == 6)
			{
				player1Character.setPosition(501, 303);
				player1Character.setTextureRect(sf::IntRect(0, 548, 395, 550));


			}
			else if (counter == 7)
			{
				player1Character.setPosition(501, 305);
				player1Character.setTextureRect(sf::IntRect(398, 550, 395, 550));


			}
			else if (counter == 8)
			{
				player1Character.setPosition(501, 304);
				player1Character.setTextureRect(sf::IntRect(1976, 0, 395, 550));


			}
			else if (counter == 9)
			{
				player1Character.setPosition(502, 304);
				player1Character.setTextureRect(sf::IntRect(2375, 0, 394, 550));


			}
			else if (counter == 10)
			{
				player1Character.setPosition(500, 305);
				player1Character.setTextureRect(sf::IntRect(0, 0, 394, 550));


			}
			else if (counter == 11)
			{
				player1Character.setPosition(501, 305);
				player1Character.setTextureRect(sf::IntRect(398, 0, 394, 550));


			}
			else if (counter == 12)
			{
				player1Character.setPosition(501, 305);
				player1Character.setTextureRect(sf::IntRect(794, 0, 394, 550));


			}
			else if (counter == 13)
			{
				player1Character.setPosition(499, 305);
				player1Character.setTextureRect(sf::IntRect(1187, 0, 394, 550));


			}
			else if (counter == 14)
			{
				player1Character.setPosition(500, 305);
				player1Character.setTextureRect(sf::IntRect(1582, 0, 394, 550));


			}
			else if (counter == 15)
			{
				player1Character.setPosition(501, 304);
				player1Character.setTextureRect(sf::IntRect(2773, 0, 390, 550));


			}
			else if (counter == 16)
			{

				player1Character.setTextureRect(sf::IntRect(3167, 0, 390, 550));


			}
			else if (counter == 17)
			{
				player1Character.setPosition(502, 303);
				player1Character.setTextureRect(sf::IntRect(3561, 0, 390, 550));


			}
			else if (counter == 18)
			{
				player1Character.setPosition(501, 304);
				player1Character.setTextureRect(sf::IntRect(3167, 0, 390, 550));


			}
			else if (counter == 19)
			{
				player1Character.setPosition(501, 304);
				player1Character.setTextureRect(sf::IntRect(2773, 0, 390, 550));


			}
			else if (counter == 20)
			{
				player1Character.setPosition(500, 305);
				player1Character.setTextureRect(sf::IntRect(1582, 0, 394, 550));


			}
			else if (counter == 21)
			{
				player1Character.setPosition(499, 305);
				player1Character.setTextureRect(sf::IntRect(1187, 0, 394, 550));


			}
			else if (counter == 22)
			{
				player1Character.setPosition(501, 305);
				player1Character.setTextureRect(sf::IntRect(794, 0, 394, 550));


			}
			else if (counter == 23)
			{
				player1Character.setPosition(501, 305);
				player1Character.setTextureRect(sf::IntRect(398, 0, 394, 550));


			}
			else if (counter == 24)
			{
				player1Character.setPosition(500, 305);
				player1Character.setTextureRect(sf::IntRect(0, 0, 394, 550));


			}
			else if (counter == 25)
			{
				player1Character.setPosition(502, 304);
				player1Character.setTextureRect(sf::IntRect(2375, 0, 394, 550));


			}
			else if (counter == 26)
			{
				player1Character.setPosition(501, 304);
				player1Character.setTextureRect(sf::IntRect(1976, 0, 395, 550));


			}
			else if (counter == 27)
			{
				player1Character.setPosition(501, 305);
				player1Character.setTextureRect(sf::IntRect(398, 550, 395, 550));


			}
			else if (counter == 28)
			{
				player1Character.setPosition(501, 303);
				player1Character.setTextureRect(sf::IntRect(0, 548, 395, 550));


			}

			else if (counter == 29)
			{
				player1Character.setPosition(502, 302);
				player1Character.setTextureRect(sf::IntRect(1194, 548, 395, 550));


			}
			else if (counter == 30)
			{
				player1Character.setPosition(501, 305);
				player1Character.setTextureRect(sf::IntRect(796, 551, 395, 550));


			}
			else if (counter == 31)
			{
				player1Character.setPosition(500, 302);
				player1Character.setTextureRect(sf::IntRect(1982, 550, 396, 550));


			}
			else if (counter == 32)
			{
				player1Character.setPosition(501, 301);
				player1Character.setTextureRect(sf::IntRect(2769, 550, 394, 550));


			}
			else if (counter > 33)
			{
				counter = 1;
			}
			player1Clock.restart();
			counter++;
		}
	}

	//Caps frame speed
	if (player2PassedTime >= 0.15)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(warriorIdleTexture);




			//controls current sprite showing on the sprite sheet

			if (counter == 1)
			{
				player2Character.setPosition(1420, 300);
				player2Character.setTextureRect(sf::IntRect(3553, 550, 393, 550));



			}
			else if (counter == 2)
			{
				player2Character.setPosition(1419, 301);
				player2Character.setTextureRect(sf::IntRect(2769, 550, 394, 550));


			}
			else if (counter == 3)
			{
				player2Character.setPosition(1420, 302);
				player2Character.setTextureRect(sf::IntRect(1982, 550, 396, 550));


			}
			else if (counter == 4)
			{
				player2Character.setPosition(1419, 305);
				player2Character.setTextureRect(sf::IntRect(796, 551, 395, 550));


			}
			else if (counter == 5)
			{
				player2Character.setPosition(1418, 302);
				player2Character.setTextureRect(sf::IntRect(1194, 548, 395, 550));


			}
			else if (counter == 6)
			{
				player2Character.setPosition(1419, 303);
				player2Character.setTextureRect(sf::IntRect(0, 548, 395, 550));


			}
			else if (counter == 7)
			{
				player2Character.setPosition(1419, 305);
				player2Character.setTextureRect(sf::IntRect(398, 550, 395, 550));


			}
			else if (counter == 8)
			{
				player2Character.setPosition(1419, 304);
				player2Character.setTextureRect(sf::IntRect(1976, 0, 395, 550));


			}
			else if (counter == 9)
			{
				player2Character.setPosition(1418, 304);
				player2Character.setTextureRect(sf::IntRect(2375, 0, 394, 550));


			}
			else if (counter == 10)
			{
				player2Character.setPosition(1420, 305);
				player2Character.setTextureRect(sf::IntRect(0, 0, 394, 550));


			}
			else if (counter == 11)
			{
				player2Character.setPosition(1419, 305);
				player2Character.setTextureRect(sf::IntRect(398, 0, 394, 550));


			}
			else if (counter == 12)
			{
				player2Character.setPosition(1419, 305);
				player2Character.setTextureRect(sf::IntRect(794, 0, 394, 550));


			}
			else if (counter == 13)
			{
				player2Character.setPosition(1421, 305);
				player2Character.setTextureRect(sf::IntRect(1187, 0, 394, 550));


			}
			else if (counter == 14)
			{
				player2Character.setPosition(1420, 305);
				player2Character.setTextureRect(sf::IntRect(1582, 0, 394, 550));


			}
			else if (counter == 15)
			{
				player2Character.setPosition(1419, 304);
				player2Character.setTextureRect(sf::IntRect(2773, 0, 390, 550));


			}
			else if (counter == 16)
			{

				player2Character.setTextureRect(sf::IntRect(3167, 0, 390, 550));


			}
			else if (counter == 17)
			{
				player2Character.setPosition(1418, 303);
				player2Character.setTextureRect(sf::IntRect(3561, 0, 390, 550));


			}
			else if (counter == 18)
			{
				player2Character.setPosition(1419, 304);
				player2Character.setTextureRect(sf::IntRect(3167, 0, 390, 550));


			}
			else if (counter == 19)
			{
				player2Character.setPosition(1419, 304);
				player2Character.setTextureRect(sf::IntRect(2773, 0, 390, 550));


			}
			else if (counter == 20)
			{
				player2Character.setPosition(1420, 305);
				player2Character.setTextureRect(sf::IntRect(1582, 0, 394, 550));


			}
			else if (counter == 21)
			{
				player2Character.setPosition(1421, 305);
				player2Character.setTextureRect(sf::IntRect(1187, 0, 394, 550));


			}
			else if (counter == 22)
			{
				player2Character.setPosition(1419, 305);
				player2Character.setTextureRect(sf::IntRect(794, 0, 394, 550));


			}
			else if (counter == 23)
			{
				player2Character.setPosition(1419, 305);
				player2Character.setTextureRect(sf::IntRect(398, 0, 394, 550));


			}
			else if (counter == 24)
			{
				player2Character.setPosition(1420, 305);
				player2Character.setTextureRect(sf::IntRect(0, 0, 394, 550));


			}
			else if (counter == 25)
			{
				player2Character.setPosition(1418, 304);
				player2Character.setTextureRect(sf::IntRect(2375, 0, 394, 550));


			}
			else if (counter == 26)
			{
				player2Character.setPosition(1419, 304);
				player2Character.setTextureRect(sf::IntRect(1976, 0, 395, 550));


			}
			else if (counter == 27)
			{
				player2Character.setPosition(1419, 305);
				player2Character.setTextureRect(sf::IntRect(398, 550, 395, 550));


			}
			else if (counter == 28)
			{
				player2Character.setPosition(1419, 303);
				player2Character.setTextureRect(sf::IntRect(0, 548, 395, 550));


			}

			else if (counter == 29)
			{
				player2Character.setPosition(1418, 302);
				player2Character.setTextureRect(sf::IntRect(1194, 548, 395, 550));


			}
			else if (counter == 30)
			{
				player2Character.setPosition(1419, 305);
				player2Character.setTextureRect(sf::IntRect(796, 551, 395, 550));


			}
			else if (counter == 31)
			{
				player2Character.setPosition(1420, 302);
				player2Character.setTextureRect(sf::IntRect(1982, 550, 396, 550));


			}
			else if (counter == 32)
			{
				player2Character.setPosition(1419, 301);
				player2Character.setTextureRect(sf::IntRect(2769, 550, 394, 550));


			}
			else if (counter > 33)
			{
				counter = 1;
			}
			player2Clock.restart();
			counter++;
		}
	}


}


//stun strike
void VisibleObjectManager::warriorMove1(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;


	if (player == 1)
	{


		//Caps frame speed(0.01)
		if (player1PassedTime >= 0.01)
		{
			if (player == 1)
			{

				//controls current sprite showing on the sprite sheet
				if (counter == 1)
				{
					//sets current texture before cropping the proper sprite
					player1Character.setTexture(warriorMove1Texture);
					player1Character.setTextureRect(sf::IntRect(3662, 3145, 380, 554));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}

				else if (counter == 2)
				{
					player1Character.setTextureRect(sf::IntRect(3298, 3138, 360, 554));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 3)
				{
					player1Character.setTextureRect(sf::IntRect(287, 2890, 331, 552));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 4)
				{
					player1Character.setTextureRect(sf::IntRect(1053, 2929, 307, 552));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 5)
				{
					player1Character.setTextureRect(sf::IntRect(1815, 2940, 307, 554));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 6)
				{
					player1Character.setTextureRect(sf::IntRect(2997, 3140, 298, 554));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 7)
				{
					player1Character.setTextureRect(sf::IntRect(0, 2324, 290, 554));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 8)
				{
					player1Character.setTextureRect(sf::IntRect(2998, 2418, 284, 566));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 9)
				{
					player1Character.setTextureRect(sf::IntRect(0, 2879, 284, 551));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 10)
				{
					player1Character.setTextureRect(sf::IntRect(3723, 2044, 300, 542));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 11)
				{
					player1Character.setTextureRect(sf::IntRect(3067, 1875, 300, 542));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 12)
				{
					player1Character.setTextureRect(sf::IntRect(1640, 1842, 294, 536));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 13)
				{
					player1Character.setTextureRect(sf::IntRect(1347, 1844, 291, 532));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 14)
				{
					player1Character.setTextureRect(sf::IntRect(717, 1829, 283, 527));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 15)
				{
					player1Character.setTextureRect(sf::IntRect(3266, 1351, 285, 523));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 16)
				{
					player1Character.setTextureRect(sf::IntRect(2277, 1331, 286, 516));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 17)
				{
					player1Character.setTextureRect(sf::IntRect(1988, 1329, 289, 514));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 18)
				{
					player1Character.setTextureRect(sf::IntRect(3699, 0, 289, 514));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 19)
				{
					player1Character.setTextureRect(sf::IntRect(3677, 517, 289, 514));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 20)
				{
					player1Character.setTextureRect(sf::IntRect(2566, 1343, 289, 514));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 21)
				{
					player1Character.setTextureRect(sf::IntRect(3554, 1525, 306, 514));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 22)
				{
					player1Character.setTextureRect(sf::IntRect(0, 1803, 325, 519));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 23)
				{
					player1Character.setTextureRect(sf::IntRect(1002, 1830, 343, 524));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 24)
				{
					player1Character.setTextureRect(sf::IntRect(1938, 1861, 362, 524));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 25)
				{
					player1Character.setTextureRect(sf::IntRect(2673, 1875, 391, 535));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 26)
				{
					player1Character.setTextureRect(sf::IntRect(686, 2360, 399, 543));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 27)
				{
					player1Character.setTextureRect(sf::IntRect(686, 2360, 399, 543));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 28)
				{
					player1Character.setTextureRect(sf::IntRect(1428, 2386, 385, 545));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 29)
				{
					player1Character.setTextureRect(sf::IntRect(3286, 2591, 378, 545));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 30)
				{
					player1Character.setTextureRect(sf::IntRect(1816, 2387, 407, 550));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 31)
				{
					player1Character.setTextureRect(sf::IntRect(2226, 2407, 407, 543));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 32)
				{
					player1Character.setTextureRect(sf::IntRect(3669, 2589, 422, 553));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 33)
				{
					player1Character.setTextureRect(sf::IntRect(2126, 2955, 425, 550));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 34)
				{
					player1Character.setTextureRect(sf::IntRect(621, 2907, 432, 551));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 35)
				{
					player1Character.setTextureRect(sf::IntRect(2555, 2967, 442, 552));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 36)
				{
					player1Character.setTextureRect(sf::IntRect(1364, 2933, 451, 553));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 37)
				{
					player1Character.setTextureRect(sf::IntRect(609, 3488, 464, 553));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 38)
				{
					player1Character.setTextureRect(sf::IntRect(1075, 3489, 474, 574));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 39)
				{
					player1Character.setTextureRect(sf::IntRect(1552, 3496, 486, 589));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 40)
				{
					player1Character.setTextureRect(sf::IntRect(527, 4047, 494, 602));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 41)
				{
					player1Character.setTextureRect(sf::IntRect(3162, 3696, 497, 601));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 42)
				{
					player1Character.setTextureRect(sf::IntRect(1537, 4090, 497, 607));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 43)
				{
					player1Character.setTextureRect(sf::IntRect(2040, 4108, 494, 612));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(210, 0);
				}
				else if (counter == 44)
				{
					player1Character.setTextureRect(sf::IntRect(3036, 4309, 496, 612));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(240, 0);
				}
				else if (counter == 45)
				{
					player1Character.setTextureRect(sf::IntRect(2538, 4297, 493, 611));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(270, 0);
				}
				else if (counter == 46)
				{
					player1Character.setTextureRect(sf::IntRect(1024, 4065, 508, 605));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(300, 0);
				}
				else if (counter == 47)
				{
					player1Character.setTextureRect(sf::IntRect(0, 4032, 524, 574));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(320, 0);
				}
				else if (counter == 48)
				{
					player1Character.setTextureRect(sf::IntRect(2619, 3717, 541, 572));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(350, 0);
				}
				else if (counter == 49)
				{
					player1Character.setTextureRect(sf::IntRect(2041, 3526, 574, 575));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(370, 0);
				}
				else if (counter == 50)
				{
					player1Character.setTextureRect(sf::IntRect(0, 3444, 606, 555));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(380, 0);
				}

				//moment before actual strike
				else if (counter == 51)
				{
					player1Character.setTextureRect(sf::IntRect(1413, 1331, 571, 508));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(400, 0);
				}
				else if (counter == 52)
				{
					player1Character.setTextureRect(sf::IntRect(3556, 1038, 445, 480));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(300, 0);

				}
				else if (counter == 53)
				{
					player1Character.setTextureRect(sf::IntRect(1609, 872, 455, 453));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(200, 0);
				}
				else if (counter == 54)
				{
					player1Character.setTextureRect(sf::IntRect(524, 864, 571, 442));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(45, 0);
				}
				else if (counter == 55)
				{
					player1Character.setTextureRect(sf::IntRect(3031, 434, 640, 438));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(110, 0);
				}
				else if (counter == 56)
				{
					player1Character.setTextureRect(sf::IntRect(2346, 435, 680, 432));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(156, 0);
				}
				else if (counter == 57)
				{
					player1Character.setTextureRect(sf::IntRect(1115, 433, 690, 427));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(167, 0);
				}
				else if (counter == 58)
				{
					player1Character.setTextureRect(sf::IntRect(2451, 0, 681, 429));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(160, 0);
				}
				else if (counter == 59)
				{
					player1Character.setTextureRect(sf::IntRect(1784, 0, 664, 429));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(140, 0);
				}
				else if (counter == 60)
				{
					player1Character.setTextureRect(sf::IntRect(0, 0, 610, 424));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(85, 0);
				}
				else if (counter == 61)
				{
					player1Character.setTextureRect(sf::IntRect(615, 0, 588, 424));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(70, 0);
				}
				else if (counter == 62)
				{
					player1Character.setTextureRect(sf::IntRect(1208, 0, 575, 427));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(60, 0);
				}
				else if (counter == 63)
				{
					player1Character.setTextureRect(sf::IntRect(3135, 0, 559, 430));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(30, 0);
				}
				else if (counter == 64)
				{
					player1Character.setTextureRect(sf::IntRect(0, 432, 563, 425));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(35, 0);
				}
				else if (counter == 65)
				{
					player1Character.setTextureRect(sf::IntRect(566, 432, 548, 428));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(19, 0);
				}
				else if (counter == 66)
				{
					player1Character.setTextureRect(sf::IntRect(1808, 436, 535, 428));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(7, 0);
				}
				else if (counter == 67)
				{
					player1Character.setTextureRect(sf::IntRect(0, 857, 521, 442));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 68)
				{
					player1Character.setTextureRect(sf::IntRect(1098, 869, 506, 442));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-18, 0);
				}
				else if (counter == 69)
				{
					player1Character.setTextureRect(sf::IntRect(2067, 875, 495, 451));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-27, 0);
				}
				else if (counter == 70)
				{
					player1Character.setTextureRect(sf::IntRect(2567, 879, 492, 460));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-27, 0);
				}
				else if (counter == 71)
				{
					player1Character.setTextureRect(sf::IntRect(3063, 877, 492, 471));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-20, 0);
				}
				else if (counter == 72)
				{
					player1Character.setTextureRect(sf::IntRect(0, 1302, 485, 493));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-15, 2);
				}
				else if (counter == 73)
				{
					player1Character.setTextureRect(sf::IntRect(491, 1314, 467, 496));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-20, 3);
				}
				else if (counter == 74)
				{
					player1Character.setTextureRect(sf::IntRect(964, 1320, 442, 504));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-33, 8);
				}
				else if (counter == 75)
				{
					player1Character.setTextureRect(sf::IntRect(2859, 1354, 404, 516));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-51, 11);
				}
				else if (counter == 76)
				{
					player1Character.setTextureRect(sf::IntRect(329, 1815, 385, 523));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-60, 10);
				}
				else if (counter == 77)
				{
					player1Character.setTextureRect(sf::IntRect(2304, 1865, 367, 532));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-61, 15);
				}
				else if (counter == 78)
				{
					player1Character.setTextureRect(sf::IntRect(3369, 2043, 351, 540));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-60, 13);
				}
				else if (counter == 79)
				{
					player1Character.setTextureRect(sf::IntRect(1090, 2378, 331, 546));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-33, 0);

				}
				else if (counter == 80)
				{
					player1Character.setTextureRect(sf::IntRect(2635, 2413, 363, 550));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(-14, 2);
				}
				else if (counter >= 80)
				{
					counter = 0;
					player1CurrentAnimation = "warriorStunStrike";
					player1MoveFinished = true;
				}

				player1Clock.restart();
				counter++;
			}
		}
	}

	if (player == 2)
	{


		//Caps frame speed(0.01)
		if (player2PassedTime >= 0.01)
		{
			if (player == 2)
			{

				//controls current sprite showing on the sprite sheet
				if (counter == 1)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTexture(warriorMove1Texture);
					player2Character.setTextureRect(sf::IntRect(3662, 3145, 380, 554));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}

				else if (counter == 2)
				{
					player2Character.setTextureRect(sf::IntRect(3298, 3138, 360, 554));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 3)
				{
					player2Character.setTextureRect(sf::IntRect(287, 2890, 331, 552));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 4)
				{
					player2Character.setTextureRect(sf::IntRect(1053, 2929, 307, 552));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 5)
				{
					player2Character.setTextureRect(sf::IntRect(1815, 2940, 307, 554));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 6)
				{
					player2Character.setTextureRect(sf::IntRect(2997, 3140, 298, 554));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 7)
				{
					player2Character.setTextureRect(sf::IntRect(0, 2324, 290, 554));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 8)
				{
					player2Character.setTextureRect(sf::IntRect(2998, 2418, 284, 566));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 9)
				{
					player2Character.setTextureRect(sf::IntRect(0, 2879, 284, 551));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 10)
				{
					player2Character.setTextureRect(sf::IntRect(3723, 2044, 300, 542));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 11)
				{
					player2Character.setTextureRect(sf::IntRect(3067, 1875, 300, 542));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 12)
				{
					player2Character.setTextureRect(sf::IntRect(1640, 1842, 294, 536));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 13)
				{
					player2Character.setTextureRect(sf::IntRect(1347, 1844, 291, 532));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 14)
				{
					player2Character.setTextureRect(sf::IntRect(717, 1829, 283, 527));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 15)
				{
					player2Character.setTextureRect(sf::IntRect(3266, 1351, 285, 523));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 16)
				{
					player2Character.setTextureRect(sf::IntRect(2277, 1331, 286, 516));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 17)
				{
					player2Character.setTextureRect(sf::IntRect(1988, 1329, 289, 514));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 18)
				{
					player2Character.setTextureRect(sf::IntRect(3699, 0, 289, 514));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 19)
				{
					player2Character.setTextureRect(sf::IntRect(3677, 517, 289, 514));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 20)
				{
					player2Character.setTextureRect(sf::IntRect(2566, 1343, 289, 514));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 21)
				{
					player2Character.setTextureRect(sf::IntRect(3554, 1525, 306, 514));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 22)
				{
					player2Character.setTextureRect(sf::IntRect(0, 1803, 325, 519));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 23)
				{
					player2Character.setTextureRect(sf::IntRect(1002, 1830, 343, 524));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 24)
				{
					player2Character.setTextureRect(sf::IntRect(1938, 1861, 362, 524));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 25)
				{
					player2Character.setTextureRect(sf::IntRect(2673, 1875, 391, 535));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 26)
				{
					player2Character.setTextureRect(sf::IntRect(686, 2360, 399, 543));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 27)
				{
					player2Character.setTextureRect(sf::IntRect(686, 2360, 399, 543));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 28)
				{
					player2Character.setTextureRect(sf::IntRect(1428, 2386, 385, 545));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 29)
				{
					player2Character.setTextureRect(sf::IntRect(3286, 2591, 378, 545));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 30)
				{
					player2Character.setTextureRect(sf::IntRect(1816, 2387, 407, 550));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 31)
				{
					player2Character.setTextureRect(sf::IntRect(2226, 2407, 407, 543));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 32)
				{
					player2Character.setTextureRect(sf::IntRect(3669, 2589, 422, 553));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 33)
				{
					player2Character.setTextureRect(sf::IntRect(2126, 2955, 425, 550));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 34)
				{
					player2Character.setTextureRect(sf::IntRect(621, 2907, 432, 551));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 35)
				{
					player2Character.setTextureRect(sf::IntRect(2555, 2967, 442, 552));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 36)
				{
					player2Character.setTextureRect(sf::IntRect(1364, 2933, 451, 553));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 37)
				{
					player2Character.setTextureRect(sf::IntRect(609, 3488, 464, 553));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 38)
				{
					player2Character.setTextureRect(sf::IntRect(1075, 3489, 474, 574));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 39)
				{
					player2Character.setTextureRect(sf::IntRect(1552, 3496, 486, 589));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 40)
				{
					player2Character.setTextureRect(sf::IntRect(527, 4047, 494, 602));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 41)
				{
					player2Character.setTextureRect(sf::IntRect(3162, 3696, 497, 601));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 42)
				{
					player2Character.setTextureRect(sf::IntRect(1537, 4090, 497, 607));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 43)
				{
					player2Character.setTextureRect(sf::IntRect(2040, 4108, 494, 612));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-210, 0);
				}
				else if (counter == 44)
				{
					player2Character.setTextureRect(sf::IntRect(3036, 4309, 496, 612));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-240, 0);
				}
				else if (counter == 45)
				{
					player2Character.setTextureRect(sf::IntRect(2538, 4297, 493, 611));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-270, 0);
				}
				else if (counter == 46)
				{
					player2Character.setTextureRect(sf::IntRect(1024, 4065, 508, 605));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-300, 0);
				}
				else if (counter == 47)
				{
					player2Character.setTextureRect(sf::IntRect(0, 4032, 524, 574));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-320, 0);
				}
				else if (counter == 48)
				{
					player2Character.setTextureRect(sf::IntRect(2619, 3717, 541, 572));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-350, 0);
				}
				else if (counter == 49)
				{
					player2Character.setTextureRect(sf::IntRect(2041, 3526, 574, 575));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-370, 0);
				}
				else if (counter == 50)
				{
					player2Character.setTextureRect(sf::IntRect(0, 3444, 606, 555));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-380, 0);
				}

				//moment before actual strike
				else if (counter == 51)
				{
					player2Character.setTextureRect(sf::IntRect(1413, 1331, 571, 508));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-400, 0);
				}
				else if (counter == 52)
				{
					player2Character.setTextureRect(sf::IntRect(3556, 1038, 445, 480));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-300, 0);

				}
				else if (counter == 53)
				{
					player2Character.setTextureRect(sf::IntRect(1609, 872, 455, 453));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-200, 0);
				}
				else if (counter == 54)
				{
					player2Character.setTextureRect(sf::IntRect(524, 864, 571, 442));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-45, 0);
				}
				else if (counter == 55)
				{
					player2Character.setTextureRect(sf::IntRect(3031, 434, 640, 438));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-110, 0);
				}
				else if (counter == 56)
				{
					player2Character.setTextureRect(sf::IntRect(2346, 435, 680, 432));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-156, 0);
				}
				else if (counter == 57)
				{
					player2Character.setTextureRect(sf::IntRect(1115, 433, 690, 427));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-167, 0);
				}
				else if (counter == 58)
				{
					player2Character.setTextureRect(sf::IntRect(2451, 0, 681, 429));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-160, 0);
				}
				else if (counter == 59)
				{
					player2Character.setTextureRect(sf::IntRect(1784, 0, 664, 429));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-140, 0);
				}
				else if (counter == 60)
				{
					player2Character.setTextureRect(sf::IntRect(0, 0, 610, 424));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-85, 0);
				}
				else if (counter == 61)
				{
					player2Character.setTextureRect(sf::IntRect(615, 0, 588, 424));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-70, 0);
				}
				else if (counter == 62)
				{
					player2Character.setTextureRect(sf::IntRect(1208, 0, 575, 427));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-60, 0);
				}
				else if (counter == 63)
				{
					player2Character.setTextureRect(sf::IntRect(3135, 0, 559, 430));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-30, 0);
				}
				else if (counter == 64)
				{
					player2Character.setTextureRect(sf::IntRect(0, 432, 563, 425));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-35, 0);
				}
				else if (counter == 65)
				{
					player2Character.setTextureRect(sf::IntRect(566, 432, 548, 428));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-19, 0);
				}
				else if (counter == 66)
				{
					player2Character.setTextureRect(sf::IntRect(1808, 436, 535, 428));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-7, 0);
				}
				else if (counter == 67)
				{
					player2Character.setTextureRect(sf::IntRect(0, 857, 521, 442));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 68)
				{
					player2Character.setTextureRect(sf::IntRect(1098, 869, 506, 442));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(18, 0);
				}
				else if (counter == 69)
				{
					player2Character.setTextureRect(sf::IntRect(2067, 875, 495, 451));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(27, 0);
				}
				else if (counter == 70)
				{
					player2Character.setTextureRect(sf::IntRect(2567, 879, 492, 460));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(27, 0);
				}
				else if (counter == 71)
				{
					player2Character.setTextureRect(sf::IntRect(3063, 877, 492, 471));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(20, 0);
				}
				else if (counter == 72)
				{
					player2Character.setTextureRect(sf::IntRect(0, 1302, 485, 493));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(15, 2);
				}
				else if (counter == 73)
				{
					player2Character.setTextureRect(sf::IntRect(491, 1314, 467, 496));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(20, 3);
				}
				else if (counter == 74)
				{
					player2Character.setTextureRect(sf::IntRect(964, 1320, 442, 504));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(33, 8);
				}
				else if (counter == 75)
				{
					player2Character.setTextureRect(sf::IntRect(2859, 1354, 404, 516));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(51, 11);
				}
				else if (counter == 76)
				{
					player2Character.setTextureRect(sf::IntRect(329, 1815, 385, 523));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(60, 10);
				}
				else if (counter == 77)
				{
					player2Character.setTextureRect(sf::IntRect(2304, 1865, 367, 532));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(61, 15);
				}
				else if (counter == 78)
				{
					player2Character.setTextureRect(sf::IntRect(3369, 2043, 351, 540));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(60, 13);
				}
				else if (counter == 79)
				{
					player2Character.setTextureRect(sf::IntRect(1090, 2378, 331, 546));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(33, 0);

				}
				else if (counter == 80)
				{
					player2Character.setTextureRect(sf::IntRect(2635, 2413, 363, 550));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(14, 2);
				}
				else if (counter >= 80)
				{
					counter = 0;
					player2CurrentAnimation = "warriorStunStrike";
					player2MoveFinished = true;
				}

				player2Clock.restart();
				counter++;
			}
		}
	}

}


//quick strike
void VisibleObjectManager::warriorMove2(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	if (player == 1)
	{


		//Caps frame speed
		if (player1PassedTime >= 0.02)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(warriorMove2Texture);

				player1Character.setTextureRect(sf::IntRect(3232, 512, 460, 509));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(41, 0);
			}
			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(2300, 501, 464, 508));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(34, 0);
			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(0, 487, 459, 508));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(13, 0);
			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(464, 489, 448, 506));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-12, 0);
			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(916, 497, 460, 503));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-12, 0);
			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(1377, 499, 461, 506));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-18, 0);
			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(1840, 496, 460, 511));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-28, 0);
			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(2766, 508, 463, 508));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-37, 0);
			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(404, 1003, 471, 509));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-37, 0);
			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(877, 1003, 478, 515));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-35, 0);
			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1514, 481, 522));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-35, 0);
			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(2109, 1016, 473, 517));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-35, 0);
			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(2172, 2081, 472, 655));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-23, 0);
			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(3106, 2098, 473, 804));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(16, 0);
			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(2646, 2093, 457, 795));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(27, 0);
			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(1623, 2075, 542, 605));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(47, 0);
			}
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(2397, 1547, 685, 531));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(3090, 0, 453, 502));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				player1Character.setTextureRect(sf::IntRect(1892, 0, 787, 496));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(444, 0);
			}
			else if (counter == 20)
			{
				player1Character.setTextureRect(sf::IntRect(1495, 0, 390, 494));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(46, 0);
			}
			else if (counter == 21)
			{
				player1Character.setTextureRect(sf::IntRect(744, 0, 364, 485));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(19, 0);
			}
			else if (counter == 22)
			{
				player1Character.setTextureRect(sf::IntRect(374, 0, 367, 485));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(23, 0);
			}
			else if (counter == 23)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 371, 485));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(25, 0);
			}

			else if (counter == 24)
			{
				player1Character.setTextureRect(sf::IntRect(1114, 0, 379, 490));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(27, 0);
			}
			else if (counter == 25)
			{
				player1Character.setTextureRect(sf::IntRect(2689, 0, 396, 500));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(27, 0);
			}
			else if (counter == 26)
			{
				player1Character.setTextureRect(sf::IntRect(3548, 0, 399, 506));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(23, 0);

			}
			else if (counter == 27)
			{
				player1Character.setTextureRect(sf::IntRect(0, 999, 402, 509));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(20, 0);
			}
			else if (counter == 28)
			{
				player1Character.setTextureRect(sf::IntRect(1357, 1014, 397, 509));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(13, 0);
			}
			else if (counter == 29)
			{
				player1Character.setTextureRect(sf::IntRect(2938, 1030, 391, 513));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-2, 0);
			}
			else if (counter == 30)
			{
				player1Character.setTextureRect(sf::IntRect(3685, 1035, 386, 513));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				player1Character.setTextureRect(sf::IntRect(485, 1518, 348, 520));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				player1Character.setTextureRect(sf::IntRect(3332, 1029, 346, 516));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, 0);
			}
			else if (counter == 33)
			{
				player1Character.setTextureRect(sf::IntRect(1757, 1010, 347, 515));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, 0);
			}
			else if (counter == 34)
			{
				player1Character.setTextureRect(sf::IntRect(3696, 513, 350, 511));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(4, 0);
			}
			else if (counter == 35)
			{
				player1Character.setTextureRect(sf::IntRect(2584, 1022, 349, 516));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, 0);
			}
			else if (counter == 36)
			{
				player1Character.setTextureRect(sf::IntRect(833, 1524, 345, 521));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 37)
			{
				player1Character.setTextureRect(sf::IntRect(1181, 1533, 353, 521));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(10, 0);
			}
			else if (counter == 38)
			{
				player1Character.setTextureRect(sf::IntRect(1536, 1533, 404, 525));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(60, 0);
			}
			else if (counter == 39)
			{
				player1Character.setTextureRect(sf::IntRect(1943, 1539, 444, 530));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(100, 0);
			}
			else if (counter == 40)
			{
				player1Character.setTextureRect(sf::IntRect(3085, 1550, 473, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(135, 0);
			}
			else if (counter == 41)
			{
				player1Character.setTextureRect(sf::IntRect(3561, 1557, 481, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(143, 0);
			}
			else if (counter == 42)
			{
				player1Character.setTextureRect(sf::IntRect(0, 2037, 472, 543));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(133, 0);
			}
			else if (counter == 43)
			{
				player1Character.setTextureRect(sf::IntRect(477, 2047, 432, 544));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(96, 0);
			}
			else if (counter == 44)
			{
				player1Character.setTextureRect(sf::IntRect(911, 2064, 391, 540));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(37, 0);
			}
			else if (counter == 45)
			{
				player1Character.setTextureRect(sf::IntRect(1304, 2066, 316, 548));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-43, 0);
			}
			else if (counter >= 45)
			{
				counter = 0;
				player1CurrentAnimation = "warriorIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}


	if (player == 2)
	{


		//Caps frame speed
		if (player2PassedTime >= 0.02)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(warriorMove2Texture);

				player2Character.setTextureRect(sf::IntRect(3232, 512, 460, 509));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-41, 0);
			}
			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(2300, 501, 464, 508));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-34, 0);
			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(0, 487, 459, 508));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-13, 0);
			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(464, 489, 448, 506));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(12, 0);
			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(916, 497, 460, 503));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(12, 0);
			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(1377, 499, 461, 506));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(18, 0);
			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(1840, 496, 460, 511));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(28, 0);
			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(2766, 508, 463, 508));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(37, 0);
			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(404, 1003, 471, 509));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(37, 0);
			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(877, 1003, 478, 515));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(35, 0);
			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1514, 481, 522));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(35, 0);
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(2109, 1016, 473, 517));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(35, 0);
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(2172, 2081, 472, 655));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(23, 0);
			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(3106, 2098, 473, 804));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-16, 0);
			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(2646, 2093, 457, 795));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-27, 0);
			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(1623, 2075, 542, 605));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-47, 0);
			}
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(2397, 1547, 685, 531));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(3090, 0, 453, 502));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				player2Character.setTextureRect(sf::IntRect(1892, 0, 787, 496));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-444, 0);
			}
			else if (counter == 20)
			{
				player2Character.setTextureRect(sf::IntRect(1495, 0, 390, 494));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-46, 0);
			}
			else if (counter == 21)
			{
				player2Character.setTextureRect(sf::IntRect(744, 0, 364, 485));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-19, 0);
			}
			else if (counter == 22)
			{
				player2Character.setTextureRect(sf::IntRect(374, 0, 367, 485));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-23, 0);
			}
			else if (counter == 23)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 371, 485));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-25, 0);
			}

			else if (counter == 24)
			{
				player2Character.setTextureRect(sf::IntRect(1114, 0, 379, 490));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-27, 0);
			}
			else if (counter == 25)
			{
				player2Character.setTextureRect(sf::IntRect(2689, 0, 396, 500));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-27, 0);
			}
			else if (counter == 26)
			{
				player2Character.setTextureRect(sf::IntRect(3548, 0, 399, 506));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-23, 0);

			}
			else if (counter == 27)
			{
				player2Character.setTextureRect(sf::IntRect(0, 999, 402, 509));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-20, 0);
			}
			else if (counter == 28)
			{
				player2Character.setTextureRect(sf::IntRect(1357, 1014, 397, 509));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-13, 0);
			}
			else if (counter == 29)
			{
				player2Character.setTextureRect(sf::IntRect(2938, 1030, 391, 513));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(2, 0);
			}
			else if (counter == 30)
			{
				player2Character.setTextureRect(sf::IntRect(3685, 1035, 386, 513));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				player2Character.setTextureRect(sf::IntRect(485, 1518, 348, 520));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				player2Character.setTextureRect(sf::IntRect(3332, 1029, 346, 516));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, 0);
			}
			else if (counter == 33)
			{
				player2Character.setTextureRect(sf::IntRect(1757, 1010, 347, 515));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, 0);
			}
			else if (counter == 34)
			{
				player2Character.setTextureRect(sf::IntRect(3696, 513, 350, 511));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-4, 0);
			}
			else if (counter == 35)
			{
				player2Character.setTextureRect(sf::IntRect(2584, 1022, 349, 516));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, 0);
			}
			else if (counter == 36)
			{
				player2Character.setTextureRect(sf::IntRect(833, 1524, 345, 521));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 37)
			{
				player2Character.setTextureRect(sf::IntRect(1181, 1533, 353, 521));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-10, 0);
			}
			else if (counter == 38)
			{
				player2Character.setTextureRect(sf::IntRect(1536, 1533, 404, 525));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-60, 0);
			}
			else if (counter == 39)
			{
				player2Character.setTextureRect(sf::IntRect(1943, 1539, 444, 530));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-100, 0);
			}
			else if (counter == 40)
			{
				player2Character.setTextureRect(sf::IntRect(3085, 1550, 473, 534));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-135, 0);
			}
			else if (counter == 41)
			{
				player2Character.setTextureRect(sf::IntRect(3561, 1557, 481, 534));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-143, 0);
			}
			else if (counter == 42)
			{
				player2Character.setTextureRect(sf::IntRect(0, 2037, 472, 543));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-133, 0);
			}
			else if (counter == 43)
			{
				player2Character.setTextureRect(sf::IntRect(477, 2047, 432, 544));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-96, 0);
			}
			else if (counter == 44)
			{
				player2Character.setTextureRect(sf::IntRect(911, 2064, 391, 540));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-37, 0);
			}
			else if (counter == 45)
			{
				player2Character.setTextureRect(sf::IntRect(1304, 2066, 316, 548));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(43, 0);
			}
			else if (counter >= 45)
			{
				counter = 0;
				player2CurrentAnimation = "warriorIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}

}


//charging strike
void VisibleObjectManager::warriorMove3(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;


	if (player == 1)
	{



		//Caps frame speed
		if (player1PassedTime >= 0.03)
		{

			if (player == 1)
			{

				//controls current sprite showing on the sprite sheet
				if (counter == 1)
				{
					//sets current texture before cropping the proper sprite
					player1Character.setTexture(warriorMove3Texture);
					player1Character.setPosition(286, 298);
					player1Character.setTextureRect(sf::IntRect(2010, 2059, 396, 552));
				}

				else if (counter == 2)
				{
					player1Character.setTextureRect(sf::IntRect(300, 2592, 403, 560));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 3)
				{
					player1Character.setTextureRect(sf::IntRect(705, 2597, 405, 561));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 4)
				{
					player1Character.setTextureRect(sf::IntRect(1600, 2605, 403, 561));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 5)
				{
					player1Character.setTextureRect(sf::IntRect(0, 4293, 413, 560));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 6)
				{
					player1Character.setTextureRect(sf::IntRect(2083, 4324, 417, 561));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 7)
				{
					player1Character.setTextureRect(sf::IntRect(1524, 3735, 429, 561));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 8)
				{
					//position needs adjustment
					player1Character.setTextureRect(sf::IntRect(3505, 2651, 438, 559));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 9)
				{

					player1Character.setTextureRect(sf::IntRect(3501, 3213, 499, 563));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 10)
				{
					player1Character.setTextureRect(sf::IntRect(2941, 3203, 556, 562));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 11)
				{
					player1Character.setTextureRect(sf::IntRect(1958, 3758, 595, 562));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 12)
				{
					player1Character.setTextureRect(sf::IntRect(319, 3728, 601, 564));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 13)
				{
					player1Character.setTextureRect(sf::IntRect(2408, 2631, 544, 559));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 14)
				{
					player1Character.setTextureRect(sf::IntRect(3085, 2081, 415, 554));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 15)
				{
					player1Character.setTextureRect(sf::IntRect(870, 2050, 315, 546));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 16)
				{
					player1Character.setTextureRect(sf::IntRect(0, 2040, 323, 537));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 17)
				{
					//fix position
					player1Character.setTextureRect(sf::IntRect(3137, 1548, 431, 529));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(100, 0);

				}
				else if (counter == 18)
				{
					//fix position
					player1Character.setTextureRect(sf::IntRect(1556, 1524, 524, 529));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(190, 0);
				}
				else if (counter == 19)
				{
					//fix position
					player1Character.setTextureRect(sf::IntRect(0, 1513, 575, 522));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(237, -5);
				}
				else if (counter == 20)
				{
					//fix position
					player1Character.setTextureRect(sf::IntRect(970, 1525, 582, 522));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(248, -5);
				}
				else if (counter == 21)
				{
					//fix position
					player1Character.setTextureRect(sf::IntRect(2079, 1530, 575, 522));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(240, -5);
				}
				else if (counter == 22)
				{
					player1Character.setTextureRect(sf::IntRect(327, 2051, 539, 538));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(210, 0);
				}
				else if (counter == 23)
				{
					player1Character.setTextureRect(sf::IntRect(3501, 2091, 504, 555));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(175, 0);
				}
				else if (counter == 24)
				{
					player1Character.setTextureRect(sf::IntRect(1530, 3169, 467, 564));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(140, 0);
				}
				else if (counter == 25)
				{
					player1Character.setTextureRect(sf::IntRect(3164, 3777, 425, 574));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(100, 0);
				}
				else if (counter == 26)
				{
					player1Character.setTextureRect(sf::IntRect(1686, 4325, 393, 584));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(70, 0);
				}
				else if (counter == 27)
				{
					player1Character.setTextureRect(sf::IntRect(0, 4873, 394, 588));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(60, 0);

				}

				else if (counter == 28)
				{
					player1Character.setTextureRect(sf::IntRect(1045, 4899, 431, 601));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(70, 0);
				}
				else if (counter == 29)
				{
					player1Character.setTextureRect(sf::IntRect(2086, 4923, 456, 627));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(78, 0);
				}
				else if (counter == 30)
				{
					player1Character.setTextureRect(sf::IntRect(2546, 4924, 460, 662));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(83, 0);
				}
				else if (counter == 31)
				{
					player1Character.setTextureRect(sf::IntRect(1681, 5558, 484, 686));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 32)
				{
					player1Character.setTextureRect(sf::IntRect(3018, 5595, 495, 702));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 33)
				{
					player1Character.setTextureRect(sf::IntRect(3517, 5651, 501, 702));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 34)
				{
					player1Character.setTextureRect(sf::IntRect(1151, 5537, 529, 686));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(80, 0);
				}
				else if (counter == 35)
				{
					player1Character.setTextureRect(sf::IntRect(3013, 4944, 596, 648));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 36)
				{
					player1Character.setTextureRect(sf::IntRect(402, 4885, 642, 592));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 37)
				{
					player1Character.setTextureRect(sf::IntRect(2410, 2076, 671, 551));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 38)
				{
					player1Character.setTextureRect(sf::IntRect(2119, 1003, 692, 520));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 39)
				{
					player1Character.setTextureRect(sf::IntRect(0, 1001, 704, 505));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 40)
				{
					player1Character.setTextureRect(sf::IntRect(2148, 504, 741, 498));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 41)
				{
					player1Character.setTextureRect(sf::IntRect(1402, 504, 742, 493));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 42)
				{
					player1Character.setTextureRect(sf::IntRect(2713, 0, 742, 498));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 43)
				{
					player1Character.setTextureRect(sf::IntRect(499, 0, 743, 498));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 44)
				{
					player1Character.setTextureRect(sf::IntRect(1245, 0, 734, 498));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 45)
				{
					player1Character.setTextureRect(sf::IntRect(1983, 0, 722, 498));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 46)
				{
					player1Character.setTextureRect(sf::IntRect(0, 501, 708, 496));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 47)
				{
					player1Character.setTextureRect(sf::IntRect(710, 503, 682, 496));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 48)
				{
					player1Character.setTextureRect(sf::IntRect(3368, 511, 665, 505));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(100, 0);
				}
				else if (counter == 49)
				{
					player1Character.setTextureRect(sf::IntRect(3460, 0, 601, 510));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);

				}
				else if (counter == 50)
				{
					player1Character.setTextureRect(sf::IntRect(1590, 1002, 526, 518));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 51)
				{
					player1Character.setTextureRect(sf::IntRect(3202, 1019, 439, 523));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 52)
				{
					player1Character.setTextureRect(sf::IntRect(3644, 1020, 417, 526));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(100, 0);
				}
				else if (counter == 53)
				{
					player1Character.setTextureRect(sf::IntRect(584, 1518, 382, 527));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 54)
				{
					player1Character.setTextureRect(sf::IntRect(2812, 1016, 388, 522));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(75, 0);
				}
				else if (counter == 55)
				{
					player1Character.setTextureRect(sf::IntRect(705, 1003, 395, 511));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(125, 0);
				}
				else if (counter == 56)
				{
					player1Character.setTextureRect(sf::IntRect(3571, 1550, 397, 536));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(140, 0);
				}
				else if (counter == 57)
				{
					player1Character.setTextureRect(sf::IntRect(1103, 1002, 482, 513));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(160, 0);
				}
				else if (counter == 58)
				{
					player1Character.setTextureRect(sf::IntRect(0, 0, 496, 491));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(220, 0);
				}
				else if (counter == 59)
				{
					player1Character.setTextureRect(sf::IntRect(2894, 503, 467, 509));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(250, 0);
				}
				else if (counter == 60)
				{
					player1Character.setTextureRect(sf::IntRect(2660, 1543, 478, 531));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(270, 0);
				}
				else if (counter == 61)
				{
					player1Character.setTextureRect(sf::IntRect(1191, 2056, 818, 548));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
					player1Character.move(500, 0);
				}
				else if (counter == 62)
				{
					player1Character.setTextureRect(sf::IntRect(3613, 4948, 386, 698));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 63)
				{
					player1Character.setTextureRect(sf::IntRect(2168, 5553, 357, 717));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 64)
				{
					player1Character.setTextureRect(sf::IntRect(2530, 5597, 487, 695));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 65)
				{
					player1Character.setTextureRect(sf::IntRect(595, 5504, 554, 671));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 66)
				{
					player1Character.setTextureRect(sf::IntRect(0, 5480, 590, 648));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 67)
				{
					player1Character.setTextureRect(sf::IntRect(1485, 4910, 601, 627));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 68)
				{
					player1Character.setTextureRect(sf::IntRect(2505, 4332, 607, 589));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 69)
				{
					player1Character.setTextureRect(sf::IntRect(2555, 3767, 607, 564));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 60)
				{
					player1Character.setTextureRect(sf::IntRect(923, 3735, 596, 559));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 70)
				{
					player1Character.setTextureRect(sf::IntRect(941, 3170, 587, 560));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 71)
				{
					player1Character.setTextureRect(sf::IntRect(0, 3156, 585, 558));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 72)
				{
					player1Character.setTextureRect(sf::IntRect(2362, 3197, 574, 557));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 73)
				{
					player1Character.setTextureRect(sf::IntRect(2956, 2642, 545, 555));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 74)
				{
					player1Character.setTextureRect(sf::IntRect(1114, 2609, 483, 553));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 75)
				{
					player1Character.setTextureRect(sf::IntRect(2010, 2618, 393, 558));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 76)
				{
					player1Character.setTextureRect(sf::IntRect(590, 3163, 346, 562));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 77)
				{
					player1Character.setTextureRect(sf::IntRect(0, 2581, 296, 564));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 78)
				{
					player1Character.setTextureRect(sf::IntRect(0, 3720, 316, 567));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 79)
				{
					player1Character.setTextureRect(sf::IntRect(1294, 4313, 387, 584));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 80)
				{
					player1Character.setTextureRect(sf::IntRect(3117, 4360, 398, 583));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 81)
				{
					player1Character.setTextureRect(sf::IntRect(3517, 4364, 429, 579));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 82)
				{
					player1Character.setTextureRect(sf::IntRect(830, 4298, 450, 582));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 83)
				{
					player1Character.setTextureRect(sf::IntRect(418, 4289, 409, 582));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 84)
				{
					player1Character.setTextureRect(sf::IntRect(3600, 3782, 375, 571));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}
				else if (counter == 85)
				{
					player1Character.setTextureRect(sf::IntRect(2001, 3182, 361, 567));
					player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				}

				/////last anim frame
				else if (counter >= 85)
				{
					counter = 0;
					player1CurrentAnimation = "warriorIdle";
					player1MoveFinished = true;
				}

				player1Clock.restart();
				counter++;
			}
		}
	}

	if (player == 2)
	{



		//Caps frame speed
		if (player2PassedTime >= 0.03)
		{

			if (player == 2)
			{

				//controls current sprite showing on the sprite sheet
				if (counter == 1)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTexture(warriorMove3Texture);
					player2Character.setTextureRect(sf::IntRect(2010, 2059, 396, 552));
				}

				else if (counter == 2)
				{
					player2Character.setTextureRect(sf::IntRect(300, 2592, 403, 560));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 3)
				{
					player2Character.setTextureRect(sf::IntRect(705, 2597, 405, 561));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 4)
				{
					player2Character.setTextureRect(sf::IntRect(1600, 2605, 403, 561));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 5)
				{
					player2Character.setTextureRect(sf::IntRect(0, 4293, 413, 560));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 6)
				{
					player2Character.setTextureRect(sf::IntRect(2083, 4324, 417, 561));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 7)
				{
					player2Character.setTextureRect(sf::IntRect(1524, 3735, 429, 561));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 8)
				{
					//position needs adjustment
					player2Character.setTextureRect(sf::IntRect(3505, 2651, 438, 559));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 9)
				{

					player2Character.setTextureRect(sf::IntRect(3501, 3213, 499, 563));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 10)
				{
					player2Character.setTextureRect(sf::IntRect(2941, 3203, 556, 562));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 11)
				{
					player2Character.setTextureRect(sf::IntRect(1958, 3758, 595, 562));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 12)
				{
					player2Character.setTextureRect(sf::IntRect(319, 3728, 601, 564));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 13)
				{
					player2Character.setTextureRect(sf::IntRect(2408, 2631, 544, 559));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 14)
				{
					player2Character.setTextureRect(sf::IntRect(3085, 2081, 415, 554));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 15)
				{
					player2Character.setTextureRect(sf::IntRect(870, 2050, 315, 546));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 16)
				{
					player2Character.setTextureRect(sf::IntRect(0, 2040, 323, 537));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 17)
				{
					//fix position
					player2Character.setTextureRect(sf::IntRect(3137, 1548, 431, 529));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-100, 0);

				}
				else if (counter == 18)
				{
					//fix position
					player2Character.setTextureRect(sf::IntRect(1556, 1524, 524, 529));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-190, 0);
				}
				else if (counter == 19)
				{
					//fix position
					player2Character.setTextureRect(sf::IntRect(0, 1513, 575, 522));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-237, -5);
				}
				else if (counter == 20)
				{
					//fix position
					player2Character.setTextureRect(sf::IntRect(970, 1525, 582, 522));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-248, -5);
				}
				else if (counter == 21)
				{
					//fix position
					player2Character.setTextureRect(sf::IntRect(2079, 1530, 575, 522));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-240, -5);
				}
				else if (counter == 22)
				{
					player2Character.setTextureRect(sf::IntRect(327, 2051, 539, 538));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-210, 0);
				}
				else if (counter == 23)
				{
					player2Character.setTextureRect(sf::IntRect(3501, 2091, 504, 555));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-175, 0);
				}
				else if (counter == 24)
				{
					player2Character.setTextureRect(sf::IntRect(1530, 3169, 467, 564));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-140, 0);
				}
				else if (counter == 25)
				{
					player2Character.setTextureRect(sf::IntRect(3164, 3777, 425, 574));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-100, 0);
				}
				else if (counter == 26)
				{
					player2Character.setTextureRect(sf::IntRect(1686, 4325, 393, 584));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-70, 0);
				}
				else if (counter == 27)
				{
					player2Character.setTextureRect(sf::IntRect(0, 4873, 394, 588));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-60, 0);

				}

				else if (counter == 28)
				{
					player2Character.setTextureRect(sf::IntRect(1045, 4899, 431, 601));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-70, 0);
				}
				else if (counter == 29)
				{
					player2Character.setTextureRect(sf::IntRect(2086, 4923, 456, 627));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-78, 0);
				}
				else if (counter == 30)
				{
					player2Character.setTextureRect(sf::IntRect(2546, 4924, 460, 662));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-83, 0);
				}
				else if (counter == 31)
				{
					player2Character.setTextureRect(sf::IntRect(1681, 5558, 484, 686));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 32)
				{
					player2Character.setTextureRect(sf::IntRect(3018, 5595, 495, 702));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 33)
				{
					player2Character.setTextureRect(sf::IntRect(3517, 5651, 501, 702));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 34)
				{
					player2Character.setTextureRect(sf::IntRect(1151, 5537, 529, 686));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-80, 0);
				}
				else if (counter == 35)
				{
					player2Character.setTextureRect(sf::IntRect(3013, 4944, 596, 648));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 36)
				{
					player2Character.setTextureRect(sf::IntRect(402, 4885, 642, 592));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 37)
				{
					player2Character.setTextureRect(sf::IntRect(2410, 2076, 671, 551));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 38)
				{
					player2Character.setTextureRect(sf::IntRect(2119, 1003, 692, 520));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 39)
				{
					player2Character.setTextureRect(sf::IntRect(0, 1001, 704, 505));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 40)
				{
					player2Character.setTextureRect(sf::IntRect(2148, 504, 741, 498));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 41)
				{
					player2Character.setTextureRect(sf::IntRect(1402, 504, 742, 493));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 42)
				{
					player2Character.setTextureRect(sf::IntRect(2713, 0, 742, 498));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 43)
				{
					player2Character.setTextureRect(sf::IntRect(499, 0, 743, 498));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 44)
				{
					player2Character.setTextureRect(sf::IntRect(1245, 0, 734, 498));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 45)
				{
					player2Character.setTextureRect(sf::IntRect(1983, 0, 722, 498));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 46)
				{
					player2Character.setTextureRect(sf::IntRect(0, 501, 708, 496));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 47)
				{
					player2Character.setTextureRect(sf::IntRect(710, 503, 682, 496));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 48)
				{
					player2Character.setTextureRect(sf::IntRect(3368, 511, 665, 505));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-100, 0);
				}
				else if (counter == 49)
				{
					player2Character.setTextureRect(sf::IntRect(3460, 0, 601, 510));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);

				}
				else if (counter == 50)
				{
					player2Character.setTextureRect(sf::IntRect(1590, 1002, 526, 518));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 51)
				{
					player2Character.setTextureRect(sf::IntRect(3202, 1019, 439, 523));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 52)
				{
					player2Character.setTextureRect(sf::IntRect(3644, 1020, 417, 526));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-100, 0);
				}
				else if (counter == 53)
				{
					player2Character.setTextureRect(sf::IntRect(584, 1518, 382, 527));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 54)
				{
					player2Character.setTextureRect(sf::IntRect(2812, 1016, 388, 522));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-75, 0);
				}
				else if (counter == 55)
				{
					player2Character.setTextureRect(sf::IntRect(705, 1003, 395, 511));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-125, 0);
				}
				else if (counter == 56)
				{
					player2Character.setTextureRect(sf::IntRect(3571, 1550, 397, 536));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-140, 0);
				}
				else if (counter == 57)
				{
					player2Character.setTextureRect(sf::IntRect(1103, 1002, 482, 513));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-160, 0);
				}
				else if (counter == 58)
				{
					player2Character.setTextureRect(sf::IntRect(0, 0, 496, 491));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-220, 0);
				}
				else if (counter == 59)
				{
					player2Character.setTextureRect(sf::IntRect(2894, 503, 467, 509));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-250, 0);
				}
				else if (counter == 60)
				{
					player2Character.setTextureRect(sf::IntRect(2660, 1543, 478, 531));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-270, 0);
				}
				else if (counter == 61)
				{
					player2Character.setTextureRect(sf::IntRect(1191, 2056, 818, 548));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
					player2Character.move(-500, 0);
				}
				else if (counter == 62)
				{
					player2Character.setTextureRect(sf::IntRect(3613, 4948, 386, 698));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 63)
				{
					player2Character.setTextureRect(sf::IntRect(2168, 5553, 357, 717));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 64)
				{
					player2Character.setTextureRect(sf::IntRect(2530, 5597, 487, 695));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 65)
				{
					player2Character.setTextureRect(sf::IntRect(595, 5504, 554, 671));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 66)
				{
					player2Character.setTextureRect(sf::IntRect(0, 5480, 590, 648));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 67)
				{
					player2Character.setTextureRect(sf::IntRect(1485, 4910, 601, 627));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 68)
				{
					player2Character.setTextureRect(sf::IntRect(2505, 4332, 607, 589));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 69)
				{
					player2Character.setTextureRect(sf::IntRect(2555, 3767, 607, 564));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 60)
				{
					player2Character.setTextureRect(sf::IntRect(923, 3735, 596, 559));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 70)
				{
					player2Character.setTextureRect(sf::IntRect(941, 3170, 587, 560));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 71)
				{
					player2Character.setTextureRect(sf::IntRect(0, 3156, 585, 558));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 72)
				{
					player2Character.setTextureRect(sf::IntRect(2362, 3197, 574, 557));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 73)
				{
					player2Character.setTextureRect(sf::IntRect(2956, 2642, 545, 555));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 74)
				{
					player2Character.setTextureRect(sf::IntRect(1114, 2609, 483, 553));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 75)
				{
					player2Character.setTextureRect(sf::IntRect(2010, 2618, 393, 558));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 76)
				{
					player2Character.setTextureRect(sf::IntRect(590, 3163, 346, 562));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 77)
				{
					player2Character.setTextureRect(sf::IntRect(0, 2581, 296, 564));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 78)
				{
					player2Character.setTextureRect(sf::IntRect(0, 3720, 316, 567));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 79)
				{
					player2Character.setTextureRect(sf::IntRect(1294, 4313, 387, 584));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 80)
				{
					player2Character.setTextureRect(sf::IntRect(3117, 4360, 398, 583));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 81)
				{
					player2Character.setTextureRect(sf::IntRect(3517, 4364, 429, 579));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 82)
				{
					player2Character.setTextureRect(sf::IntRect(830, 4298, 450, 582));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 83)
				{
					player2Character.setTextureRect(sf::IntRect(418, 4289, 409, 582));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 84)
				{
					player2Character.setTextureRect(sf::IntRect(3600, 3782, 375, 571));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 85)
				{
					player2Character.setTextureRect(sf::IntRect(2001, 3182, 361, 567));
					player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				}

				/////last anim frame
				else if (counter >= 85)
				{
					counter = 0;
					player2CurrentAnimation = "warriorIdle";
					player2MoveFinished = true;
				}

				player2Clock.restart();
				counter++;
			}
		}
	}
}


//thrust strike
void VisibleObjectManager::warriorMove4(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;


	if (player == 1)
	{

		//Caps frame speed
		if (player1PassedTime >= 0.025)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTexture(warriorMove4Texture);

				player1Character.setTextureRect(sf::IntRect(1410, 549, 403, 550));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(1313, 2208, 413, 549));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(5, 0);
			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(2429, 3281, 415, 539));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(7, 0);
			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(2008, 3275, 417, 542));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(16, 0);
			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(2728, 1071, 418, 545));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(15, 0);
			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(3150, 1075, 418, 541));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(19, 0);
			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(2845, 2717, 415, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(21, 0);
			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(2850, 3259, 402, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(24, 0);
			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(1857, 1101, 437, 532));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(90, 0);
			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(1372, 1105, 477, 532));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(135, 0);
			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(1352, 1640, 505, 531));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(160, 0);
			}
			else if (counter == 12)
			{

				player1Character.setTextureRect(sf::IntRect(3332, 541, 498, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(180, 0);
			}
			else if (counter == 13)
			{

				player1Character.setTextureRect(sf::IntRect(1726, 2194, 471, 524));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(148, 0);
			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(1581, 2760, 416, 524));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(100, 0);
			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(2603, 2190, 346, 522));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 0);
			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(3254, 2145, 340, 522));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);
			}
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(3563, 1621, 330, 520));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);

			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(2951, 2167, 300, 520));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);
			}
			else if (counter == 19)
			{
				player1Character.setTextureRect(sf::IntRect(3574, 1075, 307, 523));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);
			}
			else if (counter == 20)
			{
				player1Character.setTextureRect(sf::IntRect(2201, 2185, 398, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);
			}
			else if (counter == 21)
			{
				player1Character.setTextureRect(sf::IntRect(1575, 3296, 428, 525));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);
			}
			else if (counter == 22)
			{
				player1Character.setTextureRect(sf::IntRect(2301, 1094, 425, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);
			}
			else if (counter == 23)
			{
				player1Character.setTextureRect(sf::IntRect(2717, 1632, 404, 529));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);
			}
			else if (counter == 24)
			{
				player1Character.setTextureRect(sf::IntRect(3257, 3269, 439, 506));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);
			}
			else if (counter == 25)
			{
				player1Character.setTextureRect(sf::IntRect(0, 3406, 429, 505));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);
			}
			else if (counter == 26)
			{
				player1Character.setTextureRect(sf::IntRect(685, 2856, 419, 620));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(250, 0);
			}
			else if (counter == 27)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 778, 672));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(250, 0);
			}
			else if (counter == 28)
			{
				player1Character.setTextureRect(sf::IntRect(752, 1637, 596, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(250, 0);
			}
			else if (counter == 29)
			{
				player1Character.setTextureRect(sf::IntRect(1110, 2762, 466, 518));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(200, 0);
			}
			else if (counter == 30)
			{
				player1Character.setTextureRect(sf::IntRect(1110, 2762, 466, 518));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);
			}
			else if (counter == 31)
			{
				player1Character.setTextureRect(sf::IntRect(3261, 2676, 436, 518));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				player1Character.setTextureRect(sf::IntRect(3129, 1627, 430, 513));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				player1Character.setTextureRect(sf::IntRect(1110, 3293, 456, 516));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				player1Character.setTextureRect(sf::IntRect(2811, 541, 518, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 35)
			{
				player1Character.setTextureRect(sf::IntRect(736, 2210, 573, 531));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 36)
			{
				player1Character.setTextureRect(sf::IntRect(784, 549, 622, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 37)
			{
				player1Character.setTextureRect(sf::IntRect(2993, 0, 657, 538));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 38)
			{
				player1Character.setTextureRect(sf::IntRect(3, 2316, 694, 536));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 39)
			{
				player1Character.setTextureRect(sf::IntRect(1538, 0, 721, 540));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 40)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1224, 749, 539));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 41)
			{
				player1Character.setTextureRect(sf::IntRect(0, 678, 758, 539));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 42)
			{
				player1Character.setTextureRect(sf::IntRect(785, 0, 751, 547));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 43)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1770, 734, 544));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 44)
			{
				player1Character.setTextureRect(sf::IntRect(0, 2858, 684, 546));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 45)
			{
				player1Character.setTextureRect(sf::IntRect(762, 1084, 605, 549));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 46)
			{
				player1Character.setTextureRect(sf::IntRect(2300, 501, 508, 546));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 47)
			{
				player1Character.setTextureRect(sf::IntRect(1820, 549, 475, 546));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 48)
			{
				player1Character.setTextureRect(sf::IntRect(1862, 1639, 455, 545));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 49)
			{
				player1Character.setTextureRect(sf::IntRect(2002, 2723, 433, 548));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 50)
			{
				player1Character.setTextureRect(sf::IntRect(2441, 2725, 400, 548));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 51)
			{
				player1Character.setTextureRect(sf::IntRect(2323, 1633, 389, 552));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 51)
			{
				counter = 0;
				player1CurrentAnimation = "warriorIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}


	if (player == 2)
	{

		//Caps frame speed
		if (player2PassedTime >= 0.025)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTexture(warriorMove4Texture);

				player2Character.setTextureRect(sf::IntRect(1410, 549, 403, 550));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(1313, 2208, 413, 549));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(2429, 3281, 415, 539));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(2008, 3275, 417, 542));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(2728, 1071, 418, 545));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(3150, 1075, 418, 541));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(2845, 2717, 415, 537));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(2850, 3259, 402, 537));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(1857, 1101, 437, 532));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(1372, 1105, 477, 532));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(1352, 1640, 505, 531));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(3332, 541, 498, 527));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(1726, 2194, 471, 524));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(1581, 2760, 416, 524));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(2603, 2190, 346, 522));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(3254, 2145, 340, 522));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(3563, 1621, 330, 520));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(2951, 2167, 300, 520));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				player2Character.setTextureRect(sf::IntRect(3574, 1075, 307, 523));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				player2Character.setTextureRect(sf::IntRect(2201, 2185, 398, 534));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				player2Character.setTextureRect(sf::IntRect(1575, 3296, 428, 525));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				player2Character.setTextureRect(sf::IntRect(2301, 1094, 425, 534));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				player2Character.setTextureRect(sf::IntRect(2717, 1632, 404, 529));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				player2Character.setTextureRect(sf::IntRect(3257, 3269, 439, 506));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				player2Character.setTextureRect(sf::IntRect(0, 3406, 429, 505));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				player2Character.setTextureRect(sf::IntRect(685, 2856, 419, 620));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 778, 672));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				player2Character.setTextureRect(sf::IntRect(752, 1637, 596, 569));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				player2Character.setTextureRect(sf::IntRect(1110, 2762, 466, 518));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				player2Character.setTextureRect(sf::IntRect(1110, 2762, 466, 518));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				player2Character.setTextureRect(sf::IntRect(3261, 2676, 436, 518));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				player2Character.setTextureRect(sf::IntRect(3129, 1627, 430, 513));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				player2Character.setTextureRect(sf::IntRect(1110, 3293, 456, 516));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				player2Character.setTextureRect(sf::IntRect(2811, 541, 518, 527));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 35)
			{
				player2Character.setTextureRect(sf::IntRect(736, 2210, 573, 531));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 36)
			{
				player2Character.setTextureRect(sf::IntRect(784, 549, 622, 534));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 37)
			{
				player2Character.setTextureRect(sf::IntRect(2993, 0, 657, 538));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 38)
			{
				player2Character.setTextureRect(sf::IntRect(3, 2316, 694, 536));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 39)
			{
				player2Character.setTextureRect(sf::IntRect(1538, 0, 721, 540));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 40)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1224, 749, 539));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 41)
			{
				player2Character.setTextureRect(sf::IntRect(0, 678, 758, 539));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 42)
			{
				player2Character.setTextureRect(sf::IntRect(785, 0, 751, 547));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 43)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1770, 734, 544));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 44)
			{
				player2Character.setTextureRect(sf::IntRect(0, 2858, 684, 546));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 45)
			{
				player2Character.setTextureRect(sf::IntRect(762, 1084, 605, 549));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 46)
			{
				player2Character.setTextureRect(sf::IntRect(2300, 501, 508, 546));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 47)
			{
				player2Character.setTextureRect(sf::IntRect(1820, 549, 475, 546));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 48)
			{
				player2Character.setTextureRect(sf::IntRect(1862, 1639, 455, 545));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 49)
			{
				player2Character.setTextureRect(sf::IntRect(2002, 2723, 433, 548));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 50)
			{
				player2Character.setTextureRect(sf::IntRect(2441, 2725, 400, 548));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 51)
			{
				player2Character.setTextureRect(sf::IntRect(2323, 1633, 389, 552));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 51)
			{
				counter = 0;
				player2CurrentAnimation = "warriorIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}
}

//power stance
void VisibleObjectManager::warriorMove5(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	if (player == 1)
	{


		//Caps frame speed
		if (player1PassedTime >= 0.025)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(warriorMove5Texture);
				powerStanceChargePlayer1.setTexture(powerStanceCharge);

				player1Character.setTextureRect(sf::IntRect(1234, 2694, 395, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-34, 5);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(38, 145, 450, 450));
				powerStanceChargePlayer1.setPosition(300, 300);
				powerStanceChargePlayer1.move(0, 30);
			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(394, 3425, 381, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-55, 3);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(548, 145, 450, 450));
			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(0, 3293, 389, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-54, 6);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(1052, 145, 450, 450));
			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(405, 2886, 388, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-54, 5);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(1573, 145, 450, 450));
			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(783, 3426, 380, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-40, 5);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(2078, 145, 450, 450));
			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(2117, 1048, 307, 525));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-44, -5);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(2587, 145, 450, 450));
			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(2080, 1633, 322, 508));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-30, -15);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(3100, 145, 450, 450));
			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(2069, 2723, 347, 553));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-5, 40);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(3615, 145, 450, 450));
			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(1218, 3237, 380, 597));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(30, 108);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(30, 646, 450, 450));
			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(836, 1580, 406, 616));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 155);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(544, 646, 450, 450));
			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 421, 607));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(55, 183);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(1054, 646, 450, 450));
			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(1697, 516, 414, 578));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(45, 190);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(1573, 646, 450, 450));
			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(829, 2203, 400, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(45, 195);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(2073, 646, 450, 450));
			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(1631, 3217, 386, 565));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(15, 195);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(2588, 646, 450, 450));
			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(0, 2736, 399, 545));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(20, 190);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(3106, 646, 450, 450));
			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(838, 1045, 412, 529));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(30, 191);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(3598, 646, 450, 450));
			}
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(1694, 1098, 412, 526));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 189);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(37, 1144, 450, 450));
			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(418, 1145, 412, 535));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(534, 1144, 450, 450));
			}
			else if (counter == 19)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1661, 412, 535));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 186);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(1042, 1144, 450, 450));
			}
			else if (counter == 20)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1122, 414, 535));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(1550, 1144, 450, 450));
			}
			else if (counter == 21)
			{
				player1Character.setTextureRect(sf::IntRect(853, 515, 417, 525));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 189);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(2065, 1144, 450, 450));
			}
			else if (counter == 22)
			{
				player1Character.setTextureRect(sf::IntRect(1275, 0, 417, 518));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 191);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(2584, 1144, 450, 450));

			}
			else if (counter == 23)
			{
				player1Character.setTextureRect(sf::IntRect(855, 0, 419, 511));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 189);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(3100, 1144, 450, 450));
			}
			else if (counter == 24)
			{
				player1Character.setTextureRect(sf::IntRect(1699, 0, 415, 511));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(3615, 1144, 450, 450));

			}
			else if (counter == 25)
			{
				player1Character.setTextureRect(sf::IntRect(0, 610, 419, 513));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 193);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(38, 1551, 450, 450));

			}
			else if (counter == 26)
			{
				player1Character.setTextureRect(sf::IntRect(422, 623, 413, 519));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 192);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(534, 1551, 450, 450));
				powerStanceChargePlayer1.move(0, -30);
			}
			else if (counter == 27)
			{
				player1Character.setTextureRect(sf::IntRect(1259, 1119, 408, 511));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 187);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(1042, 1551, 450, 450));
			}
			else if (counter == 28)
			{
				player1Character.setTextureRect(sf::IntRect(0, 2227, 409, 506));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(1550, 1551, 450, 450));
			}
			else if (counter == 29)
			{
				player1Character.setTextureRect(sf::IntRect(1247, 1656, 405, 510));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 193);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(2065, 1551, 450, 450));
			}
			else if (counter == 30)
			{
				player1Character.setTextureRect(sf::IntRect(1656, 2174, 405, 511));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(2584, 1551, 450, 450));
			}
			else if (counter == 31)
			{
				player1Character.setTextureRect(sf::IntRect(1246, 2173, 405, 517));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(3100, 1551, 450, 450));
			}
			else if (counter == 32)
			{
				player1Character.setTextureRect(sf::IntRect(1659, 2700, 405, 513));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 192);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(3615, 1551, 450, 450));
			}
			else if (counter == 33)
			{
				player1Character.setTextureRect(sf::IntRect(412, 2308, 399, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 192);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(38, 2080, 450, 450));
			}
			else if (counter == 34)
			{
				player1Character.setTextureRect(sf::IntRect(1273, 522, 416, 579));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(65, 191);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(534, 2080, 450, 450));
			}
			else if (counter == 35)
			{
				player1Character.setTextureRect(sf::IntRect(428, 1, 419, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(74, 181);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(1042, 2080, 450, 450));
			}
			else if (counter == 36)
			{
				player1Character.setTextureRect(sf::IntRect(417, 1686, 406, 616));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(62, 158);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(1550, 2080, 450, 450));
			}
			else if (counter == 37)
			{
				player1Character.setTextureRect(sf::IntRect(2021, 3289, 381, 590));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(30, 103);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(2065, 2080, 450, 450));
			}
			else if (counter == 38)
			{
				player1Character.setTextureRect(sf::IntRect(2068, 2161, 349, 554));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 39);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(2584, 2080, 450, 450));
			}
			else if (counter == 39)
			{
				player1Character.setTextureRect(sf::IntRect(2117, 517, 307, 523));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-50, -11);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(3100, 2080, 450, 450));

			}
			else if (counter == 40)
			{

				player1Character.setTexture(warriorMove5Texture2);
				player1Character.setTextureRect(sf::IntRect(54, 6, 327, 513));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-53, 2);

				//power stance effect
				powerStanceChargePlayer1.setTextureRect(sf::IntRect(3615, 2080, 450, 450));

			}
			else if (counter >= 40)
			{

				player1CurrentAnimation = "warriorIdle";
				player1MoveFinished = true;
				counter = 0;


			}

			player1Clock.restart();
			counter++;

		}
	}

	if (player == 2)
	{


		//Caps frame speed
		if (player2PassedTime >= 0.025)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(warriorMove5Texture);
				powerStanceChargePlayer2.setTexture(powerStanceCharge);

				player2Character.setTextureRect(sf::IntRect(1234, 2694, 395, 537));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-34, 5);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(38, 145, 450, 450));
				powerStanceChargePlayer2.setPosition(1200, 300);
				powerStanceChargePlayer2.move(0, 30);
			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(394, 3425, 381, 537));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-55, 3);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(548, 145, 450, 450));
			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(0, 3293, 389, 534));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-54, 6);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(1052, 145, 450, 450));
			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(405, 2886, 388, 537));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-54, 5);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(1573, 145, 450, 450));
			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(783, 3426, 380, 537));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-40, 5);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(2078, 145, 450, 450));
			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(2117, 1048, 307, 525));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-44, -5);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(2587, 145, 450, 450));
			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(2080, 1633, 322, 508));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-30, -15);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(3100, 145, 450, 450));
			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(2069, 2723, 347, 553));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-5, 40);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(3615, 145, 450, 450));
			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(1218, 3237, 380, 597));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(30, 108);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(30, 646, 450, 450));
			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(836, 1580, 406, 616));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 155);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(544, 646, 450, 450));
			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 421, 607));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(55, 183);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(1054, 646, 450, 450));
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(1697, 516, 414, 578));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(45, 190);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(1573, 646, 450, 450));
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(829, 2203, 400, 572));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(45, 195);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(2073, 646, 450, 450));
			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(1631, 3217, 386, 565));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(15, 195);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(2588, 646, 450, 450));
			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(0, 2736, 399, 545));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(20, 190);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(3106, 646, 450, 450));
			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(838, 1045, 412, 529));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(30, 191);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(3598, 646, 450, 450));
			}
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(1694, 1098, 412, 526));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 189);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(37, 1144, 450, 450));
			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(418, 1145, 412, 535));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(534, 1144, 450, 450));
			}
			else if (counter == 19)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1661, 412, 535));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 186);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(1042, 1144, 450, 450));
			}
			else if (counter == 20)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1122, 414, 535));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(1550, 1144, 450, 450));
			}
			else if (counter == 21)
			{
				player2Character.setTextureRect(sf::IntRect(853, 515, 417, 525));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 189);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(2065, 1144, 450, 450));
			}
			else if (counter == 22)
			{
				player2Character.setTextureRect(sf::IntRect(1275, 0, 417, 518));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 191);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(2584, 1144, 450, 450));

			}
			else if (counter == 23)
			{
				player2Character.setTextureRect(sf::IntRect(855, 0, 419, 511));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 189);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(3100, 1144, 450, 450));
			}
			else if (counter == 24)
			{
				player2Character.setTextureRect(sf::IntRect(1699, 0, 415, 511));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(3615, 1144, 450, 450));

			}
			else if (counter == 25)
			{
				player2Character.setTextureRect(sf::IntRect(0, 610, 419, 513));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 193);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(38, 1551, 450, 450));

			}
			else if (counter == 26)
			{
				player2Character.setTextureRect(sf::IntRect(422, 623, 413, 519));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 192);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(534, 1551, 450, 450));
				powerStanceChargePlayer2.move(0, -30);
			}
			else if (counter == 27)
			{
				player2Character.setTextureRect(sf::IntRect(1259, 1119, 408, 511));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 187);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(1042, 1551, 450, 450));
			}
			else if (counter == 28)
			{
				player2Character.setTextureRect(sf::IntRect(0, 2227, 409, 506));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(1550, 1551, 450, 450));
			}
			else if (counter == 29)
			{
				player2Character.setTextureRect(sf::IntRect(1247, 1656, 405, 510));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 193);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(2065, 1551, 450, 450));
			}
			else if (counter == 30)
			{
				player2Character.setTextureRect(sf::IntRect(1656, 2174, 405, 511));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(2584, 1551, 450, 450));
			}
			else if (counter == 31)
			{
				player2Character.setTextureRect(sf::IntRect(1246, 2173, 405, 517));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 190);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(3100, 1551, 450, 450));
			}
			else if (counter == 32)
			{
				player2Character.setTextureRect(sf::IntRect(1659, 2700, 405, 513));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 192);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(3615, 1551, 450, 450));
			}
			else if (counter == 33)
			{
				player2Character.setTextureRect(sf::IntRect(412, 2308, 399, 569));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 192);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(38, 2080, 450, 450));
			}
			else if (counter == 34)
			{
				player2Character.setTextureRect(sf::IntRect(1273, 522, 416, 579));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(65, 191);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(534, 2080, 450, 450));
			}
			else if (counter == 35)
			{
				player2Character.setTextureRect(sf::IntRect(428, 1, 419, 604));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(74, 181);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(1042, 2080, 450, 450));
			}
			else if (counter == 36)
			{
				player2Character.setTextureRect(sf::IntRect(417, 1686, 406, 616));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(62, 158);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(1550, 2080, 450, 450));
			}
			else if (counter == 37)
			{
				player2Character.setTextureRect(sf::IntRect(2021, 3289, 381, 590));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(30, 103);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(2065, 2080, 450, 450));
			}
			else if (counter == 38)
			{
				player2Character.setTextureRect(sf::IntRect(2068, 2161, 349, 554));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 39);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(2584, 2080, 450, 450));
			}
			else if (counter == 39)
			{
				player2Character.setTextureRect(sf::IntRect(2117, 517, 307, 523));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-50, -11);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(3100, 2080, 450, 450));

			}
			else if (counter == 40)
			{

				player2Character.setTexture(warriorMove5Texture2);
				player2Character.setTextureRect(sf::IntRect(54, 6, 327, 513));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-53, 2);

				//power stance effect
				powerStanceChargePlayer2.setTextureRect(sf::IntRect(3615, 2080, 450, 450));

			}
			else if (counter >= 40)
			{

				player2CurrentAnimation = "warriorIdle";
				player2MoveFinished = true;
				counter = 0;


			}

			player2Clock.restart();
			counter++;

		}
	}
}

//shout
void VisibleObjectManager::warriorMove6(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	if (player == 1)
	{

		//Caps frame speed
		if (player1PassedTime >= 0.04)
		{


			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTexture(warriorMove6Texture);

				player1Character.setTextureRect(sf::IntRect(2254, 0, 440, 518));
			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(0, 521, 447, 514));
			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(1274, 524, 451, 517));
			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(2145, 525, 456, 518));
			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(2601, 526, 456, 518));
			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(423, 1044, 452, 522));
			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(879, 1045, 448, 522));
			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(3056, 524, 449, 522));
			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(1331, 1048, 439, 523));
			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(2199, 1050, 434, 525));
			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(2635, 1050, 426, 525));
			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(3064, 1051, 425, 525));
			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(1774, 1048, 422, 525));
			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1041, 418, 523));
			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(1727, 520, 415, 522));
			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(860, 518, 410, 522));
			}
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(451, 518, 405, 520));
			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(3095, 0, 399, 519));
			}
			else if (counter == 19)
			{
				player1Character.setTextureRect(sf::IntRect(2696, 0, 395, 519));
			}
			else if (counter == 20)
			{
				player1Character.setTextureRect(sf::IntRect(1864, 0, 384, 517));
			}
			else if (counter == 21)
			{
				player1Character.setTextureRect(sf::IntRect(1477, 0, 384, 517));
			}
			else if (counter == 22)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 376, 515));
			}
			else if (counter == 23)
			{
				player1Character.setTextureRect(sf::IntRect(380, 0, 369, 515));
			}
			else if (counter == 24)
			{
				player1Character.setTextureRect(sf::IntRect(750, 0, 363, 515));
			}
			else if (counter == 25)
			{
				player1Character.setTextureRect(sf::IntRect(1116, 0, 357, 515));
			}
			else if (counter >= 25)
			{
				counter = 0;
				player1CurrentAnimation = "warriorIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}


	if (player == 2)
	{

		//Caps frame speed
		if (player2PassedTime >= 0.04)
		{


			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTexture(warriorMove6Texture);

				player2Character.setTextureRect(sf::IntRect(2254, 0, 440, 518));
			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(0, 521, 447, 514));
			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(1274, 524, 451, 517));
			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(2145, 525, 456, 518));
			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(2601, 526, 456, 518));
			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(423, 1044, 452, 522));
			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(879, 1045, 448, 522));
			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(3056, 524, 449, 522));
			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(1331, 1048, 439, 523));
			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(2199, 1050, 434, 525));
			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(2635, 1050, 426, 525));
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(3064, 1051, 425, 525));
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(1774, 1048, 422, 525));
			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1041, 418, 523));
			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(1727, 520, 415, 522));
			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(860, 518, 410, 522));
			}
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(451, 518, 405, 520));
			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(3095, 0, 399, 519));
			}
			else if (counter == 19)
			{
				player2Character.setTextureRect(sf::IntRect(2696, 0, 395, 519));
			}
			else if (counter == 20)
			{
				player2Character.setTextureRect(sf::IntRect(1864, 0, 384, 517));
			}
			else if (counter == 21)
			{
				player2Character.setTextureRect(sf::IntRect(1477, 0, 384, 517));
			}
			else if (counter == 22)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 376, 515));
			}
			else if (counter == 23)
			{
				player2Character.setTextureRect(sf::IntRect(380, 0, 369, 515));
			}
			else if (counter == 24)
			{
				player2Character.setTextureRect(sf::IntRect(750, 0, 363, 515));
			}
			else if (counter == 25)
			{
				player2Character.setTextureRect(sf::IntRect(1116, 0, 357, 515));
			}
			else if (counter >= 25)
			{
				counter = 0;
				player2CurrentAnimation = "warriorIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}
}

//guard
void VisibleObjectManager::warriorMove7(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1593;
	vec2Player2.y = 550;

	if (player == 1)
	{


		//Caps frame speed
		if (player1PassedTime >= 0.03)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(warriorMove7Texture);

				player1Character.setTextureRect(sf::IntRect(0, 2276, 392, 544));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(1289, 2236, 384, 547));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(1288, 1683, 409, 549));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 0);
			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(864, 2235, 425, 549));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 0);
			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(434, 2227, 430, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 0);
			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1716, 430, 553));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 0);
			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(467, 1677, 441, 553));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 0);
			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(1025, 1122, 452, 556));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 0);
			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1157, 467, 556));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(55, 0);
			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(548, 1100, 472, 575));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(60, 0);
			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(1190, 8, 491, 599));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(70, 0);
			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(1, 583, 543, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(72, 0);
			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(612, 0, 571, 583));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(75, 0);
			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 608, 558));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(100, 0);
			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(544, 586, 576, 513));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(200, 0);
			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(1122, 608, 576, 515));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(200, 0);
			}
			else if (counter >= 16)
			{
				player1CurrentAnimation = "warriorIdle";
			}

			player1Clock.restart();
			counter++;

		}
	}

	if (player == 2)
	{


		//Caps frame speed
		if (player2PassedTime >= 0.03)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(warriorMove7Texture);

				player2Character.setTextureRect(sf::IntRect(0, 2276, 392, 544));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(1289, 2236, 384, 547));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(1288, 1683, 409, 549));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 0);
			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(864, 2235, 425, 549));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 0);
			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(434, 2227, 430, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 0);
			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1716, 430, 553));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 0);
			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(467, 1677, 441, 553));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 0);
			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(1025, 1122, 452, 556));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(50, 0);
			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1157, 467, 556));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(55, 0);
			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(548, 1100, 472, 575));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(60, 0);
			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(1190, 8, 491, 599));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(70, 0);
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(1, 583, 543, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(72, 0);
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(612, 0, 571, 583));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(75, 0);
			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 608, 558));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(100, 0);
			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(544, 586, 576, 513));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(200, 0);
			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(1122, 608, 576, 515));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(200, 0);
			}
			else if (counter >= 16)
			{
				player2CurrentAnimation = "warriorIdle";
			}

			player2Clock.restart();
			counter++;

		}
	}

}



//taunt
void VisibleObjectManager::warriorMove8(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	if (player == 1)
	{


		//Caps frame speed
		if (player1PassedTime >= 0.05)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(warriorMove8Texture);

				player1Character.setTextureRect(sf::IntRect(1121, 1157, 256, 577));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 259, 577));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);

			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(1120, 580, 261, 575));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(1120, 0, 261, 575));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(571, 578, 267, 574));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(851, 1155, 267, 574));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(842, 578, 271, 574));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(568, 1158, 277, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(287, 1156, 279, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1159, 283, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(0, 582, 283, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(260, 0, 283, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(284, 578, 285, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(544, 0, 285, 575));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(830, 0, 285, 575));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-73, 0);
			}
			else if (counter >= 15)
			{

				counter = 0;
				player1CurrentAnimation = "warriorIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}

	if (player == 2)
	{


		//Caps frame speed
		if (player2PassedTime >= 0.05)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(warriorMove8Texture);

				player2Character.setTextureRect(sf::IntRect(1121, 1157, 256, 577));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 259, 577));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);

			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(1120, 580, 261, 575));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(1120, 0, 261, 575));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(571, 578, 267, 574));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(851, 1155, 267, 574));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(842, 578, 271, 574));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(568, 1158, 277, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(287, 1156, 279, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1159, 283, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(0, 582, 283, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(260, 0, 283, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(284, 578, 285, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(544, 0, 285, 575));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(830, 0, 285, 575));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player2Character.move(73, 0);
			}
			else if (counter >= 15)
			{

				counter = 0;
				player2CurrentAnimation = "warriorIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}

};



void VisibleObjectManager::warriorHurt(int& counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 500;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;



	if (player == 1)
	{
		//Caps frame speed
		if (player1PassedTime >= 0.04)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(warriorHurtTexture);
				player1Character.setTextureRect(sf::IntRect(1, 1, 455, 526));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(1, 529, 449, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));


			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(1, 1058, 440, 530));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(1419, 1053, 424, 529));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(859, 528, 418, 526));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(450, 533, 409, 523));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(1358, 1, 427, 530));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(458, 1, 456, 525));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(912, 1, 440, 513));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(1604, 533, 291, 476));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-30, 0);

			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(1276, 533, 319, 518));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-30, 0);
			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(441, 1058, 322, 535));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-60, 0);
			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(763, 1058, 323, 552));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(1086, 1056, 325, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

			}
			else if (counter >= 14)
			{

				counter = 0;
				player1CurrentAnimation = "warriorIdle";
				player1MoveFinished = true;
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}


	if (player == 2)
	{
		//Caps frame speed
		if (player2PassedTime >= 0.04)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(warriorHurtTexture);

				player2Character.setTextureRect(sf::IntRect(1, 1, 455, 526));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(1, 529, 449, 527));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));


			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(1, 1058, 440, 530));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(1419, 1053, 424, 529));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(859, 528, 418, 526));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(450, 533, 409, 523));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(1358, 1, 427, 530));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(458, 1, 456, 525));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(912, 1, 440, 513));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(1604, 533, 291, 476));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player1Character.move(30, 0);
			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(1276, 533, 319, 518));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player1Character.move(30, 0);
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(441, 1058, 322, 535));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				player1Character.move(60, 0);
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(763, 1058, 323, 552));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(1086, 1056, 325, 569));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter >= 14)
			{

				counter = 0;
				player2CurrentAnimation = "warriorIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}
}









////////////////////////////////////////////////////////////////






//ASSASSIN////

//idle
void VisibleObjectManager::assassinIdle(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 360;
	vec1.y = 410;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 600;
	vec1Player2.y = 410;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;




	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1563;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.14)
	{
		if (player == 1)
		{

			player1Character.setScale(.8, .8);

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(assassinIdleTexture);
			player1Character.setTextureRect(sf::IntRect(0, 0, 417, 596));

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 417, 596));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-2, -4);
			}
			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 603, 423, 595));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-4, -2);
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(418, 0, 424, 595));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-6, -2);
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(425, 1166, 423, 595));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-8, 2);
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1300, 1166, 435, 587));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-4, -4);
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1293, 577, 446, 587));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, -6);
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(843, 0, 459, 574));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(14, -17);
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1302, 0, 459, 574));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(10, -18);
			}

			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(826, 578, 468, 583));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(14, -8);
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1302, 0, 459, 574));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(10, -18);
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(843, 0, 459, 574));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(14, -17);
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1293, 577, 446, 587));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(2, -8);
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1300, 1166, 435, 587));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-4, -4);
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(425, 1166, 423, 595));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-9, 4);
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(418, 0, 424, 595));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-6, -1);
			}

			else if (counter > 15)
			{
				player1Character.move(10, -3);
				counter = 0;
			}
			player1Clock.restart();
			counter++;
		}
	}



	//Caps frame speed
	if (player2PassedTime >= 0.14)
	{
		if (player == 2)
		{

			player2Character.setScale(-.8, .8);

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(assassinIdleTexture);
			player2Character.setTextureRect(sf::IntRect(0, 0, 417, 596));

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 417, 596));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(2, -4);
			}
			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 603, 423, 595));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(4, -2);
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(418, 0, 424, 595));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(6, -2);
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(425, 1166, 423, 595));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(8, 2);
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1300, 1166, 435, 587));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(4, -4);
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1293, 577, 446, 587));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, -6);
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(843, 0, 459, 574));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-14, -17);
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1302, 0, 459, 574));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-10, -18);
			}

			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(826, 578, 468, 583));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-14, -8);
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1302, 0, 459, 574));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-10, -18);
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(843, 0, 459, 574));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-14, -17);
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1293, 577, 446, 587));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-2, -8);
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1300, 1166, 435, 587));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(4, -4);
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(425, 1166, 423, 595));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(9, 4);
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(418, 0, 424, 595));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(6, -1);
			}

			else if (counter > 15)
			{
				player2Character.move(-10, -3);
				counter = 0;
			}
			player2Clock.restart();
			counter++;
		}
	}

}

//smoke bomb
void VisibleObjectManager::assassinMove1(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());



	sf::Vector2f vec1;
	vec1.x = 360;
	vec1.y = 400;





	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 360;
	vec1Player2.y = 400;

	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1323;
	vec2Player2.y = 550;


	if (player == 1)
	{
		player1Character.setScale(.8, .8);

		//Caps frame speed
		if (player1PassedTime >= 0.03)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(assassinMove1Texture);

				player1Character.setTextureRect(sf::IntRect(0, 1642, 414, 590));
				player1Character.move(15, -5);


			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(0, 2241, 410, 590));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(3, 10);

			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(0, 2836, 405, 587));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(9, 14);


			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(710, 2234, 393, 587));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(8, 21);

			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(801, 2823, 378, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(4, 24);

			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(813, 3407, 360, 575));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 21);

			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(458, 1071, 333, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(-8, 13);

			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(454, 3428, 351, 549));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 3);

			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(1465, 3361, 319, 536));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -8);

			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(956, 533, 336, 532));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -12);

			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 495, 532));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(160, -13);

			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(499, 537, 452, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(130, -13);

			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(1468, 1621, 443, 525));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(100, -13);

			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(1470, 2151, 418, 521));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(90, -13);

			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(1107, 2207, 357, 521));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -15);

			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(1688, 2677, 286, 530));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -15);

			}
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(1768, 541, 270, 528));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -15);

			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(795, 1070, 275, 535));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -15);

			}
			else if (counter == 19)
			{
				player1Character.setTextureRect(sf::IntRect(1176, 3408, 283, 549));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -15);

			}
			else if (counter == 20)
			{
				player1Character.setTextureRect(sf::IntRect(410, 2251, 295, 579));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -12);

			}
			else if (counter == 21)
			{
				player1Character.setTextureRect(sf::IntRect(417, 1644, 287, 603));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 0);

			}
			else if (counter == 22)
			{
				player1Character.setTextureRect(sf::IntRect(1453, 2737, 232, 618));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 0);

			}
			else if (counter == 23)
			{
				player1Character.setTextureRect(sf::IntRect(1182, 2737, 266, 614));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 0);

			}
			else if (counter == 24)
			{
				player1Character.setTextureRect(sf::IntRect(709, 1639, 330, 591));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 0);

			}
			else if (counter == 25)
			{
				player1Character.setTextureRect(sf::IntRect(408, 2837, 387, 586));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 0);

			}
			else if (counter == 26)
			{
				player1Character.setTextureRect(sf::IntRect(1043, 1622, 422, 580));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 0);

			}
			else if (counter == 27)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1072, 446, 567));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 0);

			}
			else if (counter == 28)
			{
				player1Character.setTextureRect(sf::IntRect(0, 3429, 452, 555));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 0);

			}
			else if (counter == 29)
			{
				player1Character.setTextureRect(sf::IntRect(1081, 1071, 451, 544));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, 0);

			}
			else if (counter == 30)
			{
				player1Character.setTextureRect(sf::IntRect(1483, 0, 478, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -9);

			}
			else if (counter == 31)
			{
				player1Character.setTextureRect(sf::IntRect(0, 537, 493, 530));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -13);

			}
			else if (counter == 32)
			{
				player1Character.setTextureRect(sf::IntRect(499, 0, 493, 530));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -13);

			}
			else if (counter == 33)
			{
				player1Character.setTextureRect(sf::IntRect(996, 0, 483, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -13);

			}
			else if (counter == 34)
			{
				player1Character.setTextureRect(sf::IntRect(1299, 539, 466, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -11);

			}
			else if (counter == 35)
			{
				player1Character.setTextureRect(sf::IntRect(1537, 1083, 456, 533));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(0, -4);

			}

			else if (counter >= 36)
			{
				counter = 1;
				player1CurrentAnimation = "assassinIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}


	if (player == 2)
	{
		player2Character.setScale(-.8, .8);

		//Caps frame speed
		if (player2PassedTime >= 0.03)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(assassinMove1Texture);

				player2Character.setTextureRect(sf::IntRect(0, 1642, 414, 590));
				player2Character.move(-15, -5);


			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(0, 2241, 410, 590));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-3, 10);

			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(0, 2836, 405, 587));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-9, 14);


			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(710, 2234, 393, 587));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-8, 21);

			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(801, 2823, 378, 582));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-4, 24);

			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(813, 3407, 360, 575));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 21);

			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(458, 1071, 333, 563));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(8, 13);

			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(454, 3428, 351, 549));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 3);

			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(1465, 3361, 319, 536));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -8);

			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(956, 533, 336, 532));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -12);

			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 495, 532));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-160, -13);

			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(499, 537, 452, 527));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-130, -13);

			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(1468, 1621, 443, 525));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-100, -13);

			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(1470, 2151, 418, 521));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-90, -13);

			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(1107, 2207, 357, 521));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -15);

			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(1688, 2677, 286, 530));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -15);

			}
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(1768, 541, 270, 528));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -15);

			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(795, 1070, 275, 535));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -15);

			}
			else if (counter == 19)
			{
				player2Character.setTextureRect(sf::IntRect(1176, 3408, 283, 549));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -15);

			}
			else if (counter == 20)
			{
				player2Character.setTextureRect(sf::IntRect(410, 2251, 295, 579));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -12);

			}
			else if (counter == 21)
			{
				player2Character.setTextureRect(sf::IntRect(417, 1644, 287, 603));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 0);

			}
			else if (counter == 22)
			{
				player2Character.setTextureRect(sf::IntRect(1453, 2737, 232, 618));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 0);

			}
			else if (counter == 23)
			{
				player2Character.setTextureRect(sf::IntRect(1182, 2737, 266, 614));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 0);

			}
			else if (counter == 24)
			{
				player2Character.setTextureRect(sf::IntRect(709, 1639, 330, 591));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 0);

			}
			else if (counter == 25)
			{
				player2Character.setTextureRect(sf::IntRect(408, 2837, 387, 586));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 0);

			}
			else if (counter == 26)
			{
				player2Character.setTextureRect(sf::IntRect(1043, 1622, 422, 580));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 0);

			}
			else if (counter == 27)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1072, 446, 567));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 0);

			}
			else if (counter == 28)
			{
				player2Character.setTextureRect(sf::IntRect(0, 3429, 452, 555));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 0);

			}
			else if (counter == 29)
			{
				player2Character.setTextureRect(sf::IntRect(1081, 1071, 451, 544));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, 0);

			}
			else if (counter == 30)
			{
				player2Character.setTextureRect(sf::IntRect(1483, 0, 478, 534));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -9);

			}
			else if (counter == 31)
			{
				player2Character.setTextureRect(sf::IntRect(0, 537, 493, 530));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -13);

			}
			else if (counter == 32)
			{
				player2Character.setTextureRect(sf::IntRect(499, 0, 493, 530));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -13);

			}
			else if (counter == 33)
			{
				player2Character.setTextureRect(sf::IntRect(996, 0, 483, 527));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -13);

			}
			else if (counter == 34)
			{
				player2Character.setTextureRect(sf::IntRect(1299, 539, 466, 527));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -11);

			}
			else if (counter == 35)
			{
				player2Character.setTextureRect(sf::IntRect(1537, 1083, 456, 533));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(0, -4);

			}

			else if (counter >= 36)
			{
				counter = 1;
				player2CurrentAnimation = "assassinIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}


}

//apply poison
void VisibleObjectManager::assassinMove2(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	if (player == 1)
	{
		player1Character.setScale(.8, .8);

		//Caps frame speed
		if (player1PassedTime >= 0.03)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(assassinMove2Texture);

				player1Character.setTextureRect(sf::IntRect(0, 0, 416, 590));
				player1Character.move(10, -5);


			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(418, 0, 414, 590));

			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(0, 602, 400, 588));
				player1Character.move(0, 3);

			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(404, 601, 372, 584));
				player1Character.move(0, 1);

			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(1199, 1762, 373, 582));
				player1Character.move(0, 2);

			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(1190, 2350, 381, 573));
				player1Character.move(0, 2);

			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(403, 1197, 396, 567));
				player1Character.move(-3, 2);

			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(406, 1768, 397, 565));

			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(806, 1195, 401, 563));
				player1Character.move(0, 2);

			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(0, 2350, 405, 563));
				player1Character.move(0, 3);

			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(411, 2341, 401, 564));

			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(838, 0, 399, 569));
				player1Character.move(0, -4);

			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1780, 402, 562));
				player1Character.move(0, 5);

			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1208, 399, 562));

			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(818, 1765, 378, 577));
				player1Character.move(14, -6);

			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(815, 2347, 371, 582));
				player1Character.move(0, -2);

			}
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(1154, 575, 366, 585));
				player1Character.move(0, 0);

			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(783, 604, 364, 585));

			}

			else if (counter >= 19)
			{
				counter = 1;
				player1CurrentAnimation = "assassinIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}


	if (player == 2)
	{
		player2Character.setScale(-.8, .8);

		//Caps frame speed
		if (player2PassedTime >= 0.03)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(assassinMove2Texture);

				player2Character.setTextureRect(sf::IntRect(0, 0, 416, 590));
				player2Character.move(-10, -5);


			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(418, 0, 414, 590));

			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(0, 602, 400, 588));
				player2Character.move(0, 3);

			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(404, 601, 372, 584));
				player2Character.move(0, 1);

			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(1199, 1762, 373, 582));
				player2Character.move(0, 2);

			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(1190, 2350, 381, 573));
				player2Character.move(0, 2);

			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(403, 1197, 396, 567));
				player2Character.move(3, 2);

			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(406, 1768, 397, 565));

			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(806, 1195, 401, 563));
				player2Character.move(0, 2);

			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(0, 2350, 405, 563));
				player2Character.move(0, 3);

			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(411, 2341, 401, 564));

			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(838, 0, 399, 569));
				player2Character.move(0, -4);

			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1780, 402, 562));
				player2Character.move(0, 5);

			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1208, 399, 562));

			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(818, 1765, 378, 577));
				player2Character.move(-14, -6);

			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(815, 2347, 371, 582));
				player2Character.move(0, -2);

			}
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(1154, 575, 366, 585));
				player2Character.move(0, 0);

			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(783, 604, 364, 585));

			}

			else if (counter >= 19)
			{
				counter = 1;
				player2CurrentAnimation = "assassinIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}


}

//kunais
void VisibleObjectManager::assassinMove3(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());



	sf::Vector2f vec1;
	vec1.x = 360;
	vec1.y = 405;





	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 360;
	vec1Player2.y = 405;

	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1323;
	vec2Player2.y = 550;


	if (player == 1)
	{

		player1Character.setScale(.8, .8);
		//Caps frame speed
		if (player1PassedTime >= 0.02)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(assassinMove3Texture);

				player1Character.setTextureRect(sf::IntRect(1828, 0, 413, 591));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));


			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(1781, 1220, 421, 588));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

				player1Character.move(2, 0);
			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(1353, 1227, 425, 588));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(8, 0);
			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(913, 1224, 434, 593));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(17, 0);
			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(1375, 0, 446, 598));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(26, 0);
			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(917, 0, 451, 598));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(35, 0);
			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(446, 1227, 461, 596));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(45, 0);
			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1847, 466, 599));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 0);
			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(448, 0, 463, 602));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(47, 0);


			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(450, 612, 459, 602));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(47, 0);
			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(472, 1833, 459, 602));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(47, 0);
			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(915, 612, 456, 601));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(47, 0);
			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(1377, 609, 453, 601));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(47, 0);
			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(934, 2442, 449, 607));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(44, 4);
			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(1369, 1826, 449, 603));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(44, 0);

			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 445, 607));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(39, 0);
			}
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(0, 617, 442, 605));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(36, 0);
			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1234, 438, 602));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(32, 0);
			}
			else if (counter == 19)
			{
				player1Character.setTextureRect(sf::IntRect(935, 1829, 429, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(26, 0);
			}
			else if (counter == 20)
			{
				player1Character.setTextureRect(sf::IntRect(0, 2458, 433, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(26, 0);
			}
			else if (counter == 21)
			{
				player1Character.setTextureRect(sf::IntRect(437, 2459, 429, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(23, 0);
			}
			else if (counter == 22)
			{
				player1Character.setTextureRect(sf::IntRect(1389, 2441, 423, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(20, 0);
			}
			else if (counter == 23)
			{
				player1Character.setTextureRect(sf::IntRect(1388, 3056, 423, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(17, 0);
			}
			else if (counter == 24)
			{
				player1Character.setTextureRect(sf::IntRect(1816, 3056, 423, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(17, 0);
			}
			else if (counter == 25)
			{
				player1Character.setTextureRect(sf::IntRect(1820, 2440, 420, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(16, 0);
			}
			else if (counter == 26)
			{
				player1Character.setTextureRect(sf::IntRect(1825, 1820, 420, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(17, 0);
			}
			else if (counter == 27)
			{
				player1Character.setTextureRect(sf::IntRect(869, 3056, 423, 607));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(17, 0);
			}
			else if (counter == 28)
			{
				player1Character.setTextureRect(sf::IntRect(0, 3072, 423, 606));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(15, 0);
			}

			else if (counter == 29)
			{
				player1Character.setTextureRect(sf::IntRect(432, 3074, 423, 604));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(20, 0);
			}

			else if (counter >= 30)
			{
				player1Character.move(0, 0);
				counter = 1;
				player1CurrentAnimation = "assassinIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}


	if (player == 2)
	{

		player2Character.setScale(-.8, .8);
		//Caps frame speed
		if (player2PassedTime >= 0.02)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(assassinMove3Texture);

				player2Character.setTextureRect(sf::IntRect(1828, 0, 413, 591));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));


			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(1781, 1220, 421, 588));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));

				player2Character.move(-2, 0);
			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(1353, 1227, 425, 588));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-8, 0);
			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(913, 1224, 434, 593));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-17, 0);
			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(1375, 0, 446, 598));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-26, 0);
			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(917, 0, 451, 598));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-35, 0);
			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(446, 1227, 461, 596));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-45, 0);
			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1847, 466, 599));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-50, 0);
			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(448, 0, 463, 602));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-47, 0);


			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(450, 612, 459, 602));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-47, 0);
			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(472, 1833, 459, 602));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-47, 0);
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(915, 612, 456, 601));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-47, 0);
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(1377, 609, 453, 601));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-47, 0);
			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(934, 2442, 449, 607));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-44, 4);
			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(1369, 1826, 449, 603));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-44, 0);

			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 445, 607));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-39, 0);
			}
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(0, 617, 442, 605));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-36, 0);
			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1234, 438, 602));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-32, 0);
			}
			else if (counter == 19)
			{
				player2Character.setTextureRect(sf::IntRect(935, 1829, 429, 604));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-26, 0);
			}
			else if (counter == 20)
			{
				player2Character.setTextureRect(sf::IntRect(0, 2458, 433, 604));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-26, 0);
			}
			else if (counter == 21)
			{
				player2Character.setTextureRect(sf::IntRect(437, 2459, 429, 604));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-23, 0);
			}
			else if (counter == 22)
			{
				player2Character.setTextureRect(sf::IntRect(1389, 2441, 423, 604));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-20, 0);
			}
			else if (counter == 23)
			{
				player2Character.setTextureRect(sf::IntRect(1388, 3056, 423, 604));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-17, 0);
			}
			else if (counter == 24)
			{
				player2Character.setTextureRect(sf::IntRect(1816, 3056, 423, 604));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-17, 0);
			}
			else if (counter == 25)
			{
				player2Character.setTextureRect(sf::IntRect(1820, 2440, 420, 604));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-16, 0);
			}
			else if (counter == 26)
			{
				player2Character.setTextureRect(sf::IntRect(1825, 1820, 420, 604));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-17, 0);
			}
			else if (counter == 27)
			{
				player2Character.setTextureRect(sf::IntRect(869, 3056, 423, 607));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-17, 0);
			}
			else if (counter == 28)
			{
				player2Character.setTextureRect(sf::IntRect(0, 3072, 423, 606));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-15, 0);
			}

			else if (counter == 29)
			{
				player2Character.setTextureRect(sf::IntRect(432, 3074, 423, 604));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-20, 0);
			}

			else if (counter >= 30)
			{
				player2Character.move(0, 0);
				counter = 1;
				player2CurrentAnimation = "assassinIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}



}

//vital strike
void VisibleObjectManager::assassinMove4(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	if (player == 1)
	{
		player1Character.setScale(.8, .8);
		//Caps frame speed
		if (player1PassedTime >= 0.02)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(assassinMove4Texture);

				player1Character.setTextureRect(sf::IntRect(2041, 2326, 411, 585));


			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(1624, 2320, 411, 580));

			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(1215, 2319, 403, 575));

			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(817, 2315, 393, 568));

			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(415, 2316, 395, 568));

			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(878, 1733, 423, 564));

			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(900, 0, 482, 568));
				player1Character.move(80, 0);
			}
			//FIRST STAB
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(1810, 0, 511, 571));
				player1Character.move(100, 0);
			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(856, 576, 505, 574));


			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(1773, 578, 489, 574));

			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1733, 465, 578));
			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(1307, 1736, 440, 579));
			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(2154, 1742, 425, 579));
			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(0, 2314, 406, 580));
			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(1755, 1737, 391, 577));

			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(472, 1734, 397, 577));

			}
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(879, 1154, 431, 574));

			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(1716, 1159, 479, 574));

			}
			else if (counter == 19)
			{
				player1Character.setTextureRect(sf::IntRect(2200, 1163, 493, 574));

			}
			else if (counter == 20)
			{
				player1Character.setTextureRect(sf::IntRect(406, 1153, 471, 574));

			}
			else if (counter == 21)
			{
				player1Character.setTextureRect(sf::IntRect(418, 576, 433, 574));

			}
			else if (counter == 22)
			{
				player1Character.setTextureRect(sf::IntRect(2267, 582, 405, 574));

			}
			else if (counter == 23)
			{
				player1Character.setTextureRect(sf::IntRect(1315, 1157, 396, 574));

			}
			else if (counter == 24)
			{
				player1Character.setTextureRect(sf::IntRect(2326, 0, 396, 574));

			}
			else if (counter == 25)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1151, 397, 574));
				player1Character.move(-30, 0);
			}
			else if (counter == 26)
			{
				player1Character.setTextureRect(sf::IntRect(1365, 576, 405, 574));
				player1Character.move(-30, 0);
			}
			else if (counter == 27)
			{
				player1Character.setTextureRect(sf::IntRect(0, 572, 411, 574));
				player1Character.move(-30, 1);

			}
			else if (counter == 28)
			{
				player1Character.setTextureRect(sf::IntRect(1385, 0, 423, 574));
				player1Character.move(-30, 1);
			}

			else if (counter == 29)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 443, 570));
				player1Character.move(-23, 1);
			}

			else if (counter == 30)
			{
				player1Character.setTextureRect(sf::IntRect(448, 0, 445, 570));
				player1Character.move(-20, 1);
			}

			else if (counter >= 31)
			{
				counter = 1;
				player1CurrentAnimation = "assassinIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}


	if (player == 2)
	{
		player2Character.setScale(-.8, .8);
		//Caps frame speed
		if (player2PassedTime >= 0.02)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(assassinMove4Texture);

				player2Character.setTextureRect(sf::IntRect(2041, 2326, 411, 585));


			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(1624, 2320, 411, 580));

			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(1215, 2319, 403, 575));

			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(817, 2315, 393, 568));

			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(415, 2316, 395, 568));

			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(878, 1733, 423, 564));

			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(900, 0, 482, 568));
				player2Character.move(-80, 0);
			}
			//FIRST STAB
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(1810, 0, 511, 571));
				player2Character.move(-100, 0);
			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(856, 576, 505, 574));


			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(1773, 578, 489, 574));

			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1733, 465, 578));
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(1307, 1736, 440, 579));
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(2154, 1742, 425, 579));
			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(0, 2314, 406, 580));
			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(1755, 1737, 391, 577));

			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(472, 1734, 397, 577));

			}
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(879, 1154, 431, 574));

			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(1716, 1159, 479, 574));

			}
			else if (counter == 19)
			{
				player2Character.setTextureRect(sf::IntRect(2200, 1163, 493, 574));

			}
			else if (counter == 20)
			{
				player2Character.setTextureRect(sf::IntRect(406, 1153, 471, 574));

			}
			else if (counter == 21)
			{
				player2Character.setTextureRect(sf::IntRect(418, 576, 433, 574));

			}
			else if (counter == 22)
			{
				player2Character.setTextureRect(sf::IntRect(2267, 582, 405, 574));

			}
			else if (counter == 23)
			{
				player2Character.setTextureRect(sf::IntRect(1315, 1157, 396, 574));

			}
			else if (counter == 24)
			{
				player2Character.setTextureRect(sf::IntRect(2326, 0, 396, 574));

			}
			else if (counter == 25)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1151, 397, 574));
				player2Character.move(30, 0);
			}
			else if (counter == 26)
			{
				player2Character.setTextureRect(sf::IntRect(1365, 576, 405, 574));
				player2Character.move(30, 0);
			}
			else if (counter == 27)
			{
				player2Character.setTextureRect(sf::IntRect(0, 572, 411, 574));
				player2Character.move(30, 1);

			}
			else if (counter == 28)
			{
				player2Character.setTextureRect(sf::IntRect(1385, 0, 423, 574));
				player2Character.move(30, 1);
			}

			else if (counter == 29)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 443, 570));
				player2Character.move(23, 1);
			}

			else if (counter == 30)
			{
				player2Character.setTextureRect(sf::IntRect(448, 0, 445, 570));
				player2Character.move(20, 1);
			}

			else if (counter >= 31)
			{
				counter = 1;
				player2CurrentAnimation = "assassinIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}


}


//backblow
void VisibleObjectManager::assassinMove5(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	if (player == 1)
	{

		player1Character.setScale(.8, .8);
		//Caps frame speed
		if (player1PassedTime >= 0.047)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(assassinMove5Texture);

				player1Character.setTextureRect(sf::IntRect(0, 0, 425, 559));
				player1Character.setPosition(520, 385);//400,300

			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(0, 564, 346, 585));
				player1Character.setPosition(620, 385);
			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(2511, 673, 360, 547));
				player1Character.setPosition(720, 415);
			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(2115, 659, 393, 521));
				player1Character.setPosition(820, 435);
			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(1641, 647, 469, 431));
				player1Character.setPosition(920, 455);
			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(1690, 272, 549, 369));
				player1Character.setPosition(1020, 475);
			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(349, 964, 545, 327));
				player1Character.setPosition(1120, 635);
			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1749, 463, 301));
				player1Character.setPosition(1220, 635);
			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(2656, 1226, 395, 287));
				player1Character.setPosition(1220, 635);

			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(1108, 260, 581, 308));
				player1Character.setPosition(1320, 635);
			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(429, 0, 601, 365));
			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(895, 1017, 500, 401));
			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(351, 594, 558, 363));
			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(1035, 0, 700, 254));
			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(434, 371, 669, 216));
				player1Character.setPosition(1020, 385);
			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(2242, 341, 532, 315));
				player1Character.setPosition(970, 385);
			}
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(468, 1677, 449, 389));
				player1Character.setPosition(920, 385);
			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(1403, 1084, 413, 328));
				player1Character.setPosition(870, 385);
			}
			else if (counter == 19)
			{
				player1Character.setTextureRect(sf::IntRect(2284, 1224, 365, 372));
				player1Character.setPosition(820, 385);
			}
			else if (counter == 20)
			{
				player1Character.setTextureRect(sf::IntRect(1392, 572, 243, 390));
				player1Character.setPosition(720, 385);
			}
			else if (counter == 21)
			{
				player1Character.setTextureRect(sf::IntRect(2880, 668, 185, 284));
				player1Character.setPosition(720, 385);
			}
			else if (counter == 22)
			{
				player1Character.setTextureRect(sf::IntRect(2782, 343, 299, 323));
				player1Character.setPosition(650, 385);
			}
			else if (counter == 23)
			{
				player1Character.setTextureRect(sf::IntRect(1915, 1623, 417, 370));
				player1Character.setPosition(600, 385);
			}
			else if (counter == 24)
			{
				player1Character.setTextureRect(sf::IntRect(1910, 1183, 372, 440));
				player1Character.setPosition(570, 385);
			}
			else if (counter == 25)
			{
				player1Character.setTextureRect(sf::IntRect(1611, 1418, 297, 533));
				player1Character.move(0, 0);
			}
			else if (counter == 26)
			{
				player1Character.setTextureRect(sf::IntRect(1281, 1420, 325, 582));
				player1Character.move(0, 0);
			}
			else if (counter == 27)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1156, 330, 589));
				player1Character.move(0, 0);

			}
			else if (counter >= 28)
			{
				counter = 1;
				player1CurrentAnimation = "assassinIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}

	if (player == 2)
	{

		player2Character.setScale(-.8, .8);
		//Caps frame speed
		if (player2PassedTime >= 0.047)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(assassinMove5Texture);

				player2Character.setTextureRect(sf::IntRect(0, 0, 425, 559));
				player2Character.setPosition(1435, 385);//400,300

			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(0, 564, 346, 585));
				player2Character.setPosition(1435, 385);
			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(2511, 673, 360, 547));
				player2Character.setPosition(1335, 415);
			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(2115, 659, 393, 521));
				player2Character.setPosition(1235, 435);
			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(1641, 647, 469, 431));
				player2Character.setPosition(1135, 455);
			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(1690, 272, 549, 369));
				player2Character.setPosition(1035, 475);
			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(349, 964, 545, 327));
				player2Character.setPosition(935, 635);
			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1749, 463, 301));
				player2Character.setPosition(835, 635);
			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(2656, 1226, 395, 287));
				player2Character.setPosition(735, 635);

			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(1108, 260, 581, 308));
				player2Character.setPosition(620, 635);
			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(429, 0, 601, 365));
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(895, 1017, 500, 401));
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(351, 594, 558, 363));
			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(1035, 0, 700, 254));
			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(434, 371, 669, 216));
				player2Character.setPosition(790, 385);
			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(2242, 341, 532, 315));
				player2Character.setPosition(840, 385);
			}
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(468, 1677, 449, 389));
				player2Character.setPosition(890, 385);
			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(1403, 1084, 413, 328));
				player2Character.setPosition(940, 385);
			}
			else if (counter == 19)
			{
				player2Character.setTextureRect(sf::IntRect(2284, 1224, 365, 372));
				player2Character.setPosition(990, 385);
			}
			else if (counter == 20)
			{
				player2Character.setTextureRect(sf::IntRect(1392, 572, 243, 390));
				player2Character.setPosition(1090, 385);
			}
			else if (counter == 21)
			{
				player2Character.setTextureRect(sf::IntRect(2880, 668, 185, 284));
				player2Character.setPosition(1190, 385);
			}
			else if (counter == 22)
			{
				player2Character.setTextureRect(sf::IntRect(2782, 343, 299, 323));
				player2Character.setPosition(1260, 385);
			}
			else if (counter == 23)
			{
				player2Character.setTextureRect(sf::IntRect(1915, 1623, 417, 370));
				player2Character.setPosition(1310, 385);
			}
			else if (counter == 24)
			{
				player2Character.setTextureRect(sf::IntRect(1910, 1183, 372, 440));
				player2Character.setPosition(1340, 385);//1570
			}
			else if (counter == 25)
			{
				player2Character.setTextureRect(sf::IntRect(1611, 1418, 297, 533));
				player2Character.move(0, 0);
			}
			else if (counter == 26)
			{
				player2Character.setTextureRect(sf::IntRect(1281, 1420, 325, 582));
				player2Character.move(0, 0);
			}
			else if (counter == 27)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1156, 330, 589));
				player2Character.move(0, 0);

			}
			else if (counter >= 28)
			{
				counter = 1;
				player2CurrentAnimation = "assassinIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}


}

//dodge
void VisibleObjectManager::assassinMove6(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	if (player == 1)
	{
		player1Character.setScale(.8, .8);

		//Caps frame speed
		if (player1PassedTime >= 0.047)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(assassinMove6Texture);

				player1Character.setTextureRect(sf::IntRect(1528, 0, 469, 578));
				player1Character.move(10, 5);


			}

			else if (counter == 2)
			{
				player1Character.setPosition(490, 385);//(300,330)
				player1Character.setTextureRect(sf::IntRect(1506, 1424, 481, 549));
				player1Character.move(10, 8);

			}
			else if (counter == 3)
			{
				player1Character.setPosition(490, 415);
				player1Character.setTextureRect(sf::IntRect(1522, 587, 475, 513));
				player1Character.move(0, 4);

			}
			else if (counter == 4)
			{
				player1Character.setPosition(490, 435);
				player1Character.setTextureRect(sf::IntRect(0, 1414, 494, 483));
				player1Character.move(0, 11);

			}
			else if (counter == 5)
			{
				player1Character.setPosition(490, 445);
				player1Character.setTextureRect(sf::IntRect(501, 1415, 494, 488));
				player1Character.move(0, -1);
			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(1004, 1425, 494, 491));

			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(1016, 943, 501, 477));
				player1Character.move(0, 8);

			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(0, 942, 506, 466));
				player1Character.move(0, 7);

			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(1020, 0, 501, 466));


			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 508, 468));

			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(511, 0, 505, 468));
			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(0, 470, 505, 468));
			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(511, 470, 499, 468));
			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(1018, 470, 499, 468));
			}
			else if (counter == 15)
			{

				player1Character.setTextureRect(sf::IntRect(511, 941, 499, 468));

			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(511, 941, 499, 468));

			}
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(1018, 470, 499, 468));

			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(511, 470, 499, 468));

			}
			else if (counter == 19)
			{
				player1Character.setTextureRect(sf::IntRect(0, 470, 505, 468));

			}
			else if (counter == 20)
			{
				player1Character.setTextureRect(sf::IntRect(511, 0, 505, 468));

			}
			else if (counter == 21)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 508, 468));

			}
			else if (counter == 22)
			{
				player1Character.setTextureRect(sf::IntRect(1020, 0, 501, 466));

			}
			else if (counter == 23)
			{
				player1Character.setTextureRect(sf::IntRect(0, 942, 506, 466));

			}
			else if (counter == 24)
			{
				player1Character.setTextureRect(sf::IntRect(1016, 943, 501, 477));
				player1Character.move(0, -8);
			}
			else if (counter == 25)
			{
				player1Character.setTextureRect(sf::IntRect(1004, 1425, 494, 491));
				player1Character.move(0, -8);
			}
			else if (counter == 26)
			{
				player1Character.setPosition(490, 445);
				player1Character.setTextureRect(sf::IntRect(501, 1415, 494, 488));
			}
			else if (counter == 27)
			{
				player1Character.setPosition(490, 448);
				player1Character.setTextureRect(sf::IntRect(0, 1414, 494, 483));

			}
			else if (counter == 28)
			{
				player1Character.setPosition(490, 410);
				player1Character.setTextureRect(sf::IntRect(1522, 587, 475, 513));
				player1Character.move(5, 12);
			}

			else if (counter == 29)
			{
				player1Character.setPosition(500, 395);
				player1Character.setTextureRect(sf::IntRect(1506, 1424, 481, 549));

			}

			else if (counter == 30)
			{
				player1Character.setTextureRect(sf::IntRect(1528, 0, 469, 578));
				player1Character.move(20, -20);
			}

			else if (counter >= 31)
			{
				player1Character.setPosition(515, 372);
				counter = 1;
				player1CurrentAnimation = "assassinIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}


	if (player == 2)
	{
		player2Character.setScale(-.8, .8);

		//Caps frame speed
		if (player2PassedTime >= 0.047)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(assassinMove6Texture);

				player2Character.setTextureRect(sf::IntRect(1528, 0, 469, 578));
				player2Character.move(-10, 5);


			}

			else if (counter == 2)
			{
				player2Character.setPosition(1405, 385);//(300,330)
				player2Character.setTextureRect(sf::IntRect(1506, 1424, 481, 549));
				player2Character.move(-10, 8);

			}
			else if (counter == 3)
			{
				player2Character.setPosition(1405, 415);
				player2Character.setTextureRect(sf::IntRect(1522, 587, 475, 513));
				player2Character.move(0, 4);

			}
			else if (counter == 4)
			{
				player2Character.setPosition(1405, 435);
				player2Character.setTextureRect(sf::IntRect(0, 1414, 494, 483));
				player2Character.move(0, 11);

			}
			else if (counter == 5)
			{
				player2Character.setPosition(1405, 445);
				player2Character.setTextureRect(sf::IntRect(501, 1415, 494, 488));
				player2Character.move(0, -1);
			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(1004, 1425, 494, 491));

			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(1016, 943, 501, 477));
				player2Character.move(0, 8);

			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(0, 942, 506, 466));
				player2Character.move(0, 7);

			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(1020, 0, 501, 466));


			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 508, 468));

			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(511, 0, 505, 468));
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(0, 470, 505, 468));
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(511, 470, 499, 468));
			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(1018, 470, 499, 468));
			}
			else if (counter == 15)
			{

				player2Character.setTextureRect(sf::IntRect(511, 941, 499, 468));

			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(511, 941, 499, 468));

			}
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(1018, 470, 499, 468));

			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(511, 470, 499, 468));

			}
			else if (counter == 19)
			{
				player2Character.setTextureRect(sf::IntRect(0, 470, 505, 468));

			}
			else if (counter == 20)
			{
				player2Character.setTextureRect(sf::IntRect(511, 0, 505, 468));

			}
			else if (counter == 21)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 508, 468));

			}
			else if (counter == 22)
			{
				player2Character.setTextureRect(sf::IntRect(1020, 0, 501, 466));

			}
			else if (counter == 23)
			{
				player2Character.setTextureRect(sf::IntRect(0, 942, 506, 466));

			}
			else if (counter == 24)
			{
				player2Character.setTextureRect(sf::IntRect(1016, 943, 501, 477));
				player2Character.move(0, -8);
			}
			else if (counter == 25)
			{
				player2Character.setTextureRect(sf::IntRect(1004, 1425, 494, 491));
				player2Character.move(0, -8);
			}
			else if (counter == 26)
			{
				player2Character.setPosition(1405, 445);
				player2Character.setTextureRect(sf::IntRect(501, 1415, 494, 488));
			}
			else if (counter == 27)
			{
				player2Character.setPosition(1405, 448);
				player2Character.setTextureRect(sf::IntRect(0, 1414, 494, 483));

			}
			else if (counter == 28)
			{
				player2Character.setPosition(1405, 410);
				player2Character.setTextureRect(sf::IntRect(1522, 587, 475, 513));
				player2Character.move(5, 12);
			}

			else if (counter == 29)
			{
				player2Character.setPosition(1415, 395);
				player2Character.setTextureRect(sf::IntRect(1506, 1424, 481, 549));

			}

			else if (counter == 30)
			{
				player2Character.setTextureRect(sf::IntRect(1528, 0, 469, 578));
				player2Character.move(-20, -20);
			}

			else if (counter >= 31)
			{
				player2Character.setPosition(1390, 372);
				counter = 1;
				player2CurrentAnimation = "assassinIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}




}

//leg slice
void VisibleObjectManager::assassinMove7(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());



	sf::Vector2f vec1;
	vec1.x = 360;
	vec1.y = 405;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 360;
	vec1Player2.y = 405;

	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1323;
	vec2Player2.y = 550;


	if (player == 1)
	{

		player1Character.setScale(.8, .8);
		//Caps frame speed
		if (player1PassedTime >= 0.015)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTexture(assassinMove7Texture);

				player1Character.setTextureRect(sf::IntRect(1123, 1089, 418, 592));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(10, 0);

			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(1554, 1341, 434, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(20, 0);
			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(1544, 757, 456, 581));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(30, 0);
			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(1065, 1685, 486, 578));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(40, 0);
			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(0, 2186, 523, 576));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(50, 0);
			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1614, 557, 568));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(60, 0);
			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1056, 596, 554));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(70, 0);

			}
			else if (counter == 8)
			{

				player1Character.setTextureRect(sf::IntRect(0, 517, 627, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(80, 0);

			}
			else if (counter == 9)
			{

				player1Character.setTextureRect(sf::IntRect(0, 0, 657, 511));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(90, 0);
			}
			else if (counter == 10)
			{
				player1Character.setPosition(340, 470);
				player1Character.setTextureRect(sf::IntRect(661, 0, 679, 479));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(100, 0);

			}
			else if (counter == 11)
			{
				player1Character.setPosition(370, 500);
				player1Character.setTextureRect(sf::IntRect(1345, 0, 698, 440));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(110, 0);
			}
			else if (counter == 12)
			{
				player1Character.setPosition(390, 530);
				player1Character.setTextureRect(sf::IntRect(2047, 0, 713, 392));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(120, 0);
			}
			else if (counter == 13)
			{
				player1Character.setPosition(410, 560);
				player1Character.setTextureRect(sf::IntRect(2763, 0, 717, 342));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(130, 0);
			}
			else if (counter == 14)
			{
				player1Character.setPosition(430, 580);
				player1Character.setTextureRect(sf::IntRect(2764, 346, 714, 324));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(140, 0);
			}
			else if (counter == 15)
			{
				player1Character.setPosition(450, 600);
				player1Character.setTextureRect(sf::IntRect(2047, 397, 709, 315));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(150, 0);
			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(1342, 443, 696, 312));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(160, 0);
			}
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(2039, 717, 668, 307));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(170, 0);
			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(2711, 978, 638, 303));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(180, 0);
			}
			else if (counter == 19)
			{
				player1Character.setTextureRect(sf::IntRect(3445, 710, 597, 303));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(190, 0);
			}
			else if (counter == 20)
			{
				player1Character.setTextureRect(sf::IntRect(2521, 2495, 516, 303));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(200, 0);
			}
			//Moment of strike
			else if (counter == 21)
			{
				player1Character.setTextureRect(sf::IntRect(1452, 2495, 516, 301));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(200, 0);
			}
			else if (counter == 22)
			{
				player1Character.setTextureRect(sf::IntRect(3041, 2492, 513, 306));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(200, 0);
			}
			else if (counter == 23)
			{
				player1Character.setTextureRect(sf::IntRect(3556, 2221, 502, 301));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(200, 0);
			}
			else if (counter == 24)
			{
				player1Character.setTextureRect(sf::IntRect(1977, 2497, 538, 301));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(200, 0);
			}
			else if (counter == 25)
			{
				player1Character.setTextureRect(sf::IntRect(3245, 1924, 575, 295));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				player1Character.setTextureRect(sf::IntRect(664, 478, 651, 301));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				player1Character.setTextureRect(sf::IntRect(2744, 673, 698, 302));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

			}
			else if (counter == 28)
			{
				player1Character.setTextureRect(sf::IntRect(632, 782, 645, 305));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 29)
			{
				player1Character.setTextureRect(sf::IntRect(2005, 1027, 638, 318));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 30)
			{
				player1Character.setPosition(500, 500);
				player1Character.setTextureRect(sf::IntRect(3352, 1014, 628, 334));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 31)
			{
				player1Character.setPosition(500, 480);
				player1Character.setTextureRect(sf::IntRect(3486, 0, 537, 403));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				player1Character.setPosition(480, 460);
				player1Character.setTextureRect(sf::IntRect(1553, 1926, 433, 471));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				player1Character.setPosition(460, 440);
				player1Character.setTextureRect(sf::IntRect(1017, 2267, 431, 521));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				player1Character.setPosition(440, 420);
				player1Character.setTextureRect(sf::IntRect(561, 1654, 500, 552));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 35)
			{
				player1Character.setPosition(420, 400);
				player1Character.setTextureRect(sf::IntRect(596, 1090, 524, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 36)
			{
				player1Character.setPosition(410, 380);
				player1Character.setTextureRect(sf::IntRect(525, 2207, 491, 566));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 37)
			{
				player1Character.setPosition(400, 360);
				player1Character.setTextureRect(sf::IntRect(2849, 1287, 415, 568));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 38)
			{
				player1Character.setPosition(380, 340);
				player1Character.setTextureRect(sf::IntRect(2847, 1921, 394, 567));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 39)
			{
				player1Character.setTextureRect(sf::IntRect(3270, 1350, 413, 567));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(20, 2);
			}
			else if (counter == 40)
			{
				player1Character.setTextureRect(sf::IntRect(2419, 1924, 425, 567));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(20, 2);
			}
			else if (counter == 41)
			{
				player1Character.setTextureRect(sf::IntRect(1989, 1349, 426, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(20, 2);
			}
			else if (counter == 42)
			{
				player1Character.setPosition(300, 300);
				player1Character.setTextureRect(sf::IntRect(2421, 1351, 426, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(20, 2);
			}
			else if (counter == 43)
			{
				player1Character.setTextureRect(sf::IntRect(1989, 1923, 426, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				player1Character.move(30, 2);
			}
			else if (counter >= 44)
			{
				player1Character.move(10, 2);
				counter = 1;
				player1CurrentAnimation = "assassinIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}

	if (player == 2)
	{

		player2Character.setScale(-.8, .8);
		//Caps frame speed
		if (player2PassedTime >= 0.015)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTexture(assassinMove7Texture);

				player2Character.setTextureRect(sf::IntRect(1123, 1089, 418, 592));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-10, 0);

			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(1554, 1341, 434, 582));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-20, 0);
			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(1544, 757, 456, 581));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-30, 0);
			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(1065, 1685, 486, 578));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-40, 0);
			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(0, 2186, 523, 576));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-50, 0);
			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1614, 557, 568));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-60, 0);
			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1056, 596, 554));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-70, 0);

			}
			else if (counter == 8)
			{

				player2Character.setTextureRect(sf::IntRect(0, 517, 627, 534));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-80, 0);

			}
			else if (counter == 9)
			{

				player2Character.setTextureRect(sf::IntRect(0, 0, 657, 511));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-90, 0);
			}
			else if (counter == 10)
			{
				player2Character.setPosition(340, 470);
				player2Character.setTextureRect(sf::IntRect(661, 0, 679, 479));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-100, 0);

			}
			else if (counter == 11)
			{
				player2Character.setPosition(370, 500);
				player2Character.setTextureRect(sf::IntRect(1345, 0, 698, 440));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-110, 0);
			}
			else if (counter == 12)
			{
				player2Character.setPosition(390, 530);
				player2Character.setTextureRect(sf::IntRect(2047, 0, 713, 392));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-120, 0);
			}
			else if (counter == 13)
			{
				player2Character.setPosition(410, 560);
				player2Character.setTextureRect(sf::IntRect(2763, 0, 717, 342));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-130, 0);
			}
			else if (counter == 14)
			{
				player2Character.setPosition(430, 580);
				player2Character.setTextureRect(sf::IntRect(2764, 346, 714, 324));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-140, 0);
			}
			else if (counter == 15)
			{
				player2Character.setPosition(450, 600);
				player2Character.setTextureRect(sf::IntRect(2047, 397, 709, 315));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-150, 0);
			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(1342, 443, 696, 312));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-160, 0);
			}
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(2039, 717, 668, 307));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-170, 0);
			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(2711, 978, 638, 303));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-180, 0);
			}
			else if (counter == 19)
			{
				player2Character.setTextureRect(sf::IntRect(3445, 710, 597, 303));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-190, 0);
			}
			else if (counter == 20)
			{
				player2Character.setTextureRect(sf::IntRect(2521, 2495, 516, 303));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-200, 0);
			}
			//Mmoment of strike
			else if (counter == 21)
			{
				player2Character.setTextureRect(sf::IntRect(1452, 2495, 516, 301));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-200, 0);
			}
			else if (counter == 22)
			{
				player2Character.setTextureRect(sf::IntRect(3041, 2492, 513, 306));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-200, 0);
			}
			else if (counter == 23)
			{
				player2Character.setTextureRect(sf::IntRect(3556, 2221, 502, 301));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-200, 0);
			}
			else if (counter == 24)
			{
				player2Character.setTextureRect(sf::IntRect(1977, 2497, 538, 301));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-200, 0);
			}
			else if (counter == 25)
			{
				player2Character.setTextureRect(sf::IntRect(3245, 1924, 575, 295));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				player2Character.setTextureRect(sf::IntRect(664, 478, 651, 301));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				player2Character.setTextureRect(sf::IntRect(2744, 673, 698, 302));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter == 28)
			{
				player2Character.setTextureRect(sf::IntRect(632, 782, 645, 305));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 29)
			{
				player2Character.setTextureRect(sf::IntRect(2005, 1027, 638, 318));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 30)
			{
				player2Character.setPosition(500, 500);
				player2Character.setTextureRect(sf::IntRect(3352, 1014, 628, 334));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 31)
			{
				player2Character.setPosition(500, 480);
				player2Character.setTextureRect(sf::IntRect(3486, 0, 537, 403));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				player2Character.setPosition(480, 460);
				player2Character.setTextureRect(sf::IntRect(1553, 1926, 433, 471));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				player2Character.setPosition(460, 440);
				player2Character.setTextureRect(sf::IntRect(1017, 2267, 431, 521));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				player2Character.setPosition(440, 420);
				player2Character.setTextureRect(sf::IntRect(561, 1654, 500, 552));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 35)
			{
				player2Character.setPosition(420, 400);
				player2Character.setTextureRect(sf::IntRect(596, 1090, 524, 562));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 36)
			{
				player2Character.setPosition(410, 380);
				player2Character.setTextureRect(sf::IntRect(525, 2207, 491, 566));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 37)
			{
				player2Character.setPosition(400, 360);
				player2Character.setTextureRect(sf::IntRect(2849, 1287, 415, 568));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 38)
			{
				player2Character.setPosition(380, 340);
				player2Character.setTextureRect(sf::IntRect(2847, 1921, 394, 567));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 39)
			{
				player2Character.setTextureRect(sf::IntRect(3270, 1350, 413, 567));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-20, 2);
			}
			else if (counter == 40)
			{
				player2Character.setTextureRect(sf::IntRect(2419, 1924, 425, 567));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-20, 2);
			}
			else if (counter == 41)
			{
				player2Character.setTextureRect(sf::IntRect(1989, 1349, 426, 569));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-20, 2);
			}
			else if (counter == 42)
			{
				player2Character.setPosition(300, 300);
				player2Character.setTextureRect(sf::IntRect(2421, 1351, 426, 569));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-20, 2);
			}
			else if (counter == 43)
			{
				player2Character.setTextureRect(sf::IntRect(1989, 1923, 426, 569));
				player2Character.setPosition(adjustPositionPlayer2(vec1Player2, player2Character, vec2Player2));
				player2Character.move(-30, 2);
			}
			else if (counter >= 44)
			{
				player2Character.move(-10, 2);
				counter = 1;
				player2CurrentAnimation = "assassinIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}

}

//disarm
void VisibleObjectManager::assassinMove8(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	if (player == 1)
	{

		player1Character.setScale(.8, .8);
		//Caps frame speed
		if (player1PassedTime >= 0.02)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player1Character.setTexture(assassinMove8Texture);

				player1Character.setTextureRect(sf::IntRect(0, 1144, 408, 581));


			}

			else if (counter == 2)
			{
				player1Character.setTextureRect(sf::IntRect(381, 1738, 401, 588));

			}
			else if (counter == 3)
			{
				player1Character.setTextureRect(sf::IntRect(1546, 1755, 393, 585));

			}
			else if (counter == 4)
			{
				player1Character.setTextureRect(sf::IntRect(1165, 1748, 376, 590));

			}
			else if (counter == 5)
			{
				player1Character.setTextureRect(sf::IntRect(787, 1745, 371, 585));

			}
			else if (counter == 6)
			{
				player1Character.setTextureRect(sf::IntRect(0, 1735, 371, 580));

			}
			else if (counter == 7)
			{
				player1Character.setTextureRect(sf::IntRect(1258, 574, 397, 575));

			}
			else if (counter == 8)
			{
				player1Character.setTextureRect(sf::IntRect(431, 570, 421, 570));

			}
			else if (counter == 9)
			{
				player1Character.setTextureRect(sf::IntRect(2, 568, 425, 570));


			}
			else if (counter == 10)
			{
				player1Character.setTextureRect(sf::IntRect(1358, 0, 413, 566));
				player1Character.move(10, 0);

			}
			else if (counter == 11)
			{
				player1Character.setTextureRect(sf::IntRect(935, 0, 419, 566));
				player1Character.move(10, 0);
			}
			else if (counter == 12)
			{
				player1Character.setTextureRect(sf::IntRect(471, 0, 459, 566));
				player1Character.move(10, 0);
			}
			else if (counter == 13)
			{
				player1Character.setTextureRect(sf::IntRect(1328, 1161, 489, 584));
				player1Character.move(10, 0);
			}
			else if (counter == 14)
			{
				player1Character.setTextureRect(sf::IntRect(1352, 2346, 482, 609));
				player1Character.move(10, 0);
			}
			else if (counter == 15)
			{
				player1Character.setTextureRect(sf::IntRect(828, 1157, 498, 580));
				player1Character.move(50, 0);
			}
			else if (counter == 16)
			{
				player1Character.setTextureRect(sf::IntRect(0, 0, 465, 563));
				player1Character.move(50, 0);
			}
			//apex
			else if (counter == 17)
			{
				player1Character.setTextureRect(sf::IntRect(857, 572, 398, 579));
				player1Character.move(50, 0);
			}
			else if (counter == 18)
			{
				player1Character.setTextureRect(sf::IntRect(410, 1149, 414, 587));

			}
			else if (counter == 19)
			{
				player1Character.move(-50, 0);
				player1Character.setTextureRect(sf::IntRect(1, 2338, 456, 590));

			}
			else if (counter == 20)
			{
				player1Character.move(-50, 0);
				player1Character.setTextureRect(sf::IntRect(458, 2339, 456, 597));

			}
			else if (counter == 21)
			{
				player1Character.move(-50, 0);
				player1Character.setTextureRect(sf::IntRect(915, 2350, 433, 597));

			}
			else if (counter >= 22)
			{
				player1Character.move(-50, 0);
				counter = 1;
				player1CurrentAnimation = "assassinIdle";
				player1MoveFinished = true;
			}

			player1Clock.restart();
			counter++;

		}
	}


	if (player == 2)
	{

		player2Character.setScale(-.8, .8);
		//Caps frame speed
		if (player2PassedTime >= 0.02)
		{

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(assassinMove8Texture);

				player2Character.setTextureRect(sf::IntRect(0, 1144, 408, 581));


			}

			else if (counter == 2)
			{
				player2Character.setTextureRect(sf::IntRect(381, 1738, 401, 588));

			}
			else if (counter == 3)
			{
				player2Character.setTextureRect(sf::IntRect(1546, 1755, 393, 585));

			}
			else if (counter == 4)
			{
				player2Character.setTextureRect(sf::IntRect(1165, 1748, 376, 590));

			}
			else if (counter == 5)
			{
				player2Character.setTextureRect(sf::IntRect(787, 1745, 371, 585));

			}
			else if (counter == 6)
			{
				player2Character.setTextureRect(sf::IntRect(0, 1735, 371, 580));

			}
			else if (counter == 7)
			{
				player2Character.setTextureRect(sf::IntRect(1258, 574, 397, 575));

			}
			else if (counter == 8)
			{
				player2Character.setTextureRect(sf::IntRect(431, 570, 421, 570));

			}
			else if (counter == 9)
			{
				player2Character.setTextureRect(sf::IntRect(2, 568, 425, 570));


			}
			else if (counter == 10)
			{
				player2Character.setTextureRect(sf::IntRect(1358, 0, 413, 566));
				player2Character.move(-10, 0);

			}
			else if (counter == 11)
			{
				player2Character.setTextureRect(sf::IntRect(935, 0, 419, 566));
				player2Character.move(-10, 0);
			}
			else if (counter == 12)
			{
				player2Character.setTextureRect(sf::IntRect(471, 0, 459, 566));
				player2Character.move(-10, 0);
			}
			else if (counter == 13)
			{
				player2Character.setTextureRect(sf::IntRect(1328, 1161, 489, 584));
				player2Character.move(-10, 0);
			}
			else if (counter == 14)
			{
				player2Character.setTextureRect(sf::IntRect(1352, 2346, 482, 609));
				player2Character.move(-10, 0);
			}
			else if (counter == 15)
			{
				player2Character.setTextureRect(sf::IntRect(828, 1157, 498, 580));
				player2Character.move(-50, 0);
			}
			else if (counter == 16)
			{
				player2Character.setTextureRect(sf::IntRect(0, 0, 465, 563));
				player2Character.move(-50, 0);
			}
			//apex
			else if (counter == 17)
			{
				player2Character.setTextureRect(sf::IntRect(857, 572, 398, 579));
				player2Character.move(-50, 0);
			}
			else if (counter == 18)
			{
				player2Character.setTextureRect(sf::IntRect(410, 1149, 414, 587));

			}
			else if (counter == 19)
			{
				player2Character.move(50, 0);
				player2Character.setTextureRect(sf::IntRect(1, 2338, 456, 590));

			}
			else if (counter == 20)
			{
				player2Character.move(50, 0);
				player2Character.setTextureRect(sf::IntRect(458, 2339, 456, 597));

			}
			else if (counter == 21)
			{
				player2Character.move(50, 0);
				player2Character.setTextureRect(sf::IntRect(915, 2350, 433, 597));

			}
			else if (counter >= 22)
			{
				player2Character.move(50, 0);
				counter = 1;
				player2CurrentAnimation = "assassinIdle";
				player2MoveFinished = true;
			}

			player2Clock.restart();
			counter++;

		}
	}


}

//animation to play when assassin gets hit out of a move
void VisibleObjectManager::assassinHit(int &counter, int player)
{

}

//stance when she dodges sucessfully
void VisibleObjectManager::assassinBackStance(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;
}


//necromancer animations
void VisibleObjectManager::necromancerIdle(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());



	//Caps frame speed
	if (player1PassedTime >= 0.14)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(necromancerIdleTexture);
			player1Character.setTextureRect(sf::IntRect(3269, 1141, 535, 562));
			player1Character.setPosition(300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3269, 1141, 535, 562));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2723, 3, 533, 561));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2186, 4, 533, 563));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(543, 1146, 540, 561));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2181, 1144, 542, 563));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1099, 0, 544, 567));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(549, 574, 546, 565));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 575, 546, 565));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1644, 573, 542, 566));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2186, 572, 542, 566));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2733, 570, 541, 566));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2725, 1142, 541, 566));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1097, 572, 543, 566));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 4, 547, 565));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(550, 0, 545, 568));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1087, 1144, 543, 563));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1635, 1145, 541, 563));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1146, 541, 562));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1645, 4, 536, 562));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3260, 3, 533, 562));
			}

			else if (counter > 20)
			{
				counter = 1;
			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.14)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(necromancerIdleTexture);
			player2Character.setTextureRect(sf::IntRect(3269, 1141, 535, 562));
			player2Character.setPosition(1600, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3269, 1141, 535, 562));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2723, 3, 533, 561));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2186, 4, 533, 563));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(543, 1146, 540, 561));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2181, 1144, 542, 563));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1099, 0, 544, 567));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(549, 574, 546, 565));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 575, 546, 565));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1644, 573, 542, 566));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2186, 572, 542, 566));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2733, 570, 541, 566));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2725, 1142, 541, 566));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1097, 572, 543, 566));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 4, 547, 565));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(550, 0, 545, 568));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1087, 1144, 543, 563));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1635, 1145, 541, 563));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1146, 541, 562));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1645, 4, 536, 562));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3260, 3, 533, 562));
			}

			else if (counter > 20)
			{
				counter = 1;
			}
			player2Clock.restart();
			counter++;
		}
	}

}

//soul swipe
void VisibleObjectManager::necromancerMove1(int &counter, int player)

{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.02)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(necromancerMove1Texture);
			player1Character.setTextureRect(sf::IntRect(1066, 1031, 536, 562));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1066, 1031, 536, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3420, 533, 546, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1006, 555, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1774, 472, 555, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2338, 473, 539, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(558, 1011, 507, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2724, 1037, 455, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3182, 1096, 451, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(6, 1566, 427, 622));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1518, 1598, 396, 673));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3184, 1661, 342, 707));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(6, 2194, 355, 725));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(788, 2252, 391, 738));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1646, 2287, 412, 738));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(371, 2209, 407, 732));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3535, 1816, 381, 721));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3635, 1095, 333, 718));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2854, 1602, 308, 718));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2429, 2305, 308, 769));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2724, 2324, 289, 788));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3049, 2374, 291, 795));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2059, 2305, 366, 756));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2380, 1605, 466, 696));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(433, 1576, 528, 632));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(966, 1596, 546, 652));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}


			//coordinates not done yet
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1197, 2274, 442, 734));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1918, 1598, 461, 690));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(561, 468, 654, 537));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 614, 445));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(616, 0, 560, 469));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1179, 0, 560, 469));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1741, 0, 560, 469));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2302, 0, 560, 469));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2861, 0, 560, 469));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3419, 0, 560, 469));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 466, 558, 554));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2140, 1034, 582, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1217, 473, 558, 554));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 39)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2878, 473, 541, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 39)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "necroIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.02)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(necromancerMove1Texture);
			player2Character.setTextureRect(sf::IntRect(1066, 1031, 536, 562));
			player2Character.setPosition(1600, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1066, 1031, 536, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3420, 533, 546, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1006, 555, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1774, 472, 555, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2338, 473, 539, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(558, 1011, 507, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2724, 1037, 455, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3182, 1096, 451, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(6, 1566, 427, 622));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1518, 1598, 396, 673));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3184, 1661, 342, 707));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(6, 2194, 355, 725));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(788, 2252, 391, 738));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1646, 2287, 412, 738));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(371, 2209, 407, 732));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3535, 1816, 381, 721));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3635, 1095, 333, 718));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2854, 1602, 308, 718));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2429, 2305, 308, 769));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2724, 2324, 289, 788));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3049, 2374, 291, 795));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2059, 2305, 366, 756));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2380, 1605, 466, 696));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(433, 1576, 528, 632));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(966, 1596, 546, 652));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}


			//coordinates not done yet
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1197, 2274, 442, 734));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1918, 1598, 461, 690));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(561, 468, 654, 537));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 614, 445));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(616, 0, 560, 469));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1179, 0, 560, 469));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1741, 0, 560, 469));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2302, 0, 560, 469));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2861, 0, 560, 469));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3419, 0, 560, 469));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 466, 558, 554));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2140, 1034, 582, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1217, 473, 558, 554));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 39)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2878, 473, 541, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 39)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "necroIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//corpse pile
void VisibleObjectManager::necromancerMove2(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.05)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(necromancerMove2Texture);
			player1Character.setTextureRect(sf::IntRect(0, 2122, 541, 562));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 2122, 541, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(436, 780, 550, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1, 1563, 556, 555));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(543, 2122, 541, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(559, 1343, 497, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(984, 762, 422, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1415, 1439, 315, 613));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1732, 1356, 281, 645));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1733, 692, 280, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1676, 2052, 284, 670));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1388, 2059, 288, 673));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1089, 2057, 292, 678));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1626, 1, 298, 684));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1426, 733, 302, 703));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1063, 1325, 350, 729));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(442, 0, 402, 752));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(7, 0, 428, 774));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 780, 434, 774));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(847, 0, 407, 753));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1254, 0, 367, 727));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(847, 0, 407, 753));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 780, 434, 774));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(7, 0, 428, 774));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(442, 0, 402, 752));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1063, 1325, 350, 729));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1426, 733, 302, 703));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1626, 1, 298, 684));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1089, 2057, 292, 678));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1388, 2059, 288, 673));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1676, 2052, 284, 670));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1733, 692, 280, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1732, 1356, 281, 645));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1415, 1439, 315, 613));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(984, 762, 422, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(559, 1343, 497, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(543, 2122, 541, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1, 1563, 556, 555));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(436, 780, 550, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 39)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 2122, 541, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 39)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "necroIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.05)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(necromancerMove2Texture);
			player2Character.setTextureRect(sf::IntRect(0, 2122, 541, 562));
			player2Character.setPosition(1600, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 2122, 541, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(436, 780, 550, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1, 1563, 556, 555));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(543, 2122, 541, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(559, 1343, 497, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(984, 762, 422, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1415, 1439, 315, 613));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1732, 1356, 281, 645));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1733, 692, 280, 657));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1676, 2052, 284, 670));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1388, 2059, 288, 673));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1089, 2057, 292, 678));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1626, 1, 298, 684));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1426, 733, 302, 703));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1063, 1325, 350, 729));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(442, 0, 402, 752));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(7, 0, 428, 774));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 780, 434, 774));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(847, 0, 407, 753));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1254, 0, 367, 727));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(847, 0, 407, 753));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 780, 434, 774));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(7, 0, 428, 774));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(442, 0, 402, 752));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1063, 1325, 350, 729));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1426, 733, 302, 703));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1626, 1, 298, 684));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1089, 2057, 292, 678));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1388, 2059, 288, 673));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1676, 2052, 284, 670));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1733, 692, 280, 657));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1732, 1356, 281, 645));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1415, 1439, 315, 613));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(984, 762, 422, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(559, 1343, 497, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(543, 2122, 541, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1, 1563, 556, 555));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(436, 780, 550, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 39)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 2122, 541, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 39)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "necroIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//soul harvest
void VisibleObjectManager::necromancerMove3(int &counter, int player)

{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.07)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(necromancerMove3Texture);
			player1Character.setTextureRect(sf::IntRect(0, 784, 554, 559));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 784, 554, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(437, 0, 496, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1132, 1529, 289, 633));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1484, 1488, 286, 666));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(844, 1490, 286, 679));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(563, 562, 347, 729));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3, 0, 432, 779));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(935, 0, 370, 729));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(561, 1296, 271, 786));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 2124, 276, 695));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(525, 2086, 283, 687));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1202, 779, 278, 747));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1304, 0, 278, 776));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1586, 0, 292, 756));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1586, 757, 292, 729));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(915, 731, 286, 756));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1, 1346, 281, 773));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(281, 1348, 269, 723));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1424, 2158, 257, 678));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1130, 2164, 251, 702));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(281, 2074, 242, 718));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1130, 2164, 251, 702));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1424, 2158, 257, 678));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(281, 1348, 269, 723));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1, 1346, 281, 773));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(915, 731, 286, 756));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1586, 757, 292, 729));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1586, 0, 292, 756));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1304, 0, 278, 776));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1202, 779, 278, 747));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(525, 2086, 283, 687));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 2124, 276, 695));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(561, 1296, 271, 786));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(935, 0, 370, 729));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3, 0, 432, 779));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(563, 562, 347, 729));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(844, 1490, 286, 679));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1484, 1488, 286, 666));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 39)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1132, 1529, 289, 633));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 40)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(437, 0, 496, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 41)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 784, 554, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 41)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "necroIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.07)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(necromancerMove3Texture);
			player2Character.setTextureRect(sf::IntRect(0, 784, 554, 559));
			player2Character.setPosition(1600, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 784, 554, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(437, 0, 496, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1132, 1529, 289, 633));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1484, 1488, 286, 666));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(844, 1490, 286, 679));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(563, 562, 347, 729));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3, 0, 432, 779));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(935, 0, 370, 729));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(561, 1296, 271, 786));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 2124, 276, 695));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(525, 2086, 283, 687));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1202, 779, 278, 747));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1304, 0, 278, 776));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1586, 0, 292, 756));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1586, 757, 292, 729));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(915, 731, 286, 756));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1, 1346, 281, 773));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(281, 1348, 269, 723));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1424, 2158, 257, 678));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1130, 2164, 251, 702));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(281, 2074, 242, 718));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1130, 2164, 251, 702));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1424, 2158, 257, 678));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(281, 1348, 269, 723));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1, 1346, 281, 773));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(915, 731, 286, 756));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1586, 757, 292, 729));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1586, 0, 292, 756));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1304, 0, 278, 776));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1202, 779, 278, 747));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(525, 2086, 283, 687));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 2124, 276, 695));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(561, 1296, 271, 786));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(935, 0, 370, 729));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3, 0, 432, 779));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(563, 562, 347, 729));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(844, 1490, 286, 679));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1484, 1488, 286, 666));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 39)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1132, 1529, 289, 633));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 40)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(437, 0, 496, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 41)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 784, 554, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 41)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "necroIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//bone wall
void VisibleObjectManager::necromancerMove4(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.05)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(necromancerMove4Texture);
			player1Character.setTextureRect(sf::IntRect(0, 864, 548, 556));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 864, 548, 556));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(550, 857, 538, 556));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2334, 818, 421, 552));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3619, 0, 331, 614));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2754, 801, 338, 660));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3281, 0, 339, 659));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1512, 840, 381, 646));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1088, 850, 423, 661));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1892, 830, 442, 703));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3094, 781, 426, 756));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2862, 0, 417, 778));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2441, 0, 417, 791));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2030, 0, 411, 807));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1621, 0, 406, 822));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1213, 0, 406, 833));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(810, 0, 402, 842));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(406, 0, 402, 851));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 402, 857));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}


			//apex////////
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3520, 663, 402, 857));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}



			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 402, 857));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(406, 0, 402, 851));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(810, 0, 402, 842));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1213, 0, 406, 833));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1621, 0, 406, 822));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2030, 0, 411, 807));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2441, 0, 417, 791));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2862, 0, 417, 778));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3094, 781, 426, 756));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1892, 830, 442, 703));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1088, 850, 423, 661));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1512, 840, 381, 646));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3281, 0, 339, 659));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3281, 0, 339, 659));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2754, 801, 338, 660));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3619, 0, 331, 614));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2334, 818, 421, 552));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(550, 857, 538, 556));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 37)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "necroIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.05)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(necromancerMove4Texture);
			player2Character.setTextureRect(sf::IntRect(0, 864, 548, 556));
			player2Character.setPosition(1600, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 864, 548, 556));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(550, 857, 538, 556));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2334, 818, 421, 552));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3619, 0, 331, 614));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2754, 801, 338, 660));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3281, 0, 339, 659));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1512, 840, 381, 646));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1088, 850, 423, 661));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1892, 830, 442, 703));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3094, 781, 426, 756));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2862, 0, 417, 778));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2441, 0, 417, 791));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2030, 0, 411, 807));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1621, 0, 406, 822));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1213, 0, 406, 833));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(810, 0, 402, 842));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(406, 0, 402, 851));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 402, 857));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}


			//apex////////
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3520, 663, 402, 857));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}



			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 402, 857));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(406, 0, 402, 851));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(810, 0, 402, 842));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1213, 0, 406, 833));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1621, 0, 406, 822));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2030, 0, 411, 807));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2441, 0, 417, 791));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2862, 0, 417, 778));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3094, 781, 426, 756));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1892, 830, 442, 703));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1088, 850, 423, 661));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1512, 840, 381, 646));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3281, 0, 339, 659));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3281, 0, 339, 659));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2754, 801, 338, 660));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3619, 0, 331, 614));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2334, 818, 421, 552));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(550, 857, 538, 556));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 37)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "necroIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//soul blast
void VisibleObjectManager::necromancerMove5(int &counter, int player)

{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.05)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(necromancerMove5Texture);
			player1Character.setTextureRect(sf::IntRect(0, 1136, 548, 562));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1136, 548, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1490, 1133, 580, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3313, 1130, 596, 553));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3341, 1690, 568, 553));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1500, 1696, 497, 550));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(709, 1700, 393, 541));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1103, 1700, 394, 544));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1, 1702, 355, 536));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(358, 1702, 349, 535));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1999, 1698, 351, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2975, 1695, 363, 526));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2353, 1696, 619, 548));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1508, 568, 506, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2015, 566, 441, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2438, 0, 441, 561));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1984, 0, 452, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1532, 0, 452, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2071, 1131, 438, 558));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2880, 0, 414, 561));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2896, 567, 411, 561));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2928, 1130, 384, 556));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3307, 567, 377, 558));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3298, 0, 389, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2513, 1131, 413, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2458, 568, 438, 557));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1048, 568, 457, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1027, 1137, 461, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(551, 1136, 474, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1043, 0, 488, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(534, 0, 507, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(530, 569, 517, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 570, 529, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 531, 566));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter >= 33)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "necroIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.05)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(necromancerMove5Texture);
			player2Character.setTextureRect(sf::IntRect(0, 1136, 548, 562));
			player2Character.setPosition(1600, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1136, 548, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1490, 1133, 580, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3313, 1130, 596, 553));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3341, 1690, 568, 553));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1500, 1696, 497, 550));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(709, 1700, 393, 541));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1103, 1700, 394, 544));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1, 1702, 355, 536));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(358, 1702, 349, 535));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1999, 1698, 351, 527));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2975, 1695, 363, 526));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2353, 1696, 619, 548));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1508, 568, 506, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2015, 566, 441, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2438, 0, 441, 561));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1984, 0, 452, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1532, 0, 452, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2071, 1131, 438, 558));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2880, 0, 414, 561));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2896, 567, 411, 561));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2928, 1130, 384, 556));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3307, 567, 377, 558));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3298, 0, 389, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2513, 1131, 413, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2458, 568, 438, 557));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1048, 568, 457, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1027, 1137, 461, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(551, 1136, 474, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1043, 0, 488, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(534, 0, 507, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(530, 569, 517, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 570, 529, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 531, 566));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter >= 33)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "necroIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//deadmans heal
void VisibleObjectManager::necromancerMove6(int &counter, int player)

{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.05)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(necromancerMove6Texture);
			player1Character.setTextureRect(sf::IntRect(1447, 570, 531, 564));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1447, 570, 531, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1452, 1137, 531, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1032, 2, 526, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(512, 0, 519, 576));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 511, 580));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 584, 497, 579));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(497, 586, 481, 573));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(982, 579, 462, 568));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1559, 0, 462, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(992, 1150, 456, 555));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(506, 1162, 484, 543));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(562, 1, 526, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(506, 1162, 484, 543));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(992, 1150, 456, 555));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1559, 0, 462, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(982, 579, 462, 568));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(497, 586, 481, 573));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 584, 497, 579));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 511, 580));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(512, 0, 519, 576));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1032, 2, 526, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1452, 1137, 531, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1447, 570, 531, 564));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 29)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "necroIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.05)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(necromancerMove6Texture);
			player2Character.setTextureRect(sf::IntRect(1447, 570, 531, 564));
			player2Character.setPosition(1600, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1447, 570, 531, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1452, 1137, 531, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1032, 2, 526, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(512, 0, 519, 576));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 511, 580));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 584, 497, 579));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(497, 586, 481, 573));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(982, 579, 462, 568));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1559, 0, 462, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(992, 1150, 456, 555));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(506, 1162, 484, 543));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1165, 506, 527));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(562, 1, 526, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(506, 1162, 484, 543));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(992, 1150, 456, 555));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1559, 0, 462, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(982, 579, 462, 568));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(497, 586, 481, 573));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 584, 497, 579));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 511, 580));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(512, 0, 519, 576));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1032, 2, 526, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1452, 1137, 531, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1447, 570, 531, 564));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 29)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "necroIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//decay aura
void VisibleObjectManager::necromancerMove7(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.05)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(necromancerMove7Texture);
			player1Character.setTextureRect(sf::IntRect(1908, 558, 532, 562));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1908, 558, 532, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(969, 1330, 548, 556));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1852, 0, 371, 552));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2512, 681, 338, 664));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2873, 604, 365, 646));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2440, 0, 436, 671));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(404, 0, 426, 756));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 864, 406, 836));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 405, 858));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1518, 1227, 466, 664));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(969, 648, 471, 664));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1442, 565, 463, 661));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(832, 0, 479, 647));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2875, 0, 476, 601));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2856, 1255, 483, 570));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1984, 1123, 529, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(406, 768, 565, 559));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(406, 1331, 563, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1310, 0, 543, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 19)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "necroIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.05)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(necromancerMove7Texture);
			player2Character.setTextureRect(sf::IntRect(1908, 558, 532, 562));
			player2Character.setPosition(1600, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1908, 558, 532, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(969, 1330, 548, 556));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1852, 0, 371, 552));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2512, 681, 338, 664));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2873, 604, 365, 646));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2440, 0, 436, 671));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(404, 0, 426, 756));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 864, 406, 836));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 405, 858));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1518, 1227, 466, 664));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(969, 648, 471, 664));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1442, 565, 463, 661));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(832, 0, 479, 647));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2875, 0, 476, 601));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2856, 1255, 483, 570));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1984, 1123, 529, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(406, 768, 565, 559));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(406, 1331, 563, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1310, 0, 543, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2));
			}
			else if (counter >= 19)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "necroIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//scythe surge
void VisibleObjectManager::necromancerMove8(int &counter, int player)

{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.07)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(necromancerMove8Texture);
			player1Character.setTextureRect(sf::IntRect(2327, 0, 531, 562));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2327, 0, 531, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2860, 0, 572, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1937, 0, 387, 555));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1096, 422, 592));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2135, 1146, 494, 623));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3081, 1151, 494, 638));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));

			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2632, 1150, 447, 620));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(568, 0, 395, 542));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 566, 528));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1336, 564, 396, 575));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1561, 1149, 572, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				counter++;
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(988, 1142, 572, 583));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2632, 1150, 447, 620));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(568, 0, 395, 542));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 566, 528));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1336, 564, 396, 575));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1561, 1149, 572, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				counter++;
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(988, 1142, 572, 583));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2632, 1150, 447, 620));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(568, 0, 395, 542));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 566, 528));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1336, 564, 396, 575));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1561, 1149, 572, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
				counter++;
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(988, 1142, 572, 583));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(426, 1131, 559, 582));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3064, 566, 534, 580));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2568, 567, 493, 577));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2124, 566, 442, 578));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1735, 569, 385, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(537, 546, 365, 570));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(901, 565, 436, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(964, 0, 455, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1419, 0, 518, 563));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 531, 535, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter >= 34)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "necroIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.07)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(necromancerMove8Texture);
			player2Character.setTextureRect(sf::IntRect(2327, 0, 531, 562));
			player2Character.setPosition(1600, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2327, 0, 531, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2860, 0, 572, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1937, 0, 387, 555));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1096, 422, 592));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2135, 1146, 494, 623));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3081, 1151, 494, 638));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));

			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2632, 1150, 447, 620));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(568, 0, 395, 542));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 566, 528));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1336, 564, 396, 575));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1561, 1149, 572, 582));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				counter++;
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(988, 1142, 572, 583));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2632, 1150, 447, 620));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(568, 0, 395, 542));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 566, 528));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1336, 564, 396, 575));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1561, 1149, 572, 582));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				counter++;
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(988, 1142, 572, 583));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2632, 1150, 447, 620));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(568, 0, 395, 542));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 566, 528));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1336, 564, 396, 575));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1561, 1149, 572, 582));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				counter++;
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(988, 1142, 572, 583));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(426, 1131, 559, 582));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3064, 566, 534, 580));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2568, 567, 493, 577));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2124, 566, 442, 578));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1735, 569, 385, 572));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(537, 546, 365, 570));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(901, 565, 436, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(964, 0, 455, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1419, 0, 518, 563));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 531, 535, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter >= 34)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "necroIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}





//demon animations
void VisibleObjectManager::demonIdle(int &counter, int player)
{

	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;


	//Caps frame speed
	if (player1PassedTime >= 0.07)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(demonIdleTexture);
			player1Character.setTextureRect(sf::IntRect(1420, 651, 479, 641));


			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1420, 651, 479, 641));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1426, 0, 461, 647));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(961, 1, 461, 646));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(36, 0, 462, 641));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1425, 1939, 460, 634));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(958, 1931, 464, 629));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(496, 651, 464, 622));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(495, 1294, 470, 619));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(18, 1271, 475, 616));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2, 2507, 475, 611));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(481, 2538, 475, 609));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(14, 1892, 474, 609));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(488, 1917, 469, 616));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(29, 646, 465, 621));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(968, 1297, 457, 630));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter >= 15)
			{
				player1Character.move(-17, -10);
				counter = 0;
			}
			player1Clock.restart();
			counter++;
		}
	}

	//Caps frame speed
	if (player2PassedTime >= 0.07)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(demonIdleTexture);
			player2Character.setTextureRect(sf::IntRect(1420, 651, 479, 641));
			//player2Character.setPosition(1500, 300);


			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1420, 651, 479, 641));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1426, 0, 461, 647));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(961, 1, 461, 646));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(36, 0, 462, 641));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1425, 1939, 460, 634));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(958, 1931, 464, 629));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(496, 651, 464, 622));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(495, 1294, 470, 619));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(18, 1271, 475, 616));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2, 2507, 475, 611));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(481, 2538, 475, 609));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(14, 1892, 474, 609));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(488, 1917, 469, 616));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(29, 646, 465, 621));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(968, 1297, 457, 630));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter >= 15)
			{
				player2Character.move(17, 10);
				counter = 0;
			}
			player2Clock.restart();
			counter++;
		}
	}
}

//bone crusher
void VisibleObjectManager::demonMove1(int &counter, int player)

{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(demonMove1Texture);
			player1Character.setTextureRect(sf::IntRect(1527, 2004, 449, 602));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1527, 2004, 449, 602));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1005, 491, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 419, 448, 580));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1497, 1420, 479, 581));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(495, 978, 500, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1001, 937, 493, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(980, 419, 508, 516));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(453, 418, 521, 558));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(496, 1551, 529, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(522, 2124, 519, 593));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1044, 2086, 482, 630));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1582, 494, 596));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1027, 1503, 468, 583));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1498, 859, 478, 561));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 2180, 521, 599));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1488, 396, 488, 460));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(556, 0, 466, 412));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1512, 1, 461, 378));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1029, 0, 477, 392));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(97, 0, 452, 413));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1029, 0, 477, 392));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1512, 1, 461, 378));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(556, 0, 466, 412));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1488, 396, 488, 460));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 2180, 521, 599));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1498, 859, 478, 561));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1027, 1503, 468, 583));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1582, 494, 596));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1044, 2086, 482, 630));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(522, 2124, 519, 593));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(496, 1551, 529, 571));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(453, 418, 521, 558));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(980, 419, 508, 516));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1001, 937, 493, 560));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(495, 978, 500, 569));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1497, 1420, 479, 581));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 419, 448, 580));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1005, 491, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 38)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "demonIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.04)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(demonMove1Texture);
			player2Character.setTextureRect(sf::IntRect(1527, 2004, 449, 602));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1527, 2004, 449, 602));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1005, 491, 572));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 419, 448, 580));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1497, 1420, 479, 581));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(495, 978, 500, 569));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1001, 937, 493, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(980, 419, 508, 516));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(453, 418, 521, 558));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(496, 1551, 529, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(522, 2124, 519, 593));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1044, 2086, 482, 630));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1582, 494, 596));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1027, 1503, 468, 583));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1498, 859, 478, 561));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 2180, 521, 599));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1488, 396, 488, 460));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(556, 0, 466, 412));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1512, 1, 461, 378));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1029, 0, 477, 392));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(97, 0, 452, 413));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1029, 0, 477, 392));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1512, 1, 461, 378));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(556, 0, 466, 412));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1488, 396, 488, 460));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 2180, 521, 599));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1498, 859, 478, 561));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1027, 1503, 468, 583));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1582, 494, 596));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1044, 2086, 482, 630));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(522, 2124, 519, 593));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(496, 1551, 529, 571));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(453, 418, 521, 558));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(980, 419, 508, 516));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1001, 937, 493, 560));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(495, 978, 500, 569));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1497, 1420, 479, 581));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 419, 448, 580));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1005, 491, 572));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 38)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "demonIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//heat fumation
void VisibleObjectManager::demonMove2(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(demonMove2Texture);
			player1Character.setTextureRect(sf::IntRect(1668, 1409, 473, 608));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1668, 1409, 473, 608));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2145, 1408, 495, 614));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(50, 1334, 532, 647));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1065, 0, 524, 685));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2129, 0, 516, 694));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2123, 708, 522, 685));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1591, 0, 528, 691));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1580, 698, 538, 688));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1020, 691, 555, 666));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1072, 1389, 593, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 589, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(30, 661, 502, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(590, 0, 473, 663));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(534, 667, 483, 663));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(589, 1361, 481, 668));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(534, 667, 483, 663));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(590, 0, 473, 663));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(30, 661, 502, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 589, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1072, 1389, 593, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1020, 691, 555, 666));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1580, 698, 538, 688));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1591, 0, 528, 691));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2123, 708, 522, 685));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2129, 0, 516, 694));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1065, 0, 524, 685));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(50, 1334, 532, 647));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2145, 1408, 495, 614));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 28)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "demonIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.04)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(demonMove2Texture);
			player2Character.setTextureRect(sf::IntRect(1668, 1409, 473, 608));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1668, 1409, 473, 608));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2145, 1408, 495, 614));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(50, 1334, 532, 647));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1065, 0, 524, 685));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2129, 0, 516, 694));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2123, 708, 522, 685));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1591, 0, 528, 691));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1580, 698, 538, 688));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1020, 691, 555, 666));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1072, 1389, 593, 657));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 589, 657));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(30, 661, 502, 657));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(590, 0, 473, 663));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(534, 667, 483, 663));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(589, 1361, 481, 668));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(534, 667, 483, 663));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(590, 0, 473, 663));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(30, 661, 502, 657));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 589, 657));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1072, 1389, 593, 657));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1020, 691, 555, 666));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1580, 698, 538, 688));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1591, 0, 528, 691));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2123, 708, 522, 685));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2129, 0, 516, 694));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1065, 0, 524, 685));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(50, 1334, 532, 647));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2145, 1408, 495, 614));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 28)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "demonIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//demon fist
void VisibleObjectManager::demonMove3(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.03)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(demonMove3Texture);
			player1Character.setTextureRect(sf::IntRect(543, 537, 406, 597));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(543, 537, 406, 597));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1596, 2, 407, 576));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(521, 1738, 464, 552));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1094, 0, 498, 550));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1610, 516, 538));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1078, 532, 530));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(549, 0, 539, 531));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 546, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 541, 539, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 2152, 518, 538));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(957, 553, 483, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(537, 1138, 416, 593));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1503, 1697, 421, 544));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1444, 580, 518, 486));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(989, 2207, 507, 482));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(988, 1701, 496, 504));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(957, 1120, 469, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1430, 1122, 416, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(957, 1120, 469, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(988, 1701, 496, 504));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(989, 2207, 507, 482));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1444, 580, 518, 486));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1503, 1697, 421, 544));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(537, 1138, 416, 593));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(957, 553, 483, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 2152, 518, 538));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 541, 539, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 546, 534));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(549, 0, 539, 531));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1078, 532, 530));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1610, 516, 538));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1094, 0, 498, 550));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(521, 1738, 464, 552));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1596, 2, 407, 576));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(543, 537, 406, 597));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 35)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "demonIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.03)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(demonMove3Texture);
			player2Character.setTextureRect(sf::IntRect(543, 537, 406, 597));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(543, 537, 406, 597));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1596, 2, 407, 576));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(521, 1738, 464, 552));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1094, 0, 498, 550));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1610, 516, 538));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1078, 532, 530));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(549, 0, 539, 531));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 546, 534));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 541, 539, 534));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 2152, 518, 538));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(957, 553, 483, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(537, 1138, 416, 593));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1503, 1697, 421, 544));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1444, 580, 518, 486));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(989, 2207, 507, 482));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(988, 1701, 496, 504));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(957, 1120, 469, 572));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1430, 1122, 416, 572));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(957, 1120, 469, 572));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(988, 1701, 496, 504));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(989, 2207, 507, 482));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1444, 580, 518, 486));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1503, 1697, 421, 544));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(537, 1138, 416, 593));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(957, 553, 483, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 2152, 518, 538));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 541, 539, 534));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 546, 534));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(549, 0, 539, 531));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1078, 532, 530));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1610, 516, 538));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1094, 0, 498, 550));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(521, 1738, 464, 552));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1596, 2, 407, 576));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(543, 537, 406, 597));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 35)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "demonIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//lava ball
void VisibleObjectManager::demonMove4(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.05)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(demonMove4Texture);
			player1Character.setTextureRect(sf::IntRect(0, 1712, 413, 606));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1712, 413, 606));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(955, 1151, 404, 601));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(413, 1722, 444, 623));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1322, 1755, 437, 623));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(859, 1751, 460, 613));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1362, 1148, 475, 603));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1126, 489, 586));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(527, 562, 515, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(454, 0, 559, 556));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 572, 520, 539));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1016, 0, 408, 558));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1038, 566, 411, 579));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(482, 1132, 460, 584));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1451, 573, 411, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1424, 12, 429, 550));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 456, 550));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1424, 12, 429, 550));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1451, 573, 411, 572));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(482, 1132, 460, 584));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1038, 566, 411, 579));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1016, 0, 408, 558));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 572, 520, 539));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(454, 0, 559, 556));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(527, 562, 515, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1126, 489, 586));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1362, 1148, 475, 603));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(859, 1751, 460, 613));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1322, 1755, 437, 623));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(413, 1722, 444, 623));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(955, 1151, 404, 601));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1712, 413, 606));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 31)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "demonIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.05)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(demonMove4Texture);
			player2Character.setTextureRect(sf::IntRect(0, 1712, 413, 606));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1712, 413, 606));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(955, 1151, 404, 601));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(413, 1722, 444, 623));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1322, 1755, 437, 623));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(859, 1751, 460, 613));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1362, 1148, 475, 603));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1126, 489, 586));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(527, 562, 515, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(454, 0, 559, 556));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 572, 520, 539));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1016, 0, 408, 558));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1038, 566, 411, 579));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(482, 1132, 460, 584));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1451, 573, 411, 572));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1424, 12, 429, 550));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 456, 550));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1424, 12, 429, 550));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1451, 573, 411, 572));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(482, 1132, 460, 584));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1038, 566, 411, 579));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1016, 0, 408, 558));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 572, 520, 539));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(454, 0, 559, 556));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(527, 562, 515, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1126, 489, 586));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1362, 1148, 475, 603));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(859, 1751, 460, 613));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1322, 1755, 437, 623));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(413, 1722, 444, 623));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(955, 1151, 404, 601));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1712, 413, 606));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 31)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "demonIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//enraged
void VisibleObjectManager::demonMove5(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.05)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(demonMove5Texture);
			player1Character.setTextureRect(sf::IntRect(441, 641, 436, 606));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(441, 641, 436, 606));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2087, 647, 429, 618));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(407, 0, 399, 593));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(49, 0, 356, 593));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3728, 689, 322, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3348, 684, 376, 458));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(4, 607, 432, 423));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1297, 640, 361, 615));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3299, 0, 354, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2853, 0, 444, 647));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3659, 0, 384, 682));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2444, 0, 400, 645));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1206, 0, 394, 635));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2021, 0, 413, 642));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1661, 644, 416, 626));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2931, 660, 408, 605));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(814, 0, 381, 636));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1609, 0, 397, 636));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(880, 638, 407, 632));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2517, 650, 405, 617));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(880, 638, 407, 632));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1609, 0, 397, 636));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(814, 0, 381, 636));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2931, 660, 408, 605));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1661, 644, 416, 626));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2021, 0, 413, 642));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1206, 0, 394, 635));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2444, 0, 400, 645));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3659, 0, 384, 682));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2853, 0, 444, 647));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3299, 0, 354, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1297, 640, 361, 615));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(4, 607, 432, 423));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3348, 684, 376, 458));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3728, 689, 322, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(49, 0, 356, 593));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(407, 0, 399, 593));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2087, 647, 429, 618));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 39)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(441, 641, 436, 606));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 39)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "demonIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.05)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(demonMove5Texture);
			player2Character.setTextureRect(sf::IntRect(441, 641, 436, 606));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(441, 641, 436, 606));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2087, 647, 429, 618));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(407, 0, 399, 593));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(49, 0, 356, 593));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3728, 689, 322, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3348, 684, 376, 458));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(4, 607, 432, 423));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1297, 640, 361, 615));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3299, 0, 354, 657));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2853, 0, 444, 647));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3659, 0, 384, 682));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2444, 0, 400, 645));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1206, 0, 394, 635));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2021, 0, 413, 642));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1661, 644, 416, 626));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2931, 660, 408, 605));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(814, 0, 381, 636));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1609, 0, 397, 636));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(880, 638, 407, 632));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2517, 650, 405, 617));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(880, 638, 407, 632));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1609, 0, 397, 636));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(814, 0, 381, 636));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2931, 660, 408, 605));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1661, 644, 416, 626));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2021, 0, 413, 642));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1206, 0, 394, 635));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2444, 0, 400, 645));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3659, 0, 384, 682));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2853, 0, 444, 647));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3299, 0, 354, 657));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1297, 640, 361, 615));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(4, 607, 432, 423));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3348, 684, 376, 458));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3728, 689, 322, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(49, 0, 356, 593));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(407, 0, 399, 593));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2087, 647, 429, 618));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 39)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(441, 641, 436, 606));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 39)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "demonIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//fireskin
void VisibleObjectManager::demonMove6(int &counter, int player)

{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.05)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(demonMove6Texture);
			player1Character.setTextureRect(sf::IntRect(736, 620, 440, 608));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(736, 620, 440, 608));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1183, 650, 434, 617));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(449, 0, 418, 597));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(33, 881, 367, 591));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(410, 610, 322, 565));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(403, 1231, 359, 479));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1188, 1271, 384, 425));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(769, 1272, 413, 387));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(4, 0, 439, 383));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1581, 1315, 455, 386));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 385, 397, 429));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(871, 0, 363, 618));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1682, 1, 358, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1621, 658, 419, 653));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1238, 0, 442, 649));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1621, 658, 419, 653));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1682, 1, 358, 657));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(871, 0, 363, 618));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 385, 397, 429));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1581, 1315, 455, 386));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(4, 0, 439, 383));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(769, 1272, 413, 387));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1188, 1271, 384, 425));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(403, 1231, 359, 479));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(410, 610, 322, 565));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(33, 881, 367, 591));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(449, 0, 418, 597));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1183, 650, 434, 617));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(736, 620, 440, 608));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 29)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "demonIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
		if (player2PassedTime >= 0.05)
		{
			if (player == 2)
			{

				//sets current texture before cropping the proper sprite
				player2Character.setTexture(demonMove6Texture);
				player2Character.setTextureRect(sf::IntRect(736, 620, 440, 608));
				player2Character.setPosition(1300, 300);

				//controls current sprite showing on the sprite sheet
				if (counter == 1)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(736, 620, 440, 608));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}

				else if (counter == 2)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(1183, 650, 434, 617));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 3)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(449, 0, 418, 597));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 4)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(33, 881, 367, 591));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 5)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(410, 610, 322, 565));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 6)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(403, 1231, 359, 479));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 7)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(1188, 1271, 384, 425));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 8)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(769, 1272, 413, 387));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 9)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(4, 0, 439, 383));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 10)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(1581, 1315, 455, 386));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 11)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(0, 385, 397, 429));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 12)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(871, 0, 363, 618));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 13)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(1682, 1, 358, 657));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 14)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(1621, 658, 419, 653));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 15)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(1238, 0, 442, 649));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 16)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(1621, 658, 419, 653));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 17)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(1682, 1, 358, 657));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 18)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(871, 0, 363, 618));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 19)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(0, 385, 397, 429));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 20)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(1581, 1315, 455, 386));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 21)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(4, 0, 439, 383));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 22)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(769, 1272, 413, 387));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 23)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(1188, 1271, 384, 425));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 24)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(403, 1231, 359, 479));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 25)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(410, 610, 322, 565));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 26)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(33, 881, 367, 591));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 27)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(449, 0, 418, 597));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 28)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(1183, 650, 434, 617));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter == 29)
				{
					//sets current texture before cropping the proper sprite
					player2Character.setTextureRect(sf::IntRect(736, 620, 440, 608));
					player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
				}
				else if (counter >= 29)
				{
					counter = 1;
					player2MoveFinished = true;
					player2CurrentAnimation = "demonIdle";


				}
				player2Clock.restart();
				counter++;
			}
		}
}

//mutilation
void VisibleObjectManager::demonMove7(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(demonMove7Texture);
			player1Character.setTextureRect(sf::IntRect(1428, 0, 460, 612));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1428, 0, 460, 612));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1433, 618, 445, 603));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(991, 617, 441, 601));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(980, 0, 441, 580));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(513, 0, 464, 536));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(500, 1122, 479, 497));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(25, 538, 492, 481));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1021, 492, 478));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(22, 0, 490, 486));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(521, 582, 467, 539));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1440, 1261, 503, 644));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(984, 1226, 455, 644));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1880, 640, 601, 614));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1892, 0, 590, 639));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1946, 1256, 533, 645));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1892, 0, 590, 639));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1880, 640, 601, 614));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(984, 1226, 455, 644));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1440, 1261, 503, 644));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(521, 582, 467, 539));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(22, 0, 490, 486));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 1021, 492, 478));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(25, 538, 492, 481));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(500, 1122, 479, 497));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(513, 0, 464, 536));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(980, 0, 441, 580));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(991, 617, 441, 601));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1433, 618, 445, 603));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1428, 0, 460, 612));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 29)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "demonIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.04)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(demonMove7Texture);
			player2Character.setTextureRect(sf::IntRect(1428, 0, 460, 612));
			player2Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1428, 0, 460, 612));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1433, 618, 445, 603));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(991, 617, 441, 601));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(980, 0, 441, 580));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(513, 0, 464, 536));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(500, 1122, 479, 497));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(25, 538, 492, 481));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1021, 492, 478));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(22, 0, 490, 486));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(521, 582, 467, 539));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1440, 1261, 503, 644));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(984, 1226, 455, 644));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1880, 640, 601, 614));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1892, 0, 590, 639));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1946, 1256, 533, 645));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1892, 0, 590, 639));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1880, 640, 601, 614));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(984, 1226, 455, 644));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1440, 1261, 503, 644));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(521, 582, 467, 539));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(22, 0, 490, 486));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 1021, 492, 478));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(25, 538, 492, 481));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(500, 1122, 479, 497));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(513, 0, 464, 536));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(980, 0, 441, 580));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(991, 617, 441, 601));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1433, 618, 445, 603));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1428, 0, 460, 612));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 29)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "demonIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

//demon tackle
void VisibleObjectManager::demonMove8(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;

	//Caps frame speed
	if (player1PassedTime >= 0.05)
	{
		if (player == 1)
		{

			//sets current texture before cropping the proper sprite
			player1Character.setTexture(demonMove8Texture);
			player1Character.setTextureRect(sf::IntRect(3350, 1951, 460, 606));
			player1Character.setPosition(400, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3350, 1951, 460, 606));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2439, 1944, 449, 585));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1930, 1800, 505, 535));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(162, 1810, 585, 382));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1276, 936, 688, 364));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1127, 472, 650, 462));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(749, 1306, 550, 528));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2857, 0, 480, 686));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3318, 1371, 492, 574));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2383, 625, 466, 616));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1967, 626, 410, 634));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3346, 0, 464, 727));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3313, 728, 497, 642));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2330, 0, 521, 622));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1778, 2, 550, 585));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(13, 963, 572, 494));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2651, 2546, 581, 426));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(758, 1836, 577, 421));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1822, 1303, 571, 495));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1339, 1819, 588, 448));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(490, 473, 631, 472));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1116, 0, 654, 470));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(462, 0, 653, 470));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(3235, 2561, 575, 404));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(202, 2195, 550, 368));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 587, 486, 368));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(217, 2567, 534, 367));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1322, 2270, 602, 329));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(132, 1460, 612, 340));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(747, 2260, 570, 358));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1489, 2604, 600, 346));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(587, 947, 687, 354));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2092, 2530, 557, 445));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(1306, 1303, 513, 512));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2396, 1222, 454, 562));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2866, 1372, 444, 568));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(0, 0, 458, 584));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2895, 1953, 454, 589));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter == 39)
			{
				//sets current texture before cropping the proper sprite
				player1Character.setTextureRect(sf::IntRect(2853, 694, 451, 593));
				player1Character.setPosition(adjustPosition(vec1, player1Character, vec2));
			}
			else if (counter >= 39)
			{
				counter = 1;
				player1MoveFinished = true;
				player1CurrentAnimation = "demonIdle";


			}
			player1Clock.restart();
			counter++;
		}
	}
	//Caps frame speed
	if (player2PassedTime >= 0.05)
	{
		if (player == 2)
		{

			//sets current texture before cropping the proper sprite
			player2Character.setTexture(demonMove8Texture);
			player2Character.setTextureRect(sf::IntRect(3350, 1951, 460, 606));
			player2Character.setPosition(1300, 300);

			//controls current sprite showing on the sprite sheet
			if (counter == 1)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3350, 1951, 460, 606));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}

			else if (counter == 2)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2439, 1944, 449, 585));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 3)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1930, 1800, 505, 535));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 4)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(162, 1810, 585, 382));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 5)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1276, 936, 688, 364));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 6)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1127, 472, 650, 462));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 7)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(749, 1306, 550, 528));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 8)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2857, 0, 480, 686));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 9)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3318, 1371, 492, 574));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 10)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2383, 625, 466, 616));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 11)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1967, 626, 410, 634));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 12)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3346, 0, 464, 727));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 13)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3313, 728, 497, 642));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 14)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2330, 0, 521, 622));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 15)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1778, 2, 550, 585));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 16)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(13, 963, 572, 494));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 17)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2651, 2546, 581, 426));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 18)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(758, 1836, 577, 421));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 19)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1822, 1303, 571, 495));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 20)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1339, 1819, 588, 448));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 21)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(490, 473, 631, 472));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 22)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1116, 0, 654, 470));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 23)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(462, 0, 653, 470));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 24)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(3235, 2561, 575, 404));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 25)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(202, 2195, 550, 368));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 26)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 587, 486, 368));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 27)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(217, 2567, 534, 367));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 28)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1322, 2270, 602, 329));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 29)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(132, 1460, 612, 340));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 30)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(747, 2260, 570, 358));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 31)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1489, 2604, 600, 346));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 32)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(587, 947, 687, 354));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 33)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2092, 2530, 557, 445));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 34)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(1306, 1303, 513, 512));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 35)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2396, 1222, 454, 562));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 36)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2866, 1372, 444, 568));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 37)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(0, 0, 458, 584));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 38)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2895, 1953, 454, 589));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter == 39)
			{
				//sets current texture before cropping the proper sprite
				player2Character.setTextureRect(sf::IntRect(2853, 694, 451, 593));
				player2Character.setPosition(adjustPosition(vec1Player2, player2Character, vec2Player2));
			}
			else if (counter >= 39)
			{
				counter = 1;
				player2MoveFinished = true;
				player2CurrentAnimation = "demonIdle";


			}
			player2Clock.restart();
			counter++;
		}
	}
}

void VisibleObjectManager::demonHit(int &counter, int player)
{
	double player1PassedTime = (double)(player1Clock.getElapsedTime().asSeconds());
	double player2PassedTime = (double)(player2Clock.getElapsedTime().asSeconds());

	sf::Vector2f vec1;
	vec1.x = 300;
	vec1.y = 300;


	sf::Vector2f vec1Player2;
	vec1Player2.x = 300;
	vec1Player2.y = 300;


	sf::Vector2f vec2;
	vec2.x = 593;
	vec2.y = 550;


	//position of sprite
	sf::Vector2f vec2Player2;
	vec2Player2.x = 1293;
	vec2Player2.y = 550;
}


sf::Vector2f VisibleObjectManager::adjustPosition(sf::Vector2f vec1, sf::Sprite sprite, sf::Vector2f vec2)
{
	sf::Vector2f tempSpriteVector;
	tempSpriteVector.x = sprite.getLocalBounds().width;
	tempSpriteVector.y = sprite.getLocalBounds().height;

	sf::Vector2f tempVector;
	tempVector.x = ((vec1.x - tempSpriteVector.x) + vec2.x);
	tempVector.y = ((vec1.y - tempSpriteVector.y) + vec2.y);


	return tempVector;
}

sf::Vector2f VisibleObjectManager::adjustPositionPlayer2(sf::Vector2f vec1, sf::Sprite sprite, sf::Vector2f vec2)
{
	sf::Vector2f tempSpriteVector;
	tempSpriteVector.x = sprite.getLocalBounds().width;
	tempSpriteVector.y = sprite.getLocalBounds().height;

	sf::Vector2f tempVector;



	//reversed x adjustment 
	tempVector.x = ((tempSpriteVector.x - vec1.x) + vec2.x);
	tempVector.y = ((vec1.y - tempSpriteVector.y) + vec2.y);


	return tempVector;
}