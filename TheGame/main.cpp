#include "SFML/Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Audio\Listener.hpp"
#include <iostream>
#include "TheSplashScreen.h"
#include "TheFrontEnd.h"
#include "TheMainMenuClass.h"
#include <math.h>
#include <string.h>



//void FrontEnd(sf::RenderWindow &GameWindow);


using namespace std;

int main()
{
	srand(time(NULL));
	sf::Music MainMenuMusic;
	MainMenuMusic.openFromFile("Data/Music/SkiesOfWarOST.ogg");
	MainMenuMusic.play();
	GameWindow.setMouseCursorVisible(false);
	IsjoystickConnected = sf::Joystick::isConnected(0);
	
	SplashScreen();	
	//-----------------menu-----------------------------------------------------------------------
	PlayerChoices PlayerChoice;

	while (GameWindow.isOpen())
	{
		TheMainMenuClass *MainMenu = new TheMainMenuClass();
		MainMenu->MainMenuDisplay(GameWindow);
		PlayerChoice = MainMenu->GetCampaignValues();
		delete MainMenu;
		MainMenuMusic.stop();
		if (GameWindow.isOpen())
		{
			if (PlayerChoice.CampaignORSurvival == 0)
			{
				GameMusic.stop();
				CutScene1();
				FrontEnd(PlayerChoice);
			}
			else
				Survival(PlayerChoice);
		}
			
	}
	return 0;
}


