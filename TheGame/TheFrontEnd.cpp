#include "TheFrontEnd.h"
#include <stdlib.h>
#include <random>


sf::Time Independence;
sf::Sprite LoadingScreen;
sf::Texture LoadingScreenTexture;
int GameIsActive;
int Pause = 0;
bool Pauseactive;
int CheckPoint;
bool InitialiseDelay;
sf::Clock ObjectiveTimer;
sf::Text CurObjective;
sf::Text DistanceRemaining;
sf::Sprite Arrow; sf::Texture ArrowTexture;
float ToReach;
int Integer;


void FrontEnd(PlayerChoices PlayerChoice)
{

	sf::Clock clock;
	LoadingScreenTexture.loadFromFile("Data/Misc/LoadingScreen.jpg");
	LoadingScreen.setTexture(LoadingScreenTexture);
	LoadingScreen.setScale(ScreenDimensions.x / LoadingScreen.getLocalBounds().width, ScreenDimensions.y / LoadingScreen.getLocalBounds().height);

	GameWindow.clear();
	GameWindow.draw(LoadingScreen);
	GameWindow.display();
	
	OperationInitialiser();
	BattlefieldFont.loadFromFile("Data/Fonts/BattlefieldFont.ttf");
	CheckPoint = 0;
	InitialiseDelay = 0;
	CurObjective.setFont(BattlefieldFont); CurObjective.setCharacterSize(30); CurObjective.setColor(sf::Color::Green);
	//DistanceRemaining.setFont(BattlefieldFont); DistanceRemaining.setCharacterSize(24); DistanceRemaining.setColor(sf::Color::Green);
	CurObjective.setString("Get to the Enemy Base!");
	DistanceRemaining.setOrigin(DistanceRemaining.getLocalBounds().width *0.14, DistanceRemaining.getLocalBounds().height / 2);
	CurObjective.setOrigin(CurObjective.getLocalBounds().width / 2, CurObjective.getLocalBounds().height / 2);
	Freedom = sf::seconds(0.0001);
	ArrowTexture.loadFromFile("Data/Misc/Arrow.png"); Arrow.setTexture(ArrowTexture);
	Arrow.setOrigin(Arrow.getLocalBounds().width / 2, Arrow.getLocalBounds().height / 2);
	

	//positioninIndicator text---------
	sf::Text Xa; sf::Text Ya; Xa.setFont(BattlefieldFont); Xa.setCharacterSize(20); Ya.setFont(BattlefieldFont); Ya.setCharacterSize(20);

	sf::Sprite ShedHouse, RustyTruck, PalmTree;
	sf::Texture ShedHouseTexture, RustyTruckTexture, PalmTreeTexture;
	ShedHouseTexture.loadFromFile("Data/Objects/ShedHouse.png");
	RustyTruckTexture.loadFromFile("Data/Objects/RustyTruck.png");
	PalmTreeTexture.loadFromFile("Data/Objects/PalmTree.png");
	ShedHouse.setTexture(ShedHouseTexture);
	RustyTruck.setTexture(RustyTruckTexture);
	PalmTree.setTexture(PalmTreeTexture);

	TheVehicleClass *Player = new TheTruckClass(PlayerChoice.Player1ChosenTruck);
	TheVehicleClass *TruckPlayer = new TheTruckClass(PlayerChoice.Player1ChosenTruck);
	TheVehicleClass *TankPlayer = new TheTankClass(PlayerChoice.Player1ChosenTank);
	TheVehicleClass *HeliPlayer = new TheHeliClass(PlayerChoice.Player1ChosenHeli);

	GameIsActive = 1;
	clock.restart().asSeconds();
	AIManager Enemies;
	AIManager Players(AI);
	Players.AddToList(Player);
	sf::Vector2f LastCheckpointPosition;
	int PlayerLives = 3;
	sf::Clock GameOverTimer; bool GameOver = false;
	TheVehicleClass *RefEnemy = new TheAITank;
	bool Victory = false;
	//-----------------------------------------THEMAINLOOP-----------------------------------------------
	while (GameWindow.isOpen()&&GameIsActive)
	{
		
		
		GameWindow.clear();
		sf::Event GameEvent;
	
		while (GameWindow.pollEvent(GameEvent))
		{
		switch (GameEvent.type)
			{
			case sf::Event::Closed:	GameWindow.close(); break;
			case sf::Event::KeyPressed:
				switch (GameEvent.key.code)
				{
				case sf::Keyboard::Escape:
					if (Pause == 0) Pause = 1;
					else Pause = 0;
				 
				}
				break;	
			case sf::Event::MouseWheelMoved:
				sf::Vector2f temppos; float temprot;
				temppos = Player->TheVehicle.getPosition(); temprot = Player->TheVehicle.getRotation();

				if ((GameEvent.mouseWheel.delta > 0))
				{
					switch (PlayerVehicle::CurrentVehicle_)
					{
					case Truck:Player->TheVehicleMoveSound.stop(); Player = TankPlayer; PlayerVehicle::CurrentVehicle_ = Tank;
						break;
					case Tank:Player->TheVehicleMoveSound.stop();  Player = HeliPlayer; PlayerVehicle::CurrentVehicle_ = Heli;
						break;
					case Heli:Player->TheVehicleMoveSound.stop(); Player = TruckPlayer; PlayerVehicle::CurrentVehicle_ = Truck;
						break;
					}
				}
				else
				{
					switch (PlayerVehicle::CurrentVehicle_)
					{
					case 0:Player->TheVehicleMoveSound.stop();  Player = HeliPlayer; PlayerVehicle::CurrentVehicle_ = Heli;
						break;
					case 1:Player->TheVehicleMoveSound.stop();  Player = TruckPlayer; PlayerVehicle::CurrentVehicle_ = Truck;
						break;
					case 2:Player->TheVehicleMoveSound.stop(); Player = TankPlayer; PlayerVehicle::CurrentVehicle_ = Tank;
						break;
					}
				}
				Player->TheVehicle.setPosition(temppos); Player->TheVehicle.setRotation(temprot);
				Players.AIlist.pop_front();
				Players.AIlist.push_front(Player);
			}
		}
		
	
		if (Pause!=0)
		{
			PauseMenu();
			Pause = 0;
			Freedom = sf::seconds(0.0000000001);
			clock.restart().asSeconds();
		}
		//-----PUT  Functions    HERE--------------------
		else
		{
			ReverseLock(Players.AIlist.front()->TheVehicle, 0);
			ViewLock(0, 0, 1, 1);
			BackHandler(GameWindow, Players.AIlist.front()->TheVehicle);
			switch (CheckPoint)
			{
		
			case 0:
				Player->TheVehicle.setPosition(ScreenDimensions.x/2, ScreenDimensions.y/2);
				WorldBounds[0].setPosition(0, Player->TheVehicle.getPosition().y + 300);
				WorldBounds[1].setPosition(0, Player->TheVehicle.getPosition().y - 25000);
				ShedHouse.setPosition(ScreenDimensions.x*0.75, ScreenDimensions.y*0.3);
				PalmTree.setPosition(ScreenDimensions.x*0.67, ScreenDimensions.y*0.2);
				RustyTruck.setPosition(ScreenDimensions.x*0.7, ScreenDimensions.y*0.4);
				LastCheckpointPosition = Player->TheVehicle.getPosition();
				Players.CreateAIUpTank(Players.AIlist.front()->TheVehicle.getPosition(),2);
				MusicLoader();
				CheckPoint++;
				break;
			case 1: 
			
				GameWindow.draw(ShedHouse);
				GameWindow.draw(RustyTruck);
				GameWindow.draw(PalmTree);
				
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					CheckPoint++; Enemies.CreateAIUpTank(Players.AIlist.front()->TheVehicle.getPosition()); LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
				break;
			case 2:
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					CheckPoint++; Enemies.CreateAIUpTank(Players.AIlist.front()->TheVehicle.getPosition(),2); clock.restart().asSeconds();LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}	
				break;
			case 3:
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					CheckPoint++; Enemies.CreateAIUpTank(Players.AIlist.front()->TheVehicle.getPosition(), 4); clock.restart().asSeconds(); LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
				break;
			case 4:
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					CheckPoint++; Enemies.CreateAIUpTank(Players.AIlist.front()->TheVehicle.getPosition(), 2); 
					Enemies.CreateAIUpHeli(Players.AIlist.front()->TheVehicle.getPosition(), 2); clock.restart().asSeconds();; LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
				break;
			case 5:
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					CheckPoint++; Players.CreateAIUpTank(Players.AIlist.front()->TheVehicle.getPosition(), 2);
					Players.CreateAIUpHeli(Players.AIlist.front()->TheVehicle.getPosition()); clock.restart().asSeconds();; LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
				break;
			case 6:


				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					CheckPoint++; Enemies.CreateAIUpTurret(Players.AIlist.front()->TheVehicle.getPosition(), 4); clock.restart().asSeconds();; LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
				break;
			case 7:
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					CheckPoint++; Enemies.CreateAIUpHeli(Players.AIlist.front()->TheVehicle.getPosition(), 3); 
					clock.restart().asSeconds(); LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
				break;
			case 8:if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
			{
				CheckPoint++; Enemies.CreateAIUpHeli(Players.AIlist.front()->TheVehicle.getPosition(), 1);
				Enemies.CreateAIUpTank(Players.AIlist.front()->TheVehicle.getPosition(), 4);
				clock.restart().asSeconds(); LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
			}
				break;
			case 9:
				
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					MusicLoader();
					CheckPoint++; Players.CreateAIUpTank(Players.AIlist.front()->TheVehicle.getPosition(), 5);
					clock.restart().asSeconds(); LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
				break;
			case 10: if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
			{
				CheckPoint++; Enemies.CreateAIUpTurret(Players.AIlist.front()->TheVehicle.getPosition(), 12);
				clock.restart().asSeconds(); LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
			}
				 break;
			case 11:
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					CheckPoint++; Enemies.CreateAIUpTurret(Players.AIlist.front()->TheVehicle.getPosition(), 12);
					clock.restart().asSeconds();; LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}

			case 12:
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					CheckPoint++; Players.CreateAIUpHeli(Players.AIlist.front()->TheVehicle.getPosition(),4);
					clock.restart().asSeconds(); LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
				break;

			case 13:
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					MusicLoader();
					CheckPoint++; Enemies.CreateAIUpTank(Players.AIlist.front()->TheVehicle.getPosition(), 10);
					Enemies.CreateAIUpHeli(Players.AIlist.front()->TheVehicle.getPosition(), 4);
					clock.restart().asSeconds();; LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
			case 14:
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					CheckPoint++; Enemies.CreateAIUpTurret(Players.AIlist.front()->TheVehicle.getPosition(), 15);
					clock.restart().asSeconds();; LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
				break;
			case 15:
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					CheckPoint++; Enemies.CreateAIUpTank(Players.AIlist.front()->TheVehicle.getPosition(), 1);
					clock.restart().asSeconds();; LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
				break;
			case 16:if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
			{
				MusicLoader();
				CheckPoint++; Enemies.AIlist.clear();
				Enemies.CreateAIUpTank(Players.AIlist.front()->TheVehicle.getPosition(), 1);
				Enemies.AIlist.front()->ScaleVehicle(4);
				Enemies.AIlist.front()->Projectile[0]->TheProjectile.scale(4, 4);
				Enemies.AIlist.front()->sethealth(700);
				Enemies.AIlist.front()->Projectile[0]->FreedomSpeed *= 0.7;
				clock.restart().asSeconds();; LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
			}
					break;

			case 17:
				if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
				{
					MusicLoader();
					CheckPoint++; Enemies.AIlist.clear();
					Enemies.CreateAIUpHeli(Players.AIlist.front()->TheVehicle.getPosition(), 1);
					Enemies.AIlist.front()->ScaleVehicle(2);
					Enemies.AIlist.front()->Projectile[0]->TheProjectile.scale(2, 2);
					Enemies.AIlist.front()->sethealth(1500);
					Enemies.AIlist.front()->Projectile[0]->FreedomSpeed *= 0.7;
					clock.restart().asSeconds();; LastCheckpointPosition = Players.AIlist.front()->TheVehicle.getPosition();
				}
				break;
			case 18:if (Players.AIlist.front()->TheVehicle.getPosition().y < LastCheckpointPosition.y - 1500)
			{
				GameIsActive = false; Victory = true;
			}
			}
			Enemies.TheAIManager(Players);

			Players.TheAIManager(Enemies);
				DispObjective();
				if (PlayerVehicle::PlayerHealth < 10)
				{
					if (PlayerLives>1)
					{
						PlayerLives--; PlayerVehicle::PlayerHealth = 100; Players.AIlist.front()->VehicleIsAlive = true;
					}
					if (PlayerVehicle::PlayerHealth < 1 && GameOver == false){
						GameOverTimer.restart().asSeconds(); GameOver = true; CurObjective.setString("game over");
					}
					if (GameOver == true)
					{
						GameWindow.draw(CurObjective);
						if (GameOverTimer.getElapsedTime().asSeconds() > 6)GameIsActive = false;
					}

				}
				
			

			GameWindow.display();
			Freedom = clock.getElapsedTime();
			clock.restart().asSeconds();
		}
	}
	delete Player;
	TankPlayer->TheVehicleMoveSound.stop();
	HeliPlayer->TheVehicleMoveSound.stop();
	TruckPlayer->TheVehicleMoveSound.stop();
	GameView.reset(sf::FloatRect(0, 0, ScreenDimensions.x, ScreenDimensions.y));
	GameWindow.setView(GameView);
	if (Victory)
	{
		sf::Clock clk;
		sf::Sprite Win; sf::Texture WinTexture; WinTexture.loadFromFile("Data/Textures/Win.png");
		Win.setTexture(WinTexture); Win.setScale(ScreenDimensions.x / Win.getLocalBounds().width, ScreenDimensions.y / Win.getGlobalBounds().height);
		GameWindow.clear();  GameWindow.draw(Win); GameWindow.display();
		MusicLoader(1);
		while (clk.getElapsedTime().asSeconds() < 5);
	}
	
	
	//delete TankPlayer;
	//delete HeliPlayer;
	//delete TruckPlayer;
	
	//return bak to menu
	
	

}

