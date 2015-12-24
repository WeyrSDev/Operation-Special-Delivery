#include "OperationsHandler.h"



float OldPlayerPos, OldPlayerPosY;



std::default_random_engine generator;
sf::Clock DamageClock;

bool W = false;		bool S = false;		bool A = false;		bool D = false;
sf::Sprite DesertBackground; sf::Texture DesertBackGroundTexture;
sf::Sprite DesertBackground2;
sf::Sprite DesertBackground3;


void OperationInitialiser()
	{
		
		ScreenBounds[0].setSize(sf::Vector2f(ScreenDimensions.x, 1));
		ScreenBounds[1].setSize(sf::Vector2f(1, ScreenDimensions.y * 200));
		ScreenBounds[2].setSize(sf::Vector2f(ScreenDimensions.x, 10));
		ScreenBounds[3].setSize(sf::Vector2f(1, ScreenDimensions.y * 200));
		ScreenBounds[1].setOrigin(0, ScreenBounds[1].getLocalBounds().height / 2);
		ScreenBounds[3].setOrigin(0, ScreenBounds[3].getLocalBounds().height / 2);
		ScreenBounds[0].setPosition(-20, 20);
		ScreenBounds[1].setPosition(ScreenDimensions.x + 10, 0);
		ScreenBounds[2].setPosition(0, ScreenDimensions.y);
		ScreenBounds[3].setPosition(0, 0);

		ScreenBounds[0].setFillColor(sf::Color::Red);
		ScreenBounds[1].setFillColor(sf::Color::White);
		ScreenBounds[2].setFillColor(sf::Color::Green);
		ScreenBounds[3].setFillColor(sf::Color::White);

		WorldBounds[0].setSize(sf::Vector2f(ScreenDimensions.x, 1));
		WorldBounds[1].setSize(sf::Vector2f(ScreenDimensions.x, 1));

		OldPlayerPosY = 0;


		DesertBackground.setPosition(0, 0);
		DesertBackGroundTexture.loadFromFile("Data/Textures/DesertRoad5.png"); DesertBackground.setTexture(DesertBackGroundTexture);
		DesertBackground.setScale(ScreenDimensions.x / DesertBackground.getLocalBounds().width, ScreenDimensions.y / DesertBackground.getGlobalBounds().height);

		DesertBackground2 = DesertBackground;
		DesertBackground3 = DesertBackground;
		// 0->up
		//1->right
		//2->down
		//3->left
	}

void VehicleCollisionCheck(TheVehicleClass *Player, TheVehicleClass *Enemy)
{
//#shortcut
//simple coll n simple soln
	if (Player->TheVehicle.getGlobalBounds().intersects(Enemy->TheVehicle.getGlobalBounds()))
	{
		if (Player->TheVehicle.getPosition().x > Enemy->TheVehicle.getPosition().x)
		{
			//Player->TheVehicle.move(1, 0);
			Enemy->TheVehicle.move(-1, 0);
		}
		else { //Player->TheVehicle.move(-1, 0); 
		Enemy->TheVehicle.move(1, 0); }

		if (Player->TheVehicle.getPosition().y > 
			Enemy->TheVehicle.getPosition().y)
		{
			//Player->TheVehicle.move(0, 1); 
			Enemy->TheVehicle.move(0, -1);
		}
		else {// Player->TheVehicle.move(0, -1)
			; Enemy->TheVehicle.move(0, 1); }


	}
}

void ViewLock( bool w, bool s, bool a, bool d)
{

	W = w; S = s; A = a; D = d;

	//scroll up lock
	if (w == true)
	{
		if (ViewDimensions.y <0)
			ViewDimensions.y = 0;
	}
	
	//scroll down lock
	if (s == true)
	{
		if (ViewDimensions.y >0)
			ViewDimensions.y = 0;
	}
	
	//scroll right lock
	if (d == true)
	{
		if (ViewDimensions.x >0)
			ViewDimensions.x = 0;
	}
	
	//scroll left lock
	if (a == true)
	{
		if (ViewDimensions.x <0)
			ViewDimensions.x = 0;
	}

	ScreenBounds[2].setPosition(0, ViewDimensions.y + ScreenDimensions.y*1.04);
	ScreenBounds[0].setPosition(0, ScreenBounds[2].getPosition().y - ScreenDimensions.y);
}

