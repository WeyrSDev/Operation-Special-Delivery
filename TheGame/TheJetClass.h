#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "OperationsHandler.h"
#include "TheMissileClass.h"
using namespace std;
class AIManager;
class TheFighterJet
{
public:

	
	int NoOfTargets;
	TheMissileClass *Missiles;
	sf::Sprite TheJet;
	sf::Texture TheJetTexture;

	sf::Sprite TheCrosshair;
	sf::Texture TheCrosshairTexture;

	sf::SoundBuffer TheJetMoveSoundBuffer;
	sf::Sound TheJetMoveSound;

	sf::SoundBuffer SonicBoomBuffer;
	sf::Sound SonicBoom;
	
	sf::Sprite RED;
	sf::Texture REDTexture;

	TheFighterJet(AIManager *_Targets);
	void TakeDownTargets();
	AIManager *Targets;
	bool IsTheJobDone();
	bool JobDone = false;
	~TheFighterJet();


	long onezero = 0;

};

