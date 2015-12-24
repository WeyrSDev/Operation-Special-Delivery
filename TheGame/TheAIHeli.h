#pragma once
#include "TheAIClass.h"
#include "TheMissileClass.h"
class TheAIHeli :
	public TheAIClass
{
public:
	
	
	TheAIHeli(TheHeliType TheHeliType = Apache, int _Tolerance = 2);
	float DeltaX, DeltaY, TurretRotation;
	bool CurrentMissile;
	sf::Clock BulletFireClock;
	sf::Clock MissileFireClock;
	sf::Sprite TheVehicleRotor;
	sf::Texture TheVehicleRotorTexture;
	sf::Color TheVehicleColor = sf::Color::White;
	void VehicleHandler();
	void VehicleHandler(TheVehicleClass &TargetVehicle);

	void ScaleVehicle(float x);

	~TheAIHeli();
};