void ReverseLock(sf::Sprite &Player, bool s )
{
	OldPlayerPos = ViewDimensions.y;
	
	ViewDimensions.x = Player.getPosition().x - (ScreenDimensions.x *0.75);
	ViewDimensions.y = Player.getPosition().y - (ScreenDimensions.y *0.75);
	

	if (s == true)
	{
			if ((OldPlayerPos < ViewDimensions.y))ViewDimensions.y = OldPlayerPos;	
			 
	}
	
	
	
	
	
}

void BackHandler(sf::RenderWindow &GameWindow,sf::Sprite Player)
{
	GlobalMousePosition = GameWindow.mapPixelToCoords(sf::Mouse::getPosition(GameWindow));

	GameView.reset(sf::FloatRect(ViewDimensions.x, ViewDimensions.y, ScreenDimensions.x, ScreenDimensions.y));

	GameView.rotate(GameViewRotation);
	GameView.zoom(GameViewZoom);
	if (GameViewCenter.x != 0) GameView.setCenter(GameViewCenter);
	GameWindow.setView(GameView);


	if (Player.getGlobalBounds().intersects(DesertBackground.getGlobalBounds()))
	{
		DesertBackground2.setPosition(0, DesertBackground.getPosition().y - (DesertBackground.getLocalBounds().height - 100));
		DesertBackground3.setPosition(0, DesertBackground.getPosition().y + (DesertBackground.getLocalBounds().height - 100));
	}
	if (Player.getGlobalBounds().intersects(DesertBackground2.getGlobalBounds()))
	{

		DesertBackground3.setPosition(0, DesertBackground2.getPosition().y - (DesertBackground2.getLocalBounds().height - 100));
		DesertBackground.setPosition(0, DesertBackground2.getPosition().y + (DesertBackground2.getLocalBounds().height - 100));
	}
	if (Player.getGlobalBounds().intersects(DesertBackground3.getGlobalBounds()))
	{

		DesertBackground.setPosition(0, DesertBackground3.getPosition().y - (DesertBackground3.getLocalBounds().height - 100));
		DesertBackground2.setPosition(0, DesertBackground3.getPosition().y + (DesertBackground3.getLocalBounds().height - 100));
	}

	GameWindow.draw(DesertBackground);
	GameWindow.draw(DesertBackground2);
	GameWindow.draw(DesertBackground3);
}

void RandSpawn(sf::Sprite &Object)
{
	std::uniform_int_distribution<int> distributionX(ScreenDimensions.x*0.2, ScreenDimensions.x*0.8);
	std::uniform_int_distribution<int> distributionY(ScreenDimensions.y*0.2, ScreenDimensions.y*0.8);
	
	Object.setPosition(distributionX(generator),distributionY(generator));

}

void SpriteCollision(TheVehicleClass &Tank, sf::Sprite Object)
{
	if (Tank.TheVehicle.getGlobalBounds().intersects(Object.getGlobalBounds()))
	{
		if (Tank.TheVehicle.getPosition().x - Object.getPosition().x >= Object.getLocalBounds().width)
			Tank.DisallowMovement = 'a';
		else if (Tank.TheVehicle.getPosition().x - Object.getPosition().x <= 0)
			Tank.DisallowMovement = 'd';
		else if (Tank.TheVehicle.getPosition().y - Object.getPosition().y <= 0)
			Tank.DisallowMovement = 's';
		else  if (Tank.TheVehicle.getPosition().y - Object.getPosition().y >= Object.getLocalBounds().height)
			Tank.DisallowMovement = 'w';
	}
	else Tank.DisallowMovement = 'z';
	/*
	if (Tank.Projectile.TheProjectile.getGlobalBounds().intersects(Object.getGlobalBounds()))
		Tank.Projectile.TheProjectile.setPosition(-1000, -1000);
	else if (Tank.Projectile2.TheProjectile.getGlobalBounds().intersects(Object.getGlobalBounds()))
		Tank.Projectile2.TheProjectile.setPosition(-1000, -1000);
	else if(Tank.LightProjectile.TheProjectile.getGlobalBounds().intersects(Object.getGlobalBounds()))
		Tank.LightProjectile.TheProjectile.setPosition(-1000, -1000);
	*/
}

