#pragma once
#include "SFML/Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Window.hpp"
#include <iostream>
#include <string>
#include <string.h>

#include "TheTankClass.h"

#include "TheFrontEnd.h"
struct PlayerChoices
{
	int SinglePlayerOrTwoPlayers;
	bool CampaignORSurvival;
	TheTankType Player1ChosenTank, Player2ChosenTank;
	TheTruckType Player1ChosenTruck, Player2ChosenTruck;
	TheHeliType Player1ChosenHeli, Player2ChosenHeli;
};

class TheMainMenuClass
{
public:
	TheMainMenuClass();
	~TheMainMenuClass();
	sf::Vector2i ScreenDimensions;
	bool MenuIsActive = true;
	float MySpeed = 300.0;
	float Alpha = 1.0;
	int PositiveORNegative = 1;
	int CurrentScreen = 1;
	sf::Time Independence;
	sf::Font BattlefieldFont;
	sf::Sprite MenuBackground;
	sf::Texture MenuBackgroundTexture;
	sf::Text Story;
	sf::Text Competitive;
	sf::Text Options;
	sf::Text Help;
	sf::Text About;
	sf::Text Exit;
	
	bool CampaignOrSurvival=0;

	int SinglePlayerOrTwoPlayers = 1;
	

	int Player1ChosenTank = 1;
	int Player2ChosenTank = 2;

	int Player1ChosenTruck = 1;
	int Player2ChosenTruck = 2;
	
	bool Player1ChosenHeli = 1;
	bool Player2ChosenHeli = 1;

	bool CampaignIsActive = false;
	bool PauseisActive = true;
	void MainMenuDisplay(sf::RenderWindow &GameWindow);
	void AboutScreen(sf::RenderWindow &GameWindow);
	void HelpScreen(sf::RenderWindow &GameWindow);
	void OptionsScreen(sf::RenderWindow &GameWindow,  std::string CallerName );
	void CampaignScreen(sf::RenderWindow &GameWindow);
	
	struct PlayerChoices GetCampaignValues();
};

