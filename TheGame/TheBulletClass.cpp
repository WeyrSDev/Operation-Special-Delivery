#include "TheBulletClass.h"


TheBulletClass::TheBulletClass()
{
	TheProjectileSpeed = 0.000001f;
	BulletIsAlive=true;
	FreedomSpeed = 400;


	switch (rand() % 6)
	{
	case 0:
		TheProjectileTexture.loadFromFile("Data/Textures/Bullets/TheVehicleBullet.png");
		TheProjectile.setTexture(TheProjectileTexture);
		TheProjectile.setScale(0.4, 0.4);
		TheProjectile.setOrigin(27, 18);
		TheProjectile.setPosition(-1000, -1000);
		TheProjectileSoundBuffer.loadFromFile("Data/Sound/TheBulletSound.ogg");
		break;
	case 1:
		TheProjectileTexture.loadFromFile("Data/Textures/Bullets/TheVehicleBullet2.png");
		TheProjectile.setTexture(TheProjectileTexture);
		TheProjectile.setScale(0.8, 0.8);
		TheProjectile.setOrigin(TheProjectile.getLocalBounds().width / 2, TheProjectile.getLocalBounds().height / 2);
		TheProjectile.setPosition(-1000, -1000);
		TheProjectileSoundBuffer.loadFromFile("Data/Sound/TheBulletSound2.ogg");
		break;
	case 2:
		TheProjectileTexture.loadFromFile("Data/Textures/Bullets/TheVehicleBullet3.png");
		TheProjectile.setTexture(TheProjectileTexture);
		TheProjectile.setScale(0.8, 0.8);
		TheProjectile.setOrigin(TheProjectile.getLocalBounds().width / 2, TheProjectile.getLocalBounds().height / 2);
		TheProjectile.setPosition(-1000, -1000);
		TheProjectileSoundBuffer.loadFromFile("Data/Sound/TheBulletSound3.ogg");
		break;
	case 3:
		TheProjectileTexture.loadFromFile("Data/Textures/Bullets/TheVehicleBullet4.png");
		TheProjectile.setTexture(TheProjectileTexture);
		TheProjectile.setOrigin(TheProjectile.getLocalBounds().width / 2, TheProjectile.getLocalBounds().height / 2);
		TheProjectile.setPosition(-1000, -1000);
		TheProjectileSoundBuffer.loadFromFile("Data/Sound/TheBulletSound4.ogg");
		break;
	case 4:
		TheProjectileTexture.loadFromFile("Data/Textures/Bullets/TheVehicleBullet5.png");
		TheProjectile.setTexture(TheProjectileTexture);
		TheProjectile.setScale(0.8, 0.8);
		TheProjectile.setOrigin(TheProjectile.getLocalBounds().width / 2, TheProjectile.getLocalBounds().height / 2);
		TheProjectile.setPosition(-1000, -1000);
		TheProjectileSoundBuffer.loadFromFile("Data/Sound/TheBulletSound5.ogg");
		break;

	default:
		TheProjectileTexture.loadFromFile("Data/Textures/Bullets/TheVehicleBullet5.png");
		TheProjectile.setTexture(TheProjectileTexture);
		TheProjectile.setScale(0.8, 0.8);
		TheProjectile.setOrigin(TheProjectile.getLocalBounds().width / 2, TheProjectile.getLocalBounds().height / 2);
		TheProjectile.setPosition(-1000, -1000);
		TheProjectileSoundBuffer.loadFromFile("Data/Sound/TheBulletSound5.ogg");

		break;
	}


	TheProjectile.scale(GlobalScaleFactor);
	TheProjectileSound.setBuffer(TheProjectileSoundBuffer);
}


TheBulletClass::~TheBulletClass()
{
}



void TheBulletClass::ReadyToFire(sf::Sprite &TheVehicle)
{
	TheProjectile.setPosition(sf::Vector2f((TheVehicle.getPosition().x), (TheVehicle.getPosition().y)));
	TheProjectileSpeed = 0.3;
	TheProjectileSound.play();
}

void TheBulletClass::TheProjectileMover(float &DeltaX, float &DeltaY, float &TurretRotation, sf::Sprite &TheVehicle)
{
		if (TheProjectile.getPosition() == TheVehicle.getPosition())
		{
			
			TurretRotation1 = TurretRotation + 90;
			TheProjectile.setRotation(TurretRotation1 + 180);
		}
			TheProjectile.move(-cos(TurretRotation1*0.017453)*Freedom.asSeconds()*FreedomSpeed*6, -sin(TurretRotation1*0.017453)*Freedom.asSeconds()*FreedomSpeed*6);
}