void JoystickKeyFinder()
{
	if (sf::Joystick::isButtonPressed(0, 1)) cout << "yea baby1" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 2))	cout << "yea baby2" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 3))	cout << "yea baby3" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 4))	cout << "yea baby4" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 5))	cout << "yea baby5" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 6))	cout << "yea baby6" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 7))cout << "yea baby7" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 8))cout << "yea baby8" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 9))cout << "yea baby9" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 10))cout << "yea baby10" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 11))cout << "yea baby11" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 12))cout << "yea baby12" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 13))cout << "yea baby13" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 14))cout << "yea baby14" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 15))cout << "yea baby15" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 16))cout << "yea baby15" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 17))cout << "yea baby15" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 18))cout << "yea baby15" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 19))cout << "yea baby15" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 20))cout << "yea baby15" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 21))cout << "yea baby15" << endl << endl;
	if (sf::Joystick::isButtonPressed(0, 0))cout << "yea baby0" << endl << endl;
	
		cout << sf::Joystick::getAxisPosition(0, sf::Joystick::Z) << endl;
}


void ProjectileCollisionCheck(TheVehicleClass *Player,TheVehicleClass *Enemy)
{
	if (Enemy->VehicleIsAlive == true)
	{
		for (int i = 0; i < Player->MaxProjectiles; i++)
		{
			if ((Player->Projectile[i]->TheProjectile.getGlobalBounds().intersects(Enemy->TheVehicle.getGlobalBounds())))
			{
				Enemy->ReduceHealth(Player->Projectile[i]->GetProjectileDamage());
				Player->Projectile[i]->TheProjectile.setPosition(-1000, -1000);
			}
		}
	}

	if (Player->VehicleIsAlive == true)
	{
		for (int i = 0; i < Enemy->MaxProjectiles; i++)
		{
			if ((Enemy->Projectile[i]->TheProjectile.getGlobalBounds().intersects(Player->TheVehicle.getGlobalBounds())))
			{
				Player->ReduceHealth(Enemy->Projectile[i]->GetProjectileDamage());
				Enemy->Projectile[i]->TheProjectile.setPosition(-1000, -1000);
			}
		}
	}



	//if (DamageClock.getElapsedTime().asSeconds() < 0.15)
	//	Player.TheVehicleColor = sf::Color::Red;
	//else Player.TheVehicleColor = sf::Color::White;
}


//list<TheVehicleClass*> Enemylist;

AIManager::AIManager()
{
	loadingTexture.loadFromFile("Data/Textures/loading.png");
	loading.setTexture(loadingTexture);
	loading.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
	loading.move(ScreenDimensions.x*0.1, 0);
	loading.setOrigin(loading.getLocalBounds().width / 2, 0);
	loading.scale(2, 2);
	}
AIManager::AIManager(Controller _AIArchEnemy)
{
	AIArchEnemy = _AIArchEnemy;
	if (AIArchEnemy == Human)
	{
		loadingTexture.loadFromFile("Data/Textures/loading.png");
		loading.setTexture(loadingTexture);
		loading.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
		loading.move(ScreenDimensions.x*0.1, 0);
		loading.setOrigin(loading.getLocalBounds().width / 2, 0);
		loading.scale(2, 2);
	}

}

