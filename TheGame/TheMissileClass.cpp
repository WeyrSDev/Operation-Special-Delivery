#include "TheMissileClass.h"


TheMissileClass::TheMissileClass()
{
	TheProjectileSpeed = 0.000001f;
	BulletIsAlive = true;
	FreedomSpeed = 400;
	Acceleration = 1;


	TheProjectileTexture.loadFromFile("Data/Textures/Heli/Rocket.png");
	TheProjectile.setTexture(TheProjectileTexture);
	TheProjectile.setScale(0.7, 0.7);
	TheProjectile.scale(GlobalScaleFactor);
	TheProjectile.setOrigin(85, 18);
	TheProjectile.setPosition(-1000, -1000);
	TheProjectileSoundBuffer.loadFromFile("Data/Sound/MissileLaunch.ogg");
	TheProjectileSound.setBuffer(TheProjectileSoundBuffer);

}


TheMissileClass::~TheMissileClass()
{
}




void TheMissileClass::ReadyToFire(sf::Sprite &TheVehicle)
{
	TheProjectile.setPosition(TheVehicle.getPosition().x,TheVehicle.getPosition().y);
	TheProjectileSpeed = 0.01;
	TheProjectileSound.play();
}

void TheMissileClass::TheProjectileMover(float &DeltaX, float &DeltaY, float &TurretRotation, sf::Sprite &TheVehicle)
{

	
				DeltaX1 = DeltaX;
				DeltaY1 = DeltaY;
				TurretRotation1 = TurretRotation;
		
		TheProjectile.setRotation(TurretRotation1 - 90);
		TheProjectileDistance = sqrt(pow((DeltaX1), 2.0) + pow(DeltaY1, 2.0));
		Acceleration += 0.07;
		TheProjectile.move((DeltaX1)* 13 * TheProjectileSpeed*Freedom.asSeconds()*FreedomSpeed*Acceleration / TheProjectileDistance, (DeltaY1)* 13 * TheProjectileSpeed*Freedom.asSeconds()*FreedomSpeed*Acceleration / TheProjectileDistance);
	


}
