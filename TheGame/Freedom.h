#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <list>
using namespace std;
extern sf::Time Freedom;
extern sf::Vector2f GlobalScaleFactor;
extern sf::Vector2f ScreenDimensions;
extern sf::Vector2f ViewDimensions;
extern sf::Vector2f GlobalMousePosition;
extern sf::View GameView;
extern float GameViewRotation;
extern float GameViewZoom;
extern sf::Vector2f GameViewCenter;
extern sf::RenderWindow GameWindow;
extern sf::Font BattlefieldFont;
extern sf::RectangleShape ScreenBounds[4];
extern sf::RectangleShape WorldBounds[2];

extern sf::Music GameMusic;

extern bool IsjoystickConnected;
/*

StuffHandler.ReverseLock(Playersprite, 1);
StuffHandler.ViewLock(0, 1, 1, 1);
StuffHandler.BackHandler(GameWindow, playersprite);
StuffHandler.BoundsCollision(Player);






*/
