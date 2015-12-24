#include "SentryGun.h"


SentryGun::SentryGun()
{
	TheVehicleTexture.loadFromFile("Data/Objects/MGun.png");
	TheVehicle.setTexture(TheVehicleTexture);
	TheVehicle.setOrigin(39, 208);
	TheVehicle.scale(0.6, 0.6);
	Tolerance = 1;

	
	
	Bogus = 0;
	Projectile.push_back(new TheBulletClass);
	Projectile[0]->SetProjectileDamage(15);
	TheFreedomSpeed = 500;
	TheVehicleHealth = 100;
	TheVehicleBoost = 100;
	TheVehicleMaxSpeed = 1.3;
	VehicleIsAlive = true;
	TheVehicleSpeed = 0.5f;
	TheVehicleBoostSpeed = 5.0f;

	TheRotation = 0;
	TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair1.png");
	TheCrosshair.setTexture(TheCrosshairTexture);
	TheCrosshair.setScale(0.2, 0.2);
	TheCrosshair.setOrigin(289, 291);
}


SentryGun::~SentryGun()
{

	for (std::vector<TheProjectileClass*>::iterator i = Projectile.begin(); i != Projectile.end(); i++)
		delete *i;
}
void SentryGun::VehicleHandler(TheVehicleClass &TargetVehicle)
{
	if (abs(TargetVehicle.TheVehicle.getPosition().y - TheVehicle.getPosition().y) < ScreenDimensions.y * 2)
	{


		if (TheVehicleHealth > 4)
		{




			//FIRE
			//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			TheCrosshair.setPosition(TargetVehicle.TheVehicle.getPosition().x, TargetVehicle.TheVehicle.getPosition().y);

			DeltaX = TargetVehicle.TheVehicle.getPosition().x - TheVehicle.getPosition().x;
			DeltaY = TargetVehicle.TheVehicle.getPosition().y - TheVehicle.getPosition().y;

			if ((TargetVehicle.TheVehicle.getPosition().x - TheVehicle.getPosition().x) < 0)
			{
				TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 270;
			}
			else
			{
				TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 90;
			}

			TheVehicle.setRotation(TheRotation);


			if (BulletFireClock.getElapsedTime().asSeconds() > 0.5 && (Projectile[0]->TheProjectileSpeed == 0))
			{
				DeltaX = TargetVehicle.TheVehicle.getPosition().x - TheVehicle.getPosition().x;
				DeltaY = TargetVehicle.TheVehicle.getPosition().y - TheVehicle.getPosition().y;
				if ((TargetVehicle.TheVehicle.getPosition().x - TheVehicle.getPosition().x) < 0)
				{
					TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 270;
				}
				else
				{
					TheRotation = ((atan((DeltaY) / (DeltaX)))*57.295) + 90;
				}
				if (TargetVehicle.VehicleIsAlive == true) Projectile[0]->ReadyToFire(TheVehicle);
				BulletFireClock.restart().asSeconds();
			}



			Projectile[0]->TheProjectileMover(DeltaX, DeltaY, TheRotation, TheVehicle);

			if (sqrt(pow(Projectile[0]->TheProjectile.getPosition().x - TheVehicle.getPosition().x, 2) + pow(Projectile[0]->TheProjectile.getPosition().y - TheVehicle.getPosition().y, 2)) > ScreenDimensions.x)
			{
				Projectile[0]->TheProjectileSpeed = 0;
				Projectile[0]->TheProjectile.setPosition(-1000, -1000);
			}

			GameWindow.draw(TheVehicle);
			GameWindow.draw(Projectile[0]->TheProjectile);
			BoundsCollision();
		//	GameWindow.draw(TheCrosshair);
		}
		else
		{
			TheVehicle.setColor(sf::Color::Red);
			if (VehicleIsAlive == true) VehicleIsAlive = false;
			GameWindow.draw(TheVehicle);
		}
	}

}

void SentryGun::VehicleHandler()
{
	if (TheVehicleHealth > 4)
		GameWindow.draw(TheVehicle);
	else 
	{
		TheVehicle.setColor(sf::Color::Red);
		if (VehicleIsAlive == true) VehicleIsAlive = false;
		GameWindow.draw(TheVehicle);
	}
}