void Survival(PlayerChoices PlayerChoice)
{

	sf::Clock clock;
	LoadingScreenTexture.loadFromFile("Data/Misc/LoadingScreen.jpg");
	LoadingScreen.setTexture(LoadingScreenTexture);
	LoadingScreen.setScale(ScreenDimensions.x / LoadingScreen.getLocalBounds().width, ScreenDimensions.y / LoadingScreen.getLocalBounds().height);

	GameWindow.clear();
	GameWindow.draw(LoadingScreen);
	GameWindow.display();

	OperationInitialiser();
	BattlefieldFont.loadFromFile("Data/Fonts/BattlefieldFont.ttf");
	

	CheckPoint = 0;
	InitialiseDelay = 0;
	
	Freedom = sf::seconds(0.0001);
	
	
	TheVehicleClass *Player = new TheTruckClass(PlayerChoice.Player1ChosenTruck);
	TheVehicleClass *TruckPlayer = new TheTruckClass(PlayerChoice.Player1ChosenTruck);
	TheVehicleClass *TankPlayer = new TheTankClass(PlayerChoice.Player1ChosenTank);
	TheVehicleClass *HeliPlayer = new TheHeliClass(PlayerChoice.Player1ChosenHeli);
	
	GameIsActive = 1;
	
	sf::Sprite *Background=new sf::Sprite; sf::Texture BackgroundTexture;
	BackgroundTexture.loadFromFile("Data/Textures/Survival/SurvivalTexture.jpg");
	//Background.setTexture(BackgroundTexture);
	//Background.setScale(ScreenDimensions.x / Background.getLocalBounds().width, ScreenDimensions.y / Background.getGlobalBounds().height);
	//Background.scale(1.2, 1.2);  Background.move(0, -ScreenDimensions.y * 0.2);
	srand(time(NULL));
	
	sf::Sprite Survive; sf::Texture SurviveTexture; SurviveTexture.loadFromFile("Data/textures/Survival/SurvivalSurvive.png");
	Survive.setTexture(SurviveTexture); Survive.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2); Survive.move(ScreenDimensions.x*0.1, 0);
	Survive.setOrigin(Survive.getLocalBounds().width / 2, Survive.getLocalBounds().height / 2);
	Survive.move(0, ScreenDimensions.y*0.3);
	CurObjective.setFont(BattlefieldFont); CurObjective.setCharacterSize(80); CurObjective.setColor(sf::Color::Red);
	CurObjective.setString("Round");
	CurObjective.setOrigin(CurObjective.getLocalBounds().width / 2, CurObjective.getLocalBounds().height / 2);
	CurObjective.setPosition(Survive.getPosition().x, Survive.getPosition().y - ScreenDimensions.y*0.3);


	
	clock.restart().asSeconds(); 

	//sf::Sound RoundSound_; sf::SoundBuffer RoundSoundBuffer_; RoundSoundBuffer_.loadFromFile("Data/Sound/R1.ogg"); RoundSound_.setBuffer(RoundSoundBuffer_);
	//BattleCityOST.play();
	MusicLoader();
	 
	Player->TheVehicle.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);

	
	AIManager Enemies;
	AIManager Players(AI);
	PowerupManager PowerManager(&Players,&Enemies);
	
	sf::Clock RoundClock;
	sf::Clock GameOverTimer; bool GameOver = false;
	BackGroundLoader(1 + rand() % 7, Background, BackgroundTexture);

	//-----------------------------------------THEMAINLOOP-----------------------------------------------
	while (GameWindow.isOpen() && GameIsActive)
	{
		
		GlobalMousePosition = GameWindow.mapPixelToCoords(sf::Mouse::getPosition(GameWindow));

		GameWindow.clear();
		sf::Event GameEvent;

		while (GameWindow.pollEvent(GameEvent))
		{
			switch (GameEvent.type)
			{
			case sf::Event::Closed:	GameWindow.close(); break;
			case sf::Event::KeyPressed:
				switch (GameEvent.key.code)
				{
				case sf::Keyboard::Escape:
					if (Pause == 0) Pause = 1;
					else Pause = 0;

				}
				break;
			case sf::Event::MouseWheelMoved:
				sf::Vector2f temppos; float temprot;
				temppos = Player->TheVehicle.getPosition(); temprot = Player->TheVehicle.getRotation();

				if ((GameEvent.mouseWheel.delta > 0))
				{
					switch (PlayerVehicle::CurrentVehicle_)
					{
					case Truck:Player->TheVehicleMoveSound.stop(); Player = TankPlayer; PlayerVehicle::CurrentVehicle_ = Tank;
						break;
					case Tank:Player->TheVehicleMoveSound.stop();  Player = HeliPlayer; PlayerVehicle::CurrentVehicle_ = Heli;
						break;
					case Heli:Player->TheVehicleMoveSound.stop(); Player = TruckPlayer; PlayerVehicle::CurrentVehicle_ = Truck;
						break;
					}
				}
				else
				{
					switch (PlayerVehicle::CurrentVehicle_)
					{
					case 0:Player->TheVehicleMoveSound.stop();  Player = HeliPlayer; PlayerVehicle::CurrentVehicle_ = Heli;
						break;
					case 1:Player->TheVehicleMoveSound.stop();  Player = TruckPlayer; PlayerVehicle::CurrentVehicle_ = Truck;
						break;
					case 2:Player->TheVehicleMoveSound.stop(); Player = TankPlayer; PlayerVehicle::CurrentVehicle_ = Tank;
						break;
					}
				}
				Player->TheVehicle.setPosition(temppos); Player->TheVehicle.setRotation(temprot);
				Players.AIlist.pop_front();
				Players.AIlist.push_front(Player);
			}
		}


		if (Pause != 0)
		{
			PauseMenu();
			Pause = 0;
			Freedom = sf::seconds(0.0000000001);
			clock.restart().asSeconds();
		}
		//-----PUT  Functions    HERE--------------------
		else
		{
			
			if (Background!=nullptr)
			GameWindow.draw(*Background);


			switch (CheckPoint)
			{

			case 0:

				GameView.reset(sf::FloatRect(0, 0, 1440 * 1.2, 900 * 1.2));
				GameView.move(0, -ScreenDimensions.y*0.2);
				GameWindow.setView(GameView);
				ScreenBounds[0].move(0, -ScreenDimensions.y*0.2);
				ScreenBounds[1].move(ScreenDimensions.x*0.2, 0);
				ScreenBounds[0].scale(2, 1);
				ScreenBounds[1].scale(1, 2);
				ScreenBounds[2].scale(2, 1);
				ScreenBounds[3].scale(1, 2);
				WorldBounds[0].setPosition(-2102, -4324);
				WorldBounds[1].setPosition(-2102, -4324);
				
				
				Enemies.CreateAI();
				
				Players.AddToList(Player);
				
				Players.AIlist.front()->TheVehicle.setPosition(ScreenDimensions.x /2.1, ScreenDimensions.y/2.1 );
				for (list<TheVehicleClass*>::iterator itr = Players.AIlist.begin(); itr != Players.AIlist.end(); itr++)
					(*itr)->TheVehicle.setPosition(ScreenDimensions.x*1.1 / 2, ScreenDimensions.y / 2);

				ObjectiveTimer.restart().asSeconds();
				CheckPoint++;

				
				CurObjective.setString(string("round ")+string(std::to_string(Enemies.CurrentRound)));
				CurObjective.setOrigin(CurObjective.getLocalBounds().width / 2, CurObjective.getLocalBounds().height / 2);

				
				break;
			case 1:
				if (Enemies.AllDead())
				{ 
				Enemies.CurrentRound++;
				if (Enemies.CurrentRound % 4 == 0)MusicLoader();
				CurObjective.setString(string("round ") + string(std::to_string(Enemies.CurrentRound)));
				Player->VehicleHandler();
				for (list<TheVehicleClass*>::iterator itr=Players.AIlist.begin(); itr != Players.AIlist.end();itr++)
					(*itr)->TheVehicle.setPosition(ScreenDimensions.x*1.1 / 2, ScreenDimensions.y / 2);
				Enemies.CreateAI(Enemies.CurrentRound);
				BackGroundLoader(1 + rand() % 7, Background, BackgroundTexture);
				RoundClock.restart().asSeconds();
				 ObjectiveTimer.restart().asSeconds();
				 clock.restart().asSeconds();
				}
				break;
			
		
			}
			if (RoundClock.getElapsedTime().asSeconds()>4)
			Enemies.TheAIManager(Players);
			
			Players.TheAIManager(Enemies);
			
		if (ObjectiveTimer.getElapsedTime().asSeconds() < 4)
			{
				GameWindow.draw(CurObjective); GameWindow.draw(Survive);
			}
			PowerManager.ThePowerupManager();
		
			
			Freedom = clock.getElapsedTime();
			clock.restart().asSeconds();
			if (PlayerVehicle::PlayerHealth < 1 && GameOver==false){
				GameOverTimer.restart().asSeconds(); GameOver = true; BackGroundLoader(10000, Background, BackgroundTexture);
				CurObjective.setString(string("You Survived ") + string( std::to_string( Enemies.CurrentRound)) + string(" rounds") );
				CurObjective.setPosition(0, ScreenDimensions.y*0.7);
				CurObjective.setOrigin(0, 0);
			}
			if (GameOver == true)
			{
				GameWindow.draw(CurObjective);
				if (GameOverTimer.getElapsedTime().asSeconds() > 6)GameIsActive = false;
			}
			GameWindow.display();
		}
	}
	Player->TheVehicleMoveSound.stop();
	delete Player;
	TankPlayer->TheVehicleMoveSound.stop();
	HeliPlayer->TheVehicleMoveSound.stop();
	TruckPlayer->TheVehicleMoveSound.stop();
	for (list<TheVehicleClass*>::iterator itr = Enemies.AIlist.begin(); itr != Enemies.AIlist.end(); itr++)
	{
		(*itr)->TheVehicleMoveSound.stop(); delete (*itr);
	}
	Enemies.AIlist.clear();
	//delete TankPlayer;
	//delete HeliPlayer;
	//delete TruckPlayer;

	//return bak to menu
	GameView.reset(sf::FloatRect(0, 0, ScreenDimensions.x, ScreenDimensions.y));
	GameWindow.setView(GameView);
	//TheMainMenuClass *MainMenu = new TheMainMenuClass();
	//MainMenu->MainMenuDisplay(GameWindow);
}

