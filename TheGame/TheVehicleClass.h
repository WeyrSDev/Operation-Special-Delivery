#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "Freedom.h"
#include "TheProjectileClass.h"

struct TheHUD;
enum TheVehicleType { Primitive, Advanced };
enum TheTankType { HoneyBadger, HankTheTank, Centurion, Crusader, Challenger, BlackPrince, Dreadnaught ,Juggernaut,Type80};
enum TheHeliType { Apache, Hunter };
enum TheTruckType {ArmyTruck,Car1,Car2};
enum Controller{Human,AI};
class TheVehicleClass
{
public:
	static sf::Sound VehicleDeath;
	static sf::SoundBuffer VehicleDeathBuffer;
	TheVehicleClass();
	TheVehicleType VehicleType=Advanced;
	Controller TheVehicleController;
	int MaxProjectiles = 1;
	std::vector<TheProjectileClass*> Projectile;
	
	float TheFreedomSpeed;
	float TheVehicleBoost;
	bool VehicleIsAlive;
	float TheVehicleSpeed;
	char DisallowMovement;
	float TheVehicleBoostSpeed;
	float TheVehicleMaxSpeed;
	bool BoostIsActive = false;
	const float TheVehicleOriginalSpeed = 0.5f;
	bool IsTheVehicleMoving;
	char TheVehicleDirection;
	sf::Sprite TheVehicle;
	sf::Texture TheVehicleTexture;
	sf::SoundBuffer TheVehicleMoveSoundBuffer;
	sf::Sound TheVehicleMoveSound;
	sf::Color TheVehicleColor = sf::Color::White;
	sf::Clock VehicleClock;

	
	void TheVehicleColorFunction();
	virtual void ReduceHealth(int ReducingValue);
	virtual void VehicleHandler();
	virtual void VehicleHandler(TheVehicleClass &Player);
	
	void BoundsCollision();
	virtual bool DoYouContainPowerup();
	virtual void MakeMeContainPowerup();
	virtual void ScaleVehicle(float x);
	virtual void SetVehicleColor(sf::Color col);

	~TheVehicleClass();

	
	bool DidIPlayDeathSound = 0;
	TheVehicleClass *nextVehicle=nullptr;//for linked list of enemies
	TheVehicleClass *prevVehicle = nullptr;
	void sethealth(float value){ TheVehicleHealth = value; }
protected:
	float TheVehicleHealth;
};


struct TheHUD
{
	TheHUD();
	int OldHealth;
	bool TakingDamage;
	float Bogus;
	sf::Sprite Mask; sf::Texture MaskTexture;
	sf::Clock MaskClock;
	sf::Clock HealthClock;
	sf::Clock RegenClock;
	sf::Sprite HealthBar; sf::Texture HealthBarTexture;
	sf::Sprite HealthStrip; sf::Texture HealthStripTexture;
	sf::Sprite Meter; sf::Sprite MeterNeedle;
	sf::Texture MeterTexture; sf::Texture MeterNeedleTexture;
	sf::Sprite Boost; sf::Texture BoostTexture;
	void HUDHandler(float &TheVehicleHealth, float &TheVehicleSpeed, float &TheVehicleBoost);
};
