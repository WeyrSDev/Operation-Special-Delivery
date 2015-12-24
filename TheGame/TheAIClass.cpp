#include "TheAIClass.h"


TheAIClass::TheAIClass()
{
	TheVehicleController = AI;
	MaxProjectiles = 1;
	
}

TheAIClass::~TheAIClass()
{
	
}

void TheAIClass::CreateEnemy()
{
	
}

bool  TheAIClass::DoYouContainPowerup()
{
	return DoIContainPowerup;
}
void TheAIClass::MakeMeContainPowerup()
{
	DoIContainPowerup = true;
}

void TheAIClass::TrackerMovement(sf::Sprite &Target)
{
	DeltaX = Target.getPosition().x - TheVehicle.getPosition().x;
	DeltaY = Target.getPosition().y - TheVehicle.getPosition().y;

	if ((Target.getPosition().x - TheVehicle.getPosition().x)< 0)
	{
		TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295);
	}
	else
	{
		TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295);
	}

	TheVehicle.setRotation(TheRotation);

	PythagorasDistance = sqrt(pow((DeltaX), 2.0) + pow(DeltaY, 2.0));
	if (PythagorasDistance>250)
		TheVehicle.move((DeltaX)*Freedom.asSeconds() * 450 * TheVehicleSpeed / PythagorasDistance, (DeltaY)*Freedom.asSeconds() * 450 * TheVehicleSpeed / PythagorasDistance);
}
void TheAIClass::TrackerMovement(sf::Vector2f &Target)
{
	DeltaX = Target.x - TheVehicle.getPosition().x;
	DeltaY = Target.y - TheVehicle.getPosition().y;

	if ((Target.x - TheVehicle.getPosition().x)< 0)
	{
		TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295);
	}
	else
	{
		TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295);
	}

	TheVehicle.setRotation(TheRotation);

	PythagorasDistance = sqrt(pow((DeltaX), 2.0) + pow(DeltaY, 2.0));
	if (PythagorasDistance>450)
		TheVehicle.move((DeltaX)*Freedom.asSeconds() * 450 * TheVehicleSpeed / PythagorasDistance, (DeltaY)*Freedom.asSeconds() * 450 * TheVehicleSpeed / PythagorasDistance);
}