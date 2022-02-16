#include "PauseMenu.h"
#include <SFML/Graphics.hpp>
using namespace sf;

void PauseMenu::pause_dec()
{
	font.loadFromFile("Aller_BdIt.ttf");
	
	//Shape
	pause[0].setSize(Vector2f(300, 400));
	pause[0].setPosition(418, 195);
	background.loadFromFile("pausebackground.png");
	pause[0].setTexture(&background);
	//Boarders
	//Up
	pause[1].setSize(Vector2f(300, 2));
	pause[1].setPosition(418, 195);
	//Left
	pause[2].setSize(Vector2f(2, 400));
	pause[2].setPosition(418, 195);
	//Down
	pause[3].setSize(Vector2f(300, 2));
	pause[3].setPosition(418, 595);
	//Right
	pause[4].setSize(Vector2f(2, 402));
	pause[4].setPosition(718, 195);

	//pause
	pausemenu[0].setFont(font);
	pausemenu[0].setFillColor(Color::White);
	pausemenu[0].setOutlineColor(Color::Cyan);
	pausemenu[0].setCharacterSize(80);
	pausemenu[0].setOutlineThickness(1);
	pausemenu[0].setString("Pause");
	pausemenu[0].setPosition(Vector2f(465, 200));

	//contiue
	pausemenu[1].setFont(font);
	pausemenu[1].setFillColor(Color(0, 255, 127));
	pausemenu[1].setCharacterSize(40);
	pausemenu[1].setString("Continue");
	pausemenu[1].setPosition(Vector2f(497, 310));

	//new game
	pausemenu[2].setFont(font);
	pausemenu[2].setFillColor(Color::White);
	pausemenu[2].setCharacterSize(40);
	pausemenu[2].setString("New Game");
	pausemenu[2].setPosition(Vector2f(480, 400));

	//Main Menu
	pausemenu[3].setFont(font);
	pausemenu[3].setFillColor(Color::White);
	pausemenu[3].setCharacterSize(40);
	pausemenu[3].setString("Main Menu");
	pausemenu[3].setPosition(Vector2f(480, 490));

	pausemenuselected = 1;
}
//Function of drawing menu
void  PauseMenu::draw(RenderWindow& play_window)
{
	for (int i = 0;i < 5;i++)
		play_window.draw(pause[i]);

	for (int i = 0; i < 4; i++)

		play_window.draw(pausemenu[i]);
}
//MoveUp
void PauseMenu::moveup()
{
	if (pausemenuselected >= 1)
	{
		pausemenu[pausemenuselected].setFillColor(Color::White);
		pausemenuselected--;
		if (pausemenuselected < 1)
			pausemenuselected = 3;
		pausemenu[pausemenuselected].setFillColor(Color(0, 255, 127));
	}
}
//MoveDown
void PauseMenu::movedown()
{
	if (pausemenuselected +1 <= MAX_PAUSE_MENU)
	{
		pausemenu[pausemenuselected].setFillColor(Color::White);
		pausemenuselected++;
		if (pausemenuselected > 3)
			pausemenuselected = 1;
		pausemenu[pausemenuselected].setFillColor(Color(0, 255, 127));

	}
}