void BackGroundLoader(int num, sf::Sprite *Background, sf::Texture &BackTexture)
{
	switch (num)
	{
	case 1:BackTexture.loadFromFile("Data/Textures/Backgrounds/S1.jpg"); break;	
	case 2:BackTexture.loadFromFile("Data/Textures/Backgrounds/S2.jpg"); break;	
	case 3:	BackTexture.loadFromFile("Data/Textures/Backgrounds/S3.png"); break;
	case 4:BackTexture.loadFromFile("Data/Textures/Backgrounds/S4.png"); break;
	case 5:BackTexture.loadFromFile("Data/Textures/Backgrounds/S5.png"); break;
	case 6:BackTexture.loadFromFile("Data/Textures/Backgrounds/S6.png"); break;
	case 7:BackTexture.loadFromFile("Data/Textures/Backgrounds/S7.jpg"); break;
	case 10000:BackTexture.loadFromFile("Data/Textures/Backgrounds/GOver.png"); break;
	default:BackTexture.loadFromFile("Data/Textures/Backgrounds/S1.jpg"); break;
		
	}
	delete Background; Background = nullptr; Background = new sf::Sprite;
	Background->setTexture(BackTexture);
	Background->setScale(ScreenDimensions.x / Background->getLocalBounds().width, ScreenDimensions.y / Background->getGlobalBounds().height);
	Background->scale(1.2, 1.2);  Background->move(0, -ScreenDimensions.y * 0.2);

}

