#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <math.h>
#include "Freedom.h"
#include "TheProjectileClass.h"
#include "TheMissileClass.h"
#include "TheMachineGunClass.h"
#include "TheVehicleClass.h"
#include "PlayerVehicle.h"
using namespace std;
class TheHeliClass:
	public PlayerVehicle
{
public:
	TheHeliClass(TheHeliType TheHeliType = Apache);
	float DeltaX, DeltaY, TurretRotation;
	bool CurrentMissile;
	sf::Clock BulletFireClock;
	sf::Clock MissileFireClock;
	sf::Sprite TheVehicleRotor;
	sf::Texture TheVehicleRotorTexture;
	sf::Color TheVehicleColor = sf::Color::White;
	void VehicleHandler();
	~TheHeliClass();
	void SetVehicleColor(sf::Color col);
	
	void ScaleVehicle(float x);
	
};


