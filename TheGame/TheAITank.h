#pragma once
#include "TheTankClass.h"
#include "TheAIClass.h"
#include "TheJetClass.h"
#include <random>
class TheAITank :
	public TheAIClass
{
public:
	

	TheAITank( TheTankType TheTankType =HoneyBadger, string _MovementType = "Random");
	
	int TheMoveDistance = 0;
	char TheMoveDirection = 'w';
	
	int Tolerance;
	float Bogus = 0;
	
	float TankTypeBool;
	int count=0;
	int X20;
	
	string MoveMentType;
	sf::RectangleShape TheTracer[2];
	std::default_random_engine generator;
	
	~TheAITank();

	sf::Sprite TheTurret;
	sf::Texture TheTurretTexture;
	sf::Clock BulletFireClock;
	
	
	
	void ScaleVehicle(float x);
	
	
	void VehicleHandler(TheVehicleClass &TargetVehicle);
	void VehicleHandler();
	void RandomMovement();
	void XMovement();
	void YMovement();
	void SetAIMovementType(string type);
	void MoveUp();
	
};

