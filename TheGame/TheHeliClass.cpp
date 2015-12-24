#include "TheHeliClass.h"


TheHeliClass::TheHeliClass(TheHeliType TheHeliType)
{
	
	MaxProjectiles = 3;
	Projectile.push_back(new TheMissileClass);
	Projectile.push_back(new TheMissileClass);
	Projectile.push_back(new TheMachineGunClass(2));
	Projectile[0]->SetProjectileDamage(100);
	Projectile[1]->SetProjectileDamage(100);
	Projectile[2]->SetProjectileDamage(3);

	TheFreedomSpeed = 500;
	//PlayerVehicle::PlayerHealth = 100;
	TheVehicleBoost = 100;
	TheVehicleMaxSpeed = 1.3;
	VehicleIsAlive = true;
	PlayerVehicle::TheVehicleSpeed = 0.5f;
	TheVehicleBoostSpeed = 5.0f;
	
	if (TheHeliType==Apache)
	{
		TheVehicleTexture.loadFromFile("Data/Textures/Heli/Heli1Body.png");
		TheVehicle.setTexture(TheVehicleTexture);
		TheVehicle.setPosition(0, ScreenDimensions.y / 2);
		TheVehicle.scale(0.5, 0.5);
		TheVehicle.setOrigin(588, 139);
		TheVehicle.rotate(-90);
		TheVehicleRotorTexture.loadFromFile("Data/Textures/Heli/Heli1Rotor.png");
		TheVehicleRotor.setTexture(TheVehicleRotorTexture);
		TheVehicleRotor.scale(0.4, 0.4);
		TheVehicleRotor.setOrigin(344, 317);
		TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/HeliSound.ogg");
		TheVehicleMoveSound.setBuffer(TheVehicleMoveSoundBuffer);
	}
	
	else if (TheHeliType == Hunter )
	{
		TheVehicleTexture.loadFromFile("Data/Textures/Heli/Heli2Body.png");
		TheVehicle.setTexture(TheVehicleTexture);
		TheVehicle.setPosition(0, ScreenDimensions.y / 2);
		TheVehicle.setOrigin(212, 55);
		TheVehicle.rotate(-90);
		TheVehicle.scale(1.3, 1.3);
		TheVehicleRotorTexture.loadFromFile("Data/Textures/Heli/Heli2Rotor.png");
		TheVehicleRotor.setTexture(TheVehicleRotorTexture);
		TheVehicleRotor.setOrigin(105, 105);
		TheVehicleRotor.scale(1.3, 1.3);
		TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/HeliSound2.ogg");
		TheVehicleMoveSound.setBuffer(TheVehicleMoveSoundBuffer);
	}
	
	TheVehicle.setPosition(sf::Vector2f(400, 400));
	TheVehicle.scale(GlobalScaleFactor);
	TheVehicleMoveSound.setLoop(1);
	TheVehicleRotor.scale(GlobalScaleFactor);
	
	switch (CrossHairType)
		{
		case 0:break;
		case 1:
			TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair1.png");
			TheCrosshair.setTexture(TheCrosshairTexture);
			TheCrosshair.setScale(0.2, 0.2);
			TheCrosshair.setOrigin(289, 291);
			break;
		case 2:
			TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair2.png");
			TheCrosshair.setTexture(TheCrosshairTexture);
			TheCrosshair.setScale(0.2, 0.2);
			TheCrosshair.setOrigin(289, 291);
			break;
		case 3:
			TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair3.png");
			TheCrosshair.setTexture(TheCrosshairTexture);
			TheCrosshair.setScale(0.2, 0.2);
			TheCrosshair.setOrigin(289, 291);
			break;
		case 4:
			TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair4.png");
			TheCrosshair.setTexture(TheCrosshairTexture);
			TheCrosshair.setScale(0.2, 0.2);
			TheCrosshair.setOrigin(289, 291);
			break;
		case 5:
			TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair5.png");
			TheCrosshair.setTexture(TheCrosshairTexture);
			TheCrosshair.setScale(0.2, 0.2);
			TheCrosshair.setOrigin(289, 291);
			break;
		case 6:
			TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair6.png");
			TheCrosshair.setTexture(TheCrosshairTexture);
			TheCrosshair.setScale(0.2, 0.2);
			TheCrosshair.setOrigin(289, 291);
			break;
		}
		TheCrosshair.scale(GlobalScaleFactor);
	

	
}



