#include "TheMainMenuClass.h"



TheMainMenuClass::TheMainMenuClass()
{
	//Independence = sf::milliseconds(2);
	ScreenDimensions.x = sf::VideoMode::getDesktopMode().width;
	ScreenDimensions.y = sf::VideoMode::getDesktopMode().height;

	BattlefieldFont.loadFromFile("Data/Fonts/BattlefieldFont.ttf");

	MenuBackgroundTexture.loadFromFile("Data/Textures/MainMenu/wow.png");
	MenuBackground.setTexture(MenuBackgroundTexture);
	MenuBackground.setScale(ScreenDimensions.x / MenuBackground.getLocalBounds().width, ScreenDimensions.y / MenuBackground.getLocalBounds().height);
	
	Story.setString("campaign");
	Story.setFont(BattlefieldFont);
	Story.setCharacterSize(50);
	Story.setPosition(700, 200);

	
	Competitive.setString("survival mode");
	Competitive.setFont(BattlefieldFont);
	Competitive.setCharacterSize(50);
	Competitive.setPosition(700, 300);

	Options.setString("options");
	Options.setFont(BattlefieldFont);
	Options.setCharacterSize(50);
	Options.setPosition(700, 400);

	Help.setString("help");
	Help.setFont(BattlefieldFont);
	Help.setCharacterSize(50);
	Help.setPosition(700, 500);

	About.setString("about");
	About.setFont(BattlefieldFont);
	About.setCharacterSize(50);
	About.setPosition(700, 600);

	Exit.setString("exit");
	Exit.setFont(BattlefieldFont);
	Exit.setCharacterSize(50);
	Exit.setPosition(700, 700);
}


TheMainMenuClass::~TheMainMenuClass()
{
}


void TheMainMenuClass::MainMenuDisplay(sf::RenderWindow &GameWindow)
{
	
	int CurrenttemIndex = 1;
	bool CampaignCall = false;
	sf::Clock myclock;
	sf::Sprite AirPlane; sf::Texture AirPlaneTexture; AirPlaneTexture.loadFromFile("Data/Textures/Jet/Plane2HighRes.png");
	AirPlane.setTexture(AirPlaneTexture);
	AirPlane.scale(0.5, 0.5);
	AirPlane.setRotation(-90);
	AirPlane.setPosition(ScreenDimensions.x / 4, ScreenDimensions.y);
	AirPlane.setOrigin(862, 388);
	sf::Sprite Tank[6]; sf::Texture TankTexture[6];
	TankTexture[0].loadFromFile("Data/Textures/TankHighRes/Type1_HoneyBadger.png");	TankTexture[1].loadFromFile("Data/Textures/TankHighRes/Type2_HankTheTank.png");
	TankTexture[2].loadFromFile("Data/Textures/TankHighRes/Type3_Centurion.png");	TankTexture[3].loadFromFile("Data/Textures/TankHighRes/Type4_Crusader.png");
	TankTexture[4].loadFromFile("Data/Textures/TankHighRes/Type5_Challenger.png");	TankTexture[5].loadFromFile("Data/Textures/TankHighRes/Type6_BlackPrince.png");
	for (int i = 0; i < 6; i++)
	{
		Tank[i].setTexture(TankTexture[i]);
		Tank[i].scale(GlobalScaleFactor);
		Tank[i].setRotation(-90);
	}
	
	Tank[0].setPosition(ScreenDimensions.x*0.01 + 80, ScreenDimensions.y + 200);	Tank[1].setPosition(ScreenDimensions.x*0.07 + 80, ScreenDimensions.y + 200);
	Tank[2].setPosition(ScreenDimensions.x*0.13 + 80, ScreenDimensions.y + 200);	Tank[3].setPosition(ScreenDimensions.x*0.185 + 80, ScreenDimensions.y + 200);
	Tank[4].setPosition(ScreenDimensions.x*0.25 + 80, ScreenDimensions.y + 200);	Tank[5].setPosition(ScreenDimensions.x*0.30 + 80, ScreenDimensions.y + 200);
	Tank[0].scale(0.3, 0.3);		Tank[1].scale(0.3, 0.3);		Tank[2].scale(0.3, 0.3);
	Tank[3].scale(0.4, 0.7);		Tank[4].scale(0.5, 0.5);		Tank[5].scale(0.45, 0.45);
	
	while (GameWindow.isOpen() && MenuIsActive)
	{
		
		sf::Event myevent;
		while (GameWindow.pollEvent(myevent))
		{
			switch (myevent.type)
			{
			case sf::Event::Closed:
				GameWindow.close();
				break;						
			case sf::Event::KeyPressed:
				switch (myevent.key.code)
				{
				
				case sf::Keyboard::Return:
					switch (CurrenttemIndex)
					{
					case 1:CampaignOrSurvival = 0;
						CampaignScreen(GameWindow);
						if (CampaignIsActive == true)
						{
							return;
						}
						break;
					case 2:CampaignOrSurvival = 1;
						CampaignScreen(GameWindow);
						if (CampaignIsActive == true)
						{
							return;
						}
						return;
						break;
					case 3:
						OptionsScreen(GameWindow, "MainMenu");
						break;
					case 4:
						HelpScreen(GameWindow);
						break;
					case 5:					
						AboutScreen(GameWindow);
						break;
					case 6: GameWindow.close();
						break;
					default:
						break;
					}
					break;

				case sf::Keyboard::Down:
					if (CurrenttemIndex == 6) CurrenttemIndex = 1;
					else CurrenttemIndex++;
					break;
				case sf::Keyboard::Up:
					if (CurrenttemIndex == 1) CurrenttemIndex = 6;
					else CurrenttemIndex--;
					break;
				default:
					break;
				}
				break;
			}
		}
		//endofeventPoLL--

		//----------TankAnimation-----------


		switch (CurrenttemIndex)
		{
		case 0:
			Story.setColor(sf::Color::White);
			Story.setScale(1.0, 1.0);
			Competitive.setColor(sf::Color::White);
			Competitive.setScale(1.0, 1.0);
			Options.setColor(sf::Color::White);
			Options.setScale(1.0, 1.0);
			Help.setColor(sf::Color::White);
			Help.setScale(1.0, 1.0);
			About.setColor(sf::Color::White);
			About.setScale(1.0, 1.0);
			Exit.setColor(sf::Color::White);
			Exit.setScale(1.0, 1.0);
			break;

		case 1:Story.setColor(sf::Color::Red);
			Story.setScale(1.2, 1.2);

			Competitive.setColor(sf::Color::White);
			Competitive.setScale(1.0, 1.0);
			Options.setColor(sf::Color::White);
			Options.setScale(1.0, 1.0);
			Help.setColor(sf::Color::White);
			Help.setScale(1.0, 1.0);
			About.setColor(sf::Color::White);
			About.setScale(1.0, 1.0);
			Exit.setColor(sf::Color::White);
			Exit.setScale(1.0, 1.0);
			break;
		case 2:
			Story.setColor(sf::Color::White);
			Story.setScale(1.0, 1.0);

			Competitive.setColor(sf::Color::Red);
			Competitive.setScale(1.2, 1.2);

			Options.setColor(sf::Color::White);
			Options.setScale(1.0, 1.0);
			Help.setColor(sf::Color::White);
			Help.setScale(1.0, 1.0);
			About.setColor(sf::Color::White);
			About.setScale(1.0, 1.0);
			Exit.setColor(sf::Color::White);
			Exit.setScale(1.0, 1.0);
			break;
		case 3:
			Story.setColor(sf::Color::White);
			Story.setScale(1.0, 1.0);
			Competitive.setColor(sf::Color::White);
			Competitive.setScale(1.0, 1.0);

			Options.setColor(sf::Color::Red);
			Options.setScale(1.2, 1.2);

			Help.setColor(sf::Color::White);
			Help.setScale(1.0, 1.0);
			About.setColor(sf::Color::White);
			About.setScale(1.0, 1.0);
			Exit.setColor(sf::Color::White);
			Exit.setScale(1.0, 1.0);
			break;
		case 4:
			Story.setColor(sf::Color::White);
			Story.setScale(1.0, 1.0);
			Competitive.setColor(sf::Color::White);
			Competitive.setScale(1.0, 1.0);
			Options.setColor(sf::Color::White);
			Options.setScale(1.0, 1.0);

			Help.setColor(sf::Color::Red);
			Help.setScale(1.2, 1.2);

			About.setColor(sf::Color::White);
			About.setScale(1.0, 1.0);
			Exit.setColor(sf::Color::White);
			Exit.setScale(1.0, 1.0);
			break;
		case 5:
			Story.setColor(sf::Color::White);
			Story.setScale(1.0, 1.0);
			Competitive.setColor(sf::Color::White);
			Competitive.setScale(1.0, 1.0);
			Options.setColor(sf::Color::White);
			Options.setScale(1.0, 1.0);
			Help.setColor(sf::Color::White);
			Help.setScale(1.0, 1.0);

			About.setColor(sf::Color::Red);
			About.setScale(1.2, 1.2);

			Exit.setColor(sf::Color::White);
			Exit.setScale(1.0, 1.0);
			break;
		case 6:
			Story.setColor(sf::Color::White);
			Story.setScale(1.0, 1.0);
			Competitive.setColor(sf::Color::White);
			Competitive.setScale(1.0, 1.0);
			Options.setColor(sf::Color::White);
			Options.setScale(1.0, 1.0);
			Help.setColor(sf::Color::White);
			Help.setScale(1.0, 1.0);
			About.setColor(sf::Color::White);
			About.setScale(1.0, 1.0);

			Exit.setColor(sf::Color::Red);
			Exit.setScale(1.2, 1.2);
		default:
			break;
		}
		//end of item highliter

		while (!(Alpha >= 255))
		{
			MenuBackground.setColor(sf::Color(255, 255, 255, Alpha));
			Story.setColor(sf::Color(255, 255, 255, Alpha));
			Competitive.setColor(sf::Color(255, 255, 255, Alpha));
			Options.setColor(sf::Color(255, 255, 255, Alpha));
			Help.setColor(sf::Color(255, 255, 255, Alpha));
			About.setColor(sf::Color(255, 255, 255, Alpha));
			Exit.setColor(sf::Color(255, 255, 255, Alpha));
			if (!(Alpha>=255))
			Alpha += 1*Independence.asSeconds()*MySpeed;
			
			if (CampaignCall == false)
			{
				GameWindow.clear();
				GameWindow.draw(MenuBackground);
				for (int i = 0; i < 6; i++)
				{
					GameWindow.draw(Tank[i]);
				}
				GameWindow.draw(Story);
				GameWindow.draw(Competitive);
				GameWindow.draw(Options);
				GameWindow.draw(Help);
				GameWindow.draw(About);
				GameWindow.draw(Exit);
				GameWindow.display();
			}
			Independence = myclock.getElapsedTime();
			myclock.restart().asSeconds();
		}

		
			AirPlane.move(0, -2);
		if (CampaignCall == false)
		{
			GameWindow.clear();
			GameWindow.draw(MenuBackground);
			for (int i = 0; i < 6; i++)
			{
				Tank[i].move(0, -1 * Freedom.asSeconds()*MySpeed*0.2);
				GameWindow.draw(Tank[i]);
			}
			GameWindow.draw(AirPlane);
			GameWindow.draw(Story);
			GameWindow.draw(Competitive);
			GameWindow.draw(Options);
			GameWindow.draw(Help);
			GameWindow.draw(About);
			GameWindow.draw(Exit);
			GameWindow.display();
		}
		
		
		
	
	}

}

