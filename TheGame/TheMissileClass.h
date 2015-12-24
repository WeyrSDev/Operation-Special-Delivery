#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <iostream>
#include <math.h>
#include  "Freedom.h"
#include "TheProjectileClass.h"
class TheMissileClass :
	public TheProjectileClass
{
public:
	TheMissileClass();
	
	void ReadyToFire(sf::Sprite &TheVehicle);
	void TheProjectileMover(float &DeltaX, float &DeltaY, float &TurretRotation, sf::Sprite &TheVehicle);
	~TheMissileClass();
};

