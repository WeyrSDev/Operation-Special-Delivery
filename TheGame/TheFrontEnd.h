#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "OperationsHandler.h"
#include "TheMainMenuClass.h"
#include <math.h>
#include <string.h>
#include "Freedom.h"

#include "TheVehicleClass.h"
#include "TheTankClass.h"
#include "TheTruckClass.h"
#include "TheHeliClass.h"
#include "TheAITank.h"
#include "SentryGun.h"
#include "PlayerVehicle.h"
#include "TheAIHeli.h"

struct PlayerChoices;


void FrontEnd(PlayerChoices PlayerChoice);
void Survival(PlayerChoices PlayerChoice);
void Mission1();
void CutScene1();


void PauseMenu();
void DispObjective();
void BackGroundLoader(int num, sf::Sprite *Back, sf::Texture &BackTexture);
void MusicLoader(int num = -1);