void TheMainMenuClass::AboutScreen(sf::RenderWindow &GameWindow)
{
		bool AboutScreenIsActive = true;
		sf::Sprite AboutScreenText;
		sf::Texture AboutScreenTextTexture; AboutScreenTextTexture.loadFromFile("Data/Textures/MainMenu/AboutScreenTextTexture.png");
		AboutScreenText.setTexture(AboutScreenTextTexture);
		AboutScreenText.setPosition(1440 / 2, 900 / 2.5);
		Alpha = 5;
		while (GameWindow.isOpen() && AboutScreenIsActive)
		{
			sf::Event myevent;
			while (GameWindow.pollEvent(myevent))
			{
				switch (myevent.type)
				{
				case sf::Event::Closed:
					GameWindow.close();
					break;
				case sf::Event::KeyPressed:
					switch (myevent.key.code)
					{
					case sf::Keyboard::Return:
					case sf::Keyboard::Escape:
					case sf::Keyboard::BackSpace:
					case sf::Keyboard::Space:    AboutScreenIsActive = false;
						
						break;
					}
				case sf::Event::MouseButtonPressed:

					switch (myevent.key.code)
					{
					case sf::Mouse::Left:
						AboutScreenIsActive = false;
					}
					break;

				}
				while (!(Alpha >= 255))
				{
					MenuBackground.setColor(sf::Color(255, 255, 255, Alpha));
					AboutScreenText.setColor(sf::Color(255, 255, 255, Alpha));
					
					Alpha += 1*Independence.asSeconds()*MySpeed;

					GameWindow.clear();
					GameWindow.draw(MenuBackground);
					GameWindow.draw(AboutScreenText);
					GameWindow.display();
				}

				GameWindow.clear();
				GameWindow.draw(MenuBackground);
				GameWindow.draw(AboutScreenText);
				GameWindow.display();
			}
		}
		Alpha = 5;
		while (!(Alpha >= 255))
		{
			MenuBackground.setColor(sf::Color(255, 255, 255, Alpha));
			Story.setColor(sf::Color(255, 255, 255, Alpha));
			Competitive.setColor(sf::Color(255, 255, 255, Alpha));
			Options.setColor(sf::Color(255, 255, 255, Alpha));
			Help.setColor(sf::Color(255, 255, 255, Alpha));
			About.setColor(sf::Color(255, 255, 255, Alpha));
			Exit.setColor(sf::Color(255, 255, 255, Alpha));

			Alpha += 1 * Independence.asSeconds()*MySpeed;

			GameWindow.clear();
			GameWindow.draw(MenuBackground);
			GameWindow.draw(Story);
			GameWindow.draw(Competitive);
			GameWindow.draw(Options);
			GameWindow.draw(Help);
			GameWindow.draw(About);
			GameWindow.draw(Exit);
			GameWindow.display();
		}
}