TheHeliClass::~TheHeliClass()
{

	for (std::vector<TheProjectileClass*>::iterator i = Projectile.begin(); i != Projectile.end(); i++)
		delete *i;
}


void TheHeliClass::VehicleHandler()
{
	if (PlayerVehicle::PlayerHealth > 0)
	{


		//--Movement
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		switch (VehicleType)
		{
		case Primitive:PrimitiveMovement(); break;
		case Advanced: 
			
			
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y)<-40))
			{
				TheVehicleSpeed += 0.001;
				IsTheVehicleMoving = true;
				TheVehicle.move(cos(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed, sin(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y)>40))
			{
				if (TheVehicleSpeed>0)
					TheVehicleSpeed -= 0.01;
				else TheVehicleSpeed -= 0.001;
				IsTheVehicleMoving = true;
				TheVehicle.move(cos(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed / 2, sin(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed / 2);
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X)<-40))
			{
				TheVehicleSpeed += 0.001;
				 IsTheVehicleMoving = true;
				TheVehicle.move(cos((TheVehicle.getRotation()-90)*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed, sin((TheVehicle.getRotation()-90)*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed);
				
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X)>40))
			{
				TheVehicleSpeed += 0.001;
				IsTheVehicleMoving = true;
				TheVehicle.move(cos((TheVehicle.getRotation()+90)*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed, sin((TheVehicle.getRotation()+90)*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed);
				
			}
			else {
				TheVehicle.move(cos(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed, sin(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed);

				IsTheVehicleMoving = true;
				if (!(TheVehicleSpeed <= 0.05)) TheVehicleSpeed -= 0.003*Freedom.asSeconds()*TheFreedomSpeed;
				else TheVehicleSpeed = 0;
			}
			if (VehicleClock.getElapsedTime().asSeconds() > 0.1)
			{
				VehicleClock.restart().asSeconds();
				if (!(TheVehicleBoost > 99)) TheVehicleBoost++;
			}
			if (!BoostIsActive == true)	{ if (TheVehicleSpeed > TheVehicleMaxSpeed)TheVehicleSpeed = TheVehicleMaxSpeed; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Joystick::isButtonPressed(0, 6))
			{
				if (TheVehicleBoost > 5)
				{
					BoostIsActive = true;
					TheVehicleSpeed = TheVehicleBoostSpeed*Freedom.asSeconds()*TheFreedomSpeed;
					TheVehicle.setColor(sf::Color::Blue);
					if (TheVehicleBoost > 0) TheVehicleBoost -= 0.10*Freedom.asSeconds()*TheFreedomSpeed;
				}
				else { TheVehicle.setColor(TheVehicleColor); BoostIsActive = false; }

				if (TheVehicleBoost > 0) TheVehicleBoost -= 0.10*Freedom.asSeconds()*TheFreedomSpeed;

			}
			else  { BoostIsActive = false;		TheVehicle.setColor(TheVehicleColor); }
			if (TheVehicleSpeed == 0)IsTheVehicleMoving = false;
			break;
		}
		//MovementSound
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		if (TheVehicleMoveSound.getStatus() != sf::Sound::Status::Playing)
		{
			TheVehicleMoveSound.play();
		}
		if (PlayerHealth < 30)
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
				PlayerVehicle::TheCrosshair.move(sf::Joystick::getAxisPosition(0, sf::Joystick::Z)*0.015, sf::Joystick::getAxisPosition(0, sf::Joystick::R)*0.015);
		}
		

				
				DeltaX = GlobalMousePosition.x - TheVehicleRotor.getPosition().x;
				DeltaY = GlobalMousePosition.y - TheVehicleRotor.getPosition().y;

				if ((GlobalMousePosition.x - TheVehicleRotor.getPosition().x) < 0)
				{
					TurretRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 270;
				}
				else
				{
					TurretRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 90;
				}
				TheVehicle.setRotation(TurretRotation-90);
				//rocket
				if ((sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || (sf::Joystick::isButtonPressed(0, 7))) && BulletFireClock.getElapsedTime().asSeconds() > 0.2 && (Projectile[0]->TheProjectileSpeed == 0 || Projectile[1]->TheProjectileSpeed == 0))
				{
					if (CurrentMissile==1)
					{
						Projectile[0]->ReadyToFire(TheVehicle); CurrentMissile = 0;
					}
					else
					{
						Projectile[1]->ReadyToFire(TheVehicle); CurrentMissile = 1;
					}

					BulletFireClock.restart().asSeconds();
				}
				
				
				if (sqrt(pow(Projectile[0]->TheProjectile.getPosition().x - TheVehicle.getPosition().x, 2) + pow(Projectile[0]->TheProjectile.getPosition().y - TheVehicle.getPosition().y, 2)) >ScreenDimensions.x)
				{
					Projectile[0]->TheProjectileSpeed = 0;
					Projectile[0]->Acceleration = 1;
					Projectile[0]->TheProjectile.setPosition(-1000, -1000);
				}
				Projectile[0]->TheProjectileMover(DeltaX, DeltaY, TurretRotation, TheVehicle);

				if (sqrt(pow(Projectile[1]->TheProjectile.getPosition().x - TheVehicle.getPosition().x, 2) + pow(Projectile[1]->TheProjectile.getPosition().y - TheVehicle.getPosition().y, 2)) >ScreenDimensions.x)
				{
					Projectile[1]->TheProjectileSpeed = 0;
					Projectile[1]->Acceleration = 1;
					Projectile[1]->TheProjectile.setPosition(-1000, -1000);
					
				}
				Projectile[1]->TheProjectileMover(DeltaX, DeltaY, TurretRotation, TheVehicle);


				//MachineGun
				if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || (sf::Joystick::isButtonPressed(0, 5))) && (Projectile[2]->TheProjectileSpeed == 0) && MissileFireClock.getElapsedTime().asSeconds() > 0.01)
				{
			
					Projectile[2]->ReadyToFire(TheVehicle);
					
				}
				

			//	if ((LightProjectile.TheProjectile.getPosition().x<0 || LightProjectile.TheProjectile.getPosition().x>sf::VideoMode::getDesktopMode().width) || (LightProjectile.TheProjectile.getPosition().y<0 || LightProjectile.TheProjectile.getPosition().y>sf::VideoMode::getDesktopMode().height))
				if (sqrt(pow(Projectile[2]->TheProjectile.getPosition().x - TheVehicle.getPosition().x, 2) + pow(Projectile[2]->TheProjectile.getPosition().y - TheVehicle.getPosition().y, 2)) >900)
				{
					Projectile[2]->TheProjectileSpeed = 0;
					Projectile[2]->TheProjectile.setPosition(-1000, -1000);
				}
				Projectile[2]->TheProjectileMover(DeltaX, DeltaY, TurretRotation, TheVehicle);

		//--HUD & stats
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		


		TheVehicleRotor.setPosition(TheVehicle.getPosition());
		TheVehicleRotor.rotate(3 * Freedom.asSeconds() * 300);

		GameWindow.draw(TheVehicle);
		GameWindow.draw(TheVehicleRotor);
		GameWindow.draw(PlayerVehicle::TheCrosshair);
		
		GameWindow.draw(Projectile[0]->TheProjectile);
		GameWindow.draw(Projectile[1]->TheProjectile);
		GameWindow.draw(Projectile[2]->TheProjectile);
		PlayerVehicle::VehicleHUD.HUDHandler(PlayerVehicle::PlayerHealth, PlayerVehicle::TheVehicleSpeed, TheVehicleBoost);
		BoundsCollision();
	}
	else
	{
		TheVehicle.setColor(sf::Color::Red);
		TheVehicleRotor.setColor(sf::Color::Red);
		TheVehicleRotor.rotate(TheVehicleMaxSpeed);
		TheVehicleMaxSpeed -= 0.002;
		if (TheVehicleMaxSpeed < 0)TheVehicleMaxSpeed = 0;
		TheVehicleRotor.setPosition(TheVehicle.getPosition());
		TheVehicleMoveSound.stop();
		Projectile[2]->TheProjectileSound.stop();
		Projectile[1]->TheProjectileSound.stop();
		Projectile[0]->TheProjectileSound.stop();
		if (VehicleIsAlive == true) VehicleIsAlive = false;

		GameViewCenter = TheVehicle.getPosition();
		if (!(GameViewZoom <= 0))	{
			GameViewZoom -= 0.0008;
			GameViewRotation += 0.08;
		}
		GameWindow.draw(TheVehicle);
		GameWindow.draw(TheVehicleRotor);
	}


}


void TheHeliClass::ScaleVehicle(float x)
{
	TheVehicle.scale(x, x);
	TheVehicleRotor.scale(x, x);
}
void TheHeliClass::SetVehicleColor(sf::Color col)
{
	TheVehicleColor = col;
	TheVehicleRotor.setColor(col);
}