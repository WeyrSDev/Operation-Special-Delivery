#include "TheMachineGunClass.h"


TheMachineGunClass::TheMachineGunClass(int _VehicleType)
{
	TheProjectileSpeed = 0.000001f;
	BulletIsAlive = true;
	FreedomSpeed = 400;
	
	VehicleType = _VehicleType;
	TheProjectileTexture.loadFromFile("Data/Textures/Heli/MGunBullet1.png");
	TheProjectile.setTexture(TheProjectileTexture);
	TheProjectile.setScale(0.7, 0.7);
	TheProjectile.scale(GlobalScaleFactor);
	TheProjectile.setOrigin(85, 18);
	TheProjectile.setPosition(-1000, -1000);
	if (VehicleType == 2)
		TheProjectileSoundBuffer.loadFromFile("Data/Sound/MGunSound.ogg");
	else TheProjectileSoundBuffer.loadFromFile("Data/Sound/MGunSound2.ogg");
	TheProjectileSound.setBuffer(TheProjectileSoundBuffer);

}


TheMachineGunClass::~TheMachineGunClass()
{
}


void TheMachineGunClass::ReadyToFire(sf::Sprite &TheVehicle)
{
	TheProjectile.setPosition(TheVehicle.getPosition().x, TheVehicle.getPosition().y);
	TheProjectileSpeed = 3;
}

void TheMachineGunClass::TheProjectileMover(float &DeltaX, float &DeltaY, float &TurretRotation, sf::Sprite &TheVehicle)
{
	if (VehicleType == 1)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || (sf::Joystick::isButtonPressed(0, 5)))
		{
			if (TheProjectileSound.getStatus() != sf::Sound::Playing)	 TheProjectileSound.play();
		}
		else TheProjectileSound.stop();
	}
	else if (VehicleType == 2)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || (sf::Joystick::isButtonPressed(0, 5)))
		{
			if (TheProjectileSound.getStatus() != sf::Sound::Playing)	 TheProjectileSound.play();
		}
		else TheProjectileSound.stop();
	}
	


		if (TheProjectile.getPosition() == TheVehicle.getPosition())
		{
			DeltaX1 = DeltaX;
			DeltaY1 = DeltaY;
			TurretRotation1 = TurretRotation;
		}
		TheProjectile.setRotation(TurretRotation1 - 90);
		TheProjectileDistance = sqrt(pow((DeltaX1), 2.0) + pow(DeltaY1, 2.0));

		TheProjectile.move((DeltaX1)* 13 * TheProjectileSpeed*Freedom.asSeconds()*FreedomSpeed / TheProjectileDistance, (DeltaY1)* 13 * TheProjectileSpeed*Freedom.asSeconds()*FreedomSpeed / TheProjectileDistance);
	


}