void TheMainMenuClass::HelpScreen(sf::RenderWindow &GameWindow)
{
	
		bool HelpScreenIsActive = true;
		sf::Sprite HelpScreenText;
		sf::Texture HelpScreenTextTexture; HelpScreenTextTexture.loadFromFile("Data/Textures/MainMenu/HelpScreenTextTexture.png");
		HelpScreenText.setTexture(HelpScreenTextTexture);


		HelpScreenText.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
		Alpha = 5;
		while (GameWindow.isOpen() && HelpScreenIsActive)
		{
			sf::Event myevent;
			while (GameWindow.pollEvent(myevent))
			{
				switch (myevent.type)
				{
				case sf::Event::Closed:
					GameWindow.close();
					break;
				case sf::Event::KeyPressed:
					switch (myevent.key.code)
					{
					case sf::Keyboard::Return:
					case sf::Keyboard::Escape:
					case sf::Keyboard::BackSpace:
					case sf::Keyboard::Space:HelpScreenIsActive = false;

						
					}
					break;
				case sf::Event::MouseButtonPressed:

					switch (myevent.key.code)
					{
					case sf::Mouse::Left:
						HelpScreenIsActive = false;
					}
					break;

				}
				while (!(Alpha >= 255))
				{
					MenuBackground.setColor(sf::Color(255, 255, 255, Alpha));
					HelpScreenText.setColor(sf::Color(255, 255, 255, Alpha));

					Alpha += 1*Independence.asSeconds()*MySpeed;

					GameWindow.clear();
					GameWindow.draw(MenuBackground);
					GameWindow.draw(HelpScreenText);
					GameWindow.display();
				}

				GameWindow.clear();
				GameWindow.draw(MenuBackground);
				GameWindow.draw(HelpScreenText);
				GameWindow.display();
			}
		}
		Alpha = 5;
		while (!(Alpha >= 255))
		{
			MenuBackground.setColor(sf::Color(255, 255, 255, Alpha));
			Story.setColor(sf::Color(255, 255, 255, Alpha));
			Competitive.setColor(sf::Color(255, 255, 255, Alpha));
			Options.setColor(sf::Color(255, 255, 255, Alpha));
			Help.setColor(sf::Color(255, 255, 255, Alpha));
			About.setColor(sf::Color(255, 255, 255, Alpha));
			Exit.setColor(sf::Color(255, 255, 255, Alpha));

			Alpha += 1 * Independence.asSeconds()*MySpeed;

			GameWindow.clear();
			GameWindow.draw(MenuBackground);
			GameWindow.draw(Story);
			GameWindow.draw(Competitive);
			GameWindow.draw(Options);
			GameWindow.draw(Help);
			GameWindow.draw(About);
			GameWindow.draw(Exit);
			GameWindow.display();
		}
	
}

