#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "Freedom.h"
#include <iostream>
class TheProjectileClass
{
public:
	TheProjectileClass();
	float TheProjectileSpeed;
	bool BulletIsAlive;
	float DeltaX1, DeltaY1, TurretRotation1;
	float Acceleration;//missileclasskeliye
	int FreedomSpeed;
	bool FirstFire = true;
	float TheProjectileDistance;
	int VehicleType;
	int TheProjectileDamage=5;
	sf::Sprite TheProjectile;
	sf::Texture TheProjectileTexture;
	sf::SoundBuffer TheProjectileSoundBuffer;
	sf::Sound TheProjectileSound;
	int GetProjectileDamage()	{return TheProjectileDamage;}
	void SetProjectileDamage(int val){ TheProjectileDamage = val; }
	
	virtual void ReadyToFire(sf::Sprite &TheVehicle);
	virtual void TheProjectileMover(float &DeltaX, float &DeltaY, float &TurretRotation, sf::Sprite &TheVehicle);
	~TheProjectileClass();
};

