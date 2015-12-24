#include "TheAITank.h"


TheAITank::TheAITank(TheTankType TheTankType ,string _MovementType)
{
	
	X20 = 800;
	DisallowMovement = 'z';
	 Bogus = 0;
	 Projectile.push_back(new TheBulletClass);
	 Projectile[0]->SetProjectileDamage(15);
	 TheFreedomSpeed = 500;
	 TheVehicleHealth = 100;
	 TheVehicleBoost = 100;
	 TheVehicleMaxSpeed = 1.3;
	 VehicleIsAlive = true;
	 TheVehicleSpeed = 0.5f;
	 TheVehicleBoostSpeed = 5.0f;
	 MaxProjectiles = 1;
	
	TheRotation = 0;
	TheMoveDirection = 'z';
	TheTracer[0].setSize(sf::Vector2f(ScreenDimensions.x, 3));;
	TheTracer[1].setSize(sf::Vector2f(3, ScreenDimensions.y));;
	TheTracer[0].setFillColor(sf::Color::Green);
	TheTracer[1].setFillColor(sf::Color::Red);
	MoveMentType = _MovementType;
	srand(time(NULL) + Freedom.asMicroseconds());
	TheVehicleSpeed = 1;
	VehicleType = Advanced;
	switch (VehicleType)
	{
	case Primitive:

		switch (TheTankType)
		{
		case HoneyBadger:
			TheVehicleTexture.loadFromFile("Data/Tank/Type1_HoneyBadgerBody.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound.ogg");
			TheVehicle.setOrigin(81, 42);
			TheVehicle.scale(0.8, 0.8);
			break;
		case HankTheTank:
			TheVehicleTexture.loadFromFile("Data/Tank/Type2_HankTheTankBody.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound2.ogg");
			TheVehicle.scale(0.8, 0.8);
			TheVehicle.setOrigin(82, 41);
			break;
		case Centurion:
			TheVehicleTexture.loadFromFile("Data/Tank/Type3_CenturionBody.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound3.ogg");
			TheVehicle.scale(0.8, 0.8);
			TheVehicle.setOrigin(72, 41);
			break;
		case Crusader:
			TheVehicleTexture.loadFromFile("Data/Tank/Type4_CrusaderBody.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound4.ogg");
			TheVehicle.scale(1.3, 1.3);
			TheVehicle.setOrigin(65, 19);
			break;
		case Challenger:
			TheVehicleTexture.loadFromFile("Data/Tank/Type5_ChallengerBody.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound.ogg");
			TheVehicle.scale(0.6, 0.6);
			TheVehicle.setOrigin(117.3, 63.6);
			break;
		case BlackPrince:
			TheVehicleTexture.loadFromFile("Data/Tank/Type6_BlackPrinceBody.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound2.ogg");
			TheVehicle.scale(1.4, 1.4);
			TheVehicle.setOrigin(56, 29);
			break;
		case Dreadnaught:
			TheVehicleTexture.loadFromFile("Data/Tank/Type7_DreadNaughtBody.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound2.ogg");
			TheVehicle.setOrigin(73, 39);
			break;
		case Juggernaut:
			TheVehicleTexture.loadFromFile("Data/Tank/Type8_Juggernaut.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound4.ogg");
			TheVehicle.setOrigin(109,49);
			break;
		case Type80:
			TheVehicleTexture.loadFromFile("Data/Tank/Type9_Type80.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound.ogg");
			TheVehicle.setOrigin(97, 44);	
		default:
			break;
		}
		break;
	case Advanced:

		switch (TheTankType)
		{
		case HoneyBadger:

			TheVehicleTexture.loadFromFile("Data/Tank/Type1_HoneyBadgerBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type1_HoneyBadgerTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound.ogg");
			TheVehicle.setOrigin(81, 42);
			TheVehicle.scale(0.8, 0.8);
			TheTurret.setOrigin(28, 135);
			TheTurret.scale(0.8, 0.8);
			break;
		case HankTheTank:
			TheVehicleTexture.loadFromFile("Data/Tank/Type2_HankTheTankBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type2_HankTheTankTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound2.ogg");
			TheVehicle.scale(0.8, 0.8);
			TheTurret.scale(0.8, 0.8);
			TheVehicle.setOrigin(82, 41);
			TheTurret.setOrigin(31, 89);
			break;
		case Centurion:
			TheVehicleTexture.loadFromFile("Data/Tank/Type3_CenturionBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type3_CenturionTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound3.ogg");
			TheVehicle.scale(0.8, 0.8);
			TheTurret.scale(0.8, 0.8);
			TheVehicle.setOrigin(72, 41);
			TheTurret.setOrigin(33, 138);
			break;
		case Crusader:
			TheVehicleTexture.loadFromFile("Data/Tank/Type4_CrusaderBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type4_CrusaderTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound4.ogg");
			TheVehicle.scale(1.3, 1.3);
			TheTurret.scale(1.3, 1.3);
			TheVehicle.setOrigin(65, 19);
			TheTurret.setOrigin(18, 66);
			break;
		case Challenger:
			TheVehicleTexture.loadFromFile("Data/Tank/Type5_ChallengerBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type5_ChallengerTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound.ogg");
			TheVehicle.scale(0.6, 0.6);
			TheTurret.scale(0.5, 0.5);
			TheVehicle.setOrigin(117.3, 63.6);
			TheTurret.setOrigin(50.5, 185.38);
			break;
		case BlackPrince:
			TheVehicleTexture.loadFromFile("Data/Tank/Type6_BlackPrinceBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type6_BlackPrinceTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound2.ogg");
			TheVehicle.scale(1.4, 1.4);
			TheTurret.scale(1.4, 1.4);
			TheVehicle.setOrigin(56, 29);
			TheTurret.setOrigin(41, 67);
			break;
		case Dreadnaught:
			TheVehicleTexture.loadFromFile("Data/Tank/Type7_DreadNaughtBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type7_DreadNaughtTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound2.ogg");
			TheVehicle.setOrigin(73, 39);
			TheTurret.setOrigin(26, 76);
			break;
		case Juggernaut:
			TheVehicleTexture.loadFromFile("Data/Tank/Type8_JuggernautBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type8_JuggernautTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound4.ogg");
			TheVehicle.setOrigin(109, 49);
			TheTurret.setOrigin(49, 109);
			break;
		case Type80:
			TheVehicleTexture.loadFromFile("Data/Tank/Type9_Type80Body.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type9_Type80Turret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound.ogg");
			TheVehicle.setOrigin(97, 44);
			TheTurret.setOrigin(46, 150);
		default:
			break;
		}

		break;
	default:
		break;
	}
	TheVehicle.setTexture(TheVehicleTexture);
	TheVehicle.setPosition(sf::Vector2f(400, 400));
	TheVehicle.scale(GlobalScaleFactor);
	TheVehicleMoveSound.setBuffer(TheVehicleMoveSoundBuffer);
	TheVehicleMoveSound.setLoop(1);
	TheTurret.setTexture(TheTurretTexture);
	TheTurret.scale(GlobalScaleFactor);
	TheTurret.setRotation(90);
	TheTurret.setPosition(-1900, 0);
	TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair1.png");
	TheCrosshair.setTexture(TheCrosshairTexture);
	TheCrosshair.setScale(0.2, 0.2);
	TheCrosshair.setOrigin(289, 291);
	
}


