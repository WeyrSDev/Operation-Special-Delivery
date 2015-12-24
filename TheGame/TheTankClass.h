#pragma once

#include <math.h>
#include "TheVehicleClass.h"
#include "TheBulletClass.h"
#include "TheMachineGunClass.h"
#include "PlayerVehicle.h"

using namespace std;
class TheTankClass:
	public PlayerVehicle
{
public:
	TheTankClass(TheTankType TheTankType=HoneyBadger);
	
	
	float DeltaX, DeltaY, TurretRotation;
	int CurrentBullet = 1;
	sf::Clock BulletFireClock;
	sf::Clock MGunFireClock;
	sf::Sprite TheTurret;
	sf::Texture TheTurretTexture;
	
	void VehicleHandler();
	void ScaleVehicle(float x);
	~TheTankClass();
	void SetVehicleColor(sf::Color col);
	
};

