#pragma once
#include "SFML/Graphics.hpp"
#include "Freedom.h"
#include "TheVehicleClass.h"
#include "TheTankClass.h"
#include "TheAITank.h"
#include "TheJetClass.h"
#include "TheTruckClass.h"
#include "TheHeliClass.h"
#include "SentryGun.h"
#include "TheAIHeli.h"
#include <list>
#include <random>


void OperationInitialiser();
	void VehicleCollisionCheck(TheVehicleClass *Player, TheVehicleClass *Enemy);
		
	

	void ViewLock(bool w = false, bool s = false, bool a = false, bool d = false );
	void ReverseLock(sf::Sprite &Player, bool s = false);
	void BackHandler(sf::RenderWindow &GameWindow, sf::Sprite Player);
	void RandSpawn(sf::Sprite &Object);
	void SpriteCollision(TheVehicleClass &Tank, sf::Sprite Object);
	void ProjectileCollisionCheck(TheVehicleClass *Player,TheVehicleClass *Enemy);
	
	
	class AIManager
	{
	
	private:
		
		list<TheVehicleClass*>::iterator itr;
		list<TheVehicleClass*>::iterator itr2;
		list<TheVehicleClass*>::iterator Enditr;
		list<TheVehicleClass*>::iterator tmp;
		
		sf::Clock DelClock;
		float DelClockBound=3;
		sf::Clock SpawnClock;
		sf::Sprite loading; sf::Texture loadingTexture;
		TheVehicleClass *_Target;
		pair<int, sf::Vector2f> UnclaimedDeadBodies=make_pair(0, sf::Vector2f(0,0));
		pair<int, sf::Vector2f> tmpdeadbodies;
		bool DidICreateASpecialEnemyAlready = 0;
	public:
		list<TheVehicleClass*> AIlist;
		Controller AIArchEnemy = Human;
		AIManager();
		AIManager(Controller _AIArchEnemy);
		int CurrentRound = 1;
		void TheAIManager(AIManager &TargetAIs);
		void AddToList(TheVehicleClass *lolCheckoutthenameindefinition);
		void CreateAI(int num = 1);

		void CreateAIUp(sf::Vector2f pos, int num = 1);
		void CreateAIUpTank(sf::Vector2f pos, int num = 1);
		void CreateAIUpHeli(sf::Vector2f pos, int num = 1);
		void CreateAIUpTurret(sf::Vector2f pos, int num = 1);

		void DeleteAI(list<TheVehicleClass*>::iterator tmp);
		bool AllDead();
		void RandPlace(sf::Sprite &Object);
		TheVehicleClass* GetLastEnemy();
		TheVehicleClass* GetRandTank();
		TheVehicleClass* GetRandHeli();
		pair<int,sf::Vector2f> SendDeadBodies();
	};
	class TheFighterJet;
	class PowerupManager
	{
		AIManager *HeroTeam, *VillanTeam;
		enum Powerups	{ InfiHealth, Speedup, FireBullet, Freeze, Bomb,Giant,LITERALLY_NOTHING };
		Powerups CurrentPowerup=LITERALLY_NOTHING;
		Powerups ToDeactivate= LITERALLY_NOTHING;
		enum Powers	    { CallTankSupport, CallHeliSupport, CallAirstrike, CallTurret };
		sf::Sprite PowerupSprite; sf::Texture PowerupSpriteTexture;
		sf::Sprite CallPowerup[4]; sf::Texture CallPowerupTexture[4];
		bool AnyoneActive;
		int Price[4];
		sf::Color Active = sf::Color::Green;
		sf::Color NotAvailable = sf::Color::Red;
		sf::Color Available = sf::Color::White;
		sf::Text Score;
		long ScoreCounter = 0;
		void CallPower(Powers CalledPower);
		sf::Clock PowerupActivationTimer;

		TheVehicleClass *ActiveBackupVehicle;
		TheFighterJet *AirStrikeJet=nullptr;
	public:
		PowerupManager(AIManager *_HeroTeam,AIManager *_VillanTeam);
		void ThePowerupManager();
		void ClaimDeadBodies(pair<int, sf::Vector2f>);
			};
	