TheAITank::~TheAITank()
{

	for (std::vector<TheProjectileClass*>::iterator i = Projectile.begin(); i != Projectile.end(); i++)
		delete *i;
}
void TheAITank::ScaleVehicle(float x)
{
	TheVehicle.setScale(TheVehicle.getScale().x * x, TheVehicle.getScale().y*x);
	TheTurret.setScale(TheTurret.getScale().x*x, TheTurret.getScale().y*x);
}

void TheAITank::VehicleHandler(TheVehicleClass &TargetVehicle )
{
	
	if (TheVehicleHealth > 4)
	{
		if ((abs(this->TheVehicle.getPosition().y - TargetVehicle.TheVehicle.getPosition().y) > ScreenDimensions.y*0.6) || (abs(this->TheVehicle.getPosition().x - TargetVehicle.TheVehicle.getPosition().x) > ScreenDimensions.x*0.6))MoveMentType = "Tracker";
			if (abs(this->TheVehicle.getPosition().y - TargetVehicle.TheVehicle.getPosition().y) < ScreenDimensions.y*0.4)MoveMentType = "Random";
			//MOVEMENT
			//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			
		
				if (MoveMentType == "Random")
					RandomMovement();
				else if (MoveMentType == "X")
					XMovement();
				else if (MoveMentType == "Y")
					YMovement();
				else if (MoveMentType == "Tracker")
					TrackerMovement(TargetVehicle.TheVehicle);
			
			
			
				


			//sound

			if (TheVehicleMoveSound.getStatus() != sf::Sound::Status::Playing)
				{
					TheVehicleMoveSound.play();
				}
			
			//FIRE
			//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			if (abs(this->TheVehicle.getPosition().y - TargetVehicle.TheVehicle.getPosition().y) < ScreenDimensions.y*0.6)
			{
				switch (VehicleType)
				{
				case Primitive:

					if (TheTracer[0].getGlobalBounds().intersects(TargetVehicle.TheVehicle.getGlobalBounds()) && (TargetVehicle.VehicleIsAlive == true))
					{
						if (TargetVehicle.TheVehicle.getPosition().x > TheVehicle.getPosition().x) { TheMoveDirection = 'd'; TheRotation = 0; }
						else if (TargetVehicle.TheVehicle.getPosition().x < TheVehicle.getPosition().x) { TheMoveDirection = 'a'; TheRotation = 180; }

						if ((BulletFireClock.getElapsedTime().asSeconds() > 1) && (Projectile[0]->TheProjectileSpeed == 0)&&rand()%5<3)
						{
							Projectile[0]->ReadyToFire(TheVehicle);
							BulletFireClock.restart().asSeconds();
						}
					}
					else if (TheTracer[1].getGlobalBounds().intersects(TargetVehicle.TheVehicle.getGlobalBounds()) && (TargetVehicle.VehicleIsAlive == true) && rand() % 5<3)
					{
						if (TargetVehicle.TheVehicle.getPosition().y > TheVehicle.getPosition().y){ TheMoveDirection = 's'; TheRotation = 90; }
						if (TargetVehicle.TheVehicle.getPosition().y < TheVehicle.getPosition().y) { TheMoveDirection = 'w'; TheRotation = 270; }
						if (BulletFireClock.getElapsedTime().asSeconds() > 1)
						{
							Projectile[0]->ReadyToFire(TheVehicle);
							BulletFireClock.restart().asSeconds();
						}

					}
					Projectile[0]->TheProjectileMover(TankTypeBool, Bogus, TheRotation, TheVehicle);
					TheTracer[0].setOrigin(TheVehicle.getPosition().x, 2); TheTracer[0].setPosition(TheVehicle.getPosition().x, TheVehicle.getPosition().y);
					TheTracer[1].setOrigin(2, TheVehicle.getPosition().y); TheTracer[1].setPosition(TheVehicle.getPosition().x, TheVehicle.getPosition().y);
					break;
				case Advanced:

					TheTurret.setPosition(TheVehicle.getPosition().x, TheVehicle.getPosition().y);
					TheCrosshair.setPosition(TargetVehicle.TheVehicle.getPosition().x, TargetVehicle.TheVehicle.getPosition().y);

					DeltaX = TargetVehicle.TheVehicle.getPosition().x - TheVehicle.getPosition().x;
					DeltaY = TargetVehicle.TheVehicle.getPosition().y - TheVehicle.getPosition().y;

					if ((TargetVehicle.TheVehicle.getPosition().x - TheVehicle.getPosition().x) < 0)
					{
						TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 270;
					}
					else
					{
						TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 90;
					}

					TheTurret.setRotation(TheRotation);


					if (BulletFireClock.getElapsedTime().asSeconds() > 1 && (Projectile[0]->TheProjectileSpeed == 0) && rand() % 5<2)
					{
						DeltaX = TargetVehicle.TheVehicle.getPosition().x - TheVehicle.getPosition().x;
						DeltaY = TargetVehicle.TheVehicle.getPosition().y - TheVehicle.getPosition().y;
						if ((TargetVehicle.TheVehicle.getPosition().x - TheVehicle.getPosition().x) < 0)
						{
							TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 270;
						}
						else
						{
							TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 90;
						}
						if (TargetVehicle.VehicleIsAlive == true) Projectile[0]->ReadyToFire(TheTurret);
						BulletFireClock.restart().asSeconds();
					}



					Projectile[0]->TheProjectileMover(DeltaX, DeltaY, TheRotation, TheTurret);
					break;

				default:
					break;
				}
			}
			else{ TheTurret.setPosition(TheVehicle.getPosition().x, TheVehicle.getPosition().y);  TheTurret.setRotation(TheVehicle.getRotation()); }
			

			if (sqrt(pow(Projectile[0]->TheProjectile.getPosition().x - TheVehicle.getPosition().x, 2) + pow(Projectile[0]->TheProjectile.getPosition().y - TheVehicle.getPosition().y, 2)) > ScreenDimensions.x)
			{
				Projectile[0]->TheProjectileSpeed = 0;
				Projectile[0]->TheProjectile.setPosition(-1000, -1000);
			}
			TheVehicle.setColor(TheVehicleColor);
			TheTurret.setColor(TheVehicleColor);
			GameWindow.draw(TheVehicle);
			GameWindow.draw(Projectile[0]->TheProjectile);
			if (VehicleType == Advanced)GameWindow.draw(TheTurret);
		//	GameWindow.draw(TheCrosshair);
			BoundsCollision();
		}
		else
		{
			//if (!DidIPlayDeathSound){ TheVehicleClass::VehicleDeath.play(); DidIPlayDeathSound = true; }
			if (TheVehicleMoveSound.getStatus() == sf::Sound::Status::Playing)
				TheVehicleMoveSound.stop();
			TheVehicle.setColor(sf::Color::Red);
			if (VehicleIsAlive == true) VehicleIsAlive = false;
			GameWindow.draw(TheVehicle);
		}
	
	
}

