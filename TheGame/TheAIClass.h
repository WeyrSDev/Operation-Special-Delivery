#pragma once
#include "TheVehicleClass.h"
#include "TheBulletClass.h"
class TheAIClass :
	public TheVehicleClass
{
public:
	bool DoIContainPowerup = false;
	void CreateEnemy();
	bool DoYouContainPowerup();
	void MakeMeContainPowerup();
	void TrackerMovement(sf::Sprite &Target);
	void TrackerMovement(sf::Vector2f &Target);
	float DeltaX, DeltaY, TurretRotation;
	float PythagorasDistance;
	float TheRotation;
	
	
	sf::Sprite TheCrosshair;
	sf::Texture TheCrosshairTexture;
	TheAIClass();
	~TheAIClass();
};