void MusicLoader(int num)
{
	if (num == -1)
		num = 1+rand() % 6;
	switch (num)
	{
	case 1:GameMusic.openFromFile("Data/Music/HaloOST.ogg"); break;
	case 2:GameMusic.openFromFile("Data/Music/BattleCityOST.ogg"); break;
	case 3:GameMusic.openFromFile("Data/Music/RandomEncounterMusic.ogg"); break;
	case 4:GameMusic.openFromFile("Data/Music/BassDrop.ogg"); break;
	case 5:GameMusic.openFromFile("Data/Music/Minoru187.ogg"); break;
	case 6:GameMusic.openFromFile("Data/Music/Blisters&Coffee.ogg"); break;
	default:GameMusic.openFromFile("Data/Music/RandomEncounterMusic.ogg"); break;
	}
	GameMusic.play();
}





void CutScene1()
{
	
	int Pause = 0;
	bool Pauseactive;
	//sf::View CutScene1View(sf::FloatRect(0, 0, ScreenDimensions.x, ScreenDimensions.y));
	GameView.reset(sf::FloatRect(0, 0, ScreenDimensions.x, ScreenDimensions.y));
	sf::Sprite DesertBackground; sf::Texture DesertBackGroundTexture;
	DesertBackGroundTexture.loadFromFile("Data/Textures/4.jpg"); DesertBackground.setTexture(DesertBackGroundTexture);
	DesertBackground.setScale(ScreenDimensions.x / DesertBackground.getLocalBounds().width, ScreenDimensions.y / DesertBackground.getGlobalBounds().height);
	DesertBackground.setOrigin(DesertBackground.getLocalBounds().width / 2, DesertBackground.getLocalBounds().height / 2);
	DesertBackground.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);

	sf::Sprite Tanks; sf::Texture TanksTexture;
	TanksTexture.loadFromFile("Data/Textures/Cutscene/ALLTanks.png"); Tanks.setTexture(TanksTexture);
	Tanks.setPosition(10, -ScreenDimensions.y*1.2);
	Tanks.setScale(ScreenDimensions.x / Tanks.getLocalBounds().width, ScreenDimensions.y / Tanks.getGlobalBounds().height);
	
	sf::Sprite Tanks2; sf::Texture TanksTexture2;
	TanksTexture2.loadFromFile("Data/Textures/Cutscene/ALLTanks.png"); Tanks2.setTexture(TanksTexture);
	Tanks2.setPosition(10, Tanks.getGlobalBounds().top - ScreenDimensions.y);
	Tanks2.setScale(ScreenDimensions.x / Tanks2.getLocalBounds().width, ScreenDimensions.y / Tanks2.getGlobalBounds().height);
	
	sf::Sprite PakTank; sf::Texture PakTex; PakTex.loadFromFile("Data/Tank/Type1_HoneyBadger.png"); PakTank.setTexture(PakTex); PakTank.setRotation(90);
	PakTank.setPosition(ScreenDimensions.x*0.55, -ScreenDimensions.y);
	sf::Font BattlefieldFont; BattlefieldFont.loadFromFile("Data/Fonts/BattlefieldFont.ttf");
	sf::Text OperationSpecialDelivery("operation special delivery", BattlefieldFont, 50);
	OperationSpecialDelivery.setColor(sf::Color::Red);
	OperationSpecialDelivery.setOrigin(OperationSpecialDelivery.getLocalBounds().width / 2, OperationSpecialDelivery.getLocalBounds().height / 2);
	OperationSpecialDelivery.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
	
	sf::Text Line1("the pakistan army captured several bases and took thousands\n of lives	\n soon they took over cities..destroying everything in their path\nthey were winning the war\n until an experimental weapon was launched ", BattlefieldFont, 25);
	Line1.setOrigin(Line1.getLocalBounds().width / 2, Line1.getLocalBounds().height / 2);
	Line1.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
	GameWindow.setView(GameView);

	//Tanks.scale(3, 3);
	PakTank.scale(3, 3);
	DesertBackground.scale(3, 3);
	int allowZoom = 200;
	//sf::Sound sound; sf::SoundBuffer buf; buf.loadFromFile("Data/Sound/TheVehicleMoveSound.ogg");
	//sound.setBuffer(buf);
	//sound.setLoop(1);
	//sound.play();
	
	bool TitlePlay = true;
	bool EndPlay = true;

	//-----------------------------------------THEMAINLOOP-----------------------------------------------
	sf::Clock clock;
	sf::Clock clock2;
	while (GameWindow.isOpen()&&EndPlay==true)
	{
		GameWindow.clear();
		sf::Event GameEvent;

		while (GameWindow.pollEvent(GameEvent))
		{
			switch (GameEvent.type)
			{
			case sf::Event::Closed:	GameWindow.close(); break;
			case sf::Event::KeyPressed:
				switch (GameEvent.key.code)
				{
				case sf::Keyboard::Escape:
					if (Pause == 0) Pause = 1;
					else Pause = 0;
					Pauseactive = true;
				}
				break;
			}
		}
		//-----PUT  Functions    HERE--------------------
		if (Pause == 0)
		{
			if (TitlePlay)
			{
				float Alpha = 6;
				bool Protect2 = false;
				int PositiveORNegative = 1;
				sf::Text Title(" rann of kutch\n\nindia pak Border\n\n	june 2015", BattlefieldFont, 40);
				Title.setOrigin(Title.getLocalBounds().width / 2, Title.getLocalBounds().height / 2);
				Title.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
				GameWindow.display();
				sf::sleep(sf::seconds(0.5));
				while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) && TitlePlay == true)
				{
					if (Alpha >= 255)
					{
						sf::sleep(sf::seconds(0.3));
						Protect2 = true;
						PositiveORNegative = -1;
					}
					else if (Alpha < 5)
					{
						TitlePlay = false;
					}
					Alpha += 1 * PositiveORNegative*Freedom.asSeconds() * 150;

					Title.setColor(sf::Color(255, 255, 255, Alpha));
					GameWindow.clear();
					GameWindow.draw(Title);

					GameWindow.display();
					if (Protect2 != true)
					{
						Freedom = clock2.getElapsedTime();
					}
					Protect2 = false;
					clock2.restart().asSeconds();

				}
				sf::sleep(sf::seconds(0.5));
			}

			GameWindow.draw(DesertBackground);
			GameWindow.draw(Tanks);
			GameWindow.draw(Tanks2);
			GameWindow.draw(PakTank);
			PakTank.move(0, 0.5);
			if (PakTank.getPosition().y > ScreenDimensions.y*1.2)
			{
				//if (sound.getStatus() == sf::Sound::Stopped)
				//	sound.play();
				if (allowZoom)
				{
					DesertBackground.scale(0.995, 0.995);
					DesertBackground.setOrigin(DesertBackground.getLocalBounds().width / 2, DesertBackground.getLocalBounds().height / 2);
					allowZoom--;
					sf::sleep(sf::seconds(0.004));
				}
				Tanks.move(0, 0.4*Freedom.asSeconds() * 300);
				Tanks2.move(0, 0.4*Freedom.asSeconds() * 300);
			}
			if ((Tanks.getPosition().y + ScreenDimensions.y*0.9 > ScreenDimensions.y) && EndPlay == true)
			{
				float Alpha = 255;
				int PositiveORNegative = -1;

				while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) && Alpha > 1)
				{

					Alpha += 1 * PositiveORNegative*Freedom.asSeconds() * 150;
					DesertBackground.setColor(sf::Color(Alpha, Alpha, Alpha));
					Tanks.setColor(sf::Color(Alpha, Alpha, Alpha));
					Tanks2.setColor(sf::Color(Alpha, Alpha, Alpha));
					Tanks.move(0, 0.4*Freedom.asSeconds() * 300);
					Tanks2.move(0, 0.4*Freedom.asSeconds() * 300);
					GameWindow.clear();
					GameWindow.draw(DesertBackground);
					GameWindow.draw(Tanks);
					GameWindow.draw(Tanks2);
					GameWindow.display();
					clock2.restart().asSeconds();
				}
				
				sf::sleep(sf::seconds(0.5));
				EndPlay = false;
			}
			if (EndPlay == false)
			{
				sf::Clock clock;

				while (clock.getElapsedTime().asSeconds() < 6)
				{
					GameWindow.clear();
					GameWindow.draw(Line1);
					GameWindow.display();
				}
				while (clock.getElapsedTime().asSeconds() < 9)
				{
					GameWindow.clear();
					GameWindow.draw(OperationSpecialDelivery);
					GameWindow.display();
				}
				clock.restart().asSeconds();
				

			}
			GameWindow.setView(GameView);
			
			GameWindow.display();
			Freedom = clock.getElapsedTime();
			clock.restart().asSeconds();
		}
		else
		{
			PauseMenu();
			Pause = 0;
		
			clock.restart().asSeconds();
		}


	}
	
}

