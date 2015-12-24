#pragma once
#include "TheAIClass.h"
#include "TheBulletClass.h"
class SentryGun :
	public TheAIClass
{
public:
	SentryGun();
	~SentryGun();
	int Tolerance;
	float Bogus = 0;
	int count = 0;
	int X20;
	sf::Clock BulletFireClock;
	
	void VehicleHandler(TheVehicleClass &TargetVehicle);
	void VehicleHandler();
	
};