void AIManager::TheAIManager(AIManager &TargetAIs)
{
	if (TargetAIs.AllDead())
	{
		itr = AIlist.begin(), Enditr = AIlist.end();
		while (itr != Enditr)
		{
					(*itr)->VehicleHandler();
			if (DelClock.getElapsedTime().asSeconds() > DelClockBound)
			{

				if ((*itr)->VehicleIsAlive == false)
				{
					tmp = itr; itr++; DelClock.restart().asSeconds(); DeleteAI(tmp);
				}
				else itr++;
			}

			else itr++;

		}
	}
	else if (!this->AllDead())
	{

	
		_Target = (TargetAIs.AIlist.back());

		Enditr = AIlist.end();
		for (itr = AIlist.begin(); itr != Enditr; itr++)
		{
			for (itr2 = AIlist.begin(); itr2 != Enditr; itr2++)
			{
				if (itr != itr2)VehicleCollisionCheck(*itr, *itr2);
			}
		}
		itr = AIlist.begin();
		while (itr != Enditr)
		{
			if ((*itr)->TheVehicleController == AI)
				(*itr)->VehicleHandler(*_Target);
			else if ((*itr)->TheVehicleController == Human)
				(*itr)->VehicleHandler();
			if ((*itr)->DoYouContainPowerup())
			(*itr)->TheVehicleColorFunction();
			ProjectileCollisionCheck(_Target, *itr);
			ProjectileCollisionCheck(TargetAIs.AIlist.front(), *itr);
			VehicleCollisionCheck(_Target, *itr);
			if (DelClock.getElapsedTime().asSeconds() > DelClockBound)
			{

				if ((*itr)->VehicleIsAlive == false&& (*itr)->TheVehicleController!=Human)
				{
					tmp = itr; itr++; DelClock.restart().asSeconds(); DeleteAI(tmp);
				}
				else itr++;
			}

			else itr++;

		}
	}

//
	//if (SpawnClock.getElapsedTime().asSeconds() < 10)
//	{
	//	ScreenBounds[1].setPosition(10000, 10000);
	//	ScreenBounds[3].setPosition(10000, 10000);
	//}
	//else {
	//	ScreenBounds[1].setPosition(ScreenDimensions.x + 10, 0); ScreenBounds[1].move(ScreenDimensions.x*0.2, 0);
	//	ScreenBounds[3].setPosition(0, 0);
	//}
	
}
void AIManager::CreateAI(int num)
{
	if (CurrentRound > 5)DelClockBound = 1;
	else if (CurrentRound > 10)DelClockBound = 0.4;
	else if (CurrentRound > 20)DelClockBound = 0.1;
	
	
	GameWindow.draw(loading);
	
	GameWindow.display();
	DidICreateASpecialEnemyAlready = 0;
	while (num > 0)
	{
		if (rand()%10<8)
		AIlist.push_back(GetRandTank());
		else AIlist.push_back(GetRandHeli());
		RandPlace((AIlist.back())->TheVehicle);
		num--;
	}
	SpawnClock.restart().asSeconds();
	//(*tmp)->TheVehicle.setPosition(rand() /(ScreenDimensions.x*1.2), rand() / (ScreenDimensions.y*1.2));
}
void AIManager::CreateAIUp(sf::Vector2f pos, int num )
{
	if (CurrentRound > 5)DelClockBound = 1;
	else if (CurrentRound > 10)DelClockBound = 0.4;
	else if (CurrentRound > 20)DelClockBound = 0.1;


	GameWindow.draw(loading);

	GameWindow.display();
	DidICreateASpecialEnemyAlready = 0;
	while (num > 0)
	{
		if (rand() % 10<8)
			AIlist.push_back(GetRandTank());
		else AIlist.push_back(GetRandHeli());
		AIlist.back()->TheVehicle.setPosition(pos.x, pos.y - 1000);

		num--;
	}
	SpawnClock.restart().asSeconds();
	//(*tmp)->TheVehicle.setPosition(rand() /(ScreenDimensions.x*1.2), rand() / (ScreenDimensions.y*1.2));
}
void AIManager::CreateAIUpTank(sf::Vector2f pos, int num)
{
	if (CurrentRound > 5)DelClockBound = 1;
	else if (CurrentRound > 10)DelClockBound = 0.4;
	else if (CurrentRound > 20)DelClockBound = 0.1;


	GameWindow.draw(loading);

	GameWindow.display();
	DidICreateASpecialEnemyAlready = 0;
	while (num > 0)
	{
		
			AIlist.push_back(GetRandTank());
		
		AIlist.back()->TheVehicle.setPosition(pos.x, pos.y - 1000);
		
		num--;
	}
	SpawnClock.restart().asSeconds();
	//(*tmp)->TheVehicle.setPosition(rand() /(ScreenDimensions.x*1.2), rand() / (ScreenDimensions.y*1.2));
}
void AIManager::CreateAIUpHeli(sf::Vector2f pos, int num)
{
	if (CurrentRound > 5)DelClockBound = 1;
	else if (CurrentRound > 10)DelClockBound = 0.4;
	else if (CurrentRound > 20)DelClockBound = 0.1;


	GameWindow.draw(loading);

	GameWindow.display();
	DidICreateASpecialEnemyAlready = 0;
	while (num > 0)
	{
		 AIlist.push_back(GetRandHeli());
		AIlist.back()->TheVehicle.setPosition(pos.x, pos.y - 1000);
		
		num--;
	}
	SpawnClock.restart().asSeconds();
	//(*tmp)->TheVehicle.setPosition(rand() /(ScreenDimensions.x*1.2), rand() / (ScreenDimensions.y*1.2));
}
void AIManager::CreateAIUpTurret(sf::Vector2f pos, int num)
{
	if (CurrentRound > 5)DelClockBound = 1;
	else if (CurrentRound > 10)DelClockBound = 0.4;
	else if (CurrentRound > 20)DelClockBound = 0.1;


	GameWindow.draw(loading);

	GameWindow.display();
	DidICreateASpecialEnemyAlready = 0;
	while (num > 0)
	{
		AIlist.push_back(new SentryGun);
		AIlist.back()->TheVehicle.setPosition(pos.x, pos.y - 1000);
		num--;
	}
	SpawnClock.restart().asSeconds();
	//(*tmp)->TheVehicle.setPosition(rand() /(ScreenDimensions.x*1.2), rand() / (ScreenDimensions.y*1.2));
}


