#include "PlayerVehicle.h"

float PlayerVehicle::PlayerHealth;
sf::Sprite PlayerVehicle::JoyDot;
int PlayerVehicle::CrossHairType=1;
sf::Sprite PlayerVehicle::TheCrosshair;
sf::Texture PlayerVehicle::TheCrosshairTexture;
CurrentVehicle PlayerVehicle::CurrentVehicle_;
int PlayerVehicle::Tolerance=4;
TheHUD PlayerVehicle::VehicleHUD;
void PlayerVehicle::ReduceHealth(int ReducingValue)
{
	PlayerVehicle::PlayerHealth = PlayerVehicle::PlayerHealth - ReducingValue / PlayerVehicle::Tolerance;
}

PlayerVehicle::PlayerVehicle()
{
	
	TheVehicleController = Human;
	LowHealthBuffer.loadFromFile("Data/Sound/lowHealth.ogg");
	LowHealth.setBuffer(LowHealthBuffer);
	CurrentVehicle_ = Truck;
	
	PlayerVehicle::PlayerHealth = 100;

	switch (PlayerVehicle::CrossHairType)
	{
	case 0:break;
	case 1:
		PlayerVehicle::TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair1.png");
		PlayerVehicle::TheCrosshair.setTexture(PlayerVehicle::TheCrosshairTexture);
		PlayerVehicle::TheCrosshair.setScale(0.2, 0.2);
		PlayerVehicle::TheCrosshair.setOrigin(289, 291);
		break;
	case 2:
		PlayerVehicle::TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair2.png");
		PlayerVehicle::TheCrosshair.setTexture(PlayerVehicle::TheCrosshairTexture);
		PlayerVehicle::TheCrosshair.setScale(0.2, 0.2);
		PlayerVehicle::TheCrosshair.setOrigin(289, 291);
		break;
	case 3:
		PlayerVehicle::TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair3.png");
		PlayerVehicle::TheCrosshair.setTexture(PlayerVehicle::TheCrosshairTexture);
		PlayerVehicle::TheCrosshair.setScale(0.2, 0.2);
		PlayerVehicle::TheCrosshair.setOrigin(289, 291);
		break;
	case 4:
		PlayerVehicle::TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair4.png");
		PlayerVehicle::TheCrosshair.setTexture(PlayerVehicle::TheCrosshairTexture);
		PlayerVehicle::TheCrosshair.setScale(0.2, 0.2);
		PlayerVehicle::TheCrosshair.setOrigin(289, 291);
		break;
	case 5:
		PlayerVehicle::TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair5.png");
		PlayerVehicle::TheCrosshair.setTexture(PlayerVehicle::TheCrosshairTexture);
		PlayerVehicle::TheCrosshair.setScale(0.2, 0.2);
		PlayerVehicle::TheCrosshair.setOrigin(289, 291);
		break;
	case 6:
		PlayerVehicle::TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair6.png");
		PlayerVehicle::TheCrosshair.setTexture(PlayerVehicle::TheCrosshairTexture);
		PlayerVehicle::TheCrosshair.setScale(0.2, 0.2);
		PlayerVehicle::TheCrosshair.setOrigin(289, 291);
		break;
	}
	PlayerVehicle::TheCrosshair.scale(GlobalScaleFactor);
	
}


PlayerVehicle::~PlayerVehicle()
{
	
}



void PlayerVehicle ::PrimitiveMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y)<-40))
	{
		TheVehicleSpeed += 0.001;
		TheVehicleDirection = 'w';
		TheVehicle.setRotation(-90);
		if (DisallowMovement != 'w')
			TheVehicle.move(0.f, -(TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed));
		IsTheVehicleMoving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y)>40))
	{
		TheVehicleSpeed += 0.001;
		TheVehicleDirection = 's';
		TheVehicle.setRotation(90);
		if (DisallowMovement != 's')
			TheVehicle.move(sf::Vector2f(0.f, (TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed)));
		IsTheVehicleMoving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X)<-40))
	{
		TheVehicleSpeed += 0.001;
		TheVehicleDirection = 'a';
		TheVehicle.setRotation(180);
		if (DisallowMovement != 'a')
			TheVehicle.move(sf::Vector2f(-(TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed), 0.f));
		IsTheVehicleMoving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X)>40))
	{
		TheVehicleSpeed += 0.001;
		TheVehicleDirection = 'd';
		TheVehicle.setRotation(0);
		if (DisallowMovement != 'd')
			TheVehicle.move(sf::Vector2f((TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed), 0.f));
		IsTheVehicleMoving = true;
	}
	else {
		switch (TheVehicleDirection)
		{
		case 'w':if (DisallowMovement != 'w')TheVehicle.move(0.f, -(TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed)); break;
		case 's':if (DisallowMovement != 's')TheVehicle.move(sf::Vector2f(0.f, (TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed))); break;
		case 'a':if (DisallowMovement != 'a')TheVehicle.move(sf::Vector2f(-(TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed), 0.f)); break;
		case 'd':if (DisallowMovement != 'd')TheVehicle.move(sf::Vector2f((TheVehicleSpeed*Freedom.asSeconds()*TheFreedomSpeed), 0.f)); break;
		}
		IsTheVehicleMoving = false;
		if (!(TheVehicleSpeed <= 0.05)) TheVehicleSpeed -= 0.005*Freedom.asSeconds()*TheFreedomSpeed;
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
			if (TheVehicleBoost > 0) TheVehicleBoost -= 0.15*Freedom.asSeconds()*TheFreedomSpeed;
		}
		else { TheVehicle.setColor(TheVehicleColor); BoostIsActive = false; }

		if (TheVehicleBoost > 0) TheVehicleBoost -= 0.15*Freedom.asSeconds()*TheFreedomSpeed;

	}
	else  { BoostIsActive = false;		TheVehicle.setColor(TheVehicleColor); }

}

void PlayerVehicle::AdvancedMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y)<-40))
	{
		TheVehicleSpeed += 0.001;
		IsTheVehicleMoving = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X)<-40))  TheVehicle.rotate(-0.5);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X)>40))  TheVehicle.rotate(0.5);
		TheVehicle.move(cos(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed, sin(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y)>40))
	{
		if (TheVehicleSpeed>0)
			TheVehicleSpeed -= 0.01;
		else TheVehicleSpeed -= 0.001;
		IsTheVehicleMoving = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X)<-40))	 TheVehicle.rotate(-0.5);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Joystick::getAxisPosition(0, sf::Joystick::R)>40))  TheVehicle.rotate(0.5);

		TheVehicle.move(cos(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed / 2, sin(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed / 2);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X)<-40))
	{
		TheVehicle.rotate(-0.2); IsTheVehicleMoving = true;
		TheVehicle.move(cos(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed, sin(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed);
		IsTheVehicleMoving = true;
		if (!(TheVehicleSpeed <= 0.05)) TheVehicleSpeed -= 0.003*Freedom.asSeconds()*TheFreedomSpeed;
		else TheVehicleSpeed = 0;
	}



	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X)>40))
	{
		TheVehicle.rotate(0.2); IsTheVehicleMoving = true;
		TheVehicle.move(cos(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed, sin(TheVehicle.getRotation()*0.017453)*Freedom.asSeconds()*TheFreedomSpeed*TheVehicleSpeed);
		IsTheVehicleMoving = true;
		if (!(TheVehicleSpeed <= 0.05)) TheVehicleSpeed -= 0.003*Freedom.asSeconds()*TheFreedomSpeed;
		else TheVehicleSpeed = 0;
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

}
