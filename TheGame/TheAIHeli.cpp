#include "TheAIHeli.h"


TheAIHeli::TheAIHeli(TheHeliType TheHeliType,int _Tolerance)
{
	DisallowMovement = 'z';

	TheFreedomSpeed = 500;
	TheVehicleHealth = 100;
	TheVehicleBoost = 100;
	TheVehicleMaxSpeed = 1.3;
	VehicleIsAlive = true;
	TheVehicleSpeed = 0.5f;
	TheVehicleBoostSpeed = 5.0f;

	
	TheRotation = 0;
	srand(time(NULL) + Freedom.asMicroseconds());
	TheVehicleSpeed = 1;
	VehicleType = Advanced;

	
	MaxProjectiles = 1;
	Projectile.push_back(new TheMissileClass);
	Projectile[0]->SetProjectileDamage(20);
	TheFreedomSpeed = 500;
	TheVehicleBoost = 100;
	TheVehicleMaxSpeed = 1.3;
	VehicleIsAlive = true;
	TheVehicleBoostSpeed = 5.0f;

	if (TheHeliType == Apache)
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

	else if (TheHeliType == Hunter)
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

		TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair1.png");
		TheCrosshair.setTexture(TheCrosshairTexture);
		TheCrosshair.setScale(0.2, 0.2);
		TheCrosshair.setOrigin(289, 291);
	TheCrosshair.scale(GlobalScaleFactor);



}


TheAIHeli::~TheAIHeli()
{

	for (std::vector<TheProjectileClass*>::iterator i = Projectile.begin(); i != Projectile.end(); i++)
		delete *i;
}
void TheAIHeli::VehicleHandler()
{
	if (TheVehicleHealth > 4)
	{
		if (TheVehicleMoveSound.getStatus() != sf::Sound::Status::Playing)
		{
			TheVehicleMoveSound.play();
		}

		TheVehicleRotor.setPosition(TheVehicle.getPosition());
		TheVehicleRotor.rotate(3 * Freedom.asSeconds() * 300);
		GameWindow.draw(TheVehicle);
		GameWindow.draw(TheVehicleRotor);
		BoundsCollision();
	}
	else
	{
		TheVehicleRotor.setColor(sf::Color::Red);
		TheVehicleRotor.rotate(TheVehicleMaxSpeed);
		TheVehicleMaxSpeed -= 0.002;
		if (TheVehicleMaxSpeed < 0)TheVehicleMaxSpeed = 0;
		TheVehicleRotor.setPosition(TheVehicle.getPosition());
		if (TheVehicleMoveSound.getStatus() == sf::Sound::Status::Playing)
			TheVehicleMoveSound.stop();
		TheVehicle.setColor(sf::Color::Red);
		if (VehicleIsAlive == true) VehicleIsAlive = false;
		GameWindow.draw(TheVehicle);
	}
}

void  TheAIHeli::ScaleVehicle(float x)
{
	TheVehicle.setScale(TheVehicle.getScale().x * x, TheVehicle.getScale().y*x);
	TheVehicleRotor.setScale(TheVehicleRotor.getScale().x*x, TheVehicleRotor.getScale().y*x);
}
void TheAIHeli::VehicleHandler(TheVehicleClass &TargetVehicle)
{


	if (TheVehicleHealth > 4)
	{
		
		 if ((abs(this->TheVehicle.getPosition().y - TargetVehicle.TheVehicle.getPosition().y) > ScreenDimensions.y*0.55) || (abs(this->TheVehicle.getPosition().x - TargetVehicle.TheVehicle.getPosition().x) > ScreenDimensions.x*0.55))
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
				TheVehicle.setRotation(TheRotation - 90);
				


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
					if (TargetVehicle.VehicleIsAlive == true) Projectile[0]->ReadyToFire(TheVehicle);
					BulletFireClock.restart().asSeconds();
				}



				Projectile[0]->TheProjectileMover(DeltaX, DeltaY, TheRotation, TheVehicle);
			
		}
		

		if (sqrt(pow(Projectile[0]->TheProjectile.getPosition().x - TheVehicle.getPosition().x, 2) + pow(Projectile[0]->TheProjectile.getPosition().y - TheVehicle.getPosition().y, 2)) > ScreenDimensions.x)
		{
			Projectile[0]->TheProjectileSpeed = 0;
			
			Projectile[0]->Acceleration = 1;
			Projectile[0]->TheProjectile.setPosition(-1000, -1000);
		}
		TheVehicle.setColor(TheVehicleColor);
		TheVehicleRotor.setColor(TheVehicleColor);

		TheVehicleRotor.setPosition(TheVehicle.getPosition());
		TheVehicleRotor.rotate(3 * Freedom.asSeconds() * 300);
		GameWindow.draw(TheVehicle);
		GameWindow.draw(TheVehicleRotor);
		GameWindow.draw(Projectile[0]->TheProjectile);
		
		BoundsCollision();
	}
	else
	{
		TheVehicleRotor.setColor(sf::Color::Red);
		TheVehicleRotor.rotate(TheVehicleMaxSpeed);
		TheVehicleMaxSpeed -= 0.002;
		if (TheVehicleMaxSpeed < 0)TheVehicleMaxSpeed = 0;
		TheVehicleRotor.setPosition(TheVehicle.getPosition());
		if (TheVehicleMoveSound.getStatus() == sf::Sound::Status::Playing)
			TheVehicleMoveSound.stop();
		TheVehicle.setColor(sf::Color::Red);
		if (VehicleIsAlive == true) VehicleIsAlive = false;
		GameWindow.draw(TheVehicle);
	}

}