void AIManager::DeleteAI(list<TheVehicleClass*>::iterator itr)
{
	UnclaimedDeadBodies.first++;
	if ((*itr)->DoYouContainPowerup())
	{
		UnclaimedDeadBodies.second = (*itr)->TheVehicle.getPosition();
	}
	
	delete *itr;
	AIlist.erase(itr);
}
bool AIManager::AllDead()
{
	if (AIlist.begin() == AIlist.end())
		return true;
	else return false;
}
void AIManager::RandPlace(sf::Sprite &Object)
{

	int x = rand() % 4;

	switch (x)
	{

	case 0:Object.setPosition(rand() / ScreenDimensions.x, -ScreenDimensions.y*1.2);
		break;
	case 1:Object.setPosition(rand() / ScreenDimensions.x, ScreenDimensions.y * 1.2);
		break;
	case 2:Object.setPosition(ScreenDimensions.x*1.2, rand() / ScreenDimensions.y);;
		break;
	case 3:Object.setPosition(-ScreenDimensions.x * 1.2, rand() / ScreenDimensions.y);
		break;
	}
}
TheVehicleClass *AIManager::GetRandTank()
{
	TheVehicleClass *tmp;
	
		int x = rand() % 9;
		switch (x)
		{
		case 0:tmp = new TheAITank(HoneyBadger);
			break;
		case 1:tmp = new TheAITank(HankTheTank);
			break;
		case 2:tmp = new TheAITank(Centurion);
			break;
		case 3:tmp = new TheAITank(Crusader);
			break;
		case 4:tmp = new TheAITank(Challenger);
			break;
		case 5:tmp = new TheAITank(BlackPrince);
			break;
		case 6:tmp = new TheAITank(Dreadnaught);
			break;
		case 7:tmp = new TheAITank(Juggernaut);
			break;
		case 8:tmp = new TheAITank(Type80);
			break;
		default:
			tmp = new TheAITank(BlackPrince);
			break;
		}
	if (AIArchEnemy == Human)
		if (rand() % 5 < 2 && DidICreateASpecialEnemyAlready == 0)
		{
		tmp->MakeMeContainPowerup(); DidICreateASpecialEnemyAlready = 1;
		}
	return tmp;
}
TheVehicleClass *AIManager::GetRandHeli()
{
	int x = rand() % 2;
	TheVehicleClass *tmp;
	switch (x)
	{

	case 0:tmp = new TheAIHeli(Apache);
		break;
	case 1:tmp = new TheAIHeli(Hunter);
		break;
	default:
		tmp = new TheAIHeli;
	}
	if (AIArchEnemy == Human)
		if (rand() % 5 < 2 && DidICreateASpecialEnemyAlready == 0)
		{
		tmp->MakeMeContainPowerup(); DidICreateASpecialEnemyAlready = 1;
		}
	return tmp;
}
void AIManager::AddToList(TheVehicleClass *toolazytowriteapropername)
{
	AIlist.push_back(toolazytowriteapropername);
}
TheVehicleClass* AIManager::GetLastEnemy()
{
	return *itr;
}
pair<int, sf::Vector2f> AIManager::SendDeadBodies()
{
	tmpdeadbodies = UnclaimedDeadBodies;
	UnclaimedDeadBodies = make_pair(0, sf::Vector2f(0, 0));
	return tmpdeadbodies;
}




