#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <iostream>
#include <math.h>
#include  "Freedom.h"
#include "TheProjectileClass.h"

class TheBulletClass:
	public TheProjectileClass
{
public:
	TheBulletClass();
	
	void ReadyToFire(sf::Sprite &TheVehicle);
	void TheProjectileMover(float &DeltaX, float &DeltaY, float &TurretRotation, sf::Sprite &TheVehicle);
	~TheBulletClass();
};

