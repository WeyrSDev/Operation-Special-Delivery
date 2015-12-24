#pragma once
#include "TheVehicleClass.h"
enum CurrentVehicle { Truck, Tank, Heli };
struct TheHUD;

class PlayerVehicle :
	public TheVehicleClass
{
public:
	PlayerVehicle();
	static sf::Sprite JoyDot;
	static float PlayerHealth;
	static int CrossHairType;
	static sf::Sprite TheCrosshair;
	static sf::Texture TheCrosshairTexture;
	static TheHUD VehicleHUD;
	sf::Sound LowHealth; sf::SoundBuffer LowHealthBuffer;
	
	void PrimitiveMovement();
	void AdvancedMovement();
	static int Tolerance ;
	void ReduceHealth(int ReducingValue);
	
	static CurrentVehicle CurrentVehicle_;
	~PlayerVehicle();
};