PowerupManager::PowerupManager(AIManager *_HeroTeam, AIManager *_VillanTeam)
{
	HeroTeam = _HeroTeam; VillanTeam = _VillanTeam;
	AnyoneActive = 0;
	Price[0] = 400; Price[1] = 800; Price[2] = 1500; Price[3] =2000;
	CallPowerupTexture[0].loadFromFile("Data/Textures/Powerup/CallTurret.png");
	CallPowerupTexture[1].loadFromFile("Data/Textures/Powerup/CallTank.png");
	CallPowerupTexture[2].loadFromFile("Data/Textures/Powerup/CallHeli.png");
	CallPowerupTexture[3].loadFromFile("Data/Textures/Powerup/CallAirstrike.png");
	for (size_t i = 0; i < 4; i++)
		CallPowerup[i].setTexture(CallPowerupTexture[i]);
	CallPowerup[0].setPosition(ScreenDimensions.x*0.95, ScreenDimensions.y*0.7);
	CallPowerup[1].setPosition(ScreenDimensions.x*1.01, ScreenDimensions.y*0.63);
	CallPowerup[2].setPosition(ScreenDimensions.x*1.06, ScreenDimensions.y*0.7);
	CallPowerup[3].setPosition(ScreenDimensions.x*1.01, ScreenDimensions.y*0.8);
	for (size_t i = 0; i < 4; i++)
	{
		CallPowerup[i].setColor(NotAvailable);
	}
	Score.setFont(BattlefieldFont); Score.setCharacterSize(40); Score.setColor(sf::Color::Red);
	Score.setPosition(ScreenDimensions.x*0.95, ScreenDimensions.y*0.9);

}
void PowerupManager::ThePowerupManager()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (CallPowerup[i].getColor() != Active)
		{
			if (ScoreCounter >= Price[i])
			{
				CallPowerup[i].setColor(Available);
			}
			else CallPowerup[i].setColor(NotAvailable);
		}
		
	}
	if (!AnyoneActive)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)&&ScoreCounter>Price[0])
		{
			ScoreCounter -= Price[0];
			AnyoneActive = true;
			CallPower(CallTurret);
			CallPowerup[0].setColor(Active);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && ScoreCounter>Price[1])
		{
			ScoreCounter -= Price[1];
			AnyoneActive = true;
			CallPower(CallTankSupport);
			CallPowerup[1].setColor(Active);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && ScoreCounter>Price[2])
		{
			ScoreCounter -= Price[2];
			AnyoneActive = true;
			CallPower(CallHeliSupport);
			CallPowerup[2].setColor(Active);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && ScoreCounter>Price[3])
		{
			ScoreCounter -= Price[3];
			AnyoneActive = true;
			CallPower(CallAirstrike);
			CallPowerup[3].setColor(Active);
		}
	}
	else  if ( (HeroTeam->AIlist.back())->TheVehicleController == Human)

	{
		AnyoneActive = false;
		for (size_t i = 0; i < 4; i++)
					CallPowerup[i].setColor(Available);
	}
	ClaimDeadBodies(VillanTeam->SendDeadBodies());

	GameWindow.draw(CallPowerup[0]); GameWindow.draw(CallPowerup[1]); GameWindow.draw(CallPowerup[2]); GameWindow.draw(CallPowerup[3]);
	Score.setString("score " + std::to_string(ScoreCounter));
	GameWindow.draw(Score);
	if (AirStrikeJet != nullptr)
	{
		AirStrikeJet->TakeDownTargets();
		CallPowerup[3].setColor(Active);
		if (AirStrikeJet->IsTheJobDone()){ delete AirStrikeJet; AirStrikeJet = nullptr; CallPowerup[3].setColor(NotAvailable); }
	}
	if (PowerupActivationTimer.getElapsedTime().asSeconds() > 10)
	{
		switch (ToDeactivate)
		{
		case PowerupManager::InfiHealth:PlayerVehicle::Tolerance = 2;
			HeroTeam->AIlist.front()->SetVehicleColor(sf::Color::White);
			ToDeactivate = LITERALLY_NOTHING;
			break;
		case PowerupManager::Speedup:
			HeroTeam->AIlist.front()->TheFreedomSpeed /= 3;
			HeroTeam->AIlist.front()->SetVehicleColor(sf::Color::White);
			ToDeactivate = LITERALLY_NOTHING;
			break;
		case PowerupManager::FireBullet:
			for (int i = 0; i < HeroTeam->AIlist.front()->MaxProjectiles; i++)
			{
				HeroTeam->AIlist.front()->Projectile[i]->TheProjectileDamage /= 10;
				HeroTeam->AIlist.front()->Projectile[i]->TheProjectile.setColor(sf::Color::White);
				HeroTeam->AIlist.front()->Projectile[i]->TheProjectile.scale(0.66, 0.66);
				HeroTeam->AIlist.front()->Projectile[i]->FreedomSpeed /= 2;
			}
			ToDeactivate = LITERALLY_NOTHING;
			break;
		case PowerupManager::Freeze:
			for (list<TheVehicleClass*>::iterator itr = VillanTeam->AIlist.begin(); itr != VillanTeam->AIlist.end(); itr++)
			{
				(*itr)->TheFreedomSpeed = 500;
				(*itr)->Projectile[0]->FreedomSpeed = 400;
			}
			ToDeactivate = LITERALLY_NOTHING;
			break;
		case PowerupManager::Bomb://ntn to do here
			break;
		case PowerupManager::Giant:
			HeroTeam->AIlist.front()->ScaleVehicle(0.5);
			for (int i = 0; i < HeroTeam->AIlist.front()->MaxProjectiles; i++)
				HeroTeam->AIlist.front()->Projectile[i]->TheProjectile.scale(0.5, 0.5);

			ToDeactivate = LITERALLY_NOTHING;
			break;
		case PowerupManager::LITERALLY_NOTHING://ntn to do here
			break;
		default:
			break;
		}
	}
	if (ToDeactivate == Giant)
	{
		for (list<TheVehicleClass*>::iterator itr=VillanTeam->AIlist.begin(); itr != VillanTeam->AIlist.end(); itr++)
		{
			if (HeroTeam->AIlist.front()->TheVehicle.getGlobalBounds().intersects((*itr)->TheVehicle.getGlobalBounds()))
				(*itr)->ReduceHealth(100);
		}
	}

	if (CurrentPowerup != LITERALLY_NOTHING)
	{
		GameWindow.draw(PowerupSprite);
		if (HeroTeam->AIlist.front()->TheVehicle.getGlobalBounds().intersects(PowerupSprite.getGlobalBounds()))
		{
			switch (CurrentPowerup)
			{
			case Bomb:
				for (list<TheVehicleClass*>::iterator itr = VillanTeam->AIlist.begin(); itr != VillanTeam->AIlist.end(); itr++)
					(*itr)->ReduceHealth(100);
				CurrentPowerup = LITERALLY_NOTHING;
				
				//{
				//	sf::Sound bomb; sf::SoundBuffer bmbbfr; bmbbfr.loadFromFile("Data/Sound/Bomb.ogg"); bomb.setBuffer(bmbbfr); bomb.play();
			//	}

				break;
			case FireBullet:
				for (int i = 0; i < HeroTeam->AIlist.front()->MaxProjectiles; i++)
				{
					HeroTeam->AIlist.front()->Projectile[i]->TheProjectileDamage *= 10;
					HeroTeam->AIlist.front()->Projectile[i]->TheProjectile.setColor(sf::Color::Red);
					HeroTeam->AIlist.front()->Projectile[i]->TheProjectile.scale(1.5,1.5);
					HeroTeam->AIlist.front()->Projectile[i]->FreedomSpeed *= 2;
				}
				ToDeactivate = FireBullet;
				break;
			case Freeze:
				for (list<TheVehicleClass*>::iterator itr = VillanTeam->AIlist.begin(); itr != VillanTeam->AIlist.end(); itr++)
				{
					(*itr)->TheFreedomSpeed = 0;
					(*itr)->Projectile[0]->FreedomSpeed= 0;
				}
				ToDeactivate = Freeze;
				break;
			case Giant:
				HeroTeam->AIlist.front()->ScaleVehicle(2);
				for (int i = 0; i < HeroTeam->AIlist.front()->MaxProjectiles; i++)
					HeroTeam->AIlist.front()->Projectile[i]->TheProjectile.scale(2, 2);
				

				ToDeactivate = Giant;
				break;
			case InfiHealth:PlayerVehicle::Tolerance = 1000; PlayerVehicle::PlayerHealth = 100;
				HeroTeam->AIlist.front()->SetVehicleColor(sf::Color::Green);
				ToDeactivate = InfiHealth;
				
				break;
			case Speedup:
				HeroTeam->AIlist.front()->TheFreedomSpeed *= 3;
				HeroTeam->AIlist.front()->SetVehicleColor(sf::Color::Blue);
				ToDeactivate = Speedup;
				break;

			}
			PowerupActivationTimer.restart().asSeconds();
			CurrentPowerup = LITERALLY_NOTHING;
		}
	}
	

}