void TheAITank::VehicleHandler()
{
	
	RandomMovement();
	if (TheVehicleMoveSound.getStatus() != sf::Sound::Status::Playing)
	{
		TheVehicleMoveSound.play();
	}
	TheTurret.setPosition(TheVehicle.getPosition().x, TheVehicle.getPosition().y);
	TheTurret.setRotation(TheVehicle.getRotation()+90);
	GameWindow.draw(TheVehicle);
	
	if (VehicleType == Advanced)GameWindow.draw(TheTurret);

	BoundsCollision();
}



void TheAITank::RandomMovement()
{
	if (!(TheMoveDistance > 0))
	{
		switch (rand() % 4)
		{
		case 0:TheMoveDirection = 'w'; break;
		case 1:TheMoveDirection = 's'; break;
		case 2:TheMoveDirection = 'a'; break;
		case 3:TheMoveDirection = 'd'; break;
		}
	}
	std::uniform_int_distribution<int> distributionX(1, 600);
	if (!(TheMoveDistance>0)) TheMoveDistance = distributionX(generator);

	switch (TheMoveDirection)
	{
	case 'w':
		TheVehicleDirection = 'w';
		TheVehicle.setRotation(-90);
		if (TheMoveDistance>0 && (DisallowMovement != 'w')) TheVehicle.move(sf::Vector2f(0.f, -(TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed)));
		TheMoveDistance--;
		break;
	case 's':
		TheVehicleDirection = 's';
		TheVehicle.setRotation(90);
		if (TheMoveDistance>0 && (DisallowMovement != 's'))  TheVehicle.move(sf::Vector2f(0.f, (TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed)));
		TheMoveDistance--;
		break;
	case 'a':
		TheVehicleDirection = 'a';
		TheVehicle.setRotation(180);
		if (TheMoveDistance>0 && (DisallowMovement != 'a')) 	TheVehicle.move(sf::Vector2f(-(TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed), 0.f));
		TheMoveDistance--;
		break;
	case 'd':
		TheVehicleDirection = 'd';
		TheVehicle.setRotation(0);
		if (TheMoveDistance>0 && (DisallowMovement != 'd'))  	TheVehicle.move(sf::Vector2f((TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed), 0.f));
		TheMoveDistance--;
		break;
	default: break;

	}
}

