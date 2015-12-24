#pragma once
#include "TheVehicleClass.h"
#include "PlayerVehicle.h"
class TheTruckClass :
	public PlayerVehicle
{
public:
	TheTruckClass(TheTruckType TheTrucktype = Car1);
	void VehicleHandler();
	~TheTruckClass();
	void ScaleVehicle(float x);
	void TruckHandler();
	void SetVehicleColor(sf::Color col);
};