void PowerupManager::ClaimDeadBodies(pair<int, sf::Vector2f> Bodies)
{
	if (Bodies.second.x != 0)
	{
		//place powerup
		switch (rand()%6)
		{
		case 0:PowerupSpriteTexture.loadFromFile("Data/Textures/Powerup/P_Bomb.png"); CurrentPowerup = Bomb;
			break;
		case 1:PowerupSpriteTexture.loadFromFile("Data/Textures/Powerup/P_FireBullet.png"); CurrentPowerup = FireBullet;
			break;
		case 2:PowerupSpriteTexture.loadFromFile("Data/Textures/Powerup/P_Freeze.png"); CurrentPowerup = Freeze;
			break;
		case 3:PowerupSpriteTexture.loadFromFile("Data/Textures/Powerup/P_Giant.png"); CurrentPowerup = Giant;
		
			break;
		case 4:PowerupSpriteTexture.loadFromFile("Data/Textures/Powerup/P_InfiHealth.png"); CurrentPowerup = InfiHealth;
		
			break;
		case 5:PowerupSpriteTexture.loadFromFile("Data/Textures/Powerup/P_Speed.png"); CurrentPowerup = Speedup;
			break;
		}
		PowerupSprite.setTexture(PowerupSpriteTexture);
		PowerupSprite.setPosition(Bodies.second);
	}
	ScoreCounter += Bodies.first*250;
}
void PowerupManager::CallPower(Powers CalledPower)
{
	switch (CalledPower)
	{
	case PowerupManager::CallTankSupport:
		
			HeroTeam->AIlist.push_back(HeroTeam->GetRandTank());
			(HeroTeam->AIlist.back())->TheVehicle.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
			(HeroTeam->AIlist.back())->sethealth(150);
			(HeroTeam->AIlist.back())->Projectile[0]->SetProjectileDamage(50);
		break;
	case PowerupManager::CallHeliSupport:

		HeroTeam->AIlist.push_back(HeroTeam->GetRandHeli());
		(HeroTeam->AIlist.back())->TheVehicle.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
		(HeroTeam->AIlist.back())->sethealth(200);
		(HeroTeam->AIlist.back())->Projectile[0]->SetProjectileDamage(50);
		break;
	case PowerupManager::CallAirstrike:
		AirStrikeJet = new TheFighterJet(VillanTeam);
		break;
	case PowerupManager::CallTurret:
		HeroTeam->AIlist.push_back(new SentryGun());
		(HeroTeam->AIlist.back())->TheVehicle.setPosition(ScreenDimensions.x / 2, ScreenDimensions.y / 4);
		(HeroTeam->AIlist.back())->sethealth(100);
		(HeroTeam->AIlist.back())->Projectile[0]->SetProjectileDamage(50);
		break;
	default:
		break;
	}
}