void TheAITank::XMovement()
{
	if (TheMoveDirection == 'z')TheMoveDirection = 'd';
	if (TheVehicle.getPosition().x > ScreenDimensions.x*0.85)
		TheMoveDirection = 'a';
	if (TheVehicle.getPosition().x < ScreenDimensions.x*0.1)
		TheMoveDirection = 'd';

	switch (TheMoveDirection)
	{
	case 'a':
		TheVehicleDirection = 'a';
		TheVehicle.setRotation(180);
			TheVehicle.move(sf::Vector2f(-(TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed), 0.f));
		break;
	case 'd':
		TheVehicleDirection = 'd';
		TheVehicle.setRotation(0);
	 	TheVehicle.move(sf::Vector2f((TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed), 0.f));
		break;
	default: break;
	}
}

void TheAITank::YMovement()
{
	if (TheMoveDirection == 'z')TheMoveDirection = 's';

	if (TheVehicle.getPosition().y > ScreenDimensions.y*0.8)
		TheMoveDirection = 'w';
	if (TheVehicle.getPosition().y < ScreenDimensions.y*0.1)
		TheMoveDirection = 's';

	switch (TheMoveDirection)
	{
	case 'w':
		TheVehicleDirection = 'w';
		TheVehicle.setRotation(-90);
		 TheVehicle.move(sf::Vector2f(0.f, -(TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed)));
		break;
	case 's':
		TheVehicleDirection = 's';
		TheVehicle.setRotation(90);
		 TheVehicle.move(sf::Vector2f(0.f, (TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed)));
		break;
	default: break;

	}
}



void TheAITank::MoveUp()
{
	TheVehicle.move(0, -1);
}