void PauseMenu()
{
	GameView.reset(sf::FloatRect(0, 0, ScreenDimensions.x, ScreenDimensions.y));
	GameWindow.setView(GameView);
	sf::Sprite *PauseScreen = new sf::Sprite;
	sf::Texture *PauseScreenTexture = new sf::Texture;
	PauseScreenTexture->loadFromFile("Data/Textures/PauseScreen2.jpg");
	PauseScreen->setTexture(*PauseScreenTexture);
	PauseScreen->setScale(ScreenDimensions.x / PauseScreen->getLocalBounds().width, ScreenDimensions.y / PauseScreen->getLocalBounds().height);
//	PauseScreen->setPosition(0, ViewDimensions.y);
	

	sf::Text Resume("Resume", BattlefieldFont, 60);
	Resume.setColor(sf::Color::Red);
	Resume.setOrigin(Resume.getLocalBounds().width / 2, Resume.getLocalBounds().height / 2);
	Resume.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.3);
	

	sf::Text MainMenu("Quit to Main Menu", BattlefieldFont, 60);
	MainMenu.setColor(sf::Color::Red);
	MainMenu.setOrigin(MainMenu.getLocalBounds().width / 2, MainMenu.getLocalBounds().height / 2);
	MainMenu.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.5);
	

	sf::Text Quit("Quit to Windows", BattlefieldFont, 60);
	Quit.setColor(sf::Color::Red);
	Quit.setOrigin(Quit.getLocalBounds().width / 2, Quit.getLocalBounds().height / 2);
	Quit.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y*0.7);
	

	
	int CurrenttemIndex = 1;
	
	sf::Clock myclock;
	int PauseIsActive = 1;
		while (GameWindow.isOpen() && PauseIsActive==1)
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
				case sf::Keyboard::Escape:
					PauseIsActive = 0;
					break;
				case sf::Keyboard::Return:
					switch (CurrenttemIndex)
					{
					case 1:PauseIsActive = 0;
						break;
					case 2:GameIsActive = 0;
						PauseIsActive = 0;
						break;
					case 3:
						GameWindow.close();
						break;
					default:
						break;
					}
					break;

				case sf::Keyboard::Down:
					if (CurrenttemIndex == 3) CurrenttemIndex = 1;
					else CurrenttemIndex++;
					break;
				case sf::Keyboard::Up:
					if (CurrenttemIndex == 1) CurrenttemIndex = 3;
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
		case 1:Resume.setColor(sf::Color::Red);
			Resume.setScale(1.2, 1.2);

			MainMenu.setColor(sf::Color::White);
			MainMenu.setScale(1.0, 1.0);
			Quit.setColor(sf::Color::White);
			Quit.setScale(1.0, 1.0);
			break;
		case 2:
			Resume.setColor(sf::Color::White);
			Resume.setScale(1.0, 1.0);
			MainMenu.setColor(sf::Color::Red);
			MainMenu.setScale(1.2, 1.2);
			Quit.setColor(sf::Color::White);
			Quit.setScale(1.0, 1.0);
			break;
		case 3:
			Resume.setColor(sf::Color::White);
			Resume.setScale(1.0, 1.0);
			MainMenu.setColor(sf::Color::White);
			MainMenu.setScale(1.0, 1.0);
			Quit.setColor(sf::Color::Red);
			Quit.setScale(1.2, 1.2);
			break;
	
		
		default:
			break;
		}
		//end of item highliter
		GameWindow.clear();
		GameWindow.draw(*PauseScreen);
		GameWindow.draw(Resume);
		GameWindow.draw(MainMenu);
		GameWindow.draw(Quit);
		GameWindow.display();
	}
}
void DispObjective()
{
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		ObjectiveTimer.restart().asSeconds();
	if (ObjectiveTimer.getElapsedTime().asSeconds() < 3.5)
	{
		CurObjective.setPosition(ScreenDimensions.x / 2, ViewDimensions.y + ScreenDimensions.y*0.3);
		DistanceRemaining.setPosition(CurObjective.getPosition().x-ScreenDimensions.y*0.07, CurObjective.getPosition().y + ScreenDimensions.y*0.05);
		Arrow.setPosition(CurObjective.getPosition().x-ScreenDimensions.x*0.015,CurObjective.getPosition().y-ScreenDimensions.y*0.08);
		GameWindow.draw(CurObjective);
		Integer = -(ToReach - (ViewDimensions.y + ScreenDimensions.y*0.7));
		DistanceRemaining.setString(std::to_string(Integer));
		GameWindow.draw(Arrow);
		GameWindow.draw(DistanceRemaining);
	}

}