void TheMainMenuClass::OptionsScreen(sf::RenderWindow &GameWindow,std::string CallerName)
{

	bool OptionsScreenIsActive = true;
	PauseisActive = true;
	int CurrenttemIndex = 1;
	int ResoultionIndex = 0;
	int SoundVolumeIndex = 80;
	sf::Text Resolution("resolution:", BattlefieldFont, 40);
	
	
	sf::Text ResolutionChoice[5];

	for (int i= 0; i < 5; i++)
	{
		ResolutionChoice[i].setFont(BattlefieldFont);
		ResolutionChoice[i].setCharacterSize(40);
		
	}
	std::string TheScreenResolution;
	sf::Vector2i DefaultResolution;
	DefaultResolution.x = ScreenDimensions.x;
	DefaultResolution.y = ScreenDimensions.y;
	TheScreenResolution = std::to_string(ScreenDimensions.x);
	TheScreenResolution.append(" x ");
	TheScreenResolution.append(std::to_string(ScreenDimensions.y));

	ResolutionChoice[0].setString(TheScreenResolution);
	ResolutionChoice[1].setString("800 x 600");	
	ResolutionChoice[2].setString("1024 x 768");	 
	ResolutionChoice[3].setString("1280 x 800");	 
	ResolutionChoice[4].setString("1440 x 900");	 
	
	
	
	sf::Text SoundVolume("sound volume:", BattlefieldFont, 40);
	
	sf::Text SoundVolumeValue("80", BattlefieldFont, 40);
	
	

	sf::Text Apply("apply", BattlefieldFont, 40);
	sf::Text Ok("back", BattlefieldFont, 40);

	Alpha = 5;
	
	sf::Time OptionsIndependence = sf::seconds(0.002);
	while (GameWindow.isOpen() && OptionsScreenIsActive)
	{
		
		Resolution.setPosition(ScreenDimensions.x / 4, ScreenDimensions.y / 4);
		for (int i = 0; i < 5; i++)
		{
			ResolutionChoice[i].setPosition(ScreenDimensions.x - ScreenDimensions.x / 3, ScreenDimensions.y / 4);
		}
		SoundVolume.setPosition(ScreenDimensions.x / 4, ScreenDimensions.y / 4 + ScreenDimensions.y / 8);
		Apply.setPosition(ScreenDimensions.x *0.75, ScreenDimensions.y - ScreenDimensions.y / 4);
		Ok.setPosition(ScreenDimensions.x /4, ScreenDimensions.y - ScreenDimensions.y / 4);
		SoundVolumeValue.setPosition(ScreenDimensions.x - ScreenDimensions.x / 3, ScreenDimensions.y / 4 + ScreenDimensions.y / 8);

		sf::Event myevent;
		while (GameWindow.pollEvent(myevent))
		{
			switch (myevent.type)
			{
			case sf::Event::Closed:
				GameWindow.close();
				break;
			case sf::Event::KeyPressed:
				switch (myevent.key.code)
				{
				case sf::Keyboard::Return:
					if (CurrenttemIndex == 4)
					{
						if (ResoultionIndex == 0)
							GameWindow.create(sf::VideoMode(DefaultResolution.x, DefaultResolution.y), "TheGame", sf::Style::Fullscreen);
						else if (ResoultionIndex == 1)
							GameWindow.create(sf::VideoMode(800, 600), "TheGame", sf::Style::Fullscreen);
						else if (ResoultionIndex == 2)
							GameWindow.create(sf::VideoMode(1024, 768), "TheGame", sf::Style::Fullscreen);
						else if (ResoultionIndex == 3)
							GameWindow.create(sf::VideoMode(1280, 800), "TheGame", sf::Style::Fullscreen);
						else if (ResoultionIndex == 4)
							GameWindow.create(sf::VideoMode(1440, 900), "TheGame", sf::Style::Fullscreen);
					}
					else if (CurrenttemIndex == 3)
					{
						OptionsScreenIsActive = false;
					}
					ScreenDimensions.x = sf::VideoMode::getDesktopMode().width;
					ScreenDimensions.y = sf::VideoMode::getDesktopMode().height;
					break;
				case sf::Keyboard::Escape:
				case sf::Keyboard::BackSpace:
					OptionsScreenIsActive = false;
					break;
				case sf::Keyboard::Space:
					break;
				case sf::Keyboard::Down:
					if(CurrenttemIndex!=4) CurrenttemIndex++;
					break;
				case sf::Keyboard::Up:
					if (CurrenttemIndex != 1)CurrenttemIndex--;
					break;
				case sf::Keyboard::Right:
					if (CurrenttemIndex == 1)
					{
						if (ResoultionIndex!=4)
						ResoultionIndex++;
					}
					else if (CurrenttemIndex == 2)
					{
						if (SoundVolumeIndex!=100)
						SoundVolumeIndex+=5;
						SoundVolumeValue.setString(std::to_string(SoundVolumeIndex));
						sf::Listener::setGlobalVolume(SoundVolumeIndex);
					}
					break;
				case sf::Keyboard::Left:
					if (CurrenttemIndex == 1)
					{
						if (ResoultionIndex!=0)
						ResoultionIndex--;
					}
					else if (CurrenttemIndex == 2)
					{
						if (SoundVolumeIndex != 0)
						SoundVolumeIndex-=5;
						SoundVolumeValue.setString(std::to_string(SoundVolumeIndex));
						sf::Listener::setGlobalVolume(SoundVolumeIndex);
					}
					break;
				}
			case sf::Event::MouseMoved:
				//if ((myevent.mouseMove.x > Story.getPosition().x && myevent.mouseMove.x < Story.getPosition().x + 343) && (myevent.mouseMove.y > Story.getPosition().y && myevent.mouseMove.y < Story.getPosition().y + 86))
				//{
				//	CurrenttemIndex = 1;
				//}
				;
			}

			switch (CurrenttemIndex)
			{
			case 0:
				Resolution.setColor(sf::Color::White);
				Resolution.setScale(1.0, 1.0);
				for (int i = 0; i < 4; i++)
				{
					ResolutionChoice[i].setColor(sf::Color::White);
					ResolutionChoice[i].setScale(1.0, 1.0);
				}
				SoundVolume.setColor(sf::Color::White);
				SoundVolume.setScale(1.0, 1.0);
				SoundVolumeValue.setColor(sf::Color::White);
				SoundVolumeValue.setScale(1.0, 1.0);

				Apply.setColor(sf::Color::White);
				Apply.setScale(1.0, 1.0);
				Ok.setColor(sf::Color::White);
				Ok.setScale(1.0, 1.0);
				break;
			case 1:
				Resolution.setColor(sf::Color::Red);
				Resolution.setScale(1.2, 1.2);
				for (int i = 0; i < 4; i++)
				{
					ResolutionChoice[i].setColor(sf::Color::Red);
					ResolutionChoice[i].setScale(1.2, 1.2);
				}
				SoundVolume.setColor(sf::Color::White);
				SoundVolume.setScale(1.0, 1.0);
				SoundVolumeValue.setColor(sf::Color::White);
				SoundVolumeValue.setScale(1.0, 1.0);

				Apply.setColor(sf::Color::White);
				Apply.setScale(1.0, 1.0);
				Ok.setColor(sf::Color::White);
				Ok.setScale(1.0, 1.0);
				break;
			case 2:
				Resolution.setColor(sf::Color::White);
				Resolution.setScale(1.0, 1.0);
				for (int i = 0; i < 4; i++)
				{
					ResolutionChoice[i].setColor(sf::Color::White);
					ResolutionChoice[i].setScale(1.0, 1.0);
				}
				SoundVolume.setColor(sf::Color::Red);
				SoundVolume.setScale(1.2, 1.2);
				SoundVolumeValue.setColor(sf::Color::Red);
				SoundVolumeValue.setScale(1.2, 1.2);

				Apply.setColor(sf::Color::White);
				Apply.setScale(1.0, 1.0);
				Ok.setColor(sf::Color::White);
				Ok.setScale(1.0, 1.0);
				break;
			case 3:
				Resolution.setColor(sf::Color::White);
				Resolution.setScale(1.0, 1.0);
				for (int i = 0; i < 4; i++)
				{
					ResolutionChoice[i].setColor(sf::Color::White);
					ResolutionChoice[i].setScale(1.0, 1.0);
				}
				SoundVolume.setColor(sf::Color::White);
				SoundVolume.setScale(1.0, 1.0);
				SoundVolumeValue.setColor(sf::Color::White);
				SoundVolumeValue.setScale(1.0, 1.0);

				Apply.setColor(sf::Color::White);
				Apply.setScale(1.0, 1.0);
				Ok.setColor(sf::Color::Red);
				Ok.setScale(1.2, 1.2);
				break;
			case 4:Resolution.setColor(sf::Color::White);
				Resolution.setScale(1.0, 1.0);
				for (int i = 0; i < 4; i++)
				{
					ResolutionChoice[i].setColor(sf::Color::White);
					ResolutionChoice[i].setScale(1.0, 1.0);
				}
				SoundVolume.setColor(sf::Color::White);
				SoundVolume.setScale(1.0, 1.0);
				SoundVolumeValue.setColor(sf::Color::White);
				SoundVolumeValue.setScale(1.0, 1.0);

				Apply.setColor(sf::Color::Red);
				Apply.setScale(1.2, 1.2);
				Ok.setColor(sf::Color::White);
				Ok.setScale(1.0, 1.0);
				break;
			}

			

			
			while (!(Alpha >= 255))
			{
				MenuBackground.setColor(sf::Color(255, 255, 255, Alpha));
				Resolution.setColor(sf::Color(255, 255, 255, Alpha));
				ResolutionChoice[ResoultionIndex].setColor(sf::Color(255, 255, 255, Alpha));
				SoundVolume.setColor(sf::Color(255, 255, 255, Alpha));
				SoundVolumeValue.setColor(sf::Color(255, 255, 255, Alpha));
				Apply.setColor(sf::Color(255, 255, 255, Alpha));
				Alpha += 1*OptionsIndependence.asSeconds()*MySpeed;

				GameWindow.clear();
				GameWindow.draw(MenuBackground);
				GameWindow.draw(Resolution);
				GameWindow.draw(ResolutionChoice[ResoultionIndex]);
				GameWindow.draw(SoundVolume);
				GameWindow.draw(SoundVolumeValue);
				GameWindow.draw(Apply);
				GameWindow.draw(Ok);
				GameWindow.display();
			}
			

			GameWindow.clear();
			GameWindow.draw(MenuBackground);
			GameWindow.draw(Resolution);
			GameWindow.draw(ResolutionChoice[ResoultionIndex]);
			GameWindow.draw(SoundVolume);
			GameWindow.draw(SoundVolumeValue);
			GameWindow.draw(Apply);
			GameWindow.draw(Ok);
			GameWindow.display();
		}
		
	}
	if (CallerName == "MainMenu")
	{
		Alpha = 5;
		while (!(Alpha >= 255))
		{
			MenuBackground.setColor(sf::Color(255, 255, 255, Alpha));
			Story.setColor(sf::Color(255, 255, 255, Alpha));
			Competitive.setColor(sf::Color(255, 255, 255, Alpha));
			Options.setColor(sf::Color(255, 255, 255, Alpha));
			Help.setColor(sf::Color(255, 255, 255, Alpha));
			About.setColor(sf::Color(255, 255, 255, Alpha));
			Exit.setColor(sf::Color(255, 255, 255, Alpha));

			Alpha +=  1 * Independence.asSeconds()*MySpeed;

			GameWindow.clear();
			GameWindow.draw(MenuBackground);
			GameWindow.draw(Story);
			GameWindow.draw(Competitive);
			GameWindow.draw(Options);
			GameWindow.draw(Help);
			GameWindow.draw(About);
			GameWindow.draw(Exit);
			GameWindow.display();
		}
	}
	PauseisActive = false;
}



