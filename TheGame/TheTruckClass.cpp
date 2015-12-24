
#include "TheTruckClass.h"

TheTruckClass::TheTruckClass(TheTruckType TheTrucktype )
{
	
	MaxProjectiles = 0;
	switch (TheTrucktype)
	{
	case ArmyTruck:TheVehicleTexture.loadFromFile("Data/Textures/Truck/Truck.png");
		TheVehicle.setTexture(TheVehicleTexture);
		TheVehicle.setOrigin(129, 57);
		TheVehicle.scale(0.8, 0.8);
		TheVehicleMaxSpeed = 3;
		TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/TheVehicleMoveSound.ogg");
		break;
	
	case Car1:
		TheVehicleTexture.loadFromFile("Data/Textures/Truck/Car.png");
		TheVehicle.setTexture(TheVehicleTexture);
		TheVehicle.setOrigin(84, 42);
		TheVehicleMaxSpeed = 2.5;
		TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/Car1.ogg");
		break;
	case Car2:TheVehicleTexture.loadFromFile("Data/Textures/Truck/Car2.png");
		TheVehicle.setTexture(TheVehicleTexture);
		TheVehicle.setOrigin(99, 47);
		TheVehicleMaxSpeed = 2.5;
		TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/Car1.ogg");
	default:TheVehicleTexture.loadFromFile("Data/Textures/Truck/Car2.png");
		TheVehicle.setTexture(TheVehicleTexture);
		TheVehicle.setOrigin(99, 47);
		TheVehicleMaxSpeed = 2.5;
		TheVehicleMoveSoundBuffer.loadFromFile("Data/Sound/Car1.ogg");
	}

	
	TheVehicleMoveSound.setBuffer(TheVehicleMoveSoundBuffer);
	TheFreedomSpeed = 500;
	//PlayerVehicle::PlayerHealth = 100;
	TheVehicleBoost = 100;
	TheVehicleMaxSpeed = 2;
	VehicleIsAlive = true;
	PlayerVehicle::TheVehicleSpeed = 0.5f;
	TheVehicleBoostSpeed = 5.0f;
	TheVehicle.rotate(-90);
	
	
}


TheTruckClass::~TheTruckClass()
{

}

void TheTruckClass::VehicleHandler()
{
	if (PlayerVehicle::PlayerHealth > 0)
	{

		//--Movement
		AdvancedMovement();
		//MovementSound
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>w>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		if ((IsTheVehicleMoving == true)&&(PlayerVehicle::TheVehicleSpeed!=0))
		{
			if (TheVehicleMoveSound.getStatus() != sf::Sound::Status::Playing)
			{
				TheVehicleMoveSound.play();
			}
		}
		else if (TheVehicleMoveSound.getStatus() == sf::Sound::Status::Playing)
			TheVehicleMoveSound.stop();

		if (PlayerHealth < 30)
		{
			if (LowHealth.getStatus() != sf::Sound::Status::Playing)LowHealth.play();
		}
		
		else LowHealth.stop();
		

		//--HUD & stats
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		
		GameWindow.draw(TheVehicle);
	
		PlayerVehicle::VehicleHUD.HUDHandler(PlayerVehicle::PlayerHealth, PlayerVehicle::TheVehicleSpeed, TheVehicleBoost);
		BoundsCollision();
		

	}
	else
	{
		TheVehicle.setColor(sf::Color::Red);
		GameViewCenter = TheVehicle.getPosition();
		if (!(GameViewZoom <= 0))	{
			GameViewZoom -= 0.0007;
			GameViewRotation += 0.07;
		}
		if (VehicleIsAlive == true) VehicleIsAlive = false;
		GameWindow.draw(TheVehicle);
	}


}

void TheTruckClass::ScaleVehicle(float x)
{
	TheVehicle.scale(x,x);
	
}
void TheTruckClass::SetVehicleColor(sf::Color col)
{
	TheVehicleColor = col;
}