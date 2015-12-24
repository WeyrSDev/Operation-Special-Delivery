#include "TheJetClass.h"


TheFighterJet::TheFighterJet(AIManager *_Targets) 
{
	Targets = _Targets;
	NoOfTargets = Targets->AIlist.size();
	Missiles = new TheMissileClass[NoOfTargets];
	if (rand()%2==0)
	TheJetTexture.loadFromFile("Data/Textures/Jet/Plane2.png");
	else TheJetTexture.loadFromFile("Data/Textures/Jet/Plane.png");
	TheJetMoveSoundBuffer.loadFromFile("Data/Sound/Jet.ogg");
	SonicBoomBuffer.loadFromFile("Data/Sound/SonicBoom.ogg");

	//TheJet.setOrigin(195, 190);
	TheJet.scale(2, 2);
	TheJet.setOrigin(TheJet.getLocalBounds().width/2, TheJet.getLocalBounds().height/2);
	
	TheJet.setRotation(-90);

	TheJet.setTexture(TheJetTexture);
	TheJet.setPosition(sf::Vector2f(ScreenDimensions.x/2, ScreenDimensions.y*3.5));
	
	TheJetMoveSound.setBuffer(TheJetMoveSoundBuffer);
	SonicBoom.setBuffer(SonicBoomBuffer);
	TheJetMoveSound.setLoop(1);
	
	TheCrosshairTexture.loadFromFile("Data/Textures/Crosshair/Crosshair1.png");
	TheCrosshair.setTexture(TheCrosshairTexture);
	TheCrosshair.setScale(0.2, 0.2);
	TheCrosshair.setOrigin(289, 291);
	REDTexture.loadFromFile("Data/Textures/RED.png");
	RED.setTexture(REDTexture);
	RED.setColor(sf::Color::Red);
	RED.setScale(10,10);
	RED.setOrigin( RED.getLocalBounds().width / 2, RED.getLocalBounds().height / 2 ); 
}


TheFighterJet::~TheFighterJet()
{
}


void TheFighterJet::TakeDownTargets()
{
	
	TheJet.move(0, -13);
	if (TheJetMoveSound.getStatus()!=sf::Sound::Playing)
	TheJetMoveSound.play();
	if (TheJet.getPosition().y < ScreenDimensions.y)
		if(SonicBoom.getStatus()!=sf::Sound::Playing) SonicBoom.play();

	GameWindow.draw(TheJet);


	if (TheJet.getPosition().y < ScreenDimensions.y / 2 && TheJet.getPosition().y >ScreenDimensions.y / 3){
		
		for (list<TheVehicleClass*>::iterator itr = Targets->AIlist.begin(); itr != Targets->AIlist.end(); itr++)
			(*itr)->ReduceHealth(100);
		GameWindow.draw(RED);
	}

	if (TheJet.getPosition().y < -900)JobDone = true;
}
bool TheFighterJet::IsTheJobDone()
{
	return JobDone;
}