void TheMainMenuClass::CampaignScreen(sf::RenderWindow &GameWindow)
{
	bool CampaignScreenIsActive = true;
	int CurrentScreenIndex = 1;
	
	int Alpha1 = 10, Alpha2 = 10, Alpha3 = 10, Alpha4 = 10;
	int poll = 1;
	sf::Sprite TestTank;
	
	while (GameWindow.isOpen() && CampaignScreenIsActive)
	{
		GameWindow.clear();
		GameWindow.draw(MenuBackground);
		sf::Event myevent;
		while (GameWindow.pollEvent(myevent))
		{
			switch (myevent.type)
			{
			case sf::Event::Closed:
				GameWindow.close();
				break;
				
			case sf::Event::KeyPressed:
				switch (myevent.key.code)
				{
				case sf::Keyboard::Escape:
				case sf::Keyboard::BackSpace:if (CurrentScreenIndex == 1)  { CampaignScreenIsActive = false; }
											 else  CurrentScreenIndex--;
					break;
				case sf::Keyboard::Return:
					if (CurrentScreenIndex == 4)
					{
						if (SinglePlayerOrTwoPlayers == 1)
							CurrentScreenIndex = 8;
						else if (SinglePlayerOrTwoPlayers == 2)
							CurrentScreenIndex++;
					}
					
					
					else CurrentScreenIndex++;
	
					Alpha1 = 1;
					
					
					break;
				case sf::Keyboard::Down:
					switch (CurrentScreenIndex)
					{
					case 1:
						if (SinglePlayerOrTwoPlayers != 2)SinglePlayerOrTwoPlayers++;	
						break;
					case 2:
						break;
					default:
						break;
					}
					
					break;
				case sf::Keyboard::Up:
					switch (CurrentScreenIndex)
					{
					case 1:
						if (SinglePlayerOrTwoPlayers != 1)SinglePlayerOrTwoPlayers--;
						break;
					case 2:
						
						break;
					}
					break;
				case sf::Keyboard::Right:
					if (CurrentScreenIndex == 2)	{ if (Player1ChosenTank!=9) Player1ChosenTank++; }
					if (CurrentScreenIndex == 3){ if (Player1ChosenTruck != 3)Player1ChosenTruck++; }
					if (CurrentScreenIndex == 4){ if (Player1ChosenHeli == 1) Player1ChosenHeli = 0; else Player1ChosenHeli = 1; }
					 if (CurrentScreenIndex == 5)	{ if (Player2ChosenTank != 9)Player2ChosenTank++; }
					 if (CurrentScreenIndex == 6){ if (Player2ChosenTruck != 3)Player2ChosenTruck++; }
					 if (CurrentScreenIndex == 7){ Player2ChosenHeli = 1; }
				//---------------------------------edit here^^^^^^-------------------------------------
						break;
				case sf::Keyboard::Left:
					if (CurrentScreenIndex == 2) { if (Player1ChosenTank != 1)Player1ChosenTank--; }
					 if (CurrentScreenIndex == 3){ if (Player1ChosenTruck != 1)Player1ChosenTruck--; }
					 if (CurrentScreenIndex == 4){ if (Player1ChosenHeli == 1) Player1ChosenHeli = 0; else Player1ChosenHeli = 1; }
					if (CurrentScreenIndex == 5) { if (Player2ChosenTank != 1)Player2ChosenTank--; }
					 if (CurrentScreenIndex == 6){ if (Player2ChosenTruck != 1)Player2ChosenTruck--; }
					 if (CurrentScreenIndex == 7){ Player2ChosenHeli = 0; }
					break;
						
				}

				break;
			}
				
			}
		//------end of event tracker--------------------------------------------
		

		switch (CurrentScreenIndex)
		{
		case 1:
			//-----------------------------screen1-----------------------------------------------
		{	sf::Text SinglePlayer("singleplayer", BattlefieldFont, 50);
		sf::Text TwoPlayers("2 players", BattlefieldFont, 50);
		SinglePlayer.setPosition(ScreenDimensions.x / 4, ScreenDimensions.y / 4);
		TwoPlayers.setPosition(ScreenDimensions.x / 4, ScreenDimensions.y / 4 + ScreenDimensions.y / 8);
		switch (SinglePlayerOrTwoPlayers)
		{
		case 1: SinglePlayer.setScale(1.2, 1.2);
			SinglePlayer.setColor(sf::Color::Red);
			TwoPlayers.setScale(1.0, 1.0);
			TwoPlayers.setColor(sf::Color::White);
			break;
		case 2: SinglePlayer.setScale(1.0, 1.0);
			SinglePlayer.setColor(sf::Color::White);
			TwoPlayers.setScale(1.2, 1.2);
			TwoPlayers.setColor(sf::Color::Red);
			break;
		}

		if (!(Alpha1 >= 255))
		{
			Alpha1 += 1;
			SinglePlayer.setColor(sf::Color(255, 255, 255, Alpha1));
			TwoPlayers.setColor(sf::Color(255, 255, 255, Alpha1));
		}
		GameWindow.draw(SinglePlayer);
		GameWindow.draw(TwoPlayers);

		}
			break;
			//--------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------
		case 2:
			//-----------------------------screen2--------------------------------------------------------------
		{
				  sf::Text ChooseTank;
				  if (SinglePlayerOrTwoPlayers == 1)	 ChooseTank.setString("choose Tank");
				  else   ChooseTank.setString("player one\n\nchoose Tank");
				  ChooseTank.setFont(BattlefieldFont); ChooseTank.setCharacterSize(60);
				  ChooseTank.setOrigin(ChooseTank.getLocalBounds().width / 2, ChooseTank.getLocalBounds().height / 2);
				  ChooseTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y * 0);

				  sf::Texture TestTankTexture;
				  sf::Sprite TestTankStats; sf::Texture TestTankStatsTexture;
				  switch (Player1ChosenTank)
				  {
				  case 1:
				  {
							
							TestTankTexture.loadFromFile("Data/Tank/Type1_HoneyBadger.png");
							TestTank.setTexture(TestTankTexture);
							TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height/ 2 );
							TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.25);
							TestTank.setScale(1.3, 1.3);
							GameWindow.draw(TestTank);
							TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/1.png");
							TestTankStats.setTexture(TestTankStatsTexture);
							TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
							TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
							GameWindow.draw(TestTankStats);
							
				  }
					  break;
				  case 2:
				  {
				  TestTankTexture.loadFromFile("Data/Tank/Type2_HankTheTank.png");
				  TestTank.setTexture(TestTankTexture);
				  TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				  TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3); 
				  TestTank.setScale(1.3, 1.3); GameWindow.draw(TestTank);
				  TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/2.png");
				  TestTankStats.setTexture(TestTankStatsTexture);
				  TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				  TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				  GameWindow.draw(TestTankStats);
				  }
					  break;
				  case 3:
				  {
				  TestTankTexture.loadFromFile("Data/Tank/Type3_Centurion.png");
				  TestTank.setTexture(TestTankTexture); 
				  TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				  TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
				  TestTank.setScale(1.3, 1.3); GameWindow.draw(TestTank);
				  TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/3.png");
				  TestTankStats.setTexture(TestTankStatsTexture);
				  TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				  TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				  GameWindow.draw(TestTankStats);
				  }
					  break;
				  case 4:
				  {
				  TestTankTexture.loadFromFile("Data/Tank/Type4_Crusader.png");
				  TestTank.setTexture(TestTankTexture);
				  TestTank.setScale(2, 2);
				  TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				  TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);  GameWindow.draw(TestTank);
				  TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/4.png");
				  TestTankStats.setTexture(TestTankStatsTexture);
				  TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				  TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				  GameWindow.draw(TestTankStats);
				  }
					  break;
				  case 5:
				  {
					 sf::Sprite TestTank;
				  TestTankTexture.loadFromFile("Data/Tank/Type5_Challenger.png");
				  TestTank.setTexture(TestTankTexture);
				  TestTank.setScale(0.7, 0.7);
				  TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				  TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3); TestTank.rotate(0.2); GameWindow.draw(TestTank);
				  TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/5.png");
				  TestTankStats.setTexture(TestTankStatsTexture);
				  TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				  TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				  GameWindow.draw(TestTankStats);
				  }
					  break;
				  case 6:
				  {

				  TestTankTexture.loadFromFile("Data/Tank/Type6_BlackPrince.png");
				  TestTank.setTexture(TestTankTexture);
				  TestTank.setScale(2, 2);
				  TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				  TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);  GameWindow.draw(TestTank);
				  TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/6.png");
				  TestTankStats.setTexture(TestTankStatsTexture);
				  TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				  TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				  GameWindow.draw(TestTankStats);
				  }
					  break;

				  case 7:
				  {
				  TestTankTexture.loadFromFile("Data/Tank/Type7_DreadNaught.png");
				  TestTank.setTexture(TestTankTexture);
				  TestTank.setScale(1.3, 1.3);
				  TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				  TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3); GameWindow.draw(TestTank);
				  TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/7.png");
				  TestTankStats.setTexture(TestTankStatsTexture);
				  TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				  TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				  GameWindow.draw(TestTankStats);
				 
				  }
					  break;
				  case 8:
				  {
				  TestTankTexture.loadFromFile("Data/Tank/Type8_Juggernaut.png");
				  TestTank.setTexture(TestTankTexture);
				  TestTank.setScale(1.3, 1.3);
				  TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				  TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3); GameWindow.draw(TestTank);
				  TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/8.png");
				  TestTankStats.setTexture(TestTankStatsTexture);
				  TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				  TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				  GameWindow.draw(TestTankStats);
				  }
					  break;
				  case 9:
				  {
				  TestTankTexture.loadFromFile("Data/Tank/Type9_Type80.png");
				  TestTank.setTexture(TestTankTexture);
				  TestTank.setScale(1.3, 1.3);
				  TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				  TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3); GameWindow.draw(TestTank);
				  TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/9.png");
				  TestTankStats.setTexture(TestTankStatsTexture);
				  TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				  TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				  GameWindow.draw(TestTankStats);
				  }
					  break;

				  }



				  
					  if (!(Alpha1 >= 255))
					  {
						  Alpha1 += 1;
						  ChooseTank.setColor(sf::Color(255, 255, 255, Alpha1));
					  }

					  GameWindow.draw(ChooseTank);
				  
		}
			break;
		case 3:
		{//-------------------------truck---------------------------------------------
			sf::Text ChooseTruck;
			if (SinglePlayerOrTwoPlayers == 1)	 ChooseTruck.setString("choose vehicle");
			else   ChooseTruck.setString("player one\n\nchoose vehicle");
			ChooseTruck.setFont(BattlefieldFont); ChooseTruck.setCharacterSize(60);
			ChooseTruck.setOrigin(ChooseTruck.getLocalBounds().width / 2, ChooseTruck.getLocalBounds().height / 2);
			ChooseTruck.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.1);

			sf::Sprite TestTank; sf::Texture TestTankTexture;
			sf::Sprite TestTankStats; sf::Texture TestTankStatsTexture;
			switch (Player1ChosenTruck)
			{
			case 1:
			{

				TestTankTexture.loadFromFile("Data/Textures/Truck/Car.png");
				TestTank.setTexture(TestTankTexture);
				TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
				TestTank.setScale(1.3, 1.3);
				GameWindow.draw(TestTank);
				TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TruckProfiles/C1.png");
				TestTankStats.setTexture(TestTankStatsTexture);
				TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				GameWindow.draw(TestTankStats);

			}
				break;
			case 2:
			{
				TestTankTexture.loadFromFile("Data/Textures/Truck/Car2.png");
				TestTank.setTexture(TestTankTexture);
				TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
				TestTank.setScale(1.3, 1.3); GameWindow.draw(TestTank);
				TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TruckProfiles/C2.png");
				TestTankStats.setTexture(TestTankStatsTexture);
				TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				GameWindow.draw(TestTankStats);
			}
				break;
			case 3:
			{
				TestTankTexture.loadFromFile("Data/Textures/Truck/Truck.png");
				TestTank.setTexture(TestTankTexture);
				TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
				TestTank.setScale(1.3, 1.3); GameWindow.draw(TestTank);
				TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TruckProfiles/C3.png");
				TestTankStats.setTexture(TestTankStatsTexture);
				TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				GameWindow.draw(TestTankStats);
			}
				break;
			}
			GameWindow.draw(ChooseTruck);
		}
			break;
		case 6:
		{//-------------------------truck---------------------------------------------
			sf::Text ChooseTruck;
		  ChooseTruck.setString("player two\n\nchoose vehicle");
			ChooseTruck.setFont(BattlefieldFont); ChooseTruck.setCharacterSize(60);
			ChooseTruck.setOrigin(ChooseTruck.getLocalBounds().width / 2, ChooseTruck.getLocalBounds().height / 2);
			ChooseTruck.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.1);

			sf::Sprite TestTank; sf::Texture TestTankTexture;
			sf::Sprite TestTankStats; sf::Texture TestTankStatsTexture;
			switch (Player2ChosenTruck)
			{
			case 1:
			{

				TestTankTexture.loadFromFile("Data/Textures/Truck/Car.png");
				TestTank.setTexture(TestTankTexture);
				TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
				TestTank.setScale(1.3, 1.3);
				GameWindow.draw(TestTank);
				TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TruckProfiles/C1.png");
				TestTankStats.setTexture(TestTankStatsTexture);
				TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				GameWindow.draw(TestTankStats);

			}
				break;
			case 2:
			{
				TestTankTexture.loadFromFile("Data/Textures/Truck/Car2.png");
				TestTank.setTexture(TestTankTexture);
				TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
				TestTank.setScale(1.3, 1.3); GameWindow.draw(TestTank);
				TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TruckProfiles/C2.png");
				TestTankStats.setTexture(TestTankStatsTexture);
				TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				GameWindow.draw(TestTankStats);
			}
				break;
			case 3:
			{
				TestTankTexture.loadFromFile("Data/Textures/Truck/Truck.png");
				TestTank.setTexture(TestTankTexture);
				TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
				TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
				TestTank.setScale(1.3, 1.3); GameWindow.draw(TestTank);
				TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TruckProfiles/C3.png");
				TestTankStats.setTexture(TestTankStatsTexture);
				TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
				TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
				GameWindow.draw(TestTankStats);
			}
				break;
			}
			GameWindow.draw(ChooseTruck);
		}
			break;
			//---------------------------------------------------------------------------------------------------
			case 5:
			{
				 if (SinglePlayerOrTwoPlayers == 2)
				 {

					 sf::Text ChooseTank;
					 ChooseTank.setString("player two\n\nchoose Tank");
					 ChooseTank.setFont(BattlefieldFont); ChooseTank.setCharacterSize(60);
					 ChooseTank.setOrigin(ChooseTank.getLocalBounds().width / 2, ChooseTank.getLocalBounds().height / 2);
					 ChooseTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.1);
					 sf::Sprite TestTank; sf::Texture TestTankTexture;
					 sf::Sprite TestTankStats; sf::Texture TestTankStatsTexture;
					 switch (Player2ChosenTank)
					 {
					 case 1:
					 {

						 TestTankTexture.loadFromFile("Data/Tank/Type1_HoneyBadger.png");
						 TestTank.setTexture(TestTankTexture);
						 TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
						 TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
						 TestTank.setScale(1.3, 1.3);
						 GameWindow.draw(TestTank);
						 TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/1.png");
						 TestTankStats.setTexture(TestTankStatsTexture);
						 TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
						 TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
						 GameWindow.draw(TestTankStats);

					 }
						 break;
					 case 2:
					 {
						 TestTankTexture.loadFromFile("Data/Tank/Type2_HankTheTank.png");
						 TestTank.setTexture(TestTankTexture);
						 TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
						 TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
						 TestTank.setScale(1.3, 1.3); GameWindow.draw(TestTank);
						 TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/2.png");
						 TestTankStats.setTexture(TestTankStatsTexture);
						 TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
						 TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
						 GameWindow.draw(TestTankStats);
					 }
						 break;
					 case 3:
					 {
						 TestTankTexture.loadFromFile("Data/Tank/Type3_Centurion.png");
						 TestTank.setTexture(TestTankTexture);
						 TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
						 TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
						 TestTank.setScale(1.3, 1.3); GameWindow.draw(TestTank);
						 TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/3.png");
						 TestTankStats.setTexture(TestTankStatsTexture);
						 TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
						 TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
						 GameWindow.draw(TestTankStats);
					 }
						 break;
					 case 4:
					 {
						 TestTankTexture.loadFromFile("Data/Tank/Type4_Crusader.png");
						 TestTank.setTexture(TestTankTexture);
						 TestTank.scale(2, 2);
						 TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
						 TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);  GameWindow.draw(TestTank);
						 TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/4.png");
						 TestTankStats.setTexture(TestTankStatsTexture);
						 TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
						 TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
						 GameWindow.draw(TestTankStats);
					 }
						 break;
					 case 5:
					 {
						 TestTankTexture.loadFromFile("Data/Tank/Type5_Challenger.png");
						 TestTank.setTexture(TestTankTexture);
						 // TestTank.scale(2, 2);
						 TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
						 TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);  GameWindow.draw(TestTank);
						 TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/5.png");
						 TestTankStats.setTexture(TestTankStatsTexture);
						 TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
						 TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
						 GameWindow.draw(TestTankStats);
					 }
						 break;
					 case 6:
					 {

						 TestTankTexture.loadFromFile("Data/Tank/Type6_BlackPrince.png");
						 TestTank.setTexture(TestTankTexture);
						 TestTank.scale(2, 2);
						 TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
						 TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);  GameWindow.draw(TestTank);
						 TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/6.png");
						 TestTankStats.setTexture(TestTankStatsTexture);
						 TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
						 TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
						 GameWindow.draw(TestTankStats);
					 }
						 break;

					 case 7:
					 {
						 TestTankTexture.loadFromFile("Data/Tank/Type7_DreadNaught.png");
						 TestTank.setTexture(TestTankTexture);
						 TestTank.scale(1.3, 1.3);
						 TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
						 TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3); GameWindow.draw(TestTank);
						 TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/7.png");
						 TestTankStats.setTexture(TestTankStatsTexture);
						 TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
						 TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
						 GameWindow.draw(TestTankStats);

					 }
						 break;
					 case 8:
					 {
						 TestTankTexture.loadFromFile("Data/Tank/Type8_Juggernaut.png");
						 TestTank.setTexture(TestTankTexture);
						 TestTank.scale(1.3, 1.3);
						 TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
						 TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3); GameWindow.draw(TestTank);
						 TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/8.png");
						 TestTankStats.setTexture(TestTankStatsTexture);
						 TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
						 TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
						 GameWindow.draw(TestTankStats);
					 }
						 break;
					 case 9:
					 {
						 TestTankTexture.loadFromFile("Data/Tank/Type9_Type80.png");
						 TestTank.setTexture(TestTankTexture);
						 TestTank.scale(1.3, 1.3);
						 TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
						 TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3); GameWindow.draw(TestTank);
						 TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/TankProfiles/9.png");
						 TestTankStats.setTexture(TestTankStatsTexture);
						 TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
						 TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
						 GameWindow.draw(TestTankStats);
					 }
						 break;

					 }
					 if (!(Alpha1 >= 255))
					 {
						 Alpha1 += 1;
						 ChooseTank.setColor(sf::Color(255, 255, 255, Alpha1));
					 }

					 GameWindow.draw(ChooseTank);
				 }
					 



			}
				break;
				//--------------------------------------------------------------------------------------------------------------
				case 4:
				{

				sf::Text ChooseTruck;
				if (SinglePlayerOrTwoPlayers == 1)	 ChooseTruck.setString("choose helicopter");
				else   ChooseTruck.setString("player one\n\nchoose helicopter");
				ChooseTruck.setFont(BattlefieldFont); ChooseTruck.setCharacterSize(60);
				ChooseTruck.setOrigin(ChooseTruck.getLocalBounds().width / 2, ChooseTruck.getLocalBounds().height / 2);
				ChooseTruck.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 8.5);

				sf::Sprite TestTank; sf::Texture TestTankTexture;
				sf::Sprite TestTankStats; sf::Texture TestTankStatsTexture;
				switch (Player1ChosenHeli)
				{
				case 0:
				{

					TestTankTexture.loadFromFile("Data/Textures/Heli/Heli1.png");
					TestTank.setTexture(TestTankTexture);
					TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
					TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
					TestTank.setScale(0.5, 0.5);
					GameWindow.draw(TestTank);
					TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/HeliProfiles/H1.png");
					TestTankStats.setTexture(TestTankStatsTexture);
					TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
					TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
					GameWindow.draw(TestTankStats);

				}
					break;
				case 1:
				{
					TestTankTexture.loadFromFile("Data/Textures/Heli/Heli2.png");
					TestTank.setTexture(TestTankTexture);
					TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
					TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
				 GameWindow.draw(TestTank);
					TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/HeliProfiles/H2.png");
					TestTankStats.setTexture(TestTankStatsTexture);
					TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
					TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
					GameWindow.draw(TestTankStats);
				}
					break;
			
				}
				GameWindow.draw(ChooseTruck);
		}
		break;
				case 7:
				{

					sf::Text ChooseTruck;
					ChooseTruck.setString("player two\n\nchoose helicopter");
					ChooseTruck.setFont(BattlefieldFont); ChooseTruck.setCharacterSize(60);
					ChooseTruck.setOrigin(ChooseTruck.getLocalBounds().width / 2, ChooseTruck.getLocalBounds().height / 2);
					ChooseTruck.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 8.5);

					sf::Sprite TestTank; sf::Texture TestTankTexture;
					sf::Sprite TestTankStats; sf::Texture TestTankStatsTexture;
					switch (Player2ChosenHeli)
					{
					case 0:
					{

						TestTankTexture.loadFromFile("Data/Textures/Heli/Heli1.png");
						TestTank.setTexture(TestTankTexture);
						TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
						TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
						TestTank.setScale(0.5, 0.5);
						GameWindow.draw(TestTank);
						TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/HeliProfiles/H1.png");
						TestTankStats.setTexture(TestTankStatsTexture);
						TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
						TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
						GameWindow.draw(TestTankStats);

					}
						break;
					case 1:
					{
						TestTankTexture.loadFromFile("Data/Textures/Heli/Heli2.png");
						TestTank.setTexture(TestTankTexture);
						TestTank.setOrigin(TestTank.getLocalBounds().width / 2, TestTank.getLocalBounds().height / 2);
						TestTank.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
						TestTank.setScale(1.3, 1.3); GameWindow.draw(TestTank);
						TestTankStatsTexture.loadFromFile("Data/Textures/MainMenu/HeliProfiles/H2.png");
						TestTankStats.setTexture(TestTankStatsTexture);
						TestTankStats.setOrigin(TestTankStats.getLocalBounds().width / 2, TestTankStats.getLocalBounds().height / 2);
						TestTankStats.setPosition(ScreenDimensions.x*0.5, ScreenDimensions.y *0.6);
						GameWindow.draw(TestTankStats);
					}
						break;

					}
					GameWindow.draw(ChooseTruck);
				}
					break;
			case 8:
			{
					  sf::Sprite ShowControls;
					  sf::Texture ShowControlsTexture;
					  if (SinglePlayerOrTwoPlayers == 1) ShowControlsTexture.loadFromFile("Data/Textures/MainMenu/PauseScreenTexture.jpg");
					  else 	ShowControlsTexture.loadFromFile("Data/Textures/MainMenu/PauseScreenTexture.jpg");
					  ShowControls.setTexture(ShowControlsTexture);
					  ShowControls.setScale(ScreenDimensions.x / ShowControls.getLocalBounds().width, ScreenDimensions.y / ShowControls.getLocalBounds().height);
					  GameWindow.draw(ShowControls);
					  sf::Text PressEnter("press enter to continue", BattlefieldFont, 50);
					  PressEnter.setOrigin(PressEnter.getLocalBounds().width / 2, PressEnter.getLocalBounds().height / 2);
					  PressEnter.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.75);
					  
					  sf::Clock clock2;
					  sf::Time Independence2;
					  
					  while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))))
					  {
						  if (Alpha1 >= 255)
						  { 
							  PositiveORNegative = -1;
						  }
						  else if (Alpha1 < 20)
						  {
							  PositiveORNegative = 1;
						  }
						  Alpha1 += 1 * PositiveORNegative*Independence2.asSeconds()*470;
						  
						  PressEnter.setColor(sf::Color(255, 255, 255, Alpha1));
						  GameWindow.clear();
						  GameWindow.draw(ShowControls);
						  GameWindow.draw(PressEnter);
						  GameWindow.display();
						  Independence2 = clock2.getElapsedTime();
						  clock2.restart().asSeconds();

					  }

					  
			}
				break;
			case 9: CampaignScreenIsActive = false;
				CampaignIsActive = true;
				return;
				break;
		}
		//std::cout << CurrentScreenIndex<<"   "<< SinglePlayerOrTwoPlayers << "   " << ChosenDifficulty << "   " << Player1ChosenTank<<"    " <<Player2ChosenTank  << std::endl;
		
		
	
		TestTank.rotate(0.3);
		GameWindow.display();

	}



	//back;
	Alpha = 5;
	while (!(Alpha >= 255))
	{
		MenuBackground.setColor(sf::Color(255, 255, 255, Alpha));
		Story.setColor(sf::Color(255, 255, 255, Alpha));
		Competitive.setColor(sf::Color(255, 255, 255, Alpha));
		Options.setColor(sf::Color(255, 255, 255, Alpha));
		Help.setColor(sf::Color(255, 255, 255, Alpha));
		About.setColor(sf::Color(255, 255, 255, Alpha));
		Exit.setColor(sf::Color(255, 255, 255, Alpha));

		Alpha += 1 * Independence.asSeconds()*MySpeed;

		GameWindow.clear();
		GameWindow.draw(MenuBackground);
		GameWindow.draw(Story);
		GameWindow.draw(Competitive);
		GameWindow.draw(Options);
		GameWindow.draw(Help);
		GameWindow.draw(About);
		GameWindow.draw(Exit);
		GameWindow.display();
	}
}

