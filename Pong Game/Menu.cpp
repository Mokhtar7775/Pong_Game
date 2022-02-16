#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "GameGuide.h"
using namespace sf;

void Menu::menu_dec(float width, float height)
{
	font.loadFromFile("ee.ttf");

	//Pong
	mainmenu[0].setFont(font);
	mainmenu[0].setFillColor(Color::Cyan);
	mainmenu[0].setOutlineColor(Color::White);
	mainmenu[0].setCharacterSize(120);
	mainmenu[0].setOutlineThickness(1);
	mainmenu[0].setString("Pong");
	mainmenu[0].setPosition(Vector2f(450, -14));
	//Game
	mainmenu[1].setFont(font);
	mainmenu[1].setFillColor(Color::Cyan);
	mainmenu[1].setOutlineColor(Color::White);
	mainmenu[1].setCharacterSize(120);
	mainmenu[1].setOutlineThickness(1);
	mainmenu[1].setString("Game");
	mainmenu[1].setPosition(Vector2f(660, -14));

	//Play
	mainmenu[2].setFont(font);
	mainmenu[2].setFillColor(Color(0,255,127));
	mainmenu[2].setCharacterSize(75);
	mainmenu[2].setOutlineThickness(1);
	mainmenu[2].setString("Play");
	mainmenu[2].setPosition(578,210);

	//Settings
	mainmenu[3].setFont(font);
	mainmenu[3].setFillColor(Color::White);
	mainmenu[3].setCharacterSize(75);
	mainmenu[3].setOutlineThickness(1);
	mainmenu[3].setString("Settings");
	mainmenu[3].setPosition(540, 285);

	//Game Guide
	mainmenu[4].setFont(font);
	mainmenu[4].setFillColor(Color::White);
	mainmenu[4].setCharacterSize(75);
	mainmenu[4].setOutlineThickness(1);
	mainmenu[4].setString("Game Guide");
	mainmenu[4].setPosition(497,360);

	//Exit
	mainmenu[5].setFont(font);
	mainmenu[5].setFillColor(Color::White);
	mainmenu[5].setCharacterSize(75);
	mainmenu[5].setOutlineThickness(1);
	mainmenu[5].setString("Exit");
	mainmenu[5].setPosition(460,440);

	mainmenuselected = 2;
}

//Function of drawing menu
void  Menu::draw(RenderWindow& menu_window)
{
	for (int i = 0; i < 6; i++)
		menu_window.draw(mainmenu[i]);
}
//MoveUp
void Menu::moveup()
{
	if (mainmenuselected >= 2)
	{
		mainmenu[mainmenuselected].setFillColor(Color::White);
		mainmenuselected--;
		if (mainmenuselected < 2)
			mainmenuselected = 5;
		mainmenu[mainmenuselected].setFillColor(Color(0, 255, 127));
	}
}
//MoveDown
void Menu::movedown()
{
	if (true)
	{
		mainmenu[mainmenuselected].setFillColor(Color::White);
		mainmenuselected++;
		if (mainmenuselected > 5)
			mainmenuselected = 2;
		mainmenu[mainmenuselected].setFillColor(Color(0, 255, 127));
	}
}