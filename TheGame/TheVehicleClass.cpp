#include "TheVehicleClass.h"


sf::Sound TheVehicleClass::VehicleDeath;
sf::SoundBuffer TheVehicleClass::VehicleDeathBuffer;
TheVehicleClass::TheVehicleClass()
{
	TheVehicleHealth = 100;
	//TheVehicleClass::VehicleDeathBuffer.loadFromFile("Data/Sound/TankDeath.ogg");
	//TheVehicleClass::VehicleDeath.setBuffer(TheVehicleClass::VehicleDeathBuffer);
	
}


TheVehicleClass::~TheVehicleClass()
{

	
}

void TheVehicleClass::SetVehicleColor(sf::Color col)
{
	                                  
}
bool TheVehicleClass::DoYouContainPowerup()
{
	return false;
}
void TheVehicleClass::MakeMeContainPowerup()
{

}
void TheVehicleClass::ScaleVehicle(float x)
{

}
void TheVehicleClass::TheVehicleColorFunction()
{
	int rand = Freedom.asMicroseconds();
	if (rand % 5 == 1) TheVehicleColor = sf::Color::Green;
	else if (rand % 4 == 1)TheVehicleColor = sf::Color::Red;
	else if (rand % 3 == 1) TheVehicleColor = sf::Color::Magenta;
	else if (rand % 2 == 1) TheVehicleColor = sf::Color::Cyan;
}

void TheVehicleClass::ReduceHealth(int ReducingValue)
{
	TheVehicleHealth = TheVehicleHealth - ReducingValue;
}
void TheVehicleClass::VehicleHandler()
{
}
void TheVehicleClass::VehicleHandler(TheVehicleClass &Player)
{

}


void TheVehicleClass::BoundsCollision()
{
	if (this->TheVehicle.getGlobalBounds().intersects(ScreenBounds[0].getGlobalBounds()))
	{
		this->TheVehicle.move(0, this->TheVehicleSpeed*Freedom.asSeconds()*this->TheFreedomSpeed);
	}
	else if (this->TheVehicle.getGlobalBounds().intersects(ScreenBounds[1].getGlobalBounds()))
	{
	
		this->TheVehicle.move(-this->TheVehicleSpeed*Freedom.asSeconds()*this->TheFreedomSpeed, 0);
	}
	else if (this->TheVehicle.getGlobalBounds().intersects(ScreenBounds[2].getGlobalBounds()))
	{
		
		this->TheVehicle.move(0, -this->TheVehicleSpeed*Freedom.asSeconds()*this->TheFreedomSpeed);
	}
	else if (this->TheVehicle.getGlobalBounds().intersects(ScreenBounds[3].getGlobalBounds()))
	{
		
		this->TheVehicle.move(this->TheVehicleSpeed*Freedom.asSeconds()*this->TheFreedomSpeed, 0);
	}
	if (this->TheVehicle.getGlobalBounds().intersects(WorldBounds[0].getGlobalBounds()))
	{
		this->TheVehicle.move(0, -this->TheVehicleSpeed*Freedom.asSeconds()*this->TheFreedomSpeed);
	}
	else if (this->TheVehicle.getGlobalBounds().intersects(WorldBounds[1].getGlobalBounds()))
	{
		this->TheVehicle.move(0, this->TheVehicleSpeed*Freedom.asSeconds()*this->TheFreedomSpeed);
	}
}




TheHUD::TheHUD()
{
	Bogus = 0;
	OldHealth = 100;
	TakingDamage = false;
	HealthBarTexture.loadFromFile("Data/Textures/HUD/HealthBar.png");
	HealthStripTexture.loadFromFile("Data/Textures/HUD/HealthStrip.png");
	HealthBar.setTexture(HealthBarTexture); HealthStrip.setTexture(HealthStripTexture);
	MeterTexture.loadFromFile("Data/Textures/HUD/Meter2.png");
	MeterNeedleTexture.loadFromFile("Data/Textures/HUD/Meter2Needle.png");
	Meter.setTexture(MeterTexture); MeterNeedle.setTexture(MeterNeedleTexture);
	BoostTexture.loadFromFile("Data/Textures/HUD/Boost.png");
	Boost.setTexture(BoostTexture);
	//MaskTexture.loadFromFile("Data/Textures/Mask.png"); Mask.setTexture(MaskTexture);
	//Mask.setColor(sf::Color::Red);
	HealthBar.setPosition(ScreenDimensions.x*0.02, ScreenDimensions.y*0.75);
	HealthStrip.setPosition(HealthBar.getPosition().x + 179, HealthBar.getPosition().y + 74.5);
	HealthBar.setScale(0.7, 0.6); HealthStrip.setScale(0.7, 0.6);
	Meter.setOrigin(108, 97); Meter.setPosition(ScreenDimensions.x*0.07, ScreenDimensions.y*0.87);
	MeterNeedle.setOrigin(1, 4); MeterNeedle.setPosition(ScreenDimensions.x*0.07, ScreenDimensions.y*0.87);
	MeterNeedle.setRotation(-220);
	Boost.setPosition(ScreenDimensions.x*0.14, ScreenDimensions.y*0.91);
}
void TheHUD::HUDHandler(float &TheVehicleHealth, float &TheVehicleSpeed, float &TheVehicleBoost)
{
	Mask.setPosition(0, ViewDimensions.y);
	HealthStrip.setScale(0.7*TheVehicleHealth / 100, 0.6);
	Meter.setPosition(ScreenDimensions.x*0.07 + ViewDimensions.x, ScreenDimensions.y*0.87 + ViewDimensions.y);
	MeterNeedle.setPosition(ScreenDimensions.x*0.07 + ViewDimensions.x, ScreenDimensions.y*0.87 + ViewDimensions.y);
	HealthBar.setPosition(ScreenDimensions.x*0.02 + ViewDimensions.x, ScreenDimensions.y*0.75 + ViewDimensions.y);
	HealthStrip.setPosition(HealthBar.getPosition().x + 179, HealthBar.getPosition().y + 74.5);
	Boost.setPosition(ScreenDimensions.x*0.14 + ViewDimensions.x, ScreenDimensions.y*0.91 + ViewDimensions.y);
	//regen health


	if (HealthClock.getElapsedTime().asSeconds() > 3)
	{

		if (OldHealth > TheVehicleHealth)TakingDamage = true;
		else TakingDamage = false;
		OldHealth = TheVehicleHealth;
		HealthClock.restart().asSeconds();

	}
	if (TakingDamage == false)
	{
		if (OldHealth > TheVehicleHealth){ TakingDamage = true; }
		if (RegenClock.getElapsedTime().asSeconds() > 0.2)
		{
			if ((!(TheVehicleHealth >= 100)) && TakingDamage == false)TheVehicleHealth++;
			RegenClock.restart().asSeconds();
		}

	}

	//Speedometer
	if (-220 + (TheVehicleSpeed)* 90>-10)
		MeterNeedle.setRotation(20);
	else 	MeterNeedle.setRotation(-220 + (TheVehicleSpeed)* 90);
	//boost
	Boost.setTextureRect(sf::IntRect(0, 0, 238 * TheVehicleBoost / 100, 25));


	GameWindow.draw(HealthBar);
	GameWindow.draw(HealthStrip);
	GameWindow.draw(Meter);
	GameWindow.draw(MeterNeedle);
	GameWindow.draw(Boost);
	if (MaskClock.getElapsedTime().asSeconds() < 0.2)GameWindow.draw(Mask);
}