struct PlayerChoices TheMainMenuClass::GetCampaignValues()
{

	PlayerChoices PlayerChoice;
	PlayerChoice.SinglePlayerOrTwoPlayers = SinglePlayerOrTwoPlayers;
	switch (Player1ChosenTank)
	{
	case 1:		PlayerChoice.Player1ChosenTank = HoneyBadger;
		break;
	case 2:		PlayerChoice.Player1ChosenTank = HankTheTank;
		break;
	case 3:		PlayerChoice.Player1ChosenTank = Centurion;
		break;
	case 4:		PlayerChoice.Player1ChosenTank = Crusader;
		break;
	case 5:		PlayerChoice.Player1ChosenTank = Challenger;
		break;
	case 6:		PlayerChoice.Player1ChosenTank = BlackPrince;
		break;
	case 7:PlayerChoice.Player1ChosenTank = Dreadnaught;
		break;
	case 8:PlayerChoice.Player1ChosenTank = Juggernaut;
		break;
	case 9:PlayerChoice.Player1ChosenTank = Type80;
		break;
	}

	switch (Player2ChosenTank)
	{
	case 1:		PlayerChoice.Player2ChosenTank = HoneyBadger;
		break;
	case 2:		PlayerChoice.Player2ChosenTank = HankTheTank;
		break;
	case 3:		PlayerChoice.Player2ChosenTank = Centurion;
		break;
	case 4:		PlayerChoice.Player2ChosenTank = Crusader;
		break;
	case 5:		PlayerChoice.Player2ChosenTank = Challenger;
		break;
	case 6:		PlayerChoice.Player2ChosenTank = BlackPrince;
		break;
	case 7:PlayerChoice.Player2ChosenTank = Dreadnaught;
		break;
	case 8:PlayerChoice.Player2ChosenTank = Juggernaut;
		break;
	case 9:PlayerChoice.Player2ChosenTank = Type80;
		break;

	}
	
	switch (Player1ChosenTruck)
	{
	case 1:PlayerChoice.Player1ChosenTruck = Car1; break;
	case 2:PlayerChoice.Player1ChosenTruck = Car2; break;
	case 3:PlayerChoice.Player1ChosenTruck = ArmyTruck; break;
	default:
		break;
	}
	switch (Player2ChosenTruck)
	{
	case 1:PlayerChoice.Player2ChosenTruck = Car1; break;
	case 2:PlayerChoice.Player2ChosenTruck = Car2; break;
	case 3:PlayerChoice.Player2ChosenTruck = ArmyTruck; break;
	default:
		break;
	}
	switch (Player1ChosenHeli)
	{
	case 1:PlayerChoice.Player1ChosenHeli = Hunter; break;
	case 0:PlayerChoice.Player1ChosenHeli = Apache; break;
	default:
		break;
	}
	switch (Player2ChosenHeli)
	{
	case 1:PlayerChoice.Player2ChosenHeli = Apache;
	case 2:PlayerChoice.Player2ChosenHeli = Hunter;
	default:
		break;
	}
	PlayerChoice.CampaignORSurvival = CampaignOrSurvival;

	return PlayerChoice;
}