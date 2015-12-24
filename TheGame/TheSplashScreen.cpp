#include "TheSplashScreen.h"


float MySpeed = 300.0;


void SplashScreen()
{
	bool SplashScreenIsActive = true;

	float Alpha = 20;
	int PositiveORNegative = 1;
	int CurrentScreen = 1;
	sf::Sprite SFMLLogo;
	sf::Texture SFMLLogoTexture;
	SFMLLogoTexture.loadFromFile("Data/Textures/Splash/SFMLLogoTexture.png");
	SFMLLogo.setTexture(SFMLLogoTexture);
	SFMLLogo.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
	SFMLLogo.setOrigin(280, 85);
	SFMLLogo.setColor(sf::Color(255, 255, 255, Alpha));
	//--------------------------------------------------------------------------------------------------------------
	sf::Sprite VisualStudioLogo;
	sf::Texture VisualStudioTexture;
	VisualStudioTexture.loadFromFile("Data/Textures/Splash/VisualStudioTexture.png");
	VisualStudioLogo.setTexture(VisualStudioTexture);
	VisualStudioLogo.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
	VisualStudioLogo.setOrigin(153, 153);
	VisualStudioLogo.setColor(sf::Color(255, 255, 255, Alpha));
	//--------------------------------------------------------------------------------------------------------------
	sf::Sprite Microsoft;
	sf::Texture MicrosoftTexture;
	MicrosoftTexture.loadFromFile("Data/Textures/Splash/MicrosoftTexture.png");
	Microsoft.setTexture(MicrosoftTexture);
	Microsoft.setColor(sf::Color(255, 255, 255, Alpha));
	Microsoft.setPosition(ScreenDimensions.x - 170, ScreenDimensions.y - 40);
	//--------------------------------------------------------------------------------------------------------------
	sf::Sprite GameLogo;
	sf::Texture GameLogoTexture;
	GameLogoTexture.loadFromFile("Data/Textures/Splash/wow5.jpg");
	GameLogo.setTexture(GameLogoTexture);
	GameLogo.setScale(ScreenDimensions.x / GameLogo.getLocalBounds().width, ScreenDimensions.y / GameLogo.getLocalBounds().height);
	sf::Sprite PressEnter;
	sf::Texture PressEnterTexture;
	PressEnterTexture.loadFromFile("Data/Textures/Splash/PressEnter.png");
	PressEnter.setTexture(PressEnterTexture);
	PressEnter.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
	PressEnter.setOrigin(171, 23);


	sf::Clock clock;
	sf::Time Independence;
	bool Protect = false;
	while (GameWindow.isOpen() && SplashScreenIsActive)
	{
		
		SFMLLogo.setColor(sf::Color(255, 255, 255, Alpha));
		VisualStudioLogo.setColor(sf::Color(255, 255, 255, Alpha));
		Microsoft.setColor(sf::Color(255, 255, 255, Alpha));
		GameLogo.setColor(sf::Color(255, 255, 255, Alpha));

		sf::Event myevent;
		while (GameWindow.pollEvent(myevent))
		{
			switch (myevent.type)
			{
			case sf::Event::Closed:
				GameWindow.close();
				break;
			}
		}


		GameWindow.clear();

		switch (CurrentScreen)
		{
		case 1:
			GameWindow.draw(SFMLLogo);
			
			if (Alpha >= 255)
			{
				sf::sleep(sf::seconds(0.6));
				Protect = true;
				PositiveORNegative = -1;
			}
			else if (Alpha < 5)
			{
				PositiveORNegative = 1;
				CurrentScreen = 2;

			}

			Alpha += 1 * PositiveORNegative*Independence.asSeconds()*MySpeed;



			break;
		case 2:
			GameWindow.draw(VisualStudioLogo);
			GameWindow.draw(Microsoft);
			if (Alpha >= 255)
			{
				sf::sleep(sf::seconds(0.6));
				Protect = true;
				PositiveORNegative = -1;
			}
			else if (Alpha < 5)
			{
				PositiveORNegative = 1;
				Alpha = 6;
				CurrentScreen = 3;

			}
			Alpha += 1 * PositiveORNegative*Independence.asSeconds()*MySpeed;
			break;
		case 3:
			
			GameWindow.draw(GameLogo);
			if (Alpha >= 255)
			{
				float Alpha2 = 1;
				sf::sleep(sf::seconds(1));
				
				sf::Clock clock2;
				sf::Time Independence2;
				bool Protect2 = false;
				while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))))
				{
					
					
					
					if (Alpha2 >= 255)
					{
						sf::sleep(sf::seconds(0.3));
						Protect2 = true;
						PositiveORNegative = -1;
					}
					else if (Alpha2 < 5)
					{
						PositiveORNegative = 1;
					}
					Alpha2 += 1 * PositiveORNegative*Independence2.asSeconds()*MySpeed;
					GameLogo.setColor(sf::Color(255, 255, 255, 255));
					PressEnter.setColor(sf::Color(255, 255, 255, Alpha2));
					GameWindow.clear();
					GameWindow.draw(GameLogo);
					GameWindow.draw(PressEnter);
					GameWindow.display();
					if (Protect2 != true)
					{
						Independence2 = clock2.getElapsedTime();
					}
					Protect2 = false;
					clock2.restart().asSeconds();
					
				}
				
				
				GameLogo.setColor(sf::Color(255, 255, 255, 0));
				PositiveORNegative = -1;

			}
			
			if (Alpha < 5)
			{
				//PositiveORNegative = 1;
				SplashScreenIsActive = false;

			}
			
			Alpha += 1 * PositiveORNegative*Independence.asSeconds()*MySpeed;
			break;
		
			
		}
		
		
		if(SplashScreenIsActive==true) GameWindow.display();
	
		//sf::sleep(sf::milliseconds(0.2));
		if (Protect != true)
		{
			Independence = clock.getElapsedTime();
		}
		Protect = false;
		clock.restart().asSeconds();
	}
}




