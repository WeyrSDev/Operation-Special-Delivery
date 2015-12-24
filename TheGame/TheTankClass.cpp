#include "TheTankClass.h"


TheTankClass::TheTankClass(TheTankType TheTankType)
{

	MaxProjectiles = 3;
	Projectile.push_back(new TheBulletClass);
	Projectile.push_back(new TheBulletClass);
	Projectile.push_back(new TheMachineGunClass(1));
	Projectile[0]->SetProjectileDamage(50);
	Projectile[1]->SetProjectileDamage(50);
	Projectile[2]->SetProjectileDamage(7);
	
	TheFreedomSpeed = 500;
//	PlayerVehicle::PlayerHealth = 100;
	TheVehicleBoost = 100;
	
	TheVehicleMaxSpeed = 1.3;
	VehicleIsAlive = true;
	PlayerVehicle::TheVehicleSpeed = 0.5f;
	TheVehicleBoostSpeed = 5.0f;
	switch (VehicleType)
	{
	case Primitive:

		switch (TheTankType)
		{
		case HoneyBadger:
			TheVehicleTexture.loadFromFile("Data/Tank/Type1_HoneyBadger.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound.ogg");
			TheVehicle.setOrigin(81, 42);
			TheVehicle.setScale(0.8, 0.8);
			break;
		case HankTheTank:
			TheVehicleTexture.loadFromFile("Data/Tank/Type2_HankTheTank.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound2.ogg");
			TheVehicle.setScale(0.8, 0.8);
			TheVehicle.setOrigin(82, 41);
			break;
		case Centurion:
			TheVehicleTexture.loadFromFile("Data/Tank/Type3_Centurion.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound3.ogg");
			TheVehicle.setScale(0.8, 0.8);
			TheVehicle.setOrigin(72, 41);
			break;
		case Crusader:
			TheVehicleTexture.loadFromFile("Data/Tank/Type4_Crusader.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound4.ogg");
			TheVehicle.setScale(1.3, 1.3);
			TheVehicle.setOrigin(65, 19);
			break;
		case Challenger:
			TheVehicleTexture.loadFromFile("Data/Tank/Type5_Challenger.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound.ogg");
			TheVehicle.setScale(0.6, 0.6);
			TheVehicle.setOrigin(117.3, 63.6);
			break;
		case BlackPrince:
			TheVehicleTexture.loadFromFile("Data/Tank/Type6_BlackPrince.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound2.ogg");
			TheVehicle.setScale(1.4, 1.4);
			TheVehicle.setOrigin(56, 29);
			break;
		case Dreadnaught:
			TheVehicleTexture.loadFromFile("Data/Tank/Type7_DreadNaught.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound2.ogg");
			TheVehicle.setOrigin(73, 39);
		case Juggernaut:
			TheVehicleTexture.loadFromFile("Data/Tank/Type8_Juggernaut.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound4.ogg");
			TheVehicle.setOrigin(49,109);
			break;
		case Type80:
			TheVehicleTexture.loadFromFile("Data/Tank/Type9_Type80.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound.ogg");
			TheVehicle.setOrigin(97, 44);
			break;
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
			TheVehicle.setOrigin(82,41);
			TheTurret.setOrigin(31,89);
			break;
		case Centurion:
			TheVehicleTexture.loadFromFile("Data/Tank/Type3_CenturionBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type3_CenturionTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound3.ogg");
			TheVehicle.scale(0.8, 0.8);
			TheTurret.scale(0.8, 0.8);
			TheVehicle.setOrigin(72,41);
			TheTurret.setOrigin(33,138);
			break;
		case Crusader:
			TheVehicleTexture.loadFromFile("Data/Tank/Type4_CrusaderBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type4_CrusaderTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound4.ogg");
			TheVehicle.scale(1.3, 1.3);
			TheTurret.scale(1.3, 1.3);
			TheVehicle.setOrigin(65,19);
			TheTurret.setOrigin(18,66);
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
			TheVehicle.setOrigin(56,29);
			TheTurret.setOrigin(41,67);
			break;
		case Dreadnaught:
			TheVehicleTexture.loadFromFile("Data/Tank/Type7_DreadNaughtBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type7_DreadNaughtTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound2.ogg");
			TheVehicle.setOrigin(73,39);
			TheTurret.setOrigin(26,76);
			break;
		case Juggernaut:
			TheVehicleTexture.loadFromFile("Data/Tank/Type8_JuggernautBody.png");
			TheTurretTexture.loadFromFile("Data/Tank/Type8_JuggernautTurret.png");
			TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound4.ogg");
			TheVehicle.setOrigin(109, 49);
			TheTurret.setOrigin(49, 109);
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
	
}







TheTankClass::~TheTankClass()
{

	for (std::vector<TheProjectileClass*>::iterator i = Projectile.begin(); i != Projectile.end(); i++)
		delete *i;
}


void TheTankClass::VehicleHandler()
{
	if (PlayerVehicle::PlayerHealth > 0)
	{

		
		//--Movement
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		switch (VehicleType)
		{
			case Primitive://---------------------------------------PRIMITIVE-----------------------------------------------------------------
				PrimitiveMovement();
				break;
			case Advanced://-----------------------------------------ADVANCED-------------------------------------------
			AdvancedMovement();
			break;
		}
		



		//MovementSound
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		if (IsTheVehicleMoving == true)
		{
			if (TheVehicleMoveSound.getStatus() != sf::Sound::Status::Playing)
			{
				TheVehicleMoveSound.play();
			}
		}
		else if (TheVehicleMoveSound.getStatus() == sf::Sound::Status::Playing)
			TheVehicleMoveSound.stop();
	

		if (PlayerHealth < 50)
		{
			if (LowHealth.getStatus() != sf::Sound::Status::Playing)LowHealth.play();
		}
		
		else LowHealth.stop();
		
		
		//--Firing
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		
		switch (IsjoystickConnected)
		{
		case 0:PlayerVehicle::TheCrosshair.setPosition(GlobalMousePosition);
			break;
		case 1:
			if (abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Z)) > 10 || abs(sf::Joystick::getAxisPosition(0, sf::Joystick::R)) > 10)
			{
				PlayerVehicle::TheCrosshair.move(sf::Joystick::getAxisPosition(0, sf::Joystick::Z)*0.015, sf::Joystick::getAxisPosition(0, sf::Joystick::R)*0.025);
				
			}
			//TheCrosshair.setPosition(TheCrosshair.getPosition().x, TheCrosshair.getPosition().y + );
			}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)  || (sf::Joystick::isButtonPressed(0, 6)))
				{
					TheTurret.setColor(TheVehicle.getColor());
				}
				else TheTurret.setColor(TheVehicleColor);

				TheTurret.setPosition(TheVehicle.getPosition().x, TheVehicle.getPosition().y);
				DeltaX = PlayerVehicle::TheCrosshair.getPosition().x - TheTurret.getPosition().x;
				DeltaY = PlayerVehicle::TheCrosshair.getPosition().y - TheTurret.getPosition().y;

				if ((PlayerVehicle::TheCrosshair.getPosition().x - TheTurret.getPosition().x) < 0)
				{
					TurretRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 270;
				}
				else
				{
					TurretRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 90;
				}
				
				TheTurret.setRotation(TurretRotation);


				
				if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Joystick::isButtonPressed(0, 7)) && BulletFireClock.getElapsedTime().asSeconds() > 0.2 && (Projectile[0]->TheProjectileSpeed == 0 || Projectile[1]->TheProjectileSpeed == 0))
				{
					if (CurrentBullet == 1)
					{
						Projectile[0]->ReadyToFire(TheVehicle); CurrentBullet = 0;
					}
					else
					{
						Projectile[1]->ReadyToFire(TheVehicle); CurrentBullet = 1;
					}

					BulletFireClock.restart().asSeconds();
				}
				
				Projectile[0]->TheProjectileMover(DeltaX, DeltaY, TurretRotation, TheTurret);
				Projectile[1]->TheProjectileMover(DeltaX, DeltaY, TurretRotation, TheTurret);
				
		
				if ((sf::Mouse::isButtonPressed(sf::Mouse::Right) || (sf::Joystick::isButtonPressed(0, 5))) && (Projectile[2]->TheProjectileSpeed == 0) && (MGunFireClock.getElapsedTime().asSeconds() > 0.001))
		{

					Projectile[2]->ReadyToFire(TheVehicle);

		}
		
				if (sqrt(pow(Projectile[2]->TheProjectile.getPosition().x - TheVehicle.getPosition().x, 2) + pow(Projectile[2]->TheProjectile.getPosition().y - TheVehicle.getPosition().y, 2)) >900)
		{
					Projectile[2]->TheProjectileSpeed = 0;
					Projectile[2]->TheProjectile.setPosition(-1000, -1000);
		}
				Projectile[2]->TheProjectileMover(DeltaX, DeltaY, TurretRotation, TheVehicle);


				if (sqrt(pow(Projectile[0]->TheProjectile.getPosition().x - TheVehicle.getPosition().x, 2) + pow(Projectile[0]->TheProjectile.getPosition().y - TheVehicle.getPosition().y, 2)) >ScreenDimensions.x)
		{
					Projectile[0]->TheProjectileSpeed = 0;
					Projectile[0]->TheProjectile.setPosition(-1000, -1000);
		}
				if (sqrt(pow(Projectile[1]->TheProjectile.getPosition().x - TheVehicle.getPosition().x, 2) + pow(Projectile[1]->TheProjectile.getPosition().y - TheVehicle.getPosition().y, 2)) >ScreenDimensions.x)
		{
					Projectile[1]->TheProjectileSpeed = 0;
					Projectile[1]->TheProjectile.setPosition(-1000, -1000);
		}
		

		//--HUD & stats
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		

		GameWindow.draw(TheVehicle);
		if (VehicleType== Advanced) GameWindow.draw(TheTurret);
		if (VehicleType == Advanced) GameWindow.draw(PlayerVehicle::TheCrosshair);
		PlayerVehicle::VehicleHUD.HUDHandler(PlayerVehicle::PlayerHealth, PlayerVehicle::TheVehicleSpeed, TheVehicleBoost);
		GameWindow.draw(Projectile[0]->TheProjectile);
		GameWindow.draw(Projectile[1]->TheProjectile);
		GameWindow.draw(Projectile[2]->TheProjectile);
		BoundsCollision();
	}
	else
	{
		TheVehicle.setColor(sf::Color::Red);
		TheTurret.setColor(sf::Color::Red);
		GameViewCenter= TheVehicle.getPosition();
		if (!(GameViewZoom <= 0))	{
			GameViewZoom -= 0.0007;
			GameViewRotation += 0.07;
		}
		if (VehicleIsAlive == true) VehicleIsAlive = false;
		GameWindow.draw(TheVehicle);
		GameWindow.draw(TheTurret);
	}
	
	
}

void TheTankClass::ScaleVehicle(float x)
{
	TheVehicle.setScale(TheVehicle.getScale().x * x, TheVehicle.getScale().y*x);
	TheTurret.setScale(TheTurret.getScale().x*x, TheTurret.getScale().y*x);
}
void TheTankClass::SetVehicleColor(sf::Color col)
{
	TheVehicleColor = col;
	
	TheTurret.setColor(col);
}